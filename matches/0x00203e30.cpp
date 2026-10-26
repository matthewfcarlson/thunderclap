#include "decls/data/engine/content.h"
// data: gManager_203e30 = DAT_00527c58

struct Manager_203e30 {
    int Get();
    void Set(int);
};
struct Waiter {
    bool Ready();
};
struct Target_203e30 {
    void Run(Waiter*);
};
extern void __cdecl FUN_00087990();
void Target_203e30::Run(Waiter* w) {
    int old = (*(Manager_203e30**)&DAT_00527c58)->Get();
    (*(Manager_203e30**)&DAT_00527c58)->Set(250000);
    while (!w->Ready())
        FUN_00087990();
    (*(Manager_203e30**)&DAT_00527c58)->Set(old);
}