#include <string>
#include <iostream>
#include <unordered_map>
#include "SymbolTable.h"

using namespace std;
SymbolTable::SymbolTable():m({{"R0",0},{"R1",1},{"R2",2},{"R3",3},{"R4",4},{"R5",5},{"R6",6},{"R7",7},{"R8",8},{"R9",9},{"R10",10},{"R11",11},{"R12",12},{"R13",13},{"R14",14},{"R15",15},{"SP",0},{"LCL",1},{"ARG",2},{"THIS",3},{"THAT",4},{"SCREEN",0x4000},{"KBD",0x6000}}){

};
void SymbolTable::print(){
  for(auto p:m){
    cout << p.first <<":"<<p.second<<endl;
  }
}
void SymbolTable::addEntry(string symbol,int address){
  m[symbol]=address;
}
bool SymbolTable::contains(string symbol){
  if(isdigit(symbol[0]))
    return true;
  return m.count(symbol)>0;
}
int SymbolTable::getAddress(string symbol){
  if(isdigit(symbol[0]))
    return stoi(symbol);
  return m[symbol];
}
