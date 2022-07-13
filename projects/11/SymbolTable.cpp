#include <string>
#include <unordered_map>
#include <iostream>
#include "SymbolTable.h"
vector<string> kindString({"static","field","arg","var","none"});

using namespace std;

SymbolTable::SymbolTable():nums(4)
{

}

SymbolTable::~SymbolTable()
{

}

void SymbolTable::startSubroutine()
{
  subK.clear();
  subT.clear();
  subI.clear();
  nums[K_ARG]=0;
  nums[K_VAR]=0;
}

void SymbolTable::define(string name,string type,Kind kind){
  //cerr << name <<","<< type <<","<< kindString[kind]<<endl;
  if(kind==K_STATIC or kind==K_FIELD){
    classK[name]=kind;
    classT[name]=type;
    classI[name]=nums[kind]++;
  }else{//arg,var
    subK[name]=kind;
    subT[name]=type;
    subI[name]=nums[kind]++;
  }
}
int SymbolTable::varCount(Kind kind){
  return nums[kind];
}
Kind SymbolTable::kindOf(string name){
  if(subK.count(name))
    return subK[name];
  if(classK.count(name))
    return classK[name];
  return K_NONE;
}
string SymbolTable::typeOf(string name){
  if(subT.count(name))
    return subT[name];
  if(classT.count(name))
    return classT[name];
  return "";
}
int SymbolTable::indexOf(string name){
  if(subI.count(name))
    return subI[name];
  if(classI.count(name))
    return classI[name];
  return -1;
}
