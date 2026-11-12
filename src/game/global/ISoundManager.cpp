// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b4280..0x000b45a0 (kind game, layer game, confidence medium), dominant class ISoundManager
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fde9996c {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fde9996c {} using namespace fn_fde9996c;
namespace fn_fde9996c { extern "C" char DAT_004076ec[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fde9996c {
class A_b4280 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(void*, int);
};
class B_b4280 {
  public:
    char pad[0x10];
    A_b4280* p;
};
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x000b4280 FUN_000b4280 (27 B): matches/0x000b4280.cpp
// sym: ?target@fn_fde9996c@@YIXPAVB_b4280@1@PAX11@Z
void __fastcall target(B_b4280* self, void*, void* first, void* arg) {
    int x = arg ? *(int*)((char*)arg + 0x10) : 0;
    self->p->f5(first, x);
}


// 0x000b43e0 FUN_000b43e0 (7 B): matches/0x000b43e0.cpp
// sym: @FUN_000b43e0@4
extern "C" int __fastcall FUN_000b43e0(void* obj) {
    return *(int*)((char*)obj + 0x1cf0);
}


// 0x000b4410 ISoundManager::vfunc_0 (31 B): matches/0x000b4410.cpp
// sym: ?f2@NonCopyable@pure3d@fn_fde9996c@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_004076ec;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fde9996c
