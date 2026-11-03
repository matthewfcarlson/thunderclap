#include "decls/data/engine/content.h"
// data: gManager_203e30 = DAT_00527c58
#include "gen/owners.h"

struct Manager_203e30 {
    int Get();
};
struct Waiter {
    bool Ready();
};
struct Target_203e30 {
    void Run(Waiter*);
};
extern "C" void __cdecl FUN_00087990();
void Target_203e30::Run(Waiter* w) {
    int old = (*(Manager_203e30**)&DAT_00527c58)->Get();
    ((owners::C_264860 *)((*(Manager_203e30**)&DAT_00527c58)))->FUN_00264860(250000);
    while (!w->Ready())
        FUN_00087990();
    ((owners::C_264860 *)((*(Manager_203e30**)&DAT_00527c58)))->FUN_00264860(old);
}