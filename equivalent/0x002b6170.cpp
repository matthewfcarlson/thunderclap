// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 39/39)
// pure3d::ShadowMeshLoader::vfunc_5 @ 0x002b6170
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
void *FUN_0008d690(unsigned int size);
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);

struct V3_2b6170 { float x, y, z; };

struct Name_2b6170 {
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

namespace pure3d {
class ShadowMeshTopology {
public:
    virtual void v0();
    virtual void v1();
    int f04;
    int f08;
    int f0c;
    unsigned short *f10;
    void *f14;
    ShadowMeshTopology(int a, int b)
    {
        f04 = 0;
        f10 = 0;
        f14 = 0;
        f0c = b;
        f08 = a;
        f10 = (unsigned short *)FUN_0008d6d0(b * 12);
        f14 = FUN_0008d6d0(f0c);
    }
};

}

class VertexSet {
public:
    virtual void v0();
    virtual void v1();
    char pad04[0xc];
    V3_2b6170 *f10;
    V3_2b6170 *f14;
    VertexSet *FUN_002b5070(int a, int b);
};

struct Res_2b6170 {
    char pad0[0x14];
    float f14[6];
    float f2c[4];
    char pad3c[0x44 - 0x3c];
    pure3d::ShadowMeshTopology *f44;
    VertexSet *f48;
};

struct Target_2b6170 {
    char pad0[8];
    Name_2b6170 name;
    char pad10[4];
    float f14[6];
    float f2c[4];
    char pad3c[0x48 - 0x3c];
    Res_2b6170 **f48;
};

struct Frame_2b6170 {
    int cntA;                        // S+0x10
    Res_2b6170 *r0;                         // 0x14
    float t[6];                      // 0x18
    char pad30[3];
    unsigned char len;               // 0x33
    int nf;                          // 0x34
    Target_2b6170 *dest;                    // 0x38
    int tmp3c;                       // 0x3c
    int cnt;                         // 0x40
    int cnt2;                        // 0x44
    char name[0x100];                // 0x48
};

namespace pure3d {

class ShadowMeshLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(Target_2b6170 **out, unsigned __int64 *outId, Stream *s, void *inv);
    virtual Target_2b6170 *vfunc_6();
};

void ShadowMeshLoader::vfunc_5(Target_2b6170 **out, unsigned __int64 *outId, Stream *s, void *inv)
{
    Frame_2b6170 f;
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    unsigned int len = f.len;
    s->reader->FUN_002647e0(f.name, len, 1, 1);
    f.name[len] = 0;
    s->reader->FUN_002647e0(&f.tmp3c, 1, 4, 1);
    s->reader->FUN_002647e0(&f.cntA, 1, 4, 1);
    s->reader->FUN_002647e0(&f.nf, 1, 4, 1);
    f.dest = vfunc_6();
    f.dest->name.FUN_0027b040(f.name);
    f.r0 = *f.dest->f48;

    void *mem = FUN_0008d690(0x18);
    ShadowMeshTopology *topo = 0;
    if (mem != 0)
        topo = new (mem) ShadowMeshTopology(f.cntA, f.nf);
    if (topo != 0)
        topo->v0();
    if (f.r0->f44 != 0)
        f.r0->f44->v1();
    f.r0->f44 = topo;

    void *mem2 = FUN_0008d690(0x18);
    VertexSet *vs;
    if (mem2 != 0)
        vs = ((VertexSet *)mem2)->FUN_002b5070(f.cntA, f.nf);
    else
        vs = 0;
    if (vs != 0)
        vs->v0();
    if (f.r0->f48 != 0)
        f.r0->f48->v1();
    f.r0->f48 = vs;

    if (s->FUN_002669f0()) {
        do {
            s->FUN_00266a30();
            int id = s->FUN_00266c30();
            if (id == 0x1001b) {
                s->reader->FUN_002647e0(&f.cnt, 1, 4, 1);
                if ((unsigned int)f.cnt != 0) {
                    unsigned int off = 0;
                    f.cntA = f.cnt;
                    do {
                        s->reader->FUN_002647e0((char *)topo->f10 + off, 6, 2, 1);
                        off += 12;
                    } while (--f.cntA != 0);
                }
            } else if (id == 0x10005) {
                s->reader->FUN_002647e0(&f.cnt2, 1, 4, 1);
                if ((unsigned int)f.cnt2 != 0) {
                    unsigned int off = 0;
                    f.cntA = f.cnt2;
                    do {
                        s->reader->FUN_002647e0((char *)vs->f10 + off, 3, 4, 1);
                        off += 12;
                    } while (--f.cntA != 0);
                }
            } else if (id == 0x10004) {
                s->reader->FUN_002647e0(&f.r0->f2c[0], 3, 4, 1);
                s->reader->FUN_002647e0(&f.tmp3c, 1, 4, 1);
                f.r0->f2c[3] = *(float *)&f.tmp3c;
            } else if (id == 0x10003) {
                s->reader->FUN_002647e0(&f.r0->f14[0], 3, 4, 1);
                s->reader->FUN_002647e0(&f.r0->f14[3], 3, 4, 1);
            }
            s->FUN_00266be0();
        } while (s->FUN_002669f0());
    }

    Res_2b6170 *r = f.r0;
    f.t[0] = r->f14[0];
    f.t[1] = r->f14[1];
    f.t[2] = r->f14[2];
    f.t[3] = r->f14[3];
    f.t[4] = r->f14[4];
    f.t[5] = r->f14[5];
    f.dest->f14[0] = f.t[0];
    f.dest->f14[2] = f.t[2];
    f.dest->f14[1] = f.t[1];
    f.dest->f14[3] = f.t[3];
    f.dest->f14[5] = f.t[5];
    f.dest->f14[4] = f.t[4];
    f.t[0] = r->f2c[0];
    f.t[1] = r->f2c[1];
    f.t[2] = r->f2c[2];
    f.t[3] = r->f2c[3];
    f.dest->f2c[0] = f.t[0];
    f.dest->f2c[2] = f.t[2];
    f.dest->f2c[1] = f.t[1];
    f.dest->f2c[3] = f.t[3];

    unsigned int i;
    for (i = 0; i < (unsigned int)f.nf; i++) {
        unsigned short *ip = (unsigned short *)((char *)topo->f10 + i * 12);
        V3_2b6170 *vb = vs->f10;
        V3_2b6170 *pa = vb + ip[0];
        V3_2b6170 *pb = vb + ip[1];
        V3_2b6170 *pc = vb + ip[2];
        double d1x = pb->x - pa->x;
        double d1y = pb->y - pa->y;
        double d1z = pb->z - pa->z;
        f.t[0] = pc->x - pb->x;
        f.t[1] = pc->y - pb->y;
        double ez = pc->z - pb->z;
        V3_2b6170 *out3 = (V3_2b6170 *)((char *)vs->f14 + i * 12);
        out3->x = (float)(ez * d1y - f.t[1] * d1z);
        out3->y = (float)(d1z * f.t[0] - ez * d1x);
        out3->z = (float)(f.t[1] * d1x - d1y * f.t[0]);
    }

    *out = f.dest;
    *outId = FUN_002672f0(f.name, 0, 0);
}

}
