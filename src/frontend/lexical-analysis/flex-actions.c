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

// Function for PropertyPairLinearObject0
token PropertyPairLinearObject0Action(const char * lexeme) {
    LogDebug("PropertyPairLinearObject0Action: '%s'.", lexeme);
    yylval.token = PROPERTY_PAIR_LINEAR_OBJECT_0;
    return PROPERTY_PAIR_LINEAR_OBJECT_0;
}

// Function for PropertyPairLinearObject1
token PropertyPairLinearObject1Action(const char * lexeme) {
    LogDebug("PropertyPairLinearObject1Action: '%s'.", lexeme);
    yylval.token = PROPERTY_PAIR_LINEAR_OBJECT_1;
    return PROPERTY_PAIR_LINEAR_OBJECT_1;
}

// Function for Alignment0
token Alignment0Action(const char * lexeme) {
    LogDebug("Alignment0Action: '%s'.", lexeme);
    yylval.token = ALIGNMENT_0;
    return ALIGNMENT_0;
}

// Function for Alignment1
token Alignment1Action(const char * lexeme) {
    LogDebug("Alignment1Action: '%s'.", lexeme);
    yylval.token = ALIGNMENT_1;
    return ALIGNMENT_1;
}

// Function for Object0
token Object0Action(const char * lexeme) {
    LogDebug("Object0Action: '%s'.", lexeme);
    yylval.token = OBJECT_0;
    return OBJECT_0;
}

// Function for Object1
token Object1Action(const char * lexeme) {
    LogDebug("Object1Action: '%s'.", lexeme);
    yylval.token = OBJECT_1;
    return OBJECT_1;
}

// Function for LinearObject0
token LinearObject0Action(const char * lexeme) {
    LogDebug("LinearObject0Action: '%s'.", lexeme);
    yylval.token = LINEAR_OBJECT_0;
    return LINEAR_OBJECT_0;
}

// Function for LinearObject1
token LinearObject1Action(const char * lexeme) {
    LogDebug("LinearObject1Action: '%s'.", lexeme);
    yylval.token = LINEAR_OBJECT_1;
    return LINEAR_OBJECT_1;
}

// Function for KeyStringA
token KeyStringAAction(const char * lexeme) {
    LogDebug("KeyStringAAction: '%s'.", lexeme);
    yylval.token = KEY_STRING_A;
    return KEY_STRING_A;
}

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

// Function for BodyA
token BodyAAction(const char * lexeme) {
    LogDebug("BodyAAction: '%s'.", lexeme);
    yylval.token = BODY_A;
    return BODY_A;
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

// Function for BodyAPrime
token BodyAPrimeAction(const char * lexeme) {
    LogDebug("BodyAPrimeAction: '%s'.", lexeme);
    yylval.token = BODY_A_PRIME;
    return BODY_A_PRIME;
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

// Function for VA1
token VA1Action(const char * lexeme) {
    LogDebug("VA1Action: '%s'.", lexeme);
    yylval.token = VA_1;
    return VA_1;
}

// Function for VA1Prime
token VA1PrimeAction(const char * lexeme) {
    LogDebug("VA1PrimeAction: '%s'.", lexeme);
    yylval.token = VA_1_PRIME;
    return VA_1_PRIME;
}

// Function for PropertyPairA1
token PropertyPairA1Action(const char * lexeme) {
    LogDebug("PropertyPairA1Action: '%s'.", lexeme);
    yylval.token = PROPERTY_PAIR_A_1;
    return PROPERTY_PAIR_A_1;
}

// Function for Position
token PositionAction(const char * lexeme) {
    LogDebug("PositionAction: '%s'.", lexeme);
    yylval.token = POSITION;
    return POSITION;
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
token Arrow0Action(const char * lexeme) {
    LogDebug("Arrow0Action: '%s'.", lexeme);
    yylval.token = ARROW_0;
    return ARROW_0;
}

// Function for G0
token G0Action(const char * lexeme) {
    LogDebug("G0Action: '%s'.", lexeme);
    yylval.token = G_0;
    return G_0;
}

// Function for VW0
token VW0Action(const char * lexeme) {
    LogDebug("VW0Action: '%s'.", lexeme);
    yylval.token = VW_0;
    return VW_0;
}

// Function for VW0Prime
token VW0PrimeAction(const char * lexeme) {
    LogDebug("VW0PrimeAction: '%s'.", lexeme);
    yylval.token = VW_0_PRIME;
    return VW_0_PRIME;
}

// Function for PropertyPairW0
token PropertyPairW0Action(const char * lexeme) {
    LogDebug("PropertyPairW0Action: '%s'.", lexeme);
    yylval.token = PROPERTY_PAIR_W_0;
    return W_0;
}

// Function for Direction
token DirectionAction(const char * lexeme) {
    LogDebug("DirectionAction: '%s'.", lexeme);
    yylval.token = DIRECTION;
    return DIRECTION;
}

// Function for Angle
token AngleAction(const char * lexeme) {
    LogDebug("AngleAction: '%s'.", lexeme);
    yylval.token = ANGLE;
    return ANGLE;
}

// Function for RopeVG0
token RopeVG0Action(const char * lexeme) {
    LogDebug("RopeVG0Action: '%s'.", lexeme);
    yylval.token = ROPE_VG_0;
    return ROPE_VG_0;
}

// Function for SpringVG0
token SpringVG0Action(const char * lexeme) {
    LogDebug("SpringVG0Action: '%s'.", lexeme);
    yylval.token = SPRING_VG_0;
    return SPRING_VG_0;
}

//Termina chatGPT

token AdditionOperatorPatternAction(const char * lexeme) {
	LogDebug("AdditionOperatorPatternAction: '%s'.", lexeme);
	yylval.token = ADD;
	return ADD;
}


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
