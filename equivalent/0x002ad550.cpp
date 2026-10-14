// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 16/18, incomplete)
// pure3d::OldParticleSystemLoader::vfunc_5 @ 0x002ad550
extern "C" char *strstr(const char *, const char *);

struct StrField_2ad550 {
    int a, b;
    void FUN_0027b040(const char *s);
};

class Item_2ad550 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(int arg);
};

struct Slot;

struct Host_2ad550 {
    void FUN_002a46d0(void *slot, Item_2ad550 *item);
};

struct Wrapper;

struct Extra_2ad550 {
    char pad0[8];
    StrField_2ad550 name;
    char pad1[0x60 - 0x10];
    Extra_2ad550 *FUN_002a73d0();
};

struct Particle;

struct Table_2ad550 {
    char pad0[8];
    StrField_2ad550 name2;
    void FUN_0027af70(StrField_2ad550 *name);
};

struct Block_2ad550 {
    char pad0[8];
    StrField_2ad550 name;
    char pad1[0x48 - 0x10];
    char *slots;
    char pad2[0x58 - 0x4c];
    unsigned char flag;
    char pad3[3];
    float count;
    int value;
    char pad4[0xa4 - 0x64];
    void *extra;
    Block_2ad550 *FUN_002a3660(int arg);
    void FUN_002a3c80(void *extra);
};

struct ExtraObj {
    char pad0[8];
    Table_2ad550 table;
    char pad1[0x60 - 0x8 - sizeof(Table_2ad550)];
    ExtraObj *FUN_002a73d0();
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

struct Reader {
    char pad0[0x284];
    Stream *stream;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

void *FUN_00263ea0(unsigned int size);
unsigned __int64 FUN_002672f0(const char *s, unsigned int lo, unsigned int hi);

namespace pure3d {
class OldParticleSystemLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual unsigned __int64 vfunc_5(Block_2ad550 **out, unsigned __int64 *outHash, Reader *r, int flag);
    char pad04[0x14 - 4];
    int f14;
    Host_2ad550 *f18;
    Item_2ad550 *FUN_002acd70(Reader *r, int flag);
};
}

unsigned __int64 pure3d::OldParticleSystemLoader::vfunc_5(Block_2ad550 **out, unsigned __int64 *outHash, Reader *r, int flag)
{
    struct Frame {
        union {
            unsigned char len;
            unsigned short s;
            unsigned char flag;
        } u;
        char pad[2];
        int slot14;
        int slot18;
        int slot1c;
        char buf[0x100];
    } fr;

    Stream *st = r->stream;
    st->FUN_002647e0(&fr.slot18, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.u.len, 1, 1, 1);
    unsigned int n = fr.u.len;
    r->stream->FUN_002647e0(fr.buf, n, 1, 1);
    fr.buf[n] = 0;
    r->stream->FUN_002647e0(&fr.slot1c, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.slot18, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.slot14, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.u.s, 1, 2, 1);
    fr.u.flag = (fr.u.s != 0);
    r->stream->FUN_002647e0(&fr.slot14, 1, 2, 1);
    r->stream->FUN_002647e0(&fr.slot14, 1, 4, 1);

    char *sep = strstr(fr.buf, "_factory");
    if (sep)
        *sep = 0;

    void *mem = FUN_00263ea0(0xb0);
    Block_2ad550 *b = 0;
    if (mem)
        b = ((Block_2ad550 *)mem)->FUN_002a3660(fr.slot14);
    b->name.FUN_0027b040(fr.buf);
    b->value = fr.slot1c;
    b->count = (float)(unsigned int)fr.slot18;
    b->flag = fr.u.flag;

    if (r->FUN_002669f0()) {
        int off = 0;
        do {
            if (r->FUN_00266a30() == 0x15806) {
                Item_2ad550 *item = FUN_002acd70(r, flag);
                item->v25(f14);
                f18->FUN_002a46d0(b->slots + off, item);
                off += 0x10;
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }

    if (b->extra == 0) {
        void *m2 = FUN_00263ea0(0x60);
        ExtraObj *e = 0;
        if (m2)
            e = ((ExtraObj *)m2)->FUN_002a73d0();
        e->table.FUN_0027af70(&b->name);
        b->FUN_002a3c80(e);
    }

    *out = b;
    unsigned __int64 h = FUN_002672f0(fr.buf, 0, 0);
    *outHash = h;
    return h;
}
