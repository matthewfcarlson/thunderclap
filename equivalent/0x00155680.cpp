// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_00155680 @ 0x00155680
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class CollisionSourceIsMissileCondition {
public:
    void FUN_0014c5a0();
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
extern ParamRegistry DAT_004e1078;
extern int DAT_004e107c;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00155680()
{
    if (DAT_004e107c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool<hulkfight::motion::CollisionSourceIsMissileCondition>("isMissile", &hulkfight::motion::CollisionSourceIsMissileCondition::FUN_0014c5a0);
        FUN_002347b0(&DAT_004e1078, params, 1);
    }
    DAT_004e107c++;
}
