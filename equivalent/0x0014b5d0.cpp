// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_0014b5d0 @ 0x0014b5d0
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class GrappleHitReactionTrack {
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
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
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
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
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
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
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
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};




void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0014b5d0()
{
    if (DAT_004e1010 == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>("timeBegin", &hulkfight::motion::GrappleHitReactionTrack::FUN_00146e30);
        mem = FUN_0008d690(0x20);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>("hitLocation", ((const char**)&DAT_0048f6cc), (*(int*)&DAT_003f5ed0), &hulkfight::motion::GrappleHitReactionTrack::FUN_00146e50);
        mem = FUN_0008d690(0x20);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>("directionFrom", ((const char**)&DAT_004ae340), 2, &hulkfight::motion::GrappleHitReactionTrack::FUN_00146e70);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>("direction", &hulkfight::motion::GrappleHitReactionTrack::FUN_00146e90);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName<hulkfight::motion::GrappleHitReactionTrack>("flag", &hulkfight::motion::GrappleHitReactionTrack::FUN_00146eb0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>("damage", &hulkfight::motion::GrappleHitReactionTrack::FUN_00146ed0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>("damageMax", &hulkfight::motion::GrappleHitReactionTrack::FUN_00146ef0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange<hulkfight::motion::GrappleHitReactionTrack>("interruptPriority", &hulkfight::motion::GrappleHitReactionTrack::FUN_00146f10);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool<hulkfight::motion::GrappleHitReactionTrack>("interrupt", &hulkfight::motion::GrappleHitReactionTrack::FUN_00146f30);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>("hitReactionTime", &hulkfight::motion::GrappleHitReactionTrack::FUN_00146f50);
        mem = FUN_0008d690(0x20);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamEnumConstList<hulkfight::motion::GrappleHitReactionTrack>("pushbackDirectionFrom", ((const char**)&DAT_004ae340), 2, &hulkfight::motion::GrappleHitReactionTrack::FUN_00146f70);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>("pushbackDirection", &hulkfight::motion::GrappleHitReactionTrack::FUN_00146f90);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>("pushbackDistance", &hulkfight::motion::GrappleHitReactionTrack::FUN_00146fc0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>("pushbackTime", &hulkfight::motion::GrappleHitReactionTrack::FUN_00146fe0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>("height", &hulkfight::motion::GrappleHitReactionTrack::FUN_00147000);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::GrappleHitReactionTrack>("stunTime", &hulkfight::motion::GrappleHitReactionTrack::FUN_00147020);
        FUN_002347b0(((ParamRegistry*)&DAT_004e100c), params, 16);
    }
    DAT_004e1010++;
}
