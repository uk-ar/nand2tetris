#include <iostream>
#include <sstream>
#include <algorithm>
#include "Parser.h"
using namespace std;

Parser::Parser(istream &inputStream): is(inputStream){
  advance();
}

Parser::~Parser(){

}
bool Parser::hasMoreCommands(){
  return !eof;
}

void Parser::advance(){
  string t;
  while(getline(is,t)){
    t.erase(t.begin(), std::find_if(t.begin(), t.end(), [](unsigned char ch) {
      return !std::isspace(ch);
      }));
    stringstream ss0(t);
    ss0 >> m_inst;
    stringstream ss(m_inst);
    if(m_inst[0]=='/' or m_inst=="")
      continue;
    // cout << m_inst<<endl;
    // cout << string(m_inst.size(),'_')<<endl;
    if(commandType()==A_COMMAND){
      m_symbol=m_inst.substr(1);
      return;
    }else if(commandType()==L_COMMAND){
      int n=m_inst.size();
      m_symbol=m_inst.substr(1,n-2);
      return;
    }
    if(m_inst.find('=')==string::npos){
      m_dest="";
    }else{
      getline(ss,m_dest,'=');
    }
    if(m_inst.find(';')==string::npos){
      getline(ss,m_comp);
      m_jump="";
    }else{
      getline(ss,m_comp,';');
      getline(ss,m_jump);
    }
    // cout << m_dest <<endl;
    // cout << m_comp <<endl;
    // cout << m_jump <<endl;
    return;
  }
  eof=true;
}

enum comType Parser::commandType(){
  if(m_inst[0]=='@')//@Xxx
    return A_COMMAND;
  if(m_inst[0]=='(')//(Xxx)
    return L_COMMAND;
  return C_COMMAND;
}
string Parser::symbol(){
  return m_symbol;
}
string Parser::dest(){
  return m_dest;
}
string Parser::comp(){
  return m_comp;
}
string Parser::jump(){
  return m_jump;
}
