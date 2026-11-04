// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_00111c40 @ 0x00111c40
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class AIFightNodeCondition_111c40 {
public:
    void FUN_0010c120();
};
}
}

class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
};
namespace fight {
template <class T>
class ParamBranch_111c40 : public ParamBranchBase {
public:
    ParamBranch_111c40(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00111c40()
{
    if (DAT_004e0aec == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_111c40<hulkfight::ai::AIFightNodeCondition_111c40>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBranch_111c40<hulkfight::ai::AIFightNodeCondition_111c40>("branch", &hulkfight::ai::AIFightNodeCondition_111c40::FUN_0010c120);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ae8), params, 1);
    }
    DAT_004e0aec++;
}
