// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00307030..0x00308a30 (kind game, layer engine, confidence high), dominant class physics::CollisionObjectLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_fa930a40 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fa930a40 {} using namespace fn_fa930a40;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_fa930a40 {
typedef unsigned short u16_307030;
class Stream {
  public:
    void FUN_00307060(const unsigned short* limits, hulk_intptr unused);
};
class A_307810 {
  public:
    char pad[0x284];
    hulk_intptr member;
    void First_00266a30();
    void Last_00266be0();
};
class B_307810 {
  public:
};
extern "C" void __fastcall FUN_002fa720(void *p);
extern "C" void __fastcall FUN_00011090(void *p);
extern "C" void __fastcall FUN_000115b0(void *p);
void __stdcall FUN_00011520(void *p, unsigned int size, int count, void(__fastcall *ctor)(void *));
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);
extern "C" void *FUN_0008d690(unsigned int size);
struct Reader_3078a0 {
};
struct Stream_3078a0 {
    char pad0[0x284];
    Reader_3078a0 *reader;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};
struct Face_3078a0 {
    int v[3];
    unsigned char c[4];
    unsigned short a;
    unsigned short b;
    unsigned short d;
    unsigned short e;
};
struct Geom_3078a0 {
    char pad00[8];
    float *verts;
    float *f0c;
    unsigned char *f10;
    unsigned short *indices;
    Face_3078a0 *faces;
    unsigned short n1c;
    char pad1e[2];
    unsigned short n20;
    char pad22[2];
    float lo[3];
    float hi[3];
    float inv[3];
};
struct CollisionMesh_nv_3078a0 {
    physics::CollisionMesh *FUN_002f3530();
};
typedef void(__cdecl *Hook_3078a0)(Stream_3078a0 *s, physics::CollisionMesh *m);
union Slot_3078a0 {
    Stream_3078a0 *s;
    unsigned int u;
    unsigned short w;
};
struct Frame_3078a0 {
    unsigned int s10;
    unsigned int s14;
    unsigned int s18;
    unsigned int i1c;
    Geom_3078a0 *saved20;
    unsigned int n24;
    hulk_uintptr x28;
    unsigned int n2c;
    unsigned int n30;
    unsigned int t34;
    unsigned int t38;
    unsigned int t3c;
    unsigned int v40;
    unsigned int sz44;
    unsigned int v48;
    float f4c;
    unsigned int v50;
    unsigned int v54;
    unsigned int v58;
    unsigned int s5c;
    float dy;
    float dz;
};
class X_307ef0 {
  public:
    int n;
    int cap;
    char* buf;
    char* next();
};
struct Entry_307f30 { unsigned a,b; void* resource; unsigned char c,d; char pad[2]; };
extern "C" void __cdecl FUN_0008d340(void*);
struct Flags_307f30 { int size; int capacity; unsigned char* data;  };
struct Object { int count; Entry_307f30* entries; Flags_307f30 flags; void FUN_00307f30(int); };
extern "C" char DAT_00431c90[];
class CollisionObjectLoader {
  public:
    hulk_uintptr v;
    unsigned a;
    unsigned b;
    unsigned c;
    unsigned d;
    CollisionObjectLoader();
};
extern int hulk_at_00431cac;
class WorldCollisionObjectLoader {
  public:
    virtual void Dummy();
    int a;
    int b;
    int c;
    int d;
    WorldCollisionObjectLoader();
};
struct V3_3080a0 {
    float x, y, z;
};
struct Reader {
    char pad000[0x284];
    Stream* stream;
    hulk_intptr FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
    unsigned short FUN_00201750();
};
struct Vec_3080a0 {
    int a;
    int b;
    int c;
};
struct Node {
    char pad04[8];
    int f08;
    int f0c;
    char pad10[4];
    Vec_3080a0* children;
    void FUN_00306600(int a);
    void FUN_00306930(Node* child);
};
struct CollisionSphere_3080a0 : Node {
    char pad18[0x48 - 0x18];
    Node* FUN_002efe50(V3_3080a0* pos, int d);
};
struct CollisionCylinder_3080a0 : Node {
    char pad18[0x8c - 0x18];
    Node* FUN_002f3070(V3_3080a0* a, V3_3080a0* b, int r2, int r1, int flag);
};
struct CollisionOBB_3080a0 : Node {
    char pad18[0xbc - 0x18];
    Node* FUN_002fbed0(V3_3080a0* a, int* tri, V3_3080a0* b, V3_3080a0* c, V3_3080a0* d);
};
struct CollisionWall_3080a0 : Node {
    char pad18[0x60 - 0x18];
    Node* FUN_0030e630(V3_3080a0* a, V3_3080a0* b);
};
struct CollisionAABB_3080a0 : Node {
    char pad18[0x44 - 0x18];
    Node* FUN_00312900();
};
Node* __cdecl FUN_003078a0(Reader* r);
void __cdecl FUN_00307810(Reader* r, V3_3080a0* out);
struct Frame_3080a0 {
    int scratch;
    union {
        int d;
        unsigned char flag;
        int word;
    } u4;
    union {
        int a;
        Vec_3080a0* vec;
    } u8;
    int b;
    int c;
    int r1;
    int tri[3];
    V3_3080a0 v[9];
};
struct Item_3083e0 {
    char data[8];
};
struct Container_3083e0 {
    int count;
    int capacity;
    Item_3083e0* items;
    void grow_00304a10(int);
    Item_3083e0* add();
};
struct Stream_308410 {
};
struct Reader_308410 {
    char pad[0x284];
    Stream_308410 *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c30();
};
struct NameField_308410 {
};
struct NameKey_308410 {
    unsigned int lo;
    unsigned int hi;
};
struct HashList {
    int count;
    int cap;
    unsigned __int64 *data;
    int pad;
    void FUN_00304a10(int newCap);
};
struct Sub38_308410 {
    void FUN_00307f30(int n);
};
struct Target_308410 {
    void FUN_00306300();
};
// (x64t5) decls/physics_world.h's CollisionObject words: the vftable and Entity's words (natively ending at 0x18, as
// Entity's own size), the names, then the shape, link and state pointers where every view of the object has them
class CollisionObject_308410 {
public:
    hulk_intptr vptr;
    int refs;
    NameField_308410 name;
    char pad9[7];
#if defined(HULK_PTR64)
    int entity_pad_;
#endif
    NameField_308410 name2;
    char pad11[7];
    void* f18; int f1c;
    Target_308410 *f20;
    int f24;
    struct { int f28, f2c; void* f30; char b34, b35; };
    struct { Sub38_308410 sub; char pad39[3]; HashList *lists; struct { int f40, f44; unsigned char* f48; char b4c, b4d; }; };
    char b50;
    char pad51[3];
    int f54;
    char pad58[0x68 - 0x58];
    char b68;
    char b69;
    char pad6a[2];
    int f6c;
    char pad70[0x78 - 0x70];
    int f78;
    char pad7c[4];

    CollisionObject_308410 *FUN_00304ed0();
    void FUN_00305190(int v1, int v2, bool b1, bool b2);
    void FUN_00304b40(void* x);   // (x64t5) the shape, a pointer (was `int`)
};
void* __cdecl FUN_003080a0(Reader_308410 *r);   // (x64t5) returns the shape (a Node*; was `int`)
int __cdecl FUN_002f2750(unsigned int lo, unsigned int hi);
struct Frame_308410 {
    char pad10[3];
    unsigned char len;
    int tmp;
    char pad18[2];
    unsigned char flag5;
    unsigned char flag6;
    unsigned short s4;
    short p1c;
    unsigned short s5;
    short p20;
    unsigned short s6;
    short p24;
    unsigned short s2;
    short p28;
    unsigned short s3;
    short p2c;
    unsigned short sD;
    short p30;
    unsigned short s1;
    short p34;
    int n;
    int v1;
    int v3;
    int v2;
    NameKey_308410 *savedName;
    int i1;
    int i2;
    int i3;
    char name2[0x100];
    char name1[0x100];
    char name3[0x100];
};
struct Ref_3088d0 { virtual void addRef()=0; virtual void release()=0; };
struct Name_3088d0 { unsigned a,b; void FUN_0027b040(const char*); };
struct Obj_3088d0 { char pad[8]; Name_3088d0 name; Ref_3088d0* ref; char tail[4]; Obj_3088d0* FUN_002fe1d0(); };
struct Reader_3088d0 { void FUN_002647e0(void*,unsigned,unsigned,unsigned); };
struct Stream_3088d0 { char pad[0x284]; Reader_3088d0* reader; bool FUN_002669f0(); void FUN_00266a30(); unsigned FUN_00266c30(); void FUN_00266be0(); };
extern "C" void* __cdecl FUN_00263ea0(unsigned);
extern "C" Ref_3088d0* __cdecl FUN_003080a0(Stream_3088d0*);


// 0x00307030 FUN_00307030 (40 B): matches/0x00307030.cpp
// sym: ?FUN_00307030@fn_fa930a40@@YAXG@Z
void __cdecl FUN_00307030(u16_307030 value) {
    if (*(*(u16_307030**)&DAT_0055543c) < 0x400) {
        (*(u16_307030**)&DAT_00555440)[*(*(u16_307030**)&DAT_0055543c)] = value;
        ++*(*(u16_307030**)&DAT_0055543c);
    }
}


// 0x00307060 FUN_00307060 (454 B): equivalent/0x00307060.cpp
// sym: ?FUN_00307060@Stream@fn_fa930a40@@QAEXPBGH@Z @bf4810b6b389 @wf5d822b465d5
// STATUS: equivalent (tools/equiv.py level 3: 53 inputs, branch coverage 33/36, incomplete)
// FUN_00307060 @ 0x00307060
// A packed stream of 16-bit words: each record has a header (selector in bits 12-13,
// type in bits 14-15), literal words that are appended to a global 0x400-entry buffer,
// and offsets to follow into nested records.
void Stream::FUN_00307060(const unsigned short* limits, hulk_intptr unused)
{
    const unsigned short* p = (const unsigned short*)this;
    for (;;) {
        unsigned hdr = p[0];
        unsigned sel = (hdr >> 12) & 3;
        unsigned short count;
        unsigned short skipA = 0;
        unsigned short skipB = 0;
        switch (sel) {
        case 0:
            count = hdr & 0xfff;
            break;
        case 1:
            skipA = (hdr >> 6) & 0x3f;
            count = hdr & 0x3f;
            break;
        case 2:
            skipB = (hdr >> 6) & 0x3f;
            count = hdr & 0x3f;
            break;
        default:
            skipA = (hdr >> 8) & 0xf;
            skipB = (hdr >> 4) & 0xf;
            count = hdr & 0xf;
            break;
        }

        const unsigned short* s = p + 1;
        for (unsigned short n = count; n != 0; n--) {
            unsigned short idx = *(*(unsigned short**)&DAT_0055543c);
            if (idx < 0x400) {
                (*(unsigned short**)&DAT_00555440)[idx] = *s;
                (*(*(unsigned short**)&DAT_0055543c))++;
            }
            s++;
        }

        unsigned short type = p[0] >> 14;
        if (type == 3)
            return;
        unsigned short key = *s;
        s++;

        if (limits[type] > key) {
            if (sel & 1)
                s += skipA;
            else
                s++;
        } else if ((sel & 1) == 0) {
            const unsigned short* child = p + *s;
            s++;
            ((Stream*)child)->FUN_00307060(limits, unused);
        } else {
            for (unsigned short n = skipA; n != 0; n--) {
                unsigned short idx = *(*(unsigned short**)&DAT_0055543c);
                if (idx < 0x400) {
                    (*(unsigned short**)&DAT_00555440)[idx] = *s;
                    (*(*(unsigned short**)&DAT_0055543c))++;
                }
                s++;
            }
        }

        if (limits[type + 3] < key)
            return;
        if ((sel & 2) == 0) {
            p = p + *s;
            continue;
        }
        for (unsigned short n = skipB; n != 0; n--) {
            unsigned short idx = *(*(unsigned short**)&DAT_0055543c);
            if (idx < 0x400) {
                (*(unsigned short**)&DAT_00555440)[idx] = *s;
                (*(*(unsigned short**)&DAT_0055543c))++;
            }
            s++;
        }
        return;
    }
}

} // namespace fn_fa930a40

// 0x00307240 FUN_00307240 (1389 B): equivalent/0x00307240.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_00307240@Stream@fn_00307240@@QAEXTArg_307240@2@@Z @9633500c5509 @we1b0410c47aa
namespace fn_00307240 {
// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 84/90, incomplete)
// FUN_00307240 @ 0x00307240

struct Vec3_307240 {
    float x, y, z;
    void FUN_001f6bc0(const float *a, float t, const float *b) throw();
};

struct Ctx_307240 {
    float v0[3];
    float v1[3];
    float v2[3];
    float v3[3];
};

union Arg_307240 {
    Ctx_307240 *ctx;
    unsigned int n2;
};

void __cdecl FUN_00307030(unsigned int w) throw();

static __forceinline void Append(unsigned short w)
{
    unsigned short c = *(*(unsigned short**)&DAT_0055543c);
    if (c < 0x400) {
        (*(unsigned short**)&DAT_00555440)[c] = w;
        (*(*(unsigned short**)&DAT_0055543c))++;
    }
}

struct Stream {
    unsigned short w[1];
    void FUN_00307240(Arg_307240 a);
};

void Stream::FUN_00307240(Arg_307240 a)
{
    struct Frame {
        unsigned short *p;
        union {
            float absTmp;
            unsigned int code;
        } c;
        union {
            unsigned int n;
            float val;
        } u;
        Vec3_307240 save;
        Vec3_307240 out;
    } f;

    Ctx_307240 *ctx = a.ctx;
    Arg_307240 pa;
    pa.ctx = ctx;
    f.p = (unsigned short *)this;
    for (;;) {
        unsigned int h = *f.p;
        unsigned int op = (h >> 12) & 3;
        unsigned int cnt = 0;
        unsigned int ebp = 0;
        a.n2 = 0;
        switch (op) {
        case 0:
            cnt = h & 0xfff;
            break;
        case 1:
            ebp = (h >> 6) & 0x3f;
            cnt = h & 0x3f;
            break;
        case 2:
            a.n2 = (h >> 6) & 0x3f;
            cnt = h & 0x3f;
            break;
        default:
            ebp = (h >> 8) & 0xf;
            a.n2 = (h >> 4) & 0xf;
            cnt = h & 0xf;
            break;
        }
        unsigned short *esi = f.p + 1;
        if ((unsigned short)cnt != 0) {
            unsigned int n = (unsigned short)cnt;
            do {
                Append(*esi);
                esi++;
                n--;
            } while (n != 0);
        }
        unsigned int code = (unsigned short)(*f.p) >> 14;
        if (code == 3)
            return;
        f.u.n = *esi;
        f.u.val = (float)(int)f.u.n;
        esi++;
        float P, Q;
        if (ctx->v3[code] >= 0.0f) {
            P = ctx->v1[code];
            Q = ctx->v0[code];
        } else {
            P = ctx->v0[code];
            Q = ctx->v1[code];
        }
        if (P + 2.0f < f.u.val) {
            if (op & 1) {
                if ((unsigned short)ebp == 0)
                    return;
                unsigned int n = (unsigned short)ebp;
                do {
                    Append(*esi);
                    esi++;
                    n--;
                } while (n != 0);
                return;
            }
            f.p = f.p + *esi;
            continue;
        }
        if (Q - 2.0f > f.u.val) {
            if (op & 1)
                esi = esi + (unsigned short)ebp;
            else
                esi = esi + 1;
            if (op & 2) {
                unsigned int n = (unsigned short)a.n2;
                if (n == 0)
                    return;
                do {
                    Append(*esi);
                    esi++;
                    n--;
                } while (n != 0);
                return;
            }
            f.p = f.p + *esi;
            continue;
        }
        f.c.absTmp = ctx->v3[code];
        *(unsigned int *)&f.c.absTmp &= 0x7fffffff;
        if (f.c.absTmp < 1e-05f) {
            if (op & 1) {
                if ((unsigned short)ebp != 0) {
                    unsigned int n = (unsigned short)ebp;
                    do {
                        Append(*esi);
                        esi++;
                        n--;
                    } while (n != 0);
                }
            } else {
                unsigned short *sub = f.p + *esi;
                esi++;
                ((Stream *)sub)->FUN_00307240(pa);
            }
            if (!(op & 2)) {
                f.p = f.p + *esi;
                continue;
            }
            unsigned int n = a.n2;
            if ((unsigned short)n == 0)
                return;
            unsigned int m = (unsigned short)n;
            do {
                Append(*esi);
                esi++;
                m--;
            } while (m != 0);
            return;
        }
        if (op == 3) {
            unsigned int n = a.n2 + ebp;
            if ((unsigned short)n == 0)
                return;
            unsigned int m = (unsigned short)n;
            do {
                Append(*esi);
                esi++;
                m--;
            } while (m != 0);
            return;
        }
        float t = (f.u.val - ctx->v2[code]) / ctx->v3[code];
        f.c.code = code;
        f.out.FUN_001f6bc0(ctx->v2, t, ctx->v3);
        if (ctx->v3[f.c.code] >= 0.0f) {
            f.save = *(Vec3_307240 *)ctx->v1;
            *(Vec3_307240 *)ctx->v1 = f.out;
            if (op & 1) {
                if ((unsigned short)ebp != 0) {
                    unsigned int n = (unsigned short)ebp;
                    do {
                        FUN_00307030(*esi);
                        esi++;
                        n--;
                    } while (n != 0);
                }
            } else {
                unsigned short *sub = f.p + *esi;
                esi++;
                ((Stream *)sub)->FUN_00307240(pa);
            }
            *(Vec3_307240 *)ctx->v1 = f.save;
            f.save = *(Vec3_307240 *)ctx->v0;
            *(Vec3_307240 *)ctx->v0 = f.out;
            if (op & 2) {
                unsigned int n = a.n2;
                if ((unsigned short)n != 0) {
                    unsigned int m = (unsigned short)n;
                    do {
                        FUN_00307030(*esi);
                        esi++;
                        m--;
                    } while (m != 0);
                }
            } else {
                unsigned short *sub = f.p + *esi;
                ((Stream *)sub)->FUN_00307240(pa);
            }
            *(Vec3_307240 *)ctx->v0 = f.save;
            return;
        }
        f.save = *(Vec3_307240 *)ctx->v0;
        *(Vec3_307240 *)ctx->v0 = f.out;
        if (op & 1) {
            if ((unsigned short)ebp != 0) {
                unsigned int n = (unsigned short)ebp;
                do {
                    FUN_00307030(*esi);
                    esi++;
                    n--;
                } while (n != 0);
            }
        } else {
            unsigned short *sub = f.p + *esi;
            esi++;
            ((Stream *)sub)->FUN_00307240(pa);
        }
        *(Vec3_307240 *)ctx->v0 = f.save;
        f.save = *(Vec3_307240 *)ctx->v1;
        *(Vec3_307240 *)ctx->v1 = f.out;
        if (op & 2) {
            unsigned int n = a.n2;
            if ((unsigned short)n != 0) {
                unsigned int m = (unsigned short)n;
                do {
                    FUN_00307030(*esi);
                    esi++;
                    m--;
                } while (m != 0);
            }
        } else {
            unsigned short *sub = f.p + *esi;
            ((Stream *)sub)->FUN_00307240(pa);
        }
        *(Vec3_307240 *)ctx->v1 = f.save;
        return;
    }
}
} // namespace fn_00307240

namespace fn_fa930a40 {

// 0x003077c0 FUN_003077c0 (1 B): matches/0x003077c0.cpp
// sym: _FUN_003077c0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_003077c0() {}


// 0x00307810 FUN_00307810 (42 B): matches/0x00307810.cpp
// sym: ?target@fn_fa930a40@@YAXPAVA_307810@1@H@Z
void __cdecl target(A_307810* p1, hulk_intptr p2) {
    p1->First_00266a30();
    ((owners::X_2647e0 *)(((B_307810*)p1->member)))->FUN_002647e0((hulk_intptr)p2, (hulk_intptr)3, 4, (hulk_intptr)1);
    p1->Last_00266be0();
}


// 0x003078a0 FUN_003078a0 (1600 B): equivalent/0x003078a0.cpp
// sym: ?FUN_003078a0@fn_fa930a40@@YAPAVCollisionMesh@physics@@TSlot_3078a0@1@@Z @a444d7a09ca9 @w1a2a335f5f30
// STATUS: equivalent (tools/equiv.py level 3: 16463 inputs, branch coverage 56/56)
// FUN_003078a0 @ 0x003078a0
physics::CollisionMesh *FUN_003078a0(Slot_3078a0 a1)
{
    Frame_3078a0 f;
    Stream_3078a0 *stream = a1.s;
    ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&a1.u), (hulk_intptr)1, 4, (hulk_intptr)1);
    void *mem = FUN_0008d690(0xd4);
    physics::CollisionMesh *mesh = 0;
    if (mem != 0)
        mesh = ((CollisionMesh_nv_3078a0*)(((physics::CollisionMesh*)(((physics::CollisionMesh *)mem)))))->FUN_002f3530();
    Geom_3078a0 *g = (*(Geom_3078a0 * *)&mesh->f_44);
    f.saved20 = g;
    ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&a1.u), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&a1.u), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(g->lo), (hulk_intptr)3, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(g->hi), (hulk_intptr)3, 4, (hulk_intptr)1);
    float dx = g->hi[0] - g->lo[0];
    f.dy = g->hi[1] - g->lo[1];
    f.dz = g->hi[2] - g->lo[2];
    *(float *)&a1.u = dx;
    a1.u &= 0x7fffffff;
    g->inv[0] = (*(float *)&a1.u >= 1e-5f) ? 65535.0f / dx : 0.0f;
    *(float *)&a1.u = f.dy;
    a1.u &= 0x7fffffff;
    g->inv[1] = (*(float *)&a1.u >= 1e-5f) ? 65535.0f / f.dy : 0.0f;
    *(float *)&a1.u = f.dz;
    a1.u &= 0x7fffffff;
    g->inv[2] = (*(float *)&a1.u >= 1e-5f) ? 65535.0f / f.dz : 0.0f;

    while (stream->FUN_002669f0()) {
        unsigned int id = stream->FUN_00266a30();
        if (id == 0x7000008) {
            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.t34), (hulk_intptr)1, 4, (hulk_intptr)1);
            unsigned int n = f.t34;
            unsigned short *p = (unsigned short *)FUN_0008d6d0(n * 2);
            g->indices = p;
            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)p, (hulk_intptr)n, 2, (hulk_intptr)1);
        } else if (id == 0x7000006) {
            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.t38), (hulk_intptr)1, 4, (hulk_intptr)1);
            unsigned int n = (unsigned short)(__int64)f.t38;
            g->n20 = (unsigned short)(__int64)f.t38;
            unsigned int *raw = (unsigned int *)FUN_0008d6d0(n * 24 + 4);
            Face_3078a0 *arr;
            if (raw != 0) {
                raw[0] = n;
                arr = (Face_3078a0 *)(raw + 1);
                f.x28 = (hulk_uintptr)arr;
                FUN_00011520(arr, 0x18, n, FUN_002fa720);
                arr = (Face_3078a0 *)f.x28;
            } else {
                arr = 0;
            }
            unsigned int i = 0;
            g->faces = arr;
            if (g->n20 != 0) {
                do {
                    Face_3078a0 *e = (*(Geom_3078a0 * *)&mesh->f_44)->faces + i;
                    ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&a1.u), (hulk_intptr)1, 2, (hulk_intptr)1);
                    e->a = a1.w;
                    ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.s10), (hulk_intptr)1, 2, (hulk_intptr)1);
                    e->b = (unsigned short)(__int64)f.s10;
                    ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.s14), (hulk_intptr)1, 2, (hulk_intptr)1);
                    e->d = (unsigned short)(__int64)f.s14;
                    ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.s18), (hulk_intptr)1, 2, (hulk_intptr)1);
                    unsigned int v = (unsigned short)(__int64)f.s18;
                    e->e = (unsigned short)(__int64)((((((((v >> 4) & 0xfff) << 1) | ((v >> 2) & 1)) << 1) | ((v >> 1) & 1)) << 1) | (v & 1));
                    i++;
                } while (i < f.saved20->n20);
            }
            g = f.saved20;
        } else if (id == 0x7000003) {
            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.t3c), (hulk_intptr)1, 4, (hulk_intptr)1);
            unsigned int n = (unsigned short)(__int64)f.t3c;
            g->n1c = (unsigned short)(__int64)f.t3c;
            float *raw = (float *)FUN_0008d6d0(n * 12);
            f.x28 = (hulk_uintptr)raw;
            float *r;
            if (raw != 0) {
                FUN_00011520(raw, 0xc, n, FUN_00011090);
                r = (float *)f.x28;
            } else {
                r = 0;
            }
            g->verts = r;
            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)r, (hulk_intptr)(g->n1c * 3), 4, (hulk_intptr)1);
        } else if (id == 0x7000747) {
            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.n2c), (hulk_intptr)1, 4, (hulk_intptr)1);
            f.i1c = 0;
            if (f.n2c != 0) {
                do {
                    unsigned int off = (unsigned int)(__int64)(unsigned short)(__int64)f.i1c * 24;
                    unsigned int k = 0;
                    f.x28 = off;
                    do {
                        ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.v40), (hulk_intptr)1, 4, (hulk_intptr)1);
                        *(unsigned int *)((char *)(*(Geom_3078a0 * *)&mesh->f_44)->faces + f.x28) = f.v40;
                        ((unsigned char *)(*(Geom_3078a0 * *)&mesh->f_44)->faces)[off + k + 0xc] = 0xff;
                        k++;
                        f.x28 += 4;
                    } while ((int)(__int64)k < 3);
                    ((unsigned char *)(*(Geom_3078a0 * *)&mesh->f_44)->faces)[off + 0xf] = 0;
                    f.i1c++;
                } while (f.i1c < f.n2c);
            }
            g = f.saved20;
        } else if (id == 0x7000748) {
            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.n30), (hulk_intptr)1, 4, (hulk_intptr)1);
            f.i1c = 0;
            if (f.n30 != 0) {
                do {
                    unsigned int off = (unsigned int)(__int64)(unsigned short)(__int64)f.i1c * 24;
                    unsigned int pos = off;
                    f.x28 = 3;
                    do {
                        ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.v48), (hulk_intptr)1, 4, (hulk_intptr)1);
                        *(unsigned int *)((char *)(*(Geom_3078a0 * *)&mesh->f_44)->faces + pos) = f.v48;
                        pos += 4;
                    } while (--f.x28 != 0);
                    int k = 0;
                    do {
                        ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.f4c), (hulk_intptr)1, 4, (hulk_intptr)1);
                        unsigned int q = (unsigned int)(__int64)(int)(__int64)(f.f4c * 32.0f);
                        if (q >= 0x100)
                            q = 0xff;
                        ((unsigned char *)(*(Geom_3078a0 * *)&mesh->f_44)->faces)[off + k + 0xc] = (unsigned char)(__int64)q;
                        k++;
                    } while (k < 3);
                    ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.v54), (hulk_intptr)1, 4, (hulk_intptr)1);
                    ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.v50), (hulk_intptr)1, 4, (hulk_intptr)1);
                    ((unsigned char *)(*(Geom_3078a0 * *)&mesh->f_44)->faces)[off + 0xf] = (unsigned char)(__int64)(int)(__int64)((1.0f - *(float *)&f.v50) * 255.0f);
                    ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.v58), (hulk_intptr)1, 4, (hulk_intptr)1);
                    f.i1c++;
                } while (f.i1c < f.n30);
            }
            g = f.saved20;
        } else if (id == 0x7000800) {
            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.n24), (hulk_intptr)1, 4, (hulk_intptr)1);
            unsigned int n = f.n24;
            float *p = (float *)FUN_0008d6d0(n * 4);
            float *arr;
            if (p != 0) {
                FUN_00011520(p, 4, f.n24, FUN_000115b0);
                arr = p;
            } else {
                arr = 0;
            }
            g->f0c = arr;
            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)arr, (hulk_intptr)(f.n24), 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.sz44), (hulk_intptr)1, 4, (hulk_intptr)1);
            unsigned int sz = f.sz44;
            unsigned char *q = (unsigned char *)FUN_0008d6d0(sz);
            g->f10 = q;
            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)q, (hulk_intptr)sz, 1, (hulk_intptr)1);
        } else if (id == 0x7016000) {
            Hook_3078a0 h = (*(Hook_3078a0*)&DAT_00555444);
            if (h != 0)
                h(stream, mesh);
        }
        stream->FUN_00266be0();
    }
    return mesh;
}


// 0x00307ef0 FUN_00307ef0 (34 B): matches/0x00307ef0.cpp
// sym: ?next@X_307ef0@fn_fa930a40@@QAEPADXZ
char* X_307ef0::next() {
    if (n >= cap)
        ((owners::Buffer_3048a0 *)this)->FUN_003048a0(cap * 2);
    ++n;
    return buf + n - 1;
}


// 0x00307f30 FUN_00307f30 (226 B): equivalent/0x00307f30.cpp
// sym: ?FUN_00307f30@Object@fn_fa930a40@@QAEXH@Z @e77a25a32722 @w8fbe1a65936f
// STATUS: equivalent (tools/equiv.py level 3: 44 inputs, branch coverage 18/18)
// FUN_00307f30 @ 0x00307f30
void Object::FUN_00307f30(int n) {
 Entry_307f30* old=entries;
 if(old) {
  int* header = reinterpret_cast<int*>(old)-1;
  int oldCount=*header;
  for(int i=oldCount-1;i>=0;--i) FUN_0008d340(old[i].resource);
  FUN_0008d340(header);
 }
 flags.size=0;
 count=n;
 int* allocation=static_cast<int*>(FUN_0008d6d0((unsigned)n*16+4));
 Entry_307f30* fresh=0;
 if(allocation) {
  *allocation=n;
  fresh=reinterpret_cast<Entry_307f30*>(allocation+1);
  for(int i=0;i<n;++i) { fresh[i].a=0; fresh[i].b=0; fresh[i].resource=0; fresh[i].c=0; fresh[i].d=0; }
 }
 entries=fresh;
 ((owners::Buffer_3048a0 *)&flags)->FUN_003048a0(count);
 for(int i=0;i<count;++i) {
  if(flags.size>=flags.capacity) ((owners::Buffer_3048a0 *)&flags)->FUN_003048a0(flags.capacity*2);
  int next=flags.size+1;
  flags.size=next;
  flags.data[next-1]=1;
 }
}


// 0x00308020 FUN_00308020 (27 B): matches/0x00308020.cpp
// sym: ??0CollisionObjectLoader@fn_fa930a40@@QAE@XZ
CollisionObjectLoader::CollisionObjectLoader() {
    a = 0;
    b = 0x7010000;
    c = 0;
    d = 0;
    v = ((hulk_intptr)DAT_00431c90);
}

} // namespace fn_fa930a40

// 0x00308040 physics::CollisionObjectLoader::vfunc_2 (31 B): matches/0x00308040.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00308040@@UAEPAV123@E@Z
namespace fn_00308040 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_308040 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_308040 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00308040

namespace fn_fa930a40 {

// 0x00308060 FUN_00308060 (27 B): matches/0x00308060.cpp
// sym: ??0WorldCollisionObjectLoader@fn_fa930a40@@QAE@XZ
WorldCollisionObjectLoader::WorldCollisionObjectLoader() {
    a = 0;
    b = 0x07010025;
    c = 0;
    d = 0;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_00431cac;
}

} // namespace fn_fa930a40

// 0x00308080 physics::WorldCollisionObjectLoader::vfunc_2 (31 B): matches/0x00308080.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00308080@@UAEPAV123@E@Z
namespace fn_00308080 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_308080 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_308080 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00308080

namespace fn_fa930a40 {

// 0x003080a0 FUN_003080a0 (785 B): equivalent/0x003080a0.cpp
// sym: ?FUN_003080a0@fn_fa930a40@@YAPAUNode@1@PAUReader@1@@Z @6ac40485a546 @w3f53e394ad60
// STATUS: equivalent (tools/equiv.py level 3: 1853 inputs, branch coverage 30/31, incomplete)
// FUN_003080a0 @ 0x003080a0
Node* __cdecl FUN_003080a0(Reader* r)
{
    Frame_3080a0 f;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.u8.a), (hulk_intptr)1, 4, (hulk_intptr)1));
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.b), (hulk_intptr)1, 4, (hulk_intptr)1));
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.c), (hulk_intptr)1, 4, (hulk_intptr)1));
    Node* obj = 0;
    r->FUN_00266a30();
    int type = r->FUN_00266c30();
    switch (type) {
    case 0x07010002: {
        ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.u4.d), (hulk_intptr)1, 4, (hulk_intptr)1));
        FUN_00307810(r, &f.v[0]);
        void* mem = FUN_0008d690((int)sizeof(CollisionSphere_3080a0));
        if (mem == 0) {
            obj = 0;
            break;
        }
        obj = ((CollisionSphere_3080a0*)mem)->FUN_002efe50(&f.v[0], f.u4.d);
        break;
    }
    case 0x07010003: {
        ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.r1), (hulk_intptr)1, 4, (hulk_intptr)1));
        ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.scratch), (hulk_intptr)1, 4, (hulk_intptr)1));
        f.u4.flag = r->FUN_00201750() != 0;
        FUN_00307810(r, &f.v[3]);
        FUN_00307810(r, &f.v[5]);
        void* mem = FUN_0008d690((int)sizeof(CollisionCylinder_3080a0));
        if (mem == 0) {
            obj = 0;
            break;
        }
        obj = ((CollisionCylinder_3080a0*)mem)->FUN_002f3070(&f.v[3], &f.v[5], f.scratch, f.r1, f.u4.word);
        break;
    }
    case 0x07010004: {
        ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.scratch), (hulk_intptr)1, 4, (hulk_intptr)1));
        f.tri[0] = f.scratch;
        ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.scratch), (hulk_intptr)1, 4, (hulk_intptr)1));
        f.tri[1] = f.scratch;
        ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.scratch), (hulk_intptr)1, 4, (hulk_intptr)1));
        f.tri[2] = f.scratch;
        FUN_00307810(r, &f.v[4]);
        FUN_00307810(r, &f.v[2]);
        FUN_00307810(r, &f.v[1]);
        FUN_00307810(r, &f.v[7]);
        void* mem = FUN_0008d690((int)sizeof(CollisionOBB_3080a0));
        if (mem == 0) {
            obj = 0;
            break;
        }
        obj = ((CollisionOBB_3080a0*)mem)->FUN_002fbed0(&f.v[4], f.tri, &f.v[2], &f.v[1], &f.v[7]);
        break;
    }
    case 0x07010005: {
        FUN_00307810(r, &f.v[8]);
        FUN_00307810(r, &f.v[6]);
        void* mem = FUN_0008d690((int)sizeof(CollisionWall_3080a0));
        if (mem == 0) {
            obj = 0;
            break;
        }
        obj = ((CollisionWall_3080a0*)mem)->FUN_0030e630(&f.v[8], &f.v[6]);
        break;
    }
    case 0x07010006: {
        void* mem = FUN_0008d690((int)sizeof(CollisionAABB_3080a0));
        if (mem != 0)
            obj = ((CollisionAABB_3080a0*)mem)->FUN_00312900();
        else
            obj = 0;
        ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.scratch), (hulk_intptr)1, 4, (hulk_intptr)1));
        break;
    }
    case 0x0701000a:
        obj = FUN_003078a0(r);
        break;
    default:
        break;
    }
    r->FUN_00266be0();
    obj->FUN_00306600(f.u8.a);
    int count = f.c;
    obj->f0c = f.b;
    if (count > 0) {
        void* mem = FUN_0008d690(0x10);
        Vec_3080a0* vec = (Vec_3080a0*)mem;
        f.u8.vec = vec;
        if (mem != 0) {
            vec->a = 0;
            vec->b = 0;
            vec->c = 0;
        } else {
            vec = 0;
        }
        obj->children = vec;
        ((owners::Buffer_2ede00 *)vec)->FUN_002ede00(count);
        while (count > 0) {
            r->FUN_00266a30();
            Node* child = FUN_003080a0(r);
            r->FUN_00266be0();
            obj->FUN_00306930(child);
            count--;
        }
    }
    return obj;
}


// 0x003083e0 FUN_003083e0 (34 B): matches/0x003083e0.cpp
// sym: ?add@Container_3083e0@fn_fa930a40@@QAEPAUItem_3083e0@2@XZ
Item_3083e0* Container_3083e0::add() {
    if (count >= capacity)
        grow_00304a10(capacity * 2);
    ++count;
    return (Item_3083e0*)((char*)items + count * 8 - 8);
}

} // namespace fn_fa930a40

// 0x00308410 physics::CollisionObjectLoader::vfunc_5 (1157 B): equivalent/0x00308410.cpp
// sym: ?vfunc_5@CollisionObjectLoader@physics@@UAEXPAX00H@Z @d414aa8a756c @w850f295c6f83
// STATUS: equivalent (tools/equiv.py level 3: 233 inputs, branch coverage 42/47, incomplete)
// physics::CollisionObjectLoader::vfunc_5 @ 0x00308410
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void physics::CollisionObjectLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr unused) { CollisionObject_308410 ** out = (CollisionObject_308410 **)__p0; NameKey_308410 * outId = (NameKey_308410 *)__p1; Reader_308410 * r = (Reader_308410 *)__p2;

    Frame_308410 f;
    void *mem = thunk_FUN_0008d690((int)sizeof(CollisionObject_308410));
    CollisionObject_308410 *obj = 0;
    if (mem)
        obj = ((CollisionObject_308410 *)mem)->FUN_00304ed0();

    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1));
    unsigned int l1 = f.len;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.name1), (hulk_intptr)l1, 1, (hulk_intptr)1));
    f.name1[l1] = 0;
    f.savedName = (NameKey_308410 *)&obj->name;
    ((owners::Target_27b040 *)&(obj->name))->FUN_0027b040((hulk_uintptr)(f.name1));

    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.tmp), (hulk_intptr)1, 4, (hulk_intptr)1));
    obj->f78 = f.tmp;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1));
    unsigned int l2 = f.len;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.name2), (hulk_intptr)l2, 1, (hulk_intptr)1));
    f.name2[l2] = 0;
    ((owners::Target_27b040 *)&(obj->name2))->FUN_0027b040((hulk_uintptr)(f.name2));

    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.tmp), (hulk_intptr)1, 4, (hulk_intptr)1));
    obj->f24 = f.tmp;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.tmp), (hulk_intptr)1, 4, (hulk_intptr)1));
    if (f.tmp > 0)
        obj->sub.FUN_00307f30(f.tmp);

    if (r->FUN_002669f0()) {
        f.tmp = 0;
        do {
            r->FUN_00266a30();
            int id = r->FUN_00266c30();
            switch (id) {
            case 0x7010001:
                obj->FUN_00304b40(FUN_003080a0(r));
                break;
            case 0x7010020:
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v1), (hulk_intptr)1, 4, (hulk_intptr)1));
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v2), (hulk_intptr)1, 4, (hulk_intptr)1));
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.s1), (hulk_intptr)1, 2, (hulk_intptr)1));
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.s2), (hulk_intptr)1, 2, (hulk_intptr)1));
                obj->FUN_00305190(f.v1, f.v2, f.s1 != 0, f.s2 != 0);
                break;
            case 0x7010021:
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.n), (hulk_intptr)1, 4, (hulk_intptr)1));
                if (f.n > 0 && r->FUN_002669f0()) {
                    do {
                        r->FUN_00266a30();
                        if (r->FUN_00266c30() == 0x7010022) {
                            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1));
                            unsigned int l3 = f.len;
                            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.name3), (hulk_intptr)l3, 1, (hulk_intptr)1));
                            f.name3[l3] = 0;
                            HashList *list = (HashList *)((char *)obj->lists + f.tmp);
                            if (list->count >= list->cap)
                                list->FUN_00304a10(list->cap * 2);
                            list->count++;
                            unsigned __int64 *slot = &list->data[list->count - 1];
                            *slot = FUN_0027b020(f.name3);
                        }
                        r->FUN_00266be0();
                    } while (r->FUN_002669f0());
                }
                f.tmp += 0x10;
                break;
            case 0x7010023: {
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.sD), (hulk_intptr)1, 2, (hulk_intptr)1));
                obj->b50 = f.sD != 0;
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v3), (hulk_intptr)1, 4, (hulk_intptr)1));
                obj->f54 = f.v3;
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.s3), (hulk_intptr)1, 2, (hulk_intptr)1));
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.s4), (hulk_intptr)1, 2, (hulk_intptr)1));
                bool b4 = f.s4 != 0;
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.s5), (hulk_intptr)1, 2, (hulk_intptr)1));
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.s6), (hulk_intptr)1, 2, (hulk_intptr)1));
                f.flag5 = f.s5 != 0;
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.i1), (hulk_intptr)1, 4, (hulk_intptr)1));
                f.flag6 = f.s6 != 0;
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.i2), (hulk_intptr)1, 4, (hulk_intptr)1));
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.i3), (hulk_intptr)1, 4, (hulk_intptr)1));
                int m = f.s3 != 0 ? 0xf : 0xb;
                if (!b4)
                    m -= 2;
                if (!f.flag5)
                    m -= 8;
                if (!f.flag6)
                    m -= 1;
                obj->f6c = m;
                break;
            }
            default:
                break;
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }

    unsigned __int64 key = FUN_0027b020(f.name2);
    ((owners::C_304740 *)obj)->FUN_00304740((hulk_intptr)(FUN_002f2750((unsigned int)key, (unsigned int)(key >> 32))));
    if (obj->b50) {
        obj->f20->FUN_00306300();
        obj->b68 = 0;
        obj->b69 = 0;
    }
    *out = obj;
    outId->lo = f.savedName->lo;
    outId->hi = f.savedName->hi;
}


// 0x003088d0 physics::WorldCollisionObjectLoader::vfunc_5 (260 B): equivalent/0x003088d0.cpp
// sym: ?vfunc_5@WorldCollisionObjectLoader@physics@@UAEXPAX00H@Z @fde41f86d74e @wf57a285184a2
// STATUS: equivalent (tools/equiv.py level 3: 177 inputs, branch coverage 12/12)
// physics::WorldCollisionObjectLoader::vfunc_5 @ 0x003088d0
void physics::WorldCollisionObjectLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { Obj_3088d0 ** out = (Obj_3088d0 **)__p0; Name_3088d0 * name = (Name_3088d0 *)__p1; Stream_3088d0 * stream = (Stream_3088d0 *)__p2; unsigned int unused = (unsigned int)__p3;

 void* mem=FUN_00263ea0(0x18);
 Obj_3088d0* obj=mem?((Obj_3088d0*)mem)->FUN_002fe1d0():0;
 unsigned char length;
 char text[256]; unsigned value;
 stream->reader->FUN_002647e0(&length,1,1,1);
 unsigned n=length;
 stream->reader->FUN_002647e0(text,n,1,1);
 text[n]=0;
 obj->name.FUN_0027b040(text);
 stream->reader->FUN_002647e0(&value,1,4,1);
 while(stream->FUN_002669f0()) {
 stream->FUN_00266a30();
 if(stream->FUN_00266c30()==0x7010001) {
 Ref_3088d0* ref=FUN_003080a0(stream);
 if(ref) ref->addRef();
 if(obj->ref) obj->ref->release();
 obj->ref=ref;
 }
 stream->FUN_00266be0();
 }
 *out=obj;
 name->a=obj->name.a;
 name->b=obj->name.b;
}

