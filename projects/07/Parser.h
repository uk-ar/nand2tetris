#include <string>
#include <unordered_map>
using namespace std;
enum comType {
  A_COMMAND,
  C_COMMAND,
  L_COMMAND
};

class Parser{
  istream &is;
  bool eof=false;
 public:
  string m_inst,m_symbol,m_dest,m_comp,m_jump;
  Parser(istream &inputStream);
  virtual ~Parser();
  bool hasMoreCommands();
  void advance();
  enum comType commandType();
  string symbol();
  string dest();
  string comp();
  string jump();
};
