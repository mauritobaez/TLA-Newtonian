%{

#include "flex-actions.h"

%}

/* Obliga a crear una regla explícita para manejar lexemas desconocidos. */
%option nodefault

/* Escanea un único archivo y se detiene. */
%option noyywrap

/* Dispone una variable global "yylineno" con el número de línea actual. */
%option yylineno

/* Contextos de Flex. */
%x COMMENT

/* Patrones reutilizables. */
digit			[0-9]
endline			[\n]
whitespace		[ \f\n\r\t\v]
color           [#[0-9A-F]{6}|red|blue|black|green|purple|yellow|orange]
anchor          ["top"|"bottom"|"left-side"|"right-side"|"center"]
direction_rel   ["up"|"down"|"left"|"right"]
direction_abs   ["north"|"south"|"east"|"west"]
string          [\"(\\.|[^\"])*\"]
boolean         ["true"|"false"]

%%

"/*"										{ BEGIN(COMMENT); BeginCommentPatternAction(); }
<COMMENT>.									{ ; }
<COMMENT>{endline}							{ ; }
<COMMENT>"*/"								{ EndCommentPatternAction(); BEGIN(INITIAL); }

/* Symbols */
"{"                                         { return OpenBracketAction(yytext); }
"}"                                         { return CloseBracketAction(yytext); }
"("											{ return OpenParenthesisAction(yytext); }
")"											{ return CloseParenthesisAction(yytext); }
","                                         { return CommaAction(yytext); }
":"                                         { return SemicolonAction(yytext); }

/* Placeable Keys */
"Row"|"Column"                              { return AlignmentKeyAction(yytext); }
"HorizontalPlane"|"VerticalPlane"           { return PlaneKeyAction(yytext); }
"Block"|"Car"                               { return BlockKeyAction(yytext); }
"Ball"|"Cylinder"                           { return BallKeyAction(yytext);  }  
"Arrow"                                     { return ArrowKeyAction(yytext); }
"Spring"|"Rope"                             { return SpringRopeKeyAction(yytexy); }
"Spacer"                                    { return SpacerKeyAction(yytext); }

/* Property Keys */
"position"                                  { return PositionKeyAction(yytext); }
"friction"                                  { return FrictionKeyAction(yytext); }
"color"                                     { return ColorKeyAction(yytext); }
"label"                                     { return LabelKeyAction(yytext); }
"direction"                                 { return DirectionKeyAction(yytext); }
"angle"                                     { return AngleKeyAction(yytext); }
"angle-label"                               { return AngleLabelKeyAction(yytext); }
"heigth"                                    { return HeigthKeyAction(yytext); }
"width"                                     { return WidthKeyAction(yytext); }
"length"                                    { return LengthKeyAction(yytext); }
"reverse-arrow"                             { return ReverseArrowKeyAction(yytext);}
"double-arrow"                              { return DoubleArrowKeyAction(yytext); }
"radius"                                    { return RadiusKeyAction(yytext); }
"visible"                                   { return VisibleKeyAction(yytext); }

/* Property Values */
{color}                                     { return ColorAction(yytext); }
{string}                                     { return StringAction(yytext); }
{anchor}                                     { return AnchorAction(yytext); }
[+-]?({digit}+([.]{digit}*)?|[.]{digit}+)   { return NumberAction(yytext, yyleng); }
{boolean}                                   { return BooleanAction(yytext); }
{direction_abs}                             { return AbsoluteDirectionAction(yytext); }
{direction_rel}                             { return RelativeDirectionAction(yytext); }

/* Other */
{whitespace}								{ IgnoredPatternAction(yytext, yyleng); }
.											{ return UnknownPatternAction(yytext, yyleng); }

%%
