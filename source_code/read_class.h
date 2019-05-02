#ifndef READ_CLASS_H
#define READ_CLASS_H
#include <string>
using namespace std;

class read{

private:
  string Qname;
  int flag;
  string Rname;
  int pos;
  int mapQ;
  string cigar;
  string Rnext;
  int Pnext;
  int len;
  string seq;
  string quality;
  int dir;

public:
  read(int dir=0,string Qname="*", int flag=0, string Rname="*", int pos=0, , int mapQ=255, string cigar="-", string Rnext="*", int Pnext=0, int len=0, string seq="*", string quality="*");

  void setQname(string);
  void setRname(string);
  void setFlag(int);
  void setPos(int);
  void setMapQ(int);
  void setLen(int);
  void setDir(int);

  string getQname();
  string getRname();
  int getFlag();
  int getPos();
  int getMapQ();
  int getLen();
  int getDir();

  string printRead();

};

#endif
