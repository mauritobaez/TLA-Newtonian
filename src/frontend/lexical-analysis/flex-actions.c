#include "../../backend/support/logger.h"
#include "flex-actions.h"


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
    return CLOSE_BRACKET;
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

// Function for Comma
token CommaAction(const char * lexeme) {
    LogDebug("CommaAction: '%s'.", lexeme);
    yylval.token = COMMA;
    return COMMA;
}

// Function for Semicolon
token SemicolonAction(const char * lexeme) {
    LogDebug("SemicolonAction: '%s'.", lexeme);
    yylval.token = SEMICOLON;
    return SEMICOLON;
}

// Function for AlignmentKey
token AlignmentKeyAction(const char * lexeme) {
    LogDebug("AlignmentKeyAction: '%s'.", lexeme);
    yylval.token = ALIGNMENT_KEY;
    return ALIGNMENT_KEY;
}

// Function for PlaneKey
token PlaneKeyAction(const char * lexeme) {
    LogDebug("PlaneKeyAction: '%s'.", lexeme);
    yylval.token = PLANE_KEY;
    return PLANE_KEY;
}

// Function for BlockKey
token BlockKeyAction(const char * lexeme) {
    LogDebug("BlockKeyAction: '%s'.", lexeme);
    yylval.token = BLOCK_KEY;
    return BLOCK_KEY;
}

// Function for BallKey
token BallKeyAction(const char * lexeme) {
    LogDebug("BallKeyAction: '%s'.", lexeme);
    yylval.token = BALL_KEY;
    return BALL_KEY;
}

// Function for ArrowKey
token ArrowKeyAction(const char * lexeme) {
    LogDebug("ArrowKeyAction: '%s'.", lexeme);
    yylval.token = ARROW_KEY;
    return ARROW_KEY;
}

// Function for SpringRopeKey
token SpringRopeKeyAction(const char * lexeme) {
    LogDebug("SpringRopeKeyAction: '%s'.", lexeme);
    yylval.token = SPRING_ROPE_KEY;
    return SPRING_ROPE_KEY;
}

// Function for SpacerKey
token SpacerKeyAction(const char * lexeme) {
    LogDebug("SpacerKeyAction: '%s'.", lexeme);
    yylval.token = SPACER_KEY;
    return SPACER_KEY;
}

// Function for PositionKey
token PositionKeyAction(const char * lexeme) {
    LogDebug("PositionKeyAction: '%s'.", lexeme);
    yylval.token = POSITION_KEY;
    return POSITION_KEY;
}

// Function for FrictionKey
token FrictionKeyAction(const char * lexeme) {
    LogDebug("FrictionKeyAction: '%s'.", lexeme);
    yylval.token = FRICTION_KEY;
    return FRICTION_KEY;
}

// Function for ColorKey
token ColorKeyAction(const char * lexeme) {
    LogDebug("ColorKeyAction: '%s'.", lexeme);
    yylval.token = COLOR_KEY;
    return COLOR_KEY;
}

// Function for LabelKey
token LabelKeyAction(const char * lexeme) {
    LogDebug("LabelKeyAction: '%s'.", lexeme);
    yylval.token = LABEL_KEY;
    return LABEL_KEY;
}

// Function for DirectionKey
token DirectionKeyAction(const char * lexeme) {
    LogDebug("DirectionKeyAction: '%s'.", lexeme);
    yylval.token = DIRECTION_KEY;
    return DIRECTION_KEY;
}

// Function for AngleKey
token AngleKeyAction(const char * lexeme) {
    LogDebug("AngleKeyAction: '%s'.", lexeme);
    yylval.token = ANGLE_KEY;
    return ANGLE_KEY;
}

// Function for AngleLabelKey
token AngleLabelKeyAction(const char * lexeme) {
    LogDebug("AngleLabelKeyAction: '%s'.", lexeme);
    yylval.token = ANGLE_LABEL_KEY;
    return ANGLE_LABEL_KEY;
}

// Function for HeightKey
token HeightKeyAction(const char * lexeme) {
    LogDebug("HeightKeyAction: '%s'.", lexeme);
    yylval.token = HEIGHT_KEY;
    return HEIGHT_KEY;
}

// Function for WidthKey
token WidthKeyAction(const char * lexeme) {
    LogDebug("WidthKeyAction: '%s'.", lexeme);
    yylval.token = WIDTH_KEY;
    return WIDTH_KEY;
}

// Function for LengthKey
token LengthKeyAction(const char * lexeme) {
    LogDebug("LengthKeyAction: '%s'.", lexeme);
    yylval.token = LENGTH_KEY;
    return LENGTH_KEY;
}

// Function for reverseArrowKey
token ReverseArrowKeyAction(const char * lexeme) {
    LogDebug("ReverseArrowKeyAction: '%s'.", lexeme);
    yylval.token = REVERSE_ARROW_KEY;
    return REVERSE_ARROW_KEY;
}

// Function for reverseArrowKey
token DoubleArrowKeyAction(const char * lexeme) {
    LogDebug("DoubleArrowKeyAction: '%s'.", lexeme);
    yylval.token = DOUBLE_ARROW_KEY;
    return DOUBLE_ARROW_KEY;
}

// Function for radiusKey
token RadiusKeyAction(const char * lexeme) {
    LogDebug("RadiusKeyAction: '%s'.", lexeme);
    yylval.token = RADIUS_KEY;
    return RADIUS_KEY;
}

// Function for VisibleKey
token VisibleKeyAction(const char * lexeme) {
    LogDebug("VisibleKeyAction: '%s'.", lexeme);
    yylval.token = VISIBLE_KEY;
    return VISIBLE_KEY;
}


//Function for Color
token ColorAction(const char *lexeme){
    LogDebug("ColorPatternAction: '%s'",lexeme);
    /*TODO*/
}

//Function for String
token StringAction(const char *lexeme){
    LogDebug("StringPatternAction: '%s'",lexeme);
    /*TODO*/
}

//Function for Anchor
token AnchorAction(const char *lexeme){
    LogDebug("AnchorPatternAction: '%s'",lexeme);
    /*TODO*/
}

//Function for Number Pattern
token NumberAction(const char *lexeme, const int length){
    LogDebug("NumberPatternAction: '%s' (length = %d).",lexeme,length);
    char *end; /*TODO: Ver si funciona*/
    yylval.number = strtof(lexeme , &end);
    return FLOAT;
}

// Function for BooleanPattern
token BooleanPatternAction(const char * lexeme) {
    LogDebug("BooleanPatternAction: '%s'.", lexeme);
    /*TODO*/
}

// Function for AbsoluteDirection
token AbsoluteDirectionAction(const char * lexeme) {
    LogDebug("AbsoluteDirectionAction: '%s'.", lexeme);
    /*TODO*/
}

// Function for RelativeDirection
token RelativeDirectionAction(const char * lexeme) {
    LogDebug("RelativeDirectionAction: '%s'.", lexeme);
    /*TODO*/
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
