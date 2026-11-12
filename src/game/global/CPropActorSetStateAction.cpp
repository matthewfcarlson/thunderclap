// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00022770..0x000228f0 (kind game, layer game, confidence medium), dominant class CPropActorSetStateAction
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f96a4a22 {
#define TREE_TU_END }
namespace fn_f96a4a22 {} using namespace fn_f96a4a22;
namespace fn_f96a4a22 { extern "C" char DAT_003f3d80[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
namespace fn_f96a4a22 { extern "C" char DAT_003f3de0[], DAT_003f3390[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f96a4a22 {
extern void* g_vftable_003f3d80[];
class Ref_22770 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22770 {
  public:
    void* vptr;
};
class CWallSlideAction_22770 : public CAction_22770 {
  public:
    char pad[0x18];
    Ref_22770* m2;
    char pad2[0x4];
    Ref_22770* m1;
    CWallSlideAction_22770* f2(unsigned char flags);
};
extern void* hulk_at_003f3390[];
class Ref_227d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_227d0 {
  public:
    void* vptr;
};
class CTargetAction_227d0 : public CAction_227d0 {
  public:
    char pad[0x1c - 4];
    Ref_227d0* m;
    CTargetAction_227d0* f2(unsigned char flags);
};
class Ref_22810 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22810 {
  public:
    void* vptr;
};
class CHeliDeathSpiralAction_22810 : public CAction_22810 {
  public:
    char pad[0x1c - 4];
    Ref_22810* m1c;
    char pad2[4];
    Ref_22810* m24;
    CHeliDeathSpiralAction_22810* f2(unsigned char flags);
};
extern void* g_vftable_22870[];
class Ref_22870 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22870 {
  public:
    void* vptr;
};
class CExplosionAction_22870 : public CAction_22870 {
  public:
    char pad[24];
    Ref_22870* m;
    CExplosionAction_22870* f2(unsigned char flags);
};
extern void* g_vftable_228b0[];
class Ref_228b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_228b0 {
  public:
    void* vptr;
};
class CPropActorSetStateAction_228b0 : public CAction_228b0 {
  public:
    char pad[0x1c - 4];
    Ref_228b0* m;
    CPropActorSetStateAction_228b0* f2(unsigned char flags);
};


// 0x00022770 CWallSlideAction::vfunc_2 (82 B): matches/0x00022770.cpp
// sym: ?f2@CWallSlideAction_22770@fn_f96a4a22@@QAEPAV12@E@Z
CWallSlideAction_22770* CWallSlideAction_22770::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3d80);
    _ReadWriteBarrier();
    if (m1) {
        m1->Release();
        m1 = 0;
    }
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m2) {
        m2->Release();
        m2 = 0;
    }
    ((fight::Action *)(CAction_22770 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x000227d0 CTargetAction::vfunc_2 (57 B): matches/0x000227d0.cpp
// sym: ?f2@CTargetAction_227d0@fn_f96a4a22@@QAEPAV12@E@Z
CTargetAction_227d0* CTargetAction_227d0::f2(unsigned char flags) {
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_227d0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00022810 CHeliDeathSpiralAction::vfunc_2 (82 B): matches/0x00022810.cpp
// sym: ?f2@CHeliDeathSpiralAction_22810@fn_f96a4a22@@QAEPAV12@E@Z
CHeliDeathSpiralAction_22810* CHeliDeathSpiralAction_22810::f2(unsigned char flags) {
    vptr = (void**)DAT_003f3de0;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = (void**)DAT_003f3390;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_22810 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00022870 CExplosionAction::vfunc_2 (57 B): matches/0x00022870.cpp
// sym: ?f2@CExplosionAction_22870@fn_f96a4a22@@QAEPAV12@E@Z
CExplosionAction_22870* CExplosionAction_22870::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22870 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x000228b0 CPropActorSetStateAction::vfunc_2 (57 B): matches/0x000228b0.cpp
// sym: ?f2@CPropActorSetStateAction_228b0@fn_f96a4a22@@QAEPAV12@E@Z
CPropActorSetStateAction_228b0* CPropActorSetStateAction_228b0::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_228b0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f96a4a22
