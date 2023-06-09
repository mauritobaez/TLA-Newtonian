
#include "bison-actions.h"

void printTree(Program * program);

// Funciones aparte para validar ciertos errores/warnings
void checkForNestedAlignments(PlaceableList* list);
void validateRepeatedProperties(PropertyList* propertyList);

void ErrorWarningMessage(error_warning_type type, int line, problem problem);

/**
 * Implementación de "bison-grammar.h".
 */

/**
* Esta función se ejecuta cada vez que se emite un error de sintaxis.
*/
void yyerror(const char * string) {
	LogError("Mensaje: '%s' debido a '%s' (linea %d).", string, yytext, yylineno);
	LogError("En ASCII es:");
	LogErrorRaw("\t");
	const int length = strlen(yytext);
	for (int i = 0; i < length; ++i) {
		LogErrorRaw("[%d]", yytext[i]);
	}
	LogErrorRaw("\n\n");
}

/**
* Esta acción se corresponde con el no-terminal que representa el símbolo
* inicial de la gramática, y por ende, es el último en ser ejecutado, lo que
* indica que efectivamente el programa de entrada se pudo generar con esta
* gramática, o lo que es lo mismo, que el programa pertenece al lenguaje.
*/
Program* ProgramAction(Placeable* placeable) {
	/*
	* "state" es una variable global que almacena el estado del compilador,
	* cuyo campo "succeed" indica si la compilación fue o no exitosa, la cual
	* es utilizada en la función "main".
	*/
	state.succeed = true;
	/*
	* Por otro lado, "result" contiene el resultado de aplicar el análisis
	* sintáctico mediante Bison, y almacenar el nood raíz del AST construido
	* en esta variable. Para el ejemplo de la calculadora, no hay AST porque
	* la expresión se computa on-the-fly, y es la razón por la cual esta
	* variable es un simple entero, en lugar de un nodo.
	*/
	Program* program = calloc(1, sizeof(Program));
	program->placeable = placeable;
	state.program = program;
	if(state.program->placeable == NULL){
		error_warning* ew = malloc(sizeof(error_warning));
		ew->linenumber = 0;
		ew->type = NO_PLACEABLE;
		add(state.error_list, ew);
	}
	if(getSize(state.error_list)){
		state.succeed = false;			// No llega a generateSVG() en main
		toBegin(state.error_list);
		while(hasNext(state.error_list)){
			error_warning * nextError = next(state.error_list);
			ErrorWarningMessage(nextError->type, nextError->linenumber, ERROR);
		}
	} else {
		// Si hay errores, no muestra los warnings
		if(getSize(state.warning_list)) {
			toBegin(state.warning_list);
			while(hasNext(state.warning_list)){
				error_warning * nextWarning = next(state.warning_list);
				ErrorWarningMessage(nextWarning->type, nextWarning->linenumber, WARNING);
			}
		}
		printTree(program);
	}
	
	return program;
}


Placeable* PlaceableAction(PlaceableHeader* header, anchor_t position, PlaceableList* mainBody) {
	Placeable* placeable = calloc(1, sizeof(Placeable));
	placeable->position = position;
	placeable->composedPlaceables = mainBody;
	if(header!=NULL) {
		placeable->type = header->type;
		placeable->properties = header->properties;
		free(header);
	}
	// No podemos tener inmediatamente otra ROW o COLUMN
	if(placeable->type==ROW || placeable->type==COLUMN) checkForNestedAlignments(mainBody);
	return placeable;
}


PlaceableHeader* PlaceableHeaderAction(PlaceableType type, PropertyList* propertiesBody) {
	PlaceableHeader* header = calloc(1, sizeof(PlaceableHeader));
	header->type = type;
	header->properties = propertiesBody;
	return header;
}

PropertyList* PlaceablePropertyAction(Property* property, PropertyList* propertyList) {
	PropertyList* propertyListNode = calloc(1, sizeof(PropertyList));
	propertyListNode->next = propertyList;
	propertyListNode->property = property;
	validateRepeatedProperties(propertyList);
	return propertyListNode;
}


Property* PropertyAction(PropertyType key, void* value) {
	Property* property = calloc(1, sizeof(Property));
	// El property->value es un unión, depende del tipo se le atribuye un tipo de valor u otro
	switch (key) {
		case COLOR_PROP:
			property->value.color = *((color_t*) value);
			break;
		case DIRECTION: 
			property->value.direction = *((direction_t*) value);
			break;
		case FRICTION:
		case REVERSE_ARROW:
		case DOUBLE_ARROW:
		case VISIBLE:
			property->value.boolean = *((boolean*) value);
			break;
		case LABEL:
		case ANGLE_LABEL:
			property->value.string = *((char**) value);
			break;
		case ANGLE:
			property->value.number = *((float*) value);
			if(property->value.number >360.0f || property->value.number < -360.0f) {
				error_warning* ew = malloc(sizeof(error_warning));
				ew->linenumber = yylineno;
				ew->type = INVALID_ANGLE;
                add(state.error_list, ew);
            }
			break;
		case HEIGHT:
		case WIDTH:
		case LENGTH:
		case RADIUS:
			property->value.number = *((float*) value);
			if(property->value.number<0.0f) {
				error_warning* ew = malloc(sizeof(error_warning));
				ew->linenumber = yylineno;
				ew->type = INVALID_VALUE;
                add(state.error_list, ew);
			}
			break;
		
	}
	property->key = key;
	return property;
}



PlaceableList* PlaceableBodyAction(Placeable* placeable, PlaceableList* placeableList) {
	PlaceableList* placeableListNode = calloc(1, sizeof(PlaceableList));
	placeableListNode->next = placeableList;
	placeableListNode->placeable = placeable;
	if(placeable->type==ROW || placeable->type==COLUMN) checkForNestedAlignments(placeable->composedPlaceables);
	return placeableListNode;
}


// Únicamente revisa los hijos directos
void checkForNestedAlignments(PlaceableList* list) {
	PlaceableList* aux = list;
	while(aux!=NULL) {
		if(aux->placeable->type==ROW || aux->placeable->type==COLUMN){
			error_warning* ew = malloc(sizeof(error_warning));
			ew->linenumber = yylineno;
			ew->type = NESTED_ALIGNMENTS;
			add(state.error_list, ew);
		}
		aux = aux->next;
	}
}

// Funciones para recursivamente hacer los free de toda memoria allocada (allocar: Proveniente de un malloc, está bastante cuerda)
void FreePlaceable(Placeable* placeable);
void FreePropertyList(PropertyList* propertyList);
void FreePlaceableList(PlaceableList* placeableList);
void FreeProperty(Property* property);
void FreeProgram(Program* program);

void FreeProgram(Program* program) {
	if(program->placeable != NULL)
		FreePlaceable(program->placeable);
	free(program);
}

void FreePlaceable(Placeable* placeable) {
	if(placeable->properties != NULL)
		FreePropertyList(placeable->properties);
	if(placeable->composedPlaceables != NULL)
		FreePlaceableList(placeable->composedPlaceables);
	free(placeable);
}

void FreePropertyList(PropertyList* propertyList) {
	if(propertyList->next != NULL)
		FreePropertyList(propertyList->next);
	if(propertyList->property != NULL)
		FreeProperty(propertyList->property);
	free(propertyList);
}

void FreePlaceableList(PlaceableList* placeableList) {
	if(placeableList->next != NULL)
		FreePlaceableList(placeableList->next);
	if(placeableList->placeable != NULL)
		FreePlaceable(placeableList->placeable);
	free(placeableList);
}

void FreeProperty(Property* property) {
	//hay un malloc en flex cuando es string
	if((property->key == LABEL || property->key == ANGLE_LABEL) && (property->value.string != NULL)) {
		free(property->value.string);
	}
	free(property);
}

// Funciones para recursivamente hacer un print del árbol (AST) que se crea
void printProperties(PropertyList* props,  char* identation);
void printPlaceable(PlaceableList * pl, int indentation);
void printPlaceableNode(Placeable * placeable, int indentation);

void printProperties(PropertyList* props, char* identation) {
	if(props!=NULL) {
		PropertyType key = props->property->key;
		PropertyValue val = props->property->value;
		switch(key) {
			case COLOR_PROP:
				printf("%sType: %d value: %d %d %d\n", identation,key,val.color.red,val.color.blue,val.color.blue);
				break;
			case DIRECTION: 
				printf("%sType: %d value: %d\n", identation, key, val.direction);
				break;
			case FRICTION:
			case REVERSE_ARROW:
			case DOUBLE_ARROW:
			case VISIBLE:
				printf("%sType: %d value: %d\n", identation, key, val.boolean);
				break;
			case LABEL:
			case ANGLE_LABEL:
				printf("%sType: %d value: %s\n", identation, key, val.string);
				break;
			case HEIGHT:
			case WIDTH:
			case LENGTH:
			case RADIUS:
			case ANGLE:
				printf("%sType: %d value: %f\n", identation, key, val.number);
				break;
		}
		printProperties(props->next, identation);
	}
}

void printPlaceable(PlaceableList * pl, int indentation) {
	while(pl!=NULL) {
		printPlaceableNode(pl->placeable, indentation);
		pl = pl->next;
	}
}

void typeToString(PlaceableType type, char* typeString) {
	switch (type) {
	case 0:
		strcpy(typeString, "Row");
		break;
	case 1:
		strcpy(typeString, "Column");
		break;
	case 2:
		strcpy(typeString, "Arrow");
		break;
	case 3:
		strcpy(typeString, "Rope");
		break;
	case 4:
		strcpy(typeString, "Spring");
		break;
	case 5:
		strcpy(typeString, "Spacer");
		break;
	case 6:
		strcpy(typeString, "Horizontal Plane");
		break;
	case 7:
		strcpy(typeString, "Vertical Plane");
		break;
	case 8:
		strcpy(typeString, "Block");
		break;
	case 9:
		strcpy(typeString, "Car");
		break;
	case 10:
		strcpy(typeString, "Ball");
		break;
	default:
		break;
	}
}

void printPlaceableNode(Placeable * placeable, int indentation) {
	char tabs[10];
	int i=0;
	while(i<indentation) tabs[i++] = '\t';
	tabs[i] = 0;
	char typeString[20];
	typeToString(placeable->type, typeString);
	printf("%sPlaceable type: %s | position: %d\n", tabs, typeString, placeable->position);
	printf("%sProperties: \n", tabs);
	tabs[i] = '\t';
	tabs[i+1] = 0;
	printProperties(placeable->properties, tabs);
	tabs[i]=0;
	printf("%sComposed Placeables: \n", tabs);
	printPlaceable(placeable->composedPlaceables, indentation+1);
}

void printTree(Program * program) {
	printf("PROGRAM NODE\n");
	printPlaceableNode(program->placeable, 1);
}

//Funcion para validar que no se esten repitiendo las propiedades y si esta ocurriendo mostrar un warning
void validateRepeatedProperties(PropertyList* propertyList) {
	char types[AMOUNT_PROPERTIES] = {0};
	while(propertyList!=NULL) {
		if(types[propertyList->property->key]++) {
			error_warning* ew = malloc(sizeof(error_warning));
			ew->linenumber = yylineno;
			ew->type = REPEATED_PROPERTIES;
			add(state.warning_list, ew);
		}
		propertyList = propertyList->next;
	}
}

//Funcion para imprimir el warning sobre las properties
void ErrorWarningMessage(error_warning_type type, int line, problem problem) {
	char* ew_message;
	switch (type)
	{
	case INVALID_ANGLE:
		ew_message = "Invalid Angle";
		break;
	case INVALID_VALUE:
		ew_message = "Invalid Value";
		break;
	case REPEATED_PROPERTIES:
		ew_message = "Repeated Properties";
		break;
	case NO_PLACEABLE:
		ew_message = "Initial Placeable is Missing";
		break;
	case NESTED_ALIGNMENTS:
		ew_message = "Nested Alignments";
		break;
	default:
		break;
	}
	if(problem == ERROR) {
		LogError("Error of type %s in line: %d\n", ew_message, line);
	} else if(problem == WARNING) {
		LogWarning("Warning of type %s in line: %d\n", ew_message, line);

	}
}