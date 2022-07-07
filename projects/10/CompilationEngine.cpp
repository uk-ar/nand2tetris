#include <string>
#include <unordered_map>
#include <iostream>
#include "CompilationEngine.h"

using namespace std;

// CompilationEngine::CompilationEngine(ostream &outputStream):fout(outputStream){
CompilationEngine::CompilationEngine(istream &inputStream, ostream &outputStream) : fout(outputStream), fin(inputStream)
{
  t = new JackTokenizer(fin);
}
void printToken(ostream &fout, JackTokenizer *t)
{
  fout << "<" + t->tokenString() + "> " << xmlescape(t->token) << " </" + t->tokenString() + ">" << endl;
  t->advance();
}
void CompilationEngine::compileClass()
{
  fout << "<class>" << endl;
  printToken(fout, t); // class
  printToken(fout, t); // className
  printToken(fout, t); //{
  compileClassVarDec();
  compileSubroutine();
  printToken(fout, t); //}
  fout << "</class>" << endl;
}
void CompilationEngine::compileClassVarDec()
{
  if (t->TokenType() != KEYWORD)
    return;
  if (t->keyWord() == STATIC or t->keyWord() == FIELD)
  {
    fout << "<classVarDec>" << endl;
    printToken(fout, t); // static or field
    printToken(fout, t); // type
    printToken(fout, t); // varName
    while (t->TokenType() == SYMBOL and t->symbol() == ',')
    {                      //,
      printToken(fout, t); //,
      printToken(fout, t); // varName
    }
    printToken(fout, t); //;
    fout << "</classVarDec>" << endl;
    compileClassVarDec();
  }
}
void CompilationEngine::compileSubroutine()
{
  if (t->TokenType() != KEYWORD)
    return;
  if (t->keyWord() == CONSTRUCTOR or t->keyWord() == FUNCTION or t->keyWord() == METHOD)
  {
    fout << "<subroutineDec>" << endl;
    printToken(fout, t); // constructor, fuction, method
    printToken(fout, t); // type
    printToken(fout, t); // subroutineName
    printToken(fout, t); //(
    compileParameterList();
    printToken(fout, t); //)
    fout << "<subroutineBody>" << endl;
    printToken(fout, t); //{
    compileVarDec();
    fout << "<statements>" << endl;
    compileStatement();
    fout << "</statements>" << endl;
    printToken(fout, t); //}
    fout << "</subroutineBody>" << endl;
    fout << "</subroutineDec>" << endl;
    compileSubroutine();
  }
}
void CompilationEngine::compileParameterList()
{
  fout << "<parameterList>" << endl;
  if (t->TokenType() != KEYWORD and t->TokenType() != IDENTIFIER)
  {
    fout << "</parameterList>" << endl;
    return;
  }
  printToken(fout, t); // type
  printToken(fout, t); // varName
  while (t->TokenType() == SYMBOL and t->symbol() == ',')
  {
    printToken(fout, t); //,
    printToken(fout, t); // type
    printToken(fout, t); // varName
  }
  fout << "</parameterList>" << endl;
}
void CompilationEngine::compileVarDec()
{
  if (t->TokenType() != KEYWORD)
    return;
  if (t->keyWord() == VAR)
  {
    fout << "<varDec>" << endl;
    printToken(fout, t); // var
    printToken(fout, t); // type
    printToken(fout, t); // varName
    while (t->TokenType() == SYMBOL and t->symbol() == ',')
    {                      //,
      printToken(fout, t); //,
      printToken(fout, t); // varName
    }
    printToken(fout, t); //;
    fout << "</varDec>" << endl;
    compileVarDec();
  }
}
void CompilationEngine::compileStatement()
{
  // if(t->TokenType()!=KEYWORD or LET>t->keyWord() or t->keyWord()>RETURN)
  //   return;
  while (t->TokenType() == KEYWORD and LET <= t->keyWord() and t->keyWord() <= RETURN)
  {
    if (t->keyWord() == LET)
    {
      compileLet();
    }
    else if (t->keyWord() == IF)
    {
      compileIf();
    }
    else if (t->keyWord() == WHILE)
    {
      compileWhile();
    }
    else if (t->keyWord() == DO)
    {
      compileDo();
    }
    else if (t->keyWord() == RETURN)
    {
      fout << "<returnStatement>" << endl;
      printToken(fout, t); // return
      if (not(t->TokenType() == SYMBOL and t->symbol() == ';'))
        compileExpression(); // expression
      printToken(fout, t);   //;
      fout << "</returnStatement>" << endl;
    }
  }
}
void CompilationEngine::compileDo()
{
  if (t->TokenType() != KEYWORD)
    return;
  if (t->keyWord() == DO)
  {
    fout << "<doStatement>" << endl;
    printToken(fout, t); // do
    compileSubroutineCall();
    printToken(fout, t); //;
    fout << "</doStatement>" << endl;
  }
}
void CompilationEngine::compileSubroutineCall()
{
  printToken(fout, t); // subroutinename or className or varName
  if (t->TokenType() == SYMBOL and t->symbol() == '.')
  {                      // method call
    printToken(fout, t); //.
    printToken(fout, t); // subroutinename
  }
  printToken(fout, t); //(
  compileExpressionList();
  printToken(fout, t); //)
}
void CompilationEngine::compileLet()
{
  if (t->TokenType() != KEYWORD)
    return;
  if (t->keyWord() == LET)
  {
    fout << "<letStatement>" << endl;
    printToken(fout, t); // let
    printToken(fout, t); // varName
    if (t->TokenType() == SYMBOL and t->symbol() == '[')
    {                      //[
      printToken(fout, t); //[
      compileExpression(); //
      printToken(fout, t); //]
    }
    printToken(fout, t); //=
    compileExpression(); //
    printToken(fout, t); //;
    fout << "</letStatement>" << endl;
  }
}
void CompilationEngine::compileWhile()
{
  if (t->TokenType() != KEYWORD)
    return;
  if (t->keyWord() == WHILE)
  {
    fout << "<whileStatement>" << endl;
    printToken(fout, t); // while
    printToken(fout, t); //(
    compileExpression(); //
    printToken(fout, t); //)
    printToken(fout, t); //{
    fout << "<statements>" << endl;
    compileStatement();
    fout << "</statements>" << endl;
    printToken(fout, t); //}
    fout << "</whileStatement>" << endl;
  }
}
void CompilationEngine::compileIf()
{
  if (t->TokenType() != KEYWORD)
    return;
  if (t->keyWord() == IF)
  {
    fout << "<ifStatement>" << endl;
    printToken(fout, t); // if
    printToken(fout, t); //(
    compileExpression(); //
    printToken(fout, t); //)
    printToken(fout, t); //{
    fout << "<statements>" << endl;
    compileStatement();
    fout << "</statements>" << endl;
    printToken(fout, t); //}
    if (t->TokenType() == KEYWORD and t->keyWord() == ELSE)
    {                      //[
      printToken(fout, t); // else
      printToken(fout, t); //{
      fout << "<statements>" << endl;
      compileStatement();
      fout << "</statements>" << endl;
      printToken(fout, t); //}
    }
    fout << "</ifStatement>" << endl;
  }
}

string opstr = "+-*/&|<>=";
unordered_set<char> ops(opstr.begin(), opstr.end());

void CompilationEngine::compileExpression()
{
  fout << "<expression>" << endl;
  compileTerm();
  while (t->TokenType() == SYMBOL and ops.count(t->symbol()))
  {
    printToken(fout, t); // op
    compileTerm();
  }
  fout << "</expression>" << endl;
}
void CompilationEngine::compileTerm()
{
  fout << "<term>" << endl;
  if (t->TokenType() == IDENTIFIER)
  {
    char p = t->peek();
    if (p == '.' or p == '(')
    {
      compileSubroutineCall();
    }
    else if (t->peek() == '[')
    {                      // array
      printToken(fout, t); // varName
      printToken(fout, t); //[
      compileExpression(); // expression
      printToken(fout, t); //]
    }
    else
    {
      // var
      printToken(fout, t); // varName
    }
  }
  else if (t->TokenType() == INT_CONST or t->TokenType() == STRING_CONST or t->TokenType() == KEYWORD)
  {
    printToken(fout, t);
  }
  else if (t->TokenType() == SYMBOL and t->symbol() == '(')
  {
    printToken(fout, t); //(
    compileExpression();
    printToken(fout, t); //)
  }
  else if (t->TokenType() == SYMBOL and (t->symbol() == '~' or t->symbol() == '-'))
  {
    printToken(fout, t); //~ or -
    compileTerm();
  }
  fout << "</term>" << endl;
}
void CompilationEngine::compileExpressionList()
{
  fout << "<expressionList>" << endl;
  if (t->TokenType() == SYMBOL and (t->symbol() == ')'))
  {
    fout << "</expressionList>" << endl;
    return;
  }
  compileExpression();
  while (t->TokenType() == SYMBOL and (t->symbol() == ','))
  {
    printToken(fout, t); //,
    compileExpression();
  }
  fout << "</expressionList>" << endl;
}
