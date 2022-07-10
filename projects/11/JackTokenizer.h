#ifndef JACKTOKENIZER_H
#define JACKTOKENIZER_H

#include <string>
#include <unordered_set>
#include <unordered_map>
#include "Types.h"
using namespace std;

class JackTokenizer{
  istream &is;
  bool eof=false;
  unordered_set<char>symbols,whiteSpaces;
  unordered_map<string,int>keywords;
 public:
  string token;
  TokenType tokenType;
  KeywordType keywordType;
  //VMcomType m_VMcomType;

  JackTokenizer(istream &inputStream);
  virtual ~JackTokenizer();
  bool hasMoreTokens();
  void advance();
  enum TokenType TokenType();
  enum KeywordType keyWord();
  char symbol();
  string identifier();
  int intVal();
  string stringVal();

  string tokenString();
  char peek();
};
extern vector<string> keywordStrings;
string xmlescape(string s);
#endif //JACKTOKENIZER_H
