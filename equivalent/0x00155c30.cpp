// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00155c30 @ 0x00155c30
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class InterruptAccumulatorSetTrack {
public:
    void FUN_0014c760();
    void FUN_0014c780();
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
extern ParamRegistry DAT_004e10d0;
extern int DAT_004e10d4;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00155c30()
{
    if (DAT_004e10d4 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>("timeBegin", &hulkfight::motion::InterruptAccumulatorSetTrack::FUN_0014c760);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>("value", &hulkfight::motion::InterruptAccumulatorSetTrack::FUN_0014c780);
        FUN_002347b0(&DAT_004e10d0, params, 2);
    }
    DAT_004e10d4++;
}
