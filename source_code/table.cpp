#include "table.h"
#include "hash_f.h"
#include <iostream>

using namespace std;

table::table(){
  size=MAX_HASH_VALUE;
  sup_reads = new linked**[size];
}


void table::hashF(read r_instance, int num_rep_reads){

  string Qname_str = r_instance.getQname();
  const char* Qname = Qname_str.c_str();
  int Qlen = strlen(Qname);

  int ind = Perfect_Hash::hash(Qname,Qlen);

  sup_reads[ind] = new linked*[num_rep_reads];

  sup_reads[ind][0] = new linked(r_instance);

  return;
}

void table::add_read(read r_instance){

  string Qname_str = r_instance.getQname();
  const char* Qname = Qname_str.c_str();
  int Qlen = strlen(Qname);

  int ind = Perfect_Hash::hash(Qname,Qlen);

  sup_reads[ind][0] = new linked(r_instance);

  return;
}
