// STATUS: equivalent (tools/equiv.py level 3: 440 inputs, branch coverage 18/18)
// FUN_00308fe0 @ 0x00308fe0
struct V3_308fe0 {
    float x, y, z;
    void Scale(float s) { x = s * x; y = s * y; z = s * z; }
    void Sub(const V3_308fe0 &a, const V3_308fe0 &b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; }
};

struct Matrix4_308fe0 {
    float m[16];
    void FUN_0022c0b0();
    void FUN_0022c2b0(const V3_308fe0 *in, V3_308fe0 *out);
    void FUN_0022c3b0(const V3_308fe0 *in, V3_308fe0 *out);
};

struct SymMatrix {
    int vptr;
    float m[6];
    void FUN_002fca90();
    void FUN_002fcaa0();
    void FUN_002fcaf0(const SymMatrix *src);
    void FUN_002fcd60(const Matrix4_308fe0 *rot);
    void FUN_002fd0a0();
    void FUN_002fd0c0(const SymMatrix *src);
};

struct Part_308fe0 {
    SymMatrix inertia;
    V3_308fe0 pos;
    float mass;
    float massBits;
    unsigned char active;
    char pad31[3];
};

class Body_308fe0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const Matrix4_308fe0 *GetRotation(int i);
    char pad04[0xc];
    Matrix4_308fe0 mat;
};

void __cdecl FUN_00305b00(SymMatrix *out, const V3_308fe0 *p, float mass);

class Hairclub {
public:
    char pad00[0x10];
    Body_308fe0 *body;
    char pad14[0x2c];
    float f40;
    float f44;
    char pad48[0x10];
    Matrix4_308fe0 mat;
    V3_308fe0 center;
    unsigned char flagA4;
    char padA5[3];
    V3_308fe0 va8;
    V3_308fe0 vb4;
    char padC0[0x1c];
    SymMatrix symDC;
    SymMatrix symF8;
    SymMatrix sym114;
    char pad130[0x1f8 - 0x130];
    Part_308fe0 *parts;
    int count;
    void FUN_00308fe0();
};

// The original's frame, in slot order: one transformed point, the part's rotated inertia,
// the centre offset, the point-mass inertia, and one matrix copy reused for both inversions.
struct Frame_308fe0 {
    V3_308fe0 a;
    SymMatrix s1;
    V3_308fe0 b;
    SymMatrix s2;
    Matrix4_308fe0 mt;
};

void Hairclub::FUN_00308fe0()
{
    if (!(f40 > 0.0f))
        return;

    Frame_308fe0 fr;
    center.z = 0;
    center.y = 0;
    center.x = 0;
    for (int i = 0; i < count; i++) {
        if (parts[i].mass > 0.0f && parts[i].active) {
            body->mat.FUN_0022c2b0(&parts[i].pos, &fr.a);
            float m = parts[i].mass;
            center.x = fr.a.x * m + center.x;
            center.y = fr.a.y * m + center.y;
            center.z = fr.a.z * m + center.z;
        }
    }

    center.Scale(f44);
    fr.b.Sub(center, *(const V3_308fe0 *)&body->mat.m[12]);
    fr.mt = mat;
    fr.mt.FUN_0022c0b0();
    fr.mt.FUN_0022c3b0(&fr.b, &va8);
    flagA4 = 0;

    fr.s2.FUN_002fca90();
    fr.s1.FUN_002fca90();
    symF8.FUN_002fd0a0();
    for (int i = 0; i < count; i++) {
        if (parts[i].mass > 0.0f && parts[i].active) {
            body->mat.FUN_0022c2b0(&parts[i].pos, &fr.a);
            fr.a.x = fr.a.x - center.x;
            fr.a.y = fr.a.y - center.y;
            fr.a.z = fr.a.z - center.z;
            FUN_00305b00(&fr.s2, &fr.a, parts[i].mass);
            fr.s1.m[0] = parts[i].inertia.m[0];
            fr.s1.m[1] = parts[i].inertia.m[1];
            fr.s1.m[2] = parts[i].inertia.m[2];
            fr.s1.m[3] = parts[i].inertia.m[3];
            fr.s1.m[4] = parts[i].inertia.m[4];
            fr.s1.m[5] = parts[i].inertia.m[5];
            fr.s1.FUN_002fcd60(body->GetRotation(i));
            fr.s2.FUN_002fcaf0(&fr.s1);
            symF8.FUN_002fcaf0(&fr.s2);
        }
    }

    symDC.m[0] = symF8.m[0];
    symDC.m[1] = symF8.m[1];
    symDC.m[2] = symF8.m[2];
    symDC.m[3] = symF8.m[3];
    symDC.m[4] = symF8.m[4];
    symDC.m[5] = symF8.m[5];
    fr.mt = mat;
    fr.mt.FUN_0022c0b0();
    symDC.FUN_002fcd60(&fr.mt);
    sym114.FUN_002fd0c0(&symF8);
    mat.FUN_0022c3b0(&vb4, &fr.a);
    center.x = fr.a.x + center.x;
    center.y = fr.a.y + center.y;
    center.z = fr.a.z + center.z;
    fr.s1.FUN_002fcaa0();
    fr.s2.FUN_002fcaa0();
}
