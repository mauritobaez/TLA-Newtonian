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
	int program;
	int expression;
	int factor;
	int constant;

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
%type <program> program
%type <expression> expression
%type <factor> factor
%type <constant> constant

// Reglas de asociatividad y precedencia (de menor a mayor).
%left ADD SUB
%left MUL DIV

// El símbolo inicial de la gramatica.
%start program

%%

program: expression													{ $$ = ProgramGrammarAction($1); }
	;

expression: expression[left] ADD expression[right]					{ $$ = AdditionExpressionGrammarAction($left, $right); }
	| expression[left] SUB expression[right]						{ $$ = SubtractionExpressionGrammarAction($left, $right); }
	| expression[left] MUL expression[right]						{ $$ = MultiplicationExpressionGrammarAction($left, $right); }
	| expression[left] DIV expression[right]						{ $$ = DivisionExpressionGrammarAction($left, $right); }
	| factor														{ $$ = FactorExpressionGrammarAction($1); }
	;

factor: OPEN_PARENTHESIS expression CLOSE_PARENTHESIS				{ $$ = ExpressionFactorGrammarAction($2); }
	| constant														{ $$ = ConstantFactorGrammarAction($1); }
	;

constant: NUMBER													{ $$ = IntegerConstantGrammarAction($1); }
	;

%%
