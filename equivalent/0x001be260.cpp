// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_001be260 @ 0x001be260
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"

struct Builder {
    char pad00[8];
    float* pos;
    char pad0c[4];
    int* color;
    void FUN_0008ef00();
};

class Gfx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual Builder* v78(int a, int b, int c, int d, int e);
    virtual void v7c(Builder* b);
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8(int a);
};

class Device_1be260 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c(int a);
    virtual void v40(int a);
};

struct DeviceHolder {
    Device_1be260* device;
    void FUN_00293d00(char* p);
};


struct Layer_1be260 {
    char pad00[0x10];
    int handle;
};

class Quad_1be260 {
public:
    char pad00[0x10];
    float size;
    char pad14[4];
    Layer_1be260* layer;
    void FUN_001be260();
};

void Quad_1be260::FUN_001be260()
{
    DAT_0052c2a8->ve8(0);
    (*(DeviceHolder**)&DAT_0052c2ac)->device->v3c(0);
    (*(DeviceHolder**)&DAT_0052c2ac)->FUN_00293d00(((char*)&DAT_004e2308));
    Builder* b = DAT_0052c2a8->v78(layer->handle, 1, 0x2020, 4, 0);
    float left = DAT_004c4c4c * (*(float*)&DAT_003f3db0);
    float top = size * (*(float*)&DAT_003f3db0);
    float right = DAT_004c4c4c * (*(float*)&DAT_003f32f4);
    float bottom = size * (*(float*)&DAT_003f32f4);
    {
        float* p = b->pos;
        p[1] = top;
        p[0] = left;
        p[2] = 0;
        b->color[0] = 0x7f000000;
        b->FUN_0008ef00();
    }
    {
        float* p = b->pos;
        p[0] = left;
        p[1] = bottom;
        p[2] = 0;
        b->color[0] = 0x7f000000;
        b->FUN_0008ef00();
    }
    {
        float* p = b->pos;
        p[0] = right;
        p[1] = top;
        p[2] = 0;
        b->color[0] = 0x7f000000;
        b->FUN_0008ef00();
    }
    {
        float* p = b->pos;
        p[0] = right;
        p[1] = bottom;
        p[2] = 0;
        b->color[0] = 0x7f000000;
        b->FUN_0008ef00();
    }
    DAT_0052c2a8->v7c(b);
    (*(DeviceHolder**)&DAT_0052c2ac)->device->v40(0);
    DAT_0052c2a8->ve8(1);
}
