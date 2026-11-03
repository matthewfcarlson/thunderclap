#include "gen/global.h"
#include "gen/owners.h"

typedef unsigned int u32_1cbd10;
struct Local_1cbd10 {
    char pad[32];
};
struct CEventManager_nv_1cbd10 {
    void Run(Local_1cbd10*);
};

void CEventManager::FUN_001cbd10(unsigned int __p0) { u32_1cbd10 arg = (u32_1cbd10)__p0;

    Local_1cbd10 local;
    ((owners::Result_1cae40 *)&local)->FUN_001cae40((hulk_uintptr)arg);
    ((CEventManager_nv_1cbd10*)this)->Run(&local);
}
