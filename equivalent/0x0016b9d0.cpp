// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_0016b9d0 @ 0x0016b9d0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class VelocityXZAngleCondition {
public:
    void FUN_00165780();
    void FUN_001657a0();
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
extern ParamRegistry DAT_004e1270;
extern int DAT_004e1274;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0016b9d0()
{
    if (DAT_004e1274 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::VelocityXZAngleCondition>("angle", &hulkfight::motion::VelocityXZAngleCondition::FUN_00165780);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::VelocityXZAngleCondition>("arc", &hulkfight::motion::VelocityXZAngleCondition::FUN_001657a0);
        FUN_002347b0(&DAT_004e1270, params, 2);
    }
    DAT_004e1274++;
}
