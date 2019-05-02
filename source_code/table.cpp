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
     sup_reads[ind]->addToTail(r_instance);
   }

  return;
}

bool table::found_matched(Node* first, Node* second){

  if(loci.empty()){
    return false;
  }

  Node* searching_back;
  Node* searching_front;
  for(int i=0; i<loci.size(); i++){
    searching_back = loci[i].supporting_reads->head;
    searching_front = searching_back->next;
    while (searching_front!=NULL) {
      if(searching_back == first){
        if(searching_front == second){
          return true;
        }
      }
      if(searching_front == first){
        if(searching_back == second){
          return true;
        }
        if(searching_front->next == second){
          return true;
        }
      }
      searching_back = searching_back->next;
      searching_front = searching_front->next;
    }
  }
  return false;
}

void table::check_support(){

  Node* first;
  Node* second;
  locus* match;

  for(int i=0; i<size-1; i++){

    if(sup_reads[i]==nullptr){continue;}

    first = sup_reads[i]->head;

    while(first != sup_reads[i]->tail){

    second = first->next;

      while(second != NULL){

        if( found_matched(first,second) ){
          second = second->next;
          continue;
        }

        match = new locus(first,second);

        for(int j=i+1; j<size; j++){

          if(sup_reads[j]==nullptr){continue;}

          Node* temp = sup_reads[j]->head;
          Node* match_first = nullptr;
          Node* match_second = nullptr;

          while(temp != NULL){

            if( temp->data.getRname() == match->first_Rname && match_first == nullptr){

              if( temp->data.getPos() <=  match->first_end - 20 && temp->data.getPos() + temp->data.getLen() > match->first_end ){
                match_first = temp;
                temp = temp->next;
                continue;
              }
              else if( temp->data.getPos() >= match->first_start && temp->data.getPos() + temp->data.getLen() <= match->first_end && temp->data.getLen() >= 21){
                match_first = temp;
                temp = temp->next;
                continue;
              }
              else if( temp->data.getPos() < match->first_start && temp->data.getPos() + temp->data.getLen() > match->first_start + 20){
                match_first = temp;
                temp = temp->next;
                continue;
              }
              else if( temp->data.getPos() < match->first_start && temp->data.getPos() + temp->data.getLen() > match->first_end && match->first_end - match->first_start >= 20){
                match_first = temp;
                temp = temp->next;
                continue;
              }

            }

            else if( temp->data.getRname() == match->second_Rname && match_second == nullptr){
              if( temp->data.getPos() <=  match->second_end - 20 && temp->data.getPos() + temp->data.getLen() > match->second_end ){
                match_second = temp;
                temp = temp->next;
                continue;
              }
              else if( temp->data.getPos() >= match->second_start && temp->data.getPos() + temp->data.getLen() <= match->second_end && temp->data.getLen() >= 21){
                match_second = temp;
                temp = temp->next;
                continue;
              }
              else if( temp->data.getPos() < match->second_start && temp->data.getPos() + temp->data.getLen() > match->second_start + 20){
                match_second = temp;
                temp = temp->next;
                continue;
              }
              else if( temp->data.getPos() < match->second_start && temp->data.getPos() + temp->data.getLen() > match->second_end && match->second_end - match->second_start >= 20){
                match_second = temp;
                temp = temp->next;
                continue;
              }
            }
            temp = temp->next;
            }

            if(match_first != nullptr && match_second != nullptr){
              match->supporting_reads->addToTail(match_first->data);
              match->supporting_reads->addToTail(match_second->data);
            }
        }
        loci.push_back(*match);
        second = second->next;
      }
      first = first->next;
    }
  }
}
