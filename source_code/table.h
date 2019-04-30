#ifndef TABLE_H
#define TABLE_H
#include <string.h>
#include "linked.h"
#include "read_class.h"
using namespace std;

class table{

private:
  int size;
  linked*** sup_reads;

public:
  table();
  void hashF(read r_instance, int num_rep_reads);
  void add_read(read r_instance);

};

#endif
