// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00304640..0x00306450 (kind game, layer engine, confidence high), dominant class physics::CollisionObject
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f3c9f944 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f3c9f944 {} using namespace fn_f3c9f944;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f3c9f944 {
struct Obj_304640 {
    int m0;
    int m4;
    char m8;
    char m9;
    int mc;
    int m10;
    Obj_304640();
};
class Inner_3046f0 {
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
    virtual void f10();
    void Stop_00306380();
    void Start_00306300();
};
class Obj_3046f0 {
  public:
    char p[0x20];
    Inner_3046f0* inner;
    char q[0x2c];
    char active;
    char r[0x17];
    char a, b;
    void Set(char x);
};
extern "C" void* __cdecl AllocFunc_0008d6d0(int size);
extern "C" void __cdecl FreeFunc_0008d340(void* ptr);
} // namespace fn_f3c9f944
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void* dst, const void* src, size_t size);
#endif
namespace fn_f3c9f944 {
struct Element_304930 { unsigned int a,b,c,d,e; void FUN_00304640(); };
void* __cdecl FUN_0008d6d0(unsigned int);
void __stdcall FUN_00011520(void*, unsigned int, int, void (Element_304930::*)());
void __cdecl FUN_0008d340(void*);
} // namespace fn_f3c9f944
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
namespace fn_f3c9f944 {
struct Array_304930 { volatile int count; volatile int capacity; Element_304930* volatile data; unsigned char pad; volatile unsigned char copyMembers; void FUN_00304930(int n); };
void* __cdecl FUN_0008d6d0(int size);
void __cdecl thunk_FUN_00267090(void *p);
struct Pair_304a10 {
    int a;
    int b;
};
class PairArray {
public:
    int count;
    int capacity;
    Pair_304a10 *data;
    char pad0c;
    char deep;
    void Reserve(int wanted);
};
struct S_304b00 {
    int a, b, c;
    char x, y;
    void Clear();
};
class CollisionObject_304b40;
class Ref_304b40 {
  public:
    virtual void A();
    virtual void B();
    int Resolve_00306190(int, unsigned char);
    void Update_003065b0(CollisionObject_304b40*);
};
struct Entry_304b40 {
    int a;
    int b;
    unsigned char c[2];
    int x;
    int y;
};
class CollisionObject_304b40 {
  public:
    char pad0[0x20];
    Ref_304b40* current;
    char pad24[4];
    int count;
    char pad2c[4];
    Entry_304b40* entries;
    char pad34[0x34];
    unsigned char flag;
    void Set(Ref_304b40*);
};
struct Vec_304bd0 {
    Node** b;
    Node** e;
    hulk_intptr bytes() { return (char*)e - (char*)b; }
    hulk_uintptr size() { return e - b; }
};
struct NodeVec_304c40 {
    Node** begin;
    Node** end;
};
struct Context {
    char pad0[8];
    int index;
};
struct Item_304da0 {
    int a, b, c, d, e;
};
class Buffer_304da0 {
  public:
    int count;
    int capacity;
    Item_304da0* data;
    Buffer_304da0& Assign(const Buffer_304da0& other);
    void Reserve_00304930(int n);
};
struct Container_304e50 {
    int count;
    int capacity;
    char* data;
    void Ensure_00304930(int);
    char* Next();
};
struct Item { char pad[8]; void *allocation; char tail[4]; };
struct Owner { char pad0[4]; Item *items; char pad1[8]; void *other; void FUN_00304e80(); };
extern char DAT_00431b08[];
struct Name_304f50 {
    char data[8];
    void FUN_0027af00();
};
struct CollisionObject {
    hulk_intptr vptr;
    char pad04[0xc];
    Name_304f50 name;
    int f18, f1c, f20, f24, f28, f2c, f30;
    char b34, b35;
    char pad36[2];
    int f38, f3c, f40, f44, f48;
    char b4c, b4d;
    char pad4e[2];
    char b50, b51;
    char pad52[2];
    int f54, f58, f5c, f60, f64;
    char b68, b69, b6a, b6b;
    int f6c;
    char b70, b71, b72;
    char pad73;
    int f74;
    int f78;
    void FUN_0027b070();
    void FUN_00304b40(int arg);
    CollisionObject *FUN_00304f50(hulk_intptr arg);
};
class Inner_305030 {
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
    virtual void f10();
    char pad[0x15];
    unsigned char state;
};
void __fastcall FUN_00306230(Inner_305030* p);
class Obj_305030 {
  public:
    char pad[0x20];
    Inner_305030* p;
    int x24;
    int x28;
    char pad2c[0x3c];
    unsigned char b68;
    unsigned char b69;
    void run();
};
typedef unsigned int u32_305170;
struct Mgr_305170 { void FUN_00304bd0(u32_305170, u32_305170, u32_305170); };
struct Ent_305190 {
    int a;
    int b;
    char c;
    unsigned char d;
    int x;
    int y;
};
struct Vec_305190 {
    int count;
    int cap;
    Ent_305190* data;
    void Grow_00304930(int n);
};
struct Sub_305190 {
    int FnF_00306190(int a, unsigned char b);
};
class T_305190 {
  public:
    char pad[0x20];
    Sub_305190* mSub;
    int pad2;
    Vec_305190 mVec;
    char pad3[0x71 - 0x34];
    char mFlag;
    void Add(int a, int b, int c, unsigned char d);
};
struct Pair_305210 { unsigned int a,b; };
struct Item_305210 { int count, capacity; Pair_305210* data; int spare; void FUN_00304a10(int); };
struct Bytes { int count, capacity; unsigned char* data;  };
extern "C" void __stdcall FUN_00304b00(void*);
extern "C" void __stdcall FUN_00011520(void*, int, int, void (__stdcall *)(void*));
struct Container_305210 { int count; Item_305210* items; Bytes bytes; Container_305210* FUN_00305210(const Container_305210* source); };
struct Vector3_305520 { float x, y, z; };
struct Row_305520 { float x, y, z, w; };
struct Matrix { Row_305520 rows[4]; };
struct Vec_305800 { float x,y,z; };
struct Object { void FUN_0022c1b0(); };
extern "C" void __cdecl FUN_00305520(const void *, void *);
} // namespace fn_f3c9f944
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sin(double);
#endif
namespace fn_f3c9f944 {
struct Vec_3059c0 {
    float x, y, z;
    float Len_0022d110();
};
struct Q_3059c0 {
    float x, y, z, w;
};
struct Vec3_305a40 { float x, y, z; };
struct V3_305b00 {
    float x, y, z;
};
struct Tensor_305b00 {
    float f0;
    float yz2;
    float nxy;
    float nzx;
    float xz2;
    float nyz;
    float xy2;
    void FUN_002fcb80(int a);
};
union FloatBits_305b80 {
    float f;
    unsigned int u;
};
inline float Abs(float x) {
    *(unsigned*)&x &= 0x7fffffff;
    return x;
}
struct Vec_305c70 { float x,y,z; hulk_freg FUN_0022d110(); };
struct Quat_305c70 { float x,y,z,w;   };
struct Vec3_305f00 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3_305f00 *other, float eps);
};
typedef int u32_306060;
extern "C" bool __cdecl Check1(u32_306060, hulk_intptr, u32_306060);
extern "C" char __cdecl Check2_00305c00(u32_306060, u32_306060, u32_306060);
class CollisionVolume_3060a0 {
  public:
    void* vptr;
    int m4;
    int m8, mc, m10, m14;
    char c18, c19;
    int m1c, m20, m24, m28, m2c, m30;
    float f;
    CollisionVolume_3060a0() throw();
};
class Thing_3060e0 {
  public:
    char pad[8];
    int a;
    int b;
    char pad10[4];
    int c;
    unsigned char d;
    unsigned char e;
    char pad1a[2];
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
};
struct Vec3_306230 {
    float x, y, z;
};
struct PtrVec_306230 {
    int* b;
    int* e;
};
struct Node {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual Vec3_306230* GetPos();
    virtual void _m_vf5();
    virtual int GetKind();
    char _m_pad_4[0x4];
    union { int level; int mIdx; };
    unsigned char* bits;
    char _m_pad_10[0x4];
    union { NodeVec_304c40* children; Vec_304bd0* kids; PtrVec_306230* mKids; };
    union { char flag; unsigned char value; };
    char _m_pad_19[0x3];
    Vec3_306230 mPos;
    char _m_pad_28[0x8];
    float x;
    float y;
    float z;
    Node* child(unsigned i) { return kids->b[i]; }
    unsigned count() { return kids->size(); }
    void Reset();
};
struct Mgr_304bd0 {
    void Fn(Node* n, int lvl, int f);
};
class CollisionObject_304c40 {
public:
    void FUN_00304c40(Node* node, Context* ctx);
};
class List_3062a0 {
  public:
    char** begin;
    char** end;
};
class Obj_3062a0 {
  public:
    virtual int a();
    virtual int b();
    virtual int c();
    virtual int d();
    virtual int e();
    virtual int f();
    virtual int ready();
    char pad[16];
    List_3062a0* list;
    volatile unsigned char result;
    unsigned char run();
};


// 0x00304640 FUN_00304640 (22 B): matches/0x00304640.cpp
// sym: ??0Obj_304640@fn_f3c9f944@@QAE@XZ
Obj_304640::Obj_304640() : m0(0), m4(0), m8(0), m9(0), mc(0), m10(0) {}


// 0x003046f0 FUN_003046f0 (75 B): matches/0x003046f0.cpp
// sym: ?Set@Obj_3046f0@fn_f3c9f944@@QAEXD@Z
void Obj_3046f0::Set(char x) {
    if (active && !x) {
        active = x;
        inner->Stop_00306380();
    } else if (!active && x) {
        inner->f10();
        active = x;
        inner->Start_00306300();
        a = 0;
        b = 0;
    }
}

} // namespace fn_f3c9f944

// 0x00304740 FUN_00304740 (10 B): matches/0x00304740.cpp
// sym: ?FUN_00304740@C_304740@owners@@QAEXH@Z
// Same code shape as 0x001fb9b0 (propagated; names are from that function)
void owners::C_304740::FUN_00304740(hulk_intptr x) {
    value = ((int)x);
}


// 0x003048a0 FUN_003048a0 (131 B): matches/0x003048a0.cpp
// sym: ?FUN_003048a0@Buffer_3048a0@owners@@QAEXH@Z
void owners::Buffer_3048a0::FUN_003048a0(int newCapacity) {
    if (newCapacity == 0)
        newCapacity = 2;
    if (mCapacity >= newCapacity)
        return;

    void* newData = AllocFunc_0008d6d0(newCapacity);
    if (mSize > 0) {
        if (mFlag) {
            for (int i = 0; i < mSize; ++i) {
                ((char*)newData)[i] = ((char*)mData)[i];
            }
        } else {
            memcpy(newData, mData, mSize);
        }
    }

    FreeFunc_0008d340(mData);
    mData = newData;
    mCapacity = newCapacity;
}

namespace fn_f3c9f944 {

// 0x00304930 FUN_00304930 (211 B): equivalent/0x00304930.cpp
// sym: ?FUN_00304930@Array_304930@fn_f3c9f944@@QAEXH@Z @d87b51f9e65b @w72821b36ef43
// STATUS: equivalent (tools/equiv.py level 3: 267 inputs, branch coverage 15/16, incomplete)
// FUN_00304930 @ 0x00304930
void Array_304930::FUN_00304930(int n) {
 if (!n) n=2;
 if (capacity>=n) return;
 unsigned int* raw=(unsigned int*)FUN_0008d6d0((unsigned int)n*20+4);
 Element_304930* fresh=0;
 if(raw) { *raw=n; fresh=(Element_304930*)(raw+1); FUN_00011520(fresh,20,n,&Element_304930::FUN_00304640); }
 if(count>0) {
 if(copyMembers) { for(int i=0;i<count;++i) { volatile Element_304930* src=data+i; volatile Element_304930* dst=fresh+i; dst->a=src->a; dst->b=src->b; dst->c=src->c; dst->d=src->d; dst->e=src->e; } }
 else { memcpy(fresh,data,(unsigned int)count*20); }
 }
 if(data) FUN_0008d340((unsigned int*)data-1);
 data=fresh; capacity=n;
}


// 0x00304a10 FUN_00304a10 (133 B): equivalent/0x00304a10.cpp
// sym: ?Reserve@PairArray@fn_f3c9f944@@QAEXH@Z @c2011433a531 @wefa9e7baa9ea
// STATUS: equivalent (tools/equiv.py level 3: 12195 inputs, branch coverage 11/12, incomplete)
// FUN_00304a10 @ 0x00304a10
// FUN_00304a10 @ 0x00304a10
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
void PairArray::Reserve(int wanted)
{
    if (wanted == 0)
        wanted = 2;
    if (capacity >= wanted)
        return;
    Pair_304a10 *fresh = (Pair_304a10 *)FUN_0008d6d0(wanted * 8);
    if (count > 0) {
        if (deep) {
            // count and data are re-read every round: fresh may overlap this
            int i = 0;
            do {
                Pair_304a10 *old = data;
                fresh[i].a = old[i].a;
                fresh[i].b = old[i].b;
                i++;
            } while (i < count);
        } else {
            memcpy(fresh, data, count * 8);
        }
    }
    thunk_FUN_00267090(data);
    data = fresh;
    capacity = wanted;
}


// 0x00304b00 FUN_00304b00 (17 B): matches/0x00304b00.cpp
// sym: ?Clear@S_304b00@fn_f3c9f944@@QAEXXZ
void S_304b00::Clear() {
    a = 0;
    b = 0;
    c = 0;
    x = 0;
    y = 0;
}


// 0x00304b40 FUN_00304b40 (129 B): matches/0x00304b40.cpp
// sym: ?Set@CollisionObject_304b40@fn_f3c9f944@@QAEXPAVRef_304b40@2@@Z
void CollisionObject_304b40::Set(Ref_304b40* p) {
    if (p)
        p->A();
    if (current)
        current->B();
    current = p;
    p->Update_003065b0(this);
    flag = 1;
    for (int i = 0; i < count; ++i) {
        Entry_304b40* e = (Entry_304b40*)((char*)entries + i * 0x14);
        e->x = current->Resolve_00306190(e->a, e->c[0]);
        e->y = current->Resolve_00306190(e->b, e->c[1]);
    }
}


// 0x00304bd0 FUN_00304bd0 (109 B): matches/0x00304bd0.cpp
// sym: ?Fn@Mgr_304bd0@fn_f3c9f944@@QAEXPAUNode@2@HH@Z
void Mgr_304bd0::Fn(Node* n, int lvl, int f) {
    if (lvl == n->level)
        n->flag = (char)f;
    if (lvl >= n->level && n->kids && (n->kids->bytes() & 0xfffffffc) != 0) {
        for (unsigned i = 0; i < n->count(); i++)
            Fn(n->child(i), lvl, f);
    }
}


// 0x00304c40 FUN_00304c40 (104 B): equivalent/0x00304c40.cpp
// sym: ?FUN_00304c40@CollisionObject_304c40@fn_f3c9f944@@QAEXPAUNode@2@PAUContext@2@@Z @7e133ce1c39e @w81d0ba6996b9
// STATUS: equivalent (tools/equiv.py level 3: 848 inputs, branch coverage 7/8, incomplete)
// FUN_00304c40 @ 0x00304c40
void CollisionObject_304c40::FUN_00304c40(Node* node, Context* ctx) {
    node->value = node->bits[ctx->index];
    if (node->children == 0)
        return;
    if (node->children->end - node->children->begin == 0)
        return;
    for (unsigned int i = 0; i < (unsigned int)(node->children->end - node->children->begin); i++)
        FUN_00304c40(node->children->begin[i], ctx);
}

} // namespace fn_f3c9f944

// 0x00304cb0 FUN_00304cb0 (128 B): equivalent/0x00304cb0.cpp [wrapped: conflict: Node]
// sym: ?FUN_00304cb0@Finder_304cb0@fn_00304cb0@@QAEHPAUNode@2@0@Z @a55292612c20 @wd47a62da5812
namespace fn_00304cb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 11/12, incomplete)
// FUN_00304cb0 @ 0x00304cb0
// 0x00304cb0: depth-first search for the slot index of `target` below `node`; -1 when not found
struct Node;
struct ChildList_304cb0 {
    Node** begin;
    Node** end;
};

struct Node {
    char pad00[8];
    int slot;
    Node* match;
    char pad10[4];
    ChildList_304cb0* children;
};

class Finder_304cb0 {
public:
    int FUN_00304cb0(Node* node, Node* target);
};

int Finder_304cb0::FUN_00304cb0(Node* node, Node* target)
{
    if (node->match == target)
        return node->slot;
    ChildList_304cb0* list = node->children;
    if (list == 0)
        return -1;
    if (((hulk_intptr)list->end - (hulk_intptr)list->begin & ~3) == 0)
        return -1;
    for (unsigned int i = 0; i < (unsigned int)(node->children->end - node->children->begin); i++) {
        int r = FUN_00304cb0(node->children->begin[i], target);
        if (r >= 0)
            return r;
    }
    return -1;
}
} // namespace fn_00304cb0

namespace fn_f3c9f944 {

// 0x00304da0 FUN_00304da0 (95 B): matches/0x00304da0.cpp
// sym: ?Assign@Buffer_304da0@fn_f3c9f944@@QAEAAV12@ABV12@@Z
Buffer_304da0& Buffer_304da0::Assign(const Buffer_304da0& other) {
    if (capacity < other.capacity)
        Reserve_00304930(other.capacity);
    count = other.count;
    for (int i = 0; i < count; ++i)
        data[i] = other.data[i];
    return *this;
}


// 0x00304e50 FUN_00304e50 (37 B): matches/0x00304e50.cpp
// sym: ?Next@Container_304e50@fn_f3c9f944@@QAEPADXZ
char* Container_304e50::Next() {
    int cap = capacity;
    if (count >= cap)
        Ensure_00304930(cap * 2);
    ++count;
    return data + count * 20 - 20;
}


// 0x00304e80 FUN_00304e80 (79 B): equivalent/0x00304e80.cpp
// sym: ?FUN_00304e80@Owner@fn_f3c9f944@@QAEXXZ @f6a9d9812ad0 @w7c06f17af2d7
// STATUS: equivalent (tools/equiv.py level 3: 720 inputs, branch coverage 6/6)
// FUN_00304e80 @ 0x00304e80
void Owner::FUN_00304e80() {
    Item *const entries = items;
    if (entries) {
        int *const header = (int *)((char *)entries - 4);
        const int count = *header;
        for (int i = count - 1; i >= 0; --i)
            FUN_0008d340(entries[i].allocation);
        FUN_0008d340(header);
    }
    FUN_0008d340(other);
}

} // namespace fn_f3c9f944

// 0x00304ed0 FUN_00304ed0 (127 B): equivalent/0x00304ed0.cpp [wrapped: conflict: physics::CollisionObject]
// sym: ??0CollisionObject@physics@fn_00304ed0@@QAE@XZ @a05fccbf6716 @w7ed939089159
namespace fn_00304ed0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00304ed0 @ 0x00304ed0
// equiv-map: ??0ObjectBase@@QAE@XZ = 0x0027b070

struct Name_304ed0 {
    int a;
    int b;
    void FUN_0027af00();
};

class Entity_304ed0 {
public:
    Entity_304ed0() throw();
    virtual void vfunc_0();
    int f04, f08, f0c;
};

namespace physics {
class CollisionObject : public Entity_304ed0 {
public:
    Name_304ed0 name;              // 0x10
    int f18, f1c, f20, f24, f28, f2c, f30;
    char b34, b35;
    char pad36[2];
    int f38, f3c, f40, f44, f48;
    char b4c, b4d;
    char pad4e[2];
    char b50, b51;
    char pad52[2];
    int f54, f58, f5c, f60, f64;
    char b68, b69, b6a, b6b;
    int f6c;
    char b70, b71, b72;
    CollisionObject() throw();
    virtual void vfunc_0();
};
}

physics::CollisionObject::CollisionObject() throw()
{
    name.FUN_0027af00();
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f2c = 0;
    f30 = 0;
    b34 = 0;
    b35 = 0;
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 0;
    f48 = 0;
    b4c = 0;
    b4d = 0;
    b50 = 0;
    f54 = 0;
    b51 = 1;
    f58 = 0;
    f5c = 0;
    f60 = 0;
    f64 = 0;
    b6b = 0;
    b71 = 0;
    b68 = 1;
    b69 = 1;
    b6a = 1;
    f6c = 0xf;
    b70 = 1;
    b72 = 1;
}
} // namespace fn_00304ed0

namespace fn_f3c9f944 {

// 0x00304f50 FUN_00304f50 (154 B): equivalent/0x00304f50.cpp
// sym: ?FUN_00304f50@CollisionObject@fn_f3c9f944@@QAEPAU12@H@Z @d4bba464d725 @w3527caa98e0d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00304f50 @ 0x00304f50
CollisionObject *CollisionObject::FUN_00304f50(hulk_intptr arg)
{
    FUN_0027b070();
    vptr = (hulk_intptr)DAT_00431b08;
    name.FUN_0027af00();
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f2c = 0;
    f30 = 0;
    b34 = 0;
    b35 = 0;
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 0;
    f48 = 0;
    b4c = 0;
    b4d = 0;
    b50 = 0;
    b51 = 1;
    f54 = 0;
    f58 = 0;
    f5c = 0;
    f60 = 0;
    f64 = 0;
    b6b = 0;
    b71 = 0;
    b68 = 1;
    b69 = 1;
    b6a = 1;
    b70 = 1;
    b72 = 1;
    f78 = 1;
    f6c = 0xf;
    FUN_00304b40(arg);
    f74 = -1;
    return this;
}

} // namespace fn_f3c9f944

// 0x00304ff0 FUN_00304ff0 (64 B): matches/0x00304ff0.cpp [wrapped: conflict: CollisionObject]
// sym: ?destroy@CollisionObject@fn_00304ff0@@QAEXXZ
namespace fn_00304ff0 {
extern "C++" { extern char DAT_00431b08[]; }
class Ref_304ff0 {
  public:
    virtual void f0();
    virtual void f1();
};
class CollisionObject {
  public:
    hulk_ulongptr vptr;
    char pad4[0x1c];
    Ref_304ff0* mRef;
    char pad24[0xc];
    void* mPtr;
    char pad34[4];
    char sub[0x10];
    void destroy();
};
class H38_304ff0 {
  public:
    void run_00304e80();
};
class H10_304ff0 {
  public:
    void run_0027af50();
};
class CollisionObject_304ff0 {
  public:
    void run_0027afd0();
};
extern void thunk_0008d340(void*);
void CollisionObject::destroy() {
    Ref_304ff0* r = mRef;
    vptr = ((hulk_intptr)DAT_00431b08);
    if (r)
        r->f1();
    ((H38_304ff0*)sub)->run_00304e80();
    if (mPtr)
        thunk_0008d340((char*)mPtr - 4);
    ((H10_304ff0*)((char*)this + 0x10))->run_0027af50();
    ((CollisionObject_304ff0*)this)->run_0027afd0();
}
} // namespace fn_00304ff0

namespace fn_f3c9f944 {

// 0x00305030 FUN_00305030 (50 B): matches/0x00305030.cpp
// sym: ?run@Obj_305030@fn_f3c9f944@@QAEXXZ
void Obj_305030::run() {
    p->state = 0;
    b68 = 1;
    b69 = 1;
    p->f10();
    x24 = 0;
    FUN_00306230(p);
    x28 = 0;
}

} // namespace fn_f3c9f944

// 0x00305070 physics::CollisionObject::vfunc_7 (244 B): equivalent/0x00305070.cpp [wrapped: conflict: physics::CollisionObject]
// sym: ?vfunc_7@CollisionObject@physics@fn_00305070@@UAEPAXPAUContext@3@@Z @0cd827695290 @w5700e70b8465
namespace fn_00305070 {
// STATUS: equivalent (tools/equiv.py level 3: 93 inputs, branch coverage 18/18)
// physics::CollisionObject::vfunc_7 @ 0x00305070
struct Entry_305070 { unsigned char kind; char padding[11]; };
struct Item_305070 { char data[8]; };
struct Group_305070 { int count; int reserved; Item_305070* items; int reserved2; };
struct Manager_305070 { char pad[0x24]; unsigned char* mapping; char pad2[0x14]; Entry_305070* begin; Entry_305070* end; unsigned char FUN_00298960(Item_305070*); };
struct Context { char pad[0x44]; Manager_305070* manager; };
struct Owner_305070 { void FUN_003062a0(); };
namespace physics {
struct CollisionObject {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void* vfunc_7(Context*);
char pad[0x1c]; Owner_305070* owner; char pad2[0x14]; int count; Group_305070* groups; int result; Manager_305070* manager; unsigned char* states;
void FUN_00304c40(Owner_305070*, int*);
};
void* CollisionObject::vfunc_7(Context* context) {
 bool changed=false;
 for(int i=0;i<count;++i) {
  unsigned char active=0;
  for(int j=0;j<groups[i].count;++j) {
   Manager_305070* m=context->manager;
   unsigned char index=m->FUN_00298960(&groups[i].items[j]);
   unsigned char n=(unsigned char)(m->end-m->begin);
   if(index<n && m->mapping[index]!=255 && m->begin[index].kind==1) { active=1; break; }
  }
  if(states[i]!=active) { states[i]=active; changed=true; }
 }
 if(changed) { FUN_00304c40(owner,&result); owner->FUN_003062a0(); }
 return &result;
}
}
} // namespace fn_00305070


// 0x00305170 physics::CollisionObject::vfunc_6 (22 B): matches/0x00305170.cpp
// sym: ?vfunc_6@CollisionObject@physics@@UAEXHH@Z
void physics::CollisionObject::vfunc_6(int __p0, int __p1) { u32_305170 a = (u32_305170)__p0; u32_305170 b = (u32_305170)__p1;

    ((Mgr_305170*)this)->FUN_00304bd0(this->f_20, a, b);
}

namespace fn_f3c9f944 {

// 0x00305190 FUN_00305190 (113 B): matches/0x00305190.cpp
// sym: ?Add@T_305190@fn_f3c9f944@@QAEXHHHE@Z
void T_305190::Add(int a, int b, int c, unsigned char d) {
    Vec_305190* v = &mVec;
    mFlag = 1;
    if (v->count >= v->cap)
        v->Grow_00304930(v->cap * 2);
    v->count++;
    Ent_305190* e = &v->data[v->count - 1];
    e->a = a;
    e->b = b;
    e->c = (char)c;
    e->d = d;
    if (mSub) {
        e->x = mSub->FnF_00306190(a, c);
        e->y = mSub->FnF_00306190(e->b, e->d);
    }
}


// 0x00305210 FUN_00305210 (261 B): equivalent/0x00305210.cpp
// sym: ?FUN_00305210@Container_305210@fn_f3c9f944@@QAEPAU12@PBU12@@Z @33030c1dfc86 @wd58a9064c163
// STATUS: equivalent (tools/equiv.py level 3: 53 inputs, branch coverage 20/20)
// FUN_00305210 @ 0x00305210
Container_305210* Container_305210::FUN_00305210(const Container_305210* source) {
 count = source->count;
 if (count > 0) {
  int n=count;
  unsigned int* allocation=(unsigned int*)FUN_0008d6d0((unsigned int)n*16+4);
  Item_305210* array=0;
  if (allocation) {
   *allocation=n;
   array=(Item_305210*)(allocation+1);
   FUN_00011520(array,16,n,FUN_00304b00);
  }
  items=array;
  for (int i=0;i<count;++i) {
   const Item_305210* from=&source->items[i];
   Item_305210* to=&items[i];
   if(to->capacity < from->capacity) to->FUN_00304a10(from->capacity);
   to->count=from->count;
   for(int j=0;j<to->count;++j) {
    Pair_305210* src=from->data;
    unsigned int a=src[j].a;
    Pair_305210* dst=to->data;
    dst[j].a=a;
    dst[j].b=src[j].b;
   }
  }
  if(bytes.capacity < source->bytes.capacity) ((owners::Buffer_3048a0 *)&bytes)->FUN_003048a0(source->bytes.capacity);
  bytes.count=source->bytes.count;
  for(int k=0;k<bytes.count;++k) bytes.data[k]=source->bytes.data[k];
 }
 return this;
}

} // namespace fn_f3c9f944

// 0x00305320 physics::CollisionObject::vfunc_2 (85 B): matches/0x00305320.cpp [wrapped: conflict: physics::CollisionObject]
// sym: ?vfunc_2@CollisionObject@physics@fn_00305320@@UAEPAV123@E@Z
namespace fn_00305320 {
class Ref_305320 {
  public:
    virtual void f0();
    virtual void f1();
};
extern int hulk_at_00431b08;
class H38_305320 {
  public:
    void run38_00304e80();
};
class H10_305320 {
  public:
    void run10_0027af50();
};
class CollisionObject_305320 {
  public:
    void run0_0027afd0();
};
namespace physics { class CollisionObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual CollisionObject* vfunc_2(unsigned char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    char pad10[0x1c];
    int field20;
    char pad24[12];
    hulk_intptr field30;
    char pad34[4];
}; }
void __cdecl freeA_0008d340(void*);
void __cdecl freeB_00263f30(void*);
physics::CollisionObject* physics::CollisionObject::vfunc_2(unsigned char p) {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_00431b08;
    if (field20) {
        Ref_305320* r = *(Ref_305320**)&field20;
        r->f1();
    }
    ((H38_305320*)((char*)this + 0x38))->run38_00304e80();
    if (field30)
        freeA_0008d340((char*)field30 - 4);
    ((H10_305320*)((char*)this + 0x10))->run10_0027af50();
    ((CollisionObject_305320*)this)->run0_0027afd0();
    if (p & 1)
        freeB_00263f30(this);
    return this;
}
} // namespace fn_00305320


// 0x00305400 physics::CollisionObject::vfunc_5 (278 B): equivalent/0x00305400.cpp [wrapped: conflict: physics::CollisionObject]
// sym: ?vfunc_5@CollisionObject@physics@fn_00305400@@UAEPAU123@H@Z @0d2a14fc0e68 @w4a3873195a5d
namespace fn_00305400 {
// STATUS: equivalent (tools/equiv.py level 3: 462 inputs, branch coverage 6/6)
// physics::CollisionObject::vfunc_5 @ 0x00305400
void* __cdecl FUN_00263ea0(unsigned int);
struct Copy8 { char data[8]; void FUN_0027af70(const Copy8*); };
struct Link_305400 { int first, second; unsigned char a,b; char pad[2]; int resolvedFirst,resolvedSecond; };
struct Links_305400 { int count; int capacity; Link_305400* items; int other; void FUN_00304da0(const Links_305400*); };
struct State_305400 { char data[24]; void FUN_00305210(const State_305400*); };
struct Shape_305400 { Shape_305400* FUN_00306c60(); int FUN_00306190(int,unsigned int); };
namespace physics {
struct CollisionObject {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual CollisionObject* vfunc_5(int); virtual void vfunc_6(); virtual void vfunc_7();
 int unknown4; Copy8 name; Copy8 otherName; int owner; int flags; Shape_305400* shape; int value24; Links_305400 links; State_305400 state; unsigned char flag50,flag51; char pad52[2]; int value54,value58,value5c,value60,value64; char pad68[2]; unsigned char flag6a,flag6b; int value6c; unsigned char flag70,flag71,flag72; char tail[13];
 CollisionObject* FUN_00304ed0(); void FUN_00304b40(Shape_305400*);
};
CollisionObject* CollisionObject::vfunc_5(int newOwner) {
 void* memory=FUN_00263ea0(128);
 CollisionObject* result=memory ? static_cast<CollisionObject*>(memory)->FUN_00304ed0() : 0;
 result->name.FUN_0027af70(&name);
 result->shape=0;
 result->flags=flags;
 Shape_305400* cloned=shape->FUN_00306c60();
 result->FUN_00304b40(cloned);
 result->owner=newOwner;
 result->otherName.FUN_0027af70(&otherName);
 result->value24=value24;
 result->links.FUN_00304da0(&links);
 result->state.FUN_00305210(&state);
 result->flag50=flag50; result->flag51=flag51; result->value54=value54; result->value6c=value6c;
 result->flag71=flag71; result->flag72=flag72; result->flag6a=flag6a; result->flag6b=flag6b;
 result->value58=value58; result->value5c=value5c; result->value60=value60; result->value64=value64;
 for(int i=0;i<links.count;++i) {
 Link_305400* entry=&result->links.items[i];
 int resolved=result->shape->FUN_00306190(entry->first,entry->a);
 entry->resolvedFirst=resolved;
 resolved=result->shape->FUN_00306190(entry->second,entry->b);
 entry->resolvedSecond=resolved;
 }
 return result;
}
}
} // namespace fn_00305400

namespace fn_f3c9f944 {

// 0x00305520 FUN_00305520 (230 B): equivalent/0x00305520.cpp
// sym: _FUN_00305520 @a5d1453a1ea1 @wacb28fb6da06
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00305520 @ 0x00305520
extern "C" void __cdecl FUN_00305520(const void * rotation_, void * matrix)
{
    const Vector3_305520 * rotation = (const Vector3_305520 *)rotation_;
    Matrix original = *((Matrix *)matrix);
    for (int i = 0; i < 3; ++i) {
        ((Matrix *)matrix)->rows[i].x = (original.rows[i].x - original.rows[i].y * rotation->z) + original.rows[i].z * rotation->y;
        ((Matrix *)matrix)->rows[i].y = (original.rows[i].x * rotation->z + original.rows[i].y) - original.rows[i].z * rotation->x;
        ((Matrix *)matrix)->rows[i].z = (original.rows[i].z - original.rows[i].x * rotation->y) + original.rows[i].y * rotation->x;
    }
}

} // namespace fn_f3c9f944

// 0x00305630 FUN_00305630 (197 B): equivalent/0x00305630.cpp [wrapped: conflict: Matrix]
// sym: _FUN_00305630 @ea7da691cb3d @wd1bca8866275
namespace fn_00305630 {
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_00305630 @ 0x00305630
struct Matrix { float m[16]; void FUN_0022b980(); };
struct Vector { float x,y,z; };
extern "C" void __cdecl FUN_00305630(Vector* out, const Matrix* a, const Matrix* b, float time) {
 Matrix temp; temp.FUN_0022b980();
 double dx0=(double)b->m[0]-a->m[0];
 double dx1=(double)b->m[1]-a->m[1];
 temp.m[2]=b->m[2]-a->m[2];
 temp.m[4]=b->m[4]-a->m[4];
 double dy1=(double)b->m[5]-a->m[5];
 temp.m[6]=b->m[6]-a->m[6];
 temp.m[8]=b->m[8]-a->m[8];
 double dz1=(double)b->m[9]-a->m[9];
 temp.m[10]=b->m[10]-a->m[10];
 out->z=(float)((dx1*a->m[0]+dz1*a->m[8])+dy1*a->m[4]);
  volatile float* tv=temp.m; // the original reads these differences back from its frame (rounded to float)
 out->y=(float)(((double)tv[8]*a->m[10]+(double)tv[4]*a->m[6])+dx0*a->m[2]);
 double scale=1.0/time;
 out->x=(float)((((double)temp.m[6]*a->m[5]+(double)temp.m[2]*a->m[1])+(double)temp.m[10]*a->m[9])*scale);
 out->y=(float)(scale*out->y);
 out->z=(float)(scale*out->z);
}
} // namespace fn_00305630

namespace fn_f3c9f944 {

// 0x00305700 FUN_00305700 (97 B): matches/0x00305700.cpp
// sym: _FUN_00305700
extern "C" void FUN_00305700(float s, float* src, float* dst) {
    dst[0] = s * src[0];
    dst[1] = s * src[1];
    dst[2] = s * src[2];
    dst[4] = s * src[4];
    dst[5] = s * src[5];
    dst[6] = s * src[6];
    dst[8] = s * src[8];
    dst[9] = s * src[9];
    dst[10] = s * src[10];
}


// 0x00305800 FUN_00305800 (190 B): equivalent/0x00305800.cpp
// sym: _FUN_00305800 @34fde874a5c8 @wcd42418e93b4
// STATUS: equivalent (tools/equiv.py level 3: 18764 inputs, branch coverage 4/4)
// FUN_00305800 @ 0x00305800
extern "C" void __cdecl FUN_00305800(const Vec_305800* input, Object* object, float divisor) {
 union Bits { float f; unsigned int u; } x,y,z;
 x.f=input->x; y.f=input->y; z.f=input->z;
 x.u &= 0x7fffffff; y.u &= 0x7fffffff; z.u &= 0x7fffffff;
 int count=(int)(__int64)(((double)z.f+y.f+x.f)/divisor)+1;
 double scale=1.0f/(double)count;
 Vec_305800 step;
 step.x=(float)(input->x*scale);
 step.y=(float)(input->y*scale);
 step.z=(float)(input->z*scale);
 for(int i=0;i<count;++i) FUN_00305520((Vec_305800 *)(&step),(Object *)object);
 object->FUN_0022c1b0();
}

} // namespace fn_f3c9f944

// 0x003058c0 FUN_003058c0 (243 B): equivalent/0x003058c0.cpp [wrapped: conflict: Matrix]
// sym: ?FUN_003058c0@fn_003058c0@@YAMPBUMatrix@1@M@Z @fb734ef7fb13 @wd398d1025776
namespace fn_003058c0 {
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 4/4)
// FUN_003058c0 @ 0x003058c0
struct Matrix { float x0,y0,z0,w0; float x1,y1,z1,w1; float x2,y2,z2,w2; };

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

hulk_freg __cdecl FUN_003058c0(const Matrix* m, float tolerance) {
    float a = (double)m->z0*m->z0 + (double)m->y0*m->y0 + (double)m->x0*m->x0;
    double b = (double)m->z1*m->z1 + (double)m->y1*m->y1 + (double)m->x1*m->x1;
    union { float f; unsigned int u; } delta;
    delta.f = a-b;
    delta.u &= 0x7fffffff;
    double inverse = 1.0 / a;
    if (!(delta.f * inverse < tolerance)) return 1.0f;
    delta.f = a-((double)m->z2*m->z2 + (double)m->y2*m->y2 + (double)m->x2*m->x2);
    delta.u &= 0x7fffffff;
    if (!(delta.f * inverse < tolerance)) return 1.0f;
    return sqrt(a);
}
} // namespace fn_003058c0

namespace fn_f3c9f944 {

// 0x003059c0 FUN_003059c0 (113 B): matches/0x003059c0.cpp
// sym: _FUN_003059c0
extern "C" bool FUN_003059c0(Vec_3059c0* a, Q_3059c0* b) {
    Vec_3059c0 v = *a;
    bool r = false;
    hulk_freg t = v.Len_0022d110();
    if (t > 0.0001f) {
        t = t * 0.5f;
        b->w = (hulk_freg)cos(t);
        hulk_freg s = (hulk_freg)sin(t);
        b->x = v.x * s;
        b->y = v.y * s;
        b->z = v.z * s;
        r = true;
    }
    return r;
}


// 0x00305a40 FUN_00305a40 (186 B): equivalent/0x00305a40.cpp
// sym: _FUN_00305a40 @31b7236bd8a2 @w610cdee6ff59
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00305a40 @ 0x00305a40
extern "C" int __cdecl FUN_00305a40(const Vec3_305a40* v, unsigned char absolute)
{
    float x=v->x, y=v->y, z=v->z;
    if (absolute) {
        union Bits { float f; unsigned int u; } a,b,c;
        a.f=x; b.f=y; c.f=z;
        a.u &= 0x7fffffff; b.u &= 0x7fffffff; c.u &= 0x7fffffff;
        x=a.f; y=b.f; z=c.f;
    }
    if (x > y) return x > z ? 0 : 2;
    return y > z ? 1 : 2;
}


// 0x00305b00 FUN_00305b00 (117 B): equivalent/0x00305b00.cpp
// sym: _FUN_00305b00 @545f9f7c960e @w38c9be55ba09
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00305b00 @ 0x00305b00
extern "C" void __cdecl FUN_00305b00(Tensor_305b00 *out, const V3_305b00 *v, int a)
{
    out->yz2 = v->y * v->y + v->z * v->z;
    out->nxy = -(v->x * v->y);
    out->nzx = -(v->z * v->x);
    out->xz2 = v->x * v->x + v->z * v->z;
    out->nyz = -(v->z * v->y);
    out->xy2 = v->x * v->x + v->y * v->y;
    out->FUN_002fcb80(a);
}


// 0x00305b80 FUN_00305b80 (113 B): equivalent/0x00305b80.cpp
// sym: ?FUN_00305b80@fn_f3c9f944@@YA_NPBUNode@1@0M@Z @798330d791a5 @w45ba71d996ff
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00305b80 @ 0x00305b80
// True when every component of a and b differs by no more than tol.
bool FUN_00305b80(const Node* a, const Node* b, float tol)
{
    FloatBits_305b80 d;
    d.f = a->x - b->x;
    d.u &= 0x7fffffff;
    if (d.f > tol)
        return false;
    d.f = a->y - b->y;
    d.u &= 0x7fffffff;
    if (d.f > tol)
        return false;
    d.f = a->z - b->z;
    d.u &= 0x7fffffff;
    if (d.f > tol)
        return false;
    return true;
}


// 0x00305c00 FUN_00305c00 (111 B): matches/0x00305c00.cpp
// sym: _FUN_00305c00
extern "C" bool FUN_00305c00(const float* a, const float* b, float e) {
    if (Abs(a[0] - b[0]) > e)
        return false;
    else if (Abs(a[5] - b[5]) > e)
        return false;
    else if (Abs(a[10] - b[10]) > e)
        return false;
    else
        return true;
}


// 0x00305c70 FUN_00305c70 (590 B): equivalent/0x00305c70.cpp
// sym: ?FUN_00305c70@fn_f3c9f944@@YA_NPBUVec_305c70@1@0PAUQuat_305c70@1@PA_N@Z @8be7ea96cf9c @w5b5663df60c3
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00305c70 @ 0x00305c70
bool __cdecl FUN_00305c70(const Vec_305c70* a,const Vec_305c70* b,Quat_305c70* out,bool* opposite) {
 *opposite=false;
 double lengths=sqrt(a->x*a->x+a->y*a->y+a->z*a->z)*sqrt(b->x*b->x+b->y*b->y+b->z*b->z);
 if(lengths < 0.000001f) {out->z=0;out->y=0;out->x=0;out->w=1;return false;}
 double dot=(a->y*b->y+a->z*b->z)+a->x*b->x;
 float savedDot=(float)dot;
 double ratio=dot/lengths;
 float angle;
 if(ratio>=1.0f) angle=0; else angle=FUN_00018a20((float)ratio);
 Vec_305c70 axis;
 axis.x=b->z*a->y-a->z*b->y;
 axis.y=b->x*a->z-b->z*a->x;
 axis.z=a->x*b->y-b->x*a->y;
 if(sqrt(axis.z*axis.z+axis.x*axis.x+axis.y*axis.y)<0.000001f) {
  if(savedDot>0.0f) {out->z=0;out->y=0;out->x=0;out->w=1;return true;}
  *opposite=true; angle=3.141592741012573242f;
  axis.x=a->z*0.0f-a->y*0.0f;
  axis.y=a->x*0.0f-a->z;
  axis.z=a->y-a->x*0.0f;
  if(sqrt(axis.z*axis.z+axis.x*axis.x+axis.y*axis.y)<0.000001f) {((owners::X_22b1c0 *)out)->FUN_0022b1c0(3.141592741012573242f);return true;}
 }
 if(axis.FUN_0022d110()!=0.0f) {
  double half=angle*0.5f;
  out->w=(float)cos(half);
  double s=sin(half);
  out->x=(float)(axis.x*s);out->y=(float)(axis.y*s);out->z=(float)(axis.z*s);
  ((owners::Vec4_22b120 *)out)->FUN_0022b120();
 } else {out->z=0;out->y=0;out->x=0;out->w=1;}
 return true;
}


// 0x00305f00 FUN_00305f00 (351 B): equivalent/0x00305f00.cpp
// sym: _FUN_00305f00 @d0488ceffa82 @wc04e68093d92
// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 6/6)
// FUN_00305f00 @ 0x00305f00
// Axis (cross product b x a) and angle between two vectors.
extern "C" void FUN_00305f00(const Vec3_305f00 *a, const Vec3_305f00 *b, Vec3_305f00 *axis, float *angle)
{
    Vec3_305f00 zero;
    float dot;      // x87: dot goes through the frame across the call (rounded)

    hulk_freg v1 = a->x * b->z - a->z * b->x;
    hulk_freg v2 = a->y * b->x - a->x * b->y;
    hulk_freg v3 = a->z * b->y - a->y * b->z;
    axis->x = v3;
    axis->y = v1;
    axis->z = v2;

    dot = a->z * b->z + a->y * b->y + a->x * b->x;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    if (axis->FUN_0022d2b0(&zero, 0.0001f)) {
        if (dot < 0.0f)
            *angle = 3.14159274f;
        else
            *angle = 0.0f;
        axis->x = a->x;
        axis->y = a->y;
        axis->z = a->z;
        return;
    }

    double lenB = sqrt((double)(b->y * b->y + b->z * b->z + b->x * b->x));
    hulk_freg ay = a->y;
    hulk_freg az = a->z;
    hulk_freg ax = a->x;
    double lenA = sqrt((double)(ay * ay + az * az + ax * ax));
    double q = dot / (lenA * lenB);
    hulk_freg c = (float)q;
    if (q >= 1.0f)
        *angle = 0.0f;
    else
        *angle = FUN_00018a20(c);
}


// 0x00306060 FUN_00306060 (54 B): matches/0x00306060.cpp
// sym: _FUN_00306060
extern "C" bool __cdecl FUN_00306060(u32_306060 a, u32_306060 b, u32_306060 c) {
    char r = Check1(a, b, c);
    if (r == 0)
        return false;
    return Check2_00305c00(a, b, c);
}


// 0x003060a0 FUN_003060a0 (61 B): matches/0x003060a0.cpp
// sym: ??0CollisionVolume_3060a0@fn_f3c9f944@@QAE@XZ
CollisionVolume_3060a0::CollisionVolume_3060a0() throw() {
    m4 = 0;
    vptr = vA;
    _ReadWriteBarrier();
    m10 = 0;
    m14 = 0;
    c18 = 1;
    c19 = 0;
    _ReadWriteBarrier();
    m8 = -1;
    mc = -1;
    m1c = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    f = 1.0f;
}


// 0x003060e0 FUN_003060e0 (47 B): matches/0x003060e0.cpp
// sym: ?FUN_003060e0@fn_f3c9f944@@YIXPAVThing_3060e0@1@@Z
void __fastcall FUN_003060e0(Thing_3060e0* p) {
    p->a = -1;
    p->b = -1;
    p->c = 0;
    p->d = 1;
    p->e = 0;
    p->f = 0;
    p->g = 0;
    p->h = 0;
    p->i = 0;
    p->j = 0;
    p->k = 0;
    p->l = 0x3f800000;
}

} // namespace fn_f3c9f944

// 0x00306190 FUN_00306190 (152 B): equivalent/0x00306190.cpp [wrapped: conflict: Node]
// sym: ?FUN_00306190@Node@fn_00306190@@QAEPAV12@H_N@Z @ac58ddd028cb @w654d127d1d14
namespace fn_00306190 {
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 20/20)
// FUN_00306190 @ 0x00306190
struct NodeList_306190;

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int Kind();
    char pad04[4];
    int id;                     // 8
    char pad0c[8];
    NodeList_306190 *children;         // 0x14
    Node *FUN_00306190(int wanted, bool strict);
};

struct NodeList_306190 {
    Node **begin;
    Node **end;
};

// Finds the node with the wanted id in this subtree (kind 1 nodes only count when not strict).
Node *Node::FUN_00306190(int wanted, bool strict)
{
    if (id > wanted)
        return 0;
    if (Kind() != 1 || !strict) {
        if (id == wanted)
            return this;
    }
    if (children == 0)
        return 0;
    for (unsigned int i = 0; i < (unsigned int)(children->end - children->begin); i++) {
        Node *child = children->begin[i];
        if (child->id == wanted && child->Kind() != 1)
            return child;
        Node *found = child->FUN_00306190(wanted, strict);
        if (found != 0)
            return found;
    }
    return 0;
}
} // namespace fn_00306190

namespace fn_f3c9f944 {

// 0x00306230 FUN_00306230 (98 B): matches/0x00306230.cpp
// sym: ?Reset@Node@fn_f3c9f944@@QAEXXZ
void Node::Reset() {
    mIdx = -1;
    if (GetKind() != 1) {
        Vec3_306230* p = GetPos();
        mPos.x = p->x;
        mPos.y = p->y;
        mPos.z = p->z;
    }
    if (mKids) {
        for (unsigned i = 0; i < (unsigned)(mKids->e - mKids->b); i++)
            ((Node*)mKids->b[i])->Reset();
    }
}


// 0x003062a0 FUN_003062a0 (87 B): matches/0x003062a0.cpp
// sym: ?run@Obj_3062a0@fn_f3c9f944@@QAEEXZ
unsigned char Obj_3062a0::run() {
    if (ready() == 1 && list) {
        result = 0;
        unsigned int i = 0;
        while (i < (unsigned int)(list->end - list->begin)) {
            if (((Obj_3062a0*)list->begin[i])->run())
                result = 1;
            ++i;
        }
    }
    return result;
}

} // namespace fn_f3c9f944

// 0x00306300 FUN_00306300 (128 B): matches/0x00306300.cpp [wrapped: conflict: Node]
// sym: ?FUN_00306300@Node@fn_00306300@@QAEXXZ
namespace fn_00306300 {
// FUN_00306300 @ 0x00306300
// 0x00306300: if the owner is active, run the handler for this node's kind, then do the same for every child
struct Owner_306300 {
    char pad00[0x50];
    char active;
};

class Node;
struct ChildList_306300 {
    Node** begin;
    Node** end;
};

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int Kind();
    char pad04[0xc];
    Owner_306300* owner;
    ChildList_306300* children;
    char pad18;
    char started;
    void FUN_00306300();
};

void Node::FUN_00306300()
{
    if (owner == 0 || owner->active == 0)
        return;
    started = 1;
    switch (Kind()) {
    case 2:
        ((owners::Axis_2f32b0 *)this)->FUN_002f32b0();
        break;
    case 5:
        ((owners::AxisRemap_2fbf20 *)this)->FUN_002fbf20();
        break;
    case 8:
        ((owners::Obj_30e8a0 *)this)->FUN_0030e8a0();
        break;
    }
    if (children == 0)
        return;
    for (unsigned int i = 0; i < (unsigned int)(children->end - children->begin); i++)
        children->begin[i]->FUN_00306300();
}
} // namespace fn_00306300


// 0x00306380 FUN_00306380 (208 B): equivalent/0x00306380.cpp [wrapped: conflict: Node]
// sym: ?FUN_00306380@Node@fn_00306380@@QAEXXZ @1fdabd70002a @wd446182cf61c
namespace fn_00306380 {
// STATUS: equivalent (tools/equiv.py level 3: 680 inputs, branch coverage 12/12)
// FUN_00306380 @ 0x00306380
struct Node;
struct Children_306380 { Node** begin; Node** end; };
struct Node {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual int slot6();
 char pad04[0x10]; Children_306380* children;
 char pad18[0x20];
 unsigned int f38;
 char pad3c[8];
 unsigned int f44,f48,f4c,f50,f54,f58,f5c,f60,f64,f68,f6c,f70,f74;
 char pad78[0x10];
 unsigned int f88,f8c,f90,f94,f98,f9c,fa0,fa4,fa8,fac,fb0,fb4;
 void FUN_00306380();
};
void Node::FUN_00306380() {
 int kind=slot6();
 if(kind==2) f60=0;
 else if(kind==5) {
 f38=0;
 f48=f88; f54=f94; f58=f98; f5c=f9c;
 f4c=f8c; f60=fa0; f64=fa4; f68=fa8;
 f50=f90; f6c=fac; f70=fb0; f74=fb4;
 } else if(kind==8) f44=0;
 if(children) {
 unsigned int count=(unsigned int)(((hulk_intptr)children->end-(hulk_intptr)children->begin)>>2);
 for(unsigned int i=0;i<count;++i) {
 children->begin[i]->FUN_00306380();
 count=(unsigned int)(((hulk_intptr)children->end-(hulk_intptr)children->begin)>>2);
 }
 }
}
} // namespace fn_00306380

