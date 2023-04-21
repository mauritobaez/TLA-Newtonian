#ifndef FLEX_ACTIONS_HEADER
#define FLEX_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include "../syntactic-analysis/bison-parser.h"
#include <stdlib.h>

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

// Function for AlignmentKey
token AlignmentKeyAction(const char * lexeme);

// Function for PlaneKey
token PlaneKeyAction(const char * lexeme);

// Function for BlockKey
token BlockKeyAction(const char * lexeme);

// Function for BallKey
token BallKeyAction(const char * lexeme);

// Function for ArrowKey
token ArrowKeyAction(const char * lexeme);

// Function for SpringRopeKey
token SpringRopeKeyAction(const char * lexeme);

// Function for SpacerKey
token SpacerKeyAction(const char * lexeme);

// Function for PositionKey
token PositionKeyAction(const char * lexeme);

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

//Function for Color
token ColorAction(const char *lexeme);

//Function for String
token StringAction(const char *lexeme);

//Function for Anchor
token AnchorAction(const char *lexeme);

//Function for Number Pattern
token NumberAction(const char *lexeme, const int length);

// Function for BooleanPattern
token BooleanPatternAction(const char * lexeme);

// Function for AbsoluteDirection
token AbsoluteDirectionAction(const char * lexeme);

// Function for RelativeDirection
token RelativeDirectionAction(const char * lexeme);

token UnknownPatternAction(const char * lexeme, const int length);

void IgnoredPatternAction(const char * lexeme, const int length);

#endif
