// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 12/12)
// FUN_00119790 @ 0x00119790
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/ai.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class MotionTargetTrack {
public:
    void FUN_001153e0();
    void FUN_001153f0();
    void FUN_00115410();
    void FUN_00115450();
    void FUN_00115480();
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

void FUN_00119790()
{
    if (DAT_004e0c70 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<MotionTargetTrack>("timeBegin", &MotionTargetTrack::FUN_001153e0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<MotionTargetTrack>("timeEnd", &MotionTargetTrack::FUN_001153f0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<MotionTargetTrack>("angle", &MotionTargetTrack::FUN_00115410);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<MotionTargetTrack>("vector", &MotionTargetTrack::FUN_00115450);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<MotionTargetTrack>("speed", &MotionTargetTrack::FUN_00115480);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c6c), params, 5);
    }
    DAT_004e0c70++;
}
