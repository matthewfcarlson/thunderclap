// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 20/20)
// FUN_0027cd10 @ 0x0027cd10
struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(struct Query_27cd10 *q);
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022ca90(Matrix *in, Matrix *by);
    void FUN_0022c120();
};

struct Query_27cd10 {
    char pad0[0xc];
    float x;                    // 0xc
    float y;                    // 0x10
    float z;                    // 0x14
    int field18;                // 0x18
    char pad1c[0x28 - 0x1c];
    char blockA[8];             // 0x28
    char blockB[8];             // 0x30
    int field38;                // 0x38
    int field3c;                // 0x3c
    char pad40[0x48 - 0x40];
    int outMode;                // 0x48
    int inMode;                 // 0x4c
};

struct Palette_27cd10 {
    char pad0[0x1c];
    Matrix *matrices;           // 0x1c
    int FUN_002843a0(int a, int b);
};

struct Holder_27cd10 {
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
    virtual Palette_27cd10 *palette();     // 0x2c
};

struct Target_27cd10 {
    int FUN_00283a40(void *block, Matrix *m, float scale, int f);
    int FUN_00283b10(void *block, Palette_27cd10 *pal, void *block2, Matrix *m, float scale, int f);
    void FUN_0027ff90(int hit, int a, int b);
};

class Renderer_27cd10 {
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
    virtual Matrix *worldMatrix();      // 0x3c
    int field4;
    int field8;                         // 0x8
    int fieldc;                         // 0xc
    char pad10[0x9c - 0x10];
    Holder_27cd10 *holder;                     // 0x9c

    Target_27cd10 *FUN_0027f250();
    void FUN_0027cd10(Query_27cd10 *q);
};

void Renderer_27cd10::FUN_0027cd10(Query_27cd10 *q)
{
    struct Frame {
        Target_27cd10 *target;
        Renderer_27cd10 *self;
        Matrix o2;
        Matrix o1;
        Matrix mc;
    } fr;

    fr.self = this;
    Target_27cd10 *target = FUN_0027f250();
    fr.target = target;
    if (target == 0)
        return;

    Palette_27cd10 *pal = holder->palette();

    switch (q->inMode) {
    case 0:
        fr.o2.FUN_0022b980();
        fr.o2.FUN_0022be40(q);
        fr.o2.FUN_0022bc20(q->x, q->y, q->z);
        {
            int idx = pal->FUN_002843a0(q->field38, q->field3c);
            Matrix *m;
            if (idx == 0xffff)
                m = worldMatrix();
            else
                m = &pal->matrices[idx];
            fr.o1.FUN_0022ca90(&fr.o2, m);
        }
        break;
    case 1:
        fr.o2.FUN_0022b980();
        fr.o2.FUN_0022be40(q);
        fr.o2.FUN_0022bc20(q->x, q->y, q->z);
        fr.o1.FUN_0022ca90(&fr.o2, worldMatrix());
        break;
    case 2:
        fr.o1.FUN_0022b980();
        fr.o1.FUN_0022be40(q);
        fr.o1.FUN_0022bc20(q->x, q->y, q->z);
        break;
    default:
        break;
    }

    int hit;
    switch (q->outMode) {
    case 0: {
        int idx = pal->FUN_002843a0(*(int *)&q->blockB[0], *(int *)&q->blockB[4]);
        Matrix *m;
        if (idx == 0xffff)
            m = worldMatrix();
        else
            m = &pal->matrices[idx];
        fr.mc = *m;
        fr.mc.FUN_0022c120();
        fr.o2.FUN_0022ca90(&fr.o1, &fr.mc);
        hit = fr.target->FUN_00283b10(q->blockA, pal, q->blockB, &fr.o2, -1.0f, q->field18);
        break;
    }
    case 1: {
        fr.mc = *worldMatrix();
        fr.mc.FUN_0022c120();
        fr.o2.FUN_0022ca90(&fr.o1, &fr.mc);
        hit = fr.target->FUN_00283b10(q->blockA, pal, 0, &fr.o2, -1.0f, q->field18);
        break;
    }
    case 2:
        hit = fr.target->FUN_00283a40(q->blockA, &fr.o1, -1.0f, q->field18);
        break;
    default:
        return;
    }

    if (hit)
        fr.target->FUN_0027ff90(hit, fr.self->field8, fr.self->fieldc);
}
