#include "table.h"
#include "hash_f.h"
#include <iostream>

using namespace std;

table::table(){
  size=MAX_HASH_VALUE;
  sup_reads = new linked*[size];
}


void table::hashF(read r_instance){

  string Qname_str = r_instance.getQname();
  const char* Qname = Qname_str.c_str();
  int Qlen = strlen(Qname);

  int ind = Perfect_Hash::hash(Qname,Qlen);

  if(sup_reads[ind] == nullptr){
     sup_reads[ind] = new linked(r_instance);
   }
   else{
     sup_reads[ind].addToTail(r_instance);
   }

  return;
}
