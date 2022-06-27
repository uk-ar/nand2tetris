#include <iostream>
#include <fstream>
using namespace std;
#include "Parser.h"
#include "CommandWriter.h"

int main(int argc, char *argv[])
{
  if(argc!=2){
    cout<<"usage:"+string(argv[0])+" input.asm"<<endl;
    exit(-1);
  }
  ifstream fin{string(argv[1])};
  if(!static_cast<bool>(fin)){
    cout << "cannot open file '"+string(argv[1]) <<"'"<<endl;
    exit(-1);
  }
  Parser *p=new Parser(fin);
  string fileName=string(argv[1])+".asm";
  ofstream fout{fileName};
  CommandWriter *c=new CommandWriter(fout);
  c->setFileName(fileName);
  int cnt=0;
  int offset=16;
  p=new Parser(fin);
  while(p->hasMoreCommands()){
    cout << "// "+ p->m_inst << endl;
    // cout << string(p->m_inst.size(),'_') << endl;
    if(p->commandType()==C_ARITHMETIC){
      c->writeArithmetic(p->arg1());
    }else if(p->commandType()==C_PUSH or p->commandType()==C_POP){
      c->writePushPop(p->commandType(),p->arg1(),p->arg2());
    }else if(p->commandType()==C_LABEL){
      c->writeLabel(p->arg1());
    }else if(p->commandType()==C_GOTO){
      c->writeGoto(p->arg1());
    }else if(p->commandType()==C_IF){
      c->writeIf(p->arg1());
    }else if(p->commandType()==C_CALL){
      c->writeCall(p->arg1(),p->arg2());
    }else if(p->commandType()==C_FUNCTION){
      c->writeFunction(p->arg1(),p->arg2());
    }else if(p->commandType()==C_RETURN){
      c->writeReturn();
    }
    // cout << p->m_inst << endl;
    // cout << p->m_command << endl;
    // cout << p->m_VMcomType << endl;
    // cout << p->m_arg1 << endl;
    p->advance();
  }
  return 0;
}
