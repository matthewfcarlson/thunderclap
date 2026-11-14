// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001acb90..0x001aed70 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f54565b1 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f54565b1 {} using namespace fn_f54565b1;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_f54565b1 {
struct Vec3_1acdd0 { float x, y, z; };
struct Mesh_1acdd0 { Vec3_1acdd0 *FUN_001b56a0(int face, int corner); };
struct V3_1acfa0 {
    float x, y, z;
    V3_1acfa0* FUN_001acfa0(const V3_1acfa0* p, const V3_1acfa0* q);
};
struct Vec3_1ad2b0 {
    float x, y, z;
};
struct Accessor {
    Vec3_1ad2b0* FUN_001b56a0(Source* src, int index);
};
class Sum3 {
public:
    Source* source;         // 0x00
    int f04;
    float x;                // 0x08
    float y;                // 0x0c
    float z;                // 0x10
    void FUN_001ad2b0(Accessor** acc);
};
struct Target_1ad4b0 {
    Target_1ad4b0* Run(int);
};
struct Target_1ad4c0 {
    Target_1ad4c0* Run(int);
};
struct A {
    unsigned int x;
};
struct B {
    char pad[16];
    unsigned int x;
};
extern "C" int __cdecl thunk_FUN_00267090(int);
char __cdecl thunk_FUN_00267090(void* p);
struct Rec_1ad5c0 {
    int a, b, c, d, e;
};
struct Node {
    Rec_1ad5c0 r;
    Node* next;
};
struct Buffer_1ad5c0 {
    Rec_1ad5c0* begin;
    Rec_1ad5c0* cur;
    Rec_1ad5c0* end;
};
extern "C" void* Alloc(hulk_uintptr);
typedef unsigned int u32_1ad6d0;
struct Obj_1ad6d0 {
    u32_1ad6d0 a;
};
extern "C" u32_1ad6d0 __fastcall FUN_00230ea0(Obj_1ad6d0*);
struct Vec3_1ad730 { float x, y, z; };
struct Skeleton {
    Vec3_1ad730* FUN_001b56a0(int a, int axis);
};
union FloatBits_1ad730 {
    float f;
    unsigned u;
};
struct Record_1ad7d0 { int children[3]; unsigned char levels[3]; unsigned char level; char pad[6]; unsigned short flags; };
struct Store { Record_1ad7d0* FUN_001b5800(int); bool FUN_001b65f0(int,int); };
struct Context { Store* store; unsigned int minLevel; unsigned int maxLevel; unsigned int minFlags; };
bool __cdecl FUN_001ad730(int, Context*);
struct Iterator_1ad7d0 { int parent; int current; int index; int accept; void advance(Context*); };
struct Vec3_1ae1f0 { float x,y,z; };
struct Item_1ae1f0 { Vec3_1ae1f0* FUN_001b5a20(Vec3_1ae1f0* result, unsigned int index); };
struct Manager_1ae1f0 { void FUN_001b6000(Vec3_1ae1f0* position, Item_1ae1f0** item, unsigned int* count); };
} // namespace fn_f54565b1
struct World { char pad[16]; Manager_1ae1f0* manager; };
namespace fn_f54565b1 {
struct Query_1ae1f0 { Item_1ae1f0* item; unsigned int type; unsigned int size; unsigned int option; unsigned int FUN_001adeb0(unsigned int argument, unsigned int count, int a, int b); };
struct Record { int value; char rest[16]; };
struct Query { char padding[12]; int identity; int value; };
struct Range { char padding[4]; Record* begin; Record* end; char padding2[8]; int identity; };
struct Vec3_1ae450 {
    float x, y, z;
};
struct Plane_1ae450 {
    float x, y, d;
    void FUN_001acfa0(const Vec3_1ae450 *a, const Vec3_1ae450 *b);
};
struct Box_1ae450 {
    Vec3_1ae450 mn;
    Vec3_1ae450 mx;
};
struct Seg_1ae450 {
    Vec3_1ae450 a, b;
    void FUN_0022fe40(Box_1ae450 *out);
};
struct Elem_1ae450 {
    int f0;
    int f4;
    Vec3_1ae450 v;
};
struct Owner_1ae450 {
    void FUN_001b5760(int a);
    Vec3_1ae450 *FUN_001b56a0(int a, int b);
};
struct Cont {
    char pad00[4];
    Elem_1ae450 *begin;
    Elem_1ae450 *end;
    char pad0c[8];
    Owner_1ae450 *owner;
};
union Arg1 {
    Cont *c;
    float t;
};
union Arg3 {
    char flag;
    Elem_1ae450 *cur;
    unsigned int bits;
    unsigned char flags[4];
};
struct Inner_1aea70 {
    char p[0x2c];
    float key;
};
struct Ref_1aea70 {
    Inner_1aea70* in;
    int tag;
};
struct A_1aea70 {
    char p[0x10];
    Ref_1aea70 r;
};
struct Item { char pad[0x2c]; float value; };
struct Entry {
  public:
    Item *item;
    char _m_pad_4[0xc];
    unsigned int key;
};
struct Group { char pad[0x10]; Item *item; void *unused; };
extern void* DAT_0041d800[];
void* FUN_0008d6d0(int);
class CPathManager_1aec00 {
  public:
    void* vptr;
    int m4, m8, mc, m10;
    char m14;
    int* m18;
    int* m1c;
    int* m20;
    int* m24;
    CPathManager_1aec00();
};
struct Src_1aecb0 {
    int a;
    int b;
};
struct Obj_1aecb0 {
    char pad[0x10];
    int a;
    int b;
};
struct Out_1aecb0 {
    Obj_1aecb0* o;
    void* t;
};
extern void* __cdecl FUN_0008d6d0(unsigned int);
void FUN_001aeae0();
void FUN_001aea70();
class T_1aecb0 {
  public:
    void Reg_00230c30(Obj_1aecb0*, void (*)(), int);
    int Make_00230be0(void (*)(), Src_1aecb0*);
    void Run(Out_1aecb0* out, Src_1aecb0* s);
};

} // namespace fn_f54565b1

// 0x001acb90 FUN_001acb90 (89 B): matches/0x001acb90.cpp
// sym: ?FUN_001acb90@Box_1acb90@owners@@QAEEPBM@Z
unsigned char owners::Box_1acb90::FUN_001acb90(const float* p) {
    if (p[0] >= lo[0] && p[0] <= hi[0] && p[1] >= lo[1] && p[1] <= hi[1] && p[2] >= lo[2] && p[2] <= hi[2])
        return 1;
    return 0;
}

namespace fn_f54565b1 {

// 0x001acd80 FUN_001acd80 (1 B): matches/0x001acd80.cpp
// sym: ?FUN_001acd80@fn_f54565b1@@YAXPAX@Z
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001acd80(void* /*this, unused: callers pass it (unb4)*/) {}


// 0x001acdd0 FUN_001acdd0 (153 B): equivalent/0x001acdd0.cpp
// sym: _FUN_001acdd0 @5b245077bc05 @w3041c479b7f6
// STATUS: equivalent (tools/equiv.py level 3: 15856 inputs, branch coverage 0/0)
// FUN_001acdd0 @ 0x001acdd0
// FUN_001acdd0 @ 0x001acdd0
// Centroid of the three corners of a face.  The x sum is rounded to float
// before it is scaled, y stays unrounded, z rounds its first partial sum.
extern "C" Vec3_1acdd0 * __cdecl FUN_001acdd0(Vec3_1acdd0 *out, Mesh_1acdd0 *mesh, int face)
{
    Vec3_1acdd0 r;
    Vec3_1acdd0 *a = mesh->FUN_001b56a0(face, 0);
    Vec3_1acdd0 *b = mesh->FUN_001b56a0(face, 1);
    Vec3_1acdd0 *c = mesh->FUN_001b56a0(face, 2);
    volatile float *px = &r.x;
    volatile float z1 = b->z + a->z;
    *px = (b->x + a->x) + c->x;
    r.y = ((b->y + a->y) + c->y) * 0.33333334f;
    r.z = (z1 + c->z) * 0.33333334f;
    *px = *px * 0.33333334f;
    *out = r;
    return out;
}


// 0x001acfa0 FUN_001acfa0 (112 B): equivalent/0x001acfa0.cpp
// sym: ?FUN_001acfa0@V3_1acfa0@fn_f54565b1@@QAEPAU12@PBU12@0@Z @aebd2931239d @w3ce1bdf50203
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001acfa0 @ 0x001acfa0
// 2D perpendicular line through p and q (x, y), normalised, with offset z.
V3_1acfa0* V3_1acfa0::FUN_001acfa0(const V3_1acfa0* p, const V3_1acfa0* q)
{
    y = q->x - p->x;
    x = p->z - q->z;
    if (y * y + x * x > 1e-5f) {
        double inv = 1.0f / sqrt(y * y + x * x);
        volatile V3_1acfa0* self = this;
        x = inv * self->x;
        y = inv * self->y;
        z = -(p->x * self->x + p->z * self->y);
        return this;
    }
    x = 0;
    y = 0;
    z = 0;
    return this;
}


// 0x001ad2b0 FUN_001ad2b0 (125 B): equivalent/0x001ad2b0.cpp
// sym: ?FUN_001ad2b0@Sum3@fn_f54565b1@@QAEXPAPAUAccessor@2@@Z @ea28aa0a984f @w60d710b9aacb
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ad2b0 @ 0x001ad2b0
void Sum3::FUN_001ad2b0(Accessor** acc)
{
    Vec3_1ad2b0* a = (*acc)->FUN_001b56a0(source, 0);
    Vec3_1ad2b0* b = (*acc)->FUN_001b56a0(source, 1);
    Vec3_1ad2b0* c = (*acc)->FUN_001b56a0(source, 2);
    volatile float y0 = b->y + a->y;
    volatile float z0 = b->z + a->z;
    // every input is read before this is written: a, b and c may point into this
    float nx = (b->x + a->x) + c->x;
    float ny = y0 + c->y;
    float nz = z0 + c->z;
    z = nz;
    x = nx;
    y = ny;
}


// 0x001ad4b0 FUN_001ad4b0 (14 B): matches/0x001ad4b0.cpp
// sym: ?Run@Target_1ad4b0@fn_f54565b1@@QAEPAU12@H@Z
// Same code shape as 0x00066860 (propagated; names are from that function)
Target_1ad4b0* Target_1ad4b0::Run(int x) {
    ((owners::X_230b60 *)(((ThisCall_00230b60*)(this))))->FUN_00230b60();
    return this;
}


// 0x001ad4c0 FUN_001ad4c0 (14 B): matches/0x001ad4c0.cpp
// sym: ?Run@Target_1ad4c0@fn_f54565b1@@QAEPAU12@H@Z
// Same code shape as 0x00066860 (propagated; names are from that function)
Target_1ad4c0* Target_1ad4c0::Run(int x) {
    ((owners::X_230b60 *)(((ThisCall_00230b60*)(this))))->FUN_00230b60();
    return this;
}


// 0x001ad4d0 FUN_001ad4d0 (27 B): matches/0x001ad4d0.cpp
// sym: ?compare@fn_f54565b1@@YAHPBUEntry@1@0@Z
int __cdecl compare(const Entry* a, const Entry* b) {
    if (a->key < b->key)
        return -1;
    return a->key > b->key;
}


// 0x001ad4f0 FUN_001ad4f0 (26 B): matches/0x001ad4f0.cpp
// sym: ?FUN_001ad4f0@fn_f54565b1@@YAHPAUA@1@PAUB@1@@Z
int __cdecl FUN_001ad4f0(A* a, B* b) {
    unsigned int ax = a->x;
    unsigned int bx = b->x;
    if (bx > ax)
        return -1;
    return bx < ax;
}


// 0x001ad550 FUN_001ad550 (16 B): matches/0x001ad550.cpp
// sym: _FUN_001ad550
extern "C" bool __cdecl FUN_001ad550(int x) {
    thunk_FUN_00267090(x);
    return true;
}


// 0x001ad560 FUN_001ad560 (16 B): matches/0x001ad560.cpp
// sym: _FUN_001ad560
extern "C" char __cdecl FUN_001ad560(void* p) {
    thunk_FUN_00267090(p);
    return 1;
}


// 0x001ad5c0 FUN_001ad5c0 (188 B): matches/0x001ad5c0.cpp
// sym: _FUN_001ad5c0
extern "C" char FUN_001ad5c0(Buffer_1ad5c0* b, Node* n) {
    unsigned int count = 0;
    Node* p = n;
    while (p) {
        p = p->next;
        ++count;
    }
    if (n && count > 0x100)
        return 0;
    Rec_1ad5c0* old = b->begin;
    b->cur = old;
    if (b->end - old == 0) {
        Rec_1ad5c0* q = (Rec_1ad5c0*)Alloc(0x1400);
        b->begin = q;
        if (q) {
            b->cur = q;
            b->end = (Rec_1ad5c0*)((char*)q + 0x1400);
        } else {
            b->cur = 0;
            b->end = 0;
        }
    }
    Node* current = n;
    while (current) {
        Rec_1ad5c0* out = b->cur;
        if (out < b->end) {
            b->cur = out + 1;
            if (out) {
                Node* src = current;
                *out = src->r;
            }
        }
        current = current->next;
    }
    return 1;
}


// 0x001ad6d0 FUN_001ad6d0 (23 B): matches/0x001ad6d0.cpp
// sym: ?target@fn_f54565b1@@YIPAIPAUObj_1ad6d0@1@PAXPAI@Z
// Same code shape as 0x00066a50 (propagated; names are from that function)
u32_1ad6d0* __fastcall target(Obj_1ad6d0* self, void*, u32_1ad6d0* out) {
    u32_1ad6d0 v = FUN_00230ea0(self);
    out[0] = v;
    out[1] = (hulk_uintptr)self;
    return out;
}


// 0x001ad730 FUN_001ad730 (152 B): equivalent/0x001ad730.cpp
// sym: ?FUN_001ad730@fn_f54565b1@@YA_NHPAPAUSkeleton@1@@Z @f33a6ea01e7d @wea73c0e505f5
// STATUS: equivalent (tools/equiv.py level 3: 20011 inputs, branch coverage 8/8)
// FUN_001ad730 @ 0x001ad730
// True when the extent of the points along y is at most 0.7.
bool __cdecl FUN_001ad730(int a, Skeleton** skel)
{
    Skeleton* s = *skel;
    ((owners::Table_1b5760 *)s)->FUN_001b5760((unsigned int)a);
    hulk_freg hi = -1000000000000.0f;
    hulk_freg lo = 1000000000000.0f;
    for (int i = 0; i < 3; i++) {
        Vec3_1ad730* p = s->FUN_001b56a0(a, i);
        if (hi < p->y)
            hi = p->y;
        if (!(lo < p->y))
            lo = p->y;
    }
    FloatBits_1ad730 d;
    d.f = hi - lo;
    d.u &= 0x7fffffff;
    return 0.7f >= d.f;
}


// 0x001ad7d0 FUN_001ad7d0 (237 B): equivalent/0x001ad7d0.cpp
// sym: ?advance@Iterator_1ad7d0@fn_f54565b1@@QAEXPAUContext@2@@Z @70a2feac791b @wc16fd131ae36
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 28/28)
// FUN_001ad7d0 @ 0x001ad7d0
void Iterator_1ad7d0::advance(Context* ctx) {
 Record_1ad7d0* root=ctx->store->FUN_001b5800(parent);
 if (!root) { index=-1; return; }
 ++index;
 while(index<3) {
  current=root->children[index];
  if(current==-1 && ctx->store->FUN_001b65f0(parent,index)) current=root->children[index];
  if(current!=-1) {
   Record_1ad7d0* entry=ctx->store->FUN_001b5800(current);
   if(entry) {
    unsigned int flags=entry->flags >> 3;
    unsigned int group=(flags>>7)&7;
    if((group==0 || group>=ctx->minFlags) && !(flags & 0x1c00)) {
     if(entry->level>ctx->maxLevel) {
      if(FUN_001ad730(current,ctx)) return;
     } else if(accept || root->levels[index]>=ctx->minLevel) return;
    }
   }
  }
  ++index;
 }
 index=-1;
}

} // namespace fn_f54565b1

// 0x001adeb0 FUN_001adeb0 (393 B): equivalent/0x001adeb0.cpp [wrapped: conflict: Node]
// sym: ?FUN_001adeb0@Finder_1adeb0@fn_001adeb0@@QAEHPAUVec3_1adeb0@2@HDH@Z @6b0a2b286412 @w445837f79c65
namespace fn_001adeb0 {
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 23/26, incomplete)
// FUN_001adeb0 @ 0x001adeb0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_1adeb0 {
    float x, y, z;
};

struct Node {
    int ids[3];                      // 0x00 (slots 1 and 2 are the neighbours)
    unsigned char level[3];          // 0x0c (bytes 1 and 2 used)
    unsigned char kind;              // 0x0f
};

struct Mgr_1adeb0 {
    Node *FUN_001b5800(int id);
    Vec3_1adeb0 *FUN_001b5a20(Vec3_1adeb0 *out, int id);
    char FUN_001b65f0(int id, int slot);
};

struct Frame_1adeb0 {
    Node *node;
    float best;
    int bestId;
    Mgr_1adeb0 *mgr;
    Vec3_1adeb0 tmp;
};

struct Finder_1adeb0 {
    Mgr_1adeb0 *mgr;                        // 0x00
    unsigned minLevel;               // 0x04
    unsigned maxKind;                // 0x08

    int FUN_001adeb0(Vec3_1adeb0 *pos, int id, char recurse, int unused);
};

int Finder_1adeb0::FUN_001adeb0(Vec3_1adeb0 *pos, int id, char recurse, int unused)
{
    Frame_1adeb0 f;
    f.node = mgr->FUN_001b5800(id);
    f.bestId = 0;
    f.best = 0;
    if (f.node == 0)
        return 0;
    f.mgr = mgr;

    Vec3_1adeb0 *p = f.mgr->FUN_001b5a20(&f.tmp, id);
    float dx = p->x - pos->x;
    float dy = p->y - pos->y;
    float dz = p->z - pos->z;
    float base = (float)sqrt((double)(dz * dz + dy * dy + dx * dx));

    for (int slot = 1; slot < 3; slot++) {
        int cid = f.node->ids[slot];
        if (cid == -1) {
            if (!mgr->FUN_001b65f0(id, slot))
                continue;
            cid = f.node->ids[slot];
            if (cid == -1)
                continue;
        }
        Node *child = mgr->FUN_001b5800(cid);
        if (child == 0) {
            f.node->ids[slot] = -1;
            continue;
        }
        if (child->kind > maxKind)
            continue;
        if (f.node->level[slot] < minLevel)
            continue;

        Vec3_1adeb0 *q = f.mgr->FUN_001b5a20(&f.tmp, cid);
        float ex = q->x - pos->x;
        float ey = q->y - pos->y;
        float ez = q->z - pos->z;
        double d = sqrt((double)(ez * ez + ey * ey + ex * ex));
        if (!(base > d)) {
            if (f.best == (*(float*)&DAT_003f32e0) || d > f.best) {
                f.best = (float)d;
                f.bestId = cid;
            }
        }
    }

    if (recurse) {
        int r = FUN_001adeb0(pos, f.bestId, 0, 1);
        if (r != 0)
            return r;
    }
    return f.bestId;
}
} // namespace fn_001adeb0


// 0x001ae040 FUN_001ae040 (271 B): equivalent/0x001ae040.cpp [wrapped: conflict: Node]
// sym: ?FUN_001ae040@Search_1ae040@fn_001ae040@@QAEHPBUVec3_1ae040@2@HH@Z @9d1a8974dbbd @wf850a0d4b08b
namespace fn_001ae040 {
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 20/20)
// FUN_001ae040 @ 0x001ae040
struct Vec3_1ae040 { float x,y,z; };
struct Node { unsigned int unused; int links[2]; unsigned char pad; unsigned char ratings[2]; unsigned char rating; };
struct Manager_1ae040 { Node* FUN_001b5800(int id); bool FUN_001b65f0(int id, unsigned int slot); Vec3_1ae040* FUN_001b5a20(Vec3_1ae040* out, int id); };

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

struct Search_1ae040 { Manager_1ae040* manager; unsigned int minRating; unsigned int maxRating; int FUN_001ae040(const Vec3_1ae040* pos, int id, int unused); };
int Search_1ae040::FUN_001ae040(const Vec3_1ae040* pos, int id, int unused) {
 Node* root=manager->FUN_001b5800(id);
 int result=0; float best=0.0f;
 if(!root) return 0;
 for(unsigned int slot=1;slot<3;++slot) {
  int neighbor=root->links[slot-1];
  if(neighbor==-1) {
   if(!manager->FUN_001b65f0(id,slot)) continue;
   neighbor=root->links[slot-1];
   if(neighbor==-1) continue;
  }
  Node* node=manager->FUN_001b5800(neighbor);
  if(!node) { root->links[slot-1]=-1; continue; }
  if(node->rating>maxRating || root->ratings[slot-1]<minRating) continue;
  Vec3_1ae040 temp; Vec3_1ae040* point=manager->FUN_001b5a20(&temp,neighbor);
  double dx=(double)point->x-pos->x, dy=(double)point->y-pos->y, dz=(double)point->z-pos->z;
  double distance=sqrt(dx*dx+dz*dz+dy*dy);
  if(best==0.0f || distance<best) { best=(float)distance; result=neighbor; }
 }
 return result;
}
} // namespace fn_001ae040


// 0x001ae150 FUN_001ae150 (160 B): equivalent/0x001ae150.cpp
// sym: ?FUN_001ae150@Ring_1ae150@owners@@QAEXH@Z @63d9baeb48fa @w53903163ce31
// STATUS: equivalent (tools/equiv.py level 3: 2397 inputs, branch coverage 20/20)
// FUN_001ae150 @ 0x001ae150
// FUN_001ae150 @ 0x001ae150: removes the first occurrence of a value from a ring buffer, rotating the older entries
void owners::Ring_1ae150::FUN_001ae150(hulk_intptr value)
{
    hulk_intptr count;
    if (head > tail)
        count = (tail - begin) + (end - head);
    else
        count = tail - head;

    for (int i = 0; i < count; i++) {
        int v = *head;
        if (tail >= end)
            tail = head;
        head++;
        if (head == end)
            head = begin;
        if (((int)value) == v)
            return;
        if (tail < end) {
            if (tail)
                *tail = v;
            tail++;
            if (tail == end)
                tail = begin;
            if (head == tail)
                tail += end - begin;
        }
    }
}

namespace fn_f54565b1 {

// 0x001ae1f0 FUN_001ae1f0 (197 B): equivalent/0x001ae1f0.cpp
// sym: ?FUN_001ae1f0@fn_f54565b1@@YG_NPBUVec3_1ae1f0@1@IPAU21@I@Z @e20171cee1c5 @w7d416d173d6e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001ae1f0 @ 0x001ae1f0
bool __stdcall FUN_001ae1f0(const Vec3_1ae1f0* position, unsigned int argument, Vec3_1ae1f0* output, unsigned int option) {
 Vec3_1ae1f0 copy = *position;
 Item_1ae1f0* item = 0;
 unsigned int count = 0xffffffff;
 DAT_004dd700->manager->FUN_001b6000(&copy, &item, &count);
 if (!item) return false;
 Query_1ae1f0 query;
 query.item = item; query.type = 2; query.size = 0x4c; query.option = option;
 if (!count) return false;
 unsigned int index = query.FUN_001adeb0(argument, count, 1, 1);
 if (!index) return false;
 Vec3_1ae1f0 temporary;
 Vec3_1ae1f0* result = item->FUN_001b5a20(&temporary, index);
 output->x = result->x;
 output->y = result->y;
 output->z = result->z;
 return true;
}

} // namespace fn_f54565b1

// 0x001ae2c0 FUN_001ae2c0 (301 B): equivalent/0x001ae2c0.cpp [wrapped: conflict: World]
// sym: ?FUN_001ae2c0@Recent@fn_001ae2c0@@QAE_NPAUVec3_1ae2c0@2@0HHHHHHHHHHH@Z @05dbb5385589 @w5d113fe3881b
namespace fn_001ae2c0 {
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 12/12)
// FUN_001ae2c0 @ 0x001ae2c0
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

struct Vec3_1ae2c0 {
    float x, y, z;
};

struct Query_1ae2c0 {
    void *obj;
    int kind;
    int size;
    int param;

    unsigned FUN_001ad8c0(Vec3_1ae2c0 *pos, int a3, unsigned region, int a4, int a5, int a6, int a7, int a8, int a9,
                          int a10, int a11, int a12, int a13);
};

struct Zone_1ae2c0 {
    Vec3_1ae2c0 *FUN_001b5a20(Query_1ae2c0 *q, unsigned id);
};

struct Locator {
    void FUN_001b6000(Vec3_1ae2c0 *pos, Zone_1ae2c0 **zone, unsigned *region);
};

struct World {
    char pad[0x10];
    Locator *locator;
};


struct Recent {
    char pad[8];
    unsigned ids[2];
    int next;

    bool FUN_001ae2c0(Vec3_1ae2c0 *out, Vec3_1ae2c0 *pos, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10,
                      int a11, int a12, int a13);
};

bool Recent::FUN_001ae2c0(Vec3_1ae2c0 *out, Vec3_1ae2c0 *pos, int a3, int a4, int a5, int a6, int a7, int a8, int a9,
                          int a10, int a11, int a12, int a13)
{
    Zone_1ae2c0 *zone = 0;
    unsigned region = (unsigned)-1;
    Vec3_1ae2c0 p;
    p.x = pos->x;
    p.y = pos->y;
    p.z = pos->z;

    DAT_004dd700->locator->FUN_001b6000(&p, &zone, &region);
    if (zone == 0)
        return false;
    if (region == 0)
        return false;

    Query_1ae2c0 q;
    q.obj = zone;
    q.kind = 2;
    q.size = 0x4c;
    q.param = a10;

    unsigned id = q.FUN_001ad8c0(pos, a3, region, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    if (id == 0)
        return false;
    if ((char)a11 == 0 && id == region)
        return false;

    Vec3_1ae2c0 *r = zone->FUN_001b5a20(&q, id);
    out->x = r->x;
    out->y = r->y;
    out->z = r->z;

    ids[next] = id;
    next++;
    if (next >= 2)
        next = 0;
    return true;
}
} // namespace fn_001ae2c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f54565b1 {

// 0x001ae3f0 FUN_001ae3f0 (92 B): equivalent/0x001ae3f0.cpp
// sym: _FUN_001ae3f0 @0c7435200bac @w064fd91ab2c5
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001ae3f0 @ 0x001ae3f0
extern "C" unsigned int __cdecl FUN_001ae3f0(Query* query, Range* range)
{
    hulk_uintptr result = (unsigned int)range->identity;
    if (range->identity == query->identity) {
        Record* end = range->end;
        result = (hulk_uintptr)end;
        if (range->begin != end) {
            Record* last = end - 1;
            if (query->value == last->value)
                return (result & 0xffffff00U) | 1;
            hulk_intptr count = end - range->begin;
            result = (unsigned int)count;
            if ((unsigned int)count >= 2) {
                range->end = last;
                if (query->value == (last - 1)->value)
                    return (result & 0xffffff00U) | 1;
            }
        }
    }
    return result & 0xffffff00U;
}


// 0x001ae450 FUN_001ae450 (1383 B): equivalent/0x001ae450.cpp
// sym: ?FUN_001ae450@fn_f54565b1@@YGHTArg1@1@PAUVec3_1ae450@1@TArg3@1@H@Z @3ae6d93788fa @we0743dfe1f0d
// STATUS: equivalent (tools/equiv.py level 3: 20039 inputs, branch coverage 63/80, incomplete)
// FUN_001ae450 @ 0x001ae450
int __stdcall FUN_001ae450(Arg1 a1, Vec3_1ae450 *out, Arg3 a3, int a4)
{
    union Frame {
        Plane_1ae450 D;
        Seg_1ae450 s23;
    } f23;
    Seg_1ae450 s45;
    Box_1ae450 b1;
    Box_1ae450 b2;

    Owner_1ae450 *O = a1.c->owner;
    if (a3.flag)
        return 0;
    Elem_1ae450 *begin = a1.c->begin;
    Elem_1ae450 *end = a1.c->end;
    if ((unsigned int)(end - begin) <= 1) {
        *out = begin->v;
        return 0;
    }
    Elem_1ae450 *end2 = a1.c->end;
    Elem_1ae450 *last = end2 - 1;
    hulk_uintptr n2 = end2 - begin;
    Elem_1ae450 *start = begin;
    if (n2 > 5)
        start = end - 5;
    a3.cur = start;
    bool toEnd = false;
    bool to140 = false;
    if (start == last) {
        toEnd = true;
    } else {
        for (;;) {
            f23.D.FUN_001acfa0(&last->v, &a3.cur->v);
            if (a3.cur == last) {
                toEnd = true;
                break;
            }
            a1.t = -f23.D.d;
            Elem_1ae450 *cur = a3.cur;
            for (;;) {
                O->FUN_001b5760(cur->f0);
                Vec3_1ae450 *p1 = O->FUN_001b56a0(cur[1].f0, cur->f4);
                Vec3_1ae450 *p2 = O->FUN_001b56a0(cur[1].f0, ((signed char*)&DAT_0041d7f8)[cur->f4]);
                bool s1 = f23.D.y * p1->z + f23.D.x * p1->x < a1.t;
                bool s2 = f23.D.y * p2->z + f23.D.x * p2->x < a1.t;
                if (s1 == s2)
                    break;
                cur = cur + 1;
                if (cur == last) {
                    to140 = true;
                    break;
                }
            }
            if (to140)
                break;
            if (cur == last) {
                to140 = true;
                break;
            }
            Elem_1ae450 *n = a3.cur + 1;
            a3.cur = n;
            if (n == last) {
                toEnd = true;
                break;
            }
        }
    }
    if (!toEnd && a3.cur == last)
        toEnd = true;
    if (toEnd) {
        int k = last[-1].f4;
        Vec3_1ae450 *A = O->FUN_001b56a0(last->f0, k);
        Vec3_1ae450 *B = O->FUN_001b56a0(last->f0, ((signed char*)&DAT_0041d7f8)[k]);
        volatile float ys = B->y + A->y;
        volatile float zs = B->z + A->z;
        out->x = (B->x + A->x) * 0.5f;
        out->y = ys * 0.5f;
        out->z = zs * 0.5f;
        return 0;
    }
    Elem_1ae450 *c0 = a3.cur;
    if (c0->f4 < 0) {
        *out = c0->v;
        return 0;
    }
    int k4 = a4;
    if (k4 < 0) {
        *out = c0->v;
        return 0;
    }
    if (!((*(unsigned char*)((char*)&DAT_004e17c0 + 48)) & 1))
        (*(unsigned char*)((char*)&DAT_004e17c0 + 48)) |= 1;
    a3.bits = 0;
    Vec3_1ae450 *r = O->FUN_001b56a0(last->f0, k4);
    ((Vec3_1ae450*)&DAT_004e17c0)[0] = *r;
    Vec3_1ae450 *r2 = O->FUN_001b56a0(last->f0, ((signed char*)&DAT_0041d7f8)[k4]);
    ((Vec3_1ae450*)&DAT_004e17c0)[1] = *r2;
    s45.a = ((Vec3_1ae450*)&DAT_004e17c0)[0];
    s45.b = ((Vec3_1ae450*)&DAT_004e17c0)[1];
    Vec3_1ae450 *r3 = O->FUN_001b56a0(c0->f0, c0->f4);
    ((Vec3_1ae450*)&DAT_004e17c0)[2] = *r3;
    Vec3_1ae450 *r4 = O->FUN_001b56a0(c0->f0, ((signed char*)&DAT_0041d7f8)[c0->f4]);
    ((Vec3_1ae450*)&DAT_004e17c0)[3] = *r4;
    f23.s23.a = ((Vec3_1ae450*)&DAT_004e17c0)[2];
    f23.s23.b = ((Vec3_1ae450*)&DAT_004e17c0)[3];
    for (int i = 0; i < 4; i++) {
        f23.s23.FUN_0022fe40(&b1);
        s45.FUN_0022fe40(&b2);
        const Vec3_1ae450 &p = ((Vec3_1ae450*)&DAT_004e17c0)[i];
        bool in1 = p.x >= b1.mn.x && p.x <= b1.mx.x && p.y >= b1.mn.y && p.y <= b1.mx.y && p.z >= b1.mn.z && p.z <= b1.mx.z;
        bool in2 = p.x >= b2.mn.x && p.x <= b2.mx.x && p.y >= b2.mn.y && p.y <= b2.mx.y && p.z >= b2.mn.z && p.z <= b2.mx.z;
        if (in1 && in2)
            a3.flags[i] = 1;
    }
    int bi = -1;
    int bj = -1;
    a1.t = 0.0f;
    for (int j = 0; j < 4; j++) {
        if (j == 0)
            continue;
        if (a3.flags[j] && a3.flags[0]) {
            double dx = ((Vec3_1ae450*)&DAT_004e17c0)[j].x - ((Vec3_1ae450*)&DAT_004e17c0)[0].x;
            double dy = ((Vec3_1ae450*)&DAT_004e17c0)[j].y - ((Vec3_1ae450*)&DAT_004e17c0)[0].y;
            double dz = ((Vec3_1ae450*)&DAT_004e17c0)[j].z - ((Vec3_1ae450*)&DAT_004e17c0)[0].z;
            double d = sqrt(dz * dz + dy * dy + dx * dx);
            if (bi < 0 || d < a1.t) {
                a1.t = (float)d;
                bi = j;
                bj = 0;
            }
        }
    }
    if (bi < 0 || bj < 0) {
        *out = c0->v;
        return 0;
    }
    volatile float ys = ((Vec3_1ae450*)&DAT_004e17c0)[bj].y + ((Vec3_1ae450*)&DAT_004e17c0)[bi].y;
    volatile float zs = ((Vec3_1ae450*)&DAT_004e17c0)[bj].z + ((Vec3_1ae450*)&DAT_004e17c0)[bi].z;
    out->x = (((Vec3_1ae450*)&DAT_004e17c0)[bi].x + ((Vec3_1ae450*)&DAT_004e17c0)[bj].x) * 0.5f;
    out->y = ys * 0.5f;
    out->z = zs * 0.5f;
    return 0;
}

} // namespace fn_f54565b1

// 0x001ae9e0 FUN_001ae9e0 (102 B): matches/0x001ae9e0.cpp [wrapped: conflict: Node]
// sym: ?F@O_1ae9e0@fn_001ae9e0@@QAEPAUPair_1ae9e0@2@PAU32@PBUSrc_1ae9e0@2@@Z
namespace fn_001ae9e0 {
extern "C" void __cdecl FUN_001ad4d0();
extern "C++" void __cdecl FUN_001ad4f0();
struct Src_1ae9e0 {
    int d[10];
};
struct Node {
    char pad[0x10];
    Src_1ae9e0 s;
};
struct Pair_1ae9e0 {
    Node* n;
    void* o;
};
struct This_FUN_00230be0 {
    void* FUN_00230be0(void* a, const Src_1ae9e0* b);
};
void* FUN_0008d6d0(unsigned n);
struct O_1ae9e0 {
    Pair_1ae9e0* F(Pair_1ae9e0* out, const Src_1ae9e0* s);
    void FnG_00230c30(Node* n, void* a, void* b);
};
Pair_1ae9e0* O_1ae9e0::F(Pair_1ae9e0* out, const Src_1ae9e0* s) {
    void* p = ((This_FUN_00230be0*)this)->FUN_00230be0((void*)((hulk_intptr)(void (__cdecl*)())&FUN_001ad4f0), s);
    if (!p) {
        out->n = 0;
        out->o = 0;
        return out;
    }
    Node* r = (Node*)FUN_0008d6d0((int)sizeof(Node));
    Node* n;
    if (r) {
        r->s = *s;
        n = r;
    } else
        n = 0;
    FnG_00230c30(n, (void*)((hulk_intptr)(void (__cdecl*)())&FUN_001ad4d0), p);
    out->n = n;
    out->o = this;
    return out;
}
} // namespace fn_001ae9e0

namespace fn_f54565b1 {

// 0x001aea70 FUN_001aea70 (98 B): matches/0x001aea70.cpp
// sym: ?Cmp@fn_f54565b1@@YAHPAUA_1aea70@1@0@Z
int Cmp(A_1aea70* q, A_1aea70* p) {
    Ref_1aea70 rp = p->r;
    float kp = rp.in->key;
    Ref_1aea70 rq = q->r;
    float kq = rq.in->key;
    if (kq == kp) {
        hulk_uintptr pa = (hulk_uintptr)rp.in + 0x10;
        hulk_uintptr pb = (hulk_uintptr)rq.in + 0x10;
        if (pa > pb)
            return -1;
        return pa < pb;
    }
    if (rq.in->key < rp.in->key)
        return -1;
    return 1;
}


// 0x001aeae0 FUN_001aeae0 (97 B): equivalent/0x001aeae0.cpp
// sym: ?FUN_001aeae0@fn_f54565b1@@YAHPAUEntry@1@PAUGroup@1@@Z @943a5f17ad68 @wb1a16ea608ca
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001aeae0 @ 0x001aeae0
int __cdecl FUN_001aeae0(Entry *left, Group *right)
{
    Item *a = left->item;
    Item *b = right->item;
    if (a->value == b->value) {
        hulk_uintptr pa = (hulk_uintptr)((char *)a + 0x10);
        hulk_uintptr pb = (hulk_uintptr)((char *)b + 0x10);
        if (pb > pa) return -1;
        return pb < pa ? 1 : 0;
    }
    return !(a->value <= b->value) ? 1 : -1;
}


// 0x001aec00 FUN_001aec00 (81 B): matches/0x001aec00.cpp
// sym: ??0CPathManager_1aec00@fn_f54565b1@@QAE@XZ
CPathManager_1aec00::CPathManager_1aec00() {
    vptr = DAT_0041d800;
    int* q = &m4;
    *q = 0;
    int** pp = &m18;
    pp[0] = 0;
    pp[1] = 0;
    m8 = 0;
    mc = 0;
    m10 = 0;
    m14 = 1;
    int* p = (int*)FUN_0008d6d0(0x80);
    m18 = p;
    if (p) {
        m1c = p;
        m20 = p;
        m24 = p + 0x20;
        return;
    }
    m1c = 0;
}


// 0x001aecb0 FUN_001aecb0 (101 B): matches/0x001aecb0.cpp
// sym: ?Run@T_1aecb0@fn_f54565b1@@QAEXPAUOut_1aecb0@2@PAUSrc_1aecb0@2@@Z
void T_1aecb0::Run(Out_1aecb0* out, Src_1aecb0* s) {
    int r = Make_00230be0(FUN_001aeae0, s);
    if (!r) {
        out->o = 0;
        out->t = 0;
        return;
    }
    Obj_1aecb0* p = (Obj_1aecb0*)FUN_0008d6d0((int)sizeof(Obj_1aecb0));
    Obj_1aecb0* o;
    if (p) {
        p->a = s->a;
        p->b = s->b;
        o = p;
    } else
        o = 0;
    Reg_00230c30(o, FUN_001aea70, r);
    out->t = this;
    out->o = o;
}

} // namespace fn_f54565b1
