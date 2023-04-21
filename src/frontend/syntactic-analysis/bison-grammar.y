%{

#include "bison-actions.h"

%}

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
	int integer;
	float number;
}

// IDs y tipos de los tokens terminales generados desde Flex.

%token <token> OPEN_BRACKET
%token <token> CLOSE_BRACKET
%token <token> COMMA
%token <token> ALIGNMENT_KEY
%token <token> SPRING_ROPE_KEY
%token <token> ARROW_KEY
%token <token> BALL_KEY
%token <token> BLOCK_KEY
%token <token> PLANE_KEY
%token <token> FRICTION
%token <token> POSITION
%token <token> COLOR
%token <token> LABEL
%token <token> SEMICOLON
%token <token> ANCHOR_A
%token <token> ARROW
%token <token> DIRECTION
%token <token> CENTER
%token <token> ANGLE
%token <token> HORIZONTAL_PLANE
%token <token> VERTICAL_PLANE
%token <token> ANGLE_LABEL
%token <token> ROPE
%token <token> SPRING
%token <token> BLOCK
%token <token> HEIGHT
%token <token> WIDTH
%token <token> LENGTH
%token <token> BALL
%token <token> SPACER
%token <token> REVERSE_ARROW
%token <token> RADIUS
%token <token> FLOAT
%token <token> VISIBLE_KEY

%token <token> OPEN_PARENTHESIS
%token <token> CLOSE_PARENTHESIS


%token <integer> INTEGER

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

constant: INTEGER													{ $$ = IntegerConstantGrammarAction($1); }
	;

%%
