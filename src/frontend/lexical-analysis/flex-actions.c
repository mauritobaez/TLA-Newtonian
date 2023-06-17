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

// Function for RowKey
token RowKeyAction(const char * lexeme) {
    LogDebug("RowKeyAction: '%s'.", lexeme);
    yylval.token = ROW_KEY;
    return ROW_KEY;
}

// Function for ColumnKey
token ColumnKeyAction(const char * lexeme) {
    LogDebug("ColumnKeyAction: '%s'.", lexeme);
    yylval.token = COLUMN_KEY;
    return COLUMN_KEY;
}

// Function for HorizontalPlaneKey
token HorizontalPlaneKeyAction(const char * lexeme) {
    LogDebug("HorizontalPlaneKeyAction: '%s'.", lexeme);
    yylval.token = HORIZONTAL_PLANE_KEY;
    return HORIZONTAL_PLANE_KEY;
}

// Function for VerticalPlaneKey
token VerticalPlaneKeyAction(const char * lexeme) {
    LogDebug("VerticalPlaneKeyAction: '%s'.", lexeme);
    yylval.token = VERTICAL_PLANE_KEY;
    return VERTICAL_PLANE_KEY;
}

// Function for BlockKey
token BlockKeyAction(const char * lexeme) {
    LogDebug("BlockKeyAction: '%s'.", lexeme);
    yylval.token = BLOCK_KEY;
    return BLOCK_KEY;
}

// Function for CarKey
token CarKeyAction(const char * lexeme) {
    LogDebug("CarKeyAction: '%s'.", lexeme);
    yylval.token = CAR_KEY;
    return CAR_KEY;
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

// Function for SpringKey
token SpringKeyAction(const char * lexeme) {
    LogDebug("SpringKeyAction: '%s'.", lexeme);
    yylval.token = SPRING_KEY;
    return SPRING_KEY;
}

// Function for RopeKey
token RopeKeyAction(const char * lexeme) {
    LogDebug("RopeKeyAction: '%s'.", lexeme);
    yylval.token = ROPE_KEY;
    return ROPE_KEY;
}

// Function for SpacerKey
token SpacerKeyAction(const char * lexeme) {
    LogDebug("SpacerKeyAction: '%s'.", lexeme);
    yylval.token = SPACER_KEY;
    return SPACER_KEY;
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
token CustomColorAction(const char *lexeme) {
    LogDebug("CustomColorPatternAction: '%s'",lexeme);
    int r_val, g_val, b_val;
    sscanf(lexeme + 1, "%02x%02x%02x", &r_val, &g_val, &b_val);
    yylval.color = (color_t) {(char) r_val, (char) g_val, (char) b_val};
    return COLOR;
}

token DefaultColorAction(const char *lexeme, const char r_val, const char g_val, const char b_val) {
    LogDebug("DefaultColorPatternAction: '%s'",lexeme);
    yylval.color = (color_t) {(char) r_val, (char) g_val, (char) b_val};
    return COLOR;
}

//Function for String
token StringAction(const char *lexeme, const int length){
    char* string = calloc(1, length + 1);

    strncpy(string, (char*) lexeme +1, length-2); //El +1 y -2 son para sacar las comillas "" inicial y final
    LogDebug("StringPatternAction: '%s'",lexeme);
    yylval.string = string;
    return STRING;
}

//Function for Anchor
token AnchorAction(const char *lexeme, const anchor_t anchor) {
    LogDebug("AnchorPatternAction: '%s'",lexeme);
    yylval.anchor = anchor;
    return ANCHOR;
}

//Function for Number Pattern
token NumberAction(const char *lexeme, const int length){
    LogDebug("NumberPatternAction: '%s' (length = %d).",lexeme,length);
    char *end;
    yylval.number = strtof(lexeme , &end);
    return NUMBER;
}

// Function for BooleanPattern
token BooleanAction(const char * lexeme, const boolean boolean) {
    LogDebug("BooleanPatternAction: '%s'.", lexeme);
    yylval.boolean = boolean;
    return BOOLEAN;
}

// Function for Direction
token DirectionAction(const char * lexeme, const direction_t direction) {
    LogDebug("DirectionPatternAction: '%s'.", lexeme);
    yylval.direction = direction;
    if(direction <= RIGHT)
        return DIRECTION_REL;
    else
        return DIRECTION_ABS;
}

token UnknownPatternAction(const char * lexeme, const int length) {
	LogDebug("UnknownPatternAction: '%s' (length = %d).", lexeme, length);
	yylval.token = U_ERROR;
	// Al emitir este token, el compilador aborta la ejecución.
	return YYUNDEF;
}

void IgnoredPatternAction(const char * lexeme, const int length) {
	LogDebug("IgnoredPatternAction: '%s' (length = %d).", lexeme, length);
	// Como no debe hacer nada con el patrón, solo se loguea en consola.
}
