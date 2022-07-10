#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <dirent.h>
#include <sys/stat.h>
using namespace std;

#include "CompilationEngine.h"
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

void parseFile(string fileName,ofstream &fout){

  ifstream fin{fileName};
  if(!static_cast<bool>(fin)){
    cout << "cannot open file '"+fileName <<"'"<<endl;
    exit(-1);
  }

  fs::path q=fileName;
  //cout << q.stem().string() <<endl;
  JackTokenizer *t=new JackTokenizer(fin);
  fout << "<tokens>"<< endl;
  while(t->hasMoreTokens()){
    fout << "<"+t->tokenString()+"> " << xmlescape(t->token) << " </"+t->tokenString()+">" << endl;
    t->advance();
  }
  fout << "</tokens>"<< endl;
}

void compileFile(string fileName,ofstream &fout){

  ifstream fin{fileName};
  if(!static_cast<bool>(fin)){
    cout << "cannot open file '"+fileName <<"'"<<endl;
    exit(-1);
  }

  //cout << q.stem().string() <<endl;
  //JackTokenizer *t=new JackTokenizer(fin);
  CompilationEngine *c=new CompilationEngine(fin,fout);
  c->compileClass();
  // fout << "<tokens>"<< endl;
  // while(t->hasMoreTokens()){
  //   fout << "<"+typeStrings[t->tokenType]+"> " << xmlescape(t->token) << " </"+typeStrings[t->tokenType]+">" << endl;
  //   t->advance();
  // }
  // fout << "</tokens>"<< endl;
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
    //string ofileName=string(stripExt(argv[1]))+"T.xml";
    string ofileName=string(stripExt(argv[1]))+".vm";
    ofstream fout{ofileName};

    compileFile(string(argv[1]),fout);
    //parseFile(string(argv[1]),fout);
  }else{
    DIR*dp;
    dp=opendir(argv[1]);
    string path=string(argv[1]);
    if(path.back()=='/')
      path.pop_back();

    dirent*entry = readdir(dp);
    while(entry!=NULL){
      if(entry!=NULL){
        if(getExt(string(entry->d_name))==".jack"){
          cout<< path+"/"+entry->d_name <<endl;
          //string ofileName=stripExt(path+"/"+entry->d_name)+"T.xml";
          string ofileName=stripExt(path+"/"+entry->d_name)+".vm";
          ofstream fout{ofileName};
          cout<< ofileName <<endl;
          compileFile(path+"/"+entry->d_name,fout);
          //parseFile(path+"/"+entry->d_name,fout);
        }
      }
      entry=readdir(dp);
    }
  }
  return 0;
}
