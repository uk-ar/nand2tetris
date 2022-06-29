#include <string>
#include <unordered_map>
#include <iostream>
#include "CommandWriter.h"
using namespace std;

CommandWriter::CommandWriter(ostream &outputStream):fout(outputStream),line(0){

}
void CommandWriter::setFileName(string fileName){
  this->fileName=fileName;
}

void arg1(string command,ostream &fout,int &line){
  fout << "@SP" << " //" << line++ << endl;
  fout << "A=M" << " //" << line++ << endl;
  fout << "A=A-1" << " //" << line++ << endl;
  if(command=="neg")
    fout << "M=-M" << " //" << line++ << endl;
  else if(command=="not")
    fout << "M=!M" << " //" << line++ << endl;
}
void arg2(string command,ostream &fout,int &line){
  fout << "@SP" << " //" << line++ << endl;
  fout << "M=M-1" << " //" << line++ << endl;
  fout << "A=M" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;

  fout << "@SP" << " //" << line++ << endl;
  fout << "A=M-1" << " //" << line++ << endl;
  if(command=="add"){
    fout << "D=M+D" << " //" << line++ << endl;
  }else if(command=="sub"){
    fout << "D=M-D" << " //" << line++ << endl;
  }else if(command=="and"){
    fout << "D=D&M" << " //" << line++ << endl;
  }else if(command=="or"){
    fout << "D=D|M" << " //" << line++ << endl;
  }
  fout << "@SP" << " //" << line++ << endl;
  fout << "A=M-1" << " //" << line++ << endl;
  fout << "M=D" << " //" << line++ << endl;
}
void comp(string command,ostream &fout,int &line){
  static int cnt=0;
  string label="true"+to_string(cnt);
  cnt++;
  fout << "@result" << " //" << line++ << endl;
  fout << "M=-1" << " //" << line++ << endl;//true

  arg2("sub",fout,line);//result is stored in D
  fout << "@"+label << " //" << line++ << endl;
  if(command=="eq")
    fout << "D;JEQ" << " //" << line++ << endl;
  if(command=="lt")
    fout << "D;JLT" << " //" << line++ << endl;
  if(command=="gt")
    fout << "D;JGT" << " //" << line++ << endl;

  fout << "@result" << " //" << line++ << endl;
  fout << "M=0" << " //" << line++ << endl;//false

  fout << "("+label+")" << " //" << line++ << endl;
  fout << "@result" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;

  fout << "@SP" << " //" << line++ << endl;
  fout << "A=M" << " //" << line++ << endl;
  fout << "A=A-1" << " //" << line++ << endl;
  fout << "M=D" << " //" << line++ << endl;
}
void CommandWriter::writeArithmetic(string command){
  //fout << command <<endl;
  if(command=="add" or command=="sub" or command=="and" or command=="or"){
    arg2(command,fout,line);
  }else if(command=="neg" or command=="not"){
    arg1(command,fout,line);
  }if(command=="eq" or command=="gt" or command=="lt"){
    comp(command,fout,line);
  }else{
    //fout << command << " //" << line++ << endl;
    //assert(false);
    //abort();
  }
}
void getFromSegment(string segment,int index,string &fileName,ostream &fout,int &line){
  if(segment=="constant"){
    fout << "@"<<index << " //" << line++ << endl;
    fout << "D=A" << " //" << line++ << endl;
    return;
  }else if(segment=="static"){
    fout << "@"+fileName+"."+to_string(index) << " //" << line++ << endl;
    fout << "D=M" << " //" << line++ << endl;
    return;
  }else if(segment=="local"){
    fout << "@LCL" << " //" << line++ << endl;
    fout << "D=M" << " //" << line++ << endl;
  }else if(segment=="argument"){
    fout << "@ARG" << " //" << line++ << endl;
    fout << "D=M" << " //" << line++ << endl;
  }else if(segment=="this"){
    fout << "@THIS" << " //" << line++ << endl;
    fout << "D=M" << " //" << line++ << endl;
  }else if(segment=="that"){
    fout << "@THAT" << " //" << line++ << endl;
    fout << "D=M" << " //" << line++ << endl;
  }else if(segment=="temp"){
    fout << "@R5" << " //" << line++ << endl;
    fout << "D=A" << " //" << line++ << endl;
  }else if(segment=="pointer"){
    fout << "@THIS" << " //" << line++ << endl;
    fout << "D=A" << " //" << line++ << endl;
  }else{
    assert(false);
  }
  fout << "@"+to_string(index) << " //" << line++ << endl;
  fout << "A=D+A" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  //Store Data to D
}
void pushD(ostream &fout,int &line){
  fout << "@SP" << " //" << line++ << endl;
  fout << "A=M" << " //" << line++ << endl;
  fout << "M=D" << " //" << line++ << endl;

  fout << "@SP" << " //" << line++ << endl;
  fout << "M=M+1" << " //" << line++ << endl;
}
void popD(ostream &fout,int &line){
  fout << "@SP" << " //" << line++ << endl;
  fout << "M=M-1" << " //" << line++ << endl;
  fout << "A=M" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
}
void CommandWriter::writePushPop(VMcomType command,string segment,int index){
  if(command==C_PUSH){
    getFromSegment(segment,index,fileName,fout,line);
    pushD(fout,line);
  }else if(command==C_POP){//from Sp
    popD(fout,line);

    fout << "@data" << " //" << line++ << endl;
    fout << "M=D" << " //" << line++ << endl;

    if(segment=="local"){
      fout << "@LCL" << " //" << line++ << endl;
      fout << "D=M" << " //" << line++ << endl;
    }else if(segment=="argument"){
      fout << "@ARG" << " //" << line++ << endl;
      fout << "D=M" << " //" << line++ << endl;
    }else if(segment=="this"){
      fout << "@THIS" << " //" << line++ << endl;
      fout << "D=M" << " //" << line++ << endl;
    }else if(segment=="that"){
      fout << "@THAT" << " //" << line++ << endl;
      fout << "D=M" << " //" << line++ << endl;
    }else if(segment=="temp"){
      fout << "@R5" << " //" << line++ << endl;
      fout << "D=A" << " //" << line++ << endl;
    }else if(segment=="pointer"){
      fout << "@THIS" << " //" << line++ << endl;
      fout << "D=A" << " //" << line++ << endl;
    }else if(segment=="static"){
    }else{
      fout << segment <<endl;
      assert(false);
    }

    if(segment=="static"){
      fout << "@"+fileName+"."+to_string(index) << " //" << line++ << endl;
      fout << "D=A" << " //" << line++ << endl;
    }else{
      fout << "@"+to_string(index) << " //" << line++ << endl;
      fout << "D=D+A" << " //" << line++ << endl;
    }

    fout << "@address" << " //" << line++ << endl;
    fout << "M=D" << " //" << line++ << endl;

    fout << "@data" << " //" << line++ << endl;
    fout << "D=M" << " //" << line++ << endl;

    fout << "@address" << " //" << line++ << endl;
    fout << "A=M" << " //" << line++ << endl;
    fout << "M=D" << " //" << line++ << endl;

  }else{
    assert(false);
    //abort();
  }

  // fout << command <<endl;
  // fout << segment <<endl;
  // fout << index <<endl;
}

void CommandWriter::writeLabel(string label){
  fout << "("+label+")" << endl;
}
void CommandWriter::writeGoto(string label){
  fout << "@"+label << " //" << line++ << endl;
  fout << "0;JMP" << " //" << line++ << endl;
}
void CommandWriter::writeIf(string label){
  popD(fout,line);

  fout << "@"+label << " //" << line++ << endl;
  fout << "D;JNE" << " //" << line++ << endl;
}
void CommandWriter::writeInit(){
  fout << "@256" << " //" << line++ <<endl;
  fout << "D=A" << " //" << line++ <<endl;
  fout << "@SP" << " //" << line++ <<endl;
  fout << "M=D" << " //" << line++ <<endl;
  writeCall("Sys.init",0);
}
void CommandWriter::writeCall(string functionName,int numLocals){
  static int cnt=0;
  string r_address="return-address"+to_string(cnt++);
  fout << "@"+r_address << " //" << line++ << endl;
  fout << "D=A" << " //" << line++ << endl;
  pushD(fout,line);

  fout << "@LCL" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  pushD(fout,line);
  fout << "@ARG" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  pushD(fout,line);
  fout << "@THIS" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  pushD(fout,line);
  fout << "@THAT" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  pushD(fout,line);

  fout << "@SP" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  fout << "@" + to_string(numLocals) << " //" << line++ << endl;
  fout << "D=D-A" << " //" << line++ << endl;
  fout << "@5" << " //" << line++ << endl;
  fout << "D=D-A" <<" //ARG=SP-n-5"<< " //" << line++ << endl;
  fout << "@ARG" << " //" << line++ << endl;
  fout << "M=D" << " //" << line++ << endl;

  fout << "@SP" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  fout << "@LCL" << " //" << line++ << endl;
  fout << "M=D" << " //" << line++ << endl;
  writeGoto(functionName);
  writeLabel(r_address);
}
void CommandWriter::writeReturn(){
  fout << "@LCL" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;//Address
  fout << "@FRAME" << " //" << line++ << endl;
  fout << "M=D" << " //" << line++ << endl;

  fout << "@5" << " //" << line++ << endl;
  fout << "A=D-A" << " //RET=*(FRAME-5)" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  fout << "@RET" << " //return address " << " //" << line++  <<endl;
  fout << "M=D" << " //" << line++ << endl;

  //*ARG=pop()
  popD(fout,line);
  fout << "@ARG" << " //" << line++ << endl;
  fout << "A=M" << " //" << line++ << endl;
  fout << "M=D" << " //" << line++ << endl;

  fout << "@ARG" << " //" << line++ << endl;
  fout << "D=M+1" << " //" << line++ << endl;
  fout << "@SP" << " //" << line++ << endl;
  fout << "M=D" << " //" << line++ << endl;//SP=ARG+1

  fout << "@FRAME" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  fout << "@1" << " //" << line++ << endl;
  fout << "A=D-A" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  fout << "@THAT" << " //" << line++ << endl;//THAT=*(FRAME-1)
  fout << "M=D" << " //" << line++ << endl;

  fout << "@FRAME" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  fout << "@2" << " //" << line++ << endl;
  fout << "A=D-A" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  fout << "@THIS" << " //" << line++ << endl;//THIS=*(FRAME-2)
  fout << "M=D" << " //" << line++ << endl;

  fout << "@FRAME" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  fout << "@3" << " //" << line++ << endl;
  fout << "A=D-A" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  fout << "@ARG" << " //" << line++ << endl;//ARG=*(FRAME-3)
  fout << "M=D" << " //" << line++ << endl;

  fout << "@FRAME" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  fout << "@4" << " //" << line++ << endl;
  fout << "A=D-A" << " //" << line++ << endl;
  fout << "D=M" << " //" << line++ << endl;
  fout << "@LCL" << " //" << line++ << endl;//LCL=*(FRAME-4)
  fout << "M=D" << " //" << line++ << endl;

  fout << "@RET" << " //" << line++ << endl;
  fout << "A=M" << " //" << line++ << endl;
  fout << "0;JMP" << " //" << line++ << endl;
}
void CommandWriter::writeFunction(string functionName,int numLocals){
  writeLabel(functionName);
  for(int i=0;i<numLocals;i++){
    writePushPop(C_PUSH,"constant",0);
  }
}
void CommandWriter::close(){

}
