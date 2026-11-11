// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00337630 FUN_00337630 (67 B): matches/0x00337630.cpp [isolated: lost its match in the tree (codegen differs (20 of 34 instructions))]
// sym: ?Destroy@Big_337630@fn_f0833c1b@@QAEXXZ
#include "gen/owners.h"
#include "decls/data/engine/movie.h"
namespace fn_f0833c1b {} using namespace fn_f0833c1b;
namespace fn_f0833c1b {
// data: gVtbl = DAT_00434574

struct PtrObj {
  public:
    virtual void f(int);
};

struct Elem_337630 {
    char data[0x288];
};

class Big_337630 {
  public:
    void Destroy();

  private:
    const void* slot0;
    char pad0[4];
    Elem_337630 mArray[32];
    int field5108;
    PtrObj* mPtr;
};

void Big_337630::Destroy() {
    slot0 = ((const void**)&DAT_00434574);
    PtrObj* p = mPtr;
    if (p) {
        p->f(1);
    }
    Elem_337630* q = &mArray[32];
    for (int i = 0x20; i != 0; --i) {
        q -= 1;
        ((owners::Obj_3371e0 *)q)->FUN_003371e0();
    }
}
} // namespace fn_f0833c1b

