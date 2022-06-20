#include <string>
#include <unordered_map>
using namespace std;
class SymbolTable{
  unordered_map<string,int>m;
 public:
  SymbolTable();
  void addEntry(string symbol,int address);
  bool contains(string symbol);
  int getAddress(string symbol);
  void print();
};
