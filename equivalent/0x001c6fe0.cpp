// STATUS: equivalent (tools/equiv.py level 3: 140 inputs, branch coverage 17/18, incomplete)
// Render::RoomLoader::vfunc_5 @ 0x001c6fe0
// cl-flags: /GS
void *FUN_0008d690(unsigned int size);
extern "C" int __cdecl FUN_001c62f0(const char *name, int n);

struct V3_1c6fe0 {
    float x, y, z;
};

struct Name_1c6fe0 {
    char data[8];
    void FUN_0027b0e0(const char *s);
    void FUN_0027af50();
};

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    bool FUN_002669f0();
    int FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
};

struct Arr_1c6fe0 {
    void FUN_001c2770(int count, int *items);
};

struct Obj_1c6fe0 {
    char pad0[0x14];
    char *recs;
    char pad18[0x56 - 0x18];
    short w56;
    char pad58[0x60 - 0x58];
    Obj_1c6fe0 *FUN_001c6e60(Name_1c6fe0 *nm, int z0, int z1, int a, int *vals, int idx, V3_1c6fe0 *va, int *desc);
};

struct Mgr_1c6fe0 {
    void FUN_001c7e90(Obj_1c6fe0 *o);
};

struct Item_1c6fe0 {
    int f0;
    int f1;
    int f2;
    int f3;
};

struct Frame_1c6fe0 {
    char pad0[3];
    unsigned char len;     // S3
    int x4;                // S4
    int flag8;             // S8
    union {                // S12
        int a;
        Obj_1c6fe0 *obj;
    };
    int c16;               // S16
    int b20;               // S20
    int t24;               // S24
    int t28;               // S28
    void *self;            // S32 (this)
    int t36;               // S36
    Name_1c6fe0 nm;               // S40
    V3_1c6fe0 vC;                 // S48
    int v1;                // S60
    int v2;                // S64
    int v3;                // S68
    V3_1c6fe0 vA;                 // S72
    V3_1c6fe0 vB;                 // S84
    int desc[10];          // S96
    char b4[256];          // S136
    char b1[256];          // S392
    char b5[256];          // S648
    char b2[256];          // S904
    char b3[256];          // S1160
    Item_1c6fe0 items[16];        // S1416
};

namespace Render {

class RoomLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(int *out0, unsigned __int64 *out1, Stream *s, void *inv);
    char pad04[0x10];
    Mgr_1c6fe0 *mgr;   // 0x14
};

void RoomLoader::vfunc_5(int *out0, unsigned __int64 *out1, Stream *s, void *inv)
{
    Frame_1c6fe0 f;
    f.self = this;
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    f.flag8 = 0;
    unsigned int n = f.len;
    s->reader->FUN_002647e0(f.b1, n, 1, 1);
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    f.b1[n] = 0;
    n = f.len;
    s->reader->FUN_002647e0(f.b2, n, 1, 1);
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    f.b2[n] = 0;
    n = f.len;
    s->reader->FUN_002647e0(f.b3, n, 1, 1);
    f.b3[n] = 0;
    for (int i = 0; i < 64; i++)
        ((volatile int *)f.b4)[i] = 0;
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    n = f.len;
    s->reader->FUN_002647e0(f.b4, n, 1, 1);
    f.b4[n] = 0;
    for (int i = 0; i < 64; i++)
        ((volatile int *)f.b5)[i] = 0;
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    n = f.len;
    s->reader->FUN_002647e0(f.b5, n, 1, 1);
    s->reader->FUN_002647e0(&f.a, 1, 4, 1);
    f.b5[n] = 0;
    s->reader->FUN_002647e0(&f.b20, 1, 4, 1);
    s->reader->FUN_002647e0(&f.c16, 1, 4, 1);
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    n = f.len;
    s->reader->FUN_002647e0(f.b2, n, 1, 1);
    s->reader->FUN_002647e0(&f.x4, 1, 4, 1);
    f.b2[n] = 0;
    f.v1 = f.x4;
    s->reader->FUN_002647e0(&f.x4, 1, 4, 1);
    f.v2 = f.x4;
    s->reader->FUN_002647e0(&f.x4, 1, 4, 1);
    f.v3 = f.x4;
    s->reader->FUN_002647e0(&f.vA, 3, 4, 1);
    s->reader->FUN_002647e0(&f.vB, 3, 4, 1);
    s->reader->FUN_002647e0(&f.vC, 3, 4, 1);
    s->reader->FUN_002647e0(&f.x4, 1, 4, 1);

    void *mem = FUN_0008d690(0x60);
    Obj_1c6fe0 *obj;
    if (mem) {
        f.nm.FUN_0027b0e0(f.b1);
        f.desc[0] = ((int *)&f.vC)[0];
        f.desc[1] = ((int *)&f.vC)[1];
        f.desc[2] = ((int *)&f.vC)[2];
        f.desc[3] = f.x4;
        f.desc[4] = ((int *)&f.vA)[0];
        f.desc[5] = ((int *)&f.vA)[1];
        f.desc[6] = ((int *)&f.vA)[2];
        f.desc[7] = ((int *)&f.vB)[0];
        f.desc[8] = ((int *)&f.vB)[1];
        f.desc[9] = ((int *)&f.vB)[2];
        f.flag8 = 1;
        int idx = FUN_001c62f0(f.b1, 0x52);
        if (idx < 0)
            idx = 0;
        obj = ((Obj_1c6fe0 *)mem)->FUN_001c6e60(&f.nm, 0, 0, f.a, &f.v1, idx, (V3_1c6fe0 *)&f.desc[4], f.desc);
        f.obj = obj;
    } else {
        f.obj = 0;
        obj = 0;
    }
    if (f.flag8 & 1)
        f.nm.FUN_0027af50();
    obj->w56 = (short)f.c16;
    if (s->FUN_002669f0()) {
        f.flag8 = 0;
        do {
            s->FUN_00266a30();
            if (s->FUN_00266c30() == 0x60000703) {
                s->reader->FUN_002647e0(&f.c16, 1, 4, 1);
                f.len = (f.c16 != 0);
                s->reader->FUN_002647e0(&f.x4, 1, 4, 1);
                unsigned int count = f.x4;
                if (count != 0) {
                    Item_1c6fe0 *it = f.items;
                    for (unsigned int i = count; i != 0; i--) {
                        s->reader->FUN_002647e0(&f.t24, 1, 4, 1);
                        it->f0 = f.t24;
                        s->reader->FUN_002647e0(&f.t28, 1, 4, 1);
                        it->f1 = f.t28;
                        s->reader->FUN_002647e0(&f.t36, 1, 4, 1);
                        it->f2 = f.t36;
                        s->reader->FUN_002647e0(&f.b20, 1, 4, 1);
                        it->f3 = f.b20;
                        it++;
                    }
                    obj = f.obj;
                    count = f.x4;
                }
                char *rec = obj->recs + f.flag8;
                *rec = (char)f.len;
                ((Arr_1c6fe0 *)(rec + 4))->FUN_001c2770((int)count, (int *)f.items);
                f.flag8 += 0xa8;
            }
            s->FUN_00266be0();
        } while (s->FUN_002669f0());
    }
    ((RoomLoader *)f.self)->mgr->FUN_001c7e90(obj);
    *out0 = 0;
    out1[0] = 0;
}

}
