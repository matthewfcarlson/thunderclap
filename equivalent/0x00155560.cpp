// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00155560 @ 0x00155560
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class CollisionTargetIsTargetCondition {
public:
    void FUN_0014c570();
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
extern ParamRegistry DAT_004e1068;
extern int DAT_004e106c;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00155560()
{
    if (DAT_004e106c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool<hulkfight::motion::CollisionTargetIsTargetCondition>("isTarget", &hulkfight::motion::CollisionTargetIsTargetCondition::FUN_0014c570);
        FUN_002347b0(&DAT_004e1068, params, 1);
    }
    DAT_004e106c++;
}
