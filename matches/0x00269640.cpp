#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/platform/xbox/core.h"
#include "gen/core.h"

typedef unsigned int u32_269640;
extern "C" u32_269640 __cdecl FUN_00266e00(u32_269640, u32_269640);
struct ControllerSystemXBox_nv_269640 {
    u32_269640 Make(u32_269640, u32_269640);
};
extern "C" void __cdecl FUN_00269640(u32_269640 a, u32_269640 b) {
    u32_269640 v = b;
    *(volatile u32_269640*)((hulk_intptr)((char*)&DAT_004cdbb0)) = v;
    hulk_uintptr x = FUN_00266e00(v, 0x12a8);
    if (x)
        *(volatile u32_269640*)((hulk_intptr)DAT_00528398) = ((ControllerSystemXBox_nv_269640*)(((core::ControllerSystemXBox*)(((core::ControllerSystemXBox*)x)))))->Make(a, v);
    else
        *(volatile u32_269640*)((hulk_intptr)DAT_00528398) = 0;
}