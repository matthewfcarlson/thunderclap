// STATUS: equivalent (tools/equiv.py level 3: 16651 inputs, branch coverage 4/4)
// FUN_000e0850 @ 0x000e0850
// FUN_000e0850 @ 0x000e0850
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
struct Vec3_e0850 {
    float x, y, z;
};

class Texture {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(int a, int b);
};

class Factory_e0850 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Texture *vfunc_11(const char *name, int flags);
};

class Gfx {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual int vfunc_30(Texture *tex, int a, int b, int c, int d);
    virtual int vfunc_31(int handle);
};


// equiv-conv: FUN_000e07c0 esi stack stack stack
void __cdecl FUN_000e07c0(int handle, Vec3_e0850 a, Vec3_e0850 b, int color);

/* Draws the outline of a quad in debug lines. */
int __cdecl FUN_000e0850(Vec3_e0850 p0, Vec3_e0850 p1, Vec3_e0850 p2, Vec3_e0850 p3, int color, int arg)
{
    if ((*(Texture**)&DAT_004de954) == 0) {
        (*(Texture**)&DAT_004de954) = (*(Factory_e0850**)&DAT_0052c2a0)->vfunc_11("simple", 0);
        (*(Texture**)&DAT_004de954)->vfunc_0();
        (*(Texture**)&DAT_004de954)->vfunc_6(0x444d4c42, 1);
    }

    int handle = DAT_0052c2a8->vfunc_30((*(Texture**)&DAT_004de954), arg, 0x2020, 8, 0);
    if (handle) {
        FUN_000e07c0(handle, p0, p1, color);
        FUN_000e07c0(handle, p1, p3, color);
        FUN_000e07c0(handle, p3, p2, color);
        FUN_000e07c0(handle, p2, p0, color);
    }
    return DAT_0052c2a8->vfunc_31(handle);
}
