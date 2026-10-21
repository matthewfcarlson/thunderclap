// STATUS: equivalent (tools/equiv.py level 3: 159 inputs, branch coverage 8/10, incomplete)
// pure3d::SpriteParticleRenderer::vfunc_4 @ 0x002d6790
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "compat/ptr.h"
extern "C" double cos(double);
extern "C" double sin(double);

struct Vec3_2d6790 {
    float x, y, z;
};

struct Matrix {
    float m[16];
};

struct MatrixProvider {
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
    virtual Matrix *v13();
};

struct Inner_2d6790 {
    char pad00[0x18];
    MatrixProvider *provider;
};

struct Holder_2d6790 {
    char pad00[8];
    Inner_2d6790 *inner;
};

class Device2_2d6790 {
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
    virtual void v21(int a);
};

struct Owner2_2d6790 {
    Device2_2d6790 *device;
};

class VertexBuffer_2d6790;

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
    virtual VertexBuffer_2d6790 *v30(void *handle, int a, int flags, int size, int b);
    virtual void v31(VertexBuffer_2d6790 *vb);
};

class VertexBuffer_2d6790 {
public:
    char pad00[8];
    Vec3_2d6790 *pos;
    char padc[4];
    unsigned int *color;
    float *uv;
    void FUN_0008ef00();
};

struct Handle_2d6790 {
    char pad00[0x10];
    void *handle;
};

struct Particle_2d6790 {
    Vec3_2d6790 pos;
    unsigned int color;
    float size;
    float angle;
    char pad18;
    signed char index;
};

struct Atlas {
    char pad00[0x10];
    float *cols;
};

class Emitter_2d6790 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual Handle_2d6790 *v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual unsigned int v13();
    char pad04[0x1bc - 4];
    Atlas *atlas;
    char pad1c0[0x1c8 - 0x1c0];
    Particle_2d6790 **particles;
};

extern "C" int FUN_0034483c();

static inline void Emit(VertexBuffer_2d6790 *vb, unsigned int color, float u, float v, float x, float y, float z)
{
    *vb->color = color;
    vb->uv[0] = u;
    vb->uv[1] = v;
    vb->pos->x = x;
    vb->pos->y = y;
    vb->pos->z = z;
    vb->FUN_0008ef00();
}

class SpriteParticleRenderer {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(Emitter_2d6790 *e);
};

void SpriteParticleRenderer::vfunc_4(Emitter_2d6790 *e)
{
    unsigned int count = e->v13();
    Atlas *atlas = e->atlas;
    if (count == 0) {
        return;
    }
    Matrix m = *(*(Holder_2d6790**)&DAT_0052c2b4)->inner->provider->v13();
    (*(Owner2_2d6790**)&DAT_0052c2ac)->device->v21(0);
    void *handle = e->v7()->handle;
    VertexBuffer_2d6790 *vb = DAT_0052c2a8->v30(handle, 0, 0x2021, count * 6, 0);
    for (unsigned int i = 0; i < count; i++) {
        Particle_2d6790 *p = e->particles[i];
        hulk_freg a = p->angle + 0.7853982f;
        hulk_freg c = (float)cos(a) * p->size;
        hulk_freg s = (float)sin(a) * p->size;
        hulk_freg x = (m.m[0] * p->pos.x + m.m[8] * p->pos.z) + m.m[4] * p->pos.y + m.m[12];
        hulk_freg y = (m.m[1] * p->pos.x + m.m[9] * p->pos.z) + m.m[5] * p->pos.y + m.m[13];
        hulk_freg z = (m.m[2] * p->pos.x + m.m[10] * p->pos.z) + m.m[6] * p->pos.y + m.m[14];
        hulk_freg ax = x + c;
        hulk_freg ay = y + s;
        hulk_freg bx = x - s;
        hulk_freg by = y + c;
        hulk_freg cx = x - c;
        hulk_freg cy = y - s;
        hulk_freg dx = x + s;
        hulk_freg dy = y - c;
        hulk_freg az = z;
        hulk_freg bz = z;
        hulk_freg cz = z;
        hulk_freg dz = z;
        float *cols = atlas->cols + p->index;
        hulk_freg u0 = cols[0];
        hulk_freg u1 = cols[1];
        unsigned int color = p->color;
        hulk_freg r = p->size / z;
        hulk_freg r2 = r * r;
        if (r2 > 0.225f) {
            if (r2 > 0.45f) {
                az = -1.0f;
                bz = -1.0f;
                cz = -1.0f;
                dz = -1.0f;
            } else {
                int alpha = (int)((1.0f - (r2 - 0.225f) * 4.4444447f) * (int)(color >> 24));
                color = (color & 0xffffff) | (alpha << 24);
            }
        }
        Emit(vb, color, u1, 1.0f, ax, ay, az);
        Emit(vb, color, u0, 0.0f, cx, cy, cz);
        Emit(vb, color, u0, 1.0f, bx, by, bz);
        Emit(vb, color, u1, 1.0f, ax, ay, az);
        Emit(vb, color, u1, 0.0f, dx, dy, dz);
        Emit(vb, color, u0, 0.0f, cx, cy, cz);
    }
    DAT_0052c2a8->v31(vb);
    (*(Owner2_2d6790**)&DAT_0052c2ac)->device->v16(0);
}
