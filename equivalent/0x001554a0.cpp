// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_001554a0 @ 0x001554a0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class CollisionDevastatorCondition {
public:
    void FUN_0014c540();
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
extern ParamRegistry DAT_004e1058;
extern int DAT_004e105c;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001554a0()
{
    if (DAT_004e105c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool<hulkfight::motion::CollisionDevastatorCondition>("isDevastator", &hulkfight::motion::CollisionDevastatorCondition::FUN_0014c540);
        FUN_002347b0(&DAT_004e1058, params, 1);
    }
    DAT_004e105c++;
}
