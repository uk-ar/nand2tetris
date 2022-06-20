#include <string>
#include <unordered_map>
#include <iostream>
#include "CommandWriter.h"
using namespace std;

CommandWriter::CommandWriter(ostream &outputStream): os(outputStream){

}
void CommandWriter::setFileName(string fileName){
}
void CommandWriter::writeArithmetic(string command){
  //cout << command <<endl;
  if(command=="add"){
    cout << "@SP" << endl;
    cout << "M=M-1" << endl;

    cout << "@SP" << endl;
    cout << "A=M" << endl;
    cout << "D=M" << endl;

    cout << "@SP" << endl;
    cout << "M=M-1" << endl;

    cout << "@SP" << endl;
    cout << "A=M" << endl;
    cout << "D=D+M" << endl;

    cout << "@SP" << endl;
    cout << "A=M" << endl;
    cout << "M=D" << endl;
  }else if(command=="sub"){

  }else if(command=="neg"){

  }else if(command=="eq"){
  }else if(command=="gt"){
    // if(true)return -1;
    // return 0;
  }else if(command=="lt"){
  }else if(command=="and"){
  }else if(command=="or"){
  }else if(command=="not"){

  }else{
    //abort();
  }
}
void CommandWriter::writePushPop(VMcomType command,string segment,int index){
  if(command==C_PUSH){
    if(segment=="constant"){
      cout << "@"<<index << endl;
      cout << "D=A" << endl;
    }

    cout << "@SP" << endl;
    cout << "A=M" << endl;
    cout << "M=D" << endl;

    cout << "@SP" << endl;
    cout << "M=M+1" << endl;
  }else if(command==C_POP){
    cout << "@SP" << endl;
    cout << "M=M-1" << endl;

    cout << "@SP" << endl;
    cout << "A=M" << endl;
    cout << "D=M" << endl;
  }else{
    //abort();
  }

  // cout << command <<endl;
  // cout << segment <<endl;
  // cout << index <<endl;
}
void CommandWriter::close(){

}
