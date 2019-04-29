#ifndef READ_CLASS_H
#define READ_CLASS_H

class read{

private:
  string Qname;
  string Rname;
  int pos;
  int mapQ;
  int len;

public:
  read(string, string, int, int, int);

  void setQname(string);
  void setRname(string);
  void setPos(int);
  void setMapQ(int);
  void setLen(int);

  string getQname();
  string getRname();
  int getPos();
  int getMapQ();
  int getLen();


};

#endif
