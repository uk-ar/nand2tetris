#include <string>
#include <unordered_map>
#include <iostream>
#include "CompilationEngine.h"

using namespace std;

// CompilationEngine::CompilationEngine(ostream &outputStream):fout(outputStream){
CompilationEngine::CompilationEngine(istream &inputStream, ostream &outputStream) : fin(inputStream),t(new JackTokenizer(fin)),sym(new SymbolTable()),v(new VMWriter(outputStream)),fout(cout)//v(new VMWriter(outputStream))
{

}
void printToken(ostream &fout, JackTokenizer *t)
{
  fout << "<" + t->tokenString() + "> " << xmlescape(t->token) << " </" + t->tokenString() + ">" << endl;
  t->advance();
}

void printId(ostream &fout, JackTokenizer *t,string cat,bool def,Kind kind)
{
  printToken(fout,t);
  //cat=var,argument,static,field,class,subroutine //used
  //kind=K_STATIC, K_FIELD, K_ARG, K_VAR, K_NONE //defined
  fout << cat +"," << (def ? "defined":"used") << "," << kindString[kind]<<endl;

}
void CompilationEngine::compileClass()
{
  fout << "<class>" << endl;
  printToken(fout, t); // class
  className=t->token;
  printId(fout, t, "class", true, K_NONE);// className
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
    string k=keywordStrings[t->keyWord()];
    Kind kind=(t->keyWord()==STATIC ? K_STATIC : K_FIELD);
    printToken(fout, t); // static or field
    string type=t->token;
    printToken(fout, t); // type
    sym->define(t->token,type,kind);
    printId(fout, t, k ,true,kind);// varName
    while (t->TokenType() == SYMBOL and t->symbol() == ',')
    {                      //,
      printToken(fout, t); //,
      sym->define(t->token,type,kind);
      printId(fout, t, k ,true,kind);// varName
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
    sym->startSubroutine();
    printToken(fout, t); // constructor, fuction, method
    printToken(fout, t); // type
    string subroutineName=t->token;
    printId(fout, t, "subroutine" ,true,K_NONE);// subroutineName
    printToken(fout, t); //(
    compileParameterList();
    printToken(fout, t); //)
    fout << "<subroutineBody>" << endl;
    printToken(fout, t); //{
    int pre=sym->varCount(K_VAR);
    compileVarDec();
    v->writeFunction(className+"."+subroutineName,sym->varCount(K_VAR) - pre);
    fout << "<statements>" << endl;
    compileStatement();
    fout << "</statements>" << endl;
    printToken(fout, t); //}
    fout << "</subroutineBody>" << endl;
    fout << "</subroutineDec>" << endl;
    compileSubroutine();
  }
}
int CompilationEngine::compileParameterList()
{
  fout << "<parameterList>" << endl;
  int params=0;
  if (t->TokenType() != KEYWORD and t->TokenType() != IDENTIFIER)
  {
    fout << "</parameterList>" << endl;
    return params;
  }
  string type=t->token;
  printToken(fout, t); // type
  sym->define(t->token,type,K_ARG);
  printId(fout, t, "argument" ,true,K_ARG);// varName
  params++;
  while (t->TokenType() == SYMBOL and t->symbol() == ',')
  {
    printToken(fout, t); //,
    type=t->token;
    printToken(fout, t); // type
    sym->define(t->token,type,K_ARG);
    printId(fout, t, "argument" ,true,K_ARG);// varName
    params++;
  }
  fout << "</parameterList>" << endl;
  return params;
}
void CompilationEngine::compileVarDec()
{
  if (t->TokenType() != KEYWORD)
    return;
  string ans;
  if (t->keyWord() == VAR)
  {
    fout << "<varDec>" << endl;
    printToken(fout, t); // var
    string type=t->token;
    printToken(fout, t); // type
    // v->writePush(S_CONST,0);
    // v->writePop(S_LOCAL,sym->varCount(K_VAR));
    sym->define(t->token,type,K_VAR);
    printId(fout, t, "var" ,true,K_VAR);// varName
    while (t->TokenType() == SYMBOL and t->symbol() == ',')
    {                      //,
      printToken(fout, t); //,
      sym->define(t->token,type,K_VAR);
      printId(fout, t, "var" ,true,K_VAR);// varName
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
      v->writeReturn();
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
  string fullName;
  if(t->peek()=='.'){//className or varName
    // method call
    if(sym->kindOf(t->token)==K_VAR){
      Kind k=sym->kindOf(t->token);
      fullName=sym->typeOf(t->token);
      printId(fout, t, kindString[k] ,false,k);// varName
      v->writePush(S_ARG,0);
    }else{
      fullName=t->token;
      printId(fout, t, "class" ,false,K_NONE);// className
    }
    printToken(fout, t); //.
  }
  fullName+="."+t->token;
  printId(fout, t, "subroutine" ,false,K_NONE);// subroutinename
  printToken(fout, t); //(
  int args=compileExpressionList();
  printToken(fout, t); //)
  v->writeCall(fullName,args);
}
unordered_map<Kind,Segment> k2s({{K_STATIC,S_STATIC},{K_ARG,S_ARG},{K_VAR,S_LOCAL}});
void CompilationEngine::compileLet()
{
  if (t->TokenType() != KEYWORD)
    return;
  if (t->keyWord() == LET)
  {
    fout << "<letStatement>" << endl;
    printToken(fout, t); // let
    Kind k=sym->kindOf(t->token);
    string varName=t->token;
    printId(fout, t, kindString[k] ,false,k);// varName
    if (t->TokenType() == SYMBOL and t->symbol() == '[')
    {
      v->writePush(k2s[k],sym->indexOf(varName));
      printToken(fout, t); //[
      compileExpression(); //
      printToken(fout, t); //]
      v->writeArithmetic(C_ADD);
      v->writePop(S_POINTER,1);//that
      printToken(fout, t); //=
      compileExpression(); //
      v->writePop(S_THAT,0);//that
      printToken(fout, t); //;
    }else{
      printToken(fout, t); //=
      compileExpression(); //
      if(k2s.count(k))
        v->writePop(k2s[k],sym->indexOf(varName));
      printToken(fout, t); //;
    }
    fout << "</letStatement>" << endl;
  }
}
static int lid=0;
void CompilationEngine::compileWhile()
{
  if (t->TokenType() != KEYWORD)
    return;
  if (t->keyWord() == WHILE)
  {
    fout << "<whileStatement>" << endl;
    int l1=lid++;
    v->writeLabel("L"+to_string(l1));
    printToken(fout, t); // while
    printToken(fout, t); //(
    compileExpression(); //
    v->writeArithmetic(C_NOT);
    int l2=lid++;
    v->writeIf("L"+to_string(l2));
    printToken(fout, t); //)
    printToken(fout, t); //{
    fout << "<statements>" << endl;
    compileStatement();
    fout << "</statements>" << endl;
    v->writeGoto("L"+to_string(l1));
    v->writeLabel("L"+to_string(l2));
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
    v->writeArithmetic(C_NOT);
    int l1=lid++;
    v->writeIf("L"+to_string(l1));
    printToken(fout, t); //)
    printToken(fout, t); //{
    fout << "<statements>" << endl;
    compileStatement();
    int l2=lid++;
    v->writeGoto("L"+to_string(l2));
    fout << "</statements>" << endl;
    printToken(fout, t); //}
    if (t->TokenType() == KEYWORD and t->keyWord() == ELSE)
    {                      //[
      printToken(fout, t); // else
      printToken(fout, t); //{
      fout << "<statements>" << endl;
      v->writeLabel("L"+to_string(l1));
      compileStatement();
      fout << "</statements>" << endl;
      printToken(fout, t); //}
    }else{
      v->writeLabel("L"+to_string(l1));
    }
    v->writeLabel("L"+to_string(l2));
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
    char op=t->symbol();
    printToken(fout, t); // op
    compileTerm();
    if(op=='+')
      v->writeArithmetic(C_ADD);
    else if(op=='-')
      v->writeArithmetic(C_SUB);
    else if(op=='*')
      v->writeCall("Math.multiply",2);
    else if(op=='/')
      v->writeCall("Math.divide",2);
    else if(op=='>')
      v->writeArithmetic(C_GT);
    else if(op=='<')
      v->writeArithmetic(C_LT);
    else if(op=='&')
      v->writeArithmetic(C_AND);
    else if(op=='|')
      v->writeArithmetic(C_OR);
    else if(op=='=')
      v->writeArithmetic(C_EQ);
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
      Kind k=sym->kindOf(t->token);
      printId(fout, t, kindString[k] ,false,k);// varName
      printToken(fout, t); //[
      compileExpression(); // expression
      printToken(fout, t); //]
    }
    else
    {
      // var
      Kind k=sym->kindOf(t->token);
      string varName=t->token;
      v->writePush(k2s[k],sym->indexOf(varName));
      printId(fout, t, kindString[k] ,false,k);// varName

    }
  }
  else if (t->TokenType() == INT_CONST or t->TokenType() == STRING_CONST or t->TokenType() == KEYWORD)
  {
    if(t->TokenType() == INT_CONST){
      v->writePush(S_CONST,t->intVal());
    }else if(t->TokenType() == KEYWORD){
      if(t->keyWord()==TRUE){
        v->writePush(S_CONST,1);
        v->writeArithmetic(C_NEG);
      }else if(t->keyWord()==K_NULL or t->keyWord()==FALSE){
        v->writePush(S_CONST,0);
      }
    }
    printToken(fout, t);
  }
  else if (t->TokenType() == SYMBOL and t->symbol() == '(')
  {
    printToken(fout, t); //(
    compileExpression();
    printToken(fout, t); //)
  }
  else if (t->TokenType() == SYMBOL and t->symbol() == '-')
  {
    printToken(fout, t); //-
    compileTerm();
    v->writeArithmetic(C_NEG);
  }
  else if (t->TokenType() == SYMBOL and t->symbol() == '~')
  {
    printToken(fout, t); //~
    compileTerm();
    v->writeArithmetic(C_NOT);
  }
  fout << "</term>" << endl;
}
int CompilationEngine::compileExpressionList()
{
  int ans=0;
  fout << "<expressionList>" << endl;
  if (t->TokenType() == SYMBOL and (t->symbol() == ')'))
  {
    fout << "</expressionList>" << endl;
    return ans;
  }
  compileExpression();
  ans++;
  while (t->TokenType() == SYMBOL and (t->symbol() == ','))
  {
    printToken(fout, t); //,
    compileExpression();
    ans++;
  }
  fout << "</expressionList>" << endl;
  return ans;
}
