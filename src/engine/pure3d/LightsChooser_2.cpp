// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0029f600..0x002a0720 (kind game, layer engine, confidence medium), dominant class pure3d::LightsChooser
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f5bc90fd {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f5bc90fd {} using namespace fn_f5bc90fd;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f5bc90fd {
extern "C" int __cdecl FUN_0008d690(int);
struct CacheManager_nv_29f7c0 {
    int Init(int, int);
};
class Thing_29f800 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    char pad[0x10];
    int field;
};
class Item_29f800 {
  public:
    Thing_29f800* owner;
    void Apply(int, int);
};
class Manager_29f800 {
    char pad[0x24];

  public:
    int count;
    void Run(hulk_intptr);
};
struct Inner_29f840 {
    int pad[5];
    int mCount; // 0x14
};
struct Entry_29f840 {
    Inner_29f840* mInner;
    void Set(int idx, Item* it); // FUN_0029eda0
};
struct Src_29f840 {
    char pad[0x10];
    int mLimit;      // 0x10
    unsigned mCount; // 0x14
    Item** mItems;   // 0x18
};
struct Grow_29f840 { int Grow(int n); };
struct Owner_29f840 {
    char pad[0x24];
    int mTotal;
     // FUN_0029c450
    void Run(Src_29f840* s);
};
struct Rec_29f8c0 {
    int field_00;
    int color;
    char pad[0x18 - 8];
    unsigned flags;
    int field_1c;
};
struct ItemList_29f8c0 {
    char pad0[0x10];
    int limit;
    int count;
    void **items;

    void FUN_002a0fc0(int index, int mode);
};
struct Slots_29f8c0 {
    ItemList_29f8c0 *list;
    Rec_29f8c0 *recs;

    void FUN_0029eda0(int index, void *item);
};
struct Owner_29f8c0;
struct Owner_29f8c0 {
    char pad[0x24];
    int removed;

    void FUN_0029f8c0(void *key);
};
struct Container_29fa30 {
    char pad[0x14];
    int count;
    void FUN_002a0fc0(int index, int value);
};
struct Entry_29fa30 {
    unsigned int value;
    unsigned int color;
    char pad[16];
    unsigned int a;
    unsigned int b;
};
struct Group_29fa30 {
    Container_29fa30* container;
    Entry_29fa30* entries;
};
struct Vec_29faf0 { float x,y,z; };
struct Pool_29faf0 { void* FUN_0029f280(); };
struct Item_29faf0 { char pad0[0x18]; unsigned int value18; char pad1[0x18]; unsigned int color; void FUN_0029e7f0(void*,void*,unsigned int); };
struct Object {
  public:
    char _m_pad_0[0x10];
    unsigned int color;
    char _m_pad_14[0x4];
    unsigned int value18;
    char _m_pad_1c[0x8];
    union { unsigned int generation; unsigned int value24; };
    char _m_pad_28[0x4];
    Group_29fa30* groups[5];
    char _m_pad_40[0x4];
    Pool_29faf0* pool;
    void FUN_0029fa30();
    bool FUN_0029e5c0(void*,Item_29faf0*);
    void FUN_0029ce40(Vec_29faf0*,void*);
    void FUN_0029df90(void*,Vec_29faf0*,void*);
    void target(void* arg, Item_29faf0* item);
};
struct Region_29fc00 {
    bool FUN_0022d2b0(void *outer, int key);
};
struct Entry_29fc00 {
    char pad00[0x1c];
    int owner;
    int key;
    char pad24[4];
    char box[8];
    char pad30[8];
    char flagged;
    char pad39[3];
    int counter;
    int interval;
    void FUN_0029ea40(int mode);
};
class Tracker_29fc00 {
public:
    char pad00[0x24];
    int owner;
    hulk_freg FUN_0029dcc0(Region_29fc00 *region, int mode);
    bool FUN_0029fc00(hulk_intptr mode, Region_29fc00 *region, Entry_29fc00 *entry);
};
struct Y_29fca0 {
    bool Chk(void* a, int b);
};
struct N_29fca0 {
    char p[0x1c];
    int m1c;
    int m20;
    char p2[4];
    char m28[0x14];
    int m3c;
    int m40;
    void Do(int a);
};
struct X_29fca0 {
    char p[0x24];
    int m24;
    bool Fn(int a, Y_29fca0* y, N_29fca0* n);
};
struct Obj_29fd20 {
    void Method(int v, void* self);
};
extern int vt1_29fd40;
} // namespace fn_f5bc90fd
void operator delete(void*) throw();
namespace fn_f5bc90fd {
void Free(void*) throw();
class Ref_29fd40 {
  public:
    virtual void f0() throw();
    virtual void Release() throw();
};
struct S_29fd40 {
    Ref_29fd40* r;
    void* buf;
    ~S_29fd40() throw() {
        r->Release();
        Free(buf);
    }
};
struct S2_29fd40 {
    Ref_29fd40* r0;
    Ref_29fd40* r4;
    Ref_29fd40* r8;
    Ref_29fd40* rc;
    ~S2_29fd40() throw() {
        rc->Release();
        r8->Release();
        r4->Release();
        r0->Release();
    }
};
class Entity_29fd40 {
  public:
    void* vptr;
    ~Entity_29fd40() throw();
};
class LightsChooser_29fd40 : public Entity_29fd40 {
  public:
    void Fini() throw();
    char p[0x28];
    S_29fd40* s2c;
    S_29fd40* s30;
    S_29fd40* s34;
    S_29fd40* s38;
    S_29fd40* s3c;
    S_29fd40* s40;
    S2_29fd40* s44;
    void* a48;
    ~LightsChooser_29fd40() throw();
};
struct Manager_29ffd0 {
    int Make();
    int Finish(int, hulk_intptr);
};
struct Obj_29ffd0 {
    char pad0[0x10];
    int field10;
    char pad14[0x30];
    Manager_29ffd0* field44;
    void Stage(int, int, int);
    void Other(int, hulk_intptr);
    void target(int, hulk_intptr);
};
struct Item_29ffd0 {
    void Last();
};
class Worker_2a0020 {
  public:
    int get();
};
class Thing_2a0020 {
  public:
    char pad[0x44];
    Worker_2a0020* member;
    void f(int a, int b);
    void apply(int x, int a, int b);
};
struct Item {
    void FUN_002a0820(int v);
};
struct Elem {
    float v;
    char pad[0x1c];
};
struct Hdr {
    char pad0[0x10];
    int f10;
    int n;
    void **arr18;
};
struct Pair {
    Hdr *hdr;
    Elem *base;
};
struct A {
    char pad0[0x10];
    int f10;
    int m;
    Item **arr18;
    void FUN_002a0fc0(int idx, void *item);
};
struct B {
    char pad[4];
};
struct C {
    char pad0[0x18];
    int f18;
    char pad1c[0x34 - 0x1c];
    int f34;
    void FUN_0029e7f0(A *a, B *b, int v);
};
class Skin {
public:
    char pad0[0x10];
    int color;
    char pad14[0x24 - 0x14];
    int f24;
    char pad28[0x3c - 0x28];
    Pair *p3c;
    bool FUN_0029fc00(A *a, B *b, C *c);
    void FUN_0029e640(A *a);
    void FUN_0029e680(A *a);
    float FUN_0029d5d0(B *b, int z);
    void FUN_002a0050(A *a, B *b, C *c);
};
class Obj_2a0580 {
  public:
    int get();
    void last(int, void*);
};
class A_2a0580 {
    char pad[0x10];
    int field;
    char padx[0x30];
    Obj_2a0580* p;
    char pad2[0x100];

  public:
    void f(int, int);
    void mid(int, int, int);
};
struct Vec3_2a05c0 {
    float x, y, z;
};
class Other_2a05c0 {
public:
    char pad00[0x18];
    int field_18;
    void FUN_0029e7f0(void* a, void* b, int c);
};
class Track {
public:
    char pad00[0x18];
    int field_18;
    char pad1c[8];
    int field_24;
    char FUN_0029fca0(struct Obj_2a05c0* a, void* b, Other_2a05c0* c);
    void FUN_0029ce40(Vec3_2a05c0* out, void* b);
    void FUN_0029e320(struct Obj_2a05c0* a, Vec3_2a05c0* v, void* b);
    void FUN_0029ccb0(struct Obj_2a05c0* a, int d);
    void FUN_0029e640(struct Obj_2a05c0* a);
    void FUN_0029e680(struct Obj_2a05c0* a);
    void FUN_002a05c0(struct Obj_2a05c0* a, void* b, Other_2a05c0* c, int d);
};
struct Obj_2a05c0 {
    char pad00[0x14];
    int field_14;
};
struct H {
    int get();
};
struct C_2a0650 {
    char pad[0x44];
    H* h;
    void f(int a, int b, int c);
    void other(int, int, int, int);
};
struct Result_2a06d0 {
    char pad[0x18];
};
struct Finder_2a06d0 {
    char pad[0x28];
    Result_2a06d0* find(int, int);
};
struct Root_2a06d0 {
    char pad[0x28];
    Finder_2a06d0* finder;
};
struct Owner_2a06d0 {
    void act(Result_2a06d0*, int);
};

} // namespace fn_f5bc90fd

// 0x0029f600 FUN_0029f600 (433 B): equivalent/0x0029f600.cpp [wrapped: conflict: pure3d::Entity; pure3d::LightsChooser]
// sym: ??0LightsChooser@pure3d@fn_0029f600@@QAE@HH@Z
namespace fn_0029f600 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 20/20)
// FUN_0029f600 @ 0x0029f600

void *FUN_0008d690(unsigned int size);

struct Name_29f600 {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct Inner_29f600 {
    void FUN_002a1180(int arg);
};

struct Slots_29f600 {
    Inner_29f600 *first;
    char pad4[8];
    Slots_29f600 *FUN_0029ecb0(int capacity);
};

struct Lookup_29f600 {
    char pad0[0x18];
    Lookup_29f600 *FUN_0029ef40(int a, int b);
};

struct TreeNode_29f600 {
    TreeNode_29f600 *left;        // 0x00
    TreeNode_29f600 *parent;      // 0x04
    int key;               // 0x08
    char pad0c[0x20 - 0x0c];
    TreeNode_29f600 *head;        // 0x20
    int isHead;            // 0x24
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void e0();
    char pad4[4];
    Name_29f600 name;
    void FUN_0027b070();
    Entity() throw() { FUN_0027b070(); }
};

class LightsChooser : public Entity {
public:
    virtual void x1();
    virtual void x2();
    virtual void x3();
    int color;             // 0x10
    float weight;          // 0x14
    int f18;
    int maxA;              // 0x1c
    int maxB;              // 0x20
    int f24;
    char f28;
    Slots_29f600 *slots0;         // 0x2c
    Slots_29f600 *slots1;
    Slots_29f600 *slots2;
    Slots_29f600 *slots3;
    Slots_29f600 *slots4;
    Slots_29f600 *slots5;         // 0x40
    Lookup_29f600 *lookup;        // 0x44
    TreeNode_29f600 *tree;        // 0x48
    LightsChooser(int a, int b) throw();
};
}

pure3d::LightsChooser::LightsChooser(int a, int b) throw()
{
    color = DAT_004cf730;
    weight = 1.0f;
    f18 = 0;
    f24 = 0;
    f28 = 0;
    maxA = a > 0 ? a : 0;
    maxB = b > 0 ? b : 0;

    void *mem = FUN_0008d690(0xc);
    slots0 = mem ? ((Slots_29f600 *)mem)->FUN_0029ecb0(0x80) : 0;
    slots0->first->FUN_002a1180(0);

    mem = FUN_0008d690(0xc);
    slots1 = mem ? ((Slots_29f600 *)mem)->FUN_0029ecb0(0x80) : 0;
    slots1->first->FUN_002a1180(0);

    mem = FUN_0008d690(0xc);
    slots2 = mem ? ((Slots_29f600 *)mem)->FUN_0029ecb0(0x80) : 0;
    slots2->first->FUN_002a1180(0);

    mem = FUN_0008d690(0xc);
    slots3 = mem ? ((Slots_29f600 *)mem)->FUN_0029ecb0(0x80) : 0;
    slots3->first->FUN_002a1180(0);

    mem = FUN_0008d690(0xc);
    slots4 = mem ? ((Slots_29f600 *)mem)->FUN_0029ecb0(0x80) : 0;
    slots4->first->FUN_002a1180(0);

    mem = FUN_0008d690(0xc);
    slots5 = mem ? ((Slots_29f600 *)mem)->FUN_0029ecb0(maxA + 1) : 0;
    slots5->first->FUN_002a1180(0);

    mem = FUN_0008d690(0x18);
    lookup = mem ? ((Lookup_29f600 *)mem)->FUN_0029ef40(maxA, maxB) : 0;

    TreeNode_29f600 *node = (TreeNode_29f600 *)FUN_0008d690((int)sizeof(TreeNode_29f600));
    if (node != 0) {
        node->isHead = 1;
        node->parent = 0;
        node->key = DAT_004cf730;
        node->head = (TreeNode_29f600 *)&node->parent;
        node->left = (TreeNode_29f600 *)&node->parent;
        tree = node;
    } else {
        tree = 0;
    }
}
} // namespace fn_0029f600

namespace fn_f5bc90fd {

// 0x0029f7c0 FUN_0029f7c0 (54 B): matches/0x0029f7c0.cpp
// sym: _FUN_0029f7c0
extern "C" void FUN_0029f7c0() {
    if ((*(int*)&DAT_0052cba0) == 0) {
        hulk_intptr x = FUN_0008d690(0x3c);
        if (x != 0)
            (*(int*)&DAT_0052cba0) = ((CacheManager_nv_29f7c0*)(((pure3d::LightsChooser::CacheManager*)(((pure3d::LightsChooser::CacheManager*)x)))))->Init(4, 0x100);
        else
            (*(int*)&DAT_0052cba0) = 0;
    }
}


// 0x0029f800 FUN_0029f800 (59 B): matches/0x0029f800.cpp
// sym: ?Run@Manager_29f800@fn_f5bc90fd@@QAEXH@Z
void Manager_29f800::Run(hulk_intptr arg) {
    if (arg) {
        Item_29f800* p = ((Item_29f800 *)((owners::Object_29c450 *)this)->FUN_0029c450((void *)(hulk_uintptr)(int)arg));
        if (p) {
            int value = p->owner->field;
            ((owners::A_2a1180 *)(p->owner))->FUN_002a1180(value + 1);
            p->Apply(value, arg);
            ++count;
        }
    }
}


// 0x0029f840 FUN_0029f840 (122 B): matches/0x0029f840.cpp
// sym: ?Run@Owner_29f840@fn_f5bc90fd@@QAEXPAUSrc_29f840@2@@Z
void Owner_29f840::Run(Src_29f840* s) {
    unsigned n = s->mCount;
    unsigned i = 0;
    for (i = 0; i < n; i++) {
        if ((int)i >= s->mLimit)
            continue;
        Item* it = s->mItems[i];
        if (!it)
            continue;
        Entry_29f840* e = ((Entry_29f840 *)((owners::Object_29c450 *)this)->FUN_0029c450((Item *)it));
        if (!e)
            continue;
        int c = *(int*)((char*)e->mInner + 0x14);
        ((Grow_29f840*)e->mInner)->Grow(c + 1);
        e->Set(c, it);
        mTotal++;
    }
}


// 0x0029f8c0 FUN_0029f8c0 (302 B): equivalent/0x0029f8c0.cpp
// sym: ?FUN_0029f8c0@Owner_29f8c0@fn_f5bc90fd@@QAEXPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 16/16)
// FUN_0029f8c0 @ 0x0029f8c0
void Owner_29f8c0::FUN_0029f8c0(void *key)
{
    if (key == 0)
        return;

    Slots_29f8c0 *s = ((Slots_29f8c0 *)((owners::Object_29c450 *)this)->FUN_0029c450(key));

    for (int i = s->list->count - 1; i >= 0; i--) {
        ItemList_29f8c0 *l = s->list;
        void *item = (i < l->limit) ? l->items[i] : 0;
        if (item != key)
            continue;

        int last = l->count - 1;
        if (i == last) {
            l->FUN_002a0fc0(i, 0);
            s->recs[i].field_00 = 0;
            s->recs[i].color = DAT_004cf730;
            s->recs[i].field_1c = 0;
            s->recs[i].flags = 0;
        } else {
            void *lastItem = (last < l->limit) ? l->items[last] : 0;
            s->FUN_0029eda0(i, lastItem);
            if (s->recs[last].flags & 8)
                s->recs[i].flags |= 8;
            else
                s->recs[i].flags &= ~8u;
            s->list->FUN_002a0fc0(last, 0);
            s->recs[last].field_00 = 0;
            s->recs[last].color = DAT_004cf730;
            s->recs[last].field_1c = 0;
            s->recs[last].flags = 0;
        }
        ((owners::A_2a1180 *)(s->list))->FUN_002a1180(last);
        removed++;
    }
}


// 0x0029fa30 FUN_0029fa30 (188 B): matches/0x0029fa30.cpp
// sym: ?FUN_0029fa30@Object@fn_f5bc90fd@@QAEXXZ
void Object::FUN_0029fa30() {
    Group_29fa30* list[6];
    list[0] = groups[0];
    list[1] = groups[1];
    list[2] = groups[2];
    list[3] = groups[3];
    list[4] = groups[4];
    list[5] = 0;
    for (int j = 0; list[j]; ++j) {
        Group_29fa30* group = list[j];
        for (int i = group->container->count - 1; i >= 0; --i) {
            group->container->FUN_002a0fc0(i, 0);
            group->entries[i].value = 0;
            group->entries[i].color = (*(unsigned int*)&DAT_004cf730);
            group->entries[i].b = 0;
            group->entries[i].a = 0;
        }
        ((owners::A_2a1180 *)(group->container))->FUN_002a1180(0);
    }
    ++generation;
}


// 0x0029faf0 FUN_0029faf0 (267 B): equivalent/0x0029faf0.cpp
// sym: ?target@Object@fn_f5bc90fd@@QAEXPAXPAUItem_29faf0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 20058 inputs, branch coverage 17/20, incomplete)
// FUN_0029faf0 @ 0x0029faf0
void Object::target(void* arg, Item_29faf0* item) {
 if (FUN_0029e5c0(arg,item)) { color=item->color; return; }
 void* handle=pool->FUN_0029f280();
 Vec_29faf0 v;
 FUN_0029ce40(&v,arg);
 FUN_0029df90(handle,&v,arg);
 int b=(int)(__int64)v.z;
 int g=(int)(__int64)v.y;
 int r=(int)(__int64)v.x;
 if(b<0)b=0; else if(b>255)b=255;
 if(g<0)g=0; else if(g>255)g=255;
 if(r<0)r=0; else if(r>255)r=255;
 color=0xff000000u | ((unsigned int)(__int64)r<<16) | ((unsigned int)(__int64)g<<8) | b;
 item->value18=value18;
 item->FUN_0029e7f0(handle,arg,value24);
 item->color=color;
}


// 0x0029fc00 FUN_0029fc00 (160 B): equivalent/0x0029fc00.cpp
// sym: ?FUN_0029fc00@Tracker_29fc00@fn_f5bc90fd@@QAE_NHPAURegion_29fc00@2@PAUEntry_29fc00@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0029fc00 @ 0x0029fc00
// FUN_0029fc00 @ 0x0029fc00: advances one entry's countdown; when it expires, re-arms it and re-emits if still valid
bool Tracker_29fc00::FUN_0029fc00(hulk_intptr mode, Region_29fc00 *region, Entry_29fc00 *entry)
{
    if (entry == 0)
        return false;

    entry->counter = entry->counter - 1;
    if (entry->counter > 0) {
        entry->FUN_0029ea40(mode);
        return true;
    }

    entry->counter = entry->interval + entry->counter;
    if (region->FUN_0022d2b0(&entry->box, entry->key)) {
        if (owner == entry->owner) {
            if (entry->flagged) {
                float v = FUN_0029dcc0(region, 8);
                if (!(v <= 0.0f))
                    return false;
            }
            entry->FUN_0029ea40(mode);
            return true;
        }
    }
    return false;
}


// 0x0029fca0 FUN_0029fca0 (113 B): matches/0x0029fca0.cpp
// sym: ?Fn@X_29fca0@fn_f5bc90fd@@QAE_NHPAUY_29fca0@2@PAUN_29fca0@2@@Z
bool X_29fca0::Fn(int a, Y_29fca0* y, N_29fca0* n) {
    bool r = false;
    if (n) {
        int c = --n->m3c;
        if (c > 0) {
            n->Do(a);
            r = true;
        } else {
            n->m3c = n->m40 + c;
            if (y->Chk(n->m28, n->m20) && m24 == n->m1c) {
                n->Do(a);
                r = true;
            }
        }
    }
    return r;
}

} // namespace fn_f5bc90fd

// 0x0029fd20 FUN_0029fd20 (20 B): matches/0x0029fd20.cpp
// sym: ?FUN_0029fd20@Caller_29fd20@owners@@QAEXH@Z
// data: gObject_29fd20 = DAT_0052cba0
void owners::Caller_29fd20::FUN_0029fd20(hulk_intptr value) {
    (*(Obj_29fd20**)&DAT_0052cba0)->Method(((int)value), this);
}

namespace fn_f5bc90fd {

// 0x0029fd40 FUN_0029fd40 (275 B): matches/0x0029fd40.cpp
// sym: ??1LightsChooser_29fd40@fn_f5bc90fd@@QAE@XZ
LightsChooser_29fd40::~LightsChooser_29fd40() throw() {
    vptr = &vt1_29fd40;
    Fini();
    if (s2c)
        delete s2c;
    if (s30)
        delete s30;
    if (s34)
        delete s34;
    if (s38)
        delete s38;
    if (s3c)
        delete s3c;
    if (s40)
        delete s40;
    if (s44)
        delete s44;
    operator delete(a48);
}

} // namespace fn_f5bc90fd

// 0x0029fe60 FUN_0029fe60 (365 B): equivalent/0x0029fe60.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_0029fe60@Brush@fn_0029fe60@@QAEXPAUItem_29fe60@2@PAXPAVTarget_29fe60@2@@Z
namespace fn_0029fe60 {
// STATUS: equivalent (tools/equiv.py level 3: 20060 inputs, branch coverage 23/26, incomplete)
// FUN_0029fe60 @ 0x0029fe60

struct Vec3_29fe60 { float x, y, z; };

struct Item_29fe60 {
    char pad0[0x14];
    int link;
};

class Target_29fe60 {
public:
    char pad0[0x18];
    int f18;
    char pad1c[0x34 - 0x1c];
    unsigned int color;
    void FUN_0029e7f0(Item_29fe60 *item, void *ctx, int arg);
};

class Brush {
public:
    char pad0[0x10];
    unsigned int color;
    char pad14[4];
    int f18;
    char pad1c[0x24 - 0x1c];
    int f24;
    bool FUN_0029fc00(Item_29fe60 *item, void *ctx, Target_29fe60 *target);
    void FUN_0029e640(Item_29fe60 *item);
    void FUN_0029e680(Item_29fe60 *item);
    void FUN_0029ce40(void *out, void *ctx);
    void FUN_0029df90(Item_29fe60 *item, void *out, void *ctx);
    void FUN_0029fe60(Item_29fe60 *item, void *ctx, Target_29fe60 *target);
};

static int Clamp255(int v)
{
    if (v < 0) return 0;
    if (v > 0xff) return 0xff;
    return v;
}

void Brush::FUN_0029fe60(Item_29fe60 *item, void *ctx, Target_29fe60 *target)
{
    if (item->link == 0) {
        color = (*(unsigned int*)&DAT_004cf730);
        if (target != 0) {
            target->f18 = 0;
            target->FUN_0029e7f0(item, ctx, f24);
            target->color = (*(unsigned int*)&DAT_004cf730);
        }
        return;
    }
    if (FUN_0029fc00(item, ctx, target)) {
        FUN_0029e640(item);
        color = target->color;
        FUN_0029e680(item);
        return;
    }
    Vec3_29fe60 v;
    FUN_0029ce40(&v, ctx);
    FUN_0029df90(item, &v, ctx);
    int b = (int)(__int64)v.z;
    int g = (int)(__int64)v.y;
    int r = (int)(__int64)v.x;
    b = Clamp255(b);
    g = Clamp255(g);
    r = Clamp255(r);
    color = 0xff000000 | (r << 16) | (g << 8) | b;
    if (target != 0) {
        target->f18 = f18;
        target->FUN_0029e7f0(item, ctx, f24);
        target->color = color;
    }
    FUN_0029e640(item);
    FUN_0029e680(item);
}
} // namespace fn_0029fe60

namespace fn_f5bc90fd {

// 0x0029ffd0 FUN_0029ffd0 (80 B): matches/0x0029ffd0.cpp
// sym: ?target@Obj_29ffd0@fn_f5bc90fd@@QAEXHH@Z
void Obj_29ffd0::target(int a, hulk_intptr b) {
    if (!b) {
        int v = field44->Make();
        Stage(v, a, 0);
        field44->Finish(v, (hulk_intptr)&field10);
    } else {
        Other(a, b);
        ((Item_29ffd0*)b)->Last();
    }
}


// 0x002a0020 FUN_002a0020 (33 B): matches/0x002a0020.cpp
// sym: ?f@Thing_2a0020@fn_f5bc90fd@@QAEXHH@Z
void Thing_2a0020::f(int a, int b) {
    int x = member->get();
    apply(x, a, b);
}


// 0x002a0050 FUN_002a0050 (1320 B): equivalent/0x002a0050.cpp
// sym: ?FUN_002a0050@Skin@fn_f5bc90fd@@QAEXPAUA@2@PAUB@2@PAUC@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 2535 inputs, branch coverage 87/90, incomplete)
// FUN_002a0050 @ 0x002a0050
void Skin::FUN_002a0050(A *a, B *b, C *c)
{
    int n = p3c->hdr->n;
    int m = a->m;
    color = DAT_004cf730;
    if (m == 0) {
        if (c == 0)
            return;
        c->f18 = m;
        c->FUN_0029e7f0(a, b, f24);
        c->f34 = DAT_004cf730;
        return;
    }
    if (FUN_0029fc00(a, b, c)) {
        FUN_0029e640(a);
        FUN_0029e680(a);
        return;
    }

    int idx[4];
    if (n <= 4) {
        int i = 0;
        if (m > 0) {
            int lim = m;
            do {
                if (i < n) {
                    Hdr *h = p3c->hdr;
                    if (i < h->f10)
                        a->FUN_002a0fc0(i, h->arr18[i]);
                    else
                        a->FUN_002a0fc0(i, 0);
                } else {
                    int start = i;
                    if (i < m) {
                        do {
                            a->FUN_002a0fc0(i, 0);
                            i++;
                        } while (i < m);
                    }
                    ((owners::A_2a1180 *)a)->FUN_002a1180(start);
                    lim = m;
                }
                i++;
            } while (i < lim);
        }
    } else {
        FUN_0029d5d0(b, 0);
        float S0 = 0.0f, S1 = 0.0f, N = 0.0f, M = 0.0f;
        int iS0 = -1, iS1 = -1, iN = -1, iM = -1;
        Elem *base = p3c->base;
        for (int i = 0; i < n; i++) {
            float x = base[i].v;
            if (!(x <= S0)) {
                M = S0;
                iM = iS0;
                if (!(x <= S1)) {
                    float S1old = S1;
                    iS0 = iS1;
                    if (!(x <= N)) {
                        S1 = N;
                        iS1 = iN;
                        N = x;
                        iN = i;
                    } else {
                        S1 = x;
                        iS1 = i;
                    }
                    S0 = S1old;
                } else {
                    S0 = x;
                    iS0 = i;
                }
            } else {
                if (x > M) {
                    M = x;
                    iM = i;
                }
            }
        }
        idx[0] = iN;
        idx[1] = iS1;
        idx[2] = iS0;
        idx[3] = iM;
        int i = 0;
        if (m > 0) {
            do {
                int e = idx[i];
                if (e != -1) {
                    Hdr *h = p3c->hdr;
                    if (e < h->f10)
                        a->FUN_002a0fc0(e, h->arr18[e]);
                    else
                        a->FUN_002a0fc0(e, 0);
                } else {
                    int start = i + 1;
                    for (; i < m; i++)
                        a->FUN_002a0fc0(i, 0);
                    ((owners::A_2a1180 *)a)->FUN_002a1180(start);
                }
                i++;
            } while (i < m);
        }
    }

    if (c) {
        c->f18 = n;
        c->FUN_0029e7f0(a, b, f24);
        c->f34 = color;
    }
    int cnt = a->m;
    for (int i = 0; i < cnt; i = i + 1) {
        if (i < a->f10) {
            Item *it = a->arr18[i];
            if (it)
                it->FUN_002a0820(1);
        }
        cnt = a->m;
    }
}


// 0x002a0580 FUN_002a0580 (50 B): matches/0x002a0580.cpp
// sym: ?f@A_2a0580@fn_f5bc90fd@@QAEXHH@Z
void A_2a0580::f(int x, int y) {
    int t = p->get();
    mid(t, x, y);
    p->last(t, &field);
}


// 0x002a05c0 FUN_002a05c0 (129 B): equivalent/0x002a05c0.cpp
// sym: ?FUN_002a05c0@Track@fn_f5bc90fd@@QAEXPAUObj_2a05c0@2@PAXPAVOther_2a05c0@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002a05c0 @ 0x002a05c0
// 0x002a05c0: add a sample to the track, rebuilding keys unless it is already covered
void Track::FUN_002a05c0(Obj_2a05c0* a, void* b, Other_2a05c0* c, int d)
{
    Vec3_2a05c0 v;
    if (a->field_14 == 0)
        return;
    if (!FUN_0029fca0(a, b, c)) {
        FUN_0029ce40(&v, b);
        FUN_0029e320(a, &v, b);
        FUN_0029ccb0(a, d);
        if (c != 0) {
            c->field_18 = field_18;
            c->FUN_0029e7f0(a, b, field_24);
        }
    }
    FUN_0029e640(a);
    FUN_0029e680(a);
}


// 0x002a0650 FUN_002a0650 (38 B): matches/0x002a0650.cpp
// sym: ?f@C_2a0650@fn_f5bc90fd@@QAEXHHH@Z
void C_2a0650::f(int a, int b, int c) {
    int x = h->get();
    other(x, a, b, c);
}

} // namespace fn_f5bc90fd

// 0x002a06b0 pure3d::LightsChooser::vfunc_2 (30 B): matches/0x002a06b0.cpp
// sym: ??_GLightsChooser@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::LightsChooser::~LightsChooser() {}

namespace fn_f5bc90fd {

// 0x002a06d0 FUN_002a06d0 (53 B): matches/0x002a06d0.cpp
// sym: ?target@fn_f5bc90fd@@YGXH@Z
// data: gCompare = DAT_0052c2b4, gRoot_2a06d0 = DAT_0052cba0
void __stdcall target(int arg) {
    Root_2a06d0* p = (*(Root_2a06d0**)&DAT_0052cba0);
    Finder_2a06d0* f = p->finder;
    Result_2a06d0* r = f->find(arg, 0);
    if (r) {
        int* q = (*(int**)&DAT_0052c2b4);
        if (*(int*)((char*)r + 0x14) == *q) {
            Owner_2a06d0* o = *(Owner_2a06d0**)((char*)r + 0x10);
            o->act(r, *(int*)((char*)r + 0xc));
        }
    }
}

} // namespace fn_f5bc90fd
