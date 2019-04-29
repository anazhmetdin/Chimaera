#include <iostream>
#include <string>
#include <fstream>
#include "hashT.h"
using namespace std;

int main(int argc, char** argv){

ifstream test_file(argv[1], ios::in);

if (test_file.is_open()) {

  string delimiter = "\t";
  string token,line;
  int pos;
  while (getline(test_file, line)) {

    while ((pos = line.find(delimiter)) != -1) {
        token = line.substr(0, pos);
        cout << token << endl;
        line.erase(0, pos + delimiter.length());
    }
    cout << line << endl;
  }

  test_file.close();
}

else {
  std::cerr << "Unable to open file\n";
}

  return 0;
}
