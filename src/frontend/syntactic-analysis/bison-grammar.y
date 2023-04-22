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
initial: positionlessPlaceable										{ $$ = Return0(); }
	;
//PL0 -> A0 | O0 | L0
positionlessPlaceable: positionlessAlignment							{ $$ = Return0(); }
	| positionlessObject											{ $$ = Return0(); }
	| positionlessLinear											{ $$ = Return0(); }
	;
//PL1 -> A1 | O1 | L1
placeable: alignment												{ $$ = Return0(); }
	| object												{ $$ = Return0(); }
	| linear												{ $$ = Return0(); }
	;
//A0 -> Ka Va0 Ba
positionlessAlignment: keyAlignment positionlessAlignmentProperties bodyAlignment												{ $$ = Return0(); }
	;

//Va0 -> lambda | ()
positionlessAlignmentProperties: %empty												{ $$ = Return0(); }
	| OPEN_PARENTHESIS CLOSE_PARENTHESIS												{ $$ = Return0(); }
	;

//Ba -> { Ba' } | lambda
bodyAlignment: OPEN_BRACKET bodyAlignmentNullable CLOSE_BRACKET 												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Ba' -> PL0, Ba' | lambda
bodyAlignmentNullable: positionlessPlaceable COMMA bodyAlignmentNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Ka -> Row | Column
keyAlignment: ROW_KEY												{ $$ = Return0(); }
	| COLUMN_KEY												{ $$ = Return0(); }
	;

//A1 -> Ka Va1 Ba
alignment: keyAlignment alignmentProperties bodyAlignment												{ $$ = Return0(); }
	;

//VA1 -> (VA1') | lambda
alignmentProperties: OPEN_PARENTHESIS alignmentPropertiesNullable CLOSE_PARENTHESIS												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Va1' -> Pa1, Va1' | lambda
alignmentPropertiesNullable: alignmentProperty COMMA alignmentPropertiesNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Pa1 -> position: Ta
alignmentProperty: POSITION_KEY SEMICOLON ANCHOR												{ $$ = Return0(); }
	;
	
//L0 -> W0 | G0 | E0
positionlessLinear: positionlessArrow												{ $$ = Return0(); }
	| positionlessRope												{ $$ = Return0(); }
	| positionlessSpacer												{ $$ = Return0(); }
	;

//W0 -> Kw Vw0
positionlessArrow: keyArrow positionlessArrowProperties												{ $$ = Return0(); }
	;

//Kw -> Arrow
keyArrow: ARROW_KEY												{ $$ = Return0(); }
	;

//Vw0 -> (vW0') | lambda
positionlessArrowProperties: OPEN_PARENTHESIS positionlessArrowPropertiesNullable CLOSE_PARENTHESIS												{ $$ = Return0(); } 
	| %empty												{ $$ = Return0(); }
	;

//Vw0' -> Pw0, Vw0' | lambda
positionlessArrowPropertiesNullable: positionlessArrowProperty COMMA positionlessArrowPropertiesNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Pw0 -> ...
positionlessArrowProperty: DIRECTION_KEY SEMICOLON DIRECTION_ABS												{ $$ = Return0(); }
	| DIRECTION_KEY SEMICOLON DIRECTION_REL												{ $$ = Return0(); }
	| ANGLE_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| ANGLE_LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	| LENGTH_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| COLOR_KEY SEMICOLON COLOR												{ $$ = Return0(); }
	| LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	| REVERSE_ARROW_KEY SEMICOLON BOOLEAN												{ $$ = Return0(); }
	| DOUBLE_ARROW_KEY SEMICOLON BOOLEAN												{ $$ = Return0(); }
	;

//G0 -> Kg Vg0
positionlessRope: keyRope positionlessRopeProperties												{ $$ = Return0(); }
	;

//Kg -> Rope | Spring
keyRope: ROPE_KEY												{ $$ = Return0(); }
	| SPRING_KEY												{ $$ = Return0(); }
	;

//Vg0 -> ( Vg0' ) | lambda
positionlessRopeProperties: OPEN_PARENTHESIS positionlessRopePropertiesNullable CLOSE_PARENTHESIS												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Vg0' -> Pg0, Vg0' | lambda
positionlessRopePropertiesNullable: positionlessRopeProperty COMMA positionlessRopePropertiesNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Pg0 -> ...
positionlessRopeProperty: LENGTH_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| COLOR_KEY SEMICOLON COLOR												{ $$ = Return0(); }
	| LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	;

//E0 -> Ke Ve0
positionlessSpacer: keySpacer positionlessSpacerProperties												{ $$ = Return0(); }
	;

//Ke -> Spacer
keySpacer: SPACER_KEY												{ $$ = Return0(); }
	;

//Ve0 -> ( Ve0' ) | lambda
positionlessSpacerProperties: OPEN_PARENTHESIS positionlessSpacerPropertiesNullable CLOSE_PARENTHESIS												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Ve0' -> Pe0, Ve0' | lambda
positionlessSpacerPropertiesNullable: positionlessSpacerProperty COMMA positionlessSpacerPropertiesNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Pg0 -> ...
positionlessSpacerProperty: LENGTH_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	;

//L1 -> W1 | G1 | E1
linear: arrow												{ $$ = Return0(); }
	| rope												{ $$ = Return0(); }
	| spacer												{ $$ = Return0(); }
	;

//W1 -> Kw Vw1
arrow: keyArrow arrowProperties												{ $$ = Return0(); }
	;

//Vw1 -> ( Vw1' ) | lambda
arrowProperties: OPEN_PARENTHESIS arrowPropertiesNullable CLOSE_PARENTHESIS 												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Vw1' -> Pw1, Vw1' | lambda
arrowPropertiesNullable: arrowProperty COMMA arrowPropertiesNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Pw1 -> ...
arrowProperty: DIRECTION_KEY SEMICOLON DIRECTION_ABS												{ $$ = Return0(); }
	| DIRECTION_KEY SEMICOLON DIRECTION_REL												{ $$ = Return0(); }
	| ANGLE_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| ANGLE_LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	| POSITION_KEY SEMICOLON ANCHOR												{ $$ = Return0(); }
	| LENGTH_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| COLOR_KEY SEMICOLON COLOR												{ $$ = Return0(); }
	| LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	| REVERSE_ARROW_KEY SEMICOLON BOOLEAN												{ $$ = Return0(); }
	| DOUBLE_ARROW_KEY SEMICOLON BOOLEAN												{ $$ = Return0(); }
	;

//G1 -> Kg Vg1
rope: keyRope ropeProperties												{ $$ = Return0(); }
	;

//Vg1 -> ( vg1' ) | lambda
ropeProperties: OPEN_PARENTHESIS ropePropertiesNullable CLOSE_PARENTHESIS												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Vg1' -> Pg1, Vg1' | lambda
ropePropertiesNullable: ropeProperty COMMA ropePropertiesNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Pg1 -> ...
ropeProperty: POSITION_KEY SEMICOLON ANCHOR												{ $$ = Return0(); }
	| LENGTH_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| COLOR_KEY SEMICOLON COLOR												{ $$ = Return0(); }
	| LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	;

//E1 -> Ke Ve1
spacer: keySpacer spacerProperties												{ $$ = Return0(); }
	;

//Ve1 -> ( ve1' ) | lambda
spacerProperties: OPEN_PARENTHESIS spacerPropertiesNullable CLOSE_PARENTHESIS												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Ve1' -> Pe1, Ve1' | lambda
spacerPropertiesNullable: spacerProperty COMMA spacerPropertiesNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Pe1 -> ...
spacerProperty: POSITION_KEY SEMICOLON ANCHOR												{ $$ = Return0(); }
	| LENGTH_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	;	

//O0 -> N0 | U0 | C0
positionlessObject: positionlessPlane												{ $$ = Return0(); }
	| positionlessBlock												{ $$ = Return0(); }
	| positionlessBall												{ $$ = Return0(); }
	;

// N0 -> Kn Vn0 Bn
positionlessPlane: keyPlane positionlessPlaneProperties bodyPlane												{ $$ = Return0(); }
	;

//Kn -> HorizontalPlane | VerticalPlane
keyPlane: HORIZONTAL_PLANE_KEY												{ $$ = Return0(); }
	| VERTICAL_PLANE_KEY												{ $$ = Return0(); }
	;

//Vn0 -> (Vn0') | lambda
positionlessPlaneProperties: OPEN_PARENTHESIS positionlessPlanePropertiesNullable CLOSE_PARENTHESIS												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Vn0' -> Pn0, Vn0' | lambda
positionlessPlanePropertiesNullable: positionlessPlaneProperty COMMA positionlessPlanePropertiesNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Pn0 -> ...
positionlessPlaneProperty: ANGLE_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| ANGLE_LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	| LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	| LENGTH_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| FRICTION_KEY SEMICOLON BOOLEAN												{ $$ = Return0(); }
	| COLOR_KEY SEMICOLON COLOR												{ $$ = Return0(); }
	| VISIBLE_KEY SEMICOLON BOOLEAN												{ $$ = Return0(); }
	;

//Bn -> { Bn' } | lambda
bodyPlane: OPEN_BRACKET bodyPlaneNullable CLOSE_BRACKET												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Bn' -> PL1, Bn' | lambda
bodyPlaneNullable: placeable COMMA bodyPlaneNullable 												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//U0 -> Ku Vu0 Bu
positionlessBlock: keyBlock positionlessBlockProperties bodyBlock												{ $$ = Return0(); }
	;

//Ku -> Black | Car
keyBlock: BLOCK_KEY												{ $$ = Return0(); }
	| CAR_KEY												{ $$ = Return0(); }
	;

//Vu0 -> (Vu0') | lambda
positionlessBlockProperties: OPEN_PARENTHESIS positionlessBlockPropertiesNullable CLOSE_PARENTHESIS												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Vu0' -> Pu0, Vu0' | lambda
positionlessBlockPropertiesNullable: positionlessBlockProperty COMMA positionlessBlockPropertiesNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Pu0 -> ...
positionlessBlockProperty: HEIGHT_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| WIDTH_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| COLOR_KEY SEMICOLON COLOR												{ $$ = Return0(); }
	| LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	;

//Bu -> { Bu' } | lambda
bodyBlock: OPEN_BRACKET bodyBlockNullable CLOSE_BRACKET												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Bu' -> PL1, Bu' | lambda
bodyBlockNullable: placeable COMMA bodyBlockNullable 												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//C0 -> Kc Vc0 Bc
positionlessBall: keyBall positionlessBallProperties bodyBall												{ $$ = Return0(); }
	;

//Kc -> Ball | Cylinder (el | está en flex porque como se dibujan igual son completamente sinónimos)
keyBall: BALL_KEY												{ $$ = Return0(); }
	;

//Vc0 -> (Vc0') | lambda
positionlessBallProperties: OPEN_PARENTHESIS positionlessBallPropertiesNullable CLOSE_PARENTHESIS												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Vc0' -> Pc0, Vc0' | lambda
positionlessBallPropertiesNullable: positionlessBallProperty COMMA positionlessBallPropertiesNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Pc0 -> ...
positionlessBallProperty: RADIUS_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| COLOR_KEY SEMICOLON COLOR												{ $$ = Return0(); }
	| LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	;

//Bc -> { Bc' } | lambda
bodyBall: OPEN_BRACKET bodyBallNullable CLOSE_BRACKET												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Bc' -> PL1, Bc' | lambda
bodyBallNullable: placeable COMMA bodyBallNullable 												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//O1 -> N1 | U1 | C1
object: plane												{ $$ = Return0(); }
	| block												{ $$ = Return0(); }
	| ball												{ $$ = Return0(); }
	;

// N1 -> Kn Vn1 Bn
plane: keyPlane planeProperties bodyPlane												{ $$ = Return0(); }
	;

//Vn1 -> (Vn1') | lambda
planeProperties: OPEN_PARENTHESIS planePropertiesNullable CLOSE_PARENTHESIS												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Vn1' -> Pn1, Vn1' | lambda
planePropertiesNullable: planeProperty COMMA planePropertiesNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Pn1 -> ...
planeProperty: POSITION_KEY SEMICOLON ANCHOR												{ $$ = Return0(); }
    | ANGLE_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| ANGLE_LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	| LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	| LENGTH_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| FRICTION_KEY SEMICOLON BOOLEAN												{ $$ = Return0(); }
	| COLOR_KEY SEMICOLON COLOR												{ $$ = Return0(); }
	| VISIBLE_KEY SEMICOLON BOOLEAN												{ $$ = Return0(); }
	;

//U1 -> Ku Vu1 Bu
block: keyBlock blockProperties bodyBlock												{ $$ = Return0(); }
	;

//Vu1 -> (Vu1') | lambda
blockProperties: OPEN_PARENTHESIS blockPropertiesNullable CLOSE_PARENTHESIS												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Vu1' -> Pu1, Vu1' | lambda
blockPropertiesNullable: blockProperty COMMA blockPropertiesNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Pu1 -> ...
blockProperty: POSITION_KEY SEMICOLON ANCHOR												{ $$ = Return0(); }
	| HEIGHT_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| WIDTH_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| COLOR_KEY SEMICOLON COLOR												{ $$ = Return0(); }
	| LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	;

//C1 -> Kc Vc1 Bc
ball: keyBall ballProperties bodyBall												{ $$ = Return0(); }
	;

//Vc1 -> (Vc1') | lambda
ballProperties: OPEN_PARENTHESIS ballPropertiesNullable CLOSE_PARENTHESIS												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Vc1' -> Pc1, Vc1' | lambda
ballPropertiesNullable: ballProperty COMMA ballPropertiesNullable												{ $$ = Return0(); }
	| %empty												{ $$ = Return0(); }
	;

//Pc1 -> ...
ballProperty: POSITION_KEY SEMICOLON ANCHOR												{ $$ = Return0(); }
	| RADIUS_KEY SEMICOLON NUMBER												{ $$ = Return0(); }
	| COLOR_KEY SEMICOLON COLOR												{ $$ = Return0(); }
	| LABEL_KEY SEMICOLON STRING												{ $$ = Return0(); }
	;

%%
