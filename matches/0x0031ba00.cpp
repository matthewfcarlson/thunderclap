#include "compat/ptr.h"
#include "gen/pure3d.h"
extern "C" char DAT_004324e4[];
typedef unsigned int u32_31ba00;
struct d3dDevice_31ba00 {
    hulk_uintptr vftable;
    char pad4[8];
    u32_31ba00 fieldC;
    u32_31ba00 field10;
    d3dDevice_31ba00* FUN_0031ba00(hulk_uintptr d3d);  // the D3D object (Direct3D_Object, pointer-sized); kept in a 32-bit word for now
};
struct d3dDevice_nv_31ba00 {
    void FUN_0031bac0();
};
extern "C" void FUN_00328130();
d3dDevice_31ba00* d3dDevice_31ba00::FUN_0031ba00(hulk_uintptr d3d) {
    ((d3dDevice_nv_31ba00*)(((pure3d::d3dDevice*)(this))))->FUN_0031bac0();
    vftable = ((hulk_intptr)DAT_004324e4);
    field10 = (u32_31ba00)d3d;
    fieldC = 0;
    FUN_00328130();
    return this;
}