// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 16/16)
// pure3d::SpriteLoader::vfunc_9 @ 0x002be1b0
struct StrField_2be1b0 {
    int a, b;
    void FUN_0027b040(const char *s);
};

struct Sprite {
    char pad0[8];
    StrField_2be1b0 name;
};

struct SpriteData_2be1b0 {
    char pad0[0x8c];
    int field8c;
    void FUN_002ae950(int a, int b, int c, int d);
    Sprite *FUN_002aedd0(const char *name);
    Sprite *FUN_002aeec0(int a, int b, int c);
};

struct Stream {
    bool FUN_002647e0(void *dst, int a, int b, int c);
};

struct Reader {
    char pad0[0x284];
    Stream *stream;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c90();
    void FUN_00266ca0(int v);
};

namespace content {
class ObjectLoader {
public:
    virtual void v0();
};
}

namespace pure3d {
class SpriteLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual Sprite *vfunc_9(Reader *r, int unused);
    char pad04[0x1c - 4];
    SpriteData_2be1b0 *data;
};
}

Sprite *pure3d::SpriteLoader::vfunc_9(Reader *r, int unused)
{
    struct Frame {
        char pad[3];
        unsigned char len;
        int a;
        int b;
        char buf[0x180];
    } fr;

    Sprite *result = 0;
    r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    unsigned int n = fr.len;
    r->stream->FUN_002647e0(fr.buf, n, 1, 1);
    fr.buf[n] = 0;
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);

    data->field8c = fr.a;
    switch (fr.b) {
    case 0xb:
        data->FUN_002ae950(8, 0, 0xd, 0);
        break;
    case 0xc:
        data->FUN_002ae950(8, 0, 0xe, 0);
        break;
    case 0xd:
        data->FUN_002ae950(8, 0, 0xf, 0);
        break;
    case 0xe:
        data->FUN_002ae950(8, 0, 0x10, 0);
        break;
    default:
        break;
    }

    if (r->FUN_002669f0()) {
        do {
            int id = r->FUN_00266a30();
            if (id == 0x19002) {
                r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
                int h = r->FUN_00266c90();
                result = data->FUN_002aeec0(h, fr.a, fr.b);
                r->FUN_00266ca0(h);
            } else if (id == 0x19003) {
                r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
                unsigned int m = fr.len;
                char *name2 = &fr.buf[0x80];
                r->stream->FUN_002647e0(name2, m, 1, 1);
                name2[m] = 0;
                result = data->FUN_002aedd0(name2);
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
        if (result != 0)
            result->name.FUN_0027b040(fr.buf);
    }
    return result;
}
