#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "Types.h"
#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
using namespace std;
enum Kind{
  K_STATIC,
  K_FIELD,
  K_ARG,
  K_VAR,
  K_NONE
};
extern vector<string> kindString;
class SymbolTable{
  unordered_map<string,Kind>classK;
  unordered_map<string,string>classT;
  unordered_map<string,int>classI;

  unordered_map<string,Kind>subK;
  unordered_map<string,string>subT;
  unordered_map<string,int>subI;
  vector<int>nums;
public:
  SymbolTable();
  virtual ~SymbolTable();
  void startSubroutine();
  void define(string name,string type,Kind kind);
  int varCount(Kind kind);
  Kind kindOf(string name);//K_STATIC,K_FIELD,...
  string typeOf(string name);//void,...
  int indexOf(string name);
};
#endif //SYMBOLTABLE_H
