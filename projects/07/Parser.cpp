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
    stringstream ss(m_inst);
    ss >> m_command;
    if(m_command[0]=='/' or m_command=="")
      continue;

    m_VMcomType=m[m_command];
    if(m_VMcomType==C_PUSH or m_VMcomType==C_POP or m_VMcomType==C_FUNCTION or
       m_VMcomType==C_CALL){
      ss>>m_arg1;
      ss>>m_arg2;
    }else{
      m_VMcomType=C_ARITHMETIC;
      m_arg1=m_command;
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
