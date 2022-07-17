#include <string>
#include <unordered_map>
#include <iostream>
#include "VMWriter.h"

using namespace std;

VMWriter::VMWriter(ostream &outputStream,ostream &debugStream):fout(outputStream),line(0),dout(debugStream){
}

vector<string>seg({"constant","argument","local","static","this","that","pointer","temp"});
void VMWriter::writePush(Segment segment,int index){
  dout << "push " << seg[segment] << " " << index <<" //"<< line << endl;
  fout << "push " << seg[segment] << " " << index <<" //"<< line++ << endl;

}
void VMWriter::writePop(Segment segment,int index){
  dout << "pop " << seg[segment] << " " << index <<" //"<< line << endl;
  fout << "pop " << seg[segment] << " " << index <<" //"<< line++ << endl;
}
vector<string>arith({"add","sub","neg","eq","gt","lt","and","or","not"});
void VMWriter::writeArithmetic(Command command){
  dout << arith[command] <<" //"<< line << endl;
  fout << arith[command] <<" //"<< line++ << endl;
}
void VMWriter::writeLabel(string label){
  dout << "label "+label <<" //"<< line << endl;
  fout << "label "+label <<" //"<< line++ << endl;
}
void VMWriter::writeGoto(string label){
  dout << "goto "+label <<" //"<< line << endl;
  fout << "goto "+label <<" //"<< line++ << endl;
}
void VMWriter::writeIf(string label){
  dout << "if-goto "+label <<" //"<< line << endl;
  fout << "if-goto "+label <<" //"<< line++ << endl;
}
void VMWriter::writeCall(string name,int nArgs){
  dout << "call " << name << " " << nArgs <<" //"<< line << endl;
  fout << "call " << name << " " << nArgs <<" //"<< line++ << endl;
}
void VMWriter::writeFunction(string name,int nLocals){
  line=0;
  dout << "function " << name << " " << nLocals <<" //"<< line << endl;
  fout << "function " << name << " " << nLocals <<" //"<< line++ << endl;
}
void VMWriter::writeReturn(){
  dout << "return" <<" //"<< line << endl;
  fout << "return" <<" //"<< line++ << endl;
}
void VMWriter::close(){

}
