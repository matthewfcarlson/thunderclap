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
extern void* g_a_afd00[];
extern void* g_b_afd00[];
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
    vptr = g_a_afd00;
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
    vptr = g_b_afd00;
}

} // namespace fn_fbbf50ac

// 0x000afdb0 CHapticController::vfunc_2 (30 B): matches/0x000afdb0.cpp
// sym: ??_GCHapticController@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CHapticController::~CHapticController() {}

