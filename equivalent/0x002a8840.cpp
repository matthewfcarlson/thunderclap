// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 30/30)
// pure3d::LightAnimationController::vfunc_27 @ 0x002a8840
#include "decls/data/game/global.h"

struct Vec3_2a8840 { float x, y, z; };

union Scalar_2a8840 {
    float f;
    int i;
    unsigned char b;
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void sampleVec3(float frame, Vec3_2a8840 *out);
    void FUN_0028ad20(float frame, int *out);
    void FUN_0028ac90(float frame, unsigned char *out);
};

struct ChannelSet_2a8840 {
    Channel *FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};

struct Source_2a8840 {
    ChannelSet_2a8840 *FUN_00288a10(int index);
};

struct Track {
    char data[0x110 - 0x2c];
    Source_2a8840 *FUN_00284f50();
    float FUN_00284f70();
};

class Light {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setDirection(Vec3_2a8840 *dir);
    void FUN_002a07a0(int color);
    void FUN_002a0820(int value);
    void FUN_002a2fc0(Vec3_2a8840 *dir);
    void FUN_002c4250(Vec3_2a8840 *dir);
    void FUN_002c3d00(float x, float y, float z);
    void FUN_002c41a0(float x, float y, float z);
    void FUN_002c3f00(float x, float y, float z);
    void FUN_002c41e0(float x, float y, float z);
};

struct Sink_2a8840 {
    void FUN_00293e90(int color);
};

struct Globals_2a8840 {
    char pad[8];
    Sink_2a8840 *sink;
};

class LightAnimationController {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void vfunc_27();
    virtual void f28();
    virtual void f29();
    char pad04[0x2c - 4];
    Track track;
    int mode;
    Light *light;
};

void LightAnimationController::vfunc_27()
{
    struct Frame {
        Scalar_2a8840 s;
        Vec3_2a8840 v;
    } fr;
    Source_2a8840 *src = track.FUN_00284f50();
    fr.s.f = track.FUN_00284f70();
    ChannelSet_2a8840 *cs = src->FUN_00288a10(0);
    Channel *c;

    if (light == 0) {
        c = cs->FUN_00288960(0x524c43, 0x524c43);
        if (c != 0) {
            c->FUN_0028ad20(fr.s.f, &fr.s.i);
            if ((*(Globals_2a8840**)&DAT_0052c2b4)->sink != 0) {
                (*(Globals_2a8840**)&DAT_0052c2b4)->sink->FUN_00293e90(fr.s.i);
            }
        }
        return;
    }

    c = cs->FUN_00288960(0x524c43, 0x524c43);
    float frame = fr.s.f;
    if (c != 0) {
        c->FUN_0028ad20(frame, &fr.s.i);
        light->FUN_002a07a0(fr.s.i);
    }

    c = cs->FUN_00288960(0x4d524150, 0x54434556);
    if (c != 0) {
        c->sampleVec3(frame, &fr.v);
        light->setDirection(&fr.v);
    }

    c = cs->FUN_00288960(0x524944, 0x54434556);
    if (c != 0) {
        c->sampleVec3(frame, &fr.v);
        if (mode == 2) {
            light->FUN_002a2fc0(&fr.v);
        } else if (mode == 3) {
            light->FUN_002c4250(&fr.v);
        }
    }

    c = cs->FUN_00288960(0x4e545441, 0x54434556);
    if (c != 0) {
        c->sampleVec3(frame, &fr.v);
        if (mode == 1) {
            light->FUN_002c3f00(fr.v.x, fr.v.y, fr.v.z);
        } else if (mode == 3) {
            light->FUN_002c41a0(fr.v.x, fr.v.y, fr.v.z);
        } else if (mode == 4) {
            light->FUN_002c3d00(fr.v.x, fr.v.y, fr.v.z);
        }
    }

    c = cs->FUN_00288960(0x454e4f43, 0x54434556);
    if (c != 0 && mode == 3) {
        c->sampleVec3(frame, &fr.v);
        light->FUN_002c41e0(fr.v.x, fr.v.y, fr.v.z);
    }

    c = cs->FUN_00288960(0x4c424145, 0x4c4f4f42);
    if (c != 0) {
        c->FUN_0028ac90(frame, &fr.s.b);
        light->FUN_002a0820(fr.s.i);
    }
}
