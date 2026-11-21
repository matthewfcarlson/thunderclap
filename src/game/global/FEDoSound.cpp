// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e8a10..0x000e8ba0 (kind game, layer game, confidence medium), dominant class FEDoSound
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"   // (nat2, D134) FEAnimation's record
#define TREE_TU_BEGIN namespace fn_ffdab178 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ffdab178 {} using namespace fn_ffdab178;
void __cdecl operator delete[](void* p);   // (x64t21, D115) the game's 0x0008d340
namespace fn_ffdab178 { extern "C" char DAT_0040bfa0[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ffdab178 {
struct Ref_e8a10 {
    virtual void a();
    virtual void release();
};
// (nat2, D134) the animation's record (FEAnimation: the resource at +4 is a pointer, freed with operator delete[];
// the child at +0xc)
struct FETextureAnimation_e8a10 : ::FEAnimation {
    void cleanup();
};
class Ref_e8a70 {
  public:
    virtual void F0();
    virtual void Release();
};
class FEParticleSystem {
  public:
    char pad[0x28];
    Ref_e8a70* volatile mRef;
    void Cleanup();
};
struct Entry_e8a90 {
    int f0;
    const char* name;
};
class Table_e8a90 {
public:
    Entry_e8a90* FUN_000e1dd0(const char* key);
};
class FEContainer {
public:
    virtual void v0();
};
class SharedTables {
public:
    char pad0[0x2078];
    Table_e8a90 table;
};
class FEScreenBase : public FEContainer {
public:
    SharedTables* shared;
    char pad8[0x9dc - 8];
    Table_e8a90 localTable;
};
class FEDoAnimation {
public:
    FEDoAnimation(FEContainer* container, const char* name);
    virtual void* v0_000e8b20(char);
    char pad4[4];
    int field8;
    int fieldC;
    FEContainer* container;
    char flag14;
    char pad15[0x34 - 0x15];
    Entry_e8a90* entry;
    int field38;
    int field3c;
    int field40;
    float field44;
    float field48;
    float field4c;
    char flag50;
};
class FEDoAction_e8b20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public FEDoAction_e8b20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}


// 0x000e8a10 FUN_000e8a10 (78 B): matches/0x000e8a10.cpp
// sym: ?cleanup@FETextureAnimation_e8a10@fn_ffdab178@@QAEXXZ
// Same code shape as 0x000e8980 (propagated; names are from that function)
void FETextureAnimation_e8a10::cleanup() {
    *(int**)this = &billboardVtable;
    Ref_e8a10* volatile* pc = (Ref_e8a10* volatile*)&f_0c;
    Ref_e8a10* c = *pc;
    if (c) {
        c->release();
        f_0c = 0;
    }
    *(int**)this = &animationVtable;
    c = *pc;
    if (c) {
        c->release();
        f_0c = 0;
    }
    if (f_04) {
        ::operator delete[](f_04);
        f_04 = 0;
    }
}


// 0x000e8a60 FETextureAnimation::vfunc_3 (1 B): matches/0x000e8a60.cpp
// sym: ?FUN_000e8a60@fn_ffdab178@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000e8a60() {}


// 0x000e8a70 FUN_000e8a70 (30 B): matches/0x000e8a70.cpp
// sym: ?Cleanup@FEParticleSystem@fn_ffdab178@@QAEXXZ
void FEParticleSystem::Cleanup() {
    *(volatile hulk_uintptr*)this = ((hulk_intptr)DAT_0040bfe0);
    Ref_e8a70* r = mRef;
    if (r) {
        r->Release();
        mRef = 0;
    }
}


// 0x000e8a90 FUN_000e8a90 (141 B): equivalent/0x000e8a90.cpp
// sym: ??0FEDoAnimation@fn_ffdab178@@QAE@PAVFEContainer@1@PBD@Z @1723beda844f @w73c76dd663ac @v87321b23ddb8
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000e8a90 @ 0x000e8a90
// FEDoAnimation constructor: reset the animation state and look the named entry up in the owning screen.
FEDoAnimation::FEDoAnimation(FEContainer* c, const char* name)
{
    field8 = -1;
    fieldC = -1;
    container = c;
    flag14 = 0;
    entry = 0;
    field38 = 0;
    field3c = 0;
    field40 = 0;
    field44 = -1.0f;
    field48 = -1.0f;
    field4c = 1.0f;
    flag50 = 1;

    FEScreenBase* screen = dynamic_cast<FEScreenBase*>(c);
    if (screen != 0) {
        Entry_e8a90* found = screen->localTable.FUN_000e1dd0(name);
        if (found == 0) {
            found = screen->shared->table.FUN_000e1dd0(name);
        }
        entry = found;
    }
}


// 0x000e8b20 FEDoAnimation::vfunc_0 (31 B): matches/0x000e8b20.cpp
// sym: ?f2@NonCopyable@pure3d@fn_ffdab178@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0040bfa0;
    if ((param & 1) != 0)
        ::operator delete(this);
    return this;
}

} // namespace fn_ffdab178

// 0x000e8b40 FEDoParticleSystem::vfunc_0 (31 B): matches/0x000e8b40.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000e8b40@@UAEPAV123@E@Z
namespace fn_000e8b40 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class FEDoAction_e8b40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_0040bfa0[];
namespace pure3d {
class NonCopyable : public FEDoAction_e8b40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_0040bfa0;
    if ((param & 1) != 0)
        ::operator delete(this);
    return this;
}
} // namespace fn_000e8b40


// 0x000e8b60 FEDoWait::vfunc_0 (31 B): matches/0x000e8b60.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000e8b60@@UAEPAV123@E@Z
namespace fn_000e8b60 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class FEDoAction_e8b60 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public FEDoAction_e8b60 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0040bfa0;
    if ((param & 1) != 0)
        ::operator delete(this);
    return this;
}
} // namespace fn_000e8b60


// 0x000e8b80 FEDoSound::vfunc_0 (31 B): matches/0x000e8b80.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000e8b80@@UAEPAV123@E@Z
namespace fn_000e8b80 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class FEDoAction_e8b80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public FEDoAction_e8b80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0040bfa0;
    if ((param & 1) != 0)
        ::operator delete(this);
    return this;
}
} // namespace fn_000e8b80

