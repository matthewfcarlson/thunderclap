// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 10/12, incomplete)
// pure3d::SpriteLoader::vfunc_8 @ 0x002bdfc0
struct Name {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
};

struct Sprite {
    char pad0[8];
    Name name;
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

struct Factory {
    char pad0[0x8c];
    int f8c;
    Sprite *FUN_002aecb0(char *name);
    Sprite *FUN_002aed60(int a, int b);
};

struct Frame {
    short unk10;
    unsigned char len;
    char flag;
    int a;
    int b;
    char buf1[0x80];
    char buf2[0x100];
};

class SpriteLoader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Sprite *vfunc_8(Reader *r, int unused);
    virtual void v9();
    char pad4[0x18];
    Factory *factory;
};

Sprite *SpriteLoader::vfunc_8(Reader *r, int unused)
{
    Frame f;
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
        result->name.FUN_0027b040(f.buf1);
        result->flag = f.flag;
    }
    return result;
}
