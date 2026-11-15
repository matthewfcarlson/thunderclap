// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00136dc0..0x00139940 (kind game, layer game, confidence high), dominant class hulkfight::motion::FallTrack
#include "tree_prelude.h"


// 0x00138910 FUN_00138910 (613 B): equivalent/0x00138910.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called; on include/gen/ and not mergeable]
// sym: _FUN_00138910 @51894e627289 @wa1ce9eb28c69
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 24/24)
// FUN_00138910 @ 0x00138910
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(size_t, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class FlyingAttackTrack {
public:
    bool FUN_001337f0(int); /* (unb4) as defined; address taken only */
    char FUN_00133800(int); /* (unb4) as defined; address taken only */
    bool FUN_00133830(void*); /* (unb4) as defined; address taken only */
    char FUN_00133860(int); /* (unb4) as defined; address taken only */
    char FUN_00133880(int); /* (unb4) as defined; address taken only */
    char FUN_001338a0(int); /* (unb4) as defined; address taken only */
    char FUN_001338c0(float); /* (unb4) as defined; address taken only */
    char FUN_001338f0(char); /* (unb4) as defined; address taken only */
    bool FUN_00133910(int); /* (unb4) as defined; address taken only */
    char FUN_00133930(int); /* (unb4) as defined; address taken only */
    char FUN_00133950(int); /* (unb4) as defined; address taken only */
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_138910 : public ParamBoolBase {
public:
    ParamBool_138910(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_138910 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_138910(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamIntConstRange_138910 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_138910(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
template <class T>
class ParamVector_138910 : public ParamVectorBase {
public:
    ParamVector_138910(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00138910()
{
    if (DAT_004e0f04 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_138910<FlyingAttackTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_138910<FlyingAttackTrack>("timeBegin", (void (FlyingAttackTrack::*)())&FlyingAttackTrack::FUN_001337f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_138910<FlyingAttackTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_138910<FlyingAttackTrack>("timeEnd", (void (FlyingAttackTrack::*)())&FlyingAttackTrack::FUN_00133800);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_138910<FlyingAttackTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamVector_138910<FlyingAttackTrack>("direction", (void (FlyingAttackTrack::*)())&FlyingAttackTrack::FUN_00133830);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_138910<FlyingAttackTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_138910<FlyingAttackTrack>("velocity", (void (FlyingAttackTrack::*)())&FlyingAttackTrack::FUN_00133860);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_138910<FlyingAttackTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_138910<FlyingAttackTrack>("acceleration", (void (FlyingAttackTrack::*)())&FlyingAttackTrack::FUN_00133880);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_138910<FlyingAttackTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_138910<FlyingAttackTrack>("heightMin", (void (FlyingAttackTrack::*)())&FlyingAttackTrack::FUN_001338a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_138910<FlyingAttackTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_138910<FlyingAttackTrack>("tracking", (void (FlyingAttackTrack::*)())&FlyingAttackTrack::FUN_001338c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_138910<FlyingAttackTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool_138910<FlyingAttackTrack>("faceDirection", (void (FlyingAttackTrack::*)())&FlyingAttackTrack::FUN_001338f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_138910<FlyingAttackTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_138910<FlyingAttackTrack>("priority", (void (FlyingAttackTrack::*)())&FlyingAttackTrack::FUN_00133910);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_138910<FlyingAttackTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_138910<FlyingAttackTrack>("blendInTime", (void (FlyingAttackTrack::*)())&FlyingAttackTrack::FUN_00133930);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_138910<FlyingAttackTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_138910<FlyingAttackTrack>("blendOutTime", (void (FlyingAttackTrack::*)())&FlyingAttackTrack::FUN_00133950);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f00), params, 11);
    }
    DAT_004e0f04++;
}

