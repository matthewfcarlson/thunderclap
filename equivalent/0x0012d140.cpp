// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 16/16)
// FUN_0012d140 @ 0x0012d140
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/ai.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace ai {
class ThreatBallTrack {
public:
    void FUN_0012b280();
    void FUN_0012b290();
    void FUN_0012b2b0();
    void FUN_0012b2c0();
    void FUN_0012b2f0();
    void FUN_0012b320();
    void FUN_0012b330();
};
}
}

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

class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234ba0(const char* name);
    ParamNameConstListBase(const char* name) { FUN_00234ba0(name); }
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
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

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0012d140()
{
    if (DAT_004e0e38 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>("timeBegin", &hulkfight::ai::ThreatBallTrack::FUN_0012b280);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>("timeEnd", &hulkfight::ai::ThreatBallTrack::FUN_0012b290);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamIntConstRange<hulkfight::ai::ThreatBallTrack>("attachmentIndex", &hulkfight::ai::ThreatBallTrack::FUN_0012b2b0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamNameConstList<hulkfight::ai::ThreatBallTrack>("joint", &hulkfight::ai::ThreatBallTrack::FUN_0012b2c0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamVector<hulkfight::ai::ThreatBallTrack>("offset", &hulkfight::ai::ThreatBallTrack::FUN_0012b2f0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>("radius", &hulkfight::ai::ThreatBallTrack::FUN_0012b320);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamName<hulkfight::ai::ThreatBallTrack>("threatName", &hulkfight::ai::ThreatBallTrack::FUN_0012b330);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0e34), params, 7);
    }
    DAT_004e0e38++;
}
