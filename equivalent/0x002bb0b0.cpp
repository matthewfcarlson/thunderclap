// STATUS: equivalent (tools/equiv.py level 3: 2639 inputs, branch coverage 39/48, incomplete)
// FUN_002bb0b0 @ 0x002bb0b0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void *thunk_FUN_0008d690(unsigned int size);
extern "C" double cos(double);

struct Name {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct Xform {
    void FUN_0022be40(float *pos);
    void FUN_0022ba20(float *quat);
};

struct Base {
    char pad0[8];
    Name name;
    char pad10[0x3c - 0x10];
    int v3c;
    Xform xf;
    char pad40[0x80 - 0x40 - sizeof(Xform)];
    float f80;
    float f84;
    int i88;
    bool b8c;
    char pad8d[3];
    int i90;
    char pad94[4];
    int m98[8];
    int b8[2];
    char padc0[8];
    int ic8;
    int icc;
    Base *FUN_002b8e80();
};

struct BillboardCutOffQuad_2bb0b0 : public Base {
    char padd0[4];
    int d4;
    int d8;
    int dc;
    int e0;
    int e4;
    int e8;
    int ec;
    int f0;
    char padf4[0x110 - 0xf4];
    BillboardCutOffQuad_2bb0b0 *FUN_002b9520();
};

union FI {
    float f;
    int i;
};

struct Frame {
    char pad0[3];
    bool flag;
    FI f4;
    FI f8;
    char pad0c[3];
    unsigned char len;
    int v16;
    float v20;
    int v24;
    int v28;
    int v32;
    unsigned int type;
    float v40;
    int id44;
    int v48;
    float pos[3];
    float quat[4];
    int w80[2];
    int m88[8];
    int dummy120[4];
    char name[256];
};

Base *__stdcall FUN_002bb0b0(Stream *s, void *ctx)
{
    Frame f;
    Reader *r = s->reader;
    r->FUN_002647e0(&f.v16, 1, 4, 1);
    int kind = 0;
    for (int i = 0; i < 3; i++)
        f.pos[i] = 0;
    f.quat[0] = 0;
    f.quat[1] = 0;
    f.quat[2] = 0;
    f.quat[3] = 1.0f;
    f.f4.f = 1.0f;
    f.f8.f = 1.0f;
    f.flag = true;
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    unsigned int len = f.len;
    s->reader->FUN_002647e0(f.name, len, 1, 1);
    f.name[len] = 0;
    s->reader->FUN_002647e0(&f.type, 1, 4, 1);
    s->reader->FUN_002647e0(f.pos, 3, 4, 1);
    s->reader->FUN_002647e0(&f.v16, 1, 4, 1);
    s->reader->FUN_002647e0(f.m88, 8, 4, 1);
    s->reader->FUN_002647e0(&f.v40, 1, 4, 1);
    s->reader->FUN_002647e0(&f.v20, 1, 4, 1);
    s->reader->FUN_002647e0(&f.v24, 1, 4, 1);
    s->reader->FUN_002647e0(f.w80, 2, 4, 1);

    while (s->FUN_002669f0()) {
        int id = s->FUN_00266a30();
        if (id == 0x17003) {
            s->reader->FUN_002647e0(&f.dummy120[1], 1, 4, 1);
            s->reader->FUN_002647e0(f.quat, 4, 4, 1);
            s->reader->FUN_002647e0(&f.id44, 1, 4, 1);
            kind = f.id44;
            s->reader->FUN_002647e0(&f.dummy120[2], 2, 4, 1);
            s->reader->FUN_002647e0(&f.v48, 1, 4, 1);
            f.f4.i = f.v48;
            s->reader->FUN_002647e0(&f.v28, 1, 4, 1);
            f.f8.i = f.v28;
        } else if (id == 0x17004) {
            s->reader->FUN_002647e0(&f.dummy120[0], 1, 4, 1);
            s->reader->FUN_002647e0(&f.v32, 1, 4, 1);
            f.flag = (f.v32 != 0);
        }
        s->FUN_00266be0();
    }

    Base *obj;
    bool generic = true;
    float sum = f.f8.f + f.f4.f;
    if (sum > 0.0f) {
        double c = cos((double)sum);
        if (c >= 0.0 && c <= 1.0)
            f.f8.f = (float)c;
        else
            f.f8.f = (c > 1.0) ? 1.0f : 0.0f;
        c = cos((double)f.f4.f);
        if (c >= 0.0 && c <= 1.0)
            f.f4.f = (float)c;
        else
            f.f4.f = (c > 1.0) ? 1.0f : 0.0f;

        if (kind == 0x474e53 || kind == 0x4c4244) {
            void *mem = thunk_FUN_0008d690(0x110);
            BillboardCutOffQuad_2bb0b0 *o = 0;
            if (mem)
                o = ((BillboardCutOffQuad_2bb0b0 *)mem)->FUN_002b9520();
            int a = f.f4.i;
            int b = f.f8.i;
            o->ic8 = 3;
            o->d4 = a;
            o->d8 = b;
            o->dc = a;
            o->e0 = b;
            o->icc = 0;
            obj = o;
            generic = false;
        } else if (kind == 0x4d4143) {
            void *mem = thunk_FUN_0008d690(0x110);
            BillboardCutOffQuad_2bb0b0 *o = 0;
            if (mem)
                o = ((BillboardCutOffQuad_2bb0b0 *)mem)->FUN_002b9520();
            int a = f.f4.i;
            int b = f.f8.i;
            o->ic8 = 0;
            o->icc = 3;
            o->e4 = a;
            o->e8 = b;
            o->ec = a;
            o->f0 = b;
            obj = o;
            generic = false;
        }
    }
    if (generic) {
        void *mem = thunk_FUN_0008d690(0xc8);
        obj = 0;
        if (mem)
            obj = ((Base *)mem)->FUN_002b8e80();
    }

    obj->name.FUN_0027b040(f.name);

    int mode;
    switch (f.type) {
    case 0x58414f4e: mode = 0; break;
    case 0x584158: mode = 2; break;
    case 0x584159: mode = 3; break;
    case 0x5841584c: mode = 4; break;
    case 0x5841594c: mode = 5; break;
    default: mode = 1; break;
    }
    obj->b8c = f.flag;
    obj->i90 = mode;
    obj->xf.FUN_0022be40(f.pos);
    obj->xf.FUN_0022ba20(f.quat);
    obj->f80 = f.v40 * 0.5f;
    obj->i88 = f.v24;
    obj->v3c = f.v16;
    obj->f84 = f.v20 * 0.5f;
    for (int i = 0; i < 8; i++)
        obj->m98[i] = f.m88[i];
    obj->b8[0] = f.w80[0];
    obj->b8[1] = f.w80[1];
    return obj;
}
