#include <string>
#include <unordered_map>
#include <iostream>
#include "VMWriter.h"

using namespace std;

VMWriter::VMWriter(ostream &outputStream):fout(outputStream){

}
static int line=0;
vector<string>seg({"constant","argument","local","static","this","that","pointer","temp"});
void VMWriter::writePush(Segment segment,int index){
  fout << "push " << seg[segment] << " " << index <<" //"<< line++ << endl;
}
void VMWriter::writePop(Segment segment,int index){
  fout << "pop " << seg[segment] << " " << index <<" //"<< line++ << endl;
}
vector<string>arith({"add","sub","neg","eq","gt","lt","and","or","not"});
void VMWriter::writeArithmetic(Command command){
  fout << arith[command] <<" //"<< line++ << endl;
}
void VMWriter::writeLabel(string label){
  fout << "label "+label <<" //"<< line++ << endl;
}
void VMWriter::writeGoto(string label){
  fout << "goto "+label <<" //"<< line++ << endl;
}
void VMWriter::writeIf(string label){
  fout << "if-goto "+label <<" //"<< line++ << endl;
}
void VMWriter::writeCall(string name,int nArgs){
  fout << "call " << name << " " << nArgs <<" //"<< line++ << endl;
}
void VMWriter::writeFunction(string name,int nLocals){
  fout << "function " << name << " " << nLocals <<" //"<< line++ << endl;
}
void VMWriter::writeReturn(){
  fout << "return" <<" //"<< line++ << endl;
}
void VMWriter::close(){

}
