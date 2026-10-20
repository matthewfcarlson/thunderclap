#include "compat/ptr.h"
#include "gen/fight.h"

struct Init_11afc0 {
    void init(int);
};
extern char g_hgpc_vftable;
struct HasGroundPointCondition_11afc0 {
    char pad[12];
    unsigned char x;
    unsigned char y;
};
void* __cdecl alloc(hulk_uintptr);

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::HasGroundPointCondition>::vfunc_5() {
    HasGroundPointCondition_11afc0* p = (HasGroundPointCondition_11afc0*)alloc(0x10);
    if (p) {
        ((Init_11afc0*)p)->init(0);
        *(void**)p = (void*)&g_hgpc_vftable;
        p->x = 1;
        p->y = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
