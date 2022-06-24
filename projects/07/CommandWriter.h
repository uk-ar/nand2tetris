#include <string>
#include <unordered_map>
#include "VMcomType.h"
using namespace std;

class CommandWriter{
  ostream &os;
  string fileName;
 public:
  CommandWriter(ostream &outputStream);
  void setFileName(string fileName);
  void writeArithmetic(string command);
  void writePushPop(VMcomType command,string segment,int index);
  void close();
};
