#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>

/**
 * Implementación de "flex-actions.h".
 *
 * Cada función debe realizar 2 operaciones básicas para lograr el streaming
 * de tokens hacia Bison:
 *
 *	1) Computar los atributos del token y almacenarlos donde sea conveniente
 *		(en la tabla de símbolos, en "yylval", o en ambos).
 *	2) Retornar el token que identifica el terminal identificado.
 *
 * Bison utilizará el token retornado en el punto (2) para matchear dicho
 * terminal en la gramática. Por otro lado, el valor almacenado en "yylval" es
 * el que Bison proveerá como valor semántico al realizar una reducción
 * (mediante $1, $2, $3, etc.).
 */

void BeginCommentPatternAction() {
	LogDebug("BeginCommentPatternAction.");
}

void EndCommentPatternAction() {
	LogDebug("EndCommentPatternAction.");
}

// empieza chatGPT





// Function for OpenParenthesis
token OpenParenthesisAction(const char * lexeme) {
    LogDebug("OpenParenthesisAction: '%s'.", lexeme);
    yylval.token = OPEN_PARENTHESIS;
    return OPEN_PARENTHESIS;
}

// Function for CloseParenthesis
token CloseParenthesisAction(const char * lexeme) {
    LogDebug("CloseParenthesisAction: '%s'.", lexeme);
    yylval.token = CLOSE_PARENTHESIS;
    return CLOSE_PARENTHESIS;
}

// Function for OpenBracket
token OpenBracketAction(const char * lexeme) {
    LogDebug("OpenBracketAction: '%s'.", lexeme);
    yylval.token = OPEN_BRACKET;
    return OPEN_BRACKET;
}

// Function for CloseBracket
token CloseBracketAction(const char * lexeme) {
    LogDebug("CloseBracketAction: '%s'.", lexeme);
    yylval.token = CLOSE_BRACKET;
    return CLOSE_BR
}

// Function for Comma
token CommaAction(const char * lexeme) {
    LogDebug("CommaAction: '%s'.", lexeme);
    yylval.token = COMMA;
    return COMMA;
}

// Function for Row
token RowAction(const char * lexeme) {
    LogDebug("RowAction: '%s'.", lexeme);
    yylval.token = ROW;
    return ROW;
}

// Function for Column
token ColumnAction(const char * lexeme) {
    LogDebug("ColumnAction: '%s'.", lexeme);
    yylval.token = COLUMN;
    return COLUMN;
}

// Function for Friction
token FrictionAction(const char * lexeme) {
    LogDebug("FrictionAction: '%s'.", lexeme);
    yylval.token = FRICTION;
    return FRICTION;
}

// Function for Position
token PositionAction(const char * lexeme) {
    LogDebug("PositionAction: '%s'.", lexeme);
    yylval.token = POSITION;
    return POSITION;
}

// Function for Color
token ColorAction(const char * lexeme) {
    LogDebug("ColorAction: '%s'.", lexeme);
    yylval.token = COLOR;
    return COLOR;
}

// Function for Label
token LabelAction(const char * lexeme) {
    LogDebug("LabelAction: '%s'.", lexeme);
    yylval.token = LABEL;
    return LABEL;
}

// Function for top
token TopAction(const char * lexeme) {
    LogDebug("TopAction: '%s'.", lexeme);
    yylval.token = TOP;
    return TOP;
}

// Function for bottom
token BottomAction(const char * lexeme) {
    LogDebug("BottomAction: '%s'.", lexeme);
    yylval.token = BOTTOM;
    return BOTTOM;
}

// Function for left
token LeftAction(const char * lexeme) {
    LogDebug("LeftAction: '%s'.", lexeme);
    yylval.token = LEFT;
    return LEFT;
}

// Function for right
token RightAction(const char * lexeme) {
    LogDebug("RightAction: '%s'.", lexeme);
    yylval.token = RIGHT;
    return RIGHT;
}

// Function for Semicolon
token SemicolonAction(const char * lexeme) {
    LogDebug("SemicolonAction: '%s'.", lexeme);
    yylval.token = SEMICOLON;
    return SEMICOLON;
}

// Function for AnchorA
token AnchorAAction(const char * lexeme) {
    LogDebug("AnchorAAction: '%s'.", lexeme);
    yylval.token = ANCHOR_A;
    return ANCHOR_A;
}

// Function for Arrow0
token ArrowAction(const char * lexeme) {
    LogDebug("Arrow0Action: '%s'.", lexeme);
    yylval.token = ARROW_0;
    return ARROW_0;
}

// Function for Direction
token DirectionAction(const char * lexeme) {
    LogDebug("DirectionAction: '%s'.", lexeme);
    yylval.token = DIRECTION;
    return DIRECTION;
}

// Function for center
token CenterAction(const char * lexeme) {
    LogDebug("CenterAction: '%s'.", lexeme);
    yylval.token = CENTER;
    return CENTER;
}

// Function for Angle
token AngleAction(const char * lexeme) {
    LogDebug("AngleAction: '%s'.", lexeme);
    yylval.token = ANGLE;
    return ANGLE;
}

// Function for HorizontalPlane
token HorizontalPlaneAction(const char * lexeme) {
    LogDebug("HorizontalPlaneAction: '%s'.", lexeme);
    yylval.token = HORIZONTAL_PLANE;
    return HORIZONTAL_PLANE;
}

// Function for VerticalPlane
token VerticalPlaneAction(const char * lexeme) {
    LogDebug("VerticalPlaneAction: '%s'.", lexeme);
    yylval.token = VERTICAL_PLANE;
    return VERTICAL_PLANE;
}

// Function for Angle-label
token AngleLabelAction(const char * lexeme) {
    LogDebug("AngleLabelAction: '%s'.", lexeme);
    yylval.token = ANGLE_LABEL;
    return ANGLE_LABEL;
}

// Function for RopeVG0
token RopeAction(const char * lexeme) {
    LogDebug("RopeVG0Action: '%s'.", lexeme);
    yylval.token = ROPE_VG_0;
    return ROPE_VG_0;
}

// Function for SpringVG0
token SpringAction(const char * lexeme) {
    LogDebug("SpringVG0Action: '%s'.", lexeme);
    yylval.token = SPRING_VG_0;
    return SPRING_VG_0;
}

// Function for Block
token BlockAction(const char * lexeme) {
    LogDebug("BlockAction: '%s'.", lexeme);
    yylval.token = BLOCK;
    return BLOCK;
}

// Function for width
token WidthAction(const char * lexeme) {
    LogDebug("WidthAction: '%s'.", lexeme);
    yylval.token = WIDTH;
    return WIDTH;
}

// Function for length
token LengthAction(const char * lexeme) {
    LogDebug("LengthAction: '%s'.", lexeme);
    yylval.token = LENGTH;
    return LENGTH;
}

// Function for Ball
token BallAction(const char * lexeme) {
    LogDebug("BallAction: '%s'.", lexeme);
    yylval.token = BALL;
    return BALL;
}

// Function for spacer
token SpacerAction(const char * lexeme) {
    LogDebug("SpacerAction: '%s'.", lexeme);
    yylval.token = SPACER;
    return SPACER;
}

// Function for reverse-arrow
token ReverseArrowAction(const char * lexeme) {
    LogDebug("ReverseArrowAction: '%s'.", lexeme);
    yylval.token = REVERSE_ARROW;
    return REVERSE_ARROW;
}

// Function for radius
token RadiusAction(const char * lexeme) {
    LogDebug("RadiusAction: '%s'.", lexeme);
    yylval.token = RADIUS;
    return RADIUS;
}

// Function for color
token ColorAction(const char * lexeme) {
    LogDebug("ColorAction: '%s'.", lexeme);
    yylval.token = COLOR;
    return COLOR;
}

//Termina chatGPT

token UnknownPatternAction(const char * lexeme, const int length) {
	LogDebug("UnknownPatternAction: '%s' (length = %d).", lexeme, length);
	yylval.token = YYUNDEF;
	// Al emitir este token, el compilador aborta la ejecución.
	return YYUNDEF;
}

void IgnoredPatternAction(const char * lexeme, const int length) {
	LogDebug("IgnoredPatternAction: '%s' (length = %d).", lexeme, length);
	// Como no debe hacer nada con el patrón, solo se loguea en consola.
}
