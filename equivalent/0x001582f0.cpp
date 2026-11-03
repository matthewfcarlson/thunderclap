// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 36/36)
// FUN_001582f0 @ 0x001582f0
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class HitReactionFloatTrack_1582f0 {
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
class ParamBool_1582f0 : public ParamBoolBase {
public:
    ParamBool_1582f0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_1582f0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1582f0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_1582f0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1582f0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_1582f0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_1582f0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_1582f0 : public ParamNameBase {
public:
    ParamName_1582f0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_001582f0()
{
    if (DAT_004e10e4 == 0) {
        void* params[17];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("timeBegin", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c880);
        mem = FUN_0008d690(0x20);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("hitLocation", ((const char**)&DAT_0048f6cc), (*(int*)&DAT_003f5ed0), &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c8a0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("direction", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c8c0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("flag", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c8e0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamIntConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("interruptPriority", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c900);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("pushbackDirection", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c920);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("damageMin", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c950);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("damageMax", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c970);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("pushbackDistanceMin", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c990);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("pushbackDistanceMax", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c9b0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("pushbackTimeMin", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c9d0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("pushbackTimeMax", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c9f0);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("heightMin", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014ca10);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("heightMax", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014ca30);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("stunTimeMin", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014ca50);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("stunTimeMax", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014ca70);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBool_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("ignoreHitRecord", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014ca90);
        FUN_002347b0(((ParamRegistry*)&DAT_004e10e0), params, 17);
    }
    DAT_004e10e4++;
}
