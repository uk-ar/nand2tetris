#include <iostream>
#include <fstream>
#include <filesystem>
#include <dirent.h>
#include <sys/stat.h>
using namespace std;
#include "Parser.h"
#include "CommandWriter.h"
namespace fs=std::filesystem;

string stripExt(string s){
  string::size_type pos;
  if((pos=s.find_last_of("."))==string::npos)
    return s;
  return s.substr(0,pos);
}

string getExt(string s){
  string::size_type pos;
  if((pos=s.find_last_of("."))==string::npos)
    return s;
  return s.substr(pos);
}

void parseFile(string fileName,CommandWriter *c,ofstream &fout){
  ifstream fin{fileName};
  if(!static_cast<bool>(fin)){
    cout << "cannot open file '"+fileName <<"'"<<endl;
    exit(-1);
  }

  Parser *p=new Parser(fin);
  c->setFileName(fileName);
  while(p->hasMoreCommands()){
    fout << "// "+ p->m_inst << endl;
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
}
int main(int argc, char *argv[])
{
  if(argc!=2){
    cout<<"usage:"<<endl;
    cout << string(argv[0])+" source_file"<<endl;
    cout << string(argv[0])+" source_directory"<<endl;
    exit(-1);
  }
  struct stat sb;
  stat(argv[1],&sb);
  if(!S_ISREG(sb.st_mode) and !S_ISDIR(sb.st_mode)){
    cout << string(argv[1])+" is not regularfile or directory"<<endl;
    exit(-1);
  }

  if(S_ISREG(sb.st_mode)){
    string ofileName=string(stripExt(argv[1]))+".asm";
    ofstream fout{ofileName};
    CommandWriter *c=new CommandWriter(fout);
    c->writeInit();

    parseFile(string(argv[1]),c,fout);
  }else{
    DIR*dp;
    dp=opendir(argv[1]);
    string path=string(argv[1]);
    if(path.back()=='/')
      path.pop_back();
    fs::path p=path;
    dirent*entry = readdir(dp);
    p/=p.filename().string()+".asm";
    ofstream fout{p.string()};
    CommandWriter *c=new CommandWriter(fout);
    c->writeInit();

    while(entry!=NULL){
      if(entry!=NULL){
        if(getExt(string(entry->d_name))==".vm"){
          cout<< path+"/"+entry->d_name <<endl;
          parseFile(path+"/"+entry->d_name,c,fout);
        }
      }
      entry=readdir(dp);
    }
  }
  return 0;
}
