// STATUS: equivalent (tools/equiv.py level 3: 1961 inputs, branch coverage 54/54)
// FUN_000612e0 @ 0x000612e0
#include "compat/ptr.h"
#include "decls/data/game/global.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class CMotionTrailTrack {
public:
    void FUN_00060210();
    void FUN_00060220();
    void FUN_00060230();
    void FUN_00060240();
    void FUN_00012c40();
    void FUN_00060b10();
    void FUN_00060250();
    void FUN_000602b0();
    void FUN_00060260();
    void FUN_000602d0();
    void FUN_00060270();
    void FUN_000602f0();
    void FUN_00060280();
    void FUN_00060310();
    void FUN_00060290();
    void FUN_00060340();
    void FUN_000602a0();
    void FUN_00060370();
    void FUN_00012c80();
    void FUN_000603a0();
    void FUN_000603d0();
    void FUN_000603e0();
    void FUN_000603f0();
    void FUN_00060400();
    void FUN_00060410();
    void FUN_00060420();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
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
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234ba0(const char* name);
    ParamNameConstListBase(const char* name) { FUN_00234ba0(name); }
};
class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_000612e0()
{
    if (DAT_004dc604 == 0) {
        void* params[26];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<::CMotionTrailTrack>("timeBegin", &::CMotionTrailTrack::FUN_00060210);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<::CMotionTrailTrack>("timeEnd", &::CMotionTrailTrack::FUN_00060220);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<::CMotionTrailTrack>("generateTime", &::CMotionTrailTrack::FUN_00060230);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<::CMotionTrailTrack>("fadeOutTime", &::CMotionTrailTrack::FUN_00060240);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName<::CMotionTrailTrack>("shader", &::CMotionTrailTrack::FUN_00012c40);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange<::CMotionTrailTrack>("numJoints", &::CMotionTrailTrack::FUN_00060b10);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamNameConstList<::CMotionTrailTrack>("joint1", &::CMotionTrailTrack::FUN_00060250);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector<::CMotionTrailTrack>("jointOffset1", &::CMotionTrailTrack::FUN_000602b0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamNameConstList<::CMotionTrailTrack>("joint2", &::CMotionTrailTrack::FUN_00060260);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamVector<::CMotionTrailTrack>("jointOffset2", &::CMotionTrailTrack::FUN_000602d0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamNameConstList<::CMotionTrailTrack>("joint3", &::CMotionTrailTrack::FUN_00060270);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamVector<::CMotionTrailTrack>("jointOffset3", &::CMotionTrailTrack::FUN_000602f0);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamNameConstList<::CMotionTrailTrack>("joint4", &::CMotionTrailTrack::FUN_00060280);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamVector<::CMotionTrailTrack>("jointOffset4", &::CMotionTrailTrack::FUN_00060310);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamNameConstList<::CMotionTrailTrack>("joint5", &::CMotionTrailTrack::FUN_00060290);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamVector<::CMotionTrailTrack>("jointOffset5", &::CMotionTrailTrack::FUN_00060340);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamNameConstList<::CMotionTrailTrack>("joint6", &::CMotionTrailTrack::FUN_000602a0);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamVector<::CMotionTrailTrack>("jointOffset6", &::CMotionTrailTrack::FUN_00060370);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamNameConstList<::CMotionTrailTrack>("shrinkJoint", &::CMotionTrailTrack::FUN_00012c80);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamVector<::CMotionTrailTrack>("shrinkOffset", &::CMotionTrailTrack::FUN_000603a0);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange<::CMotionTrailTrack>("shrinkTime", &::CMotionTrailTrack::FUN_000603d0);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamFloatConstRange<::CMotionTrailTrack>("fadeTime", &::CMotionTrailTrack::FUN_000603e0);
        mem = FUN_0008d690(0x18);
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamFloatConstRange<::CMotionTrailTrack>("textureTime", &::CMotionTrailTrack::FUN_000603f0);
        mem = FUN_0008d690(0x18);
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamBool<::CMotionTrailTrack>("abortWhenInterrupted", &::CMotionTrailTrack::FUN_00060400);
        mem = FUN_0008d690(0x18);
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamBool<::CMotionTrailTrack>("runTillStop", &::CMotionTrailTrack::FUN_00060410);
        mem = FUN_0008d690(0x18);
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamIntConstRange<::CMotionTrailTrack>("slot", &::CMotionTrailTrack::FUN_00060420);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc600), params, 26);
    }
    DAT_004dc604++;
}
