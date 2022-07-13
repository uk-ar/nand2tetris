#include <string>
#include <unordered_map>
#include "Types.h"
#include "JackTokenizer.h"
#include "SymbolTable.h"
#include "VMWriter.h"
using namespace std;

class CompilationEngine{
  ostream &fout;
  istream &fin;
  int line=0;
  string fileName;
  //
  JackTokenizer *t;
  SymbolTable *sym;
  VMWriter *v;
  string className;
 public:
  CompilationEngine(istream &inputStream, ostream &outputStream,ostream &debugStream);
  //CompilationEngine(ostream &outputStream);
  void compileClass();
  void compileClassVarDec();
  void compileSubroutine();
  void compileParameterList();
  void compileVarDec();
  void compileStatement();
  void compileDo();
  void compileLet();
  void compileWhile();
  void compileIf();
  void compileExpression();
  void compileTerm();
  int compileExpressionList();
  void compileSubroutineCall();
};
