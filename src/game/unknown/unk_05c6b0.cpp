// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005c6b0..0x0005d190 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f35d11f7 {
#define TREE_TU_END }
namespace fn_f35d11f7 {} using namespace fn_f35d11f7;
#include "game/unknown.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f35d11f7 {
extern "C" void* FUN_0008d690(unsigned int size);
class CGrappleLocoStrafe4Track_5c6b0 {
public:
    void FUN_0005a0d0();
    void FUN_0005a0e0();
    void FUN_00012900();
    void FUN_00012910();
    void FUN_00012920();
    void FUN_00012930();
    void FUN_00012940();
    void FUN_00012950();
    void FUN_00012960();
    void FUN_00012970();
    void FUN_00012980();
    void FUN_00012990();
    void FUN_000129a0();
    void FUN_0005a0f0();
    void FUN_0005a100();
    void FUN_0005a110();
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_f35d11f7
namespace fight {
template <class T>
class ParamFloatConstRange_5c6b0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_5c6b0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_5c6b0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_5c6b0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_5c6b0 : public ParamNameBase {
public:
    ParamName_5c6b0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f35d11f7 {
extern ParamRegistry hulk_at_004dc590;
extern int hulk_at_004dc594;
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class CGrappleAttachTrack_5ca20 {
public:
    void FUN_0005a120();
    void FUN_000129e0();
    void FUN_000129f0();
    void FUN_0005a130();
    void FUN_0005a140();
    void FUN_0005a160();
    void FUN_0005a180();
    void FUN_00012a60();
    void FUN_0005a1b0();
    void FUN_0005a1d0();
    void FUN_0005a1e0();
    void FUN_0005a1f0();
    void FUN_0005a200();
    void FUN_0005a210();
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f35d11f7
namespace fight {
template <class T>
class ParamBool_5ca20 : public ParamBoolBase {
public:
    ParamBool_5ca20(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_5ca20 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_5ca20(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_5ca20 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_5ca20(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f35d11f7 {
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
} // namespace fn_f35d11f7
namespace fight {
template <class T>
class ParamNameConstList_5ca20 : public ParamNameConstListBase {
public:
    ParamNameConstList_5ca20(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_5ca20 : public ParamVectorBase {
public:
    ParamVector_5ca20(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f35d11f7 {
class CGrappleSwapTrack_5cd20 {
public:
    void FUN_0005a220();
    void FUN_00012ae0();
    void FUN_00012af0();
    void FUN_0005a230();
    void FUN_0005a240();
    void FUN_0005a260();
    void FUN_0005a280();
    void FUN_0005a290();
    void FUN_0005a2a0();
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class CGrabTrack_5cf20 {
public:
    void FUN_0005a360();
    void FUN_0005a370();
    void FUN_0005a380();
    void FUN_0005a390();
    void FUN_0005a3b0();
    void FUN_0005a3c0();
    void FUN_0005a3d0();
    void FUN_00012bd0();
    void FUN_00012be0();
};
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
};
template <class T>
class ParamBranch : public ParamBranchBase {
public:
    ParamBranch(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
struct T_5d130 {
    char pad[0x10];
    int value;
    char FUN_0005d130(int a) {
        value = a;
        return 1;
    }
};
struct M_5d150 {
    int val;
};
class X_5d150 {
  public:
    char Set(int v);
    char pad[0x18];
    M_5d150 m;
};


// 0x0005c6b0 FUN_0005c6b0 (868 B): equivalent/0x0005c6b0.cpp
// sym: _FUN_0005c6b0 @8c9ae9661be1 @w58187241c629
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_0005c6b0 @ 0x0005c6b0
extern "C" void FUN_0005c6b0()
{
    if (hulk_at_004dc594 == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("timeBegin", &::CGrappleLocoStrafe4Track_5c6b0::FUN_0005a0d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("timeEnd", &::CGrappleLocoStrafe4Track_5c6b0::FUN_0005a0e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("locomotion", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012900);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animIdle", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012910);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animWalkNorth", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012920);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animWalkEast", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012930);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animWalkSouth", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012940);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animWalkWest", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012950);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animRunNorth", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012960);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animRunEast", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012970);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animRunSouth", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012980);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animRunWest", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012990);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("partition", &::CGrappleLocoStrafe4Track_5c6b0::FUN_000129a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("priority", &::CGrappleLocoStrafe4Track_5c6b0::FUN_0005a0f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("blendInTime", &::CGrappleLocoStrafe4Track_5c6b0::FUN_0005a100);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("blendOutTime", &::CGrappleLocoStrafe4Track_5c6b0::FUN_0005a110);
        FUN_002347b0(&hulk_at_004dc590, params, 16);
    }
    hulk_at_004dc594++;
}


// 0x0005ca20 FUN_0005ca20 (766 B): equivalent/0x0005ca20.cpp
// sym: _FUN_0005ca20 @f524d4da3623 @w895e39d36e35
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 30/30)
// FUN_0005ca20 @ 0x0005ca20
extern "C" void FUN_0005ca20()
{
    if (DAT_004dc59c == 0) {
        void* params[14];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>("timeBegin", &CGrappleAttachTrack_5ca20::FUN_0005a120);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_5ca20<CGrappleAttachTrack_5ca20>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamNameConstList_5ca20<CGrappleAttachTrack_5ca20>("joint", &CGrappleAttachTrack_5ca20::FUN_000129e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_5ca20<CGrappleAttachTrack_5ca20>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList_5ca20<CGrappleAttachTrack_5ca20>("channel", &CGrappleAttachTrack_5ca20::FUN_000129f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_5ca20<CGrappleAttachTrack_5ca20>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_5ca20<CGrappleAttachTrack_5ca20>("useOffset", &CGrappleAttachTrack_5ca20::FUN_0005a130);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_5ca20<CGrappleAttachTrack_5ca20>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector_5ca20<CGrappleAttachTrack_5ca20>("offsetPosition", &CGrappleAttachTrack_5ca20::FUN_0005a140);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>("offsetOrientation", &CGrappleAttachTrack_5ca20::FUN_0005a160);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_5ca20<CGrappleAttachTrack_5ca20>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector_5ca20<CGrappleAttachTrack_5ca20>("offsetAngle", &CGrappleAttachTrack_5ca20::FUN_0005a180);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_5ca20<CGrappleAttachTrack_5ca20>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamNameConstList_5ca20<CGrappleAttachTrack_5ca20>("orientJoint", &CGrappleAttachTrack_5ca20::FUN_00012a60);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_5ca20<CGrappleAttachTrack_5ca20>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector_5ca20<CGrappleAttachTrack_5ca20>("orientJointOffset", &CGrappleAttachTrack_5ca20::FUN_0005a1b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>("orientJointMinDistance", &CGrappleAttachTrack_5ca20::FUN_0005a1d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>("orientJointMaxDistance", &CGrappleAttachTrack_5ca20::FUN_0005a1e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_5ca20<CGrappleAttachTrack_5ca20>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamBool_5ca20<CGrappleAttachTrack_5ca20>("attachToGrapplee", &CGrappleAttachTrack_5ca20::FUN_0005a1f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_5ca20<CGrappleAttachTrack_5ca20>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamIntConstRange_5ca20<CGrappleAttachTrack_5ca20>("rootPriority", &CGrappleAttachTrack_5ca20::FUN_0005a200);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>("rootBlendInTime", &CGrappleAttachTrack_5ca20::FUN_0005a210);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc598), params, 14);
    }
    DAT_004dc59c++;
}


// 0x0005cd20 FUN_0005cd20 (511 B): equivalent/0x0005cd20.cpp
// sym: _FUN_0005cd20 @28668867e3d2 @wd9d64ba1b0a1
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 20/20)
// FUN_0005cd20 @ 0x0005cd20
extern "C" void FUN_0005cd20()
{
    if (DAT_004dc5a4 == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CGrappleSwapTrack_5cd20>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CGrappleSwapTrack_5cd20>("timeBegin", &CGrappleSwapTrack_5cd20::FUN_0005a220);
        mem = FUN_0008d690((int)sizeof(ParamNameConstList<CGrappleSwapTrack_5cd20>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamNameConstList<CGrappleSwapTrack_5cd20>("joint", &CGrappleSwapTrack_5cd20::FUN_00012ae0);
        mem = FUN_0008d690((int)sizeof(ParamNameConstList<CGrappleSwapTrack_5cd20>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamNameConstList<CGrappleSwapTrack_5cd20>("channel", &CGrappleSwapTrack_5cd20::FUN_00012af0);
        mem = FUN_0008d690((int)sizeof(ParamBool<CGrappleSwapTrack_5cd20>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<CGrappleSwapTrack_5cd20>("useOffset", &CGrappleSwapTrack_5cd20::FUN_0005a230);
        mem = FUN_0008d690((int)sizeof(ParamVector<CGrappleSwapTrack_5cd20>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamVector<CGrappleSwapTrack_5cd20>("offsetPosition", &CGrappleSwapTrack_5cd20::FUN_0005a240);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CGrappleSwapTrack_5cd20>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<CGrappleSwapTrack_5cd20>("offsetOrientation", &CGrappleSwapTrack_5cd20::FUN_0005a260);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<CGrappleSwapTrack_5cd20>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamIntConstRange<CGrappleSwapTrack_5cd20>("rootPriority", &CGrappleSwapTrack_5cd20::FUN_0005a280);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CGrappleSwapTrack_5cd20>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<CGrappleSwapTrack_5cd20>("rootBlendInTime", &CGrappleSwapTrack_5cd20::FUN_0005a290);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CGrappleSwapTrack_5cd20>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamFloatConstRange<CGrappleSwapTrack_5cd20>("rootBlendOutTime", &CGrappleSwapTrack_5cd20::FUN_0005a2a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5a0), params, 9);
    }
    DAT_004dc5a4++;
}


// 0x0005cf20 FUN_0005cf20 (511 B): equivalent/0x0005cf20.cpp
// sym: _FUN_0005cf20 @b38df0393e62 @wd2b064cb7759
// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 20/20)
// FUN_0005cf20 @ 0x0005cf20
extern "C" void FUN_0005cf20()
{
    if (DAT_004dc5c4 == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CGrabTrack_5cf20>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CGrabTrack_5cf20>("timeBegin", &CGrabTrack_5cf20::FUN_0005a360);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CGrabTrack_5cf20>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CGrabTrack_5cf20>("timeEnd", &CGrabTrack_5cf20::FUN_0005a370);
        mem = FUN_0008d690((int)sizeof(ParamNameConstList<CGrabTrack_5cf20>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamNameConstList<CGrabTrack_5cf20>("joint", &CGrabTrack_5cf20::FUN_0005a380);
        mem = FUN_0008d690((int)sizeof(ParamVector<CGrabTrack_5cf20>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<CGrabTrack_5cf20>("offset", &CGrabTrack_5cf20::FUN_0005a390);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CGrabTrack_5cf20>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<CGrabTrack_5cf20>("radius", &CGrabTrack_5cf20::FUN_0005a3b0);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<CGrabTrack_5cf20>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamIntConstRange<CGrabTrack_5cf20>("interruptPriority", &CGrabTrack_5cf20::FUN_0005a3c0);
        mem = FUN_0008d690((int)sizeof(ParamBool<CGrabTrack_5cf20>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamBool<CGrabTrack_5cf20>("missileCatch", &CGrabTrack_5cf20::FUN_0005a3d0);
        mem = FUN_0008d690((int)sizeof(ParamBranch<CGrabTrack_5cf20>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamBranch<CGrabTrack_5cf20>("receiver", &CGrabTrack_5cf20::FUN_00012bd0);
        mem = FUN_0008d690((int)sizeof(ParamBranch<CGrabTrack_5cf20>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamBranch<CGrabTrack_5cf20>("giver", &CGrabTrack_5cf20::FUN_00012be0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5c0), params, 9);
    }
    DAT_004dc5c4++;
}

} // namespace fn_f35d11f7

// 0x0005d120 FUN_0005d120 (12 B): matches/0x0005d120.cpp
// sym: ?FUN_0005d120@Obj_5d120@owners@@QAE_NH@Z
bool owners::Obj_5d120::FUN_0005d120(int x) {
    mVal = x;
    return true;
}

namespace fn_f35d11f7 {

// 0x0005d130 FUN_0005d130 (12 B): matches/0x0005d130.cpp
// sym: ?FUN_0005d130@T_5d130@fn_f35d11f7@@QAEDH@Z
int main() {
    T_5d130 t;
    return t.FUN_0005d130(0);
}

} // namespace fn_f35d11f7

// 0x0005d140 FUN_0005d140 (12 B): matches/0x0005d140.cpp
// sym: ?FUN_0005d140@Obj_5d140@owners@@QAEDH@Z
char owners::Obj_5d140::FUN_0005d140(int value) {
    m14 = value;
    return 1;
}

namespace fn_f35d11f7 {

// 0x0005d150 FUN_0005d150 (12 B): matches/0x0005d150.cpp
// sym: ?Set@X_5d150@fn_f35d11f7@@QAEDH@Z
char X_5d150::Set(int v) {
    m.val = v;
    return 1;
}

} // namespace fn_f35d11f7

// 0x0005d160 FUN_0005d160 (12 B): matches/0x0005d160.cpp
// sym: ?FUN_0005d160@Obj_5d160@owners@@QAEEE@Z
unsigned char owners::Obj_5d160::FUN_0005d160(unsigned char v) {
    b = v;
    return 1;
}

namespace fn_f35d11f7 {

// 0x0005d170 FUN_0005d170 (19 B): matches/0x0005d170.cpp
// sym: ?FUN_0005d170@fn_f35d11f7@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005d170() {
    FUN_00234810(((char*)&DAT_004dc5c8), ((char*)&DAT_004dc5cc));
}

} // namespace fn_f35d11f7
