#include "compat/ptr.h"
extern "C" char DAT_0042d4d4[];
class CompositeDrawableLoader {
  public:
    hulk_intptr a;
    int b;
    int c;
    int d;
    int e;
    CompositeDrawableLoader();
};
CompositeDrawableLoader::CompositeDrawableLoader() {
    b = 0;
    c = 0x123000;
    d = 0;
    e = 0;
    a = ((hulk_intptr)DAT_0042d4d4);
}