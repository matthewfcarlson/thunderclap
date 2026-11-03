#include "gen/pure3d.h"
void* FUN_0008d690(unsigned int);
struct Obj {
};
Obj* FUN_00327f20(int x) {
    Obj* p = (Obj*)FUN_0008d690(0xc8);
    if (p)
        return ((Obj *)((pure3d::d3dProjectedTextureShader *)p)->FUN_0032cbc0((void *)(hulk_uintptr)(int)x));
    return 0;
}
