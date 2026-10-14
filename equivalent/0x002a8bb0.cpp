// STATUS: equivalent (tools/equiv.py level 3: 145 inputs, branch coverage 76/84, incomplete)
// pure3d::LightAnimationController::vfunc_28 @ 0x002a8bb0
struct V3 {
    float x, y, z;
};

class VChan {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(unsigned int t, V3 *out);
};

struct ColChan {
    void FUN_0028ad20(unsigned int t, unsigned int *out);
};

struct BoolChan {
    void FUN_0028ac90(unsigned int t, char *out);
};

struct Chans {
    void *FUN_00288960(int a, int b);
};

struct Anim {
    Chans *FUN_00288a10(int i);
};

struct Elem {
    char pad[0x2c];
    Anim *FUN_00284f50();
    float FUN_00284f70();
    float FUN_00284f60();
};

class Light {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(V3 *out);
    void FUN_002c3f00(float x, float y, float z);
    void FUN_002a2fc0(V3 *v);
    void FUN_002c4250(V3 *v);
    void FUN_002c41a0(float x, float y, float z);
    void FUN_002c41e0(float x, float y, float z);
    void FUN_002c3d00(float x, float y, float z);
    void FUN_002a07a0(unsigned int color);
    void FUN_002a0820(char flag);
};

struct Sink {
    void FUN_00293e90(unsigned int color);
};
struct SinkHolder {
    char pad0[8];
    Sink *f8;
};
extern SinkHolder *DAT_0052c2b4;

union Slot {
    volatile float f;
    unsigned int u;
    int i;
};

struct Frame {
    Slot s0, s4, s8, sc;                // 0x00..0x0c
    volatile float acc0, acc1, acc2, acc3;  // 0x10..0x1c
    char pad20[3];
    char flag;                          // 0x23
    volatile float cx, cy, cz;          // 0x24
    volatile float dx, dy, dz;          // 0x30
    volatile float ax, ay, az;          // 0x3c
    volatile float e;                   // 0x48
    volatile float bx, by, bz;          // 0x4c
    int idx;                            // 0x58
    V3 tdir;                            // 0x5c
    V3 tcone;                           // 0x68
    V3 tattn;                           // 0x74
    V3 tpos;                            // 0x80
};

class LightAnimationController {
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
    char pad04[0x28 - 4];
    unsigned int count;         // 0x28
    Elem elems[1];              // 0x2c
    char pad58[0x110 - 0x58];
    int mode;                   // 0x110
    Light *light;               // 0x114
};

void LightAnimationController::v28()
{
    Frame f;
    unsigned int cnt = count;
    unsigned int color;
    int c0, c1, c2, c3;

    f.acc3 = 0.0f;
    f.acc2 = 0.0f;
    f.acc1 = 0.0f;
    f.acc0 = 0.0f;
    if (light != 0) {
        f.ax = 0.0f;
        f.ay = 0.0f;
        f.az = 0.0f;
        f.bx = 0.0f;
        f.by = 0.0f;
        f.bz = 0.0f;
        f.cx = 0.0f;
        f.cy = 0.0f;
        f.cz = 0.0f;
        f.dx = 0.0f;
        f.dy = 0.0f;
        f.dz = 0.0f;
        f.e = 0.0f;
        f.idx = 0;
        if (cnt != 0) {
            Elem *el = &elems[0];
            do {
                Chans *Y = el->FUN_00284f50()->FUN_00288a10(0);
                f.s8.f = el->FUN_00284f70();
                f.s4.f = el->FUN_00284f60();
                f.s0.f = 1.0f - f.s4.f;
                unsigned int t = f.s8.u;
                void *clr = Y->FUN_00288960(0x524c43, 0x524c43);
                if (clr != 0) {
                    ((ColChan *)clr)->FUN_0028ad20(t, &f.sc.u);
                    unsigned int col = f.sc.u;
                    f.s8.i = (col >> 16) & 0xff;
                    f.acc0 = (float)f.s8.i * f.s4.f + f.s0.f * f.acc0;
                    f.s8.i = (col >> 8) & 0xff;
                    f.acc1 = (float)f.s8.i * f.s4.f + f.s0.f * f.acc1;
                    f.s8.i = col & 0xff;
                    f.acc2 = (float)f.s8.i * f.s4.f + f.s0.f * f.acc2;
                    f.s8.i = col >> 24;
                    f.acc3 = (float)f.s8.i * f.s4.f + f.s0.f * f.acc3;
                }
                void *pv = Y->FUN_00288960(0x4d524150, 0x54434556);
                if (pv != 0) {
                    ((VChan *)pv)->v4(t, &f.tpos);
                    f.az = f.az * f.s0.f;
                    f.ax = f.tpos.x * f.s4.f + f.ax * f.s0.f;
                    f.ay = f.tpos.y * f.s4.f + f.ay * f.s0.f;
                    f.az = f.tpos.z * f.s4.f + f.az;
                }
                void *pd = Y->FUN_00288960(0x524944, 0x54434556);
                if (pd != 0) {
                    ((VChan *)pd)->v4(t, &f.tdir);
                    f.bz = f.tdir.z * f.s0.f;
                    f.bx = f.tdir.x * f.s4.f + f.tdir.x * f.s0.f;
                    f.by = f.tdir.y * f.s4.f + f.tdir.y * f.s0.f;
                    f.bz = f.tdir.z * f.s4.f + f.bz;
                }
                void *pa = Y->FUN_00288960(0x4e545441, 0x54434556);
                if (pa != 0) {
                    ((VChan *)pa)->v4(t, &f.tattn);
                    f.cz = f.cz * f.s0.f;
                    f.cx = f.tattn.x * f.s4.f + f.cx * f.s0.f;
                    f.cy = f.tattn.y * f.s4.f + f.cy * f.s0.f;
                    f.cz = f.tattn.z * f.s4.f + f.cz;
                }
                void *pc = Y->FUN_00288960(0x454e4f43, 0x54434556);
                if (pc != 0) {
                    ((VChan *)pc)->v4(t, &f.tcone);
                    f.dz = f.dz * f.s0.f;
                    f.dx = f.tcone.x * f.s4.f + f.dx * f.s0.f;
                    f.dy = f.tcone.y * f.s4.f + f.dy * f.s0.f;
                    f.dz = f.tcone.z * f.s4.f + f.dz;
                }
                void *pe = Y->FUN_00288960(0x4c424145, 0x4c4f4f42);
                if (pe != 0) {
                    ((BoolChan *)pe)->FUN_0028ac90(t, &f.flag);
                    f.e = (f.flag == 1 ? 1.0f : 0.0f) * f.s4.f + f.s0.f * f.e;
                }
                f.idx++;
                el++;
            } while ((unsigned int)f.idx < count);
        }
        switch (mode) {
        case 1:
            light->v8((V3 *)&f.ax);
            light->FUN_002c3f00(f.cx, f.cy, f.cz);
            break;
        case 2:
            light->FUN_002a2fc0((V3 *)&f.bx);
            break;
        case 3:
            light->v8((V3 *)&f.ax);
            light->FUN_002c4250((V3 *)&f.bx);
            light->FUN_002c41a0(f.cx, f.cy, f.cz);
            light->FUN_002c41e0(f.dx, f.dy, f.dz);
            break;
        case 4:
            light->FUN_002c3d00(f.cx, f.cy, f.cz);
            break;
        default:
            break;
        }
        c0 = (int)f.acc0;
        if (c0 < 0)
            c0 = 0;
        else if (c0 > 0xff)
            c0 = 0xff;
        c1 = (int)f.acc1;
        if (c1 < 0)
            c1 = 0;
        else if (c1 > 0xff)
            c1 = 0xff;
        c2 = (int)f.acc2;
        if (c2 < 0)
            c2 = 0;
        else if (c2 > 0xff)
            c2 = 0xff;
        c3 = (int)f.acc3;
        if (c3 < 0)
            c3 = 0;
        else if (c3 > 0xff)
            c3 = 0xff;
        color = (((c3 << 8 | c0) << 8 | c1) << 8) | c2;
        light->FUN_002a07a0(color);
        if (f.e > 0.5f)
            light->FUN_002a0820(1);
        else
            light->FUN_002a0820(0);
        return;
    }

    if (cnt != 0) {
        Elem *el = &elems[0];
        unsigned int i = 0;
        do {
            Chans *Y = el->FUN_00284f50()->FUN_00288a10(0);
            f.sc.f = el->FUN_00284f70();
            f.s0.f = el->FUN_00284f60();
            f.s4.f = 1.0f - f.s0.f;
            void *clr = Y->FUN_00288960(0x524c43, 0x524c43);
            if (clr != 0) {
                ((ColChan *)clr)->FUN_0028ad20(f.sc.u, &f.s8.u);
                unsigned int col = f.s8.u;
                f.sc.i = (col >> 16) & 0xff;
                f.acc0 = (float)f.sc.i * f.s0.f + f.s4.f * f.acc0;
                f.sc.i = (col >> 8) & 0xff;
                f.acc1 = (float)f.sc.i * f.s0.f + f.s4.f * f.acc1;
                f.sc.i = col & 0xff;
                f.acc2 = (float)f.sc.i * f.s0.f + f.s4.f * f.acc2;
                f.sc.i = col >> 24;
                f.acc3 = (float)f.sc.i * f.s0.f + f.s4.f * f.acc3;
            }
            i++;
            el++;
        } while (i < count);
    }
    c0 = (int)f.acc0;
    if (c0 < 0)
        c0 = 0;
    else if (c0 > 0xff)
        c0 = 0xff;
    c1 = (int)f.acc1;
    if (c1 < 0)
        c1 = 0;
    else if (c1 > 0xff)
        c1 = 0xff;
    c2 = (int)f.acc2;
    if (c2 < 0)
        c2 = 0;
    else if (c2 > 0xff)
        c2 = 0xff;
    c3 = (int)f.acc3;
    if (c3 < 0)
        c3 = 0;
    else if (c3 > 0xff)
        c3 = 0xff;
    Sink *sink = DAT_0052c2b4->f8;
    if (sink != 0) {
        color = (((c3 << 8 | c0) << 8 | c1) << 8) | c2;
        sink->FUN_00293e90(color);
    }
}
