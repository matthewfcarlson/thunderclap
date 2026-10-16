// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 46/46)
// FUN_00074d90 @ 0x00074d90
#include "decls/data/game/global.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CKeyPoseTrack {
public:
    void FUN_00011e20();
    void FUN_0006b310();
    void FUN_0006b320();
    void FUN_0006b330();
    void FUN_0006b340();
    void FUN_0006b350();
    void FUN_0006b360();
    void FUN_0006b370();
    void FUN_0006b380();
    void FUN_0006b390();
    void FUN_0006b3a0();
    void FUN_0006b3b0();
    void FUN_0006b3c0();
    void FUN_0006b3d0();
    void FUN_0006b3e0();
    void FUN_0006b3f0();
    void FUN_0006b400();
    void FUN_00068210();
    void FUN_00011e40();
    void FUN_00068220();
    void FUN_00068230();
    void FUN_00068240();
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
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00074d90()
{
    if (DAT_004dcf34 == 0) {
        void* params[22];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName<::CKeyPoseTrack>("animation", &::CKeyPoseTrack::FUN_00011e20);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("key0", &::CKeyPoseTrack::FUN_0006b310);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("map0", &::CKeyPoseTrack::FUN_0006b320);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("key1", &::CKeyPoseTrack::FUN_0006b330);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("map1", &::CKeyPoseTrack::FUN_0006b340);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("key2", &::CKeyPoseTrack::FUN_0006b350);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("map2", &::CKeyPoseTrack::FUN_0006b360);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("key3", &::CKeyPoseTrack::FUN_0006b370);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("map3", &::CKeyPoseTrack::FUN_0006b380);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("key4", &::CKeyPoseTrack::FUN_0006b390);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("map4", &::CKeyPoseTrack::FUN_0006b3a0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("key5", &::CKeyPoseTrack::FUN_0006b3b0);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("map5", &::CKeyPoseTrack::FUN_0006b3c0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("key6", &::CKeyPoseTrack::FUN_0006b3d0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("map6", &::CKeyPoseTrack::FUN_0006b3e0);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("key7", &::CKeyPoseTrack::FUN_0006b3f0);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("map7", &::CKeyPoseTrack::FUN_0006b400);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamBool<::CKeyPoseTrack>("rootMotion", &::CKeyPoseTrack::FUN_00068210);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamName<::CKeyPoseTrack>("partition", &::CKeyPoseTrack::FUN_00011e40);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamIntConstRange<::CKeyPoseTrack>("priority", &::CKeyPoseTrack::FUN_00068220);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("blendInTime", &::CKeyPoseTrack::FUN_00068230);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamFloatConstRange<::CKeyPoseTrack>("blendOutTime", &::CKeyPoseTrack::FUN_00068240);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf30), params, 22);
    }
    DAT_004dcf34++;
}
