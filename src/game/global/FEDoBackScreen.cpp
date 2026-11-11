// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e1d20..0x000e1d70 (kind game, layer game, confidence medium), dominant class FEDoBackScreen
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_febb50d8 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_febb50d8 {} using namespace fn_febb50d8;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_febb50d8 {
class FEDoAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    char pad[0x10 - 4];
    struct Holder {
        int x;
        void* ptr;
    }* member;
};
class Related_e1d20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
};
class FEDoBackScreen : public FEDoAction {
  public:
    char pad2[0x34 - 0x14];
    unsigned char a;
    unsigned char b;
    void vfunc_1();
};


// 0x000e1d20 FEDoBackScreen::vfunc_1 (39 B): matches/0x000e1d20.cpp
// sym: ?vfunc_1@FEDoBackScreen@fn_febb50d8@@QAEXXZ
void FEDoBackScreen::vfunc_1() {
    if (a) {
        member->ptr;
        ((Related_e1d20*)member->ptr)->f23();
        return;
    }
    if (b) {
        ((Related_e1d20*)member->ptr)->f22();
        return;
    }
    ((Related_e1d20*)member->ptr)->f21();
}

} // namespace fn_febb50d8
