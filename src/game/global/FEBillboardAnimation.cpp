// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f10c0..0x000f11f0 (kind game, layer game, confidence medium), dominant class FEBillboardAnimation
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f40d35a2 {
#define TREE_TU_END }
namespace fn_f40d35a2 {} using namespace fn_f40d35a2;
namespace fn_f40d35a2 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f40d35a2 {
extern void* hulk_at_0040c42c[];
class FEControl_f10c0 {
  public:
    void Destroy_000e9030(); // FUN_00236d60, __thiscall, this in ecx
};
class TextButton_f10c0 : public FEControl_f10c0 {
  public:
    TextButton_f10c0* vfunc_5(signed char flags);
};
extern void* hulk_at_0040c61c[];
class FEObject_f1130 {
  public:
    void Destroy_000e9030(); // FUN_00236d60, __thiscall, this in ecx
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
    *(void***)this = hulk_at_0040c42c;
    Destroy_000e9030();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x000f1130 TextLabel::vfunc_2 (36 B): matches/0x000f1130.cpp
// sym: ?vfunc_5@TextLabel_f1130@fn_f40d35a2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TextLabel_f1130* TextLabel_f1130::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040c61c;
    Destroy_000e9030();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
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
extern "C++" __declspec(nothrow) void __cdecl freeA_0008d340(void*);
extern "C++" __declspec(nothrow) void __cdecl freeB_0008d330(void*);
extern void* hulk_at_0040bfc0;

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
    *(void**)this = &hulk_at_0040bfc0;
    _ReadWriteBarrier();
    if (mRel != 0) {
        mRel->Release();
        mRel = 0;
    }
    if (mPtr != 0) {
        freeA_0008d340(mPtr);
        mPtr = 0;
    }
    if (param & 1) {
        freeB_0008d330(this);
    }
    return this;
}
} // namespace fn_000f1160


// 0x000f11b0 FEPoseAnimation::vfunc_0 (30 B): matches/0x000f11b0.cpp
// sym: ?vfunc_0@FEPoseAnimation_f11b0@fn_000f11b0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `FEPoseAnimation::~FEPoseAnimation() {}` stood for it, which natively defines no
// function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's body
// 0x000e8730, then (flags & 1) operator delete.
namespace fn_000f11b0 {
struct FEPoseAnimation_f11b0 {
    void FUN_000e8730();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* FEPoseAnimation_f11b0::vfunc_0(unsigned int flags) {
    FUN_000e8730();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000f11b0
// (x64t21) the destructor itself, which other objects' code references:
FEPoseAnimation::~FEPoseAnimation() {}


// 0x000f11d0 FEBillboardAnimation::vfunc_0 (30 B): matches/0x000f11d0.cpp
// sym: ?vfunc_0@FEBillboardAnimation_f11d0@fn_000f11d0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `FEBillboardAnimation::~FEBillboardAnimation() {}` stood for it, which natively
// defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's
// body 0x000e8980, then (flags & 1) operator delete.
namespace fn_000f11d0 {
struct FEBillboardAnimation_f11d0 {
    void FUN_000e8980();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* FEBillboardAnimation_f11d0::vfunc_0(unsigned int flags) {
    FUN_000e8980();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000f11d0
// (x64t21) the destructor itself, which other objects' code references:
FEBillboardAnimation::~FEBillboardAnimation() {}

