#ifndef VMWRITER_H
#define VMWRITER_H

#include <string>
#include <unordered_map>
#include "Types.h"
#include "JackTokenizer.h"
#include "SymbolTable.h"
using namespace std;

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

class VMWriter{
 public:
  ostream &fout;
  VMWriter(ostream &outputStream);
  void writePush(Segment segment,int index);
  void writePop(Segment segment,int index);
  void writeArithmetic(Command command);
  void writeLabel(string label);
  void writeGoto(string label);
  void writeIf(string label);
  void writeCall(string name,int nArgs);
  void writeFunction(string name,int nLocals);
  void writeReturn();
  void close();
};
#endif //VMWRITER_H
