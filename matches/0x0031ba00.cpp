#include "compat/ptr.h"
#include "gen/pure3d.h"
extern "C" char DAT_004324e4[];
typedef unsigned int u32_31ba00;
struct d3dDevice_31ba00 {
    hulk_uintptr vftable;
    char pad4[8];
    u32_31ba00 fieldC;
    u32_31ba00 field10;
    d3dDevice_31ba00* Init(u32_31ba00 value);
};
struct d3dDevice_nv_31ba00 {
    void FUN_0031bac0();
};
extern void FUN_00328130();
d3dDevice_31ba00* d3dDevice_31ba00::Init(u32_31ba00 value) {
    ((d3dDevice_nv_31ba00*)(((pure3d::d3dDevice*)(this))))->FUN_0031bac0();
    vftable = ((hulk_intptr)DAT_004324e4);
    field10 = value;
    fieldC = 0;
    FUN_00328130();
    return this;
}