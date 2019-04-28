#include <iostream>
#include <fstream>
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

  return 0;
}
