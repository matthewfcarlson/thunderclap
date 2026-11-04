// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_0014b5d0 @ 0x0014b5d0
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class GrappleHitReactionTrack_14b5d0 {
public:
    void FUN_00146e30();
    void FUN_00146e50();
    void FUN_00146e70();
    void FUN_00146e90();
    void FUN_00146eb0();
    void FUN_00146ed0();
    void FUN_00146ef0();
    void FUN_00146f10();
    void FUN_00146f30();
    void FUN_00146f50();
    void FUN_00146f70();
    void FUN_00146f90();
    void FUN_00146fc0();
    void FUN_00146fe0();
    void FUN_00147000();
    void FUN_00147020();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamBool_14b5d0 : public ParamBoolBase {
public:
    ParamBool_14b5d0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_14b5d0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_14b5d0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_14b5d0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_14b5d0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_14b5d0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_14b5d0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_14b5d0 : public ParamNameBase {
public:
    ParamName_14b5d0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};




extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0014b5d0()
{
    if (DAT_004e1010 == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("timeBegin", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146e30);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("hitLocation", ((const char**)&DAT_0048f6cc), (*(int*)&DAT_003f5ed0), &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146e50);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("directionFrom", ((const char**)&DAT_004ae340), 2, &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146e70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("direction", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146e90);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("flag", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146eb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("damage", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146ed0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("damageMax", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146ef0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("interruptPriority", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f10);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("interrupt", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("hitReactionTime", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f50);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("pushbackDirectionFrom", ((const char**)&DAT_004ae340), 2, &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("pushbackDirection", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("pushbackDistance", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146fc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("pushbackTime", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146fe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("height", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00147000);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("stunTime", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00147020);
        FUN_002347b0(((ParamRegistry*)&DAT_004e100c), params, 16);
    }
    DAT_004e1010++;
}
