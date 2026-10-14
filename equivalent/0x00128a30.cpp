// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00128a30 @ 0x00128a30
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class TargetOrientationCondition {
public:
    void FUN_00123740();
    void FUN_00123760();
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
extern ParamRegistry DAT_004e0d9c;
extern int DAT_004e0da0;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00128a30()
{
    if (DAT_004e0da0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::TargetOrientationCondition>("orientation", &hulkfight::ai::TargetOrientationCondition::FUN_00123740);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::TargetOrientationCondition>("arc", &hulkfight::ai::TargetOrientationCondition::FUN_00123760);
        FUN_002347b0(&DAT_004e0d9c, params, 2);
    }
    DAT_004e0da0++;
}
