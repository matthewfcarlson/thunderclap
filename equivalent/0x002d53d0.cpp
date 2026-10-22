// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 12/12)
// FUN_002d53d0 @ 0x002d53d0
#include "compat/ptr.h"
#include "decls/data/game/global.h"

struct Stream;

struct Vec3_2d53d0 {
    float x, y, z;
};

struct Matrix {
    float m[12];
    Vec3_2d53d0 pos;
    float w;
    void FUN_0022ca90(Matrix* a, Matrix* b);
};

class PositionReader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReadPosition(Stream* s, Vec3_2d53d0* out);        // slot 4
};

class RotationReader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void ReadRotation(Stream* s, Matrix* out);      // slot 6
};

struct Curve_2d53d0 {
    void FUN_0028a1c0(Stream* s, float* out);
};

struct ColorCurve {
    void FUN_0028ad20(Stream* s, unsigned int* out);
};

struct ByteCurve {
    void FUN_0028a0b0(Stream* s, unsigned char* out);
};

struct Desc_2d53d0 {
    char pad00[8];
    Curve_2d53d0* c08;
    Curve_2d53d0* c0c;
    Curve_2d53d0* c10;
    Curve_2d53d0* c14;
    Curve_2d53d0* c18;
    Curve_2d53d0* c1c;
    Curve_2d53d0* c20;
    Curve_2d53d0* c24;
    Curve_2d53d0* c28;
    Curve_2d53d0* c2c;
    Curve_2d53d0* c30;
    Curve_2d53d0* c34;
    Curve_2d53d0* c38;
    ColorCurve* c3c;
    ByteCurve* b40;
    ByteCurve* b44;
    ByteCurve* b48;
};

struct Extra_2d53d0 {
    void FUN_0028ac90(Stream* s, int* out);
};

struct Camera {
    Matrix* FUN_0028faa0();
};

struct CameraHolder {
    Camera* camera;
};


class Emitter_2d53d0 {
public:
    void FUN_002d53d0(Stream* s, Desc_2d53d0* d, Matrix* parent);

    char pad0[0x8];
    Matrix local;  // 0x8
    Matrix orient;  // 0x48
    PositionReader* positionReader;  // 0x88
    RotationReader* rotationReader;  // 0x8c
    int f90;  // 0x90
    Extra_2d53d0* extra;  // 0x94
    char pad98[0x14];
    float fac;  // 0xac
    float fb0;  // 0xb0
    char padb4[0x4];
    float fb8;  // 0xb8
    float fbc;  // 0xbc
    float fc0;  // 0xc0
    float fc4;  // 0xc4
    float fc8;  // 0xc8
    float fcc;  // 0xcc
    float fd0;  // 0xd0
    float fd4;  // 0xd4
    float fd8;  // 0xd8
    char paddc[0x8];
    float fe4;  // 0xe4
    float fe8;  // 0xe8
    float fec;  // 0xec
    float ff0;  // 0xf0
    float ff4;  // 0xf4
    float ff8;  // 0xf8
    float ffc;  // 0xfc
    float f100;  // 0x100
    float f104;  // 0x104
    float f108;  // 0x108
    unsigned int color;  // 0x10c
    unsigned char b110;  // 0x110
    unsigned char b111;  // 0x111
};

void Emitter_2d53d0::FUN_002d53d0(Stream* s, Desc_2d53d0* d, Matrix* parent)
{
    positionReader->ReadPosition(s, &orient.pos);
    rotationReader->ReadRotation(s, &orient);
    if (extra)
        extra->FUN_0028ac90(s, &f90);

    local.FUN_0022ca90(parent, &orient);
    Matrix combined;
    combined.FUN_0022ca90(&local, (*(CameraHolder**)&DAT_0052c2b0)->camera->FUN_0028faa0());
    local = combined;

    d->c08->FUN_0028a1c0(s, &fac);
    hulk_freg p = fb0 * fac;
    fac = (p < 0.0f) ? 0.0f : p;

    d->c0c->FUN_0028a1c0(s, &fb8);
    p = fc0 * fb8;
    fb8 = (p < 0.0f) ? 0.0f : p;

    d->c10->FUN_0028a1c0(s, &fbc);

    d->c14->FUN_0028a1c0(s, &fc4);
    fc4 = fcc * fc4;
    d->c18->FUN_0028a1c0(s, &fc8);

    d->c1c->FUN_0028a1c0(s, &fd0);
    p = fd8 * fd0;
    fd0 = (p < 0.0f) ? 0.0f : p;
    d->c20->FUN_0028a1c0(s, &fd4);

    if (d->c24) {
        d->c24->FUN_0028a1c0(s, &fe4);
        fe4 = fec * fe4;
    }
    if (d->c28)
        d->c28->FUN_0028a1c0(s, &fe8);

    d->c2c->FUN_0028a1c0(s, &ff0);
    ff0 = ff8 * ff0;
    d->c30->FUN_0028a1c0(s, &ff4);

    d->c34->FUN_0028a1c0(s, &ffc);
    ffc = f100 * ffc;

    d->c38->FUN_0028a1c0(s, &f104);
    f104 = f108 * f104;

    d->c3c->FUN_0028ad20(s, &color);

    unsigned char b;
    d->b44->FUN_0028a0b0(s, &b);
    color = (color & 0xffffff) | ((unsigned int)b << 24);
    d->b40->FUN_0028a0b0(s, &b);
    b110 = b;
    d->b48->FUN_0028a0b0(s, &b);
    b111 = b;
}
