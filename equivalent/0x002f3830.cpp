// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002f3830 @ 0x002f3830
struct Vec3 {
    float x, y, z;
    void FUN_0022dfe0(const Vec3* a, const Vec3* b, const Vec3* c);
};
struct Xform { char data[0x80]; void FUN_0022c3b0(const Vec3* in, Vec3* out); };
struct VertexBuf { char pad[8]; Vec3* verts; };
struct Tri { char pad[0x10]; unsigned short a, b, c; };

class Mesh {
public:
    char pad0[0x44];
    VertexBuf* vb;
    char pad1[4];
    Xform xf;
    char transformed;
    Vec3* GetNormal(Vec3* out, const Tri* t);
};

Vec3* Mesh::GetNormal(Vec3* out, const Tri* t)
{
    Vec3* v = vb->verts;
    Vec3 res;
    Vec3 tmp;
    Vec3* pa = v + t->a;
    Vec3* pb = v + t->b;
    Vec3* pc = v + t->c;
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
