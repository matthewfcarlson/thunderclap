// STATUS: equivalent (tools/equiv.py level 3: 104 inputs, branch coverage 19/22, incomplete)
// CChaseCamera::vfunc_34 @ 0x000a1520
extern "C" double atan2(double y, double x);

struct Vec3_a1520 {
    float x, y, z;
};

class CChaseCamera {
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void vfunc_34(int a1, int a2, float a3, float a4, float a5);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    char pad04[0x194 - 4];
    Vec3_a1520 pos;
    char pad1a0[0x1b8 - 0x1a0];
    Vec3_a1520 savedA;
    Vec3_a1520 lookAt;
    char pad1d0[0x1e8 - 0x1d0];
    Vec3_a1520 savedB;
    char pad1f4[0x320 - 0x1f4];
    int mode;
    char pad324[0x350 - 0x324];
    int owner;
    char pad354[0x3b4 - 0x354];
    int state;
    int state2;
    float outA;
    float outB;
    float outC;
    float value;
    char pad3cc[0x3d0 - 0x3cc];
    Vec3_a1520 snapA;
    Vec3_a1520 snapB;
    Vec3_a1520 snapPos;
    char pad3f4[0x40c - 0x3f4];
    int field40c;
    char pad410[0x440 - 0x410];
    float limit;
    char pad444[0x488 - 0x444];
    int field488;
    char pad48c[0x4bb - 0x48c];
    unsigned char flag4bb;
    void FUN_000a0c40(int v);
};

void __cdecl FUN_000a04c0(Vec3_a1520 *delta, float *a, float *b, float *c);

void CChaseCamera::vfunc_34(int a1, int a2, float a3, float a4, float a5)
{
    if (owner == 0 || a2 != owner) {
        return;
    }
    double inv = 1.0f / a5;
    float ratio = a4 * inv;
    float energy = inv * a4 * a4 * 0.5f;
    float angle = atan2(a4, a3) * 57.2958f;

    if (mode == 3 && (ratio < 0.5f || angle < 60.0f)) {
        FUN_000a0c40(1);
        state = 2;
        state2 = 0;
        snapA = savedA;
        snapB = savedB;
        snapPos = pos;
        Vec3_a1520 delta;
        delta.x = pos.x - lookAt.x;
        delta.y = pos.y - lookAt.y;
        delta.z = pos.z - lookAt.z;
        FUN_000a04c0(&delta, &outA, &outB, &outC);
        field40c = 0;
        field488 = 0;
        if (angle < 60.0f) {
            flag4bb = 1;
        }
        return;
    }

    if (mode == 0 && ratio < 0.5f && 0.9f * limit > energy && angle > 70.0f) {
        state = 0;
        value = a5;
        return;
    }
    if (angle < 80.0f) {
        state = 2;
    } else {
        state = 1;
    }
    value = a5;
}
