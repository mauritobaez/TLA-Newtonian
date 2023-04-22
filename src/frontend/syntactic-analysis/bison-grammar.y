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

	// No-terminales (frontend).
	int initial; //S

	int positionlessPlaceable; // PL0
	int placeable; // PL1 
	
	int positionlessObject; // O0
	int positionlessLinear; // L0
	
	int object; //O1
	int linear; //L1

	int keyObject; // Ko
	int keyLinear; //Kl
	
	// Kx Bx Bx' X0 X1 Vx0 Vx0' Px0 Vx1 Vx1' Px1
	// a w g e n u c

	int keyAlignment; // Ka
	int bodyAlignment; // Ba
	int bodyAlignmentNullable; //Ba'
	int positionlessAlignment; // A0
	int alignment; //A1
	int positionlessAlignmentProperties; //Va0
	//positionlessAlignment no tiene ninguna property -> no hay Va0' ni Pa0
	int alignmentProperties; // Va1
	int alignmentPropertiesNullable; //Va1'
	int alignmentProperty; // Pa1

	int keyArrow; //Kw
	//No tiene body
	int positionlessArrow; //W0
	int arrow; //W1
	int positionlessArrowProperties; //VW0
	int positionlessArrowPropertiesNullable; //VW0'
	int positionlessArrowProperty;//PW0
	int arrowProperties; //VW1
	int arrowPropertiesNullable; // VW1'
	int arrowProperty; //PW1
	
	int keyRope; // Kg
	//No tiene Body
	int positionlessRope; //G0
	int rope; //G1
	int positionlessRopeProperties; //VG0
	int positionlessRopePropertiesNullable; //VG0'
	int positionlessRopeProperty; // PG0
	int ropeProperties; // VG1
	int ropePropertiesNullable; // VG1'
	int ropeProperty; // PG1

	int keySpacer; // Ke
	//No tiene Body
	int positionlessSpacer; //E0
	int spacer; //E1
	int positionlessSpacerProperties; //VE0
	int positionlessSpacerPropertiesNullable; //VE0'
	int positionlessSpacerProperty; // PE0
	int spacerProperties; // VE1
	int spacerPropertiesNullable; // VE1'
	int spacerProperty; // PE1

	int keyPlane; //Kn
	int bodyPlane; //Bn
	int bodyPlaneNullable;  //Bn'
	int positionlessPlane; //N0
	int plane; // N1
	int positionlessPlaneProperties; //VN0
	int positionlessPlanePropertiesNullable; //VN0'
	int positionlessPlaneProperty; //PN0
	int planeProperties; //VN1
	int planePropertiesNullable;//VN1'
	int planeProperty; // PN1

	int keyBlock; //Ku
	int bodyBlock; //Bu
	int bodyBlockNullable;  //Bu'
	int positionlessBlock; //U0
	int block; // U1
	int positionlessBlockProperties; //VU0
	int positionlessBlockPropertiesNullable; //VU0'
	int positionlessBlockProperty;//PU0
	int blockProperties;//VU1
	int blockPropertiesNullable;//VU1'
	int blockProperty;//PU1

	int keyBall; //Kc
	int bodyBall; //Bc
	int bodyBallNullable;  //Bc'
	int positionlessBall; //C0
	int ball; //C1
	int positionlessBallProperties; //VC0
	int positionlessBallPropertiesNullable;//VC0'
	int positionlessBallProperty; //PC0
	int ballProperties; //VC1
	int ballPropertiesNullable;//VC1'
	int ballProperty; //PC1

	// Terminales.
	token token;
	float number; //Tn 
	anchor_t anchor; //Ta
	direction_t direction; //Td
	color_t color; //Tc
	bool_t boolean; //Tb
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
%token <token> CYLINDER_KEY
%token <token> ARROW_KEY
%token <token> SPRING_KEY
%token <token> ROPE_KEY
%token <token> SPACER_KEY
%token <token> POSITION_KEY
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
%type <initial> initial //S
%type <positionlessPlaceable> positionlessPlaceable // PL0
%type <placeable> placeable // PL1 
%type <positionlessObject> positionlessObject // O0
%type <positionlessLinear> positionlessLinear // L0
%type <object> object //O1
%type <linear> linear //L1
%type <keyObject> keyObject // Ko
%type <keyLinear> keyLinear //Kl
%type <keyAlignment> keyAlignment // Ka
%type <bodyAlignment> bodyAlignment // Ba
%type <bodyAlignmentNullable> bodyAlignmentNullable //Ba'
%type <positionlessAlignment> positionlessAlignment // A0
%type <alignment> alignment //A1
%type <positionlessAlignmentProperties> positionlessAlignmentProperties //Va0
%type <alignmentProperties> alignmentProperties // Va1
%type <alignmentPropertiesNullable> alignmentPropertiesNullable //Va1'
%type <alignmentProperty> alignmentProperty // Pa1
%type <keyArrow> keyArrow //Kw
%type <positionlessArrow> positionlessArrow //W0
%type <arrow> arrow //W1
%type <positionlessArrowProperties> positionlessArrowProperties //VW0
%type <positionlessArrowPropertiesNullable> positionlessArrowPropertiesNullable //VW0'
%type <positionlessArrowProperty> positionlessArrowProperty //PW0
%type <arrowProperties> arrowProperties //VW1
%type <arrowPropertiesNullable> arrowPropertiesNullable // VW1'
%type <arrowProperty> arrowProperty //PW1
%type <keyRope> keyRope // Kg
%type <positionlessRope> positionlessRope //G0
%type <rope> rope //G1
%type <positionlessRopeProperties> positionlessRopeProperties //VG0
%type <positionlessRopePropertiesNullable> positionlessRopePropertiesNullable //VG0'
%type <positionlessRopeProperty> positionlessRopeProperty // PG0
%type <ropeProperties> ropeProperties // VG1
%type <ropePropertiesNullable> ropePropertiesNullable // VG1'
%type <ropeProperty> ropeProperty // PG1
%type <keySpacer> keySpacer // Ke
%type <positionlessSpacer> positionlessSpacer //E0
%type <spacer> spacer //E1
%type <positionlessSpacerProperties> positionlessSpacerProperties //VE0
%type <positionlessSpacerPropertiesNullable> positionlessSpacerPropertiesNullable //VE0'
%type <positionlessSpacerProperty> positionlessSpacerProperty // PE0
%type <spacerProperties> spacerProperties // VE1
%type <spacerPropertiesNullable> spacerPropertiesNullable // VE1'
%type <spacerProperty> spacerProperty // PE1
%type <keyPlane> keyPlane //Kn
%type <bodyPlane> bodyPlane //Bn
%type <bodyPlaneNullable> bodyPlaneNullable  //Bn'
%type <positionlessPlane> positionlessPlane //N0
%type <plane> plane // N1
%type <positionlessPlaneProperties> positionlessPlaneProperties //VN0
%type <positionlessPlanePropertiesNullable> positionlessPlanePropertiesNullable //VN0'
%type <positionlessPlaneProperty> positionlessPlaneProperty //PN0
%type <planeProperties> planeProperties //VN1
%type <planePropertiesNullable> planePropertiesNullable //VN1'
%type <planeProperty> planeProperty // PN1
%type <keyBlock> keyBlock //Ku
%type <bodyBlock> bodyBlock //Bu
%type <bodyBlockNullable> bodyBlockNullable  //Bu'
%type <positionlessBlock> positionlessBlock //U0
%type <block> block // U1
%type <positionlessBlockProperties> positionlessBlockProperties //VU0
%type <positionlessBlockPropertiesNullable> positionlessBlockPropertiesNullable //VU0'
%type <positionlessBlockProperty> positionlessBlockProperty //PU0
%type <blockProperties> blockProperties //VU1
%type <blockPropertiesNullable> blockPropertiesNullable //VU1'
%type <blockProperty> blockProperty //PU1
%type <keyBall> keyBall //Kc
%type <bodyBall> bodyBall //Bc
%type <bodyBallNullable> bodyBallNullable  //Bc'
%type <positionlessBall> positionlessBall //C0
%type <ball> ball //C1
%type <positionlessBallProperties> positionlessBallProperties //VC0
%type <positionlessBallPropertiesNullable> positionlessBallPropertiesNullable //VC0'
%type <positionlessBallProperty> positionlessBallProperty //PC0
%type <ballProperties> ballProperties //VC1
%type <ballPropertiesNullable> ballPropertiesNullable //VC1'
%type <ballProperty> ballProperty //PC1

// Reglas de asociatividad y precedencia (de menor a mayor).
/* %left ADD SUB
%left MUL DIV */

// El símbolo inicial de la gramatica.
%start initial

%%
// S -> PL0
initial: positionlessPlaceable										{ $$ = return0(); }
	;
//PL0 -> A0 | O0 | L0
positionlessPlaceable: positionlessAlignment							{ $$ = return0(); }
	| positionlessObject											{ $$ = return0(); }
	| positionlessLinear											{ $$ = return0(); }
	;
//PL1 -> A1 | O1 | L1
placeable: alignment
	| object
	| linear
	;
//A0 -> Ka Va0 Ba
positionlessAlignment: keyAlignment positionlessAlignmentProperties bodyAlignment
	;

//Va0 -> lambda | ()
positionlessAlignmentProperties: %empty
	| OPEN_PARENTHESIS CLOSE_PARENTHESIS
	;

//Ba -> { Ba' } | lambda
bodyAlignment: OPEN_BRACKET bodyAlignmentNullable CLOSE_BRACKET 
	| %empty
	;

//Ba' -> PL0, Ba' | lambda
bodyAlignmentNullable: positionlessPlaceable COMMA bodyAlignmentNullable
	| %empty
	;

//Ka -> Row | Column
Ka: ROW_KEY
	| COLUMN_KEY
	;

//A1 -> Ka Va1 Ba
alignment: keyAlignment alignmentProperties bodyAlignment
	;

//VA1 -> (VA1') | lambda
alignmentProperties: OPEN_PARENTHESIS alignmentPropertiesNullable CLOSE_PARENTHESIS
	| %empty
	;

//Va1' -> Pa1, Va1' | lambda
alignmentPropertiesNullable: alignmentProperty COMMA alignmentPropertiesNullable
	| %empty
	;

//Pa1 -> position: Ta
alignmentProperty: POSITION_KEY SEMICOLON ANCHOR
	;
	
//L0 -> W0 | G0
positionlessLinear: positionlessArrow
	| positionlessRope
	;

// W0 -> Kw Vw0
positionlessArrow: keyArrow positionlessArrowProperties
	;

//Kw -> Arrow
keyArrow: ARROW_KEY
	;

//Vw0 -> (vW0') | lambda
positionlessArrowProperties: OPEN_PARENTHESIS positionlessArrowPropertiesNullable CLOSE_PARENTHESIS 
	| %empty
	;

//Vw0' -> Pw0, Vw0' | lambda
positionlessArrowPropertiesNullable: positionlessArrowProperty COMMA positionlessArrowPropertiesNullable
	| %empty
	;

//Pw0 -> ...
positionlessArrowProperty: DIRECTION_KEY SEMICOLON DIRECTION_ABS
	| DIRECTION_KEY SEMICOLON DIRECTION_REL
	| ANGLE_KEY SEMICOLON NUMBER
	| ANGLE_LABEL_KEY SEMICOLON STRING
	| LENGTH_KEY SEMICOLON NUMBER
	| COLOR_KEY SEMICOLON COLOR
	| LABEL_KEY SEMICOLON STRING
	| REVERSE_ARROW_KEY SEMICOLON BOOLEAN
	| DOUBLE_ARROW_KEY SEMICOLON BOOLEAN
	;

positionlessRope: ROPE_KEY positionlessRopeProperties
	| SPRING_KEY positionlessRopeProperties
	;

positionlessRopeProperties: OPEN_PARENTHESIS positionlessRopePropertiesNullable CLOSE_PARENTHESIS
	| %empty
	;

positionlessRopePropertiesNullable: positionlessRopeProperty COMMA positonlessRopePropertiesNullable
	| %empty
	;

positionlessRopeProperty: POSITION_KEY SEMICOLON DIRECTION_ABS
	| POSITION_KEY SEMICOLON DIRECTION_REL
	| LENGTH_KEY SEMICOLON NUMBER
	| COLOR_KEY SEMICOLON COLOR
	| LABEL_KEY SEMICOLON STRING
	;

linear: arrow
	| rope
	;

arrow: ARROW_KEY arrowProperties
	;

arrowProperties: OPEN_PARENTHESIS arrowPropertiesNullable CLOSE_PARENTHESIS 
	| %empty
	;

arrowPropertiesNullable: arrowProperty COMMA arrowPropertiesNullable
	| %empty
	;

arrowPropertiesNullable: DIRECTION_KEY SEMICOLON DIRECTION_ABS
	| ANGLE_KEY SEMICOLON NUMBER
	| ANGLE_LABEL_KEY SEMICOLON STRING
	| POSITION_KEY SEMICOLON DIRECTION_ABS /* esto es abs o rel? */
	| LENGTH_KEY SEMICOLON NUMBER
	| COLOR_KEY SEMICOLON COLOR
	| LABEL_KEY SEMICOLON STRING
	| REVERSE_ARROW_KEY
	| DOUBLE_ARROW_KEY
	;

rope: ROPE_KEY ropeProperties
	| SPRING_KEY ropeProperties
	;

ropeProperties: OPEN_PARENTHESIS ropePropertiesNullable CLOSE_PARENTHESIS
	| %empty
	;

ropePropertiesNullable: ropeProperty COMMA ropePropertiesNullable
	| %empty
	;

ropeProperty: POSITION_KEY SEMICOLON DIRECTION_ABS /* TODO: abs o rel?*/
	| LENGTH_KEY SEMICOLON NUMBER
	| COLOR_KEY SEMICOLON COLOR
	| LABEL_KEY SEMICOLON STRING
	;

positionlessObject: positionlessPlane
	| positionlessBlock
	| positionlessBall
	;

positionlessPlane: keyPlane positionlessPlaneProperties bodyPlane
	;

keyPlane: HORIZONTAL_PLANE_KEY
	| VERTICAL_PLANE_KEY
	;

bodyPlane: OPEN_BRACKET bodyPlaneNullable CLOSE_BRACKET
	| %empty
	;

bodyPlaneNullable: placeable COMMA bodyPlaneNullable 
	| %empty
	;

positionlessBlock: keyBlock positionlessBlockProperties bodyBlock
	;

keyBlock: BLOCK_KEY
	| CAR_KEY
	;

bodyBlock: OPEN_BRACKET bodyBlockNullable CLOSE_BRACKET
	| %empty
	;

bodyBlockNullable: placeable COMMA bodyBlockNullable 
	| %empty
	;

positionlessBall: keyBall positionlessBallProperties bodyBall
	;

keyBall: BALL_KEY
	| CYLINDER_KEY /*no sé si está en flex*/
	;

bodyBall: OPEN_BRACKET bodyBallNullable CLOSE_BRACKET
	| %empty
	;

bodyBallNullable: placeable COMMA bodyBallNullable 
	| %empty
	;



%%
