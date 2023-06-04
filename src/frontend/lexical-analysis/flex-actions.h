#ifndef FLEX_ACTIONS_HEADER
#define FLEX_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include "../syntactic-analysis/bison-parser.h"
#include "../newtonian-types.h"
#include <stdlib.h>
#include <string.h>

/**
 * Se definen las acciones a ejecutar sobre cada patrón hallado mediante el
 * analizador léxico Flex. Este analizador solo puede identificar
 * construcciones regulares, ya que utiliza un autómata finito determinístico
 * (a.k.a. DFA), como mecanismo de escaneo y reconocimiento.
 *
 * Debería existir una acción por cada patrón disponible en Flex (es decir,
 * por cada regla).
 *
 * Solo aquellas acciones que tengan interés en conocer el largo del lexema
 * emplean el parámetro adicional "length". Esto es útil cuando se desea
 * asignar memoria dinámica, y por lo tanto, se debe saber exactamente el
 * largo de aquello que se va a almacenar.
 */

// Bloque de comentarios multilínea.
void BeginCommentPatternAction();

void EndCommentPatternAction();

// Function for OpenBracket
token OpenBracketAction(const char * lexeme);

// Function for CloseBracket
token CloseBracketAction(const char * lexeme);

// Function for OpenParenthesis
token OpenParenthesisAction(const char * lexeme);

// Function for CloseParenthesis
token CloseParenthesisAction(const char * lexeme);

// Function for Comma
token CommaAction(const char * lexeme);

// Function for Semicolon
token SemicolonAction(const char * lexeme);

// Function for RowKey
token RowKeyAction(const char * lexeme);

// Function for ColumnKey
token ColumnKeyAction(const char * lexeme);

// Function for HorizontalPlaneKey
token HorizontalPlaneKeyAction(const char * lexeme);

// Function for VerticalPlaneKey
token VerticalPlaneKeyAction(const char * lexeme);

// Function for BlockKey
token BlockKeyAction(const char * lexeme);

// Function for CarKey
token CarKeyAction(const char * lexeme);

// Function for BallKey
token BallKeyAction(const char * lexeme);

// Function for ArrowKey
token ArrowKeyAction(const char * lexeme);

// Function for SpringKey
token SpringKeyAction(const char * lexeme);

// Function for RopeKey
token RopeKeyAction(const char * lexeme);

// Function for SpacerKey
token SpacerKeyAction(const char * lexeme);

// Function for FrictionKey
token FrictionKeyAction(const char * lexeme);

// Function for ColorKey
token ColorKeyAction(const char * lexeme);

// Function for LabelKey
token LabelKeyAction(const char * lexeme);

// Function for DirectionKey
token DirectionKeyAction(const char * lexeme);

// Function for AngleKey
token AngleKeyAction(const char * lexeme);

// Function for AngleLabelKey
token AngleLabelKeyAction(const char * lexeme);

// Function for HeightKey
token HeightKeyAction(const char * lexeme);

// Function for WidthKey
token WidthKeyAction(const char * lexeme);

// Function for LengthKey
token LengthKeyAction(const char * lexeme);

// Function for reverseArrowKey
token ReverseArrowKeyAction(const char * lexeme);

// Function for reverseArrowKey
token DoubleArrowKeyAction(const char * lexeme);

// Function for radiusKey
token RadiusKeyAction(const char * lexeme);

// Function for VisibleKey
token VisibleKeyAction(const char * lexeme);

//Function for Custom Color
token CustomColorAction(const char *lexeme);

//Function for Default Color
token DefaultColorAction(const char *lexeme, const char r_val, const char g_val, const char b_val);

//Function for String
token StringAction(const char *lexeme, const int length);

//Function for Anchor
token AnchorAction(const char *lexeme, const anchor_t anchor);

//Function for Number Pattern
token NumberAction(const char *lexeme, const int length);

// Function for BooleanPattern
token BooleanAction(const char * lexeme, const boolean boolean);

// Function for Direction
token DirectionAction(const char * lexeme, const direction_t direction);

token UnknownPatternAction(const char * lexeme, const int length);

void IgnoredPatternAction(const char * lexeme, const int length);

#endif
