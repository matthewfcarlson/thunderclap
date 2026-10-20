// STATUS: equivalent (tools/equiv.py level 3: 2670 inputs, branch coverage 119/124, incomplete)
// FUN_002e2a70 @ 0x002e2a70
// FUN_002e2a70 @ 0x002e2a70
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/data/engine/pure3d/prop.h"

inline void *operator new(unsigned int, void *p) throw() { return p; }
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d690(unsigned int size);
void *__cdecl FUN_00266e00(int a, unsigned int n);
void __cdecl FUN_00267090(void *p);

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    unsigned int FUN_001c61c0();
    void FUN_001c6200(void *dst);
    float FUN_001c61e0();
};

struct RefObj_2e2a70 {
    virtual void AddRef();
    virtual void Release();
};

struct IntVec_2e2a70 {
    unsigned int *begin;
    unsigned int *end;
    void FUN_002e18c0(unsigned int n);
};

// The reference count sits after the vptr and is cleared before the vptr is stored.
struct RefCount_2e2a70 {
    int refCount;
    RefCount_2e2a70() throw() { refCount = 0; }
};

class MatrixPaletteList : public RefCount_2e2a70 {
public:
    virtual void AddRef();
    virtual void Release();
    IntVec_2e2a70 vec;
    int pad10;
    MatrixPaletteList() { vec.begin = 0; vec.end = 0; }
};

struct VData {
    char pad00[0x18];
    char *f18;
    char *f1c;
    char pad20[8];
    char *f28;
    char pad2c[4];
    char *f30;
    char pad34[4];
    char *tex[4];
    char *uv[4];
    char *f58;
    void FUN_002d0a50(int a, RefObj_2e2a70 *b, MatrixPaletteList *c);
};

class Buffer_2e2a70 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void b2();
    virtual void b3();
    virtual int b4();
    virtual void b5(int v);
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9(unsigned short *buf, unsigned int n);
};

struct Desc_2e2a70 {
    unsigned int a;
    unsigned int flags;
    unsigned char tag[8];
    unsigned int c;
    unsigned int d;
    unsigned char e0;
    unsigned char e1;
    unsigned char pad[2];
    unsigned int f;
    unsigned int g;
};

class Factory_2e2a70 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual Buffer_2e2a70 *Create(Desc_2e2a70 *d);
};

struct Vec3_2e2a70 { float x, y, z; };

class PrimObj2 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void SetName(int v);
    char pad04[0x10];
    Vec3_2e2a70 v14;
    Vec3_2e2a70 v20;
    Vec3_2e2a70 v2c;
    float f38;
    char pad3c[8];
    unsigned int f44;
    char pad48[8];
    unsigned int f50;
    char pad54[4];
    Buffer_2e2a70 *vb;
    RefObj_2e2a70 *pal;
    RefObj_2e2a70 *palShared;
    MatrixPaletteList *list;
    VData *vdata;
    PrimObj2 *FUN_002e0620(unsigned int a, unsigned int b, unsigned int c);
};

union Slot2 {
    Stream *stream;
    unsigned short *buf;
    MatrixPaletteList *list;
    unsigned int cnt;
};
union Slot5_2e2a70 {
    const unsigned int *p;
    unsigned int u;
};

class PrimLoader {
public:
    char pad00[8];
    unsigned int f08;
    unsigned int f0c;
    char pad10[4];
    unsigned int f14;
    char pad18[4];
    unsigned int flags;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    void FUN_002a46d0(int a1, PrimObj2 *o);
    void FUN_002a4b00(int a1, Stream *s, int a3);
    void FUN_002e2a70(int a1, Slot2 a2, int a3, RefObj_2e2a70 *a4, Slot5_2e2a70 a5);
};

struct Frame_2e2a70 {
    PrimObj2 *obj;     // 0x10
    Buffer_2e2a70 *vb;        // 0x14
    unsigned int vA;   // 0x18
    unsigned int cnt;  // 0x1c
    PrimLoader *self;  // 0x20
    unsigned int lim;  // 0x24
    unsigned int tmpw; // 0x28
    unsigned int tmpd; // 0x2c
    unsigned int idx;  // 0x30
    Desc_2e2a70 d;            // 0x34
};

void PrimLoader::FUN_002e2a70(int a1, Slot2 a2, int a3, RefObj_2e2a70 *a4, Slot5_2e2a70 a5)
{
    Frame_2e2a70 f;
    unsigned int fl = flags;
    f.self = this;
    unsigned int vA;
    if (fl & 0x20)
        vA = 1;
    else if (fl & 0x4000)
        vA = (fl >> 15) & 7;
    else
        vA = 0;
    f.vA = vA;
    f.lim = fl & 0xf;
    void *mem = thunk_FUN_0008d690(0x70);
    PrimObj2 *obj = 0;
    if (mem != 0)
        obj = ((PrimObj2 *)mem)->FUN_002e0620(flags, f20, f24);
    f.obj = obj;
    obj->SetName(f08);
    obj->f44 = f0c;
    obj->f50 = f14;
    FUN_002a46d0(a1, obj);
    f.d.flags = flags & 0xfffffe7f;
    f.d.a = f0c;
    f.d.tag[3] = 0x20;
    f.d.tag[2] = 0x20;
    f.d.tag[1] = 0x20;
    f.d.tag[0] = 0x20;
    f.d.tag[4] = 0x20;
    f.d.tag[5] = 0x20;
    f.d.tag[6] = 0x20;
    f.d.c = f20;
    f.d.d = f24;
    f.d.e1 = 0;
    f.d.f = 0;
    f.d.e0 = 0;
    f.d.g = f28;
    if (a5.p != 0) {
        unsigned int lo = a5.p[0];
        unsigned int hi = a5.p[1];
        *(unsigned int *)&f.d.tag[0] = lo;
        *(unsigned int *)&f.d.tag[4] = hi;
    }
    Buffer_2e2a70 *vb = (*(Factory_2e2a70**)&DAT_0052c2a0)->Create(&f.d);
    f.vb = vb;
    if (vb != 0)
        vb->AddRef();
    if (obj->vb != 0)
        obj->vb->Release();
    obj->vb = f.vb;
    Stream *stream = a2.stream;
    VData *vd = obj->vdata;
    while (stream->FUN_002669f0()) {
        PrimLoader *self = f.self;
        unsigned int id = stream->FUN_00266a30();
        if (id > 0x1001c) {
            if (id == 0x121204)
                self->FUN_002a4b00(a1, stream, a3);
        } else if (id == 0x1001c) {
            if (self->flags & 0x4000) {
                stream->reader->FUN_002647e0(&f.cnt, 1, 4, 1);
                stream->reader->FUN_002647e0(&f.idx, 1, 4, 1);
                unsigned int index = f.idx;
                if (index < f.vA) {
                    if (f.cnt > 0) {
                        unsigned int i = 0;
                        do {
                            stream->reader->FUN_002647e0(vd->uv[index] + i * 4, 1, 4, 1);
                            i++;
                        } while (i < f.cnt);
                    }
                }
            }
        } else {
            switch (id - 0x10003) {
            case 0:
                stream->FUN_001c6200(&obj->v14);
                stream->FUN_001c6200(&obj->v20);
                break;
            case 1:
                stream->FUN_001c6200(&obj->v2c);
                obj->f38 = stream->FUN_001c61e0();
                break;
            case 2:
                if (self->flags & 0x2000) {
                    unsigned int n = stream->FUN_001c61c0();
                    if (n > 0) {
                        unsigned int off = 0;
                        do {
                            stream->reader->FUN_002647e0(vd->f18 + off, 3, 4, 1);
                            off += 0xc;
                        } while (--n != 0);
                    }
                }
                break;
            case 3:
                if (self->flags & 0x10) {
                    unsigned int n = stream->FUN_001c61c0();
                    if (n > 0) {
                        unsigned int off = 0;
                        do {
                            stream->reader->FUN_002647e0(vd->f1c + off, 3, 4, 1);
                            off += 0xc;
                        } while (--n != 0);
                    }
                }
                break;
            case 4:
                if (self->flags & 0xf) {
                    unsigned int n = stream->FUN_001c61c0();
                    a2.cnt = stream->FUN_001c61c0();
                    if (a2.cnt < f.lim) {
                        unsigned int i = 0;
                        if (n > 0) {
                            do {
                                stream->reader->FUN_002647e0(vd->tex[a2.cnt] + i * 8, 2, 4, 1);
                                i++;
                            } while (i < n);
                        }
                    }
                }
                break;
            case 5:
                if (self->flags & 0x20) {
                    unsigned int n = stream->FUN_001c61c0();
                    unsigned int i = 0;
                    if (n > 0) {
                        do {
                            stream->reader->FUN_002647e0(vd->uv[0] + i * 4, 1, 4, 1);
                            i++;
                        } while (i < n);
                    }
                }
                break;
            case 7: {
                unsigned int n = stream->FUN_001c61c0();
                a2.buf = (unsigned short *)FUN_00266e00(1, n * 2);
                unsigned int i = 0;
                if (n > 0) {
                    do {
                        stream->reader->FUN_002647e0(&f.tmpw, 1, 4, 1);
                        a2.buf[i] = (unsigned short)f.tmpw;
                        i++;
                    } while (i < n);
                }
                f.vb->b9(a2.buf, n);
                FUN_00267090(a2.buf);
                break;
            }
            case 9:
                if (self->flags & 0x100) {
                    unsigned int n = stream->FUN_001c61c0();
                    if (n > 0) {
                        unsigned int off = 0;
                        do {
                            stream->reader->FUN_002647e0(vd->uv[3] + off, 3, 4, 1);
                            off += 0xc;
                        } while (--n != 0);
                    }
                }
                break;
            case 8:
                if (self->flags & 0x80) {
                    unsigned int n = stream->FUN_001c61c0();
                    unsigned int i = 0;
                    if (n > 0) {
                        do {
                            stream->reader->FUN_002647e0(&a5.u, 1, 4, 1);
                            vd->uv[2][i * 4] = (char)(a5.u >> 24);
                            vd->uv[2][i * 4 + 1] = (char)(a5.u >> 16);
                            vd->uv[2][i * 4 + 2] = (char)(a5.u >> 8);
                            vd->uv[2][i * 4 + 3] = (char)a5.u;
                            i++;
                        } while (i < n);
                    }
                }
                break;
            case 10:
                if (self->flags & 0x80) {
                    unsigned int n = stream->FUN_001c61c0();
                    void *m = FUN_0008d690(0x14);
                    MatrixPaletteList *list = 0;
                    if (m != 0)
                        list = new (m) MatrixPaletteList();
                    a2.list = list;
                    a2.list->vec.FUN_002e18c0(n);
                    unsigned int i = 0;
                    if (n > 0) {
                        do {
                            stream->reader->FUN_002647e0(&f.tmpd, 1, 4, 1);
                            a2.list->vec.begin[i] = f.tmpd;
                            i++;
                        } while (i < n);
                    }
                    RefObj_2e2a70 *p = a4;
                    if (p != 0)
                        p->AddRef();
                    PrimObj2 *o = f.obj;
                    if (o->palShared != 0)
                        o->palShared->Release();
                    o->palShared = p;
                    MatrixPaletteList *l = a2.list;
                    if (l != 0)
                        l->AddRef();
                    if (o->list != 0)
                        o->list->Release();
                    o->list = l;
                }
                break;
            case 18:
                if (self->flags & 0x1000) {
                    unsigned int n = stream->FUN_001c61c0();
                    if (n > 0) {
                        unsigned int off = 0;
                        do {
                            stream->reader->FUN_002647e0(vd->f30 + off, 3, 4, 1);
                            off += 0xc;
                        } while (--n != 0);
                    }
                }
                break;
            case 19:
                if (self->flags & 0x800) {
                    unsigned int n = stream->FUN_001c61c0();
                    if (n > 0) {
                        unsigned int off = 0;
                        do {
                            stream->reader->FUN_002647e0(vd->f28 + off, 3, 4, 1);
                            off += 0xc;
                        } while (--n != 0);
                    }
                }
                break;
            default:
                break;
            }
        }
        stream->FUN_00266be0();
        obj = f.obj;
    }
    MatrixPaletteList *pl = obj->list;
    int bufv;
    if ((unsigned int)(pl->vec.end - pl->vec.begin) > 0) {
        bufv = f.vb->b4();
        vd->FUN_002d0a50(bufv, obj->palShared, obj->list);
    } else {
        bufv = f.vb->b4();
        vd->FUN_002d0a50(bufv, 0, 0);
    }
    f.vb->b5(bufv);
}
