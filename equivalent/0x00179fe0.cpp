// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 16/16)
// FUN_00179fe0 @ 0x00179fe0
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class DriftToPositionTrack {
public:
    void FUN_0016f090();
    void FUN_0016f0a0();
    void FUN_0016f0c0();
    void FUN_0016f0f0();
    void FUN_0016f120();
    void FUN_0016f140();
    void FUN_00170480();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
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
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
template <class T>
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00179fe0()
{
    if (DAT_004e1334 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<DriftToPositionTrack>("timeBegin", &DriftToPositionTrack::FUN_0016f090);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<DriftToPositionTrack>("timeEnd", &DriftToPositionTrack::FUN_0016f0a0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<DriftToPositionTrack>("letMeSpecifyPosition", &DriftToPositionTrack::FUN_0016f0c0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<DriftToPositionTrack>("position", &DriftToPositionTrack::FUN_0016f0f0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<DriftToPositionTrack>("ditchYIfInDefaultMode", &DriftToPositionTrack::FUN_0016f120);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<DriftToPositionTrack>("teleportAtEnd", &DriftToPositionTrack::FUN_0016f140);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamString<DriftToPositionTrack>("variable", &DriftToPositionTrack::FUN_00170480);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1330), params, 7);
    }
    DAT_004e1334++;
}
