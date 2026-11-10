#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/pure3d.h"
extern "C" void* __cdecl FUN_0008d690(unsigned int);
// pure3d::d3dDisplay (matches/0x0031b520.cpp constructs it from the D3D object): its 32-bit layout, 0x49c bytes
// (pddiObject's vftable and two words, the D3D object, the caps block, the display mode, the viewport words).
struct d3dDisplay_31b830 {
    void* vftable;
    int field4, field8;
    int d3d;        // +0x0c the D3D object (0x0031ba00 keeps it at d3dDevice +0x10)
    int field_10;
    char pad14[0x58 - 0x14];
    char caps[0x434 - 0x58];
    unsigned char b434, b435, b436, b437;
    int field438;
    char mode[0x34];
    int field470, field474, field478, field47c, field480;
    float scaleX, scaleY, scaleZ;
    char pad490[8];
    int field498;
    d3dDisplay_31b830* FUN_0031b520(int d3d);
};
// pddiDevice::newDisplay: a d3dDisplay on the game's heap, built from this device's D3D object; the display or 0.
void* pure3d::d3dDevice::vfunc_7(int arg) {
    HULK_SIZE32(d3dDisplay_31b830, 0x49c);
    d3dDisplay_31b830* result = (d3dDisplay_31b830*)FUN_0008d690((unsigned int)sizeof(d3dDisplay_31b830));
    if (result)
        return result->FUN_0031b520(*(int*)((char*)this + 0x10));
    return 0;
}
