#include <string>
#include <unordered_map>
#include <iostream>
#include "CommandWriter.h"
using namespace std;

CommandWriter::CommandWriter(ostream &outputStream): os(outputStream){

}
void CommandWriter::setFileName(string fileName){
}
void arg1(string command){
  cout << "@SP" << endl;
  cout << "A=M" << endl;
  cout << "A=A-1" << endl;
  if(command=="neg")
    cout << "M=-M" << endl;
  else if(command=="not")
    cout << "M=!M" << endl;
}
void arg2(string command){
  cout << "@SP" << endl;
  cout << "M=M-1" << endl;
  cout << "A=M" << endl;
  cout << "D=M" << endl;

  cout << "@SP" << endl;
  cout << "A=M-1" << endl;
  if(command=="add"){
    cout << "D=M+D" << endl;
  }else if(command=="sub"){
    cout << "D=M-D" << endl;
  }else if(command=="and"){
    cout << "D=D&M" << endl;
  }else if(command=="or"){
    cout << "D=D|M" << endl;
  }
  cout << "@SP" << endl;
  cout << "A=M-1" << endl;
  cout << "M=D" << endl;
}
void comp(string command){
  static int cnt=0;
  string label="true"+to_string(cnt);
  cnt++;
  cout << "@result" << endl;
  cout << "M=-1" << endl;//true

  arg2("sub");//result is stored in D
  cout << "@"+label << endl;
  if(command=="eq")
    cout << "D;JEQ" << endl;
  if(command=="lt")
    cout << "D;JLT" << endl;
  if(command=="gt")
    cout << "D;JGT" << endl;

  cout << "@result" << endl;
  cout << "M=0" << endl;//false

  cout << "("+label+")" << endl;
  cout << "@result" << endl;
  cout << "D=M" << endl;

  cout << "@SP" << endl;
  cout << "A=M" << endl;
  cout << "A=A-1" << endl;
  cout << "M=D" << endl;
}
void CommandWriter::writeArithmetic(string command){
  //cout << command <<endl;
  if(command=="add" or command=="sub" or command=="and" or command=="or"){
    arg2(command);
  }else if(command=="neg" or command=="not"){
    arg1(command);
  }if(command=="eq" or command=="gt" or command=="lt"){
    comp(command);
  }else{
    //cout << command << endl;
    //assert(false);
    //abort();
  }
}
void getFromSegment(string segment,int index,string &fileName){
  if(segment=="constant"){
    cout << "@"<<index << endl;
    cout << "D=A" << endl;
    return;
  }else if(segment=="static"){
    cout << "@"+fileName+"."+to_string(index) << endl;
    cout << "D=M" << endl;
    return;
  }else if(segment=="local"){
    cout << "@LCL" << endl;
    cout << "D=M" << endl;
  }else if(segment=="argument"){
    cout << "@ARG" << endl;
    cout << "D=M" << endl;
  }else if(segment=="this"){
    cout << "@THIS" << endl;
    cout << "D=M" << endl;
  }else if(segment=="that"){
    cout << "@THAT" << endl;
    cout << "D=M" << endl;
  }else if(segment=="temp"){
    cout << "@R5" << endl;
    cout << "D=A" << endl;
  }else if(segment=="pointer"){
    cout << "@THIS" << endl;
    cout << "D=A" << endl;
  }else{
    assert(false);
  }
  cout << "@"+to_string(index) << endl;
  cout << "A=D+A" << endl;
  cout << "D=M" << endl;
  //Store Data to D
}
void setToSegment(string segment,int index,string &fileName){

}
void CommandWriter::writePushPop(VMcomType command,string segment,int index){
  if(command==C_PUSH){
    getFromSegment(segment,index,fileName);

    cout << "@SP" << endl;
    cout << "A=M" << endl;
    cout << "M=D" << endl;

    cout << "@SP" << endl;
    cout << "M=M+1" << endl;
  }else if(command==C_POP){//from Sp
    cout << "@SP" << endl;
    cout << "M=M-1" << endl;
    cout << "A=M" << endl;
    cout << "D=M" << endl;

    cout << "@data" << endl;
    cout << "M=D" << endl;

    if(segment=="local"){
      cout << "@LCL" << endl;
      cout << "D=M" << endl;
    }else if(segment=="argument"){
      cout << "@ARG" << endl;
      cout << "D=M" << endl;
    }else if(segment=="this"){
      cout << "@THIS" << endl;
      cout << "D=M" << endl;
    }else if(segment=="that"){
      cout << "@THAT" << endl;
      cout << "D=M" << endl;
    }else if(segment=="temp"){
      cout << "@R5" << endl;
      cout << "D=A" << endl;
    }else if(segment=="pointer"){
      cout << "@THIS" << endl;
      cout << "D=A" << endl;
    }else if(segment=="static"){
    }else{
      //cout << segment <<endl;
      assert(false);
    }

    if(segment=="static"){
      cout << "@"+fileName+"."+to_string(index) << endl;
      cout << "D=A" << endl;
    }else{
      cout << "@"+to_string(index) << endl;
      cout << "D=D+A" << endl;
    }

    cout << "@address" << endl;
    cout << "M=D" << endl;

    cout << "@data" << endl;
    cout << "D=M" << endl;

    cout << "@address" << endl;
    cout << "A=M" << endl;
    cout << "M=D" << endl;

  }else{
    assert(false);
    //abort();
  }

  // cout << command <<endl;
  // cout << segment <<endl;
  // cout << index <<endl;
}
void CommandWriter::close(){

}
