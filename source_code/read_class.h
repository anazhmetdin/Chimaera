#ifndef READ_CLASS_H
#define READ_CLASS_H
#include <string>
using namespace std;

class read{

private:
  string Qname;
  string Rname;
  int flag;
  int pos;
  int mapQ;
  int len;
  int dir;

public:
  read(int dir=0,string Qname="*", string Rname="*", int flag=0, int pos=0, int len=0, int mapQ=255);

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
