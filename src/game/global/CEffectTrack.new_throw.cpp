// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000604d0..0x00061b40 (kind game, layer game, confidence high), dominant class CEffectTrack
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0ac4b35 {
#define TREE_TU_END }
namespace fn_f0ac4b35 {} using namespace fn_f0ac4b35;
#include "game/global.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f0ac4b35 {
extern "C" void* FUN_0008d690(unsigned int size);
class CMotionTrailTrack_612e0 {
public:
    void FUN_00060210();
    void FUN_00060220();
    void FUN_00060230();
    void FUN_00060240();
    void FUN_00012c40();
    void FUN_00060b10();
    void FUN_00060250();
    void FUN_000602b0();
    void FUN_00060260();
    void FUN_000602d0();
    void FUN_00060270();
    void FUN_000602f0();
    void FUN_00060280();
    void FUN_00060310();
    void FUN_00060290();
    void FUN_00060340();
    void FUN_000602a0();
    void FUN_00060370();
    void FUN_00012c80();
    void FUN_000603a0();
    void FUN_000603d0();
    void FUN_000603e0();
    void FUN_000603f0();
    void FUN_00060400();
    void FUN_00060410();
    void FUN_00060420();
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
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
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
} // namespace fn_f0ac4b35
namespace fight {
template <class T>
class ParamBool_612e0 : public ParamBoolBase {
public:
    ParamBool_612e0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_612e0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_612e0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_612e0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_612e0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_612e0 : public ParamNameBase {
public:
    ParamName_612e0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamNameConstList_612e0 : public ParamNameConstListBase {
public:
    ParamNameConstList_612e0(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_612e0 : public ParamVectorBase {
public:
    ParamVector_612e0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f0ac4b35 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class CEffectTrack_61850 {
public:
    bool FUN_00060430(int); /* (unb4) as defined; address taken only */
    bool FUN_00060440(int); /* (unb4) as defined; address taken only */
    void FUN_00012db0();
    bool FUN_00060470(int); /* (unb4) as defined; address taken only */
    void FUN_00012d80();
    bool FUN_00060450(void*); /* (unb4) as defined; address taken only */
    char FUN_000607d0(void*); /* (unb4) as defined; address taken only */
    bool FUN_00060480(int); /* (unb4) as defined; address taken only */
    void FUN_00012da0();
    char FUN_00060490(char); /* (unb4) as defined; address taken only */
    char FUN_000604a0(char); /* (unb4) as defined; address taken only */
    bool FUN_000604b0(int); /* (unb4) as defined; address taken only */
    bool FUN_000604c0(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_f0ac4b35
namespace fight {
template <class T>
class ParamBool_61850 : public ParamBoolBase {
public:
    ParamBool_61850(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_61850 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_61850(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { names = n; count = c; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_61850 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_61850(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_61850 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_61850(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_61850 : public ParamNameBase {
public:
    ParamName_61850(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamNameConstList_61850 : public ParamNameConstListBase {
public:
    ParamNameConstList_61850(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_61850 : public ParamVectorBase {
public:
    ParamVector_61850(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_f0ac4b35 {

// 0x000612e0 FUN_000612e0 (1378 B): equivalent/0x000612e0.cpp
// sym: _FUN_000612e0 @1df01b142511 @w15a45b3229af
// STATUS: equivalent (tools/equiv.py level 3: 1961 inputs, branch coverage 54/54)
// FUN_000612e0 @ 0x000612e0
extern "C" void FUN_000612e0()
{
    if (DAT_004dc604 == 0) {
        void* params[26];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>("timeBegin", &::CMotionTrailTrack_612e0::FUN_00060210);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>("timeEnd", &::CMotionTrailTrack_612e0::FUN_00060220);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>("generateTime", &::CMotionTrailTrack_612e0::FUN_00060230);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>("fadeOutTime", &::CMotionTrailTrack_612e0::FUN_00060240);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_612e0<::CMotionTrailTrack_612e0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName_612e0<::CMotionTrailTrack_612e0>("shader", &::CMotionTrailTrack_612e0::FUN_00012c40);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_612e0<::CMotionTrailTrack_612e0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange_612e0<::CMotionTrailTrack_612e0>("numJoints", &::CMotionTrailTrack_612e0::FUN_00060b10);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>("joint1", &::CMotionTrailTrack_612e0::FUN_00060250);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_612e0<::CMotionTrailTrack_612e0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_612e0<::CMotionTrailTrack_612e0>("jointOffset1", &::CMotionTrailTrack_612e0::FUN_000602b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>("joint2", &::CMotionTrailTrack_612e0::FUN_00060260);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_612e0<::CMotionTrailTrack_612e0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamVector_612e0<::CMotionTrailTrack_612e0>("jointOffset2", &::CMotionTrailTrack_612e0::FUN_000602d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>("joint3", &::CMotionTrailTrack_612e0::FUN_00060270);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_612e0<::CMotionTrailTrack_612e0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamVector_612e0<::CMotionTrailTrack_612e0>("jointOffset3", &::CMotionTrailTrack_612e0::FUN_000602f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>("joint4", &::CMotionTrailTrack_612e0::FUN_00060280);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_612e0<::CMotionTrailTrack_612e0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamVector_612e0<::CMotionTrailTrack_612e0>("jointOffset4", &::CMotionTrailTrack_612e0::FUN_00060310);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>("joint5", &::CMotionTrailTrack_612e0::FUN_00060290);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_612e0<::CMotionTrailTrack_612e0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamVector_612e0<::CMotionTrailTrack_612e0>("jointOffset5", &::CMotionTrailTrack_612e0::FUN_00060340);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>("joint6", &::CMotionTrailTrack_612e0::FUN_000602a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_612e0<::CMotionTrailTrack_612e0>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamVector_612e0<::CMotionTrailTrack_612e0>("jointOffset6", &::CMotionTrailTrack_612e0::FUN_00060370);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamNameConstList_612e0<::CMotionTrailTrack_612e0>("shrinkJoint", &::CMotionTrailTrack_612e0::FUN_00012c80);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_612e0<::CMotionTrailTrack_612e0>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamVector_612e0<::CMotionTrailTrack_612e0>("shrinkOffset", &::CMotionTrailTrack_612e0::FUN_000603a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>("shrinkTime", &::CMotionTrailTrack_612e0::FUN_000603d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>("fadeTime", &::CMotionTrailTrack_612e0::FUN_000603e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamFloatConstRange_612e0<::CMotionTrailTrack_612e0>("textureTime", &::CMotionTrailTrack_612e0::FUN_000603f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_612e0<::CMotionTrailTrack_612e0>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamBool_612e0<::CMotionTrailTrack_612e0>("abortWhenInterrupted", &::CMotionTrailTrack_612e0::FUN_00060400);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_612e0<::CMotionTrailTrack_612e0>));
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamBool_612e0<::CMotionTrailTrack_612e0>("runTillStop", &::CMotionTrailTrack_612e0::FUN_00060410);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_612e0<::CMotionTrailTrack_612e0>));
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamIntConstRange_612e0<::CMotionTrailTrack_612e0>("slot", &::CMotionTrailTrack_612e0::FUN_00060420);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc600), params, 26);
    }
    DAT_004dc604++;
}


// 0x00061850 FUN_00061850 (743 B): equivalent/0x00061850.cpp
// sym: _FUN_00061850 @e1f25b9b5518 @w91371bbb8c6f
// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 28/28)
// FUN_00061850 @ 0x00061850
extern "C" void FUN_00061850()
{
    if (DAT_004dc60c == 0) {
        void* params[13];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_61850<CEffectTrack_61850>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_61850<CEffectTrack_61850>("timeBegin", (void (CEffectTrack_61850::*)())&CEffectTrack_61850::FUN_00060430);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_61850<CEffectTrack_61850>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_61850<CEffectTrack_61850>("timeEnd", (void (CEffectTrack_61850::*)())&CEffectTrack_61850::FUN_00060440);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_61850<CEffectTrack_61850>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_61850<CEffectTrack_61850>("effectName", &CEffectTrack_61850::FUN_00012db0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_61850<CEffectTrack_61850>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamEnumConstList_61850<CEffectTrack_61850>("emitSpace", ((const char**)&DAT_00495d60), 5, (void (CEffectTrack_61850::*)())&CEffectTrack_61850::FUN_00060470);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_61850<CEffectTrack_61850>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamNameConstList_61850<CEffectTrack_61850>("emitJoint", &CEffectTrack_61850::FUN_00012d80);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_61850<CEffectTrack_61850>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamVector_61850<CEffectTrack_61850>("offset", (void (CEffectTrack_61850::*)())&CEffectTrack_61850::FUN_00060450);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_61850<CEffectTrack_61850>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector_61850<CEffectTrack_61850>("orientation", (void (CEffectTrack_61850::*)())&CEffectTrack_61850::FUN_000607d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_61850<CEffectTrack_61850>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamEnumConstList_61850<CEffectTrack_61850>("attachSpace", ((const char**)&DAT_00495d50), 4, (void (CEffectTrack_61850::*)())&CEffectTrack_61850::FUN_00060480);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_61850<CEffectTrack_61850>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamNameConstList_61850<CEffectTrack_61850>("attachJoint", &CEffectTrack_61850::FUN_00012da0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_61850<CEffectTrack_61850>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_61850<CEffectTrack_61850>("abortWhenInterrupted", (void (CEffectTrack_61850::*)())&CEffectTrack_61850::FUN_00060490);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_61850<CEffectTrack_61850>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool_61850<CEffectTrack_61850>("runTillStop", (void (CEffectTrack_61850::*)())&CEffectTrack_61850::FUN_000604a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_61850<CEffectTrack_61850>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamIntConstRange_61850<CEffectTrack_61850>("slot", (void (CEffectTrack_61850::*)())&CEffectTrack_61850::FUN_000604b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_61850<CEffectTrack_61850>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_61850<CEffectTrack_61850>("scale", (void (CEffectTrack_61850::*)())&CEffectTrack_61850::FUN_000604c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc608), params, 13);
    }
    DAT_004dc60c++;
}

} // namespace fn_f0ac4b35
