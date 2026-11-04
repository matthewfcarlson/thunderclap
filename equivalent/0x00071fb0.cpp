// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 18/18)
// FUN_00071fb0 @ 0x00071fb0
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class COrientTrack_71fb0 {
public:
    void FUN_00068850();
    void FUN_00068860();
    void FUN_00068870();
    void FUN_00068890();
    void FUN_000688b0();
    void FUN_000688c0();
    void FUN_000688d0();
    void FUN_000688e0();
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

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00071fb0()
{
    if (DAT_004dcfc4 == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COrientTrack_71fb0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<COrientTrack_71fb0>("timeBegin", &COrientTrack_71fb0::FUN_00068850);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COrientTrack_71fb0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<COrientTrack_71fb0>("timeEnd", &COrientTrack_71fb0::FUN_00068860);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COrientTrack_71fb0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<COrientTrack_71fb0>("turningVelocity", &COrientTrack_71fb0::FUN_00068870);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COrientTrack_71fb0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<COrientTrack_71fb0>("offset", &COrientTrack_71fb0::FUN_00068890);
        mem = FUN_0008d690((int)sizeof(ParamBool<COrientTrack_71fb0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<COrientTrack_71fb0>("steering", &COrientTrack_71fb0::FUN_000688b0);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<COrientTrack_71fb0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamIntConstRange<COrientTrack_71fb0>("priority", &COrientTrack_71fb0::FUN_000688c0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COrientTrack_71fb0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<COrientTrack_71fb0>("blendInTime", &COrientTrack_71fb0::FUN_000688d0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COrientTrack_71fb0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<COrientTrack_71fb0>("blendOutTime", &COrientTrack_71fb0::FUN_000688e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcfc0), params, 8);
    }
    DAT_004dcfc4++;
}
