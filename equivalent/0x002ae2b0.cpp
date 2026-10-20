// STATUS: equivalent (tools/equiv.py level 3: 3106 inputs, branch coverage 62/62)
// pure3d::TextureBuilder::vfunc_0 @ 0x002ae2b0
#include "decls/data/engine/pure3d/prop.h"

void *FUN_00263ea0(unsigned int size);

struct Surface_2ae2b0 {
    char pad00[0x48];
    int pitch;
    char pad4c[4];
    unsigned char *data;
};

class Resource_2ae2b0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11(int size, int arg);
    virtual void vfunc_12();
    virtual Surface_2ae2b0 *vfunc_13(int a, int b);
};

class Texture {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad04[0xc];
    Resource_2ae2b0 *res;
    Texture *FUN_002c1c30();
    bool FUN_002c1c70(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

class Device_2ae2b0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2();
};


namespace pure3d {
class TextureBuilder {
public:
    virtual bool vfunc_0(int a1, int a2, int a3, int a4, int a5);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();

    Texture *tex;           // 0x04
    int flags;              // 0x08
    Surface_2ae2b0 *surface;       // 0x0c
    int stride;             // 0x10
    unsigned char *dest;    // 0x14
    int rows;               // 0x18
    int level;              // 0x1c
    int width;              // 0x20
    int height;             // 0x24
    int format;             // 0x28
    int depth;              // 0x2c
    int bpp;                // 0x30
};
}

bool pure3d::TextureBuilder::vfunc_0(int a1, int a2, int a3, int a4, int a5)
{
    if (tex == 0) {
        void *mem = FUN_00263ea0(0x18);
        Texture *t = 0;
        if (mem)
            t = ((Texture *)mem)->FUN_002c1c30();
        tex = t;
        int fmt = format;
        switch (fmt) {
        case 0:
        case 1: {
            int g = bpp;
            if (g == 0x10) {
                t->FUN_002c1c70(a1, a2, 0x10, width, height, 0, depth);
            } else if (g > 8 || a3 > 8) {
                t->FUN_002c1c70(a1, a2, 0x20, width, height, 0, depth);
            } else if (a3 == 8) {
                t->FUN_002c1c70(a1, a2, 8, width, height, 1, depth);
                tex->res->vfunc_11(0x100, a5);
            } else if (a3 == 4) {
                t->FUN_002c1c70(a1, a2, 4, width, height, 1, depth);
                tex->res->vfunc_11(0x10, a5);
            }
            break;
        }
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            t->FUN_002c1c70(a1, a2, 2, 0, height, fmt, depth);
            break;
        case 0xd:
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x1b:
        case 0x11:
        case 0x12:
        case 0x15:
        case 0x13:
        case 0x14:
            t->FUN_002c1c70(a1, a2, a3, 8, height, fmt, depth);
            break;
        case 0x1c:
            t->FUN_002c1c70(a1, a2, 0x20, 0x1c, height, fmt, depth);
            break;
        default:
            break;
        }
    }

    if (tex->res == 0) {
        if ((*(Device_2ae2b0**)&DAT_0052c2a0)->vfunc_2() != 1) {
            tex->vfunc_1();
            tex = 0;
        }
    }
    if (tex == 0)
        return false;

    surface = tex->res->vfunc_13(level, 0);
    dest = surface->data;
    rows = 0;
    stride = surface->pitch;
    if (a4 == 1) {
        dest = dest + (a2 - 1) * stride;
        stride = -stride;
    }
    flags = a5;
    return true;
}
