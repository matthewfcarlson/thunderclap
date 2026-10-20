#include "compat/ptr.h"
extern "C" char DAT_0042ebb0[];
class LocatorLoader {
  public:
    hulk_intptr vptr;
    int a;
    int b;
    int c;
    int d;
    LocatorLoader();
};
LocatorLoader::LocatorLoader() {
    a = 0;
    b = 0x14000;
    c = 0;
    d = 0;
    vptr = ((hulk_intptr)DAT_0042ebb0);
}