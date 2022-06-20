#include <string>
#include <unordered_map>
#include "VMcomType.h"
using namespace std;

class Parser{
  istream &is;
  bool eof=false;
  unordered_map<string,VMcomType>m;
 public:
  string m_inst,m_arg1,m_command;
  VMcomType m_VMcomType;
  int m_arg2;
  Parser(istream &inputStream);
  virtual ~Parser();
  bool hasMoreCommands();
  void advance();
  enum VMcomType commandType();
  string arg1();
  int arg2();
};
