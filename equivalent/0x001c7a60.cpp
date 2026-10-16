// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001c7a60 @ 0x001c7a60
#include "decls/address.h"
extern "C" double sin(double);
extern "C" double cos(double);

struct Vec3_1c7a60 { float x, y, z; };

struct VertexSink_1c7a60 {
    char pad0[8];
    float *pos;
    char pad0c[4];
    unsigned int *color;
    float *tex;
    void FUN_0008ef00();
};

class Device1 {
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15(int a);
    virtual void vfunc_16(int a);
};

struct Wrapper1 {
    Device1 *dev;
    void FUN_00293d00(Vec3_1c7a60 *origin);
};

class Gfx {
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual VertexSink_1c7a60 *vfunc_30(int buffer, int a, int flags, int stride, int b);
    virtual void vfunc_31(VertexSink_1c7a60 *sink);
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62(int a);
};

extern Wrapper1 *DAT_0052c2ac;

struct Target_1c7a60 {
    char pad0[0x24];
    Vec3_1c7a60 pos;
};

struct Buffer_1c7a60 {
    char pad0[0x10];
    int handle;
};

class Marker_1c7a60 {
public:
    char pad0[0x750];
    Buffer_1c7a60 *buffer;
    void Draw(Target_1c7a60 *target, float radius, unsigned int gray, unsigned int alpha, unsigned int edgeByte);
};

void Marker_1c7a60::Draw(Target_1c7a60 *target, float radius, unsigned int gray, unsigned int alpha, unsigned int edgeByte)
{
    unsigned int edge = ((((edgeByte | 0xffffff00) << 8) | edgeByte) << 8) | edgeByte;
    unsigned int fill = ((((alpha << 8) | gray) << 8 | gray) << 8) | gray;

    Vec3_1c7a60 origin = target->pos;
    DAT_0052c2ac->dev->vfunc_15(0);
    DAT_0052c2ac->FUN_00293d00(&origin);
    DAT_0052c2a8->vfunc_62(0);
    VertexSink_1c7a60 *sink = DAT_0052c2a8->vfunc_30(buffer->handle, 0, 0x2020, 0x24, 0);

    float angle = 0.0f;
    float x = (float)(sin(0.0) * radius);
    float y = (float)(cos(0.0) * radius);
    for (int i = 12; i != 0; i--) {
        *sink->color = fill;
        sink->pos[0] = 0.0f;
        sink->pos[1] = 0.03f;
        sink->pos[2] = 0.0f;
        sink->FUN_0008ef00();

        *sink->color = edge;
        sink->pos[0] = x;
        sink->pos[1] = 0.03f;
        sink->pos[2] = y;
        sink->FUN_0008ef00();

        angle = angle + 0.52359879f;
        *sink->color = edge;
        x = (float)(sin(angle) * radius);
        sink->pos[0] = x;
        sink->pos[1] = 0.03f;
        y = (float)(cos(angle) * radius);
        sink->pos[2] = y;
        sink->FUN_0008ef00();
    }

    DAT_0052c2a8->vfunc_31(sink);
    DAT_0052c2a8->vfunc_62(1);
    DAT_0052c2ac->dev->vfunc_16(0);
}
