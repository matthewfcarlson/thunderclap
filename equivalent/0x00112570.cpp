// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00112570 @ 0x00112570
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class TokenCondition {
public:
    void FUN_0010c370();
    void FUN_0010c390();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
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
}

struct ParamRegistry {
};
extern ParamRegistry DAT_004e0b50;
extern int DAT_004e0b54;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00112570()
{
    if (DAT_004e0b54 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool<hulkfight::ai::TokenCondition>("oRNoOneHas", &hulkfight::ai::TokenCondition::FUN_0010c370);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool<hulkfight::ai::TokenCondition>("have", &hulkfight::ai::TokenCondition::FUN_0010c390);
        FUN_002347b0(&DAT_004e0b50, params, 2);
    }
    DAT_004e0b54++;
}
