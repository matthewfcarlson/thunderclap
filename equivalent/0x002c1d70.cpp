// STATUS: equivalent (tools/equiv.py level 3: 16754 inputs, branch coverage 16/16)
// FUN_002c1d70 @ 0x002c1d70
#include "gen/pure3d.h"
struct StrField_2c1d70 {
    int a, b;
    void FUN_0027b040(const char *s);
};

struct Sprite_2c1d70 {
    char pad0[8];
    StrField_2c1d70 name;
};

struct TextureBuilder_nv_2c1d70 {
    Sprite_2c1d70 *FUN_002aedd0(const char *name);
    Sprite_2c1d70 *FUN_002aeec0(int h, int a, int b);
    void FUN_002aef60(const char *name, Sprite_2c1d70 *existing, int arg);
    void FUN_002af010(int h, Sprite_2c1d70 *existing, int b, int arg);
};

struct Stream_2c1d70 {
    bool FUN_002647e0(void *dst, int a, int b, int c);
};

struct Reader_2c1d70 {
    char pad0[0x284];
    Stream_2c1d70 *stream;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c90();
    void FUN_00266ca0(int v);
};

class Loader_2c1d70 {
public:
    char pad00[0x14];
    pure3d::TextureBuilder *data;
    Sprite_2c1d70 *FUN_002c1d70(Reader_2c1d70 *r, pure3d::TextureBuilder *sd, Sprite_2c1d70 *existing, int arg);
};

Sprite_2c1d70 *Loader_2c1d70::FUN_002c1d70(Reader_2c1d70 *r, pure3d::TextureBuilder *sd, Sprite_2c1d70 *existing, int arg)
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
                    existing = ((TextureBuilder_nv_2c1d70*)(((pure3d::TextureBuilder*)(sd))))->FUN_002aeec0(h, fr.a, fr.b);
                else
                    ((TextureBuilder_nv_2c1d70*)(((pure3d::TextureBuilder*)(sd))))->FUN_002af010(h, existing, fr.b, arg);
                r->FUN_00266ca0(h);
            } else if (id == 0x19003) {
                r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
                unsigned int m = fr.len;
                char *name2 = &fr.buf[0x80];
                r->stream->FUN_002647e0(name2, m, 1, 1);
                name2[m] = 0;
                if (existing == 0)
                    existing = ((TextureBuilder_nv_2c1d70*)(((pure3d::TextureBuilder*)(sd))))->FUN_002aedd0(name2);
                else
                    ((TextureBuilder_nv_2c1d70*)(((pure3d::TextureBuilder*)(sd))))->FUN_002aef60(name2, existing, arg);
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }
    if (existing != 0)
        existing->name.FUN_0027b040(fr.buf);
    return existing;
}
