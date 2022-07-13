#ifndef TYPES_H
#define TYPES_H

enum Segment{
  S_CONST,
  S_ARG,
  S_LOCAL,
  S_STATIC,
  S_THIS,
  S_THAT,
  S_POINTER,
  S_TEMP
};
enum Command{
  C_ADD,
  C_SUB,
  C_NEG,
  C_EQ,
  C_GT,
  C_LT,
  C_AND,
  C_OR,
  C_NOT
};

enum Kind{
  K_STATIC,
  K_FIELD,
  K_ARG,
  K_VAR,
  K_NONE
};

enum TokenType {
  KEYWORD,
  SYMBOL,
  IDENTIFIER,
  INT_CONST,
  STRING_CONST,
};

enum KeywordType {
  CLASS,
  METHOD,
  FUNCTION,
  CONSTRUCTOR,
  INT,
  BOOLEAN,
  CHAR,
  VOID,
  VAR,
  STATIC,
  FIELD,
  LET,
  DO,
  IF,
  ELSE,
  WHILE,
  RETURN,
  TRUE,
  FALSE,
  K_NULL,
  THIS,
};

#endif /* TYPES_H */
