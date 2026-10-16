// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 18/18)
// pure3d::ParticleSystem::vfunc_8 @ 0x002a39a0
#include "decls/data/engine/pure3d/prop.h"

class Device_2a39a0 {
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
    virtual void v16(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23(int a, void* p);
};

class Child_2a39a0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7();
    virtual void v8(int a);
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
    virtual void v22(void* out);
};

class Helper_2a39a0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int a);
    virtual int v4(int a);
};

class Lifecycle {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

struct Mat_2a39a0 {
    float m[16];
};

struct Elem_2a39a0 {
    Child_2a39a0* child;
    char pad[12];
    void FUN_002a4060();
};

struct Renderer_2a39a0 {
    void FUN_0029b9d0(void* system, unsigned int index, Mat_2a39a0* mat, int arg);
};


class ParticleSystem {
public:
    void run(Renderer_2a39a0* renderer, int arg);
    char p0[0x10];
    Helper_2a39a0* helper;
    char p1[0x48 - 0x14];
    Elem_2a39a0* begin;
    Elem_2a39a0* end;
    char p2[0x64 - 0x50];
    char block64[0xa4 - 0x64];
    Lifecycle* life;
};

void ParticleSystem::run(Renderer_2a39a0* renderer, int arg)
{
    (*(*(Device_2a39a0***)&DAT_0052c2ac))->v23(0, block64);
    if (life != 0)
        life->v7();

    if (renderer == 0) {
        unsigned int count = (unsigned int)(end - begin);
        if (helper != 0) {
            for (unsigned int i = 0; i < count; i++) {
                Child_2a39a0* c = begin[i].child;
                c->v8(helper->v3(c->v7()));
                begin[i].FUN_002a4060();
                c->v8(helper->v4(c->v7()));
            }
        } else {
            for (unsigned int i = 0; i < count; i++)
                begin[i].FUN_002a4060();
        }
    } else {
        unsigned int count = (unsigned int)(end - begin);
        for (unsigned int i = 0; i < count; i++) {
            Mat_2a39a0 mat;
            begin[i].child->v22(&mat);
            renderer->FUN_0029b9d0(this, i, &mat, arg);
        }
    }
    (*(*(Device_2a39a0***)&DAT_0052c2ac))->v16(0);
}
