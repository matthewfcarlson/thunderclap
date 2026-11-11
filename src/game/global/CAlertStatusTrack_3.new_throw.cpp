// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00072590..0x00075ce0 (kind game, layer game, confidence high), dominant class CAlertStatusTrack
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc3775b1 {
#define TREE_TU_END }
namespace fn_fc3775b1 {} using namespace fn_fc3775b1;
#include "game/global.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fc3775b1 {
extern "C" void* FUN_0008d690(unsigned int size);
class CWallSlideTrack_72820 {
public:
    void FUN_00068bc0();
    void FUN_00068bd0();
    void FUN_00068be0();
    void FUN_00068bf0();
    void FUN_00068c00();
    void FUN_00068c10();
    void FUN_00068c20();
    void FUN_00068c30();
    void FUN_00068c40();
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class CJointTrack_74ab0 {
public:
    void FUN_00067f30();
    void FUN_00067f40();
    void FUN_00011ce0();
    void FUN_00067f50();
    void FUN_00067f60();
    void FUN_00067f80();
    void FUN_00068d90();
    void FUN_00067f90();
    void FUN_00067fa0();
    void FUN_00067fb0();
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_fc3775b1
namespace fight {
template <class T>
class ParamBool_74ab0 : public ParamBoolBase {
public:
    ParamBool_74ab0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_74ab0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_74ab0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_74ab0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_74ab0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fc3775b1 {
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
} // namespace fn_fc3775b1
namespace fight {
template <class T>
class ParamNameConstList_74ab0 : public ParamNameConstListBase {
public:
    ParamNameConstList_74ab0(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_74ab0 : public ParamVectorBase {
public:
    ParamVector_74ab0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_fc3775b1 {

// 0x00072820 FUN_00072820 (511 B): equivalent/0x00072820.cpp
// sym: _FUN_00072820 @ab489e1b485d @w2ddec1bdab23
// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 20/20)
// FUN_00072820 @ 0x00072820
extern "C" void FUN_00072820()
{
    if (DAT_004dd024 == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CWallSlideTrack_72820>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CWallSlideTrack_72820>("timeBegin", &CWallSlideTrack_72820::FUN_00068bc0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CWallSlideTrack_72820>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CWallSlideTrack_72820>("maxTimeEnd", &CWallSlideTrack_72820::FUN_00068bd0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CWallSlideTrack_72820>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<CWallSlideTrack_72820>("friction", &CWallSlideTrack_72820::FUN_00068be0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CWallSlideTrack_72820>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<CWallSlideTrack_72820>("gravity", &CWallSlideTrack_72820::FUN_00068bf0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CWallSlideTrack_72820>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<CWallSlideTrack_72820>("deceleration", &CWallSlideTrack_72820::FUN_00068c00);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CWallSlideTrack_72820>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<CWallSlideTrack_72820>("minVelocity", &CWallSlideTrack_72820::FUN_00068c10);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<CWallSlideTrack_72820>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamIntConstRange<CWallSlideTrack_72820>("priority", &CWallSlideTrack_72820::FUN_00068c20);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CWallSlideTrack_72820>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<CWallSlideTrack_72820>("blendInTime", &CWallSlideTrack_72820::FUN_00068c30);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CWallSlideTrack_72820>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamFloatConstRange<CWallSlideTrack_72820>("blendOutTime", &CWallSlideTrack_72820::FUN_00068c40);
        FUN_002347b0(((ParamRegistry*)&DAT_004dd020), params, 9);
    }
    DAT_004dd024++;
}


// 0x00074ab0 FUN_00074ab0 (562 B): equivalent/0x00074ab0.cpp
// sym: _FUN_00074ab0 @a1fedbf2b18b @we08f77e41b6d
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 22/22)
// FUN_00074ab0 @ 0x00074ab0
extern "C" void FUN_00074ab0()
{
    if (DAT_004dcf0c == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>("timeBegin", &CJointTrack_74ab0::FUN_00067f30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>("timeEnd", &CJointTrack_74ab0::FUN_00067f40);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_74ab0<CJointTrack_74ab0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList_74ab0<CJointTrack_74ab0>("joint", &CJointTrack_74ab0::FUN_00011ce0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_74ab0<CJointTrack_74ab0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_74ab0<CJointTrack_74ab0>("hasTranslation", &CJointTrack_74ab0::FUN_00067f50);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_74ab0<CJointTrack_74ab0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector_74ab0<CJointTrack_74ab0>("translation", &CJointTrack_74ab0::FUN_00067f60);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_74ab0<CJointTrack_74ab0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamBool_74ab0<CJointTrack_74ab0>("hasRotation", &CJointTrack_74ab0::FUN_00067f80);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_74ab0<CJointTrack_74ab0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector_74ab0<CJointTrack_74ab0>("rotation", &CJointTrack_74ab0::FUN_00068d90);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_74ab0<CJointTrack_74ab0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_74ab0<CJointTrack_74ab0>("priority", &CJointTrack_74ab0::FUN_00067f90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>("blendInTime", &CJointTrack_74ab0::FUN_00067fa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>("blendOutTime", &CJointTrack_74ab0::FUN_00067fb0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf08), params, 10);
    }
    DAT_004dcf0c++;
}

} // namespace fn_fc3775b1
