// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 18/18)
// FUN_0005ed90 @ 0x0005ed90
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class CSnapToWallTrack_5ed90 {
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
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0005ed90()
{
    if (DAT_004dc5f4 == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CSnapToWallTrack_5ed90>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CSnapToWallTrack_5ed90>("timeBegin", &CSnapToWallTrack_5ed90::FUN_0005d850);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CSnapToWallTrack_5ed90>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CSnapToWallTrack_5ed90>("timeEnd", &CSnapToWallTrack_5ed90::FUN_0005d860);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CSnapToWallTrack_5ed90>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<CSnapToWallTrack_5ed90>("orientation", &CSnapToWallTrack_5ed90::FUN_0005d870);
        mem = FUN_0008d690((int)sizeof(ParamVector<CSnapToWallTrack_5ed90>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<CSnapToWallTrack_5ed90>("offset", &CSnapToWallTrack_5ed90::FUN_0005d890);
        mem = FUN_0008d690((int)sizeof(ParamBool<CSnapToWallTrack_5ed90>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<CSnapToWallTrack_5ed90>("snapToGround", &CSnapToWallTrack_5ed90::FUN_0005d8b0);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<CSnapToWallTrack_5ed90>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamIntConstRange<CSnapToWallTrack_5ed90>("priority", &CSnapToWallTrack_5ed90::FUN_0005d8c0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CSnapToWallTrack_5ed90>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<CSnapToWallTrack_5ed90>("rootBlendInTime", &CSnapToWallTrack_5ed90::FUN_0005d8d0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CSnapToWallTrack_5ed90>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<CSnapToWallTrack_5ed90>("rootBlendOutTime", &CSnapToWallTrack_5ed90::FUN_0005d8e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5f0), params, 8);
    }
    DAT_004dc5f4++;
}
