// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 36/36)
// FUN_001582f0 @ 0x001582f0
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class HitReactionFloatTrack {
public:
    void FUN_0014c880();
    void FUN_0014c8a0();
    void FUN_0014c8c0();
    void FUN_0014c8e0();
    void FUN_0014c900();
    void FUN_0014c920();
    void FUN_0014c950();
    void FUN_0014c970();
    void FUN_0014c990();
    void FUN_0014c9b0();
    void FUN_0014c9d0();
    void FUN_0014c9f0();
    void FUN_0014ca10();
    void FUN_0014ca30();
    void FUN_0014ca50();
    void FUN_0014ca70();
    void FUN_0014ca90();
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

void FUN_001582f0()
{
    if (DAT_004e10e4 == 0) {
        void* params[17];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>("timeBegin", &hulkfight::motion::HitReactionFloatTrack::FUN_0014c880);
        mem = FUN_0008d690(0x20);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>("hitLocation", ((const char**)&DAT_0048f6cc), (*(int*)&DAT_003f5ed0), &hulkfight::motion::HitReactionFloatTrack::FUN_0014c8a0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>("direction", &hulkfight::motion::HitReactionFloatTrack::FUN_0014c8c0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName<hulkfight::motion::HitReactionFloatTrack>("flag", &hulkfight::motion::HitReactionFloatTrack::FUN_0014c8e0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamIntConstRange<hulkfight::motion::HitReactionFloatTrack>("interruptPriority", &hulkfight::motion::HitReactionFloatTrack::FUN_0014c900);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>("pushbackDirection", &hulkfight::motion::HitReactionFloatTrack::FUN_0014c920);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>("damageMin", &hulkfight::motion::HitReactionFloatTrack::FUN_0014c950);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>("damageMax", &hulkfight::motion::HitReactionFloatTrack::FUN_0014c970);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>("pushbackDistanceMin", &hulkfight::motion::HitReactionFloatTrack::FUN_0014c990);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>("pushbackDistanceMax", &hulkfight::motion::HitReactionFloatTrack::FUN_0014c9b0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>("pushbackTimeMin", &hulkfight::motion::HitReactionFloatTrack::FUN_0014c9d0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>("pushbackTimeMax", &hulkfight::motion::HitReactionFloatTrack::FUN_0014c9f0);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>("heightMin", &hulkfight::motion::HitReactionFloatTrack::FUN_0014ca10);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>("heightMax", &hulkfight::motion::HitReactionFloatTrack::FUN_0014ca30);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>("stunTimeMin", &hulkfight::motion::HitReactionFloatTrack::FUN_0014ca50);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>("stunTimeMax", &hulkfight::motion::HitReactionFloatTrack::FUN_0014ca70);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBool<hulkfight::motion::HitReactionFloatTrack>("ignoreHitRecord", &hulkfight::motion::HitReactionFloatTrack::FUN_0014ca90);
        FUN_002347b0(((ParamRegistry*)&DAT_004e10e0), params, 17);
    }
    DAT_004e10e4++;
}
