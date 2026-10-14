// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 32/32)
// FUN_0029ea40 @ 0x0029ea40
struct Vec3_29ea40 {
    float x, y, z;
};

void* FUN_00263ea0(unsigned int size);

class Light {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void vfunc_7(Vec3_29ea40 v);
    virtual void v8();
    virtual void v9();
    void FUN_002a0820(char flag);
    void FUN_002a07a0(int value);
};

class PointLight : public Light {
public:
    PointLight* FUN_002c3e10();
    void FUN_002c3f00(Vec3_29ea40 v);
};

class SpotLight : public Light {
public:
    SpotLight* FUN_002c4020();
    void FUN_002c4130(Vec3_29ea40 v);
    void FUN_002c41a0(Vec3_29ea40 v);
};

class DirectionalLight : public Light {
public:
    DirectionalLight* FUN_002a2e70();
    void FUN_002a2ef0(Vec3_29ea40 v);
};

struct LightRec_29ea40 {
    int f0;
    int kind;
    int value;
    Vec3_29ea40 v0c;
    Vec3_29ea40 v18;
    Vec3_29ea40 v24;
    Vec3_29ea40 v30;
    int pad3c;
};

struct LightList_29ea40 {
    char pad0[0x10];
    int size;
    int count;
    Light** items;
    void FUN_002a0fc0(int index, Light* light);
    void FUN_002a1180(int n);
};

class LightSetup_29ea40 {
public:
    char pad0[0x14];
    int count;
    char pad18[0x24 - 0x18];
    LightRec_29ea40* recs;
    void FUN_0029ea40(LightList_29ea40* list);
};

void LightSetup_29ea40::FUN_0029ea40(LightList_29ea40* list)
{
    for (int i = 0; i < list->count; i++) {
        Light* light = 0;
        if (i < list->size)
            light = list->items[i];

        if (count <= i) {
            if (light)
                light->FUN_002a0820(0);
            list->FUN_002a0fc0(i, 0);
            continue;
        }

        switch (recs[i].kind) {
        case 0: {
            DirectionalLight* d = dynamic_cast<DirectionalLight*>(light);
            if (d == 0) {
                void* mem = FUN_00263ea0(0x68);
                d = mem ? ((DirectionalLight*)mem)->FUN_002a2e70() : 0;
                light = d;
            }
            d->FUN_002a2ef0(recs[i].v18);
            break;
        }
        case 1: {
            PointLight* p = dynamic_cast<PointLight*>(light);
            if (p == 0) {
                void* mem = FUN_00263ea0(0x68);
                p = mem ? ((PointLight*)mem)->FUN_002c3e10() : 0;
                light = p;
            }
            p->vfunc_7(recs[i].v0c);
            p->FUN_002c3f00(recs[i].v24);
            break;
        }
        case 2: {
            SpotLight* s = dynamic_cast<SpotLight*>(light);
            if (s == 0) {
                void* mem = FUN_00263ea0(0x80);
                s = mem ? ((SpotLight*)mem)->FUN_002c4020() : 0;
                light = s;
            }
            s->vfunc_7(recs[i].v0c);
            s->FUN_002c4130(recs[i].v18);
            s->FUN_002c41a0(recs[i].v24);
            recs[i].v30 = recs[i].v30; // x87 load/store round trip in the original (quiets signalling NaNs)
            break;
        }
        default:
            if (light) {
                light->FUN_002a0820(0);
                light = 0;
            }
            list->FUN_002a0fc0(i, light);
            continue;
        }

        if (light) {
            light->FUN_002a0820(1);
            light->FUN_002a07a0(recs[i].value);
        }
        list->FUN_002a0fc0(i, light);
    }
    list->FUN_002a1180(count);
}
