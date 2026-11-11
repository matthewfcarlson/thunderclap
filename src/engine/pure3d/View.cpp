// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00294a10..0x00294b00 (kind game, layer engine, confidence medium), dominant class pure3d::View
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f58bed2c {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f58bed2c {} using namespace fn_f58bed2c;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f58bed2c {
extern int hulk_at_0042d0bc, hulk_at_003f6098;
class IRefCount {
  public:
    virtual void A();
    virtual void Release();
};
class View {
  public:
    char* v;
    char pad[0x14];
    IRefCount* mRef;
    char pad2[0x20];
    IRefCount* arr[32];
    void Cleanup();
};


// 0x00294a10 FUN_00294a10 (65 B): matches/0x00294a10.cpp
// sym: ?Cleanup@View@fn_f58bed2c@@QAEXXZ
void View::Cleanup() {
    ((hulk_intptr*)this)[0] = (hulk_intptr)&hulk_at_0042d0bc;
    if (mRef)
        mRef->Release();
    for (int i = 0; i < 32; i++) {
        if (arr[i]) {
            arr[i]->Release();
            arr[i] = 0;
        }
    }
    ((hulk_intptr*)this)[0] = (hulk_intptr)&hulk_at_003f6098;
}

} // namespace fn_f58bed2c

// 0x00294a60 pure3d::View::vfunc_2 (30 B): matches/0x00294a60.cpp
// sym: ??_GView@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::View::~View() {}

