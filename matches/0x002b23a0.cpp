#include "compat/ptr.h"
extern "C" char DAT_0042e49c[];
class MultiControllerLoader {
  public:
    int a;
    int b;
    int c;
    int d;
    int e;
    MultiControllerLoader();
};
MultiControllerLoader::MultiControllerLoader() {
    b = 0;
    c = 0x121202;
    d = 0;
    e = 0;
    a = ((hulk_intptr)DAT_0042e49c);
}