// Same code shape as 0x0012a410 (propagated; names are from that function)
#include "compat/ptr.h"
extern "C" void* __cdecl alloc(unsigned int);
extern int tdcVtable;
class TDC_12aa30 {
  public:
    int vf;
    char pad[8];
    int x;
    int y;
    unsigned char a;
    unsigned char b;
    void init(int);
};
TDC_12aa30* __cdecl target() {
    TDC_12aa30* p = (TDC_12aa30*)alloc(0x18);
    int z = 0;
    if (p) {
        p->init(z);
        p->x = z;
        p->y = z;
        p->a = (unsigned char)z;
        p->b = (unsigned char)z;
        p->vf = (hulk_intptr)&tdcVtable;
        return p;
    }
    return 0;
}
