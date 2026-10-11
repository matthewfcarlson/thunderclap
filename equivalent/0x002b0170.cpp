// STATUS: equivalent (tools/equiv.py level 3: 37 inputs, branch coverage 13/14, incomplete)
// pure3d::ExpressionGroupLoader::vfunc_5 @ 0x002b0170
struct Item {
    virtual void v0();
};

struct StrField {
    int a, b;
    void FUN_0027b040(const char *s);
};

struct ExprGroup {
    char pad0[8];
    StrField name;
    Item **items;
    char pad1[0x20 - 0x14];
    unsigned __int64 hash;
    int *vals;
    ExprGroup *FUN_002b0060(int count);
};

struct Stream {
    bool FUN_002647e0(void *dst, int a, int b, int c);
};

namespace content {
class ObjectLoader {
public:
    virtual void v0();
};
}

struct Reader;

namespace pure3d {
class ExpressionLoader : public content::ObjectLoader {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned __int64 v5(Item **out, unsigned __int64 *hash, Reader *r, int flag);
};
}

struct Reader {
    char pad0[0x280];
    int depth;
    Stream *stream;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    void *FUN_00266c30();
};

struct Registry {
    content::ObjectLoader *FUN_00265310(void *key);
};

extern Registry *DAT_00527c58;

void *FUN_00263ea0(unsigned int size);
unsigned __int64 FUN_0027b020(const char *s);
unsigned __int64 FUN_002672f0(const char *s, unsigned int lo, unsigned int hi);

class ExpressionGroupLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual unsigned __int64 vfunc_5(ExprGroup **out, unsigned __int64 *outHash, Reader *r, int flag);
};

unsigned __int64 ExpressionGroupLoader::vfunc_5(ExprGroup **out, unsigned __int64 *outHash, Reader *r, int flag)
{
    struct Frame {
        char pad[3];
        unsigned char len;
        union {
            int v;
            Item *item;
        } u;
        unsigned __int64 x;
        char buf1[0x100];
        char buf2[0x100];
    } fr;

    r->stream->FUN_002647e0(&fr.u.v, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    unsigned int n1 = fr.len;
    r->stream->FUN_002647e0(fr.buf1, n1, 1, 1);
    fr.buf1[n1] = 0;
    r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    unsigned int n2 = fr.len;
    r->stream->FUN_002647e0(fr.buf2, n2, 1, 1);
    fr.buf2[n2] = 0;
    r->stream->FUN_002647e0(&fr.u.v, 1, 4, 1);

    void *mem = FUN_00263ea0(0x38);
    int count = fr.u.v;
    ExprGroup *g = 0;
    if (mem)
        g = ((ExprGroup *)mem)->FUN_002b0060(count);
    g->name.FUN_0027b040(fr.buf1);
    g->hash = FUN_0027b020(fr.buf2);
    for (int i = 0; i < count; i++) {
        r->stream->FUN_002647e0(&fr.u.v, 1, 4, 1);
        g->vals[i] = fr.u.v;
    }

    if (r->FUN_002669f0()) {
        unsigned int off = 0;
        do {
            if (r->FUN_00266a30() == 0x21000) {
                pure3d::ExpressionLoader *el = dynamic_cast<pure3d::ExpressionLoader *>(DAT_00527c58->FUN_00265310(r->FUN_00266c30()));
                if (el != 0) {
                    fr.u.item = 0;
                    el->v5(&fr.u.item, &fr.x, r, 0);
                    fr.u.item->v0();
                    *(Item **)((char *)g->items + off) = fr.u.item;
                    off += 4;
                }
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }
    *out = g;
    unsigned __int64 h = FUN_002672f0(fr.buf1, 0, 0);
    *outHash = h;
    return h;
}
