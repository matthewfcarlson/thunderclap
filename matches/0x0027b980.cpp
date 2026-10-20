#include "compat/ptr.h"
extern "C" char DAT_0042c1cc[];
class SkeletonLoader {
  public:
    void* vf;
    int a;
    int b;
    int c;
    int d;
    unsigned char e;
    SkeletonLoader();
};
SkeletonLoader::SkeletonLoader() {
    a = 0;
    b = 0x23000;
    c = 0;
    d = 0;
    vf = (void*)((hulk_intptr)DAT_0042c1cc);
    e = 1;
}