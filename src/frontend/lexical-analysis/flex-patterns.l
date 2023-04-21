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
color           [red|blue|black|green|purple|yellow|orange]
anchor          [top|bottom|left-side|right-side|center]
direction_rel   [up|down|left|right]
direction_abs   [north|south|east|west]
string          [\"(\\.|[^\"])*\"]
number          [\-?[0-9]*\.[0-9]*]
%%

"/*"										{ BEGIN(COMMENT); BeginCommentPatternAction(); }
<COMMENT>.									{ ; }
<COMMENT>{endline}							{ ; }
<COMMENT>"*/"								{ EndCommentPatternAction(); BEGIN(INITIAL); }

"{"                                         { return OpenBracketAction(yytext); }
"}"                                         { return CloseBracketAction(yytext); }
","                                         { return CommaAction(yytext); }
"Row"                                       { return RowAction(yytext); }
"Column"                                    { return ColumnAction(yytext); }
":"                                         { return SemicolonAction(yytext); }
"Arrow"                                     { return ArrowAction(yytext); }
"Spring"
"Rope"
"position"                                  { return PositionAction(yytext); }
"friction"                                  { return FrictionAction(yytext); }
"color"                                     { return ColorAction(yytext); }
"label"                                     { return LabelAction(yytext); }
"top"                                       { return}
"bottom"                                    { return}
"left"                                      { return}
"right"                                     { return}
"center"                                    { return}
"direction"                                 { return DirectionAction(yytext); }
"angle"                                     { return AngleAction(yytext); }
"angle-label"                               { return AngleLabelAction(yytext); }
"HorizontalPlane"                           { return HorizontalPlaneAction(yytext); }
"VerticalPlane"                             { return VerticalPlane(yytext); }
"Block"                                     { return BlockAction(yytext); }
"width"                                     { return WidthAction(yytext); }
"length"                                    { return LengthAction(yytext); }
"reverse-arrow"                             { return BallAction(yytext);}
"Spacer"                                    { return SpacerAction(yytext); }
"Ball"                                      { return ReverseArrowAction(yytext); }
"radius"                                    { return RadiusAction(yytext); }
{color}                                     { return ColorAction(yytext); }

"("											{ return OpenParenthesisPatternAction(yytext); }
")"											{ return CloseParenthesisPatternAction(yytext); }

{digit}+									{ return IntegerPatternAction(yytext, yyleng); }

{whitespace}								{ IgnoredPatternAction(yytext, yyleng); }
[+-]?({digit}+([.]{digit}*)?|[.]{digit}+)   { return FloatPatternAction(yytext, yyleng); }

"true"|"false"                              { return BooleanPatternAction(yytext); }

"top"|"bottom"|"left"|"right"|"north"|"south"|"east"|"west"             { return DirectionPatternAction(yytext); }

[#[0-9A-F]{6}]|"red"|"green"|"blue"|"magenta"|"cyan"|"yellow"|"black"|"white"|"gray"|"dark_gray"|"light_gray"|"orange"|"pink" { return ColorPatternAction(yytext);}

.											{ return UnknownPatternAction(yytext, yyleng); }

%%
