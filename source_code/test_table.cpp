#include <iostream>
#include <fstream>
#include <string>
#include "table.h"
using namespace std;

int main(){

  read whtevr1;
  read whtevr2;
  read whtevr3;
  read whtevr4;

  whtevr1.setQname("HWI-EAS367:3:3:32:1913");
    whtevr1.setPos(33);
      whtevr1.setLen(40);
        whtevr1.setRname("chr_1");

        whtevr2.setQname("HWI-EAS367:3:3:32:1913");
          whtevr2.setPos(200);
            whtevr2.setLen(40);
              whtevr2.setRname("chr_1");

              whtevr3.setQname("HWI-EAS367:3:2:1291:1343");
                whtevr3.setPos(33);
                  whtevr3.setLen(40);
                    whtevr3.setRname("chr_1");

                    whtevr4.setQname("HWI-EAS367:3:2:1291:1343");
                      whtevr4.setPos(200);
                        whtevr4.setLen(40);
                          whtevr4.setRname("chr_1");

  table whtevrT;
  whtevrT.hashF(whtevr1);
  whtevrT.hashF(whtevr2);
  whtevrT.hashF(whtevr3);
  whtevrT.hashF(whtevr4);

  whtevrT.check_support();
  cout << whtevrT.loci.size() << '\n';
  for(int i=0; i<whtevrT.loci.size(); i++){
    cout<<whtevrT.loci[i].supporting_reads->head->next->data.getPos()<<endl;
  }

}
