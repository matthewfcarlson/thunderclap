// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000c8200..0x000c96e0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff187fa7 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff187fa7 {} using namespace fn_ff187fa7;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff187fa7 {
struct Vector { float x,y,z; };
struct Key_c8550 { unsigned a,b; };
struct Position_c8550 { void FUN_00059a50(Vector* out); };
struct Found_c8550 { char pad[16]; Position_c8550* position; };
struct Lookup_c8550 { Found_c8550* FUN_00024280(unsigned a,unsigned b); };
struct Manager_c8550 { bool FUN_001dd7b0(Key_c8550* key); bool FUN_001dd5d0(Key_c8550* key, Vector* out); int FUN_001e3410(Key_c8550* key); };
} // namespace fn_ff187fa7
struct World { char pad0[12]; Manager_c8550* manager; char pad1[16]; Lookup_c8550* lookup; };
namespace fn_ff187fa7 {
struct Entry_c8550 { unsigned unused; Vector position; char pad[24]; Key_c8550 key; int type; char tail[12]; };
struct Object { char pad[0x258]; Entry_c8550 entries[1]; bool FUN_000c8550(unsigned index,Vector* out); };
class Obj_c8710 {
  public:
    virtual void A();
    virtual void B();
};
extern void* hulk_at_0040a1f4[];
class Ref_c87a0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct T1 {
    char c;
    void Fini_0027af50();
};
class Entity_c87a0 {
  public:
    void* vptr;
    void Fin_0027afd0();
};
class CHudMap_c87a0 : public Entity_c87a0 {
  public:
    char pad4[0xc];
    Ref_c87a0* m10;
    Ref_c87a0* m14;
    Ref_c87a0* m18;
    Ref_c87a0* m1c;
    char pad20[0x22c - 0x20];
    Ref_c87a0* m22c[10];
    ~CHudMap_c87a0() throw();
};
struct Slot { int id; char pad[0x38]; unsigned char active; char tail[3]; };
struct Manager { char pad[0x258]; Slot slots[128]; void FUN_000c8ef0(int index); };
struct Entry { int id; int a; int b; int c; char padding[48]; };
struct Holder { char padding[0x258]; Entry entries[128]; void FUN_000c9090(int index, int a, int b, int c); };
struct Entry_c90d0 { // 0x40 bytes
    int id;    // +0x00, -1 = unused
    char pad04[0x3d - 4];
    unsigned char value; // +0x3d
    char pad3e[0x40 - 0x3e];
};
class Thing_c90d0 {
  public:
    Entry_c90d0* GetEntry(int index) {
        if (index >= 0 && index < 0x80 && entries[index].id != -1)
            return &entries[index];
        return 0;
    }
    void Set(int index, unsigned char value);

    char pad[0x258];
    Entry_c90d0 entries[0x80]; // +0x258
};
struct Handle_c9100 {
    unsigned int data[2];
    Handle_c9100* FUN_0027af00();
    void FUN_0027af70(Handle_c9100* other);
    void FUN_0027af50();
};
struct Entry_c9100 {
    int id;
    int values[8];
    int reserved24;
    Handle_c9100 handle;
    int state;
    int reserved34;
    int count;
    unsigned char active;
    char padding[3];
};
struct Manager_c9100 {
    char padding0[0x20];
    unsigned char active;
    char padding21[0x237];
    Entry_c9100 entries[128];
    void FUN_000c84e0(int index);
    void FUN_000c9100(int index);
};
struct Triple_c93e0 {
    int a, b, c;
};
struct Key {
    int a, b, c;
    ~Key() throw();
    int FUN_0027b0e0(int index) throw();
};
class Host_c93e0 {
public:
    int FUN_000c8200(int a1, int handle, Triple_c93e0 t1, Triple_c93e0 t2, Key key) throw();
    int FUN_000c93e0(int a1, int index, Triple_c93e0 t1, Triple_c93e0 t2, Key key) throw();
};
struct Surface_c9460 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual int width(); virtual int height();
};
struct Holder_c9460 { char pad[16]; Surface_c9460* surface; };
struct Point_c9460 { float x,y; };
struct Mapper_c9460 {
 char pad0[16]; Holder_c9460* holder; char pad1[44]; float sx,sy,ox,oy;
 Point_c9460* FUN_000c9460(Point_c9460* output, float x, float unused, float y);
};

} // namespace fn_ff187fa7

// 0x000c8410 FUN_000c8410 (56 B): equivalent/0x000c8410.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_000c8410@Object@fn_000c8410@@QAEXHHHH@Z @ba2477ca5dab @w99e5a64f61ce
namespace fn_000c8410 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_000c8410 @ 0x000c8410
struct Entry { int active; char pad[20]; int x; int y; int z; char tail[20]; }; struct Object { char pad[0x9d * 0x38]; Entry entries[32]; void FUN_000c8410(int index, int x, int y, int z); }; void Object::FUN_000c8410(int index, int x, int y, int z) { if (index >= 0 && index < 32 && entries[index].active != 0) { entries[index].x = x; entries[index].y = y; entries[index].z = z; } }
} // namespace fn_000c8410


// 0x000c8450 FUN_000c8450 (56 B): equivalent/0x000c8450.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_000c8450@Manager@fn_000c8450@@QAEXHHHH@Z @f52039f29bdc @w364a5a549eae
namespace fn_000c8450 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_000c8450 @ 0x000c8450
struct Entry { int active; char pad[0x20]; int x; int y; int z; char tail[8]; }; struct Manager { char pad[0x9d * 0x38]; Entry entries[32]; void FUN_000c8450(int index, int x, int y, int z); }; void Manager::FUN_000c8450(int index, int x, int y, int z) { if (index >= 0 && index < 32) { Entry *entry = &entries[index]; if (entry->active && entry) { entry->x = x; entry->y = y; entry->z = z; } } }
} // namespace fn_000c8450


// 0x000c8490 FUN_000c8490 (69 B): equivalent/0x000c8490.cpp [wrapped: conflict: DAT_004dd700]
// sym: ?FUN_000c8490@Owner@fn_000c8490@@QAEXH@Z @e31bad33eab9 @wb3c4b8c38fcd
namespace fn_000c8490 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_000c8490 @ 0x000c8490
struct Entry { int active; char pad[0x2c]; int handle; char rest[4]; }; struct Owner { char pad[0x2258]; Entry entries[32]; void FUN_000c8490(int index); }; struct Manager { void FUN_001e5bc0(int); }; struct Context { char pad[12]; Manager *manager; }; 
#define DAT_004dd700 (*(Context * *)&::DAT_004dd700)
 void Owner::FUN_000c8490(int index) { if (index >= 0 && index < 32) { Entry *entry = &entries[index]; if (entry->active && entry) { DAT_004dd700->manager->FUN_001e5bc0(entry->handle); entry->handle = -1; entry->active = 0; } } }
} // namespace fn_000c8490
#undef DAT_004dd700


// 0x000c84e0 FUN_000c84e0 (85 B): equivalent/0x000c84e0.cpp [wrapped: conflict: DAT_004dd700]
// sym: ?FUN_000c84e0@Owner@fn_000c84e0@@QAEXH@Z @ab7e08ca77e4 @w473abc19b983
namespace fn_000c84e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 9/12, incomplete)
// FUN_000c84e0 @ 0x000c84e0
struct Entry { int active; char pad[0x2c]; int handle; int key; }; struct Backend { void FUN_001e5bc0(int); }; struct Manager { char pad[12]; Backend* backend; }; 
#define DAT_004dd700 (*(Manager* *)&::DAT_004dd700)
 struct Owner { char pad[0x2258]; Entry entries[32]; void FUN_000c84e0(int key); }; void Owner::FUN_000c84e0(int key) { for (int i = 0; i < 32; ++i) { Entry& entry = entries[i]; if (entry.active && entry.key == key) { DAT_004dd700->backend->FUN_001e5bc0(entry.handle); entry.handle = -1; entry.active = 0; } } }
} // namespace fn_000c84e0
#undef DAT_004dd700

namespace fn_ff187fa7 {

// 0x000c8540 FUN_000c8540 (6 B): matches/0x000c8540.cpp
// sym: _FUN_000c8540
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_000c8540(void* /*this, unused: callers pass it (unb4)*/) {
    return &DAT_0049fbf4;
}


// 0x000c8550 FUN_000c8550 (211 B): equivalent/0x000c8550.cpp
// sym: ?FUN_000c8550@Object@fn_ff187fa7@@QAE_NIPAUVector@2@@Z @f60ace864c81 @w1908937b8d31
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000c8550 @ 0x000c8550
bool Object::FUN_000c8550(unsigned index,Vector* out) {
 Entry_c8550& e=entries[index];
 if(e.type==2) { out->x=e.position.x; out->y=e.position.y; out->z=e.position.z; return true; }
 if(e.type==0) { Found_c8550* f=DAT_004dd700->lookup->FUN_00024280(e.key.a,e.key.b); if(!f)return false; f->position->FUN_00059a50(out); return true; }
 if(e.type==1) { Manager_c8550* m=DAT_004dd700->manager; Key_c8550* k=&e.key; Vector temp; if(!m->FUN_001dd7b0(k))return false; if(!m->FUN_001dd5d0(k,&temp))return false; if(m->FUN_001e3410(k)<=0)return false; out->x=temp.x; out->y=temp.y; out->z=temp.z; return true; }
 return false;
}

} // namespace fn_ff187fa7

// 0x000c8630 FUN_000c8630 (207 B): equivalent/0x000c8630.cpp [wrapped: conflict: Object; World]
// sym: ?FUN_000c8630@Object@fn_000c8630@@QAE_NHPAUVec_c8630@2@@Z @281b69771e68 @wa70b9352ef26
namespace fn_000c8630 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000c8630 @ 0x000c8630
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec_c8630 { float x,y,z; };
struct Key_c8630 { unsigned int a,b; };
struct ResultWorker { void FUN_00059a50(Vec_c8630* out); };
struct Result_c8630 { char pad[16]; ResultWorker* worker; };
struct Lookup_c8630 { Result_c8630* FUN_00024280(unsigned int a,unsigned int b); };
struct Store { bool FUN_001dd7b0(Key_c8630* key); bool FUN_001dd5d0(Key_c8630* key,Vec_c8630* out); int FUN_001e3410(Key_c8630* key); };
struct World { char pad[12]; Store* store; char pad2[16]; Lookup_c8630* lookup; };
struct Entry_c8630 { unsigned int unused; Vec_c8630 value; Key_c8630 key; char pad[32]; };
struct Object { char pad[0x2258]; Entry_c8630 entries[1]; bool FUN_000c8630(int index,Vec_c8630* out); };
bool Object::FUN_000c8630(int index,Vec_c8630* out) {
 Entry_c8630* e=&entries[index];
 Key_c8630* key=&e->key;
 if (!(key->a|key->b)) { *out=e->value; return true; }
 Result_c8630* r=DAT_004dd700->lookup->FUN_00024280(key->a,key->b);
 if (r) { r->worker->FUN_00059a50(out); return true; }
 Store* store=DAT_004dd700->store;
 Vec_c8630 v;
 if (store->FUN_001dd7b0(key) && store->FUN_001dd5d0(key,&v) && store->FUN_001e3410(key)>0) { *out=v; return true; }
 return false;
}
} // namespace fn_000c8630
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ff187fa7 {

// 0x000c8710 FUN_000c8710 (36 B): matches/0x000c8710.cpp
// sym: ?Set@fn_ff187fa7@@YAXPAPAVObj_c8710@1@PAV21@@Z
// Same code shape as 0x000187a0 (propagated; names are from that function)
void Set(Obj_c8710** p, Obj_c8710* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}


// 0x000c87a0 FUN_000c87a0 (168 B): matches/0x000c87a0.cpp
// sym: ??1CHudMap_c87a0@fn_ff187fa7@@QAE@XZ
CHudMap_c87a0::~CHudMap_c87a0() throw() {
    *(void* volatile*)&vptr = hulk_at_0040a1f4;
    Ref_c87a0* t10 = *(Ref_c87a0* volatile*)&m10;
    if (t10) {
        t10->Release();
        m10 = 0;
    }
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    if (m18) {
        m18->Release();
        m18 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Ref_c87a0** p = m22c;
    int n = 10;
    do {
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
        p++;
    } while (--n);
    char* q = (char*)this + 0x2968;
    n = 32;
    do {
        q -= 0x38;
        ((T1*)q)->Fini_0027af50();
    } while (--n);
    q = (char*)this + 0x2280;
    n = 128;
    do {
        q -= 0x40;
        ((T1*)q)->Fini_0027af50();
    } while (--n);
    Fin_0027afd0();
}

} // namespace fn_ff187fa7

// 0x000c8850 FUN_000c8850 (1693 B): equivalent/0x000c8850.cpp [wrapped: macros]
// sym: ?FUN_000c8850@Marker@fn_000c8850@@QAEXXZ @9a7808a48a7e @w3ce4cf4d4e38
namespace fn_000c8850 {
// STATUS: equivalent (tools/equiv.py level 3: 2139 inputs, branch coverage 28/28)
// FUN_000c8850 @ 0x000c8850
// FUN_000c8850 @ 0x000c8850
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double atan2(double y, double x);
#endif


struct V3 {
    float x, y, z;
    void FUN_0022d260(const struct Mat4 *m);
    void FUN_0022d180();
};

struct Mat4 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bab0(float angle);
    void FUN_0022cd50(const V3 *v);
};

struct V2 { float x, y; };

struct Cam {
    V3 *FUN_001c39c0();
};
Cam *FUN_001c3d90();

struct VBuf {
    char pad0[8];
    V3 *pos;
    char padc[4];
    unsigned int *color;
    V2 *uv;
    void FUN_0008ef00();
};

struct Gfx {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
    virtual VBuf *v30(void *a, int b, int c, int d, int e);
    virtual void v31(VBuf *vb);
};

struct Dev {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
    virtual void v17(int a, Mat4 *m);
};

struct Render {
    Dev *dev;
    void FUN_00293d00(const V3 *v);
    void FUN_00293bf0(float a);
    void FUN_00293da0(float a, float b, float c);
    void FUN_00293c20(float a);
};

struct Handler {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
};

struct Sink {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(int a, int b);
};

struct SinkHolder {
    char pad0[0x10];
    Sink *sink;
};

struct Node {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual SinkHolder *v7();
};

struct NodeOwner {
    Node *node;
};

struct Item {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
    char pad4[0x44];
    Node **f48;
};

struct Shot {
    int id;                 // 0
    char pad4[0xc];
    float x;                // 0x10
    float y;                // 0x14
    V3 w;                   // 0x18
    char pad24[0x34 - 0x24];
    int a34;
    char pad38[0x3d - 0x38];
    char flag3d;
    char pad3e[2];
};

struct Src {
    char pad0[0x10];
    void *f10;
};


#define EMIT(PV, UU, UV) { V3 *pp_ = vb->pos; *pp_ = (PV); unsigned int *cp_ = vb->color; *cp_ = color; V2 *up_ = vb->uv; up_->x = (UU); up_->y = (UV); vb->FUN_0008ef00(); }

class Marker {
public:
    char pad0[0x10];
    void *f10;
    Src *f14;
    Handler *f18;
    Handler *f1c;
    char pad20[0x38 - 0x20];
    float f38;
    float f3c;
    char pad40[0x50 - 0x40];
    float ring[28];
    V3 pts[28];
    float f210;
    float f214;
    char pad218[0x228 - 0x218];
    int f228;
    Item *tbl[11];
    Shot shots[0x80];

    void FUN_000c8850();
};

struct Frame {
    V3 base;                // x0,y0,z0
    V3 p;
    V3 q;
};

void Marker::FUN_000c8850()
{
    if (f10 == 0)
        return;
    V3 *dir = FUN_001c3d90()->FUN_001c39c0();
    V3 d0 = *dir;
    float ang = (float)atan2(d0.z, d0.x) + 4.712389f;
    Mat4 m1;
    m1.FUN_0022b980();
    m1.FUN_0022bab0(ang);
    unsigned int color = ((unsigned int)f228 << 24) | 0xffffff;
    VBuf *vb = DAT_0052c2a8->v30(f14->f10, 0, 0x2021, 0x54, 0);

    volatile float tenth = DAT_004de600 * DAT_0049fbd8;
    V3 base;
    volatile float hx = DAT_004de600 * -0.5f;
    volatile float hy = DAT_004de604 * -0.5f;
    base.x = hx + tenth;
    base.y = hy + DAT_004de604 * DAT_0049fbdc;
    base.z = 0.0f;
    V3 p, q;
    p.z = 0.0f;
    q.z = 0.0f;

    int k = 1;
    for (int n = 0x1c; n != 0; n--, k++) {
        int a = (k + 6) % 0x1c;
        int b = (k + 7) % 0x1c;
        int c = k % 0x1c;
        p.x = ring[a] * f210;
        p.y = ring[k - 1] * f210;
        q.x = ring[b] * f210;
        q.y = ring[c] * f210;
        p.z = 0.0f;
        q.z = 0.0f;
        p.FUN_0022d260(&m1);
        q.FUN_0022d260(&m1);
        p.x = p.x + f38;
        p.y = p.y + f3c;
        float pu = p.x;
        float pv = p.y;
        q.x = q.x + f38;
        float qu = q.x;
        q.y = q.y + f3c;
        float qv = q.y;

        const V3 *r = &pts[c];
        float tx = DAT_0049fbe0 * r->x;
        float ty = DAT_0049fbe0 * r->y;
        volatile float tzs = DAT_0049fbe0 * r->z;
        V3 t;
        t.x = tx + base.x;
        t.y = ty + base.y;
        t.z = tzs + base.z;

        const V3 *s = &pts[k - 1];
        float ux = DAT_0049fbe0 * s->x;
        float uy = DAT_0049fbe0 * s->y;
        volatile float uzs = DAT_0049fbe0 * s->z;
        V3 u;
        u.x = ux + base.x;
        u.y = uy + base.y;
        u.z = uzs + base.z;

        EMIT(base, f38, f3c);
        EMIT(t, qu, qv);
        EMIT(u, pu, pv);
    }

    DAT_0052c2a8->v31(vb);
    (*(Render**)&DAT_0052c2ac)->dev->v15(0);
    (*(Render**)&DAT_0052c2ac)->FUN_00293d00(&base);
    (*(Render**)&DAT_0052c2ac)->FUN_00293bf0(-1.5707964f);
    (*(Render**)&DAT_0052c2ac)->FUN_00293da0(DAT_0049fbe0, DAT_0049fbe0, DAT_0049fbe0);
    if (f18 != 0)
        f18->v8(0, 0);
    if (f1c != 0) {
        (*(Render**)&DAT_0052c2ac)->FUN_00293c20(ang);
        f1c->v8(0, 0);
    }
    (*(Render**)&DAT_0052c2ac)->dev->v16(0);

    float rot = 6.2831855f - ang;
    V3 d;
    d.x = 0.0f;
    d.y = 0.0f;
    d.z = 0.0f;
    for (const int *kp = ((int*)&DAT_0049fbf4); *kp != -1; kp++) {
        for (int i = 0; i < 0x80; i++) {
            Shot *sh = &shots[i];
            if (sh->id != *kp)
                continue;
            float inv = 1.0f / f210;
            d.x = (sh->x - f38) * inv;
            d.y = (sh->y - f3c) * inv;
            if (!(d.y * d.y + d.x * d.x + d.z * d.z >= 1.0f)) {
            } else {
                if (sh->flag3d != 0)
                    continue;
                d.FUN_0022d180();
            }
            Mat4 m2;
            m2.FUN_0022b980();
            m2.FUN_0022bab0(rot);
            d.FUN_0022d260(&m2);
            float g = f214;
            volatile float gy = g * d.y;
            volatile float gz = d.z * g;
            V3 w;
            // y and z are scaled and rounded to float before base is added; base.z is a stack word
            // (it stays 0, so adding it turns a -0 product into +0).
            volatile float gyk = gy * DAT_0049fbe0;
            volatile float gzk = gz * DAT_0049fbe0;
            volatile float baseZ = base.z;
            float wx = d.x * g * DAT_0049fbe0 + base.x;
            float wy = gyk + base.y;
            float wz = gzk + baseZ;
            w.x = wx;
            w.y = wy;
            w.z = wz;
            Mat4 m3;
            m3.FUN_0022b980();
            if (sh->id == 0) {
                V3 v = sh->w;
                v.FUN_0022d260(&m2);
                m3.FUN_0022cd50(&v);
            }
            Item *it = tbl[sh->id];
            if (it == 0)
                continue;
            (*(Render**)&DAT_0052c2ac)->dev->v15(0);
            (*(Render**)&DAT_0052c2ac)->FUN_00293d00(&w);
            (*(Render**)&DAT_0052c2ac)->dev->v17(0, &m3);
            (*(Render**)&DAT_0052c2ac)->FUN_00293da0(1.5f, 1.5f, 1.5f);
            int val = sh->a34;
            (*tbl[sh->id]->f48)->v7()->sink->v7(0x45444146, val);
            tbl[sh->id]->v8(0, 0);
            (*(Render**)&DAT_0052c2ac)->dev->v16(0);
        }
    }
}
} // namespace fn_000c8850
#undef EMIT
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ff187fa7 {

// 0x000c8ef0 FUN_000c8ef0 (91 B): equivalent/0x000c8ef0.cpp
// sym: ?FUN_000c8ef0@Manager@fn_ff187fa7@@QAEXH@Z @1005a2c75661 @w6343b333c65b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 11/12, incomplete)
// FUN_000c8ef0 @ 0x000c8ef0
void Manager::FUN_000c8ef0(int index) { if (index < 0 || index >= 128) return; Slot *slot = &slots[index]; if (slot->id == -1 || !slot) return; for (int i = 0; i < 128; ++i) { if (slots[i].active == 1) { slots[i].active = 0; slot->active = 1; return; } } slot->active = 1; }

} // namespace fn_ff187fa7

// 0x000c8f50 FUN_000c8f50 (313 B): equivalent/0x000c8f50.cpp
// sym: ?FUN_000c8f50@Obj_c8f50@owners@@QAEXM@Z @e433242efd89 @w8403ffaa62df
// STATUS: equivalent (tools/equiv.py level 3: 20037 inputs, branch coverage 17/18, incomplete)
// FUN_000c8f50 @ 0x000c8f50
void owners::Obj_c8f50::FUN_000c8f50(float target)
{
    hulk_freg d = target - f218;
    hulk_freg s;
    if (d < 0.0f)
        s = -1.0f;
    else if (d > 0.0f)
        s = 1.0f;
    else
        s = 0.0f;

    hulk_freg v = f218 * f218 * 0.0125f;
    hulk_freg c;
    if (!(v >= 0.0f))
        c = 0.0f;
    else if (v > 0.02f)
        c = 0.02f;
    else
        c = v;

    hulk_freg pos = c * s + f218; // the stored f218 is rounded; the uses below take the register
    f218 = pos;
    f210 = 0.12f * pos;
    float a = pos - 0.6f;
    if (a < 0.0f) a = -a;
    if (a <= 0.02f && s == -1.0f) {
        c224 = 1;
        c2959 = 0;
        return;
    }
    float b = pos - 1.25f;
    if (b < 0.0f) b = -b;
    if (b <= 0.02f && s == 1.0f) {
        c224 = 1;
        c2959 = 0;
    }
}

namespace fn_ff187fa7 {

// 0x000c9090 FUN_000c9090 (58 B): equivalent/0x000c9090.cpp
// sym: ?FUN_000c9090@Holder@fn_ff187fa7@@QAEXHHHH@Z @a87e8f4e2dbc @wd85fe0ba6160
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_000c9090 @ 0x000c9090
void Holder::FUN_000c9090(int index, int a, int b, int c) { if (index >= 0 && index < 128 && entries[index].id != -1) { entries[index].a = a; entries[index].b = b; entries[index].c = c; } }


// 0x000c90d0 FUN_000c90d0 (44 B): matches/0x000c90d0.cpp
// sym: ?Set@Thing_c90d0@fn_ff187fa7@@QAEXHE@Z
void Thing_c90d0::Set(int index, unsigned char value) {
    Entry_c90d0* e = GetEntry(index);
    if (e)
        e->value = value;
}


// 0x000c9100 FUN_000c9100 (177 B): equivalent/0x000c9100.cpp
// sym: ?FUN_000c9100@Manager_c9100@fn_ff187fa7@@QAEXH@Z @4bc708402675 @w789c4007eb14
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/10, incomplete)
// FUN_000c9100 @ 0x000c9100
void Manager_c9100::FUN_000c9100(int index) {
    if (index < 0 || index >= 128) return;
    Entry_c9100* entry = &entries[index];
    if (entry->id == -1 || !entry) return;
    if (entry->active == 1) active = 0;
    entry->id = -1;
    Handle_c9100 temporary;
    Handle_c9100* result = temporary.FUN_0027af00();
    entry->handle.FUN_0027af70(result);
    temporary.FUN_0027af50();
    entry->state = -1;
    for (int i = 0; i < 8; ++i) entry->values[i] = 0;
    entry->count = 0;
    entry->active = 0;
    FUN_000c84e0(index);
}

} // namespace fn_ff187fa7

// 0x000c91c0 FUN_000c91c0 (77 B): matches/0x000c91c0.cpp [wrapped: merged class would differ: Obj: field entries: Field(+0x2258 Entry [32] entries) vs Field(+0x2258 Entry [32] entries)]
// sym: ?Clear@Obj@fn_000c91c0@@QAEXXZ
namespace fn_000c91c0 {
struct Manager {
    void Release_001e5bc0(int);
};
struct Global {
    char pad[12];
    Manager* manager;
};
extern Global* hulk_at_004dd700;
struct Entry {
    int value;
    char pad[44];
    int handle;
    char tail[4];
};
class Obj {
    char pad[0x2258];
    Entry entries[32];

  public:
    void Clear();
};
void Obj::Clear() {
    for (int i = 0; i < 32; i++) {
        Entry* e = &entries[i];
        if (i >= 0 && i < 32 && e->value && (hulk_uintptr)this + 0x2258 + i * 56 != 0) {
            hulk_at_004dd700->manager->Release_001e5bc0(e->handle);
            e->handle = -1;
            e->value = 0;
        }
    }
}
} // namespace fn_000c91c0


// 0x000c9210 FUN_000c9210 (210 B): equivalent/0x000c9210.cpp [wrapped: conflict: Object]
// sym: ?FUN_000c9210@Object@fn_000c9210@@QAEHHHUVec_c9210@2@0@Z @d2e6768eb8ad @wd9abc65ad4a8
namespace fn_000c9210 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000c9210 @ 0x000c9210
struct Vec_c9210 { float x,y,z; };
struct Source_c9210 { int id; Vec_c9210 position; char pad[24]; char data[24]; };
struct Result_c9210 { int active; char pad[48]; int sourceIndex; };
struct Object {
 char pad[0x258]; Source_c9210 sources[128]; Result_c9210 results[32];
 int FUN_000c8200(int value, void* data, Vec_c9210 position, Vec_c9210 a, Vec_c9210 b);
 int FUN_000c9210(int index, int value, Vec_c9210 a, Vec_c9210 b);
};
int Object::FUN_000c9210(int index, int value, Vec_c9210 a, Vec_c9210 b) {
 Source_c9210* source = 0;
 if (index >= 0 && index < 128 && sources[index].id != -1) source = &sources[index];
 if (!source) return -1;
 int result = FUN_000c8200(value, source->data, source->position, a, b);
 if (result != -1) {
  Result_c9210* entry = 0;
  if (result >= 0 && result < 32 && results[result].active != 0) entry = &results[result];
  entry->sourceIndex = index;
 }
 return result;
}
} // namespace fn_000c9210


// 0x000c92f0 FUN_000c92f0 (80 B): equivalent/0x000c92f0.cpp [wrapped: conflict: Object]
// sym: ?FUN_000c92f0@Object@fn_000c92f0@@QAEXHHHHH@Z @092e7527c772 @wa205e95f0f07
namespace fn_000c92f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_000c92f0 @ 0x000c92f0
struct Entry { int active; char gap[0x14]; int x, y, z; char rest[0x14]; }; struct Object { char padding[0x2258]; Entry entries[32]; void FUN_000c92f0(int unused, int index, int x, int y, int z); }; void Object::FUN_000c92f0(int unused, int index, int x, int y, int z) { if (index >= 0 && index < 32) { Entry* entry = &entries[index]; if (entry->active && entry) { entry->x = x; entry->y = y; entry->z = z; } } }
} // namespace fn_000c92f0


// 0x000c9340 FUN_000c9340 (80 B): equivalent/0x000c9340.cpp [wrapped: conflict: Entry; Object]
// sym: ?FUN_000c9340@Object@fn_000c9340@@QAEXHHHHH@Z @f7759cf0b715 @w9393e9ac9835
namespace fn_000c9340 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_000c9340 @ 0x000c9340
struct Entry { int active; char padding[0x20]; int x; int y; int z; char rest[0x8]; }; struct Object { char padding[0x2258]; Entry entries[32]; void FUN_000c9340(int unused, int index, int x, int y, int z); }; void Object::FUN_000c9340(int unused, int index, int x, int y, int z) { if (index >= 0 && index < 32) { Entry *entry = &entries[index]; if (entry->active) { entry->x = x; entry->y = y; entry->z = z; } } }
} // namespace fn_000c9340


// 0x000c9390 FUN_000c9390 (69 B): equivalent/0x000c9390.cpp [wrapped: conflict: DAT_004dd700; Manager]
// sym: ?FUN_000c9390@Manager@fn_000c9390@@QAEXHH@Z @a519597696c4 @wa111a14df2ee
namespace fn_000c9390 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_000c9390 @ 0x000c9390
struct Entry { int active; char reserved[0x2c]; int handle; char tail[4]; };
struct Worker { void FUN_001e5bc0(int); };
struct Service { char pad[12]; Worker *worker; };

#define DAT_004dd700 (*(Service * *)&::DAT_004dd700)

struct Manager { char pad[0x9d * 0x38]; Entry entries[32]; void FUN_000c9390(int unused, int index); };
void Manager::FUN_000c9390(int unused, int index) {
    if (index >= 0 && index < 32) {
        Entry *entry = &entries[index];
        if (entry->active && entry) {
            DAT_004dd700->worker->FUN_001e5bc0(entry->handle);
            entry->handle = -1;
            entry->active = 0;
        }
    }
}
} // namespace fn_000c9390
#undef DAT_004dd700

namespace fn_ff187fa7 {

// 0x000c93e0 FUN_000c93e0 (122 B): matches/0x000c93e0.cpp
// sym: ?FUN_000c93e0@Host_c93e0@fn_ff187fa7@@QAEHHHUTriple_c93e0@2@0UKey@2@@Z
// FUN_000c93e0 @ 0x000c93e0
// equiv-map: ??1Key@@QAE@XZ = 0x0027af50
int Host_c93e0::FUN_000c93e0(int a1, int index, Triple_c93e0 t1, Triple_c93e0 t2, Key key) throw() {
    return FUN_000c8200(a1, key.FUN_0027b0e0(index), t1, t2, key);
}


// 0x000c9460 FUN_000c9460 (235 B): equivalent/0x000c9460.cpp
// sym: ?FUN_000c9460@Mapper_c9460@fn_ff187fa7@@QAEPAUPoint_c9460@2@PAU32@MMM@Z @7a2820bc0884 @wc36a58dee279
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000c9460 @ 0x000c9460
Point_c9460* Mapper_c9460::FUN_000c9460(Point_c9460* output, float x, float unused, float y) {
 int w = holder->surface->width();
 float u = (x * sx + ox) / w;
 int h = holder->surface->height();
 float v = 1.0f - (y * sy + oy) / h;
 if (!(u >= 0.0f && u <= 1.0f)) u = u > 1.0f ? 1.0f : 0.0f;
 if (!(v >= 0.0f && v <= 1.0f)) v = v > 1.0f ? 1.0f : 0.0f;
 output->x=u; output->y=v;
 return output;
}

} // namespace fn_ff187fa7
