// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// pure3d::Sprite::vfunc_6 @ 0x002bdd40
struct Vec3 {
    float x, y, z;
};

struct Shader {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void SetTexture(int id, void *tex);
};

struct Material {
    char pad0[0x10];
    Shader *shader;
};

struct Quad {
    Vec3 pos;
    float w;
    float uv[2];
};

struct Batch {
    void FUN_0008ef00();
    char pad0[8];
    Vec3 *pos;
    char pad1[4];
    float *w;
    float *uv;
};

class Device {
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
    virtual Batch *CreateBatch(void *obj, int a, int b, int c, int d);
    virtual void Submit(Batch *b);
};

extern Device *DAT_0052c2a8;

struct Texture {
    char pad0[0x10];
    void *tex;
};

struct Verts {
    Quad corner[4];
};

namespace pure3d {
class Sprite {
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
    char pad0[0x40 - 4];
    int count;
    Verts *verts;
    Texture **textures;
    Material *material;
};
}

void pure3d::Sprite::vfunc_6()
{
    for (int i = 0; i < count; i++) {
        Texture *t = textures[i];
        material->shader->SetTexture(0x584554, t->tex);
        Batch *b = DAT_0052c2a8->CreateBatch(material->shader, 1, 0x2021, 4, 0);
        for (int k = 0; k < 4; k++) {
            Quad *q = &verts[i].corner[k];
            float w = q->w;
            Vec3 *p = b->pos;
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
