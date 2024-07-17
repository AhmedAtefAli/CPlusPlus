#include <iostream>
#include <list>
#include <vector>

const char *GetErrorMessage(int errorNo) { return "Empty"; }

// typedef const char *(*PFN)(int);
using PFN = const char *(*)(int);

void ShowError(PFN ptr) {}

// typedef std::vector<std::list<std::string>> Names;
template <typename T> using Names = std::vector<std::list<T>>;

int main() {

  Names<int> n;
  Names<std::string> names;
  PFN pfn = GetErrorMessage;
  ShowError(pfn);
  return 0;
}