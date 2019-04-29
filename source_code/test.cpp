#include <iostream>
#include <fstream>
#include <string>
#include "read_class.h"
using namespace std;

int main(){

/*
basic method to create output, write, file
*/
fstream test_file;

test_file.open("test.txt",ios::out);
test_file << "This is a line.\n";

test_file.close();


/*
auto method to create output, append, file
*/
ofstream test_file2("test.txt",ios::app);

if (test_file2.is_open()) {
  test_file2 << "This is a line.\n";
  test_file2 << "This is another line.\n";

  test_file2.close();
}


/*
auto method to create input, read, file
store each line in string line
cerr: cout error
*/
ifstream test_file3("test.txt", ios::in);

if (test_file3.is_open()) {
  string line;
  while (getline(test_file3, line)) {
    cout << line << '\n';
  }
  test_file3.close();
}
else {
  std::cerr << "Unable to open file\n";
}


/*
Testing read_class
*/
read readt;
cout<<readt.getLen()<<endl;

readt.setLen(21);
cout<<readt.getLen()<<endl;
  return 0;
}
