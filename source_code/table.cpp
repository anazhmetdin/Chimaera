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

  if(sup_reads[ind] == nullptr){
     sup_reads[ind] = new linked*[num_rep_reads];
     sup_reads[ind][0] = new linked(r_instance);
   }
   else{
     add_read(r_instance,ind,num_rep_reads)
   }

  return;
}

void table::add_read(read r_instance, int ind, int num_rep_reads){

  string Qname_str = r_instance.getQname();
  const char* Qname = Qname_str.c_str();

  for(int i=0; i<num_rep_reads; i++){
    if(sup_reads[ind][i]==nullptr){
      sup_reads[ind][i] = new linked(r_instance);
    }
  }

  return;
}
