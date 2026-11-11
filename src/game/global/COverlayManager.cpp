// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000d6e00..0x000d6f00 (kind game, layer game, confidence medium), dominant class COverlayManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fc6a9358 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc6a9358 {} using namespace fn_fc6a9358;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc6a9358 {
class Item_d6e00 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
class Owner_d6e00 {
  public:
    char pad[12];
    Item_d6e00* items[8];
    void run(int);
};
extern "C" char DAT_0040b370[];
struct Ref_d6e30 {
    virtual void f0();
    virtual void Release();
};
class COverlayManager {
  public:
    virtual void v0();
    Ref_d6e30* a;
    char pad[0x24];
    Ref_d6e30* b;
    void clear();
};
extern void* g_vftable_d6e70[];
class Ref_d6e70 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class COverlayManager_d6e70 {
  public:
    void* vptr;
    Ref_d6e70* m4;
    char p8[0x24];
    Ref_d6e70* m2c;
    COverlayManager_d6e70* f2(unsigned char flags);
};


// 0x000d6e00 FUN_000d6e00 (42 B): matches/0x000d6e00.cpp
// sym: ?run@Owner_d6e00@fn_fc6a9358@@QAEXH@Z
void Owner_d6e00::run(int arg) {
    for (int i = 0; i < 8; ++i)
        if (items[i])
            items[i]->f5(arg);
}


// 0x000d6e30 FUN_000d6e30 (49 B): matches/0x000d6e30.cpp
// sym: ?clear@COverlayManager@fn_fc6a9358@@QAEXXZ
void COverlayManager::clear() {
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_0040b370);
    Ref_d6e30* x = *(Ref_d6e30* volatile*)&a;
    if (x) {
        x->Release();
        a = 0;
    }
    if (b) {
        b->Release();
        b = 0;
    }
}


// 0x000d6e70 COverlayManager::vfunc_0 (69 B): matches/0x000d6e70.cpp
// sym: ?f2@COverlayManager_d6e70@fn_fc6a9358@@QAEPAV12@E@Z
COverlayManager_d6e70* COverlayManager_d6e70::f2(unsigned char flags) {
    vptr = g_vftable_d6e70;
    _ReadWriteBarrier();
    if (m4) {
        m4->f1();
        m4 = 0;
    }
    if (m2c) {
        m2c->f1();
        m2c = 0;
    }
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fc6a9358
