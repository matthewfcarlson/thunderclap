// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 30/30)
// FUN_00158700 @ 0x00158700
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class HitReactionTrack_158700 {
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
class ParamBool_158700 : public ParamBoolBase {
public:
    ParamBool_158700(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_158700 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_158700(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_158700 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_158700(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_158700 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_158700(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_158700 : public ParamNameBase {
public:
    ParamName_158700(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00158700()
{
    if (DAT_004e10f4 == 0) {
        void* params[14];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("timeBegin", &hulkfight::motion::HitReactionTrack_158700::FUN_0014caf0);
        mem = FUN_0008d690(0x20);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_158700<hulkfight::motion::HitReactionTrack_158700>("hitLocation", ((const char**)&DAT_0048f6cc), (*(int*)&DAT_003f5ed0), &hulkfight::motion::HitReactionTrack_158700::FUN_0014cb10);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("direction", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cb30);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName_158700<hulkfight::motion::HitReactionTrack_158700>("flag", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cb50);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("damage", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cb70);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("interruptPriority", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cb90);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_158700<hulkfight::motion::HitReactionTrack_158700>("interrupt", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cbb0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("hitReactionTime", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cbd0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("pushbackDirection", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cbf0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("pushbackDistance", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cc20);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("pushbackTime", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cc40);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("height", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cc60);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("stunTime", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cc80);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamBool_158700<hulkfight::motion::HitReactionTrack_158700>("ignoreHitRecord", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cca0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e10f0), params, 14);
    }
    DAT_004e10f4++;
}
