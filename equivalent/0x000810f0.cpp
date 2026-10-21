// STATUS: equivalent (tools/equiv.py level 3: 19916 inputs, branch coverage 18/18)
// FUN_000810f0 @ 0x000810f0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/address.h"
struct Vec3_810f0 {
    float x, y, z;
};

struct NameHolder_810f0 {
    char pad[8];
    void FUN_0027b040(const char* name);
};

struct Matrix {
    char pad[0x40];
    void FUN_0022b980();
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0();
    char pad04[4];
    NameHolder_810f0 nameHolder;
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

// ref-counted object: slot 0 = AddRef, slot 1 = Release
class Device_810f0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual int s11();
};

class Skeleton {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x148 - 4];
    int f148;
    Skeleton* FUN_00287860();
    void FUN_00288080(int a);
    void FUN_00284ad0(int a);
};

class Controller_810f0 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x70];
    char* f74;
    Controller_810f0* FUN_002efe50(Vec3_810f0* v, float f);
};

struct Camera {
    void FUN_001b4360(void* who);
};

struct World {
    char pad00[0x10];
    Camera* camera;
};


void* FUN_0008d690(unsigned int size);
void* thunk_FUN_0008d690(unsigned int size);
Controller_810f0* FUN_002efca0(void* mem, int arg);

class CCivilian : public pure3d::Entity {
public:
    CCivilian(int a1, Device_810f0* dev, int a3, int a4, int a5, char flag);
    virtual void v1();
    virtual void v2();

    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    Matrix m34;
    int f74;
    int f78;
    int f7c;
    int f80[15];  // 0x80 .. 0xbc
    int fbc[4];   // 0xbc .. 0xcc
    int fcc[7];   // 0xcc .. 0xe8
    Device_810f0* fe8;
    int fec;
    Skeleton* ff0;
    char padf4[0x100 - 0xf4];
    Controller_810f0* f100;
};

CCivilian::CCivilian(int a1, Device_810f0* dev, int a3, int a4, int a5, char flag)
{
    int i;
    f18 = a4;
    f1c = a5;
    f10 = a3;
    f14 = 0x10;
    f20 = 1;
    f24 = 0;
    f28 = 2;
    f2c = 0;
    f30 = 0;
    for (i = 0; i < 15; i++)
        f80[i] = 0;
    for (i = 0; i < 4; i++)
        fbc[i] = -1;
    for (i = 0; i < 7; i++)
        fcc[i] = 0;
    fe8 = 0;
    fec = 0;
    ff0 = 0;
    f100 = 0;
    nameHolder.FUN_0027b040((const char*)a1);
    if (flag)
        f28 |= 4;
    m34.FUN_0022b980();
    f7c = 0;
    f78 = 0;
    f74 = 0;
    f10 = a3;

    if (dev)
        dev->AddRef();
    if (fe8)
        fe8->Release();
    fe8 = dev;
    void* mem = thunk_FUN_0008d690(0x150);
    Skeleton* skel = 0;
    if (mem)
        skel = ((Skeleton*)mem)->FUN_00287860();
    if (skel)
        skel->AddRef();
    if (ff0)
        ff0->Release();
    ff0 = skel;
    int value = fe8->s11();
    ff0->FUN_00288080(value);
    ff0->FUN_00284ad0(0);
    *(int*)((char*)ff0 + 0x148) = 0;

    Vec3_810f0 v;
    v.x = 0.0f;
    v.y = 0.8f;
    v.z = 0.0f;
    mem = FUN_0008d690(0x48);
    Controller_810f0* ctl = 0;
    if (mem)
        ctl = ((Controller_810f0*)mem)->FUN_002efe50(&v, 0.801f);
    ctl = FUN_002efca0(ctl, a1);
    if (ctl)
        ctl->AddRef();
    if (f100)
        f100->Release();
    f100 = ctl;
    ctl->f74[0x72] = 0;
    DAT_004dd700->camera->FUN_001b4360(this);
}
