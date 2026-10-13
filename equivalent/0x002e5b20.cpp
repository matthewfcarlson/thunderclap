// STATUS: equivalent (tools/equiv.py level 3: 223 inputs, branch coverage 60/62, incomplete)
// FUN_002e5b20 @ 0x002e5b20
void *FUN_0008d690(unsigned int size);

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

struct Quad {
    unsigned short s[4];
    void FUN_002c6d30();
    void FUN_002c6d50();
};

struct ElemC {
    unsigned int id;
    Quad q;
};
struct ElemF {
    unsigned int id;
    float v[2];
};
struct ElemV {
    unsigned int id;
    float v[3];
};

struct VecC {
    ElemC *begin;
    ElemC *end;
    int pad8;
    char FUN_002e5700(unsigned int n, const ElemC *def);
};
struct VecF {
    ElemF *begin;
    ElemF *end;
    int pad8;
    char FUN_002e56a0(unsigned int n, const ElemF *def);
};
struct VecV {
    ElemV *begin;
    ElemV *end;
    int pad8;
    char FUN_002e5640(unsigned int n, const ElemV *def);
};

class Mesh {
public:
    virtual void v0();
    char pad04[4];
    unsigned int f08;
    unsigned int f0c;
    unsigned int flags;
    VecV pos;
    VecV nrm;
    VecF vu0;
    VecF vu1;
    VecF vu2;
    VecF vu3;
    VecC clr0;
    VecC clr1;
    Mesh *FUN_002e5a10();
};

struct Frame {
    Mesh *mesh;       // 8
    unsigned int c12; // 12
    unsigned int remain;
    unsigned int c20, c24, c28, c32, c36, c40;
    unsigned int u44;
    unsigned int t48, t52, t56, t60, t64, t68, t72, t76, t80, t84, t88, t92, t96, t100;
    ElemC clr1; // 104
    union {
        ElemC e12;
        ElemF f12;
        ElemV e16;
    } d;
};

Mesh *__stdcall FUN_002e5b20(Stream *s, int unused)
{
    Frame f;
    s->reader->FUN_002647e0(&f.t88, 1, 4, 1);
    void *mem = FUN_0008d690(0x74);
    Mesh *m;
    if (mem != 0) {
        m = ((Mesh *)mem)->FUN_002e5a10();
        f.mesh = m;
    } else {
        f.mesh = 0;
        m = f.mesh;
    }
    s->reader->FUN_002647e0(&f.u44, 1, 4, 1);
    m->f08 = f.u44;
    s->reader->FUN_002647e0(&f.u44, 1, 4, 1);
    m->f0c = f.u44;
    while (s->FUN_002669f0()) {
        int id = s->FUN_00266a30() - 0x10f00;
        if (id == 0) {
            s->reader->FUN_002647e0(&f.t100, 1, 4, 1);
            s->reader->FUN_002647e0(&f.t80, 1, 4, 1);
            if (f.t80 == 0x534f50) {
                s->reader->FUN_002647e0(&f.u44, 1, 4, 1);
                unsigned int n = f.u44;
                m->pos.FUN_002e5640(n, &f.d.e16);
                if (n > 0) {
                    unsigned int rem = f.u44;
                    unsigned int i = 0;
                    do {
                        s->reader->FUN_002647e0(&f.t88, 1, 4, 1);
                        m->pos.begin[i].id = f.t88;
                        s->reader->FUN_002647e0(m->pos.begin[i].v, 3, 4, 1);
                        i++;
                    } while (--rem != 0);
                }
                m->flags |= 0x10;
            } else if (f.t80 == 0x4c4d524e) {
                s->reader->FUN_002647e0(&f.c40, 1, 4, 1);
                unsigned int n = f.c40;
                m->nrm.FUN_002e5640(n, &f.d.e16);
                if (n > 0) {
                    unsigned int rem = f.c40;
                    unsigned int i = 0;
                    do {
                        s->reader->FUN_002647e0(&f.t84, 1, 4, 1);
                        m->nrm.begin[i].id = f.t84;
                        s->reader->FUN_002647e0(m->nrm.begin[i].v, 3, 4, 1);
                        i++;
                    } while (--rem != 0);
                }
                m->flags |= 0x20;
            }
        } else if (id == 1) {
            s->reader->FUN_002647e0(&f.t96, 1, 4, 1);
            s->reader->FUN_002647e0(&f.t60, 1, 4, 1);
            if (f.t60 == 0x325655) {
                s->reader->FUN_002647e0(&f.c32, 1, 4, 1);
                unsigned int n = f.c32;
                m->vu2.FUN_002e56a0(n, &f.d.f12);
                if (n > 0) {
                    f.remain = f.c32;
                    unsigned int i = 0;
                    do {
                        s->reader->FUN_002647e0(&f.t72, 1, 4, 1);
                        m->vu2.begin[i].id = f.t72;
                        s->reader->FUN_002647e0(m->vu2.begin[i].v, 2, 4, 1);
                        i++;
                        f.remain--;
                    } while (f.remain != 0);
                }
                m->flags |= 4;
            } else if (f.t60 == 0x305655) {
                s->reader->FUN_002647e0(&f.c28, 1, 4, 1);
                unsigned int n = f.c28;
                m->vu0.FUN_002e56a0(n, &f.d.f12);
                if (n > 0) {
                    f.remain = f.c28;
                    unsigned int i = 0;
                    do {
                        s->reader->FUN_002647e0(&f.t68, 1, 4, 1);
                        m->vu0.begin[i].id = f.t68;
                        s->reader->FUN_002647e0(m->vu0.begin[i].v, 2, 4, 1);
                        i++;
                        f.remain--;
                    } while (f.remain != 0);
                }
                m->flags |= 1;
            } else if (f.t60 == 0x315655) {
                s->reader->FUN_002647e0(&f.c24, 1, 4, 1);
                unsigned int n = f.c24;
                m->vu1.FUN_002e56a0(n, &f.d.f12);
                if (n > 0) {
                    f.remain = f.c24;
                    unsigned int i = 0;
                    do {
                        s->reader->FUN_002647e0(&f.t64, 1, 4, 1);
                        m->vu1.begin[i].id = f.t64;
                        s->reader->FUN_002647e0(m->vu1.begin[i].v, 2, 4, 1);
                        i++;
                        f.remain--;
                    } while (f.remain != 0);
                }
                m->flags |= 2;
            } else if (f.t60 == 0x335655) {
                s->reader->FUN_002647e0(&f.c36, 1, 4, 1);
                unsigned int n = f.c36;
                m->vu3.FUN_002e56a0(n, &f.d.f12);
                if (n > 0) {
                    f.remain = f.c36;
                    unsigned int i = 0;
                    do {
                        s->reader->FUN_002647e0(&f.t76, 1, 4, 1);
                        m->vu3.begin[i].id = f.t76;
                        s->reader->FUN_002647e0(m->vu3.begin[i].v, 2, 4, 1);
                        i++;
                        f.remain--;
                    } while (f.remain != 0);
                }
                m->flags |= 8;
            }
        } else if (id == 2) {
            s->reader->FUN_002647e0(&f.t92, 1, 4, 1);
            s->reader->FUN_002647e0(&f.t48, 1, 4, 1);
            if (f.t48 == 0x30524c43) {
                s->reader->FUN_002647e0(&f.c20, 1, 4, 1);
                f.d.e12.q.FUN_002c6d30();
                unsigned int n = f.c20;
                m->clr0.FUN_002e5700(n, &f.d.e12);
                f.d.e12.q.FUN_002c6d50();
                if (n > 0) {
                    f.remain = f.c20;
                    unsigned int i = 0;
                    do {
                        s->reader->FUN_002647e0(&f.t56, 1, 4, 1);
                        m->clr0.begin[i].id = f.t56;
                        s->reader->FUN_002647e0(&m->clr0.begin[i].q, 4, 2, 1);
                        i++;
                        f.remain--;
                    } while (f.remain != 0);
                }
                m->flags |= 0x40;
            } else if (f.t48 == 0x31524c43) {
                s->reader->FUN_002647e0(&f.c12, 1, 4, 1);
                f.clr1.q.FUN_002c6d30();
                unsigned int n = f.c12;
                m->clr1.FUN_002e5700(n, &f.clr1);
                f.clr1.q.FUN_002c6d50();
                if (n > 0) {
                    f.remain = f.c12;
                    unsigned int i = 0;
                    do {
                        s->reader->FUN_002647e0(&f.t52, 1, 4, 1);
                        m->clr1.begin[i].id = f.t52;
                        s->reader->FUN_002647e0(&m->clr1.begin[i].q, 4, 2, 1);
                        i++;
                        f.remain--;
                    } while (f.remain != 0);
                }
                m->flags |= 0x80;
            }
        }
        s->FUN_00266be0();
    }
    return m;
}
