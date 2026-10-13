// STATUS: equivalent (tools/equiv.py level 3: 253 inputs, branch coverage 59/61, incomplete)
// FUN_002ba8d0 @ 0x002ba8d0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
extern "C" double cos(double);

void *thunk_FUN_0008d690(unsigned int size);

struct Stream {
    int FUN_002647e0(void *buf, int count, int size, int flag);
};

struct Reader {
    char pad0[0x284];
    Stream *stream;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct NameHolder {
    char pad[8];
    void FUN_0027b040(const char *name);
};

struct Sub40 {
    char pad[0x40];
    void FUN_0022ba20(const void *q);
    void FUN_0022be40(const void *v);
};

struct Obj {
    char pad0[8];
    NameHolder nameHolder;      // 0x08
    char pad10[0x3c - 0x10];
    int f3c;
    Sub40 f40;
    float f80;
    float f84;
    int f88;
    bool b8c;
    char pad8d[3];
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
    union {
        int fa8;
        float fa8f;
    };
    int fac;
    union {
        int fb0;
        float fb0f;
    };
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    unsigned int fc4;
    int fc8;
    int fcc;
    int fd0;
    float fd4, fd8, fdc, fe0, fe4, fe8, fec, ff0;
    int ff4, ff8, ffc, f100, f104, f108;
};

struct Big : Obj {
    Big *FUN_002b9520();
};

struct Small : Obj {
    Small *FUN_002b8e80();
};

int __cdecl FUN_002b87d0(int v);
int __cdecl FUN_002b8800(int v);

struct Frame {
    char pad0[3];
    char flag;          // 0x03
    int t1a4;           // 0x04
    int t1a0;           // 0x08
    int t19c;           // 0x0c
    int t198;           // 0x10
    int t194;           // 0x14
    int t190;           // 0x18
    int t18c;           // 0x1c
    int t188;           // 0x20
    int t184;           // 0x24
    int t180;           // 0x28
    int t17c;           // 0x2c
    int t178;           // 0x30
    int t174;           // 0x34
    int t170;           // 0x38
    int t16c;           // 0x3c
    int t168;           // 0x40
    int t164;           // 0x44
    int t160;           // 0x48
    int t15c;           // 0x4c
    int t158;           // 0x50
    int t154;           // 0x54
    int t150;           // 0x58
    int t14c;           // 0x5c
    int t148;           // 0x60
    int t144;           // 0x64
    int t140;           // 0x68
    int t13c;           // 0x6c
    int t138;           // 0x70
    int t134;           // 0x74
    int t130;           // 0x78
    int t12c;           // 0x7c
    int t128;           // 0x80
    int t124;           // 0x84
    int t120;           // 0x88
    int t11c[3];        // 0x8c
    int q110[4];        // 0x98
    char name[0x100];   // 0xa8
};

Obj *__stdcall FUN_002ba8d0(Reader *r, int unused)
{
    Frame f;
    Obj *o;

    r->stream->FUN_002647e0(&f.t19c, 1, 4, 1);
    r->stream->FUN_002647e0(&f.flag, 1, 1, 1);
    unsigned int len = (unsigned char)f.flag;
    r->stream->FUN_002647e0(f.name, len, 1, 1);
    f.name[len] = 0;
    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    bool big = (f.t1a4 != 0);
    f.flag = big;
    if (big) {
        Big *b = (Big *)thunk_FUN_0008d690(0x110);
        if (b != 0)
            o = b->FUN_002b9520();
        else
            o = 0;
    } else {
        Small *s = (Small *)thunk_FUN_0008d690(0xc8);
        if (s != 0)
            o = s->FUN_002b8e80();
        else
            o = 0;
    }
    o->nameHolder.FUN_0027b040(f.name);

    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    o->b8c = (f.t1a4 != 0);
    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    switch ((unsigned int)f.t1a4) {
    case 0x58414f4e:
        o->f90 = 0;
        break;
    case 0x584158:
        o->f90 = 2;
        break;
    case 0x584159:
        o->f90 = 3;
        break;
    case 0x5841584c:
        o->f90 = 4;
        break;
    case 0x5841594c:
        o->f90 = 5;
        break;
    default:
        o->f90 = 1;
        break;
    }
    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    o->f3c = f.t1a4;
    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    o->f80 = *(float *)&f.t1a4 * 0.5f;
    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    o->f84 = *(float *)&f.t1a4 * 0.5f;
    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    o->f88 = f.t1a4;

    while (r->FUN_002669f0()) {
        switch (r->FUN_00266a30()) {
        case 0x17007:
            r->stream->FUN_002647e0(&f.t13c, 1, 4, 1);
            r->stream->FUN_002647e0(f.q110, 4, 4, 1);
            o->f40.FUN_0022ba20(f.q110);
            r->stream->FUN_002647e0(f.t11c, 3, 4, 1);
            o->f40.FUN_0022be40(f.t11c);
            break;
        case 0x17008:
            r->stream->FUN_002647e0(&f.t120, 1, 4, 1);
            r->stream->FUN_002647e0(&f.t15c, 1, 4, 1);
            o->f94 = (f.t15c != 0) + 1;
            r->stream->FUN_002647e0(&f.t1a0, 1, 2, 1);
            o->fc4 = *(unsigned short *)&f.t1a0;
            r->stream->FUN_002647e0(&f.t1a4, 1, 2, 1);
            {
                unsigned int w = *(unsigned short *)&f.t1a4;
                if (w > o->fc4)
                    w = o->fc4;
                o->fc0 = w;
            }
            {
                float inv = 1.0f / (float)o->fc4;
                o->fb0f = inv;
                o->fa8f = inv;
            }
            break;
        case 0x17009:
            r->stream->FUN_002647e0(&f.t124, 1, 4, 1);
            r->stream->FUN_002647e0(&f.t16c, 1, 4, 1);
            {
                bool p = (f.t16c != 0);
                r->stream->FUN_002647e0(&f.t190, 1, 4, 1);
                bool q = (f.t190 != 0);
                if (p == 1) {
                    o->f94 = (q == p) * 2 + 3;
                } else if (q == 1) {
                    o->f94 = 4;
                }
            }
            {
                int *dst = &o->f98;
                int n;
                for (n = 0; n < 4; n++) {
                    r->stream->FUN_002647e0(&f.t164, 1, 4, 1);
                    dst[0] = f.t164;
                    r->stream->FUN_002647e0(&f.t188, 1, 4, 1);
                    dst[1] = f.t188;
                    dst += 2;
                }
            }
            r->stream->FUN_002647e0(&f.t160, 1, 4, 1);
            o->fb8 = f.t160;
            r->stream->FUN_002647e0(&f.t180, 1, 4, 1);
            o->fbc = f.t180;
            break;
        case 0x1700a:
            if (big == 1) {
                r->stream->FUN_002647e0(&f.t128, 1, 4, 1);
                r->stream->FUN_002647e0(&f.t158, 1, 4, 1);
                o->fc8 = FUN_002b87d0(f.t158);
                r->stream->FUN_002647e0(&f.t178, 1, 4, 1);
                o->fd4 = (float)cos((double)*(float *)&f.t178);
                r->stream->FUN_002647e0(&f.t150, 1, 4, 1);
                o->fd8 = (float)cos((double)*(float *)&f.t150);
                r->stream->FUN_002647e0(&f.t170, 1, 4, 1);
                o->fdc = (float)cos((double)*(float *)&f.t170);
                r->stream->FUN_002647e0(&f.t148, 1, 4, 1);
                o->fe0 = (float)cos((double)*(float *)&f.t148);
            }
            break;
        case 0x1700b:
            if (big == 1) {
                r->stream->FUN_002647e0(&f.t138, 1, 4, 1);
                r->stream->FUN_002647e0(&f.t168, 1, 4, 1);
                o->fcc = FUN_002b8800(f.t168);
                r->stream->FUN_002647e0(&f.t140, 1, 4, 1);
                o->fe4 = (float)cos((double)*(float *)&f.t140);
                r->stream->FUN_002647e0(&f.t144, 1, 4, 1);
                o->fe8 = (float)cos((double)*(float *)&f.t144);
                r->stream->FUN_002647e0(&f.t198, 1, 4, 1);
                o->fec = (float)cos((double)*(float *)&f.t198);
                r->stream->FUN_002647e0(&f.t14c, 1, 4, 1);
                o->ff0 = (float)cos((double)*(float *)&f.t14c);
            }
            break;
        case 0x1700c:
            if (big == 1) {
                r->stream->FUN_002647e0(&f.t134, 1, 4, 1);
                r->stream->FUN_002647e0(&f.t154, 1, 4, 1);
                o->fd0 = (f.t154 == 0x454e494c);
                r->stream->FUN_002647e0(&f.t194, 1, 4, 1);
                o->f104 = f.t194;
                r->stream->FUN_002647e0(&f.t18c, 1, 4, 1);
                o->f108 = f.t18c;
            }
            break;
        case 0x1700d:
            r->stream->FUN_002647e0(&f.t12c, 1, 4, 1);
            r->stream->FUN_002647e0(&f.t184, 1, 4, 1);
            o->ff4 = f.t184;
            r->stream->FUN_002647e0(&f.t17c, 1, 4, 1);
            o->ff8 = f.t17c;
            r->stream->FUN_002647e0(&f.t174, 1, 4, 1);
            o->ffc = f.t174;
            r->stream->FUN_002647e0(&f.t19c, 1, 4, 1);
            o->f100 = f.t19c;
            break;
        default:
            break;
        }
        r->FUN_00266be0();
    }
    return o;
}
