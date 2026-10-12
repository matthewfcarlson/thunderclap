// STATUS: equivalent (tools/equiv.py level 3: 185 inputs, branch coverage 34/36, incomplete)
// pure3d::ShadowMeshBufferLoader::vfunc_5 @ 0x002b6930
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-map: ??0MeshBufferBase@pure3d@@QAE@XZ = 0x002a5060
inline void *operator new(unsigned int, void *p) throw() { return p; }
void *thunk_FUN_0008d690(unsigned int size);

struct Name {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    bool FUN_002669f0();
    int FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
};

extern int DAT_00554bb4;
extern "C" unsigned __int64 __cdecl FUN_002672f0(const char *s, int a, int b);

class Res;

namespace pure3d {

class MeshBufferBase {
public:
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    MeshBufferBase();
    char pad04[0xc];
    int f10;
};

class ShadowMeshBufferImpl : public MeshBufferBase {
public:
    ShadowMeshBufferImpl()
    {
        f40 = 0;
        f10 = 2;
    }
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    int f14[6];
    int f2c[4];
    char pad3c[4];
    ::Res *f40;
};

}

class Res {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int snapshot);
};

struct Target {
    char pad0[8];
    Name name;
    char pad10[4];
    int f14[6];
    int f2c[4];
    char pad3c[0x48 - 0x3c];
    Res **f48;
    void FUN_002a4500(int which, pure3d::ShadowMeshBufferImpl *buf);
};

struct Manager {
    void FUN_002e4d70(Res **slot, Stream *s, void *inv, int a, int b, char *flags);
};

namespace pure3d {

class ShadowMeshBufferLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(Target **out, unsigned __int64 *outId, Stream *s, void *inv);
    virtual Target *vfunc_6(int kind);
    char pad08[0x10];
    Manager *mgr;   // 0x14
};

struct Frame {
    char pad0[3];
    char useB;      // S3
    ShadowMeshBufferImpl *bufB;  // S4
    char flags[7];  // S8
    char pad15[1];
    int v16;        // S16
    int v20;        // S20
    int v24;
    int v28;
    int v32;
    int v36;
    int v40;
    int tmp[6];     // S44
    int v68;
    int v72;
    int v76;
    int v80;
    char name[256]; // S84
};

void ShadowMeshBufferLoader::vfunc_5(Target **out, unsigned __int64 *outId, Stream *s, void *inv)
{
    Frame f;
    s->reader->FUN_002647e0(&f.useB, 1, 1, 1);
    unsigned int len = (unsigned char)f.useB;
    s->reader->FUN_002647e0(f.name, len, 1, 1);
    f.name[len] = 0;
    s->reader->FUN_002647e0(&f.v16, 1, 4, 1);
    s->reader->FUN_002647e0(&f.v16, 1, 4, 1);
    s->reader->FUN_002647e0(&f.v16, 1, 4, 1);
    s->reader->FUN_002647e0(&f.v16, 1, 4, 1);
    s->reader->FUN_002647e0(&f.v16, 1, 4, 1);
    s->reader->FUN_002647e0(&f.v20, 1, 4, 1);
    int kind = f.v20;
    f.useB = 1;
    if (kind == 1 || kind == 4 || kind == 7)
        f.useB = 0;

    Target *impl = vfunc_6(f.useB ? 2 : 1);
    impl->name.FUN_0027b040(f.name);

    void *mem = thunk_FUN_0008d690(0x48);
    ShadowMeshBufferImpl *bufA = 0;
    if (mem)
        bufA = new (mem) ShadowMeshBufferImpl;
    bufA->b0();

    f.bufB = 0;
    if (f.useB) {
        void *mem2 = thunk_FUN_0008d690(0x48);
        ShadowMeshBufferImpl *b = 0;
        if (mem2)
            b = new (mem2) ShadowMeshBufferImpl;
        f.bufB = b;
        f.bufB->b0();
    }

    f.v20 = DAT_00554bb4;
    f.flags[3] = ' ';
    f.flags[2] = ' ';
    f.flags[1] = ' ';
    f.flags[0] = ' ';
    f.flags[4] = ' ';
    f.flags[5] = ' ';
    f.flags[6] = ' ';

    if (s->FUN_002669f0()) {
        do {
            s->FUN_00266a30();
            int id = s->FUN_00266c30();
            if (id == 0x10003) {
                s->reader->FUN_002647e0(&bufA->f14[0], 3, 4, 1);
                s->reader->FUN_002647e0(&bufA->f14[3], 3, 4, 1);
                if (f.useB) {
                    f.bufB->f14[0] = bufA->f14[0];
                    f.bufB->f14[1] = bufA->f14[1];
                    f.bufB->f14[2] = bufA->f14[2];
                    f.bufB->f14[3] = bufA->f14[3];
                    f.bufB->f14[4] = bufA->f14[4];
                    f.bufB->f14[5] = bufA->f14[5];
                }
            } else if (id == 0x10004) {
                s->reader->FUN_002647e0(&bufA->f2c[0], 3, 4, 1);
                s->reader->FUN_002647e0(&f.v16, 1, 4, 1);
                bufA->f2c[3] = f.v16;
                if (f.useB) {
                    f.bufB->f2c[0] = bufA->f2c[0];
                    f.bufB->f2c[1] = bufA->f2c[1];
                    f.bufB->f2c[2] = bufA->f2c[2];
                    f.bufB->f2c[3] = bufA->f2c[3];
                }
            } else if (id == 0x10021) {
                s->reader->FUN_002647e0(&f.v80, 1, 4, 1);
                s->reader->FUN_002647e0(&f.v36, 1, 4, 1);
                f.flags[0] = (char)f.v36;
                s->reader->FUN_002647e0(&f.v32, 1, 4, 1);
                f.flags[1] = (char)f.v32;
                s->reader->FUN_002647e0(&f.v76, 1, 4, 1);
                f.flags[2] = (char)f.v76;
                s->reader->FUN_002647e0(&f.v28, 1, 4, 1);
                f.flags[3] = (char)f.v28;
                s->reader->FUN_002647e0(&f.v40, 1, 4, 1);
                f.flags[4] = (char)f.v40;
                s->reader->FUN_002647e0(&f.v68, 1, 4, 1);
                f.flags[5] = (char)f.v68;
                s->reader->FUN_002647e0(&f.v72, 1, 4, 1);
                f.flags[6] = (char)f.v72;
            } else if (id == 0x10024) {
                s->FUN_00266a30();
                mgr->FUN_002e4d70(impl->f48, s, inv, 0, 1, f.flags);
                Res *r = *impl->f48;
                r->v8(f.v20);
                r->v0();
                if (bufA->f40)
                    bufA->f40->v1();
                bufA->f40 = r;
                impl->FUN_002a4500(0, bufA);
                s->FUN_00266be0();
            } else if (id == 0x10025) {
                s->FUN_00266a30();
                mgr->FUN_002e4d70(impl->f48 + 4, s, inv, 0, 1, f.flags);
                Res *r = impl->f48[4];
                r->v8(f.v20);
                r->v0();
                if (f.bufB->f40)
                    f.bufB->f40->v1();
                f.bufB->f40 = r;
                impl->FUN_002a4500(1, f.bufB);
                s->FUN_00266be0();
            }
            s->FUN_00266be0();
        } while (s->FUN_002669f0());
    }

    f.tmp[0] = bufA->f14[0];
    f.tmp[1] = bufA->f14[1];
    f.tmp[2] = bufA->f14[2];
    f.tmp[3] = bufA->f14[3];
    f.tmp[4] = bufA->f14[4];
    f.tmp[5] = bufA->f14[5];
    impl->f14[0] = f.tmp[0];
    impl->f14[1] = f.tmp[1];
    impl->f14[2] = f.tmp[2];
    impl->f14[3] = f.tmp[3];
    impl->f14[4] = f.tmp[4];
    impl->f14[5] = f.tmp[5];
    impl->f2c[0] = bufA->f2c[0];
    impl->f2c[1] = bufA->f2c[1];
    impl->f2c[2] = bufA->f2c[2];
    impl->f2c[3] = bufA->f2c[3];
    bufA->b1();
    if (f.useB)
        f.bufB->b1();
    *out = impl;
    *outId = FUN_002672f0(f.name, 0, 0);
}

}
