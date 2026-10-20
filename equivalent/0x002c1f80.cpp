// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 24/28, incomplete)
// FUN_002c1f80 @ 0x002c1f80
#include "compat/ptr.h"
extern "C" int sprintf(char *buf, const char *fmt, ...);
void *FUN_0008d6d0(unsigned int size);
void FUN_0008d340(void *p);

class Ref_2c1f80 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Stream {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Reader {
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c90();
    void FUN_00266ca0(int handle);
};

struct Factory_2c1f80 {
    Ref_2c1f80 *FUN_002aecb0(char *name);
    Ref_2c1f80 *FUN_002aed60(int handle, int arg);
};

class Sink_2c1f80 {
public:
    virtual void v0();
    virtual void v1();
    virtual void *Install(Ref_2c1f80 **items, int count, int a, int b);
    virtual void *InstallScaled(Ref_2c1f80 **items, int count, int a, int b);
};

class Loader_2c1f80 {
public:
    char pad0[0x14];
    Factory_2c1f80 *defaultFactory;    // 0x14
    Sink_2c1f80 *sink;                 // 0x18

    void *FUN_002c1f80(Reader *r, Factory_2c1f80 *factory, hulk_intptr a3, int a4, int a5);
};

void *Loader_2c1f80::FUN_002c1f80(Reader *r, Factory_2c1f80 *factory, hulk_intptr a3, int a4, int a5)
{
    if (factory == 0)
        factory = defaultFactory;

    // One contiguous frame (the stream stubs fill through these pointers).
    struct {
        char pad[3];
        unsigned char len;
        int v0;
        Ref_2c1f80 **items;
        void *result;
        Loader_2c1f80 *self;
        int count;
        int v2;
        char buf1[0x80];
        char buf2[0x100];
        char buf3[0x100];
    } f;

    f.self = this;
    r->stream->FUN_002647e0(&f.len, 1, 1, 1);
    int len = f.len;
    r->stream->FUN_002647e0(f.buf1, len, 1, 1);
    f.buf1[len] = 0;
    r->stream->FUN_002647e0(&f.v0, 1, 4, 1);
    r->stream->FUN_002647e0(&f.v0, 1, 4, 1);
    r->stream->FUN_002647e0(&f.v0, 1, 4, 1);
    r->stream->FUN_002647e0(&f.count, 1, 4, 1);
    r->stream->FUN_002647e0(&f.v0, 1, 4, 1);
    r->stream->FUN_002647e0(&f.v0, 1, 4, 1);
    r->stream->FUN_002647e0(&f.v0, 1, 4, 1);
    r->stream->FUN_002647e0(&f.v0, 1, 4, 1);

    f.result = (void *)a3;
    f.items = (Ref_2c1f80 **)FUN_0008d6d0(f.count * 4);
    int n = 0;
    if (r->FUN_002669f0()) {
        do {
            if (r->FUN_00266a30() == 0x19001 && n < f.count) {
                bool found = false;
                sprintf(f.buf3, "%s_%i", f.buf1, n);
                while (r->FUN_002669f0() && !found) {
                    int id = r->FUN_00266a30();
                    if (id == 0x19002) {
                        r->stream->FUN_002647e0(&f.v2, 1, 4, 1);
                        int h = r->FUN_00266c90();
                        Ref_2c1f80 *obj = factory->FUN_002aed60(h, f.v0);
                        f.items[n] = obj;
                        obj->AddRef();
                        r->FUN_00266ca0(h);
                        n++;
                        found = true;
                    } else if (id == 0x19003) {
                        r->stream->FUN_002647e0(&f.len, 1, 1, 1);
                        int l2 = f.len;
                        r->stream->FUN_002647e0(f.buf2, l2, 1, 1);
                        f.buf2[l2] = 0;
                        Ref_2c1f80 *obj = factory->FUN_002aecb0(f.buf2);
                        f.items[n] = obj;
                        obj->AddRef();
                        n++;
                        found = true;
                    }
                    r->FUN_00266be0();
                }
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }

    if (n > 0) {
        if (a3 == 0)
            f.result = f.self->sink->Install(f.items, n, a5, 0);
        else
            f.result = f.self->sink->InstallScaled(f.items, n, a3, a4);
    }
    for (int i = 0; i < n; i++)
        f.items[i]->Release();
    FUN_0008d340(f.items);
    return f.result;
}
