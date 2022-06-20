#include <iostream>
#include <fstream>
using namespace std;
#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"

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
  Code *c=new Code();
  SymbolTable *s=new SymbolTable();
  int cnt=0;
  while(p->hasMoreCommands()){
    if(p->commandType()==L_COMMAND){
      s->addEntry(p->symbol(),cnt);
    }else{
      cnt++;
    }
    p->advance();
  }
  //s->print();
  fin.clear();//clear eof flag
  fin.seekg(0,ios_base::beg);
  int offset=16;
  p=new Parser(fin);
  while(p->hasMoreCommands()){
    if(p->commandType()==A_COMMAND){
      if(!s->contains(p->symbol())){
        s->addEntry(p->symbol(),offset++);
      }
      cout <<"0"<< bitset<15>(s->getAddress(p->symbol()))<<endl;
    }else if(p->commandType()==C_COMMAND){
      // cout << p->m_inst<<endl;
      //cout << p->m_comp << ":"<<p->m_dest << ":"<< p->m_jump <<endl;
      cout <<"111"<< c->comp(p->m_comp) << c->dest(p->dest()) << c->jump(p->jump())<<endl;
    }
    p->advance();
  }
  return 0;
}
