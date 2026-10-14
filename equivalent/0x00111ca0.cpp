// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_00111ca0 @ 0x00111ca0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class DefendingCondition {
public:
    void FUN_0010c130();
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
extern ParamRegistry DAT_004e0af0;
extern int DAT_004e0af4;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00111ca0()
{
    if (DAT_004e0af4 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool<hulkfight::ai::DefendingCondition>("defending", &hulkfight::ai::DefendingCondition::FUN_0010c130);
        FUN_002347b0(&DAT_004e0af0, params, 1);
    }
    DAT_004e0af4++;
}
