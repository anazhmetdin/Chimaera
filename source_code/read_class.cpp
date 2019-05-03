#include <iostream>
#include "read_class.h"

using namespace std;

read::read(int dir,string Qname, int flag, string Rname, int pos, int mapQ, string cigar, string Rnext, int Pnext, int len, string seq, string quality, string tag){
  this->dir = dir;
  this->Qname = Qname;
  this->flag = flag;
  this->Rname = Rname;
  this->pos = pos;
  this->mapQ = mapQ;
  this->cigar = cigar;
  this->Rnext = Rnext;
  this->Pnext = Pnext;
  this->len = len;
  this->seq = seq;
  this->quality = quality;
  this->tag;
}

void read::setQname(string Qname){this->Qname = Qname;}

void read::setFlag(int flag){this->flag = flag;}

void read::setRname(string Rname){this->Rname = Rname;}

void read::setPos(int pos){this->pos = pos;}

void read::setMapQ(int mapQ){this->mapQ = mapQ;}

void read::setCigar(string cigar){this->cigar = cigar;}

void read::setRnext(string Rnext){this->Rnext = Rnext;}

void read::setPnext(int Pnext){this->Pnext = Pnext;}

void read::setLen(int len){this->len = len;}

void read::setSeq(string seq){this->seq = seq;}

void read::setQuality(string quality){this->quality = quality;}

void read::setDir(int dir){this->dir = dir;}

void read::setTag(string tag){this->tag = tag;}


string read::getQname(){return Qname;}

int read::getFlag(){return flag;}

string read::getRname(){return Rname;}

int read::getPos(){return pos;}

int read::getMapQ(){return mapQ;}

string read::getCigar(){return cigar;}

string read::getRnext(){return Rnext;}

int read::getPnext(){return Pnext;}

int read::getLen(){return len;}

string read::getSeq(){return seq;}

string read::getQuality(){return quality;}

int read::getDir(){return dir;}

string read::getTag(){return tag;}

string read::printRead(){
  return this->Qname + "\t" + to_string(this->flag) + "\t" + this->Rname + "\t" + to_string(this->pos) + "\t" + to_string(this->mapQ) + "\t" + this->cigar + "\t" + this->Rname + "\t" + this->Rnext + "\t" + to_string(this->Pnext) + "\t" + to_string(this->len) + "\t" + this->seq + "\t" + this->quality + "\t" + this->tag + "\n";
}
