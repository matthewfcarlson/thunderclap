// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002f3830 @ 0x002f3830
struct Vec3_2f3830 {
    float x, y, z;
    void FUN_0022dfe0(const Vec3_2f3830* a, const Vec3_2f3830* b, const Vec3_2f3830* c);
};
struct Xform_2f3830 { char data[0x80]; void FUN_0022c3b0(const Vec3_2f3830* in, Vec3_2f3830* out); };
struct VertexBuf_2f3830 { char pad[8]; Vec3_2f3830* verts; };
struct Tri_2f3830 { char pad[0x10]; unsigned short a, b, c; };

class Mesh_2f3830 {
public:
    char pad0[0x44];
    VertexBuf_2f3830* vb;
    char pad1[4];
    Xform_2f3830 xf;
    char transformed;
    Vec3_2f3830* GetNormal(Vec3_2f3830* out, const Tri_2f3830* t);
};

Vec3_2f3830* Mesh_2f3830::GetNormal(Vec3_2f3830* out, const Tri_2f3830* t)
{
    Vec3_2f3830* v = vb->verts;
    Vec3_2f3830 res;
    Vec3_2f3830 tmp;
    Vec3_2f3830* pa = v + t->a;
    Vec3_2f3830* pb = v + t->b;
    Vec3_2f3830* pc = v + t->c;
    if (transformed) {
        tmp.FUN_0022dfe0(pa, pb, pc);
        xf.FUN_0022c3b0(&tmp, &res);
    } else {
        tmp.FUN_0022dfe0(pa, pb, pc);
        res = tmp;
    }
    *out = res;
    return out;
}
