#include "compat/ptr.h"
extern "C" char DAT_0042cca0[];
class StatePropDataLoader {
  public:
    StatePropDataLoader();
    hulk_intptr vptr;
    int a;
    int b;
    int c;
    int d;
};
StatePropDataLoader::StatePropDataLoader() {
    a = 0;
    b = 0x802000a;
    c = 0;
    d = 0;
    vptr = ((hulk_intptr)DAT_0042cca0);
}