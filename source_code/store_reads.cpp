#include <iostream>
#include <string>
#include <fstream>
#include "hashT.h"
using namespace std;

int main(int argc, char** argv){

ifstream test_file(argv[1], ios::in);

if (test_file.is_open()) {
  string line;
  while (getline(test_file, line)) {
    cout << line << '\n';
  }
  test_file.close();
}
else {
  std::cerr << "Unable to open file\n";
}

  return 0;
}
