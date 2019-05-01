#ifndef TABLE_H
#define TABLE_H
#include <string.h>
#include "linked.h"
#include <vector>
#include "locus.h"
#include "read_class.h"
using namespace std;

class table{

private:
  int size;
  linked** sup_reads;

public:
  table();
  void hashF(read r_instance);
  bool found_matched(Node* first, Node* second);
  void check_support();
  vector<locus> loci;

};

#endif
