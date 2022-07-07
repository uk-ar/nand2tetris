#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "JackTokenizer.h"
using namespace std;
string symbolChars = "{}()[].,;+-*/&|<>=~";
string whiteSpaceChars = " \t\n\r";

vector<string> keywordStrings({"class","method","function","constructor","int","boolean","char","void","var","static","field","let","do","if","else","while","return","true","false","null","this"});
vector<string> typeStrings({"keyword","symbol","identifier","integerConstant","stringConstant"});

string xmlescape(string s){
  if(s=="<")
    return "&lt;";
  else if(s==">")
    return "&gt;";
  else if(s=="&")
    return "&amp;";
  return s;
}

JackTokenizer::JackTokenizer(istream &inputStream) :
  is(inputStream),
  symbols(symbolChars.begin(), symbolChars.end()),
  whiteSpaces(whiteSpaceChars.begin(), whiteSpaceChars.end())
{
  //keywords(keywordStrings.begin(),keywordStrings.end())
  for(int i=0;i<keywordStrings.size();i++)
    keywords[keywordStrings[i]]=i;
  advance();
}
JackTokenizer::~JackTokenizer()
{
}
bool JackTokenizer::hasMoreTokens()
{
  return !eof;
}
void whiteSpace(istream &is, bool &eof)
{
  int a = 1;
  while (a != EOF)
  {
    a = is.get();
    //cout << (char)a << endl;
    if (a == ' ' or a == '\t' or a == '\n' or a=='\r')
    {
      continue;
    }
    else if (a == '/')
    {
      if (is.peek() == '/')
      {
        while (a != '\n' and a!='\r' and a != EOF){
          a = is.get();
          //cout << (char)a << endl;
        }
        continue;
      }
      else if (is.peek() == '*')
      {
        int pre = 0;
        while (a != EOF)
        {
          if (pre == '*' and a == '/')
            break;
          pre = a;
          a = is.get();
          //cout << (char)a << endl;
        }
        continue;
      }
      else
      {
        is.putback(a);
        break;
      }
    }
    else
    {
      is.putback(a);
      break;
    }
  }
  if (a == EOF)
    eof = true;
}
void JackTokenizer::advance()
{
  token = "";
  whiteSpace(is, eof);
  if (eof)
    return;
  int a = ' ';
  while (a != EOF)
  {
    a = is.get();
    //cout << (char)a<<endl;
    if (whiteSpaces.count(a))
      break;
    else if(a=='\"'){
      while (a != EOF){
        a = is.get();
        if(a=='\"'){
          tokenType=STRING_CONST;
          return;
        }
        token += a;
      }
      continue;
    }else if (symbols.count(a)){
      if(token.empty()){
        token+=a;
        tokenType=SYMBOL;
        return;
      }else{
        is.putback(a);
        break;
      }
    }
    token += a;
    //cout << token << endl;
  }
  if(keywords.count(token)){
    tokenType=KEYWORD;
    keywordType=static_cast<KeywordType>(keywords[token]);
  }else if(isdigit(token[0]))
    tokenType=INT_CONST;
  else
    tokenType=IDENTIFIER;
}
enum TokenType JackTokenizer::TokenType()
{
  return tokenType;
}
string JackTokenizer::tokenString()
{
  return typeStrings[tokenType];
}
enum KeywordType JackTokenizer::keyWord()
{
  return keywordType;
}
char JackTokenizer::symbol()
{
  return token[0];
}
string JackTokenizer::identifier()
{
  return token;
}
int JackTokenizer::intVal()
{
  int i=0;
  for(auto c:token)
    i=i*10+c-'0';
  return i;
}
char JackTokenizer::peek(){
  return is.peek();
}
string JackTokenizer::stringVal()
{
  return token;
}
