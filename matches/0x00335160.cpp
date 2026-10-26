#include "decls/data/engine/core.h"

typedef unsigned char u8_335160;
extern char refvt_335160, basevt;
void __cdecl cleanup(int, void*);
namespace movie { class BinkCallback {
  public:
    void* vptr;
    int m;
    void* refptr;
    BinkCallback* vfunc_0(u8_335160 flag);
}; }
movie::BinkCallback* movie::BinkCallback::vfunc_0(u8_335160 flag) {
    movie::BinkCallback* p = this;
    if (p)
        p = (movie::BinkCallback*)((char*)p + 8);
    else
        p = (movie::BinkCallback*)0;
    p->vptr = &refvt_335160;
    DAT_004cdbb0 = m;
    vptr = &basevt;
    if (flag & 1)
        cleanup(DAT_004cdbb0, this);
    return this;
}