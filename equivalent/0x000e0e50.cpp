// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000e0e50 @ 0x000e0e50
// FUN_000e0e50 @ 0x000e0e50
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
struct Vec3_e0e50 {
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

class Factory_e0e50 {
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
    virtual void vfunc_31(int handle);
};


void __cdecl FUN_000e07c0(Vec3_e0e50 a, Vec3_e0e50 b, int color);

/* Draws the 12 edges of a box given its 8 corners in debug lines. */
void __cdecl FUN_000e0e50(Vec3_e0e50 c0, Vec3_e0e50 c1, Vec3_e0e50 c2, Vec3_e0e50 c3,
                          Vec3_e0e50 c4, Vec3_e0e50 c5, Vec3_e0e50 c6, Vec3_e0e50 c7, int color, int arg)
{
    if ((*(Texture**)&DAT_004de954) == 0) {
        (*(Texture**)&DAT_004de954) = (*(Factory_e0e50**)&DAT_0052c2a0)->vfunc_11("simple", 0);
        (*(Texture**)&DAT_004de954)->vfunc_0();
        (*(Texture**)&DAT_004de954)->vfunc_6(0x444d4c42, 1);
    }

    int handle = DAT_0052c2a8->vfunc_30((*(Texture**)&DAT_004de954), arg, 0x2020, 0x18, 0);
    if (handle) {
        FUN_000e07c0(c0, c1, color);
        FUN_000e07c0(c1, c3, color);
        FUN_000e07c0(c3, c2, color);
        FUN_000e07c0(c2, c0, color);
        FUN_000e07c0(c4, c5, color);
        FUN_000e07c0(c5, c7, color);
        FUN_000e07c0(c7, c6, color);
        FUN_000e07c0(c6, c4, color);
        FUN_000e07c0(c0, c4, color);
        FUN_000e07c0(c1, c5, color);
        FUN_000e07c0(c2, c6, color);
        FUN_000e07c0(c3, c7, color);
    }
    DAT_0052c2a8->vfunc_31(handle);
}
