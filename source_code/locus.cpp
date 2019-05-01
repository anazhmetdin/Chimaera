#include "locus.h"
#include <iostream>

using namespace std;

locus::locus(Node* first, Node* second){

  first_start = first->data.getPos();
  first_end = first_start+first->data.getLen();
  first_Rname = first->data.getRname();

  second_start = second->data.getPos();;
  second_end = second_start+second->data.getLen();
  second_Rname = first->data.getRname();

  supporting_reads = new linked(first->data);
  supporting_reads->addToTail(second->data);

}
