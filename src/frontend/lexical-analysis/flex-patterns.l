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

%%

"/*"										{ BEGIN(COMMENT); BeginCommentPatternAction(); }
<COMMENT>.									{ ; }
<COMMENT>{endline}							{ ; }
<COMMENT>"*/"								{ EndCommentPatternAction(); BEGIN(INITIAL); }


"{"                                         { return OpenBracketAction(yytext); }
"}"                                         { return CloseBracketAction(yytext); }
"("											{ return OpenParenthesisAction(yytext); }
")"											{ return CloseParenthesisAction(yytext); }
","                                         { return CommaAction(yytext); }
":"                                         { return SemicolonAction(yytext); }


"Row"                                       { return RowKeyAction(yytext); }
"Column"                                    { return ColumnKeyAction(yytext); }
"HorizontalPlane"                           { return HorizontalPlaneKeyAction(yytext); }
"VerticalPlane"                             { return VerticalPlaneKeyAction(yytext); }
"Block"|"Box"                               { return BlockKeyAction(yytext); }
"Car"                                       { return CarKeyAction(yytext); }
"Ball"|"Cylinder"                           { return BallKeyAction(yytext);  }  
"Arrow"                                     { return ArrowKeyAction(yytext); }
"Spring"                                    { return SpringKeyAction(yytext); }
"Rope"                                      { return RopeKeyAction(yytext); }
"Spacer"                                    { return SpacerKeyAction(yytext); }


"position"                                  { return PositionKeyAction(yytext); }
"friction"                                  { return FrictionKeyAction(yytext); }
"color"                                     { return ColorKeyAction(yytext); }
"label"                                     { return LabelKeyAction(yytext); }
"direction"                                 { return DirectionKeyAction(yytext); }
"angle"                                     { return AngleKeyAction(yytext); }
"angle-label"                               { return AngleLabelKeyAction(yytext); }
"height"                                    { return HeightKeyAction(yytext); }
"width"                                     { return WidthKeyAction(yytext); }
"length"                                    { return LengthKeyAction(yytext); }
"reverse-arrow"                             { return ReverseArrowKeyAction(yytext);}
"double-arrow"                              { return DoubleArrowKeyAction(yytext); }
"radius"                                    { return RadiusKeyAction(yytext); }
"visible"                                   { return VisibleKeyAction(yytext); }


#[0-9A-F]{6}                                { return CustomColorAction(yytext); }
"red"                                       { return DefaultColorAction(yytext, 255, 0, 0); }
"green"                                     { return DefaultColorAction(yytext, 0, 255, 0); }
"blue"                                      { return DefaultColorAction(yytext, 0, 0, 255); }
"black"                                     { return DefaultColorAction(yytext, 0, 0, 0); }
"yellow"                                    { return DefaultColorAction(yytext, 255, 255, 0); }
"orange"                                    { return DefaultColorAction(yytext, 255, 140, 0); }
"purple"                                    { return DefaultColorAction(yytext, 128, 0, 128); }
\"(\\.|[^\"])*\"                            { return StringAction(yytext); }
"top"                                       { return AnchorAction(yytext, TOP); }
"bottom"                                    { return AnchorAction(yytext, BOTTOM); }
"left-side"                                 { return AnchorAction(yytext, LEFT_SIDE); }
"right-side"                                { return AnchorAction(yytext, RIGHT_SIDE); }
"center"                                    { return AnchorAction(yytext, CENTER); }
[+-]?({digit}+([.]{digit}*)?|[.]{digit}+)   { return NumberAction(yytext, yyleng); }
"true"                                      { return BooleanAction(yytext, 1); }
"false"                                     { return BooleanAction(yytext, 0); }
"up"                                        { return DirectionAction(yytext, UP); }
"down"                                      { return DirectionAction(yytext, DOWN); }
"left"                                      { return DirectionAction(yytext, LEFT); }
"right"                                     { return DirectionAction(yytext, RIGHT); }
"north"                                     { return DirectionAction(yytext, NORTH); }
"south"                                     { return DirectionAction(yytext, SOUTH); }
"east"                                      { return DirectionAction(yytext, EAST); }
"west"                                      { return DirectionAction(yytext, WEST); }


{whitespace}								{ IgnoredPatternAction(yytext, yyleng); }
.											{ return UnknownPatternAction(yytext, yyleng); }

%%
