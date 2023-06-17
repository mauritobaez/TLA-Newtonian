%{

#include "bison-actions.h"

%}

%code requires {
	#include "../newtonian-types.h"
}

// Tipos de dato utilizados en las variables semánticas ($$, $1, $2, etc.).
%union {
	// No-terminales
	/*
	Program program;
	Expression expression;
	Factor factor;
	Constant constant;
	...
	*/
	
	Program* initial;
	Placeable* positionlessPlaceable;
	Placeable* placeable;
	anchor_t positionTag;
	Placeable* alignment;
	Placeable* positionlessAlignment;
	PlaceableHeader* keyAlignment;
	PlaceableList* bodyAlignment;
	PlaceableList* bodyAlignmentNullable;
	Placeable* object;
	Placeable* positionlessObject;
	PlaceableHeader* objectHeader;
	PlaceableList* bodyObject;
	PlaceableList* bodyObjectNullable;
	PlaceableHeader* plane;
	PlaceableType keyPlane;
	PropertyList* planeProperties;
	PropertyList* planePropertiesNullable;
	Property* planeProperty;
	PlaceableHeader* block;
	PlaceableType keyBlock;
	PropertyList* blockProperties;
	PropertyList* blockPropertiesNullable;
	Property* blockProperty;
	PlaceableHeader* ball;
	PlaceableType keyBall;
	PropertyList* ballProperties;
	PropertyList* ballPropertiesNullable;
	Property* ballProperty;
	Placeable* linear;
	Placeable* positionlessLinear;
	PlaceableHeader* linearHeader;
	PlaceableHeader* arrow;
	PlaceableType keyArrow;
	PropertyList* arrowProperties;
	PropertyList* arrowPropertiesNullable;
	Property* arrowProperty;
	PlaceableHeader* rope;
	PlaceableType keyRope;
	PropertyList* ropeProperties;
	PropertyList* ropePropertiesNullable;
	Property* ropeProperty;
	PlaceableHeader* spacer;
	PlaceableType keySpacer;
	PropertyList* spacerProperties;
	PropertyList* spacerPropertiesNullable;
	Property* spacerProperty;
	Property* group_generalProperty;
	Property* group_planeProperty;
	Property* group_straightProperty;
	Property* group_arrowProperty;
	Property* group_angleProperty;
	Property* group_blockProperty;
	Property* group_circularProperty;

	Property* frictionPropertyKeyValue;
	Property* colorPropertyKeyValue;
	Property* labelPropertyKeyValue;
	Property* directionPropertyKeyValue;
	Property* anglePropertyKeyValue;
	Property* angleLabelPropertyKeyValue;
	Property* heightPropertyKeyValue;
	Property* widthPropertyKeyValue;
	Property* lengthPropertyKeyValue;
	Property* reverseArrowPropertyKeyValue;
	Property* doubleArrowPropertyKeyValue;
	Property* radiusPropertyKeyValue;
	Property* visiblePropertyKeyValue;
	
 	// Terminales.
	token token;
	float number; //Tn 
	anchor_t anchor; //Ta
	direction_t direction; //Td
	color_t color; //Tc
	boolean boolean; //Tb
	char* string; //Ts
}
// IDs y tipos de los tokens terminales generados desde Flex.

%token <token> OPEN_BRACKET
%token <token> CLOSE_BRACKET
%token <token> OPEN_PARENTHESIS
%token <token> CLOSE_PARENTHESIS
%token <token> COMMA
%token <token> SEMICOLON
%token <token> ROW_KEY
%token <token> COLUMN_KEY
%token <token> HORIZONTAL_PLANE_KEY
%token <token> VERTICAL_PLANE_KEY
%token <token> BLOCK_KEY
%token <token> CAR_KEY
%token <token> BALL_KEY
%token <token> ARROW_KEY
%token <token> SPRING_KEY
%token <token> ROPE_KEY
%token <token> SPACER_KEY
%token <token> FRICTION_KEY
%token <token> COLOR_KEY
%token <token> LABEL_KEY
%token <token> DIRECTION_KEY
%token <token> ANGLE_KEY
%token <token> ANGLE_LABEL_KEY
%token <token> HEIGHT_KEY
%token <token> WIDTH_KEY
%token <token> LENGTH_KEY
%token <token> REVERSE_ARROW_KEY
%token <token> DOUBLE_ARROW_KEY
%token <token> RADIUS_KEY
%token <token> VISIBLE_KEY
%token <token> U_ERROR

%token <color> COLOR
%token <string> STRING 
%token <anchor> ANCHOR 
%token <number> NUMBER 
%token <boolean> BOOLEAN 
%token <direction> DIRECTION_REL
%token <direction> DIRECTION_ABS

// Tipos de dato para los no-terminales generados desde Bison.  
%type <initial> initial
%type <positionlessPlaceable> positionlessPlaceable
%type <placeable> placeable
%type <positionTag> positionTag
%type <alignment> alignment
%type <positionlessAlignment> positionlessAlignment
%type <keyAlignment> keyAlignment
%type <bodyAlignment> bodyAlignment
%type <bodyAlignmentNullable> bodyAlignmentNullable
%type <object> object
%type <positionlessObject> positionlessObject
%type <objectHeader> objectHeader
%type <bodyObject> bodyObject
%type <bodyObjectNullable> bodyObjectNullable
%type <plane> plane
%type <keyPlane> keyPlane
%type <planeProperties> planeProperties
%type <planePropertiesNullable> planePropertiesNullable
%type <planeProperty> planeProperty
%type <block> block
%type <keyBlock> keyBlock
%type <blockProperties> blockProperties
%type <blockPropertiesNullable> blockPropertiesNullable
%type <blockProperty> blockProperty
%type <ball> ball
%type <keyBall> keyBall
%type <ballProperties> ballProperties
%type <ballPropertiesNullable> ballPropertiesNullable
%type <ballProperty> ballProperty
%type <linear> linear
%type <positionlessLinear> positionlessLinear
%type <linearHeader> linearHeader
%type <arrow> arrow
%type <keyArrow> keyArrow
%type <arrowProperties> arrowProperties
%type <arrowPropertiesNullable> arrowPropertiesNullable
%type <arrowProperty> arrowProperty
%type <rope> rope
%type <keyRope> keyRope
%type <ropeProperties> ropeProperties
%type <ropePropertiesNullable> ropePropertiesNullable
%type <ropeProperty> ropeProperty
%type <spacer> spacer
%type <keySpacer> keySpacer
%type <spacerProperties> spacerProperties
%type <spacerPropertiesNullable> spacerPropertiesNullable
%type <spacerProperty> spacerProperty
%type <group_generalProperty> group_generalProperty
%type <group_planeProperty> group_planeProperty
%type <group_straightProperty> group_straightProperty
%type <group_arrowProperty> group_arrowProperty
%type <group_angleProperty> group_angleProperty
%type <group_blockProperty> group_blockProperty
%type <group_circularProperty> group_circularProperty
%type <frictionPropertyKeyValue> frictionPropertyKeyValue
%type <colorPropertyKeyValue> colorPropertyKeyValue
%type <labelPropertyKeyValue> labelPropertyKeyValue
%type <directionPropertyKeyValue> directionPropertyKeyValue
%type <anglePropertyKeyValue> anglePropertyKeyValue
%type <angleLabelPropertyKeyValue> angleLabelPropertyKeyValue
%type <heightPropertyKeyValue> heightPropertyKeyValue
%type <widthPropertyKeyValue> widthPropertyKeyValue
%type <lengthPropertyKeyValue> lengthPropertyKeyValue
%type <reverseArrowPropertyKeyValue> reverseArrowPropertyKeyValue
%type <doubleArrowPropertyKeyValue> doubleArrowPropertyKeyValue
%type <radiusPropertyKeyValue> radiusPropertyKeyValue
%type <visiblePropertyKeyValue> visiblePropertyKeyValue


// El símbolo inicial de la gramatica.
%start initial

%%

/*
	Bison Actions genericas a definir, para no hacer una para cada una y terminar en 2025:

	Program* ProgramAction(Placeable* placeable);
	Placeable* PlaceableAction(PlaceableType (enum) type, Boolean positionless, PropertyList* propertiesBody, PlaceableList* mainBody);
	PropertyList* PlaceablePropertyAction(Property* property, PropertyList* propertyList);
	Property* PropertyAction(PropertyType (enum) key, PropertyValue (union) value);
	PlaceableList* PlaceableBodyAction(Placeable* placeable, ComposedPlaceablesList* placeableList);

	Con Flex y Bison ya nos aseguramos que las propiedades son correctas para el Placeable en las que están y que 
	los tipos de dato de los values son correctos para la key correspondiente. También nos aseguramos que los Linear 
	no tengan Body y que los Placeable dentro de positionless no tengan Position.
	No nos aseguramos que properties estén repetidas, pero eso lo resolvemos después.
*/

//---------------------------------------------------------
//---------------------- PLACEABLE ------------------------
//---------------------------------------------------------

// S -> PL0
initial: positionlessPlaceable																			{ $$ = ProgramAction($1); }
	;

//PL0 -> A0 | O0 | L0
positionlessPlaceable: positionlessAlignment															{ $$ = $1; }
	| positionlessObject																				{ $$ = $1; }
	| positionlessLinear																				{ $$ = $1; }
	;

//PL1 -> A1 | O1 | L1
placeable: alignment																					{ $$ = $1; }
	| object																							{ $$ = $1; }
	| linear																							{ $$ = $1; }
	;

//pT
positionTag: SEMICOLON ANCHOR																			{ $$ = $2; }
	| %empty																							{ $$ = NO_ANCHOR; }
	; 

//---------------------------------------------------------
//---------------------- ALIGNMENT ------------------------
//---------------------------------------------------------

//A1 -> Ka pT Ba
alignment: keyAlignment positionTag bodyAlignment														{ $$ = PlaceableAction($1, $2, $3); }
	;

//A0 -> Ka Ba
positionlessAlignment: keyAlignment bodyAlignment														{ $$ = PlaceableAction($1, NO_ANCHOR, $2); }
	;

//Ka -> Row | Column
keyAlignment: ROW_KEY																					{ $$ = PlaceableHeaderAction(ROW, NULL); }
	| COLUMN_KEY																						{ $$ = PlaceableHeaderAction(COLUMN, NULL); }
	;

//Ba -> { Ba' } | lambda
bodyAlignment: OPEN_BRACKET bodyAlignmentNullable CLOSE_BRACKET 										{ $$ = $2; }
	| %empty																							{ $$ = NULL; }
	;

//Ba' -> Ba' | PL0, Ba' | lambda
bodyAlignmentNullable: positionlessPlaceable 															{ $$ = PlaceableBodyAction($1, NULL); }
	| positionlessPlaceable COMMA bodyAlignmentNullable													{ $$ = PlaceableBodyAction($1, $3); }
	| %empty																							{ $$ = NULL; }
	;

//---------------------------------------------------------
//---------------------- OBJECT ---------------------------
//---------------------------------------------------------

//O1 -> Ho pT Bo
object: objectHeader positionTag bodyObject																{ $$ = PlaceableAction($1, $2, $3); }
	;

//O0 -> Ho B
positionlessObject: objectHeader bodyObject 															{ $$ = PlaceableAction($1, NO_ANCHOR, $2); }
	;

//Ho -> N | U | C
objectHeader: plane																						{ $$ = $1; }
	| block																								{ $$ = $1; }
	| ball																								{ $$ = $1; }
	;

//Bo -> { Bo' } | lambda
bodyObject: OPEN_BRACKET bodyObjectNullable CLOSE_BRACKET 												{ $$ = $2; }
	| %empty																							{ $$ = NULL; }
	;

//Bo' -> Bo' | PL0, Bo' | lambda
bodyObjectNullable: placeable 																			{ $$ = PlaceableBodyAction($1, NULL); }
	| placeable COMMA bodyObjectNullable																{ $$ = PlaceableBodyAction($1, $3); }
	| %empty																							{ $$ = NULL; }
	;

//------------------------- OBJECT: PLANE ----------------------------

// N -> Kn Vn
plane: keyPlane planeProperties																			{ $$ = PlaceableHeaderAction($1, $2); }
	;

//Kn -> HorizontalPlane | VerticalPlane
keyPlane: HORIZONTAL_PLANE_KEY																			{ $$ = HORIZONTAL_PLANE; }
	| VERTICAL_PLANE_KEY																				{ $$ = VERTICAL_PLANE; }
	;

//Vn -> (Vn') | lambda
planeProperties: OPEN_PARENTHESIS planePropertiesNullable CLOSE_PARENTHESIS								{ $$ = $2; }
	| %empty																							{ $$ = NULL; }
	;

//Vn' -> Pn | Pn, Vn' | lambda
planePropertiesNullable: planeProperty																	{ $$ = PlaceablePropertyAction($1, NULL); }
	| planeProperty COMMA planePropertiesNullable														{ $$ = PlaceablePropertyAction($1, $3); }
	| %empty																							{ $$ = NULL; }
	;

//Pn -> ...
planeProperty: group_generalProperty																	{ $$ = $1; }
	| group_planeProperty																				{ $$ = $1; }
	| group_straightProperty																			{ $$ = $1; }
	| group_angleProperty																				{ $$ = $1; }
	;	

//------------------------- OBJECT: BLOCK ----------------------------

//U -> Ku Vu
block: keyBlock blockProperties																			{ $$ = PlaceableHeaderAction($1, $2); }
	;

//Ku -> Block | Car
keyBlock: BLOCK_KEY																						{ $$ = BLOCK; }
	| CAR_KEY																							{ $$ = CAR; }
	;

//Vu -> (Vu') | lambda
blockProperties: OPEN_PARENTHESIS blockPropertiesNullable CLOSE_PARENTHESIS								{ $$ = $2; }
	| %empty																							{ $$ = NULL; }
	;

//Vu' -> Pu | Pu, Vu' | lambda
blockPropertiesNullable: blockProperty 																	{ $$ = PlaceablePropertyAction($1, NULL); }
	| blockProperty COMMA blockPropertiesNullable														{ $$ = PlaceablePropertyAction($1, $3); }
	| %empty																							{ $$ = NULL; }
	;

//Pu -> ...
blockProperty: group_generalProperty																	{ $$ = $1; }
	| group_blockProperty																				{ $$ = $1; }
	;

//------------------------- OBJECT: BALL ----------------------------

//C -> Kc Vc
ball: keyBall ballProperties 																			{ $$ = PlaceableHeaderAction($1, $2); }
	;

//Kc -> Ball | Cylinder (el | está en flex porque como se dibujan igual son completamente sinónimos)
keyBall: BALL_KEY																						{ $$ = BALL; }
	;

//Vc -> (Vc') | lambda
ballProperties: OPEN_PARENTHESIS ballPropertiesNullable CLOSE_PARENTHESIS								{ $$ = $2; }
	| %empty																							{ $$ = NULL; }
	;

//Vc' -> Pc | Pc, Vc' | lambda
ballPropertiesNullable: ballProperty 																	{ $$ = PlaceablePropertyAction($1, NULL); }
	| ballProperty COMMA ballPropertiesNullable															{ $$ = PlaceablePropertyAction($1, $3); }
	| %empty																							{ $$ = NULL; }
	;

//Pc -> ...
ballProperty: group_generalProperty																		{ $$ = $1; }
	| group_circularProperty																			{ $$ = $1; }
	;

//---------------------------------------------------------
//---------------------- LINEAR ---------------------------
//---------------------------------------------------------

//L1 -> Hl pT
linear: linearHeader positionTag																		{ $$ = PlaceableAction($1, $2, NULL); }
	;

//L0 -> Hl
positionlessLinear: linearHeader																		{ $$ = PlaceableAction($1, NO_ANCHOR, NULL); }
	;

//Hl -> W | G | E
linearHeader: arrow																						{ $$ = $1; }
	| rope																								{ $$ = $1; }
	| spacer																							{ $$ = $1; }
	;

//---------------------- LINEAR OBJECT: ARROW ----------------------------

//W -> Kw Vw
arrow: keyArrow arrowProperties																			{ $$ = PlaceableHeaderAction($1, $2); }
	;

//Kw -> Arrow
keyArrow: ARROW_KEY																						{ $$ = ARROW; }
	;

//Vw -> ( Vw' ) | lambda
arrowProperties: OPEN_PARENTHESIS arrowPropertiesNullable CLOSE_PARENTHESIS 							{ $$ = $2; }
	| %empty																							{ $$ = NULL; }
	;

//Vw' -> Pw | Pw, Vw' | lambda
arrowPropertiesNullable: arrowProperty 																	{ $$ = PlaceablePropertyAction($1, NULL); }
	| arrowProperty COMMA arrowPropertiesNullable														{ $$ = PlaceablePropertyAction($1, $3); }
	| %empty																							{ $$ = NULL; }
	;

//Pw -> ...
arrowProperty: group_generalProperty																	{ $$ = $1; }
	| group_arrowProperty																				{ $$ = $1; }
	| group_straightProperty																			{ $$ = $1; }
	| group_angleProperty																				{ $$ = $1; }
	;

//---------------------- LINEAR OBJECT: ROPE ----------------------------

//G -> Kg Vg
rope: keyRope ropeProperties																			{ $$ = PlaceableHeaderAction($1, $2); }
	;

//Kg -> Rope | Spring
keyRope: ROPE_KEY																						{ $$ = ROPE; }
	| SPRING_KEY																						{ $$ = SPRING; }
	;

//Vg -> ( vg' ) | lambda
ropeProperties: OPEN_PARENTHESIS ropePropertiesNullable CLOSE_PARENTHESIS								{ $$ = $2; }
	| %empty																							{ $$ = NULL; }
	;

//Vg' -> Pg | Pg, Vg' | lambda
ropePropertiesNullable: ropeProperty 																	{ $$ = PlaceablePropertyAction($1, NULL); }
	| ropeProperty COMMA ropePropertiesNullable															{ $$ = PlaceablePropertyAction($1, $3); }
	| %empty																							{ $$ = NULL; }
	;

//Pg -> ...
ropeProperty: group_generalProperty																		{ $$ = $1; }
	| group_straightProperty																			{ $$ = $1; }
	;

//---------------------- LINEAR OBJECT: SPACER ----------------------------

//E -> Ke Ve
spacer: keySpacer spacerProperties																		{ $$ = PlaceableHeaderAction($1, $2); }
	;

//Ke -> Spacer
keySpacer: SPACER_KEY																					{ $$ = SPACER; }
	;

//Ve -> ( ve' ) | lambda
spacerProperties: OPEN_PARENTHESIS spacerPropertiesNullable CLOSE_PARENTHESIS							{ $$ = $2; }
	| %empty																							{ $$ = NULL; }
	;

//Ve' -> Pe | Pe, Ve' | lambda
spacerPropertiesNullable: spacerProperty 																{ $$ = PlaceablePropertyAction($1, NULL); }
	| spacerProperty COMMA spacerPropertiesNullable														{ $$ = PlaceablePropertyAction($1, $3); }
	| %empty																							{ $$ = NULL; }
	;

//Pe -> ...
spacerProperty: group_straightProperty																	{ $$ = $1; }
	;
	
//---------------------------------------------------------
//---------------------- GROUPS ---------------------------
//---------------------------------------------------------

group_generalProperty: colorPropertyKeyValue															{ $$ = $1; }																	
	| labelPropertyKeyValue																				{ $$ = $1; }
	;

group_planeProperty: frictionPropertyKeyValue															{ $$ = $1; }
	| visiblePropertyKeyValue																			{ $$ = $1; }
	;

group_straightProperty: lengthPropertyKeyValue															{ $$ = $1; }
	;

group_arrowProperty: directionPropertyKeyValue															{ $$ = $1; }
	| doubleArrowPropertyKeyValue																		{ $$ = $1; }
	| reverseArrowPropertyKeyValue																		{ $$ = $1; }
	;

group_angleProperty: anglePropertyKeyValue																{ $$ = $1; }
	| angleLabelPropertyKeyValue																		{ $$ = $1; }
	;

group_blockProperty: widthPropertyKeyValue																{ $$ = $1; }
	| heightPropertyKeyValue																			{ $$ = $1; }
	;

group_circularProperty: radiusPropertyKeyValue															{ $$ = $1; }
	;


//---------------------------------------------------------
//-------------------- PROPERTIES -------------------------
//---------------------------------------------------------

frictionPropertyKeyValue: FRICTION_KEY SEMICOLON BOOLEAN												{ $$ = PropertyAction(FRICTION, (void*) &($3)); }
	;

colorPropertyKeyValue: COLOR_KEY SEMICOLON COLOR														{ $$ = PropertyAction(COLOR_PROP, (void*) &($3)); }
	;

labelPropertyKeyValue: LABEL_KEY SEMICOLON STRING														{ $$ = PropertyAction(LABEL, (void*) &($3)); }
	;

directionPropertyKeyValue: DIRECTION_KEY SEMICOLON DIRECTION_ABS										{ $$ = PropertyAction(DIRECTION, (void*) &($3)); }
	| DIRECTION_KEY SEMICOLON DIRECTION_REL																{ $$ = PropertyAction(DIRECTION, (void*) &($3)); }
	;

anglePropertyKeyValue: ANGLE_KEY SEMICOLON NUMBER														{ $$ = PropertyAction(ANGLE, (void*) &($3)); }
	;
	
angleLabelPropertyKeyValue: ANGLE_LABEL_KEY SEMICOLON STRING											{ $$ = PropertyAction(ANGLE_LABEL, (void*) &($3)); }
	;
	
heightPropertyKeyValue: HEIGHT_KEY SEMICOLON NUMBER														{ $$ = PropertyAction(HEIGHT, (void*) &($3)); }
	;

widthPropertyKeyValue: WIDTH_KEY SEMICOLON NUMBER														{ $$ = PropertyAction(WIDTH, (void*) &($3)); }
	;

lengthPropertyKeyValue: LENGTH_KEY SEMICOLON NUMBER														{ $$ = PropertyAction(LENGTH, (void*) &($3)); }
	;

reverseArrowPropertyKeyValue: REVERSE_ARROW_KEY SEMICOLON BOOLEAN										{ $$ = PropertyAction(REVERSE_ARROW, (void*) &($3)); }
	;

doubleArrowPropertyKeyValue: DOUBLE_ARROW_KEY SEMICOLON BOOLEAN											{ $$ = PropertyAction(DOUBLE_ARROW, (void*) &($3)); }
	;

radiusPropertyKeyValue: RADIUS_KEY SEMICOLON NUMBER														{ $$ = PropertyAction(RADIUS, (void*) &($3)); }
	;

visiblePropertyKeyValue: VISIBLE_KEY SEMICOLON BOOLEAN													{ $$ = PropertyAction(VISIBLE, (void*) &($3)); }
	;

%%
