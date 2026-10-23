// Same code shape as 0x00113f80 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"

extern void* __cdecl Alloc(hulk_uintptr);
struct GameStateCondition_nv_1328a0 {
    void Init(int);
};
extern int AIHistoryNameCondition_vftable;

template <> void* fight::ConditionFactoryTemplate<hulkfight::GameStateCondition>::vfunc_5() {
    hulkfight::GameStateCondition* p = (hulkfight::GameStateCondition*)Alloc(0x18);
    void* result;
    if (p) {
        ((GameStateCondition_nv_1328a0*)(p))->Init(0);
        *(int**)p = &AIHistoryNameCondition_vftable;
        (*(int *)&p->f_0c) = 0;
        p->f_10 = 0;
        (*(int *)&p->f_14) = 0;
        result = p;
    } else
        result = 0;
    return (void*)(result);
}
