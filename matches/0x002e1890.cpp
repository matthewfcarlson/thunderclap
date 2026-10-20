#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042fce4[];
extern "C" void __cdecl Release(void*);
class MatrixPaletteList {
  public:
    char pad[8];
    void* volatile p;
    void Destroy();
};
void MatrixPaletteList::Destroy() {
    *(volatile hulk_ulongptr*)this = ((hulk_intptr)DAT_0042fce4);
    void* q = p;
    if (q)
        Release(q);
    *(volatile hulk_ulongptr*)this = ((hulk_intptr)DAT_003f6098);
}