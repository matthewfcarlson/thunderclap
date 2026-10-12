// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 16/16)
// FUN_002c1d70 @ 0x002c1d70
struct StrField {
    int a, b;
    void FUN_0027b040(const char *s);
};

struct Sprite {
    char pad0[8];
    StrField name;
};

struct SpriteData {
    Sprite *FUN_002aedd0(const char *name);
    Sprite *FUN_002aeec0(int h, int a, int b);
    void FUN_002aef60(const char *name, Sprite *existing, int arg);
    void FUN_002af010(int h, Sprite *existing, int b, int arg);
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

class Loader {
public:
    char pad00[0x14];
    SpriteData *data;
    Sprite *FUN_002c1d70(Reader *r, SpriteData *sd, Sprite *existing, int arg);
};

Sprite *Loader::FUN_002c1d70(Reader *r, SpriteData *sd, Sprite *existing, int arg)
{
    struct Frame {
        char pad[3];
        unsigned char len;
        int a;
        int b;
        char buf[0x180];
    } fr;

    if (sd == 0)
        sd = data;
    r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    unsigned int n = fr.len;
    r->stream->FUN_002647e0(fr.buf, n, 1, 1);
    fr.buf[n] = 0;
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);

    if (r->FUN_002669f0()) {
        do {
            int id = r->FUN_00266a30();
            if (id == 0x19002) {
                r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
                int h = r->FUN_00266c90();
                if (existing == 0)
                    existing = sd->FUN_002aeec0(h, fr.a, fr.b);
                else
                    sd->FUN_002af010(h, existing, fr.b, arg);
                r->FUN_00266ca0(h);
            } else if (id == 0x19003) {
                r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
                unsigned int m = fr.len;
                char *name2 = &fr.buf[0x80];
                r->stream->FUN_002647e0(name2, m, 1, 1);
                name2[m] = 0;
                if (existing == 0)
                    existing = sd->FUN_002aedd0(name2);
                else
                    sd->FUN_002aef60(name2, existing, arg);
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }
    if (existing != 0)
        existing->name.FUN_0027b040(fr.buf);
    return existing;
}
