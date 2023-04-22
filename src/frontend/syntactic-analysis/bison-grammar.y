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
	int initial;

	int positionlessPlaceable; // PL0
	int placeable; // PL1 
	int positionlessAlignment; // A0
	int positionlessObject; // O0
	int positionlessLinear; // L0
	int alignment; //A1
	int object; //O1
	int linear; //L1

	int keyAlignment; // Ka
	int keyObject; // Ko
	int keyLinear; //Kl

	int positionlessAlignmentBody; // Ba
	int positionlessAlignmentBodyNullable //Ba'
	int body; //B
	int bodyNullable;  //B'

	int positionlessAlignmentProperties; //Va0
	int propertiesAlignment; // Va1
	int propertiesAlignmentNullable; //Va1'
	int alignmentProperty; // Pa1

	int positionlessArrow; //W0
	int arrow; //W1
	int positionlessArrowProperties; //VW0
	int positionlessArrowPropertiesNullable; //VW0'
	int positionlessArrowProperty;//PW0
	int arrowProperties; //VW1
	int arrowPropertiesNullable; // VW1'
	int arrowProperty; //PW0
	
	int positionlessRope; //G0
	int rope; //G1
	int keyRope; //Rope | Spring
	int positionlessRopeProperties; //VG0
	int positionlessRopePropertiesNullable; //VG0'
	int positionlessRopeProperty; // PG0
	int ropeProperties; // VG1
	int ropePropertiesNullable; // VG1'
	int ropeProperty; // PG1

	int positionlessBlock;//U0
	int block; // U1 
	int keyBlock; // Block | Car
	int positionlessBlockProperties; //VU0
	int positionlessBlockPropertiesNullable; //VU0'
	int positionlessBlockProperty;//PU0
	int blockProperties;//VU1
	int blockPropertiesNullable;//VU1'
	int blockProperty;//PU1

	int positionlessBall; //C0
	int ball; //C1
	int keyBall; // Ball | Cylinder
	int positionlessBallProperties; //VC0
	int positionlessBallPropertiesNullable;//VC0'
	int positionlessBallProperty; //PC0
	int ballProperties; //VC1
	int ballPropertiesNullable;//VC1'
	int ballProperty;//PC1


	int positionlessPlane;//N0
	int plane; // N1
	int keyPlane; // HorizontalPlane | VerticalPlane
	int positionlessPlaneProperties;//VN0
	int positionlessPlanePropertiesNullable;//VN0'
	int positionlessPlaneProperty;//PN0
	int planeProperties; //VN1
	int planePropertiesNullable;//VN1'
	int planeProperty; // PN1

	// Terminales.
	token token;
	float number;
	anchor_t anchor;
	direction_t direction;
	color_t color;
	bool_t boolean;
	char* string;
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
%type <initial> initial

%type <positionlessPlaceable> positionlessPlaceable
%type <placeable> placeable
%type <positionlessAlignment> positionlessAlignment
%type <positionlessObject> positionlessObject
%type <positionlessLinear> positionlessLinear
%type <alignment> alignment
%type <object> object
%type <linear> linear

%type <keyAlignment> keyAlignment
%type <keyObject> keyObject
%type <keyLinear> keyLinear

%type <positionlessAlignmentBody> positionlessAlignmentBody; // Ba
%type <pos> positionlessAlignmentBodyNullable //Ba'
%type <> body; //B
%type <> bodyNullable;  //B'

%type <> positionlessAlignmentProperties; //Va0
%type <> propertiesAlignment; // Va1
%type <> propertiesAlignmentNullable; //Va1'
%type <> alignmentProperty; // Pa1

%type <> positionlessArrow; //W0
%type <> arrow; //W1
%type <> positionlessArrowProperties; //VW0
%type <> positionlessArrowPropertiesNullable; //VW0'
%type <> positionlessArrowProperty;//PW0
%type <> arrowProperties; //VW1
%type <> arrowPropertiesNullable; // VW1'
%type <> arrowProperty; //PW0
%type <>
%type <> positionlessRope; //G0
%type <> rope; //G1
%type <> keyRope; //Rope | Spring
%type <> positionlessRopeProperties; //VG0
%type <> positionlessRopePropertiesNullable; //VG0'
%type <> positionlessRopeProperty; // PG0
%type <> ropeProperties; // VG1
%type <> ropePropertiesNullable; // VG1'
%type <> ropeProperty; // PG1

%type <> positionlessBlock;//U0
%type <> block; // U1 
%type <> keyBlock; // Block | Car
%type <> positionlessBlockProperties; //VU0
%type <> positionlessBlockPropertiesNullable; //VU0'
%type <> positionlessBlockProperty;//PU0
%type <> blockProperties;//VU1
%type <> blockPropertiesNullable;//VU1'
%type <> blockProperty;//PU1

%type <> positionlessBall; //C0
%type <> ball; //C1
%type <> keyBall; // Ball | Cylinder
%type <> positionlessBallProperties; //VC0
%type <> positionlessBallPropertiesNullable;//VC0'
%type <> positionlessBallProperty; //PC0
%type <> ballProperties; //VC1
%type <> ballPropertiesNullable;//VC1'
%type <> ballProperty;//PC1


%type <> positionlessPlane;//N0
%type <> plane; // N1
%type <> keyPlane; // HorizontalPlane | VerticalPlane
%type <> positionlessPlaneProperties;//VN0
%type <> positionlessPlanePropertiesNullable;//VN0'
%type <> positionlessPlaneProperty;//PN0
%type <> planeProperties; //VN1
%type <> planePropertiesNullable;//VN1'
%type <> planeProperty; // PN1

// Reglas de asociatividad y precedencia (de menor a mayor).
%left ADD SUB
%left MUL DIV

// El símbolo inicial de la gramatica.
%start initial

%%

initial: positionlessPlaceable										{ $$ = return0(); }
	;

positionlessPlaceable: positionlessAlignment							{ $$ = return0(); }
	| positionlessObject											{ $$ = return0(); }
	| positionlessLinear											{ $$ = return0(); }
	;

placeable: alignment
	| object
	| linear
	;

positionlessAlignment: Ka Va0 Ba
	;

Va0: lamda
	| OPEN_PARENTHESIS CLOSE_PARENTHESIS
	;

Ba: OPEN_BRACKET BaPrime CLOSE_BRACKET 
	| lamda
	;

BaPrime: positionlessPlaceable COMMA BaPrime
	| lamda
	;

Ka: ROW_KEY
	| COLUMN_KEY
	;

alignment: Ka Va1 Ba
	;

Va1: OPEN_PARENTHESIS Va1Prime CLOSE_PARENTHESIS
	| lamda
	;

Va1Prime: Pa1 COMMA Va1Prime  /*podría poner Pa1 COMMA Va0Prime ?*/
	| lamda
	;

Pa1: POSITION_KEY SEMICOLON ANCHOR /*acá faltarían los otros*/
	;
	
positionlessLinear: W0
	| G0
	;

W0: ARROW_KEY Vw0
	;

Vw0: OPEN_PARENTHESIS Vw0Prime CLOSE_PARENTHESIS 
	| lamda
	;

Vw0Prime: Pw0 COMMA Vw0Prime
	| lamda
	;

Pw0: DIRECTION_KEY SEMICOLON DIRECTION_ABS
	| ANGLE_KEY SEMICOLON NUMBER
	| ANGLE_LABEL_KEY SEMICOLON STRING
	| POSITION_KEY SEMICOLON DIRECTION_ABS /* esto es abs o rel? */
	| LENGTH_KEY SEMICOLON NUMBER
	| COLOR_KEY SEMICOLON COLOR
	| LABEL_KEY SEMICOLON STRING
	| REVERSE_ARROW_KEY
	| DOUBLE_ARROW_KEY
	;

G0: ROPE_KEY VG0
	| SPRING_KEY VG0
	;

VG0: OPEN_PARENTHESIS VG0Prime CLOSE_PARENTHESIS
	| lamda
	;

VG0Prime: Pg0 COMMA VG0Prime
	| lamda
	;

Pg0: POSITION_KEY SEMICOLON DIRECTION_ABS /*abs o rel?*/
	| LENGTH_KEY SEMICOLON NUMBER
	| COLOR_KEY SEMICOLON COLOR
	| LABEL_KEY SEMICOLON STRING
	;

linear: W1
	| G1
	;

W1: ARROW_KEY Vw1
	;

Vw1: OPEN_PARENTHESIS Vw1Prime CLOSE_PARENTHESIS 
	| lamda
	;

Vw1Prime: Pw1 COMMA Vw1Prime
	| lamda
	;

Pw1: DIRECTION_KEY SEMICOLON DIRECTION_ABS
	| ANGLE_KEY SEMICOLON NUMBER
	| ANGLE_LABEL_KEY SEMICOLON STRING
	| POSITION_KEY SEMICOLON DIRECTION_ABS /* esto es abs o rel? */
	| LENGTH_KEY SEMICOLON NUMBER
	| COLOR_KEY SEMICOLON COLOR
	| LABEL_KEY SEMICOLON STRING
	| REVERSE_ARROW_KEY
	| DOUBLE_ARROW_KEY
	;

G1: ROPE_KEY VG1
	| SPRING_KEY VG1
	;

VG1: OPEN_PARENTHESIS VG1Prime CLOSE_PARENTHESIS
	| lamda
	;

VG1Prime: Pg1 COMMA VG1Prime
	| lamda
	;

Pg1: POSITION_KEY SEMICOLON DIRECTION_ABS /*abs o rel?*/
	| LENGTH_KEY SEMICOLON NUMBER
	| COLOR_KEY SEMICOLON COLOR
	| LABEL_KEY SEMICOLON STRING
	;

positionlessObject: N0
	| U0
	| C0
	;

N0: Kn Vn0 Bn
	;

Kn: HORIZONTAL_PLANE_KEY
	| VERTICAL_PLANE_KEY
	;

Bn: OPEN_BRACKET BnPrime CLOSE_BRACKET
	| lamda
	;

BnPrime: placeable COMMA BnPrime 
	| lamda
	;

U0: Ku Vu0 Bu
	;

Ku: BLOCK_KEY
	| CAR_KEY
	;

Bu: OPEN_BRACKET BuPrime CLOSE_BRACKET
	| lamda
	;

BuPrime: placeable COMMA BuPrime 
	| lamda
	;

C0: Kc Vc0 Bc
	;

Kc: BALL_KEY
	| CYLINDER_KEY /*no sé si está en flex*/
	;

Bc: OPEN_BRACKET BcPrime CLOSE_BRACKET
	| lamda
	;

BcPrime: placeable COMMA BcPrime 
	| lamda
	;



%%
