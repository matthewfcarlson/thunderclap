// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 16/16)
// FUN_00121690 @ 0x00121690
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class StrafeCircleHBTrack {
public:
    void FUN_0011bde0();
    void FUN_0011bdf0();
    void FUN_0011be10();
    void FUN_0011be30();
    void FUN_0011be50();
    void FUN_0011be70();
    void FUN_0011be90();
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

struct ParamRegistry {
};
extern ParamRegistry DAT_004e0cd0;
extern int DAT_004e0cd4;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00121690()
{
    if (DAT_004e0cd4 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>("timeBegin", &hulkfight::ai::StrafeCircleHBTrack::FUN_0011bde0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>("timeEnd", &hulkfight::ai::StrafeCircleHBTrack::FUN_0011bdf0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>("distanceMin", &hulkfight::ai::StrafeCircleHBTrack::FUN_0011be10);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>("distanceMax", &hulkfight::ai::StrafeCircleHBTrack::FUN_0011be30);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>("heightMin", &hulkfight::ai::StrafeCircleHBTrack::FUN_0011be50);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>("heightMax", &hulkfight::ai::StrafeCircleHBTrack::FUN_0011be70);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>("speed", &hulkfight::ai::StrafeCircleHBTrack::FUN_0011be90);
        FUN_002347b0(&DAT_004e0cd0, params, 7);
    }
    DAT_004e0cd4++;
}
