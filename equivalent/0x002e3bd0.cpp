// STATUS: equivalent (tools/equiv.py level 3: 2765 inputs, branch coverage 118/118)
// FUN_002e3bd0 @ 0x002e3bd0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
inline void *operator new(unsigned int, void *p) throw() { return p; }
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d690(unsigned int size);
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct Named {
    char pad00[0x10];
    int f10;
};

struct RefObj {
    virtual void AddRef();
    virtual void Release();
};

struct IntVec {
    unsigned int *begin;
    unsigned int *end;
    void FUN_002e16f0(unsigned int n, const unsigned int *def);
};

namespace pure3d {
class MatrixPaletteList {
public:
    virtual void AddRef();
    virtual void Release();
    int pad4;
    IntVec vec;
    MatrixPaletteList() { vec.begin = 0; vec.end = 0; }
};
}
using pure3d::MatrixPaletteList;

struct PalSrc : RefObj {
    char pad04[4];
    char *begin;
    char *end;
};

struct VData {
    char pad00[0xc];
    unsigned int f0c;
    char pad10[4];
    unsigned short *f14;
    char *f18;
    char *f1c;
    char *f20;
    char pad24[4];
    char *f28;
    char pad2c[4];
    char *f30;
    char pad34[4];
    char *tex[4];
    char *uv[4];
    char pad58[4];
};

struct DevObj {
    virtual void d0();
    virtual void d1();
    virtual int Make(int a, unsigned int b, unsigned int c, int d, int e);
    virtual void d3();
    virtual char Check(int a, int b);
};



class Device {
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
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual DevObj *Get(int id);
};
extern Device *DAT_0052c2a8;

class __declspec(novtable) GroupBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void SetName(Named *v);
    char pad04[0x40];
    unsigned int f44;
    char pad48[0x10];
    int f58;
    VData *vdata;
    GroupBase *FUN_002e01d0(unsigned int a, unsigned int b, unsigned int c);
    GroupBase(unsigned int a, unsigned int b, unsigned int c) { FUN_002e01d0(a, b, c); }
};

namespace pure3d {
class PrimGroupSkinnedStreamed : public GroupBase {
public:
    virtual void s0();
    RefObj *pal;
    MatrixPaletteList *list;
    PrimGroupSkinnedStreamed(unsigned int a, unsigned int b, unsigned int c) : GroupBase(a, b, c)
    {
        pal = 0;
        list = 0;
    }
};
}

union Slot1 {
    int a;
    unsigned int u;
};
union Slot2 {
    Stream *s;
    unsigned int n;
};

class Loader {
public:
    char pad00[8];
    Named *f08;
    unsigned int f0c;
    char pad10[4];
    unsigned int flags;
    unsigned int f18;
    unsigned int f1c;
    void FUN_002a46d0(Slot1 a1, GroupBase *g);
    void FUN_002e3bd0(Slot1 a1, Slot2 a2, int a3, PalSrc *a4);
};

struct Frame {
    unsigned int vA;     // 0x10
    pure3d::PrimGroupSkinnedStreamed *obj; // 0x14
    MatrixPaletteList *list; // 0x18
    Loader *self;        // 0x1c
    unsigned int cntA;   // 0x20
    unsigned int cntB;   // 0x24
    unsigned int cnt1;   // 0x28
    unsigned int cnt2;   // 0x2c
    unsigned int cnt3;   // 0x30
    unsigned int cnt4;   // 0x34
    unsigned int cnt5;   // 0x38
    unsigned int idxA;   // 0x3c
    unsigned int idxB;   // 0x40
    unsigned int lim;    // 0x44
    unsigned int cnt6;   // 0x48
    unsigned int tmp16;  // 0x4c
    unsigned int cnt7;   // 0x50
    unsigned int cnt8;   // 0x54
    unsigned int def0;   // 0x58
    unsigned int tmpL;   // 0x5c
};

void Loader::FUN_002e3bd0(Slot1 a1, Slot2 a2, int a3, PalSrc *a4)
{
    Frame f;
    unsigned int fl = flags;
    f.self = this;
    if (fl & 0x20)
        f.vA = 1;
    else if (fl & 0x4000)
        f.vA = (fl >> 15) & 7;
    else
        f.vA = 0;
    f.lim = fl & 0xf;
    f.obj = 0;
    GroupBase *g;
    if (a4 != 0 && (unsigned int)((a4->end - a4->begin) >> 6) > 0) {
        void *mem = thunk_FUN_0008d690(0x68);
        pure3d::PrimGroupSkinnedStreamed *sg = 0;
        if (mem != 0)
            sg = new (mem) pure3d::PrimGroupSkinnedStreamed(flags, f18, f1c);
        g = sg;
        f.obj = sg;
    } else {
        void *mem = thunk_FUN_0008d690(0x60);
        g = 0;
        if (mem != 0)
            g = ((GroupBase *)mem)->FUN_002e01d0(flags, f18, f1c);
    }
    g->SetName(f08);
    g->f44 = f0c;
    FUN_002a46d0(a1, g);
    DevObj *dev = DAT_0052c2a8->Get(0x106);
    if (dev != 0) {
        if (dev->Check(f08->f10, 0))
            g->f58 = dev->Make(f08->f10, f0c, flags, 0, 0);
    }
    Stream *stream = a2.s;
    VData *vd = g->vdata;
    while (stream->FUN_002669f0()) {
        Loader *self = f.self;
        unsigned int id = stream->FUN_00266a30();
        switch (id) {
        case 0x10005:
            if (self->flags & 0x2000) {
                stream->reader->FUN_002647e0(&f.cnt1, 1, 4, 1);
                unsigned int n = f.cnt1;
                if (n > 0) {
                    unsigned int off = 0;
                    do {
                        stream->reader->FUN_002647e0(vd->f18 + off, 3, 4, 1);
                        off += 0xc;
                    } while (--n != 0);
                }
                if (f.self->flags & 0x80) {
                    if (vd->f20 != 0)
                        memcpy(vd->f20, vd->f18, vd->f0c * 12);
                }
            }
            break;
        case 0x10006:
            if (self->flags & 0x10) {
                stream->reader->FUN_002647e0(&f.cnt2, 1, 4, 1);
                unsigned int n = f.cnt2;
                if (n > 0) {
                    unsigned int off = 0;
                    do {
                        stream->reader->FUN_002647e0(vd->f1c + off, 3, 4, 1);
                        off += 0xc;
                    } while (--n != 0);
                }
            }
            break;
        case 0x10016:
            if (self->flags & 0x800) {
                stream->reader->FUN_002647e0(&f.cnt3, 1, 4, 1);
                unsigned int n = f.cnt3;
                if (n > 0) {
                    unsigned int off = 0;
                    do {
                        stream->reader->FUN_002647e0(vd->f28 + off, 3, 4, 1);
                        off += 0xc;
                    } while (--n != 0);
                }
            }
            break;
        case 0x10015:
            if (self->flags & 0x1000) {
                stream->reader->FUN_002647e0(&f.cnt4, 1, 4, 1);
                unsigned int n = f.cnt4;
                if (n > 0) {
                    unsigned int off = 0;
                    do {
                        stream->reader->FUN_002647e0(vd->f30 + off, 3, 4, 1);
                        off += 0xc;
                    } while (--n != 0);
                }
            }
            break;
        case 0x10008:
            if (self->flags & 0x20) {
                stream->reader->FUN_002647e0(&f.cnt5, 1, 4, 1);
                unsigned int n = f.cnt5;
                unsigned int i = 0;
                if (n > 0) {
                    do {
                        stream->reader->FUN_002647e0(vd->uv[0] + i * 4, 1, 4, 1);
                        i++;
                    } while (i < n);
                }
            }
            break;
        case 0x1001c:
            if (self->flags & 0x4000) {
                stream->reader->FUN_002647e0(&f.cntA, 1, 4, 1);
                stream->reader->FUN_002647e0(&f.idxA, 1, 4, 1);
                unsigned int index = f.idxA;
                if (index < f.vA) {
                    unsigned int i = 0;
                    if (f.cntA > 0) {
                        do {
                            stream->reader->FUN_002647e0(vd->uv[index] + i * 4, 1, 4, 1);
                            i++;
                        } while (i < f.cntA);
                    }
                }
            }
            break;
        case 0x10007:
            if (self->flags & 0xf) {
                stream->reader->FUN_002647e0(&f.cntB, 1, 4, 1);
                stream->reader->FUN_002647e0(&f.idxB, 1, 4, 1);
                unsigned int index = f.idxB;
                if (index < f.lim) {
                    unsigned int i = 0;
                    if (f.cntB > 0) {
                        do {
                            stream->reader->FUN_002647e0(vd->tex[index] + i * 8, 2, 4, 1);
                            i++;
                        } while (i < f.cntB);
                    }
                }
            }
            break;
        case 0x1000a: {
            stream->reader->FUN_002647e0(&f.cnt6, 1, 4, 1);
            unsigned int n = f.cnt6;
            unsigned int i = 0;
            if (n > 0) {
                do {
                    stream->reader->FUN_002647e0(&f.tmp16, 1, 4, 1);
                    vd->f14[i] = (unsigned short)f.tmp16;
                    i++;
                } while (i < n);
            }
            if (vd->f20 != 0)
                memcpy(vd->f20, vd->f18, vd->f0c * 12);
            break;
        }
        case 0x1000c:
            if (self->flags & 0x100) {
                stream->reader->FUN_002647e0(&f.cnt7, 1, 4, 1);
                unsigned int n = f.cnt7;
                if (n > 0) {
                    unsigned int off = 0;
                    do {
                        stream->reader->FUN_002647e0(vd->uv[3] + off, 3, 4, 1);
                        off += 0xc;
                    } while (--n != 0);
                }
            }
            break;
        case 0x1000b:
            if (self->flags & 0x80) {
                stream->reader->FUN_002647e0(&f.cnt8, 1, 4, 1);
                unsigned int n = f.cnt8;
                unsigned int i = 0;
                if (n > 0) {
                    do {
                        stream->reader->FUN_002647e0(&a1.u, 1, 4, 1);
                        vd->uv[2][i * 4] = (char)(a1.u >> 24);
                        vd->uv[2][i * 4 + 1] = (char)(a1.u >> 16);
                        vd->uv[2][i * 4 + 2] = (char)(a1.u >> 8);
                        vd->uv[2][i * 4 + 3] = (char)a1.u;
                        i++;
                    } while (i < n);
                }
            }
            break;
        case 0x1000d:
            if (self->flags & 0x80) {
                stream->reader->FUN_002647e0(&a2.n, 1, 4, 1);
                void *m = FUN_0008d690(0x14);
                MatrixPaletteList *l = 0;
                if (m != 0)
                    l = new (m) MatrixPaletteList();
                f.list = l;
                IntVec *v = &l->vec;
                f.def0 = 0;
                v->FUN_002e16f0(a2.n, &f.def0);
                unsigned int i = 0;
                if (a2.n > 0) {
                    do {
                        stream->reader->FUN_002647e0(&f.tmpL, 1, 4, 1);
                        v->begin[i] = f.tmpL;
                        i++;
                    } while (i < a2.n);
                }
                RefObj *p = a4;
                if (p != 0)
                    p->AddRef();
                pure3d::PrimGroupSkinnedStreamed *sg = f.obj;
                if (sg->pal != 0)
                    sg->pal->Release();
                sg->pal = p;
                MatrixPaletteList *l2 = f.list;
                if (l2 != 0)
                    l2->AddRef();
                if (sg->list != 0)
                    sg->list->Release();
                sg->list = l2;
            }
            break;
        default:
            break;
        }
        stream->FUN_00266be0();
    }
}
