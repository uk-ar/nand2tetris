#include <string>
#include <unordered_map>
using namespace std;

class Code{
  unordered_map<string,string>dm,cm,jm;
 public:
  Code();
  string dest(string a);
  string comp(string a);
  string jump(string a);
};
