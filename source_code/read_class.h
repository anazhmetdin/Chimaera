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
  string tag;
  int dir;

public:
  read(int dir=0,string Qname="*", int flag=0, string Rname="*", int pos=0, int mapQ=255, string cigar="-", string Rnext="*", int Pnext=0, int len=0, string seq="*", string quality="*", string tag="");

  void setQname(string Qname);
  void setFlag(int flag);
  void setRname(string Rname);
  void setPos(int pos);
  void setMapQ(int mapQ);
  void setCigar(string cigar);
  void setRnext(string Rnext);
  void setPnext(int Pnext);
  void setLen(int len);
  void setSeq(string seq);
  void setQuality(string quality);
  void setDir(int dir);
  void setTag(string tag);

  string getQname();
  int getFlag();
  string getRname();
  int getPos();
  int getMapQ();
  string getCigar();
  string getRnext();
  int getPnext();
  int getLen();
  string getSeq();
  string getQuality();
  int getDir();
  string getTag();

  string printRead();

};

#endif
