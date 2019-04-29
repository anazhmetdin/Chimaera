#include <iostream>
#include <string>
#include <fstream>
#include "hashT.h"
#include "read_class.h"
using namespace std;

int main(int argc, char** argv){

ifstream test_file(argv[1], ios::in);

if (test_file.is_open()) {

  string delimiter = "\t";
  string token,line;
  int pos;

  while (getline(test_file, line)) {

    read dump_read;
    int field_counter = 0;

    while ((pos = line.find(delimiter)) != -1) {
        token = line.substr(0, pos);

        if(field_counter==0){
          dump_read.setQname(token);
        }
        if(field_counter==1){
          dump_read.setFlag(stoi(token));
        }
        if(field_counter==2){
          dump_read.setRname(token);
        }
        if(field_counter==3){
          dump_read.setPos(stoi(token));
        }
        if(field_counter==4){
          dump_read.setMapQ(stoi(token));
        }
        if(field_counter==8){
          dump_read.setMapQ(stoi(token));
          break;
        }

        line.erase(0, pos + delimiter.length());
        field_counter++;
    }

    cout<< dump_read.getLen() << endl;
    cout<< dump_read.getPos() << endl;
    cout<< dump_read.getFlag() << endl;
    cout<< dump_read.getMapQ() << endl;
    cout<< dump_read.getLen() << endl;
    cout<< dump_read.getQname() << endl;
    cout<< dump_read.getRname() << endl;

  }

  test_file.close();
}

else {
  std::cerr << "Unable to open file\n";
}

  return 0;
}
