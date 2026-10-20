#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/platform/xbox/core.h"
#include "gen/core.h"

typedef unsigned int u32_269640;
extern u32_269640 __cdecl FindThing(u32_269640, u32_269640);
struct ControllerSystemXBox_nv_269640 {
    u32_269640 Make(u32_269640, u32_269640);
};
void __cdecl Target(u32_269640 a, u32_269640 b) {
    u32_269640 v = b;
    *(volatile u32_269640*)((hulk_intptr)((char*)&DAT_004cdbb0)) = v;
    hulk_uintptr x = FindThing(v, 0x12a8);
    if (x)
        *(volatile u32_269640*)((hulk_intptr)DAT_00528398) = ((ControllerSystemXBox_nv_269640*)(((core::ControllerSystemXBox*)x)))->Make(a, v);
    else
        *(volatile u32_269640*)((hulk_intptr)DAT_00528398) = 0;
}