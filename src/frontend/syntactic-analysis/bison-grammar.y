%{

#include "bison-actions.h"

%}

%code requires {
	#include "../newtonian-types.h"
}

// Tipos de dato utilizados en las variables semánticas ($$, $1, $2, etc.).
%union {
	// No-terminales (backend).
	/*
	Program program;
	Expression expression;
	Factor factor;
	Constant constant;
	...
	*/
	Program* initial;

	// No-terminales (frontend).
	//int initial;
	int positionlessPlaceable;
	int placeable;
	int positionTag;
	int alignment;
	int positionlessAlignment;
	int keyAlignment;
	int bodyAlignment;
	int bodyAlignmentNullable;
	int object;
	int positionlessObject;
	int objectHeader;
	int bodyObject;
	int bodyObjectNullable;
	int plane;
	int keyPlane;
	int planeProperties;
	int planePropertiesNullable;
	int planeProperty;
	int block;
	int keyBlock;
	int blockProperties;
	int blockPropertiesNullable;
	int blockProperty;
	int ball;
	int keyBall;
	int ballProperties;
	int ballPropertiesNullable;
	int ballProperty;
	int linear;
	int positionlessLinear;
	int linearHeader;
	int arrow;
	int keyArrow;
	int arrowProperties;
	int arrowPropertiesNullable;
	int arrowProperty;
	int rope;
	int keyRope;
	int ropeProperties;
	int ropePropertiesNullable;
	int ropeProperty;
	int spacer;
	int keySpacer;
	int spacerProperties;
	int spacerPropertiesNullable;
	int spacerProperty;
	int group_generalProperty;
	int group_planeProperty;
	int group_straightProperty;
	int group_arrowProperty;
	int group_angleProperty;
	int group_blockProperty;
	int group_circularProperty;
	int frictionPropertyKeyValue;
	int colorPropertyKeyValue;
	int labelPropertyKeyValue;
	int directionPropertyKeyValue;
	int anglePropertyKeyValue;
	int angleLabelPropertyKeyValue;
	int heightPropertyKeyValue;
	int widthPropertyKeyValue;
	int lengthPropertyKeyValue;
	int reverseArrowPropertyKeyValue;
	int doubleArrowPropertyKeyValue;
	int radiusPropertyKeyValue;
	int visiblePropertyKeyValue;
	
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
%token <token> YYUNDEF

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

// Reglas de asociatividad y precedencia (de menor a mayor).
/* %left ADD SUB
%left MUL DIV */

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
initial: positionlessPlaceable																			{ $$ = ProgramAction(0); }
	;

//PL0 -> A0 | O0 | L0
positionlessPlaceable: positionlessAlignment															{ $$ = Return0(); }
	| positionlessObject																				{ $$ = Return0(); }
	| positionlessLinear																				{ $$ = Return0(); }
	;

//PL1 -> A1 | O1 | L1
placeable: alignment																					{ $$ = Return0(); }
	| object																							{ $$ = Return0(); }
	| linear																							{ $$ = Return0(); }
	;

//pT
positionTag: SEMICOLON ANCHOR																			{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	; 

//---------------------------------------------------------
//---------------------- ALIGNMENT ------------------------
//---------------------------------------------------------

//A1 -> Ka pT Ba
alignment: keyAlignment positionTag bodyAlignment														{ $$ = Return0(); }
	;

//A0 -> Ka Ba
positionlessAlignment: keyAlignment bodyAlignment														{ $$ = Return0(); }
	;

//Ka -> Row | Column
keyAlignment: ROW_KEY																					{ $$ = Return0(); }
	| COLUMN_KEY																						{ $$ = Return0(); }
	;

//Ba -> { Ba' } | lambda
bodyAlignment: OPEN_BRACKET bodyAlignmentNullable CLOSE_BRACKET 										{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Ba' -> Ba' | PL0, Ba' | lambda
bodyAlignmentNullable: positionlessPlaceable 															{ $$ = Return0(); }
	| positionlessPlaceable COMMA bodyAlignmentNullable													{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//---------------------------------------------------------
//---------------------- OBJECT ---------------------------
//---------------------------------------------------------

//O1 -> Ho pT Bo
object: objectHeader positionTag bodyObject																{ $$ = Return0(); }
	;

//O0 -> Ho B
positionlessObject: objectHeader bodyObject 															{ $$ = Return0(); }
	;

//Ho -> N | U | C
objectHeader: plane																						{ $$ = Return0(); }
	| block																								{ $$ = Return0(); }
	| ball																								{ $$ = Return0(); }
	;

//Bo -> { Bo' } | lambda
bodyObject: OPEN_BRACKET bodyObjectNullable CLOSE_BRACKET 												{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Bo' -> Bo' | PL0, Bo' | lambda
bodyObjectNullable: placeable 																			{ $$ = Return0(); }
	| placeable COMMA bodyObjectNullable																{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//------------------------- OBJECT: PLANE ----------------------------

// N -> Kn Vn
plane: keyPlane planeProperties																			{ $$ = Return0(); }
	;

//Kn -> HorizontalPlane | VerticalPlane
keyPlane: HORIZONTAL_PLANE_KEY																			{ $$ = Return0(); }
	| VERTICAL_PLANE_KEY																				{ $$ = Return0(); }
	;

//Vn -> (Vn') | lambda
planeProperties: OPEN_PARENTHESIS planePropertiesNullable CLOSE_PARENTHESIS								{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Vn' -> Pn | Pn, Vn' | lambda
planePropertiesNullable: planeProperty																	{ $$ = Return0(); }
	| planeProperty COMMA planePropertiesNullable														{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Pn -> ...
planeProperty: group_generalProperty																	{ $$ = Return0(); }
	| group_planeProperty																				{ $$ = Return0(); }
	| group_straightProperty																			{ $$ = Return0(); }
	| group_angleProperty																				{ $$ = Return0(); }
	;	

//------------------------- OBJECT: BLOCK ----------------------------

//U -> Ku Vu
block: keyBlock blockProperties																			{ $$ = Return0(); }
	;

//Ku -> Block | Car
keyBlock: BLOCK_KEY																						{ $$ = Return0(); }
	| CAR_KEY																							{ $$ = Return0(); }
	;

//Vu -> (Vu') | lambda
blockProperties: OPEN_PARENTHESIS blockPropertiesNullable CLOSE_PARENTHESIS								{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Vu' -> Pu | Pu, Vu' | lambda
blockPropertiesNullable: blockProperty 																	{ $$ = Return0(); }
	| blockProperty COMMA blockPropertiesNullable														{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Pu -> ...
blockProperty: group_generalProperty																	{ $$ = Return0(); }
	| group_blockProperty																				{ $$ = Return0(); }
	;

//------------------------- OBJECT: BALL ----------------------------

//C -> Kc Vc
ball: keyBall ballProperties 																			{ $$ = Return0(); }
	;

//Kc -> Ball | Cylinder (el | está en flex porque como se dibujan igual son completamente sinónimos)
keyBall: BALL_KEY																						{ $$ = Return0(); }
	;

//Vc -> (Vc') | lambda
ballProperties: OPEN_PARENTHESIS ballPropertiesNullable CLOSE_PARENTHESIS								{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Vc' -> Pc | Pc, Vc' | lambda
ballPropertiesNullable: ballProperty 																	{ $$ = Return0(); }
	| ballProperty COMMA ballPropertiesNullable															{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Pc -> ...
ballProperty: group_generalProperty																		{ $$ = Return0(); }
	| group_circularProperty																			{ $$ = Return0(); }
	;

//---------------------------------------------------------
//---------------------- LINEAR ---------------------------
//---------------------------------------------------------

//L1 -> Hl pT
linear: linearHeader positionTag																		{ $$ = Return0(); }
	;

//L0 -> Hl
positionlessLinear: linearHeader																		{ $$ = Return0(); }
	;

//Hl -> W | G | E
linearHeader: arrow																						{ $$ = Return0(); }
	| rope																								{ $$ = Return0(); }
	| spacer																							{ $$ = Return0(); }
	;

//---------------------- LINEAR OBJECT: ARROW ----------------------------

//W -> Kw Vw
arrow: keyArrow arrowProperties																			{ $$ = Return0(); }
	;

//Kw -> Arrow
keyArrow: ARROW_KEY																						{ $$ = Return0(); }
	;

//Vw -> ( Vw' ) | lambda
arrowProperties: OPEN_PARENTHESIS arrowPropertiesNullable CLOSE_PARENTHESIS 							{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Vw' -> Pw | Pw, Vw' | lambda
arrowPropertiesNullable: arrowProperty 																	{ $$ = Return0(); }
	| arrowProperty COMMA arrowPropertiesNullable														{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Pw -> ...
arrowProperty: group_generalProperty																	{ $$ = Return0(); }
	| group_arrowProperty																				{ $$ = Return0(); }
	| group_straightProperty																			{ $$ = Return0(); }
	| group_angleProperty																				{ $$ = Return0(); }
	;

//---------------------- LINEAR OBJECT: ROPE ----------------------------

//G -> Kg Vg
rope: keyRope ropeProperties																			{ $$ = Return0(); }
	;

//Kg -> Rope | Spring
keyRope: ROPE_KEY																						{ $$ = Return0(); }
	| SPRING_KEY																						{ $$ = Return0(); }
	;

//Vg -> ( vg' ) | lambda
ropeProperties: OPEN_PARENTHESIS ropePropertiesNullable CLOSE_PARENTHESIS								{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Vg' -> Pg | Pg, Vg' | lambda
ropePropertiesNullable: ropeProperty 																	{ $$ = Return0(); }
	| ropeProperty COMMA ropePropertiesNullable															{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Pg -> ...
ropeProperty: group_generalProperty																		{ $$ = Return0(); }
	| group_straightProperty																			{ $$ = Return0(); }
	;

//---------------------- LINEAR OBJECT: SPACER ----------------------------

//E -> Ke Ve
spacer: keySpacer spacerProperties																		{ $$ = Return0(); }
	;

//Ke -> Spacer
keySpacer: SPACER_KEY																					{ $$ = Return0(); }
	;

//Ve -> ( ve' ) | lambda
spacerProperties: OPEN_PARENTHESIS spacerPropertiesNullable CLOSE_PARENTHESIS							{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Ve' -> Pe | Pe, Ve' | lambda
spacerPropertiesNullable: spacerProperty 																{ $$ = Return0(); }
	| spacerProperty COMMA spacerPropertiesNullable														{ $$ = Return0(); }
	| %empty																							{ $$ = Return0(); }
	;

//Pe -> ...
spacerProperty: group_straightProperty																	{ $$ = Return0(); }
	;
	
//---------------------------------------------------------
//---------------------- GROUPS ---------------------------
//---------------------------------------------------------

group_generalProperty: colorPropertyKeyValue															{ $$ = Return0(); }																	
	| labelPropertyKeyValue																				{ $$ = Return0(); }
	;

group_planeProperty: frictionPropertyKeyValue															{ $$ = Return0(); }
	| visiblePropertyKeyValue																			{ $$ = Return0(); }
	;

group_straightProperty: lengthPropertyKeyValue															{ $$ = Return0(); }
	;

group_arrowProperty: directionPropertyKeyValue															{ $$ = Return0(); }
	| doubleArrowPropertyKeyValue																		{ $$ = Return0(); }
	| reverseArrowPropertyKeyValue																		{ $$ = Return0(); }
	;

group_angleProperty: anglePropertyKeyValue																{ $$ = Return0(); }
	| angleLabelPropertyKeyValue																		{ $$ = Return0(); }
	;

group_blockProperty: widthPropertyKeyValue																{ $$ = Return0(); }
	| heightPropertyKeyValue																			{ $$ = Return0(); }
	;

group_circularProperty: radiusPropertyKeyValue															{ $$ = Return0(); }
	;


//---------------------------------------------------------
//-------------------- PROPERTIES -------------------------
//---------------------------------------------------------

frictionPropertyKeyValue: FRICTION_KEY SEMICOLON BOOLEAN												{ $$ = Return0(); }
	;

colorPropertyKeyValue: COLOR_KEY SEMICOLON COLOR														{ $$ = Return0(); }
	;

labelPropertyKeyValue: LABEL_KEY SEMICOLON STRING														{ $$ = Return0(); }
	;

directionPropertyKeyValue: DIRECTION_KEY SEMICOLON DIRECTION_ABS										{ $$ = Return0(); }
	| DIRECTION_KEY SEMICOLON DIRECTION_REL																{ $$ = Return0(); }
	;

anglePropertyKeyValue: ANGLE_KEY SEMICOLON NUMBER														{ $$ = Return0(); }
	;
	
angleLabelPropertyKeyValue: ANGLE_LABEL_KEY SEMICOLON STRING											{ $$ = Return0(); }
	;
	
heightPropertyKeyValue: HEIGHT_KEY SEMICOLON NUMBER														{ $$ = Return0(); }
	;

widthPropertyKeyValue: WIDTH_KEY SEMICOLON NUMBER														{ $$ = Return0(); }
	;

lengthPropertyKeyValue: LENGTH_KEY SEMICOLON NUMBER														{ $$ = Return0(); }
	;

reverseArrowPropertyKeyValue: REVERSE_ARROW_KEY SEMICOLON BOOLEAN										{ $$ = Return0(); }
	;

doubleArrowPropertyKeyValue: DOUBLE_ARROW_KEY SEMICOLON BOOLEAN											{ $$ = Return0(); }
	;

radiusPropertyKeyValue: RADIUS_KEY SEMICOLON NUMBER														{ $$ = Return0(); }
	;

visiblePropertyKeyValue: VISIBLE_KEY SEMICOLON BOOLEAN													{ $$ = Return0(); }
	;

%%
