// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000afd00..0x000afdf0 (kind game, layer game, confidence medium), dominant class CHapticController
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fbbf50ac {
#define TREE_TU_END }
namespace fn_fbbf50ac {} using namespace fn_fbbf50ac;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fbbf50ac {
extern void* hulk_at_00405e74[];
extern void* hulk_at_003f6098[];
} // namespace fn_fbbf50ac
void operator delete[](void*);
namespace fn_fbbf50ac {
class Ref_afd00 {
  public:
    virtual void F0();
    virtual void Release();
};
struct P_afd00 {
    char pad[0x2c];
    Ref_afd00* r;
    void Fini() {
        if (r) {
            r->Release();
            r = 0;
        }
    }
};
class CHapticController_afd00 {
  public:
    void* vptr;
    char pad[8];
    Ref_afd00* mc;
    int count;
    P_afd00* arr;
    void f();
};


// 0x000afd00 FUN_000afd00 (164 B): matches/0x000afd00.cpp
// sym: ?f@CHapticController_afd00@fn_fbbf50ac@@QAEXXZ
void CHapticController_afd00::f() {
    vptr = hulk_at_00405e74;
    if (arr) {
        for (int i = 0; i < count; i++)
            if (arr[i].r) {
                arr[i].r->Release();
                arr[i].r = 0;
            }
        if (arr) {
            int n = ((int*)arr)[-1];
            void* blk = (int*)arr - 1;
            P_afd00* p = arr + n;
            while (--n >= 0) {
                --p;
                p->Fini();
            }
            operator delete[](blk);
            arr = 0;
        }
    }
    if (mc) {
        mc->Release();
        mc = 0;
    }
    vptr = hulk_at_003f6098;
}

} // namespace fn_fbbf50ac

// 0x000afdb0 CHapticController::vfunc_2 (30 B): matches/0x000afdb0.cpp
// sym: ?vfunc_2@CHapticController_afdb0@fn_000afdb0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `CHapticController::~CHapticController() {}` stood for it, which natively
// defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's
// body 0x000afd00, then (flags & 1) operator delete.
namespace fn_000afdb0 {
struct CHapticController_afdb0 {
    void FUN_000afd00();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* CHapticController_afdb0::vfunc_2(unsigned int flags) {
    FUN_000afd00();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000afdb0
// (x64t21) the destructor itself, which other objects' code references:
CHapticController::~CHapticController() {}

