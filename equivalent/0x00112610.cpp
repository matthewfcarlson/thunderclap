// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00112610 @ 0x00112610
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight { namespace ai {
class FightingOtherNPCCondition {
public:
    void FUN_0010c3a0();
};
} }

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00112610()
{
    if (DAT_004e0b5c == 0) {
        void* params[1];
        void* mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::FightingOtherNPCCondition::FUN_0010c3a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0b58), params, 1);
    }
    DAT_004e0b5c++;
}
