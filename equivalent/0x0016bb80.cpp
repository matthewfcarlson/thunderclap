// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_0016bb80 @ 0x0016bb80
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class VelocityAnimatedXZAngleCondition {
public:
    void FUN_00165900();
    void FUN_00165920();
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
extern ParamRegistry DAT_004e1290;
extern int DAT_004e1294;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0016bb80()
{
    if (DAT_004e1294 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZAngleCondition>("angle", &hulkfight::motion::VelocityAnimatedXZAngleCondition::FUN_00165900);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZAngleCondition>("arc", &hulkfight::motion::VelocityAnimatedXZAngleCondition::FUN_00165920);
        FUN_002347b0(&DAT_004e1290, params, 2);
    }
    DAT_004e1294++;
}
