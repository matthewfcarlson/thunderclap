// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 10/12, incomplete)
// FUN_002c0590 @ 0x002c0590
#include "compat/ptr.h"
#include "gen/owners.h"
struct Name_2c0590 {
    unsigned int lo, hi;
};

struct Sprite {
    char pad0[8];
    Name_2c0590 name;
    char pad10[0x28 - 0x10];
    char flag;
};

struct Stream {
};

struct Reader {
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
    void FUN_00266ca0(int v);
};

struct Factory_2c0590 {
    char pad0[0x8c];
    int f8c;
    Sprite *FUN_002aecb0(char *name);
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
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    int len = f.len;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.buf1), (hulk_intptr)len, 1, (hulk_intptr)1);
    f.buf1[len] = 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.b), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.b), (hulk_intptr)1, 4, (hulk_intptr)1);
    int kind = f.b;
    f.flag = (kind == 1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.b), (hulk_intptr)1, 4, (hulk_intptr)1);
    factory->f8c = f.a;
    while (r->FUN_002669f0()) {
        int id = r->FUN_00266a30();
        if (id == 0x19002) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
            int v = ((int)((owners::Target_266c90 *)r)->FUN_00266c90());
            result = ((Sprite *)((owners::SomeClass_2aed60 *)factory)->FUN_002aed60((void *)(hulk_uintptr)(int)v, (void *)(hulk_uintptr)(int)(f.b)));
            r->FUN_00266ca0(v);
        } else if (id == 0x19003) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
            int n = f.len;
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.buf2), (hulk_intptr)n, 1, (hulk_intptr)1);
            f.buf2[n] = 0;
            result = factory->FUN_002aecb0(f.buf2);
        }
        r->FUN_00266be0();
    }
    if (result) {
        result->flag = f.flag;
        ((owners::Target_27b040 *)&(result->name))->FUN_0027b040((hulk_uintptr)(f.buf1));
    }
    return result;
}
