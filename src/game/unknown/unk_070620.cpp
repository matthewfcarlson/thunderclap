// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070620..0x00072590 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f844dd59 {
#define TREE_TU_END }
namespace fn_f844dd59 {} using namespace fn_f844dd59;
#include "game/unknown.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f844dd59 {
void* FUN_0008d690(unsigned int size);
class CClimbingTrack_70620 {
public:
    void FUN_00067fc0();
    void FUN_00067fd0();
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamFloatConstRange_70620 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_70620(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class CJumpTrack_706c0 {
public:
    bool FUN_00067fe0(int); /* (unb4) as defined; address taken only */
    char FUN_00067ff0(int); /* (unb4) as defined; address taken only */
    char FUN_00068000(void*); /* (unb4) as defined; address taken only */
    char FUN_00068010(int); /* (unb4) as defined; address taken only */
    bool FUN_00068020(int); /* (unb4) as defined; address taken only */
    bool FUN_00068030(int); /* (unb4) as defined; address taken only */
    char FUN_00068040(int); /* (unb4) as defined; address taken only */
    char FUN_00068050(int); /* (unb4) as defined; address taken only */
    bool FUN_00068060(int); /* (unb4) as defined; address taken only */
    char FUN_000680e0(float); /* (unb4) as defined; address taken only */
    bool FUN_00068070(int); /* (unb4) as defined; address taken only */
    bool FUN_00068100(float); /* (unb4) as defined; address taken only */
    bool FUN_00068080(int); /* (unb4) as defined; address taken only */
    bool FUN_00068090(int); /* (unb4) as defined; address taken only */
    char FUN_000680a0(int); /* (unb4) as defined; address taken only */
    bool FUN_000680b0(int); /* (unb4) as defined; address taken only */
    char FUN_000680c0(char); /* (unb4) as defined; address taken only */
    char FUN_000680d0(char); /* (unb4) as defined; address taken only */
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamBool_706c0 : public ParamBoolBase {
public:
    ParamBool_706c0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_706c0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_706c0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_706c0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_706c0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
class CDropTrack_70ab0 {
public:
    bool FUN_00068120(int); /* (unb4) as defined; address taken only */
    char FUN_00068130(int); /* (unb4) as defined; address taken only */
    char FUN_00068140(float); /* (unb4) as defined; address taken only */
    char FUN_00068160(float); /* (unb4) as defined; address taken only */
    bool FUN_00068180(float); /* (unb4) as defined; address taken only */
    char FUN_000681a0(char); /* (unb4) as defined; address taken only */
    char FUN_000681b0(int); /* (unb4) as defined; address taken only */
    char FUN_000681c0(int); /* (unb4) as defined; address taken only */
    bool FUN_000681d0(void*); /* (unb4) as defined; address taken only */
    bool FUN_000681e0(int); /* (unb4) as defined; address taken only */
    bool FUN_000681f0(int); /* (unb4) as defined; address taken only */
    bool FUN_00068200(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamBool_70ab0 : public ParamBoolBase {
public:
    ParamBool_70ab0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_70ab0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_70ab0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_70ab0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_70ab0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
class CMoveTrack_70f20 {
public:
    bool FUN_00068280(int); /* (unb4) as defined; address taken only */
    bool FUN_00068290(int); /* (unb4) as defined; address taken only */
    char FUN_000682a0(int); /* (unb4) as defined; address taken only */
    bool FUN_000682b0(int); /* (unb4) as defined; address taken only */
    bool FUN_000682c0(int); /* (unb4) as defined; address taken only */
    bool FUN_000682d0(int); /* (unb4) as defined; address taken only */
    bool FUN_0006b6f0(float); /* (unb4) as defined; address taken only */
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamFloatConstRange_70f20 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_70f20(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_70f20 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_70f20(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
class CSweepTrack_712c0 {
public:
    char FUN_00068340(int); /* (unb4) as defined; address taken only */
    bool FUN_00068350(int); /* (unb4) as defined; address taken only */
    bool FUN_00068360(float); /* (unb4) as defined; address taken only */
    bool FUN_00068380(int); /* (unb4) as defined; address taken only */
    char FUN_00068390(int); /* (unb4) as defined; address taken only */
    char FUN_000683a0(int); /* (unb4) as defined; address taken only */
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class CIntangibleTrack_71a80 {
public:
    void FUN_000685b0();
    void FUN_000685c0();
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamFloatConstRange_71a80 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_71a80(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
class CIntangibleToActorsTrack_71b20 {
public:
    void FUN_000685d0();
    void FUN_000685e0();
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamFloatConstRange_71b20 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_71b20(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
class CJumpAttackTrack_71db0 {
public:
    bool FUN_000687a0(int); /* (unb4) as defined; address taken only */
    bool FUN_000687b0(int); /* (unb4) as defined; address taken only */
    char FUN_000687c0(void*); /* (unb4) as defined; address taken only */
    char FUN_000687e0(float); /* (unb4) as defined; address taken only */
    char FUN_00068800(int); /* (unb4) as defined; address taken only */
    bool FUN_00068810(int); /* (unb4) as defined; address taken only */
    bool FUN_00068820(int); /* (unb4) as defined; address taken only */
    char FUN_00068830(int); /* (unb4) as defined; address taken only */
    bool FUN_00068840(int); /* (unb4) as defined; address taken only */
};
class COrientTrack_71fb0 {
public:
    bool FUN_00068850(int); /* (unb4) as defined; address taken only */
    char FUN_00068860(int); /* (unb4) as defined; address taken only */
    bool FUN_00068870(float); /* (unb4) as defined; address taken only */
    char FUN_00068890(float); /* (unb4) as defined; address taken only */
    char FUN_000688b0(char); /* (unb4) as defined; address taken only */
    bool FUN_000688c0(int); /* (unb4) as defined; address taken only */
    bool FUN_000688d0(int); /* (unb4) as defined; address taken only */
    char FUN_000688e0(int); /* (unb4) as defined; address taken only */
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class CRageModeTrack_72440 {
public:
    void FUN_00068990();
    void FUN_000689a0();
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamEnumConstList_72440 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_72440(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_72440 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_72440(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f844dd59 {
class CStageTrack_724f0 {
public:
    void FUN_000689b0();
    void FUN_000689c0();
};
} // namespace fn_f844dd59
namespace fight {
template <class T>
class ParamFloatConstRange_724f0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_724f0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_724f0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_724f0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_f844dd59 {

// 0x00070620 FUN_00070620 (158 B): equivalent/0x00070620.cpp
// sym: _FUN_00070620 @f792edbf360c @w87d3155fd700
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00070620 @ 0x00070620
extern "C" void FUN_00070620()
{
    if (DAT_004dcf1c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70620<::CClimbingTrack_70620>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_70620<::CClimbingTrack_70620>("timeBegin", &::CClimbingTrack_70620::FUN_00067fc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70620<::CClimbingTrack_70620>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_70620<::CClimbingTrack_70620>("timeEnd", &::CClimbingTrack_70620::FUN_00067fd0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf18), params, 2);
    }
    DAT_004dcf1c++;
}


// 0x000706c0 FUN_000706c0 (970 B): equivalent/0x000706c0.cpp
// sym: _FUN_000706c0 @0e06dba671c3 @w046423b028f1
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 38/38)
// FUN_000706c0 @ 0x000706c0
extern "C" void FUN_000706c0()
{
    if (DAT_004dcf24 == 0) {
        void* params[18];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("timeBegin", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_00067fe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("timeEnd", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_00067ff0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("minFlightTime", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_00068000);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("maxFlightTime", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_00068010);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("upDistanceMin", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_00068020);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("upDistanceMax", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_00068030);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("forwardDistanceMin", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_00068040);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("forwardDistanceMax", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_00068050);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("drift", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_00068060);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("turningVelocityMin", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_000680e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("turningVelocityMinForwardSpeedCap", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_00068070);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("turningVelocityMax", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_00068100);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("turningVelocityMaxForwardSpeedCap", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_00068080);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_706c0<CJumpTrack_706c0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange_706c0<CJumpTrack_706c0>("priority", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_00068090);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("blendInTime", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_000680a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("blendOutTime", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_000680b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_706c0<CJumpTrack_706c0>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBool_706c0<CJumpTrack_706c0>("stopTrackAtApex", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_000680c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_706c0<CJumpTrack_706c0>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamBool_706c0<CJumpTrack_706c0>("redirect", (void (CJumpTrack_706c0::*)())&CJumpTrack_706c0::FUN_000680d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf20), params, 18);
    }
    DAT_004dcf24++;
}


// 0x00070ab0 FUN_00070ab0 (664 B): equivalent/0x00070ab0.cpp
// sym: _FUN_00070ab0 @a6582eb7a22a @w4cb7c840b97a
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 26/26)
// FUN_00070ab0 @ 0x00070ab0
extern "C" void FUN_00070ab0()
{
    if (DAT_004dcf2c == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("timeBegin", (void (CDropTrack_70ab0::*)())&CDropTrack_70ab0::FUN_00068120);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("timeEnd", (void (CDropTrack_70ab0::*)())&CDropTrack_70ab0::FUN_00068130);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("facing", (void (CDropTrack_70ab0::*)())&CDropTrack_70ab0::FUN_00068140);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("facingVelocity", (void (CDropTrack_70ab0::*)())&CDropTrack_70ab0::FUN_00068160);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("turningVelocity", (void (CDropTrack_70ab0::*)())&CDropTrack_70ab0::FUN_00068180);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_70ab0<CDropTrack_70ab0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamBool_70ab0<CDropTrack_70ab0>("useInitialVelocity", (void (CDropTrack_70ab0::*)())&CDropTrack_70ab0::FUN_000681a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("initialVelocity", (void (CDropTrack_70ab0::*)())&CDropTrack_70ab0::FUN_000681b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("gravity", (void (CDropTrack_70ab0::*)())&CDropTrack_70ab0::FUN_000681c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("maxVelocity", (void (CDropTrack_70ab0::*)())&CDropTrack_70ab0::FUN_000681d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_70ab0<CDropTrack_70ab0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamIntConstRange_70ab0<CDropTrack_70ab0>("priority", (void (CDropTrack_70ab0::*)())&CDropTrack_70ab0::FUN_000681e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("rootBlendInTime", (void (CDropTrack_70ab0::*)())&CDropTrack_70ab0::FUN_000681f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("rootBlendOutTime", (void (CDropTrack_70ab0::*)())&CDropTrack_70ab0::FUN_00068200);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf28), params, 12);
    }
    DAT_004dcf2c++;
}


// 0x00070f20 FUN_00070f20 (409 B): equivalent/0x00070f20.cpp
// sym: _FUN_00070f20 @1625f77f5337 @wcf4a4fa2384b
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 16/16)
// FUN_00070f20 @ 0x00070f20
extern "C" void FUN_00070f20()
{
    if (DAT_004dcf4c == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>("timeBegin", (void (CMoveTrack_70f20::*)())&CMoveTrack_70f20::FUN_00068280);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>("timeEnd", (void (CMoveTrack_70f20::*)())&CMoveTrack_70f20::FUN_00068290);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>("distance", (void (CMoveTrack_70f20::*)())&CMoveTrack_70f20::FUN_000682a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>("direction", (void (CMoveTrack_70f20::*)())&CMoveTrack_70f20::FUN_0006b6f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_70f20<CMoveTrack_70f20>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamIntConstRange_70f20<CMoveTrack_70f20>("priority", (void (CMoveTrack_70f20::*)())&CMoveTrack_70f20::FUN_000682b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>("blendInTime", (void (CMoveTrack_70f20::*)())&CMoveTrack_70f20::FUN_000682c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>("blendOutTime", (void (CMoveTrack_70f20::*)())&CMoveTrack_70f20::FUN_000682d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf48), params, 7);
    }
    DAT_004dcf4c++;
}

} // namespace fn_f844dd59

// 0x000710c0 FUN_000710c0 (256 B): equivalent/0x000710c0.cpp [wrapped: conflict: fight::ParamFloatConstRange]
// sym: _FUN_000710c0 @ab5711e865af @w2780eaefd806
namespace fn_000710c0 {
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 10/10)
// FUN_000710c0 @ 0x000710c0

void* __cdecl FUN_0008d690(unsigned);
bool FUN_000682e0(void*, int); /* (unb4) as defined; address taken only */ char FUN_000682f0(void*, int); /* (unb4) as defined; address taken only */ bool FUN_00068300(void*, int); /* (unb4) as defined; address taken only */ bool FUN_0006b750(void*, float); /* (unb4) as defined; address taken only */
class CMoveAddTrack;
namespace fight { template<class T> struct ParamFloatConstRange {
 virtual void slot0(); char data[12]; void (__cdecl *callback)(); unsigned tail;
 void FUN_00234960(const char*);
}; }
 
void __cdecl FUN_002347b0(unsigned*,fight::ParamFloatConstRange<CMoveAddTrack>**,unsigned);
extern "C" void __cdecl FUN_000710c0() {
 typedef fight::ParamFloatConstRange<CMoveAddTrack> Range;
 if (!DAT_004dcf54) {
 Range* items[4];
 const char* names[4] = {"timeBegin","timeEnd","distance","direction"};
 void (__cdecl *callbacks[4])() = {(void (*)())FUN_000682e0,(void (*)())FUN_000682f0,(void (*)())FUN_00068300,(void (*)())FUN_0006b750};
 for (unsigned i=0;i<4;++i) {
 Range* p = (Range*)FUN_0008d690((int)sizeof(Range));
 if(p) { p->FUN_00234960(names[i]); p->fight::ParamFloatConstRange<CMoveAddTrack>::ParamFloatConstRange(); p->callback=callbacks[i]; }
 items[i]=p;
 }
 FUN_002347b0(&DAT_004dcf50,items,4);
 }
 ++DAT_004dcf54;
}
} // namespace fn_000710c0

namespace fn_f844dd59 {

// 0x000712c0 FUN_000712c0 (358 B): equivalent/0x000712c0.cpp
// sym: _FUN_000712c0 @97c6cc03b373 @wc957925ab425
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_000712c0 @ 0x000712c0
extern "C" void FUN_000712c0()
{
    if (DAT_004dcf64 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CSweepTrack_712c0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CSweepTrack_712c0>("timeBegin", (void (CSweepTrack_712c0::*)())&CSweepTrack_712c0::FUN_00068340);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CSweepTrack_712c0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CSweepTrack_712c0>("timeEnd", (void (CSweepTrack_712c0::*)())&CSweepTrack_712c0::FUN_00068350);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CSweepTrack_712c0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<CSweepTrack_712c0>("arc", (void (CSweepTrack_712c0::*)())&CSweepTrack_712c0::FUN_00068360);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<CSweepTrack_712c0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamIntConstRange<CSweepTrack_712c0>("priority", (void (CSweepTrack_712c0::*)())&CSweepTrack_712c0::FUN_00068380);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CSweepTrack_712c0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<CSweepTrack_712c0>("rootBlendInTime", (void (CSweepTrack_712c0::*)())&CSweepTrack_712c0::FUN_00068390);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CSweepTrack_712c0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<CSweepTrack_712c0>("rootBlendOutTime", (void (CSweepTrack_712c0::*)())&CSweepTrack_712c0::FUN_000683a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf60), params, 6);
    }
    DAT_004dcf64++;
}

} // namespace fn_f844dd59

// 0x00071430 FUN_00071430 (715 B): matches/0x00071430.cpp [wrapped: macros]
// sym: ?Target@fn_00071430@@YAXXZ
namespace fn_00071430 {
// data: gCount = DAT_004dcf6c

extern "C" void __cdecl FUN_000683b0();
extern "C" void __cdecl FUN_000683c0();
extern "C" void __cdecl FUN_000683d0();
extern "C" void __cdecl FUN_00068410();
extern "C" void __cdecl FUN_00068440();
extern "C" void __cdecl FUN_00068470();
extern "C" void __cdecl FUN_00068480();
extern "C" void __cdecl FUN_000684a0();
extern "C" void __cdecl FUN_000684c0();
extern "C" void __cdecl FUN_000684d0();
extern "C" void __cdecl FUN_000684e0();
extern "C" void __cdecl FUN_00069cf0();
extern "C" void __cdecl FUN_00069d10();
extern "C" char DAT_003fc624[];
extern "C" char DAT_003fc644[];
extern "C" char DAT_003fc664[];
extern "C++" __declspec(nothrow) void* __cdecl Alloc(hulk_uintptr);
struct P {
    void InitFloat(const char*);
    void InitBool(const char*);
    void InitInt(const char*);
};
extern "C++" __declspec(nothrow) void __cdecl Register_002347b0(void**, void**, int);

void Target() {
    if ((*(int*)&DAT_004dcf6c) == 0) {
        void* a[13];
        P* p;
#define M(i, n, f, v, d)                                                                                     \
    p = (P*)Alloc(24);                                                                                       \
    if (p) {                                                                                                 \
        p->f(n);                                                                                             \
        *(void**)p = (void*)v;                                                                               \
        *(void**)((char*)p + 16) = (void*)d;                                                                 \
        a[i] = p;                                                                                            \
    } else {                                                                                                 \
        a[i] = 0;                                                                                            \
    }
        M(0, "timeBegin", InitFloat, ((int)DAT_003fc624), ((hulk_intptr)(void (__cdecl*)())&FUN_000683b0))
        M(1, "timeEnd", InitFloat, ((int)DAT_003fc624), ((hulk_intptr)(void (__cdecl*)())&FUN_000683c0))
        M(2, "turningVelocity", InitFloat, ((int)DAT_003fc624), ((hulk_intptr)(void (__cdecl*)())&FUN_00069cf0))
        M(3, "arc", InitFloat, ((int)DAT_003fc624), ((hulk_intptr)(void (__cdecl*)())&FUN_00069d10))
        M(4, "distance", InitFloat, ((int)DAT_003fc624), ((hulk_intptr)(void (__cdecl*)())&FUN_000683d0))
        M(5, "checkDistance", InitBool, ((int)DAT_003fc644), ((hulk_intptr)(void (__cdecl*)())&FUN_00068410))
        M(6, "pickupPropTarget", InitBool, ((int)DAT_003fc644), ((hulk_intptr)(void (__cdecl*)())&FUN_00068440))
        M(7, "locator", InitBool, ((int)DAT_003fc644), ((hulk_intptr)(void (__cdecl*)())&FUN_00068470))
        M(8, "orientOffset", InitFloat, ((int)DAT_003fc624), ((hulk_intptr)(void (__cdecl*)())&FUN_00068480))
        M(9, "orientOffsetFromTarget", InitFloat, ((int)DAT_003fc624), ((hulk_intptr)(void (__cdecl*)())&FUN_000684a0))
        M(10, "priority", InitInt, ((int)DAT_003fc664), ((hulk_intptr)(void (__cdecl*)())&FUN_000684c0))
        M(11, "blendInTime", InitFloat, ((int)DAT_003fc624), ((hulk_intptr)(void (__cdecl*)())&FUN_000684d0))
        M(12, "blendOutTime", InitFloat, ((int)DAT_003fc624), ((hulk_intptr)(void (__cdecl*)())&FUN_000684e0))
        Register_002347b0((void**)((hulk_intptr)DAT_004dcf68), a, 13);
    }
    ++(*(int*)&DAT_004dcf6c);
}
} // namespace fn_00071430
#undef M

namespace fn_f844dd59 {

// 0x00071a80 FUN_00071a80 (158 B): equivalent/0x00071a80.cpp
// sym: _FUN_00071a80 @be08a57309ce @wb602cd237924
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00071a80 @ 0x00071a80
extern "C" void FUN_00071a80()
{
    if (DAT_004dcf94 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_71a80<::CIntangibleTrack_71a80>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_71a80<::CIntangibleTrack_71a80>("timeBegin", &::CIntangibleTrack_71a80::FUN_000685b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_71a80<::CIntangibleTrack_71a80>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_71a80<::CIntangibleTrack_71a80>("timeEnd", &::CIntangibleTrack_71a80::FUN_000685c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf90), params, 2);
    }
    DAT_004dcf94++;
}


// 0x00071b20 FUN_00071b20 (158 B): equivalent/0x00071b20.cpp
// sym: _FUN_00071b20 @6e57a3b2dad9 @wbb2e5a300083
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00071b20 @ 0x00071b20
extern "C" void FUN_00071b20()
{
    if (DAT_004dcf9c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_71b20<::CIntangibleToActorsTrack_71b20>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_71b20<::CIntangibleToActorsTrack_71b20>("timeBegin", &::CIntangibleToActorsTrack_71b20::FUN_000685d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_71b20<::CIntangibleToActorsTrack_71b20>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_71b20<::CIntangibleToActorsTrack_71b20>("timeEnd", &::CIntangibleToActorsTrack_71b20::FUN_000685e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf98), params, 2);
    }
    DAT_004dcf9c++;
}


// 0x00071db0 FUN_00071db0 (511 B): equivalent/0x00071db0.cpp
// sym: _FUN_00071db0 @332946c7941e @w9b79d5049e24
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 20/20)
// FUN_00071db0 @ 0x00071db0
extern "C" void FUN_00071db0()
{
    if (DAT_004dcfbc == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("timeBegin", (void (CJumpAttackTrack_71db0::*)())&CJumpAttackTrack_71db0::FUN_000687a0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("timeEnd", (void (CJumpAttackTrack_71db0::*)())&CJumpAttackTrack_71db0::FUN_000687b0);
        mem = FUN_0008d690((int)sizeof(ParamVector<CJumpAttackTrack_71db0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamVector<CJumpAttackTrack_71db0>("direction", (void (CJumpAttackTrack_71db0::*)())&CJumpAttackTrack_71db0::FUN_000687c0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("arc", (void (CJumpAttackTrack_71db0::*)())&CJumpAttackTrack_71db0::FUN_000687e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("distance", (void (CJumpAttackTrack_71db0::*)())&CJumpAttackTrack_71db0::FUN_00068800);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("speed", (void (CJumpAttackTrack_71db0::*)())&CJumpAttackTrack_71db0::FUN_00068810);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<CJumpAttackTrack_71db0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamIntConstRange<CJumpAttackTrack_71db0>("priority", (void (CJumpAttackTrack_71db0::*)())&CJumpAttackTrack_71db0::FUN_00068820);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("rootBlendInTime", (void (CJumpAttackTrack_71db0::*)())&CJumpAttackTrack_71db0::FUN_00068830);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("rootBlendOutTime", (void (CJumpAttackTrack_71db0::*)())&CJumpAttackTrack_71db0::FUN_00068840);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcfb8), params, 9);
    }
    DAT_004dcfbc++;
}


// 0x00071fb0 FUN_00071fb0 (460 B): equivalent/0x00071fb0.cpp
// sym: _FUN_00071fb0 @3278e90d947e @w85703c09be99
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 18/18)
// FUN_00071fb0 @ 0x00071fb0
extern "C" void FUN_00071fb0()
{
    if (DAT_004dcfc4 == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COrientTrack_71fb0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<COrientTrack_71fb0>("timeBegin", (void (COrientTrack_71fb0::*)())&COrientTrack_71fb0::FUN_00068850);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COrientTrack_71fb0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<COrientTrack_71fb0>("timeEnd", (void (COrientTrack_71fb0::*)())&COrientTrack_71fb0::FUN_00068860);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COrientTrack_71fb0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<COrientTrack_71fb0>("turningVelocity", (void (COrientTrack_71fb0::*)())&COrientTrack_71fb0::FUN_00068870);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COrientTrack_71fb0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<COrientTrack_71fb0>("offset", (void (COrientTrack_71fb0::*)())&COrientTrack_71fb0::FUN_00068890);
        mem = FUN_0008d690((int)sizeof(ParamBool<COrientTrack_71fb0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<COrientTrack_71fb0>("steering", (void (COrientTrack_71fb0::*)())&COrientTrack_71fb0::FUN_000688b0);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<COrientTrack_71fb0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamIntConstRange<COrientTrack_71fb0>("priority", (void (COrientTrack_71fb0::*)())&COrientTrack_71fb0::FUN_000688c0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COrientTrack_71fb0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<COrientTrack_71fb0>("blendInTime", (void (COrientTrack_71fb0::*)())&COrientTrack_71fb0::FUN_000688d0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COrientTrack_71fb0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<COrientTrack_71fb0>("blendOutTime", (void (COrientTrack_71fb0::*)())&COrientTrack_71fb0::FUN_000688e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcfc0), params, 8);
    }
    DAT_004dcfc4++;
}

} // namespace fn_f844dd59

// 0x00072360 FUN_00072360 (213 B): equivalent/0x00072360.cpp [wrapped: conflict: fight::ParamFloatConstRange]
// sym: _FUN_00072360 @df4eb52acb32 @w662203cc6ea4
namespace fn_00072360 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_00072360 @ 0x00072360

void* __cdecl FUN_0008d690(unsigned int);
bool FUN_00068960(void*, int); /* (unb4) as defined; address taken only */
bool FUN_00068970(void*, int); /* (unb4) as defined; address taken only */
bool FUN_00068980(void*, int); /* (unb4) as defined; address taken only */
class CInvulnerableTrack;
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 void FUN_00234960(const char*);
 char pad[12];
 void (__cdecl *callback)();
 int tail;
};
}
typedef fight::ParamFloatConstRange<CInvulnerableTrack> Param;
void __cdecl FUN_002347b0(void*, Param**, int);
extern "C" void __cdecl FUN_00072360() {
 if (!DAT_004dcfdc) {
 Param* entries[3];
 const char* names[3]={"timeBegin","timeEnd","extensionTime"};
 void (__cdecl *callbacks[3])()={(void (*)())FUN_00068960,(void (*)())FUN_00068970,(void (*)())FUN_00068980};
 for(int i=0;i<3;++i) {
 Param* p=(Param*)FUN_0008d690((int)sizeof(Param));
 if(p) {
 p->FUN_00234960(names[i]);
 p->fight::ParamFloatConstRange<CInvulnerableTrack>::ParamFloatConstRange();
 p->callback=callbacks[i];
 }
 entries[i]=p;
 }
 FUN_002347b0(&DAT_004dcfd8,entries,3);
 }
 ++DAT_004dcfdc;
}
} // namespace fn_00072360

namespace fn_f844dd59 {

// 0x00072440 FUN_00072440 (172 B): equivalent/0x00072440.cpp
// sym: _FUN_00072440 @0e4cd911bee1 @wa4e6346cd7fa
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00072440 @ 0x00072440
extern "C" void FUN_00072440()
{
    if (DAT_004dcfe4 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_72440<::CRageModeTrack_72440>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_72440<::CRageModeTrack_72440>("timeBegin", &::CRageModeTrack_72440::FUN_00068990);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_72440<::CRageModeTrack_72440>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_72440<::CRageModeTrack_72440>("rageMode", ((const char**)&DAT_00496fd8), 3, &::CRageModeTrack_72440::FUN_000689a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcfe0), params, 2);
    }
    DAT_004dcfe4++;
}


// 0x000724f0 FUN_000724f0 (158 B): equivalent/0x000724f0.cpp
// sym: _FUN_000724f0 @50fe66d86e9f @w98a0dd5d7c08
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_000724f0 @ 0x000724f0
extern "C" void FUN_000724f0()
{
    if (DAT_004dcfec == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_724f0<::CStageTrack_724f0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_724f0<::CStageTrack_724f0>("timeBegin", &::CStageTrack_724f0::FUN_000689b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_724f0<::CStageTrack_724f0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange_724f0<::CStageTrack_724f0>("stage", &::CStageTrack_724f0::FUN_000689c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcfe8), params, 2);
    }
    DAT_004dcfec++;
}

} // namespace fn_f844dd59
