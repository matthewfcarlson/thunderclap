// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 22/22)
// FUN_0013ce00 @ 0x0013ce00
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class AnimationPhaseMatchedTrack {
public:
    void FUN_00139d70();
    void FUN_00139d80();
    void FUN_00139d90();
    void FUN_00139db0();
    void FUN_00139dd0();
    void FUN_00139df0();
    void FUN_00139e00();
    void FUN_00139e20();
    void FUN_00139e40();
    void FUN_00139e60();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
namespace fight {
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
extern ParamRegistry DAT_004e0f30;
extern int DAT_004e0f34;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0013ce00()
{
    if (DAT_004e0f34 == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<AnimationPhaseMatchedTrack>("timeBegin", &AnimationPhaseMatchedTrack::FUN_00139d70);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<AnimationPhaseMatchedTrack>("timeEnd", &AnimationPhaseMatchedTrack::FUN_00139d80);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName<AnimationPhaseMatchedTrack>("animation", &AnimationPhaseMatchedTrack::FUN_00139d90);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<AnimationPhaseMatchedTrack>("syncFrame", &AnimationPhaseMatchedTrack::FUN_00139db0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<AnimationPhaseMatchedTrack>("startFrame", &AnimationPhaseMatchedTrack::FUN_00139dd0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<AnimationPhaseMatchedTrack>("endFrame", &AnimationPhaseMatchedTrack::FUN_00139df0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamName<AnimationPhaseMatchedTrack>("partition", &AnimationPhaseMatchedTrack::FUN_00139e00);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange<AnimationPhaseMatchedTrack>("priority", &AnimationPhaseMatchedTrack::FUN_00139e20);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<AnimationPhaseMatchedTrack>("blendInTime", &AnimationPhaseMatchedTrack::FUN_00139e40);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<AnimationPhaseMatchedTrack>("blendOutTime", &AnimationPhaseMatchedTrack::FUN_00139e60);
        FUN_002347b0(&DAT_004e0f30, params, 10);
    }
    DAT_004e0f34++;
}
