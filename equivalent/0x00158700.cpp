// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 30/30)
// FUN_00158700 @ 0x00158700
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class HitReactionTrack {
public:
    void FUN_0014caf0();
    void FUN_0014cb10();
    void FUN_0014cb30();
    void FUN_0014cb50();
    void FUN_0014cb70();
    void FUN_0014cb90();
    void FUN_0014cbb0();
    void FUN_0014cbd0();
    void FUN_0014cbf0();
    void FUN_0014cc20();
    void FUN_0014cc40();
    void FUN_0014cc60();
    void FUN_0014cc80();
    void FUN_0014cca0();
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

void FUN_00158700()
{
    if (DAT_004e10f4 == 0) {
        void* params[14];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>("timeBegin", &hulkfight::motion::HitReactionTrack::FUN_0014caf0);
        mem = FUN_0008d690(0x20);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>("hitLocation", ((const char**)&DAT_0048f6cc), (*(int*)&DAT_003f5ed0), &hulkfight::motion::HitReactionTrack::FUN_0014cb10);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>("direction", &hulkfight::motion::HitReactionTrack::FUN_0014cb30);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName<hulkfight::motion::HitReactionTrack>("flag", &hulkfight::motion::HitReactionTrack::FUN_0014cb50);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>("damage", &hulkfight::motion::HitReactionTrack::FUN_0014cb70);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange<hulkfight::motion::HitReactionTrack>("interruptPriority", &hulkfight::motion::HitReactionTrack::FUN_0014cb90);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool<hulkfight::motion::HitReactionTrack>("interrupt", &hulkfight::motion::HitReactionTrack::FUN_0014cbb0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>("hitReactionTime", &hulkfight::motion::HitReactionTrack::FUN_0014cbd0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>("pushbackDirection", &hulkfight::motion::HitReactionTrack::FUN_0014cbf0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>("pushbackDistance", &hulkfight::motion::HitReactionTrack::FUN_0014cc20);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>("pushbackTime", &hulkfight::motion::HitReactionTrack::FUN_0014cc40);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>("height", &hulkfight::motion::HitReactionTrack::FUN_0014cc60);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>("stunTime", &hulkfight::motion::HitReactionTrack::FUN_0014cc80);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamBool<hulkfight::motion::HitReactionTrack>("ignoreHitRecord", &hulkfight::motion::HitReactionTrack::FUN_0014cca0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e10f0), params, 14);
    }
    DAT_004e10f4++;
}
