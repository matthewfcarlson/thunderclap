#include "gen/fight.h"

extern "C" char DAT_0041c5b0[];
extern void* __cdecl FUN_0008d690(unsigned int);
struct Event_1aab50 {
    void Init(int);
};
struct Tail_1aab50 {
    void Run();
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropStateNameCondition>::vfunc_5() {
    Event_1aab50* p = (Event_1aab50*)FUN_0008d690(0x18);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_0041c5b0);
        ((Tail_1aab50*)((char*)p + 0x10))->Run();
        return (void*)(p);
    }
    return (void*)(0);
}
