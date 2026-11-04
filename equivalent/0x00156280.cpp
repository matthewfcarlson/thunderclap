// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_00156280 @ 0x00156280
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class HitFloatTrack_156280 {
public:
    void FUN_0014cdd0();
    void FUN_0014cde0();
    void FUN_0014ce00();
    void FUN_0014ce20();
    void FUN_0014ce50();
    void FUN_0014ce70();
    void FUN_0014ce90();
};
}
}

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

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00156280()
{
    if (DAT_004e1114 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>("timeBegin", &hulkfight::motion::HitFloatTrack_156280::FUN_0014cdd0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>("timeEnd", &hulkfight::motion::HitFloatTrack_156280::FUN_0014cde0);
        mem = FUN_0008d690((int)sizeof(ParamBool<hulkfight::motion::HitFloatTrack_156280>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<hulkfight::motion::HitFloatTrack_156280>("snapToPushback", &hulkfight::motion::HitFloatTrack_156280::FUN_0014ce00);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>("orientation", &hulkfight::motion::HitFloatTrack_156280::FUN_0014ce20);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<hulkfight::motion::HitFloatTrack_156280>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamIntConstRange<hulkfight::motion::HitFloatTrack_156280>("priority", &hulkfight::motion::HitFloatTrack_156280::FUN_0014ce50);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>("blendInTime", &hulkfight::motion::HitFloatTrack_156280::FUN_0014ce70);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack_156280>("blendOutTime", &hulkfight::motion::HitFloatTrack_156280::FUN_0014ce90);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1110), params, 7);
    }
    DAT_004e1114++;
}
