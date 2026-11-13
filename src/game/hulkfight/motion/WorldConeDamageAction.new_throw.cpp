// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00143100..0x00146900 (kind game, layer game, confidence high), dominant class hulkfight::motion::WorldConeDamageAction
#include "tree_prelude.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7eb1b84 {
#define TREE_TU_END }
namespace fn_f7eb1b84 {} using namespace fn_f7eb1b84;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f7eb1b84 {
extern "C" void* FUN_0008d690(unsigned int size);
class SlowMotionTrack {
public:
    bool FUN_00143230(int); /* (unb4) as defined; address taken only */
    char FUN_00143250(int); /* (unb4) as defined; address taken only */
    bool FUN_00143270(int); /* (unb4) as defined; address taken only */
    char FUN_00143290(int); /* (unb4) as defined; address taken only */
    bool FUN_001432b0(int); /* (unb4) as defined; address taken only */
    char FUN_001432d0(char); /* (unb4) as defined; address taken only */
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
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
} // namespace fn_f7eb1b84
namespace hulkfight { namespace motion {
class WorldConeDamageTrack_1456b0 {
public:
    bool FUN_00143400(int); /* (unb4) as defined; address taken only */
    bool FUN_00143430(void*); /* (unb4) as defined; address taken only */
    bool FUN_00143470(void*); /* (unb4) as defined; address taken only */
    char FUN_001434b0(void*); /* (unb4) as defined; address taken only */
    char FUN_001434e0(float); /* (unb4) as defined; address taken only */
    bool FUN_00143510(float); /* (unb4) as defined; address taken only */
    bool FUN_00143540(int); /* (unb4) as defined; address taken only */
    char FUN_00143560(int); /* (unb4) as defined; address taken only */
    char FUN_00143580(int); /* (unb4) as defined; address taken only */
    char FUN_001435a0(int); /* (unb4) as defined; address taken only */
    char FUN_001435c0(int); /* (unb4) as defined; address taken only */
    bool FUN_001435e0(int); /* (unb4) as defined; address taken only */
    bool FUN_00143600(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_1456b0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1456b0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_1456b0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1456b0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_1456b0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_1456b0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_1456b0 : public ParamVectorBase {
public:
    ParamVector_1456b0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class MotionTrailStopTrack_145b00 {
public:
    bool FUN_001436c0(int); /* (unb4) as defined; address taken only */
    bool FUN_001436e0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_145b00 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_145b00(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_145b00 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_145b00(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class HitEffectTrack_145f90 {
public:
    bool FUN_00143180(int); /* (unb4) as defined; address taken only */
    char FUN_001431a0(int); /* (unb4) as defined; address taken only */
    void FUN_001431b0();
    char FUN_001431d0(int); /* (unb4) as defined; address taken only */
    void FUN_001431e0();
    bool FUN_00143200(int); /* (unb4) as defined; address taken only */
    char FUN_00143220(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f7eb1b84 {
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class WorldDamageTrack {
public:
    char FUN_001432e0(int); /* (unb4) as defined; address taken only */
    void FUN_001432f0();
    char FUN_00143320(void*); /* (unb4) as defined; address taken only */
    bool FUN_00143360(void*); /* (unb4) as defined; address taken only */
    bool FUN_00143390(int); /* (unb4) as defined; address taken only */
    char FUN_001433b0(int); /* (unb4) as defined; address taken only */
    bool FUN_001433d0(int); /* (unb4) as defined; address taken only */
    char FUN_001433f0(int); /* (unb4) as defined; address taken only */
};
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};


// 0x00145540 FUN_00145540 (358 B): equivalent/0x00145540.cpp
// sym: ?FUN_00145540@fn_f7eb1b84@@YAXXZ @a650d82625fa @w30d01b6b620e
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 14/14)
// FUN_00145540 @ 0x00145540
void FUN_00145540()
{
    if (DAT_004e0f8c == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SlowMotionTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<SlowMotionTrack>("timeBegin", (void (SlowMotionTrack::*)())&SlowMotionTrack::FUN_00143230);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SlowMotionTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<SlowMotionTrack>("timeOn", (void (SlowMotionTrack::*)())&SlowMotionTrack::FUN_00143250);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SlowMotionTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<SlowMotionTrack>("timeOff", (void (SlowMotionTrack::*)())&SlowMotionTrack::FUN_00143270);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SlowMotionTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<SlowMotionTrack>("timeEnd", (void (SlowMotionTrack::*)())&SlowMotionTrack::FUN_00143290);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SlowMotionTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<SlowMotionTrack>("simulationRate", (void (SlowMotionTrack::*)())&SlowMotionTrack::FUN_001432b0);
        mem = FUN_0008d690((int)sizeof(ParamBool<SlowMotionTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<SlowMotionTrack>("fromScenario", (void (SlowMotionTrack::*)())&SlowMotionTrack::FUN_001432d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f88), params, 6);
    }
    DAT_004e0f8c++;
}


// 0x001456b0 FUN_001456b0 (729 B): equivalent/0x001456b0.cpp
// sym: ?FUN_001456b0@fn_f7eb1b84@@YAXXZ @aceb7d2c9ca1 @w3f84ffd8f732
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 28/28)
// FUN_001456b0 @ 0x001456b0
void FUN_001456b0()
{
    if (DAT_004e0f9c == 0) {
        void* params[13];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>("timeBegin", (void (hulkfight::motion::WorldConeDamageTrack_1456b0::*)())&hulkfight::motion::WorldConeDamageTrack_1456b0::FUN_00143400);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamVector_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>("position", (void (hulkfight::motion::WorldConeDamageTrack_1456b0::*)())&hulkfight::motion::WorldConeDamageTrack_1456b0::FUN_00143430);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamVector_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>("direction", (void (hulkfight::motion::WorldConeDamageTrack_1456b0::*)())&hulkfight::motion::WorldConeDamageTrack_1456b0::FUN_00143470);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>("up", (void (hulkfight::motion::WorldConeDamageTrack_1456b0::*)())&hulkfight::motion::WorldConeDamageTrack_1456b0::FUN_001434b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>("minAngle", (void (hulkfight::motion::WorldConeDamageTrack_1456b0::*)())&hulkfight::motion::WorldConeDamageTrack_1456b0::FUN_001434e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>("maxAngle", (void (hulkfight::motion::WorldConeDamageTrack_1456b0::*)())&hulkfight::motion::WorldConeDamageTrack_1456b0::FUN_00143510);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>("startDistance", (void (hulkfight::motion::WorldConeDamageTrack_1456b0::*)())&hulkfight::motion::WorldConeDamageTrack_1456b0::FUN_00143540);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>("length", (void (hulkfight::motion::WorldConeDamageTrack_1456b0::*)())&hulkfight::motion::WorldConeDamageTrack_1456b0::FUN_00143560);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>("minDecals", (void (hulkfight::motion::WorldConeDamageTrack_1456b0::*)())&hulkfight::motion::WorldConeDamageTrack_1456b0::FUN_00143580);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamIntConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>("maxDecals", (void (hulkfight::motion::WorldConeDamageTrack_1456b0::*)())&hulkfight::motion::WorldConeDamageTrack_1456b0::FUN_001435a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>("minDecalScale", (void (hulkfight::motion::WorldConeDamageTrack_1456b0::*)())&hulkfight::motion::WorldConeDamageTrack_1456b0::FUN_001435c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>("maxDecalScale", (void (hulkfight::motion::WorldConeDamageTrack_1456b0::*)())&hulkfight::motion::WorldConeDamageTrack_1456b0::FUN_001435e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamEnumConstList_1456b0<hulkfight::motion::WorldConeDamageTrack_1456b0>("damageType", ((const char**)&DAT_004ad788), 7, (void (hulkfight::motion::WorldConeDamageTrack_1456b0::*)())&hulkfight::motion::WorldConeDamageTrack_1456b0::FUN_00143600);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f98), params, 13);
    }
    DAT_004e0f9c++;
}


// 0x00145b00 FUN_00145b00 (158 B): equivalent/0x00145b00.cpp
// sym: ?FUN_00145b00@fn_f7eb1b84@@YAXXZ @059f893f4da1 @w1b3a9b61a5e0
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// FUN_00145b00 @ 0x00145b00
void FUN_00145b00()
{
    if (DAT_004e0fac == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_145b00<hulkfight::motion::MotionTrailStopTrack_145b00>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_145b00<hulkfight::motion::MotionTrailStopTrack_145b00>("timeBegin", (void (hulkfight::motion::MotionTrailStopTrack_145b00::*)())&hulkfight::motion::MotionTrailStopTrack_145b00::FUN_001436c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_145b00<hulkfight::motion::MotionTrailStopTrack_145b00>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange_145b00<hulkfight::motion::MotionTrailStopTrack_145b00>("slot", (void (hulkfight::motion::MotionTrailStopTrack_145b00::*)())&hulkfight::motion::MotionTrailStopTrack_145b00::FUN_001436e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fa8), params, 2);
    }
    DAT_004e0fac++;
}


// 0x00145f90 FUN_00145f90 (409 B): equivalent/0x00145f90.cpp
// sym: ?FUN_00145f90@fn_f7eb1b84@@YAXXZ @10ccb3e19ede @w3422a40fe7cf
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_00145f90 @ 0x00145f90
void FUN_00145f90()
{
    if (DAT_004e0f84 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitEffectTrack_145f90>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<hulkfight::motion::HitEffectTrack_145f90>("timeBegin", (void (hulkfight::motion::HitEffectTrack_145f90::*)())&hulkfight::motion::HitEffectTrack_145f90::FUN_00143180);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitEffectTrack_145f90>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<hulkfight::motion::HitEffectTrack_145f90>("timeEnd", (void (hulkfight::motion::HitEffectTrack_145f90::*)())&hulkfight::motion::HitEffectTrack_145f90::FUN_001431a0);
        mem = FUN_0008d690((int)sizeof(ParamName<hulkfight::motion::HitEffectTrack_145f90>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamName<hulkfight::motion::HitEffectTrack_145f90>("hitEffectName", &hulkfight::motion::HitEffectTrack_145f90::FUN_001431b0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitEffectTrack_145f90>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<hulkfight::motion::HitEffectTrack_145f90>("hitEffectScale", (void (hulkfight::motion::HitEffectTrack_145f90::*)())&hulkfight::motion::HitEffectTrack_145f90::FUN_001431d0);
        mem = FUN_0008d690((int)sizeof(ParamName<hulkfight::motion::HitEffectTrack_145f90>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamName<hulkfight::motion::HitEffectTrack_145f90>("whiffEffectName", &hulkfight::motion::HitEffectTrack_145f90::FUN_001431e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitEffectTrack_145f90>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<hulkfight::motion::HitEffectTrack_145f90>("whiffEffectScale", (void (hulkfight::motion::HitEffectTrack_145f90::*)())&hulkfight::motion::HitEffectTrack_145f90::FUN_00143200);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<hulkfight::motion::HitEffectTrack_145f90>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamIntConstRange<hulkfight::motion::HitEffectTrack_145f90>("priority", (void (hulkfight::motion::HitEffectTrack_145f90::*)())&hulkfight::motion::HitEffectTrack_145f90::FUN_00143220);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f80), params, 7);
    }
    DAT_004e0f84++;
}


// 0x00146190 FUN_00146190 (474 B): equivalent/0x00146190.cpp
// sym: ?FUN_00146190@fn_f7eb1b84@@YAXXZ @d7a0ee84e2c2 @weff765272159
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_00146190 @ 0x00146190
void FUN_00146190()
{
    if (DAT_004e0f94 == 0) {
        void* params[8];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<WorldDamageTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<WorldDamageTrack>("timeBegin", (void (WorldDamageTrack::*)())&WorldDamageTrack::FUN_001432e0);
        mem = FUN_0008d690((int)sizeof(ParamNameConstList<WorldDamageTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamNameConstList<WorldDamageTrack>("joint", &WorldDamageTrack::FUN_001432f0);
        mem = FUN_0008d690((int)sizeof(ParamVector<WorldDamageTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamVector<WorldDamageTrack>("position", (void (WorldDamageTrack::*)())&WorldDamageTrack::FUN_00143320);
        mem = FUN_0008d690((int)sizeof(ParamVector<WorldDamageTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<WorldDamageTrack>("direction", (void (WorldDamageTrack::*)())&WorldDamageTrack::FUN_00143360);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<WorldDamageTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<WorldDamageTrack>("distance", (void (WorldDamageTrack::*)())&WorldDamageTrack::FUN_00143390);
        mem = FUN_0008d690((int)sizeof(ParamEnumConstList<WorldDamageTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamEnumConstList<WorldDamageTrack>("damageType", ((char**)&DAT_004ad788), 7, (void (WorldDamageTrack::*)())&WorldDamageTrack::FUN_001433b0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<WorldDamageTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<WorldDamageTrack>("scaleX", (void (WorldDamageTrack::*)())&WorldDamageTrack::FUN_001433d0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<WorldDamageTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<WorldDamageTrack>("scaleY", (void (WorldDamageTrack::*)())&WorldDamageTrack::FUN_001433f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f90), params, 8);
    }
    DAT_004e0f94++;
}

} // namespace fn_f7eb1b84
