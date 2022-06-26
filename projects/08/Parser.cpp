#include <iostream>
#include <sstream>
#include <algorithm>
#include "Parser.h"
using namespace std;

Parser::Parser(istream &inputStream): is(inputStream),m({
    {"push",C_PUSH},{"pop",C_POP},{"label",C_LABEL},{"goto",C_GOTO},
      {"if-goto",C_IF},{"function",C_FUNCTION},{"call",C_CALL},{"return",C_RETURN}
      //function functionName nLocals
      //call functionName nArgs
  }){
  //advance();
}

Parser::~Parser(){

}

bool Parser::hasMoreCommands(){
  return !eof;
}

void Parser::advance(){
  while(getline(is,m_inst)){
    if(m_inst[0]=='/' or m_inst=="" or m_inst==" " or m_inst.size()<3)
      continue;
    stringstream ss(m_inst);

    ss >> m_command;

    // cout << m_inst << endl;
    // cout << string(m_inst.size(),'_') << endl;

    if(m_command[0]=='/' or m_command=="" or m_command==" ")
      continue;
    // cout << m_command << endl;
    // cout << string(m_command.size(),'_') << endl;

    m_VMcomType=m[m_command];
    if(m_VMcomType==C_PUSH or m_VMcomType==C_POP or m_VMcomType==C_FUNCTION or
       m_VMcomType==C_CALL){
      ss>>m_arg1;
      ss>>m_arg2;
    }else if(m_VMcomType==C_ARITHMETIC){
      m_arg1=m_command;
    }else if(m_VMcomType==C_LABEL or m_VMcomType==C_GOTO or m_VMcomType==C_IF){
      ss>>m_arg1;
    }
    // cout << m_inst << endl;
    // cout << m_command << endl;
    // cout << string(m_command.size(),'_')<<endl;
    // cout << m_VMcomType << endl;
    return;
  }
  eof=true;
}

enum VMcomType Parser::commandType(){
  return m_VMcomType;
}
string Parser::arg1(){
  return m_arg1;
}
int Parser::arg2(){
  return m_arg2;
}
