#include <iostream>
#include <string>
#include <fstream>
#include "read_class.h"
#include "table.h"
using namespace std;


read store_read(string line);


int main(int argc, char** argv){
  //a table that would store all the reads in the inputfile
  //where each group of similar reads would be grouped to one set
  table file_table;
  //initiating opject to stream from the input file
  ifstream test_file(argv[1], ios::in);

  if (test_file.is_open()) {

    string line;
    //loop over each line and store its fields in one object
    while (getline(test_file, line)) {

        read line_read = store_read(line);
        //store each read in the file_table
        //if it does exist alread:
        //  -add the read the old set of similar Qnamea
        //if the read has a new Qname:
        //  -add it to a new set
        file_table.hashF(line_read);
      }

    test_file.close();
  }

  else {
    cerr << "Unable to open file\n";
  }
  //loop over each two reads in the table
  //where each read is considered as on destinctive locus
  //then, loop over the rest of reads to cheack if:
  // -the read has the same direction as any of the basis loci
  // -the read is adjacent, under the input limit, to the locus in question
  //and update the start and the end of the new locus
  file_table.check_support();
  //output a file the result of the previous check_support()
  //the template goes like this:
  /*
  @$num_supp_reads	$1st_start-$1st_end	$2nd_start-$2nd_end
  >>$first_locus_refrence_name $direction
  >>$second_locus_refrence_name $direction
  $supporting_read_1st_refrence_line
  $supporting_read_2nd_refrence_line
  $supporting_read_1st_refrence_line
  $supporting_read_2nd_refrence_line
  */
  file_table.report_support();

  return 0;
}



//loop over each field in the line
//store each field as a prameter of one read_class
read store_read(string line){
  string delimiter = "\t";
  string token;
  int pos;

  read dump_read;
  int field_counter = 0;

  while ((pos = line.find(delimiter)) != -1) {
      token = line.substr(0, pos);

      if(field_counter==0){
        dump_read.setDir(stoi(token));
      }
      else if(field_counter==1){
        dump_read.setQname(token);
      }
      else if(field_counter==2){
        dump_read.setFlag(stoi(token));
      }
      else if(field_counter==3){
        dump_read.setRname(token);
      }
      else if(field_counter==4){
        dump_read.setPos(stoi(token));
      }
      else if(field_counter==5){
        dump_read.setMapQ(stoi(token));
      }
      else if(field_counter==6){
        dump_read.setCigar(token);
      }
      else if(field_counter==7){
        dump_read.setRnext(token);
      }
      else if(field_counter==8){
        dump_read.setPnext(stoi(token));
      }
      else if(field_counter==9){
        dump_read.setLen(stoi(token));
      }
      else if(field_counter==10){
        dump_read.setSeq(token);
      }
      else if(field_counter==11){
        dump_read.setQuality(token);
        line.erase(0, pos + delimiter.length());
        dump_read.setTag(line);
      }

      line.erase(0, pos + delimiter.length());
      field_counter++;
  }
  return dump_read;
}
