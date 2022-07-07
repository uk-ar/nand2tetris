#ifndef TYPES_H
#define TYPES_H

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
