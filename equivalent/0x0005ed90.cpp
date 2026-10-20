// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 18/18)
// FUN_0005ed90 @ 0x0005ed90
#include "compat/ptr.h"
#include "decls/data/game/global.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class CSnapToWallTrack {
public:
    void FUN_0005d850();
    void FUN_0005d860();
    void FUN_0005d870();
    void FUN_0005d890();
    void FUN_0005d8b0();
    void FUN_0005d8c0();
    void FUN_0005d8d0();
    void FUN_0005d8e0();
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

void FUN_0005ed90()
{
    if (DAT_004dc5f4 == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CSnapToWallTrack>("timeBegin", &CSnapToWallTrack::FUN_0005d850);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CSnapToWallTrack>("timeEnd", &CSnapToWallTrack::FUN_0005d860);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<CSnapToWallTrack>("orientation", &CSnapToWallTrack::FUN_0005d870);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<CSnapToWallTrack>("offset", &CSnapToWallTrack::FUN_0005d890);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<CSnapToWallTrack>("snapToGround", &CSnapToWallTrack::FUN_0005d8b0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamIntConstRange<CSnapToWallTrack>("priority", &CSnapToWallTrack::FUN_0005d8c0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<CSnapToWallTrack>("rootBlendInTime", &CSnapToWallTrack::FUN_0005d8d0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<CSnapToWallTrack>("rootBlendOutTime", &CSnapToWallTrack::FUN_0005d8e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5f0), params, 8);
    }
    DAT_004dc5f4++;
}
