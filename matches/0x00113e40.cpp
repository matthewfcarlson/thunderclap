#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040d9a4[];
struct AIFightNodeCondition_113e40 {
    int v;
};
extern void* __cdecl operator_new(unsigned int);
struct InitObj_113e40 {
    void InitCondition(int);
};
struct EntityObj {
    void InitEntity();
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::AIFightNodeCondition>::vfunc_5() {
    AIFightNodeCondition_113e40* p = (AIFightNodeCondition_113e40*)operator_new(0x18);
    if (p) {
        ((InitObj_113e40*)p)->InitCondition(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_0040d9a4);
        ((EntityObj*)((char*)p + 0xc))->InitEntity();
        return (void*)(p);
    }
    return (void*)(0);
}
