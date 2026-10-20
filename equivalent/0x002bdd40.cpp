// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// pure3d::Sprite::vfunc_6 @ 0x002bdd40
#include "gen/pure3d.h"

#include "decls/address.h"
struct Vec3_2bdd40 {
    float x, y, z;
};

struct Shader_2bdd40 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void SetTexture(int id, void *tex);
};

struct Material_2bdd40 {
    char pad0[0x10];
    Shader_2bdd40 *shader;
};

struct Quad_2bdd40 {
    Vec3_2bdd40 pos;
    float w;
    float uv[2];
};

struct Batch_2bdd40 {
    void FUN_0008ef00();
    char pad0[8];
    Vec3_2bdd40 *pos;
    char pad1[4];
    float *w;
    float *uv;
};

class Gfx {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual Batch_2bdd40 *CreateBatch(void *obj, int a, int b, int c, int d);
    virtual void Submit(Batch_2bdd40 *b);
};

struct Texture_2bdd40 {
    char pad0[0x10];
    void *tex;
};

struct Verts {
    Quad_2bdd40 corner[4];
};

namespace pure3d {
}
void pure3d::Sprite::vfunc_6() {
    for (int i = 0; i < this->f_40; i++) {
        Texture_2bdd40 *t = (*(Texture_2bdd40 ** *)&this->f_48)[i];
        (*(Material_2bdd40 * *)&this->f_4c)->shader->SetTexture(0x584554, t->tex);
        Batch_2bdd40 *b = DAT_0052c2a8->CreateBatch((*(Material_2bdd40 * *)&this->f_4c)->shader, 1, 0x2021, 4, 0);
        for (int k = 0; k < 4; k++) {
            Quad_2bdd40 *q = &(*(Verts * *)&this->f_44)[i].corner[k];
            float w = q->w;
            Vec3_2bdd40 *p = b->pos;
            p->x = q->pos.x;
            p->y = q->pos.y;
            p->z = q->pos.z;
            *b->w = w;
            b->uv[0] = q->uv[0];
            b->uv[1] = q->uv[1];
            b->FUN_0008ef00();
        }
        DAT_0052c2a8->Submit(b);
    }
}
