// STATUS: equivalent (tools/equiv.py level 3: 211 inputs, branch coverage 18/18)
// FUN_00308fe0 @ 0x00308fe0
struct V3 {
    float x, y, z;
};

struct Matrix4 {
    float m[16];
    void FUN_0022c0b0();
    void FUN_0022c2b0(const V3 *in, V3 *out);
    void FUN_0022c3b0(const V3 *in, V3 *out);
};

struct SymMatrix {
    int vptr;
    float m[6];
    void FUN_002fca90();
    void FUN_002fcaa0();
    void FUN_002fcaf0(const SymMatrix *src);
    void FUN_002fcd60(const Matrix4 *rot);
    void FUN_002fd0a0();
    void FUN_002fd0c0(const SymMatrix *src);
};

struct Part {
    SymMatrix inertia;
    V3 pos;
    float mass;
    float massBits;
    unsigned char active;
    char pad31[3];
};

class Body {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const Matrix4 *GetRotation(int i);
    char pad04[0xc];
    Matrix4 mat;
};

void __cdecl FUN_00305b00(SymMatrix *out, const V3 *p, float mass);

class Hairclub {
public:
    char pad00[0x10];
    Body *body;
    char pad14[0x2c];
    float f40;
    float f44;
    char pad48[0x10];
    Matrix4 mat;
    V3 center;
    unsigned char flagA4;
    char padA5[3];
    V3 va8;
    V3 vb4;
    char padC0[0x1c];
    SymMatrix symDC;
    SymMatrix symF8;
    SymMatrix sym114;
    char pad130[0x1f8 - 0x130];
    Part *parts;
    int count;
    void FUN_00308fe0();
};

void Hairclub::FUN_00308fe0()
{
    if (!(f40 > 0.0f))
        return;

    V3 a;
    center.z = 0;
    center.y = 0;
    center.x = 0;
    for (int i = 0; i < count; i++) {
        if (parts[i].mass > 0.0f && parts[i].active) {
            body->mat.FUN_0022c2b0(&parts[i].pos, &a);
            float m = parts[i].mass;
            center.x = a.x * m + center.x;
            center.y = a.y * m + center.y;
            center.z = a.z * m + center.z;
        }
    }

    float s = f44;
    center.x = s * center.x;
    center.y = s * center.y;
    center.z = s * center.z;

    const float *t = &body->mat.m[12];
    V3 b;
    Matrix4 mt = mat;
    b.x = center.x - t[0];
    b.y = center.y - t[1];
    b.z = center.z - t[2];
    mt.FUN_0022c0b0();
    mt.FUN_0022c3b0(&b, &va8);
    flagA4 = 0;

    SymMatrix s2;
    SymMatrix s1;
    s2.FUN_002fca90();
    s1.FUN_002fca90();
    symF8.FUN_002fd0a0();
    for (int i = 0; i < count; i++) {
        if (parts[i].mass > 0.0f && parts[i].active) {
            body->mat.FUN_0022c2b0(&parts[i].pos, &a);
            a.x = a.x - center.x;
            a.y = a.y - center.y;
            a.z = a.z - center.z;
            FUN_00305b00(&s2, &a, parts[i].mass);
            s1.m[0] = parts[i].inertia.m[0];
            s1.m[1] = parts[i].inertia.m[1];
            s1.m[2] = parts[i].inertia.m[2];
            s1.m[3] = parts[i].inertia.m[3];
            s1.m[4] = parts[i].inertia.m[4];
            s1.m[5] = parts[i].inertia.m[5];
            s1.FUN_002fcd60(body->GetRotation(i));
            s2.FUN_002fcaf0(&s1);
            symF8.FUN_002fcaf0(&s2);
        }
    }

    symDC.m[0] = symF8.m[0];
    symDC.m[1] = symF8.m[1];
    symDC.m[2] = symF8.m[2];
    symDC.m[3] = symF8.m[3];
    symDC.m[4] = symF8.m[4];
    symDC.m[5] = symF8.m[5];
    Matrix4 mt2 = mat;
    mt2.FUN_0022c0b0();
    symDC.FUN_002fcd60(&mt2);
    sym114.FUN_002fd0c0(&symF8);
    mat.FUN_0022c3b0(&vb4, &a);
    center.x = a.x + center.x;
    center.y = a.y + center.y;
    center.z = a.z + center.z;
    s1.FUN_002fcaa0();
    s2.FUN_002fcaa0();
}
