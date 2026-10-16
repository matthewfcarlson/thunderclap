// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 14/14)
// FUN_001127d0 @ 0x001127d0
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class TokenSupressTrack {
public:
    void FUN_0010c420();
    void FUN_0010c430();
    void FUN_0010c450();
    void FUN_0010c470();
    void FUN_0010c490();
    void FUN_0010c4b0();
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

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001127d0()
{
    if (DAT_004e0b6c == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<TokenSupressTrack>("timeBegin", &TokenSupressTrack::FUN_0010c420);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<TokenSupressTrack>("timeEnd", &TokenSupressTrack::FUN_0010c430);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<TokenSupressTrack>("supressEveryFrame", &TokenSupressTrack::FUN_0010c450);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<TokenSupressTrack>("floatDelayDuration", &TokenSupressTrack::FUN_0010c470);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<TokenSupressTrack>("floatDelayDurationPermenant", &TokenSupressTrack::FUN_0010c490);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<TokenSupressTrack>("floatDelayEndOnTrackFinish", &TokenSupressTrack::FUN_0010c4b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b68), params, 6);
    }
    DAT_004e0b6c++;
}
