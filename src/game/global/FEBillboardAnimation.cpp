// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f10c0..0x000f11f0 (kind game, layer game, confidence medium), dominant class FEBillboardAnimation
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f40d35a2 {
#define TREE_TU_END }
namespace fn_f40d35a2 {} using namespace fn_f40d35a2;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f40d35a2 {
extern void* FEControl_f10c0_vftable[];
class FEControl_f10c0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class TextButton_f10c0 : public FEControl_f10c0 {
  public:
    TextButton_f10c0* vfunc_5(signed char flags);
};
extern void* FEObject_f1130_vftable[];
class FEObject_f1130 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class TextLabel_f1130 : public FEObject_f1130 {
  public:
    TextLabel_f1130* vfunc_5(signed char flags);
};


// 0x000f10c0 TextButton::vfunc_2 (36 B): matches/0x000f10c0.cpp
// sym: ?vfunc_5@TextButton_f10c0@fn_f40d35a2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TextButton_f10c0* TextButton_f10c0::vfunc_5(signed char flags) {
    *(void***)this = FEControl_f10c0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x000f1130 TextLabel::vfunc_2 (36 B): matches/0x000f1130.cpp
// sym: ?vfunc_5@TextLabel_f1130@fn_f40d35a2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TextLabel_f1130* TextLabel_f1130::vfunc_5(signed char flags) {
    *(void***)this = FEObject_f1130_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f40d35a2

// 0x000f1160 FEAnimation::vfunc_0 (73 B): matches/0x000f1160.cpp [wrapped: conflict: FEAnimation]
// sym: ?vfunc_0@FEAnimation@fn_000f1160@@UAEPAV12@E@Z
namespace fn_000f1160 {
extern "C" void _ReadWriteBarrier();
struct RelObj_f1160 {
  public:
    virtual void A();
    virtual void Release();
};
extern "C++" __declspec(nothrow) void __cdecl freeA(void*);
extern "C++" __declspec(nothrow) void __cdecl freeB(void*);
extern void* FEAnimation_vftable;

class FEAnimation {
  public:
    virtual FEAnimation* vfunc_0(unsigned char param);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    void* mPtr;
    char pad[4];
    RelObj_f1160* mRel;
};

FEAnimation* FEAnimation::vfunc_0(unsigned char param) {
    *(void**)this = &FEAnimation_vftable;
    _ReadWriteBarrier();
    if (mRel != 0) {
        mRel->Release();
        mRel = 0;
    }
    if (mPtr != 0) {
        freeA(mPtr);
        mPtr = 0;
    }
    if (param & 1) {
        freeB(this);
    }
    return this;
}
} // namespace fn_000f1160


// 0x000f11b0 FEPoseAnimation::vfunc_0 (30 B): matches/0x000f11b0.cpp
// sym: ??_GFEPoseAnimation@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
FEPoseAnimation::~FEPoseAnimation() {}


// 0x000f11d0 FEBillboardAnimation::vfunc_0 (30 B): matches/0x000f11d0.cpp
// sym: ??_GFEBillboardAnimation@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
FEBillboardAnimation::~FEBillboardAnimation() {}

