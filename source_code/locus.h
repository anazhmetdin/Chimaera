#ifndef LOCUS_H
#define LOCUS_H
#include <string.h>
#include "linked.h"
using namespace std;

class locus{

public:
  locus(Node* first, Node* second);
  int first_start;
  int first_end;
  string first_Rname;
  int second_start;
  int second_end;
  string second_Rname;
  linked* supporting_reads;

};

#endif
