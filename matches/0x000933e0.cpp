#include "compat/ptr.h"
extern "C" char DAT_0040449c[];
extern "C" char DAT_004044a4[];
extern "C" void Free1(void* p);
extern "C" void Free2(void* p);

class Helper_933e0 {
  public:
    void F();
};

class CUnlockableBlonskyFile {
  public:
    void* vfunc_0(unsigned char f);
};

void* CUnlockableBlonskyFile::vfunc_0(unsigned char f) {
    char* s = (char*)this;
    *(hulk_intptr*)s = ((hulk_intptr)DAT_004044a4);
    ((Helper_933e0*)(s + 0x20))->F();
    void* p = *(void**)(s + 0x18);
    *(hulk_intptr*)s = ((hulk_intptr)DAT_0040449c);
    if (p) {
        Free1(p);
        *(void**)(s + 0x18) = 0;
    }
    ((Helper_933e0*)(s + 0x10))->F();
    if (f & 1)
        Free2(s);
    return this;
}
