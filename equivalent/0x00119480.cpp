// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 12/12)
// FUN_00119480 @ 0x00119480
#include "decls/data/game/hulkfight/ai.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class MotionFacingTrack {
public:
    void FUN_00115130();
    void FUN_00115140();
    void FUN_00115160();
    void FUN_001151a0();
    void FUN_001151d0();
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

void FUN_00119480()
{
    if (DAT_004e0c58 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<MotionFacingTrack>("timeBegin", &MotionFacingTrack::FUN_00115130);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<MotionFacingTrack>("timeEnd", &MotionFacingTrack::FUN_00115140);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<MotionFacingTrack>("angle", &MotionFacingTrack::FUN_00115160);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<MotionFacingTrack>("vector", &MotionFacingTrack::FUN_001151a0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<MotionFacingTrack>("speed", &MotionFacingTrack::FUN_001151d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c54), params, 5);
    }
    DAT_004e0c58++;
}
