#include <iostream>
#include "read_class.h"

using namespace std;

read::read(string Qname="*", string Rname="*", int pos=0, int len=0int, mapQ=255,){
  this->Qname = Qname;
  this->Rname = Rname;
  this->pos = pos;
  this->len = len;
  this->mapQ = mapQ;
}

void read::setQname(string Qname){this->Qname = Qname;}

void read::setRname(string Rname){this->Rname = Rname;}

void read::setPos(int pos){this->pos = pos;}

void read::setMapQ(int mapQ){this->mapQ = mapQ;}

void read::setLen(int len){this->len = len;}


string read::getQname(){return Qname;}

string read::getRname(){return Rname;}

int read::getPos(){return pos;}

int read::getMapQ(){return mapQ;}

int read::getLen(){return len;}
