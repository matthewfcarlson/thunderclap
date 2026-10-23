#include "decls/data/engine/core.h"
#include "gen/core.h"

void* __cdecl FUN_00266e00(int, int);
struct XboxDrive_nv_26fcf0 {
    core::XboxDrive* FUN_0026f570(int, int);
};
void __cdecl FUN_0026fcf0(core::XboxDrive** result, int second, int third, int fourth) {
    DAT_004cdbb0 = third;
    core::XboxDrive* allocated = (core::XboxDrive*)FUN_00266e00(third, 0x1e4);
    core::XboxDrive* object = allocated ? ((XboxDrive_nv_26fcf0*)(((core::XboxDrive*)(allocated))))->FUN_0026f570(second, third) : 0;
    *result = object;
    object->vfunc_21(fourth);
}