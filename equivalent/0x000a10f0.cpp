// STATUS: equivalent (tools/equiv.py level 3: 3116 inputs, branch coverage 44/44)
// CChaseCamera::vfunc_33 @ 0x000a10f0
struct Vec3_a10f0 {
    float x, y, z;
    void FUN_00011250(Vec3_a10f0 *out, const Vec3_a10f0 *other);
};

struct Owner_a10f0 {
    char pad000[0x338];
    Owner_a10f0 *other;
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
    virtual void vfunc_33(int a1, Owner_a10f0 *who, int event);
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    char pad04[0x194 - 4];
    Vec3_a10f0 pos;
    char pad1a0[0x1b8 - 0x1a0];
    Vec3_a10f0 savedA;
    Vec3_a10f0 lookAt;
    char pad1d0[0x1e8 - 0x1d0];
    Vec3_a10f0 savedB;
    char pad1f4[0x23c - 0x1f4];
    float f23c;
    char pad240[0x320 - 0x240];
    int mode;
    char pad324[0x350 - 0x324];
    Owner_a10f0 *owner;
    char pad354[0x3b4 - 0x354];
    int state;
    int state2;
    float outA;
    float outB;
    float outC;
    char pad3c8[0x3d0 - 0x3c8];
    Vec3_a10f0 snapA;
    Vec3_a10f0 snapB;
    Vec3_a10f0 snapPos;
    char pad3f4[0x400 - 0x3f4];
    int f400;
    int f404;
    int f408;
    float f40c;
    unsigned int mask;
    char pad414[0x478 - 0x414];
    float out2A;
    float out2B;
    float out2C;
    int f484;
    int field488;
    void FUN_000a0c40(int v);
};

void __cdecl FUN_000a04c0(Vec3_a10f0 *delta, float *a, float *b, float *c);

void CChaseCamera::vfunc_33(int a1, Owner_a10f0 *who, int event)
{
    if (owner == 0)
        return;
    if (who != owner) {
        Owner_a10f0 *o2 = owner->other;
        if (o2 == 0 || who != o2)
            return;
    }
    unsigned int bit = 1 << event;
    mask = mask | bit;
    int m = mode;
    if (m == 6)
        return;
    if ((unsigned int)event > 7)
        return;
    Vec3_a10f0 delta;
    switch (event) {
    case 0:
    case 5:
        if (m == 4)
            return;
        FUN_000a0c40(4);
        pos.FUN_00011250(&delta, &lookAt);
        FUN_000a04c0(&delta, &out2A, &out2B, &out2C);
        return;
    case 1:
        if (m == 1)
            return;
        if (!(savedA.y - f23c > 5.0f))
            return;
        FUN_000a0c40(1);
        state = 2;
        pos.FUN_00011250(&delta, &lookAt);
        FUN_000a04c0(&delta, &outA, &outB, &outC);
        snapA = savedA;
        snapB = savedB;
        snapPos = pos;
        field488 = 0;
        return;
    case 2:
        if (m == 3) {
            if (f40c == 0.0f)
                f40c = 0.6f;
            return;
        }
        if (m == 1)
            return;
        FUN_000a0c40(1);
        state2 = 0;
        snapA = savedA;
        snapB = savedB;
        snapPos = pos;
        pos.FUN_00011250(&delta, &lookAt);
        FUN_000a04c0(&delta, &outA, &outB, &outC);
        field488 = 0;
        return;
    case 3:
        if (m == 2 || m == 7)
            return;
        if (m != 3)
            field488 = 0;
        FUN_000a0c40(2);
        f408 = 0;
        f404 = 0;
        f400 = 0;
        return;
    case 4:
        f40c = 0.0f;
        if (m == 3)
            return;
        field488 = 0;
        FUN_000a0c40(3);
        return;
    case 7:
        if (m == 1) {
            if (state == 0)
                return;
            state = 0;
            snapB = savedB;
            return;
        }
        FUN_000a0c40(1);
        state = 0;
        state2 = 0;
        snapA = savedA;
        snapB = savedB;
        snapPos = pos;
        pos.FUN_00011250(&delta, &lookAt);
        FUN_000a04c0(&delta, &outA, &outB, &outC);
        return;
    }
}
