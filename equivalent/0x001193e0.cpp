// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001193e0 @ 0x001193e0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class MotionStopTrack {
public:
    void FUN_00115110();
    void FUN_00115120();
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
extern ParamRegistry DAT_004e0c4c;
extern int DAT_004e0c50;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001193e0()
{
    if (DAT_004e0c50 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::MotionStopTrack>("timeBegin", &hulkfight::ai::MotionStopTrack::FUN_00115110);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::MotionStopTrack>("timeEnd", &hulkfight::ai::MotionStopTrack::FUN_00115120);
        FUN_002347b0(&DAT_004e0c4c, params, 2);
    }
    DAT_004e0c50++;
}
