// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 10/12, incomplete)
// FUN_002c0590 @ 0x002c0590
struct Name_2c0590 {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
};

struct Sprite {
    char pad0[8];
    Name_2c0590 name;
    char pad10[0x28 - 0x10];
    char flag;
};

struct Stream {
    void FUN_002647e0(void *dst, int a, int b, int c);
};

struct Reader {
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c90();
    void FUN_00266ca0(int v);
};

struct Factory_2c0590 {
    char pad0[0x8c];
    int f8c;
    Sprite *FUN_002aecb0(char *name);
    Sprite *FUN_002aed60(int a, int b);
};

struct Frame_2c0590 {
    short unk10;
    unsigned char len;
    char flag;
    int a;
    int b;
    char buf1[0x80];
    char buf2[0x100];
};

class Loader_2c0590 {
public:
    char pad0[0x14];
    Factory_2c0590 *factory;
    Sprite *FUN_002c0590(Reader *r, int unused);
};

Sprite *Loader_2c0590::FUN_002c0590(Reader *r, int unused)
{
    Frame_2c0590 f;
    Sprite *result = 0;
    r->stream->FUN_002647e0(&f.len, 1, 1, 1);
    int len = f.len;
    r->stream->FUN_002647e0(f.buf1, len, 1, 1);
    f.buf1[len] = 0;
    r->stream->FUN_002647e0(&f.a, 1, 4, 1);
    r->stream->FUN_002647e0(&f.a, 1, 4, 1);
    r->stream->FUN_002647e0(&f.a, 1, 4, 1);
    r->stream->FUN_002647e0(&f.a, 1, 4, 1);
    r->stream->FUN_002647e0(&f.b, 1, 4, 1);
    r->stream->FUN_002647e0(&f.b, 1, 4, 1);
    int kind = f.b;
    f.flag = (kind == 1);
    r->stream->FUN_002647e0(&f.b, 1, 4, 1);
    factory->f8c = f.a;
    while (r->FUN_002669f0()) {
        int id = r->FUN_00266a30();
        if (id == 0x19002) {
            r->stream->FUN_002647e0(&f.a, 1, 4, 1);
            int v = r->FUN_00266c90();
            result = factory->FUN_002aed60(v, f.b);
            r->FUN_00266ca0(v);
        } else if (id == 0x19003) {
            r->stream->FUN_002647e0(&f.len, 1, 1, 1);
            int n = f.len;
            r->stream->FUN_002647e0(f.buf2, n, 1, 1);
            f.buf2[n] = 0;
            result = factory->FUN_002aecb0(f.buf2);
        }
        r->FUN_00266be0();
    }
    if (result) {
        result->flag = f.flag;
        result->name.FUN_0027b040(f.buf1);
    }
    return result;
}
