// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00247ba0..0x0024c1c0 (kind game, layer engine, confidence medium), dominant class audio::StreamPlayerAllocator
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9a518a5 {
#define TREE_TU_END }
namespace fn_f9a518a5 {} using namespace fn_f9a518a5;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f9a518a5 {
typedef unsigned int u32_247bd0;
extern "C" void __cdecl FUN_0024bf90(void *);
struct Node {
  public:
    union { Node* a; Node* left; Node* next; };
    union { Node* b; Node* parent; int value; };
    union { Node* c; Node* right; };
    int state;
    char _m_pad_10[0x8];
    int value0;
    int value1;
    int other;
    char _m_pad_24[0x4];
    int finalValue;
};
struct Tree_247d50 {
    Node* root;
};
struct Tree_247eb0 {
    Node* root;
};
struct N_247f80 {
    N_247f80* l;
    N_247f80* r;
    N_247f80* p;
};
struct RbNode_247fc0 {
    RbNode_247fc0* left;
    RbNode_247fc0* right;
    RbNode_247fc0* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_247fc0 {
    RbNode_247fc0* root;
    RbNode_247fc0 nil;
};
struct Tree_2482a0 {
    Node* root;
};
struct Tree_2483b0 {
    Node* root;
};
typedef unsigned int U_2485c0;
struct Triple_2485c0 {
    U_2485c0 a, b, c;
};
struct Obj_2485c0 {
    char pad[0x90];
    U_2485c0 a, b, c, d, e, f, g;
};
struct Sound_248670 {
 float volume;
};
struct ThisNote_0025d740 {
    // equiv-conv: FUN_0025d740 ecx
    void FUN_0025d740();
};
struct ThisNote_0025d780 {
    // equiv-conv: FUN_0025d780 ecx
    void FUN_0025d780();
};
struct Owner_248670 { char reserved[48]; unsigned active; };
struct Fade_248670 {
 char reserved[8];
 Sound_248670* sound;
 unsigned result;
 char reserved10[8];
 unsigned delay;
 unsigned duration;
 unsigned elapsed;
 float progress;
 unsigned phase;
};
struct Output_248780 { float value;  void FUN_0025d3f0(int); };
struct State_248780 { char pad0[8]; Output_248780* output; unsigned active; char pad10[8]; unsigned delay; unsigned duration; unsigned elapsed; float level; unsigned phase; };
struct N_248bf0 {
    N_248bf0* next;
    N_248bf0* l;
    N_248bf0* r;
};
struct RbNode_248d40 {
    RbNode_248d40* left;
    RbNode_248d40* right;
    RbNode_248d40* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_248d40 {
    RbNode_248d40* root;
    RbNode_248d40 nil;
};
struct RbNode_248fa0 {
    RbNode_248fa0* left;
    RbNode_248fa0* right;
    RbNode_248fa0* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_248fa0 {
    RbNode_248fa0* root;
    RbNode_248fa0 nil;
};
struct RbNode_249200 {
    RbNode_249200* left;
    RbNode_249200* right;
    RbNode_249200* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_249200 {
    RbNode_249200* root;
    RbNode_249200 nil;
};
typedef unsigned int u32_2495f0;
struct A_2495f0 {
    char pad[0x10];
    u32_2495f0 value;
};
typedef unsigned int u32_249600;
typedef unsigned int u32_249610;
extern "C" float __cdecl FUN_00241700(int, int);
extern "C" float __cdecl FUN_00241710(int, int);
struct Object {
  public:
    char _m_pad_0[0x8];
    union { float scale; int value; };
    float base;
    float outputScale;
    float outputBase;
    char _m_pad_18[0x18];
    int state;
    float amount;
    int duration;
    Node* nodes;
    char _m_pad_40[0x4];
    int key;
};
struct Flags { char pad[0x44]; unsigned char bits; unsigned short FUN_00249750(); };
struct Owner {
  public:
    char _m_pad_0[0x1c];
    Flags* flags;
    char _m_pad_20[0x2];
    unsigned short count;
};
struct Item {
  public:
    Item* next;
    Owner* owner;
    int value;
    void* link;
    char _m_pad_10[0x2c];
    unsigned short count;
    char _m_pad_3e[0x86];
    int state;
};
int FUN_00249750(Item*);
struct Voice_2498d0 { float value;   void FUN_0025dfc0(unsigned,unsigned); };
struct Link_2498d0 { Link_2498d0* next; };
struct List_2498d0 { char pad[0x48]; Link_2498d0* head; };
struct Item_2498d0 { char pad0[8]; Voice_2498d0* voice; int state; unsigned char flag; char pad11[3]; int blocked; unsigned a,b,c; float magnitude; unsigned d; char pad2c[4]; List_2498d0* list; Link_2498d0 link; };
struct Entry_249b40 {
    Entry_249b40 *next;
    char pad04[8];
    void *value;
};
struct TreeNode_249b40 {
    TreeNode_249b40 *left;
    TreeNode_249b40 *right;
    TreeNode_249b40 *parent;
    int pad0c;
    Entry_249b40 *entries;
};
struct Tree_249b40 {
    char pad00[0x18];
    TreeNode_249b40 *root;
    TreeNode_249b40 nil;
};
struct Container { char pad00[16]; Node *head; };
struct Pair { int first; int second; };
struct Link_24a3c0 {
    void FUN_0025dd00(int a);
};
struct Obj_24a3c0 {
    char pad0[8];
    Link_24a3c0 *link;
    int state;
};
extern "C++" __declspec(nothrow) void __cdecl FUN_00249810(void *, int);
void FUN_002498d0(Obj_24a3c0 *o);
extern "C" void __cdecl FUN_00248670(void *, void *, unsigned);
extern "C" void __cdecl FUN_00248780(void *, unsigned);
struct Obj_24a4f0 {
    char pad[0x14];
};
struct ListLink {
    ListLink* next;
};
class Settings_24a510 {
public:
    char pad0[0x10];
    int owner;
    float scale0;
    float* pScaleA;
    float* pScaleB;
    float scale1;
    float scale2;
    float* pLimit;
    int zero2c;
    int* pMode;
    int* pCounter;
    float* pRate;
    int zero3c;
    int zero40;
    int zero44;
    int zero48;
    int zero4c;
    ListLink* link50;
    ListLink listA[3];  // 0x54: empty circular list (all links point at the head)
    int zero60;
    ListLink* link64;
    ListLink listB[3];  // 0x68: second empty circular list
    int zero74;
    Settings_24a510* FUN_0024a510(int ownerArg);
};
typedef unsigned int u32_24a590;
extern void __cdecl F47550(void*, u32_24a590);
struct Obj_24a590 {
    char pad[0x3c];
    u32_24a590 m3c;
    u32_24a590 m40;
};
struct IntrusiveList {
    void *head;
    void *next;
    void *prev;
    void *last;
    int count;
    // empty list: every link points at the sentinel stored in the second slot
    void Init() { head = &next; next = &next; prev = &next; last = &next; count = 0; }
};
struct Pool_24a5d0 {
    char data[0x48];
};
struct ItemLink {
    ItemLink *next;
};
struct Item_24a5d0 {
    char pad00[0x14];
    ItemLink link;           // 0x14
    char pad18[0x38 - 0x18];
    int attr;                // 0x38
};
struct Entry_24a5d0 {
    char pad00[0x10];
    int key;                 // 0x10
};
struct Source_24a5d0 {
    char pad00[0x22];
    unsigned short refCount; // 0x22
    char pad24[0x3c - 0x24];
    ItemLink *itemHead;      // 0x3c
    Entry_24a5d0 *FUN_00257250();
};
struct SrcNode {
    char pad00[0x10];
    int f10;
    int f14;
    int f18;
    Item_24a5d0 *owner;             // 0x1c
};
struct KeyNode {
    KeyNode *next;
    void *key;
};
} // namespace fn_f9a518a5
namespace audio {
class StreamPlayerAllocator_24a5d0 {
public:
    virtual void v0();
    unsigned char flags;     // 0x04
    StreamPlayerAllocator_24a5d0() {}
};
}
namespace fn_f9a518a5 {
extern "C" void FUN_00257e80(void *list, void *item);
void *FUN_00247530(Pool_24a5d0 *pool);
void FUN_00249ce0(IntrusiveList *list, SrcNode *node, int *attr);
extern "C" void *FUN_00242ce0(void *a3, int *key);
class StreamVoice {
public:
    char pad00[8];
    float f08;
    float f0c;
    float f10;
    float f14;
    IntrusiveList nodes;     // 0x18
    Source_24a5d0 *source;          // 0x2c
    int mode;                // 0x30
    float f34;
    int f38;
    KeyNode *keyHead;        // 0x3c
    KeyNode *keyTail;        // 0x40
    void *owner;             // 0x44
    IntrusiveList list48;    // 0x48
    IntrusiveList list5c;    // 0x5c
    IntrusiveList list70;    // 0x70
    int f84;
    int f88;
    int f8c;
    int f90, f94, f98;
    int f9c, fa0, fa4;
    float fa8;
    audio::StreamPlayerAllocator_24a5d0 *allocator; // 0xac
    audio::StreamPlayerAllocator_24a5d0 ownAllocator; // 0xb0

    StreamVoice(int a0, int a1, Source_24a5d0 *a2, void *a3, int a4, audio::StreamPlayerAllocator_24a5d0 *a5);
};
typedef unsigned char u8_24a7a0;
class Obj_24a7a0 {
  public:
    char pad[0x3c];
    int m3c;
    int m40;
    Obj_24a7a0* Update(u8_24a7a0);
};
extern void Copy(void*, hulk_intptr);
struct Obj_24ace0 {
    int Do(int, int, int, int, int, int);
};
extern "C" hulk_intptr __cdecl GetThing(void*);
struct Child;
struct Sub {
    char pad[0x14];
    char inner;
};
struct Node1 {
    Node1 *next;
    char pad[0x10 - 4];
    Child *children;
};
struct List1 {
    Node1 *first;
    Node1 *last;
};
struct Node2 {
    Node2 *next;
    char pad0[0x3c - 4];
    hulk_intptr value3c;
    hulk_intptr value40;
    char pad1[0x50 - 0x44];
    Sub sub50;
};
struct List2 {
    Node2 *first;
    Node2 *last;
};
struct SNode {
    SNode *next;
    int payload;
};
struct Pool {
    char pad[1];
};
void FUN_00249750(Child *c);
extern "C++" __declspec(nothrow) void __cdecl FUN_00248ac0(void *, void *);
extern "C++" __declspec(nothrow) void __cdecl FUN_00249ec0(void *, void *);
void FUN_00247550(void *pool, void *block);
extern "C" void FUN_00257f00(void *a, void *b);
extern "C" void FUN_00242d70(void *a, int b);
struct Registry {
    char pad0[0x18];
    List1 list1;
    char pad1[0x2c - 0x20];
    Owner *owner;
    char pad2[0x3c - 0x30];
    SNode *head;
    SNode *tail;
    void *pool44;
    List2 list2;
    char pad3[0x5c - 0x50];
    Sub sub5c;

    void FUN_0024ad20();
};
struct Obj_24ae50 {
    int x;
    void Helper();
    Obj_24ae50* Bar(unsigned char flag);
};
void __cdecl FUN_00247550(void*, Obj_24ae50*);
struct Obj_24af00 {
    void Clean();
};
struct X {
    int a;
    int value;
    int b;
    float scale;
};
extern const float big;
typedef unsigned int u32_24afe0;
typedef unsigned int u32_24b030;
extern "C" int __cdecl FUN_0025d060(u32_24b030);
extern "C" void __cdecl FUN_00258b80(int value, float amount);
struct Argument { char reserved[8]; void* value; };
struct Entry_24b050;
extern "C" void __cdecl FUN_00258ba0(void* value, Entry_24b050* entries, unsigned count);
extern "C" int __cdecl FUN_00258c80(int value, float amount);
typedef unsigned int u32_24b0d0;
struct Inner_24b0d0 {
    char pad[0x24];
    u32_24b0d0 value;
};
struct Outer_24b0d0 {
    char pad[0x10];
    Inner_24b0d0* inner;
};
struct Ring_24b170 {
    char pad0[4];
    unsigned int size;
    char pad8[0x18 - 8];
    unsigned int readPos;
    unsigned int fillEnd;
    unsigned int pending;
    unsigned int filled;
};
class Stream {
  public:
    virtual void start();
    virtual void stop();
    virtual void _m_vf2();
    virtual char done();
    char _m_pad_4[0x4];
    void* handle;
    char _m_pad_c[0x4];
    Ring_24b170* ring;
    char _m_pad_14[0xac];
    int state;
    int mode;
};
extern "C" unsigned int __cdecl FUN_00258f00(void* handle);
bool __cdecl FUN_0025e350(Ring_24b170* ring, unsigned int count);
extern "C" void * __cdecl FUN_00259c50(void *);
void __cdecl FUN_00258e50(void* handle);
struct Obj_24b220 {
    char pad[0xb9];
    u8 value;
};
class Obj_24b270 {
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
    virtual void f11();
    virtual void f12();
};
struct Handler_24b480 {
    virtual void v0();
    virtual int State();
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
};
struct Slots_24b480 {
    Handler_24b480 *handler;
    int pad4[2];
};
struct Ring_24b480 {
    Slots_24b480 slots[10];
    unsigned char current;
    unsigned char count;
    unsigned char size;
    void FUN_0024b270();
};
struct Machine {
    char pad0[0x40];
    Ring_24b480 ring;
};
class Sink_24b550 {
public:
    virtual void v0();
    virtual int state();
    virtual void v2();
    virtual unsigned int v3();
    virtual void v4();
    virtual void v5();
    virtual void write(unsigned int a, unsigned int b, unsigned int c);
    virtual void v7();
    virtual char poll(unsigned int *out);
};
struct Slot_24b550 {
    Sink_24b550 *sink;
    char rest[8];
};
struct Queue_24b550 {
    Slot_24b550 slots[10];
    unsigned char current;
    unsigned char enabled;
};
struct Chunk {
    unsigned int f0;
    unsigned int f4;
    char pad8[4];
    float fc;
    char pad10[4];
    void *f14;
};
struct Region_24b550 {
    unsigned int pos;
    char pad4[4];
    unsigned int len;
    char padc[0x18 - 0xc];
    unsigned int extra;
};
struct Frame_24b550 {
    unsigned int x;
    unsigned int y;
    unsigned int z;
};
unsigned int FUN_0025e090(Chunk *c);
hulk_uintptr FUN_0026fd80(hulk_uintptr a, unsigned int n);
extern "C" unsigned int FUN_0025e310(Region_24b550 *r);
extern "C" char FUN_0025cf70(int a, void *b, hulk_uintptr c, unsigned int *out);
extern "C" char FUN_0025d070(int a, void *b, hulk_uintptr c, int d, unsigned int *z, unsigned int *y, unsigned int *x);
unsigned int FUN_00267f80();
Stream *FUN_002703c0(unsigned int y, unsigned int z, unsigned int w, unsigned int v, unsigned int x);
extern "C" void FUN_0025d0f0(int a, unsigned int b);
void FUN_0025e350(Region_24b550 *r, unsigned int v);
char FUN_0025d010(int a);
void FUN_0025e0b0(Chunk *c, unsigned int v, int flag);
struct Player_24b550 {
    char pad00[0xc];
    int h0c;
    Chunk *chunk;
    Region_24b550 *region;
    unsigned int t18;
    int n1c;
    unsigned int t20;
    unsigned int t24;
    unsigned int mark28;
    unsigned int t2c;
    unsigned int t30;
    unsigned int t34;
    unsigned int t38;
    unsigned int t3c;
    Queue_24b550 queue;
    char pad_bc[4];
    int mode;
    int state;
    char pad_c8[4];
    unsigned int pos;
    char pad_d0[4];
    Stream *stream;
};
class Obj_24ba70 {
  public:
    char pad0[0xb8];
    unsigned char head;
    unsigned char count;
    unsigned char size;
    char padbb;
    int total;
};
struct Entry_24ba70 {
    int a;
    int b;
    int c;
};
struct Obj_24bae0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void Release();
};
struct Slot_24bae0 { Obj_24bae0* obj; unsigned size; int pad; };
struct Ring_24bae0 {
    char pad[0x40];
    Slot_24bae0 slots[10];
    unsigned char start;
    unsigned char count;
    unsigned char cap;
    char pad2;
    unsigned total;
};
class Sink_24bc70 {
public:
    virtual void v0();
    virtual int state();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void finish();
};
struct Slot_24bc70 {
    Sink_24bc70 *sink;
    char rest[8];
};
struct Queue_24bc70 {
    Slot_24bc70 slots[10];
    unsigned char current;
    unsigned char enabled;
    unsigned char count;
};
struct Span_24bc70 {
    char pad0[0x1c];
    unsigned int start;
    unsigned int length;
};
struct Resource_24bc70 { char pad[4]; };
struct Player_24bc70 {
    char pad0[8];
    int handle;
    unsigned int limit;
    Span_24bc70 *span;
    Resource_24bc70 *res;
    char pad18[0x40 - 0x18];
    Queue_24bc70 queue;
    int f0bc;
    int state;
    int f0c4;
    int f0c8;
};
unsigned int __cdecl FUN_0025d040(unsigned int v);
extern "C" void __cdecl FUN_00258ea0(int handle, int arg);
extern "C" void __cdecl FUN_0025e290(void *obj);
void __cdecl FUN_0024bae0(Player_24bc70 *p, int arg);
extern "C" bool __cdecl FUN_0024b170(void *);
extern "C" void __cdecl FUN_0024b480(void *);
extern "C" void __cdecl FUN_0024b550(void *);
extern "C++" __declspec(nothrow) void __cdecl FUN_0024b920(void *);
} // namespace fn_f9a518a5
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memset(void *p, int c, unsigned n);
#endif
namespace fn_f9a518a5 {
struct Sub_24be00 {
    char pad0[0xc];
    float f0c;
    char pad10[0x28 - 0x10];
    int f28;
    int f2c;
};
struct Rec_24be00 {
    Rec_24be00 *next;
    Rec_24be00 *prev;
    int handle;
    int fc;
    Sub_24be00 *f10;
    Sub_24be00 *f14;
    int f18[10];
    char pad40[0xb8 - 0x40];
    char b8;
    char b9;
    char ba;
    char pad_bb;
    int fbc;
    int fc0, fc4, fc8, fcc, fd0, fd4;
};
struct Pool_24be00 {
    char data[0x48];
};
void *FUN_00247530(void *pool);
void FUN_00247550(void *pool, Rec_24be00 *r);
extern "C" int FUN_0025d340(int a, int b, int c);
extern "C" int FUN_00259610(int a, int b, int c);
extern "C" void FUN_00258b40(int h, int one);
hulk_intptr FUN_0025e070();
int FUN_0025d040(int h);
extern "C" void FUN_0025e550(Sub_24be00 *s, int a, int b, int c);
extern void F24bae0(void*, int);
extern "C" void FUN_00259b40(void*);
extern "C" void FUN_0025d300(void*);
extern "C" void FUN_0025e280(void*);
extern void* F25e070();
extern void F247550(void*, void*);
struct Obj_24bf90 {
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    void* f;
};
extern "C" void __cdecl FUN_0024bc70(void *);
struct Task { char pad[0xc0]; int active; int state; };
struct State { char pad0[8]; int resource; char pad1[0xb4]; int status; int repeat; };
extern "C" void __cdecl FUN_00259be0(int);

} // namespace fn_f9a518a5

// 0x00247ba0 audio::StreamPlayerAllocator::vfunc_0 (34 B): matches/0x00247ba0.cpp [wrapped: conflict: audio::StreamPlayerAllocator]
// sym: ?vfunc_0@StreamPlayerAllocator@audio@fn_00247ba0@@UAEXIIII@Z
namespace fn_00247ba0 {
typedef unsigned int u32_247ba0;
namespace audio {
class StreamPlayerAllocator {
  public:
    virtual void vfunc_0(u32_247ba0 a, u32_247ba0 b, u32_247ba0 c, u32_247ba0 d);
    virtual void vfunc_1();
};
} // namespace audio
extern "C++" __declspec(nothrow) void * __cdecl FUN_0024be00(int, int, int, int, int, int, int);
void audio::StreamPlayerAllocator::vfunc_0(u32_247ba0 a, u32_247ba0 b, u32_247ba0 c, u32_247ba0 d) {
    FUN_0024be00((unsigned int)c, 1, (unsigned int)b, (unsigned int)d, 0, 0, 1);
}
} // namespace fn_00247ba0


// 0x00247bd0 audio::StreamPlayerAllocator::vfunc_1 (14 B): matches/0x00247bd0.cpp
// sym: ?vfunc_1@StreamPlayerAllocator@audio@@UAEXHH@Z
void audio::StreamPlayerAllocator::vfunc_1(int __p0, int __p1) { u32_247bd0 a = (u32_247bd0)__p0; u32_247bd0 b = (u32_247bd0)__p1;

    FUN_0024bf90((void *)(hulk_uintptr)(unsigned int)b);
}

namespace fn_f9a518a5 {

// 0x00247d10 FUN_00247d10 (55 B): matches/0x00247d10.cpp
// sym: ?Walk@fn_f9a518a5@@YAPAUNode@1@PAU21@0@Z
Node* Walk(Node* head, Node* node) {
    Node* nil = (Node*)((char*)head + 4);
    Node* p = node->parent;
    if (p != nil) {
        while (p->left != nil)
            p = p->left;
        return p;
    }
    p = node->right;
    while (p != nil) {
        if (node != p->parent)
            break;
        node = p;
        p = p->right;
    }
    return p;
}


// 0x00247d50 FUN_00247d50 (78 B): matches/0x00247d50.cpp
// sym: ?insert@fn_f9a518a5@@YAXPAUTree_247d50@1@PAUNode@1@@Z
// Same code shape as 0x00241880 (propagated; names are from that function)
void insert(Tree_247d50* tree, Node* node) {
    Node* child = node->b;
    node->b = child->a;
    if (child->a != (Node*)(tree + 1)) {
        child->a->c = node;
    }
    child->c = node->c;
    Node* parent = node->c;
    if (parent == (Node*)(tree + 1)) {
        *reinterpret_cast<Node**>(tree) = child;
        child->a = node;
        node->c = child;
        return;
    }
    if (node == parent->a) {
        parent->a = child;
        child->a = node;
        node->c = child;
        return;
    }
    parent->b = child;
    child->a = node;
    node->c = child;
}

} // namespace fn_f9a518a5

// 0x00247da0 FUN_00247da0 (81 B): matches/0x00247da0.cpp [wrapped: merged class would differ: Tree_247da0: field head: Field(+0x4 Node head) vs Field(+0x4 Node head)]
// sym: _FUN_00247da0
namespace fn_00247da0 {
// Same code shape as 0x002418d0 (propagated; names are from that function)
struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree_247da0 {
    Node* root;
    Node head;
};
extern "C" void FUN_00247da0(Tree_247da0* tree, Node* node) {
    Node* child = node->left;
    node->left = child->parent;
    if (child->parent != &tree->head)
        child->parent->right = node;
    child->right = node->right;
    Node* p = node->right;
    if (p == &tree->head) {
        tree->root = child;
        child->parent = node;
        node->right = child;
        return;
    }
    if (node == p->left) {
        p->left = child;
        child->parent = node;
        node->right = child;
        return;
    }
    p->parent = child;
    child->parent = node;
    node->right = child;
}
} // namespace fn_00247da0

namespace fn_f9a518a5 {

// 0x00247eb0 FUN_00247eb0 (78 B): matches/0x00247eb0.cpp
// sym: ?insert@fn_f9a518a5@@YAXPAUTree_247d50@1@PAUNode@1@@Z
// Same code shape as 0x00241880 (propagated; names are from that function)
void insert(Tree_247eb0* tree, Node* node) {
    Node* child = node->b;
    node->b = child->a;
    if (child->a != (Node*)(tree + 1)) {
        child->a->c = node;
    }
    child->c = node->c;
    Node* parent = node->c;
    if (parent == (Node*)(tree + 1)) {
        *reinterpret_cast<Node**>(tree) = child;
        child->a = node;
        node->c = child;
        return;
    }
    if (node == parent->a) {
        parent->a = child;
        child->a = node;
        node->c = child;
        return;
    }
    parent->b = child;
    child->a = node;
    node->c = child;
}

} // namespace fn_f9a518a5

// 0x00247f00 FUN_00247f00 (81 B): matches/0x00247f00.cpp [wrapped: merged class would differ: Tree_247f00: field head: Field(+0x4 Node head) vs Field(+0x4 Node head)]
// sym: ?swap_node@fn_00247f00@@YAXPAUTree_247f00@1@PAUNode@1@@Z
namespace fn_00247f00 {
// Same code shape as 0x002418d0 (propagated; names are from that function)
struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree_247f00 {
    Node* root;
    Node head;
};
void swap_node(Tree_247f00* tree, Node* node) {
    Node* child = node->left;
    node->left = child->parent;
    if (child->parent != &tree->head)
        child->parent->right = node;
    child->right = node->right;
    Node* p = node->right;
    if (p == &tree->head) {
        tree->root = child;
        child->parent = node;
        node->right = child;
        return;
    }
    if (node == p->left) {
        p->left = child;
        child->parent = node;
        node->right = child;
        return;
    }
    p->parent = child;
    child->parent = node;
    node->right = child;
}
} // namespace fn_00247f00

namespace fn_f9a518a5 {

// 0x00247f80 FUN_00247f80 (55 B): matches/0x00247f80.cpp
// sym: ?Next@fn_f9a518a5@@YAPAUN_247f80@1@PAU21@0@Z
N_247f80* Next(N_247f80* head, N_247f80* x) {
    N_247f80* s = (N_247f80*)((char*)head + 4);
    N_247f80* n = x->r;
    if (n != s) {
        while (n->l != s)
            n = n->l;
        return n;
    }
    n = x->p;
    while (n != s && x == n->r) {
        x = n;
        n = n->p;
    }
    return n;
}


// 0x00247fc0 FUN_00247fc0 (604 B): equivalent/0x00247fc0.cpp
// sym: _FUN_00247fc0
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00247fc0 @ 0x00247fc0
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_00247fc0(void * tree_, void * x_)
{
    RbTree_247fc0 * tree = (RbTree_247fc0 *)tree_;
    RbNode_247fc0 * x = (RbNode_247fc0 *)x_;
    RbNode_247fc0* nil = &tree->nil;
    RbNode_247fc0* y;
    RbNode_247fc0* z;
    RbNode_247fc0* p;
    RbNode_247fc0* c;

    if (x == tree->root) {
        x->color = 0;
        return;
    }
    while (x->color == 0 /* black */) {
        if (x == x->parent->left) {
            y = x->parent->right;
            if (y->color == 1) {
                y->color = 0;
                x->parent->color = 1;
                p = x->parent;
                z = p->right;
                p->right = z->left;
                if (z->left != nil)
                    z->left->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->left = p;
                p->parent = z;
                y = x->parent->right;
            }
            if (y->left->color == 0 && y->right->color == 0) {
                y->color = 1;
                x = x->parent;
            } else {
                if (y->right->color == 0) {
                    y->left->color = 0;
                    z = y->left;
                    y->color = 1;
                    y->left = z->right;
                    if (z->right != nil)
                        z->right->parent = y;
                    z->parent = y->parent;
                    if (y->parent == nil)
                        tree->root = z;
                    else if (y == y->parent->left)
                        y->parent->left = z;
                    else
                        y->parent->right = z;
                    z->right = y;
                    y->parent = z;
                    y = x->parent->right;
                }
                y->color = x->parent->color;
                x->parent->color = 0;
                y->right->color = 0;
                p = x->parent;
                z = p->right;
                p->right = z->left;
                if (z->left != nil)
                    z->left->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->left = p;
                p->parent = z;
                x = tree->root;
            }
        } else {
            y = x->parent->left;
            if (y->color == 1) {
                y->color = 0;
                x->parent->color = 1;
                p = x->parent;
                z = p->left;
                p->left = z->right;
                if (z->right != nil)
                    z->right->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->right = p;
                p->parent = z;
                y = x->parent->left;
            }
            if (y->right->color == 0 && y->left->color == 0) {
                y->color = 1;
                x = x->parent;
            } else {
                if (y->left->color == 0) {
                    y->right->color = 0;
                    z = y->right;
                    y->color = 1;
                    y->right = z->left;
                    if (z->left != nil)
                        z->left->parent = y;
                    z->parent = y->parent;
                    if (y->parent == nil)
                        tree->root = z;
                    else if (y == y->parent->left)
                        y->parent->left = z;
                    else
                        y->parent->right = z;
                    z->left = y;
                    y->parent = z;
                    y = x->parent->left;
                }
                y->color = x->parent->color;
                x->parent->color = 0;
                y->left->color = 0;
                p = x->parent;
                z = p->left;
                p->left = z->right;
                if (z->right != nil)
                    z->right->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->right = p;
                p->parent = z;
                x = tree->root;
            }
        }
        if (x == tree->root)
            break;
    }
    x->color = 0;
}


// 0x00248240 FUN_00248240 (55 B): matches/0x00248240.cpp
// sym: ?next@fn_f9a518a5@@YAPAUNode@1@PAU21@0@Z
Node* __cdecl next(Node* n, Node* current) {
    Node* h = (Node*)((char*)n + 4);
    Node* p = current->parent;
    if (p != h) {
        if (p->left == h)
            return p;
        do {
            p = p->left;
        } while (p->left != h);
        return p;
    }
    p = current->right;
    while (p != h && current == p->parent) {
        current = p;
        p = p->right;
    }
    return p;
}


// 0x002482a0 FUN_002482a0 (78 B): matches/0x002482a0.cpp
// sym: _FUN_002482a0
// Same code shape as 0x00241880 (propagated; names are from that function)
extern "C" void FUN_002482a0(void * tree, void * node) {
    Node* child = ((Node *)node)->b;
    ((Node *)node)->b = child->a;
    if (child->a != (Node*)(((Tree_2482a0 *)tree) + 1)) {
        child->a->c = ((Node *)node);
    }
    child->c = ((Node *)node)->c;
    Node* parent = ((Node *)node)->c;
    if (parent == (Node*)(((Tree_2482a0 *)tree) + 1)) {
        *reinterpret_cast<Node**>(((Tree_2482a0 *)tree)) = child;
        child->a = ((Node *)node);
        ((Node *)node)->c = child;
        return;
    }
    if (((Node *)node) == parent->a) {
        parent->a = child;
        child->a = ((Node *)node);
        ((Node *)node)->c = child;
        return;
    }
    parent->b = child;
    child->a = ((Node *)node);
    ((Node *)node)->c = child;
}

} // namespace fn_f9a518a5

// 0x002482f0 FUN_002482f0 (81 B): matches/0x002482f0.cpp [wrapped: merged class would differ: Tree_2482f0: field head: Field(+0x4 Node head) vs Field(+0x4 Node head)]
// sym: ?swap_node@fn_002482f0@@YAXPAUTree_2482f0@1@PAUNode@1@@Z
namespace fn_002482f0 {
// Same code shape as 0x002418d0 (propagated; names are from that function)
struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree_2482f0 {
    Node* root;
    Node head;
};
void swap_node(Tree_2482f0* tree, Node* node) {
    Node* child = node->left;
    node->left = child->parent;
    if (child->parent != &tree->head)
        child->parent->right = node;
    child->right = node->right;
    Node* p = node->right;
    if (p == &tree->head) {
        tree->root = child;
        child->parent = node;
        node->right = child;
        return;
    }
    if (node == p->left) {
        p->left = child;
        child->parent = node;
        node->right = child;
        return;
    }
    p->parent = child;
    child->parent = node;
    node->right = child;
}
} // namespace fn_002482f0


// 0x00248370 FUN_00248370 (55 B): matches/0x00248370.cpp [wrapped: merged class would differ: Tree: field sentinel: Field(+0x4 Node sentinel) vs Field(+0x4 Node sentinel)]
// sym: ?FUN_00248370@fn_00248370@@YAPAUNode@1@PAUTree@1@PAU21@@Z
namespace fn_00248370 {
struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree {
    char pad[4];
    Node sentinel;
};
Node* __cdecl FUN_00248370(Tree* tree, Node* node) {
    Node* nil = &tree->sentinel;
    Node* next = node->parent;
    if (next != nil) {
        while (next->left != nil)
            next = next->left;
        return next;
    }
    next = node->right;
    while (next != nil && node == next->parent) {
        node = next;
        next = next->right;
    }
    return next;
}
} // namespace fn_00248370

namespace fn_f9a518a5 {

// 0x002483b0 FUN_002483b0 (78 B): matches/0x002483b0.cpp
// sym: _FUN_002483b0
// Same code shape as 0x00241880 (propagated; names are from that function)
extern "C" void FUN_002483b0(Tree_2483b0* tree, Node* node) {
    Node* child = node->b;
    node->b = child->a;
    if (child->a != (Node*)(tree + 1)) {
        child->a->c = node;
    }
    child->c = node->c;
    Node* parent = node->c;
    if (parent == (Node*)(tree + 1)) {
        *reinterpret_cast<Node**>(tree) = child;
        child->a = node;
        node->c = child;
        return;
    }
    if (node == parent->a) {
        parent->a = child;
        child->a = node;
        node->c = child;
        return;
    }
    parent->b = child;
    child->a = node;
    node->c = child;
}

} // namespace fn_f9a518a5

// 0x00248400 FUN_00248400 (81 B): matches/0x00248400.cpp [wrapped: merged class would differ: Tree_248400: field head: Field(+0x4 Node head) vs Field(+0x4 Node head)]
// sym: _FUN_00248400
namespace fn_00248400 {
// Same code shape as 0x002418d0 (propagated; names are from that function)
struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree_248400 {
    Node* root;
    Node head;
};
extern "C" void FUN_00248400(Tree_248400* tree, Node* node) {
    Node* child = node->left;
    node->left = child->parent;
    if (child->parent != &tree->head)
        child->parent->right = node;
    child->right = node->right;
    Node* p = node->right;
    if (p == &tree->head) {
        tree->root = child;
        child->parent = node;
        node->right = child;
        return;
    }
    if (node == p->left) {
        p->left = child;
        child->parent = node;
        node->right = child;
        return;
    }
    p->parent = child;
    child->parent = node;
    node->right = child;
}
} // namespace fn_00248400

namespace fn_f9a518a5 {

// 0x002485c0 FUN_002485c0 (94 B): matches/0x002485c0.cpp
// sym: _FUN_002485c0
extern "C" void FUN_002485c0(Obj_2485c0* self, Triple_2485c0* p, Triple_2485c0* q, U_2485c0 value) {
    if (p) {
        self->a = p->a;
        self->b = p->b;
        self->c = p->c;
    }
    if (q) {
        self->d = q->a;
        self->e = q->b;
        self->f = q->c;
    }
    self->g = value;
}


// 0x00248670 FUN_00248670 (247 B): equivalent/0x00248670.cpp
// sym: _FUN_00248670
// STATUS: equivalent (tools/equiv.py level 3: 19923 inputs, branch coverage 30/30)
// FUN_00248670 @ 0x00248670
    // equiv-conv: FUN_0025d740 ecx
    // equiv-conv: FUN_0025d780 ecx
// equiv-conv: FUN_00248670 edi esi stack
extern "C" void __cdecl FUN_00248670(void * owner, void * fade, unsigned ticks) {
 if (!((Owner_248670 *)owner)->active) ticks = 0;
 if (((Fade_248670 *)fade)->phase == 0) {
  ((Fade_248670 *)fade)->elapsed += ticks;
  if (((Fade_248670 *)fade)->elapsed >= ((Fade_248670 *)fade)->delay) {
   ((Fade_248670 *)fade)->phase = 1;
   ticks = ((Fade_248670 *)fade)->elapsed - ((Fade_248670 *)fade)->delay;
  }
 }
 if (((Fade_248670 *)fade)->phase == 1) {
  if (((Fade_248670 *)fade)->duration != 0) {
   double step = (double)(int)ticks / (double)(int)((Fade_248670 *)fade)->duration;
   if (step >= 0.1f) step = 0.1f;
   double progress = step + ((Fade_248670 *)fade)->progress;
   ((Fade_248670 *)fade)->progress = (float)progress;
   if (progress >= 1.0f) {
    ((Fade_248670 *)fade)->progress = 1.0f;
    ((Fade_248670 *)fade)->phase = 2;
   }
  } else {
   ((Fade_248670 *)fade)->progress = 1.0f;
   ((Fade_248670 *)fade)->phase = 2;
  }
 }
 ((Fade_248670 *)fade)->sound->volume = (float)sqrt(((Fade_248670 *)fade)->progress);
 unsigned state = ((unsigned)((owners::Object_25d3e0 *)(((Fade_248670 *)fade)->sound))->FUN_0025d3e0());
 switch (state) {
 case 2:
 case 4:
  if (((Fade_248670 *)fade)->phase && ((Owner_248670 *)owner)->active) ((ThisNote_0025d740*)(((Fade_248670 *)fade)->sound))->FUN_0025d740();
  break;
 case 3:
  if (!((Owner_248670 *)owner)->active) ((ThisNote_0025d780*)(((Fade_248670 *)fade)->sound))->FUN_0025d780();
  break;
 case 0:
 case 5:
  ((Fade_248670 *)fade)->result = 5;
  break;
 }
}


// 0x00248780 FUN_00248780 (208 B): equivalent/0x00248780.cpp
// sym: _FUN_00248780
// STATUS: equivalent (tools/equiv.py level 3: 19929 inputs, branch coverage 22/22)
// FUN_00248780 @ 0x00248780
// equiv-conv: FUN_00248780 esi stack
extern "C" void __cdecl FUN_00248780(void * s, unsigned delta) {
 if(((State_248780 *)s)->phase==0) { ((State_248780 *)s)->elapsed+=delta; if(((State_248780 *)s)->elapsed>=((State_248780 *)s)->delay) { delta=((State_248780 *)s)->elapsed-((State_248780 *)s)->delay; ((State_248780 *)s)->phase=1; } }
 if(((State_248780 *)s)->phase==1) {
  hulk_freg duration=(float)(int)((State_248780 *)s)->duration;
  if((int)((State_248780 *)s)->duration<0) duration+=4294967296.0f;
  if(duration>0.0f) {
   hulk_freg amount=(float)(int)delta/(float)(int)((State_248780 *)s)->duration;
   if(!(amount<0.1f)) amount=0.1f;
   hulk_freg result=((State_248780 *)s)->level-amount;
   ((State_248780 *)s)->level=result;
   if(result<=0.0f) { ((State_248780 *)s)->level=0.0f; ((State_248780 *)s)->phase=2; }
  } else { ((State_248780 *)s)->level=0.0f; ((State_248780 *)s)->phase=2; }
 }
 ((State_248780 *)s)->output->value=(float)sqrt(((State_248780 *)s)->level);
 int status=((owners::Object_25d3e0 *)(((State_248780 *)s)->output))->FUN_0025d3e0();
 if(status==0) ((State_248780 *)s)->active=0;
 else if(status>0 && status<=4 && ((State_248780 *)s)->phase==2) ((State_248780 *)s)->output->FUN_0025d3f0(0);
}

} // namespace fn_f9a518a5

// 0x00248ac0 FUN_00248ac0 (178 B): matches/0x00248ac0.cpp [wrapped: conflict: Node]
// sym: _FUN_00248ac0
namespace fn_00248ac0 {
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int data;
};
void* FUN_00247f80(void*, void*);
extern "C++" __declspec(nothrow) void __cdecl FUN_00247fc0(void *, void *);
extern "C" void FUN_00248ac0(void * tree, void * node) {
    Node* nil = (Node*)((char*)((Node *)tree) + 4);
    Node* x;
    if (((Node *)node)->left == nil || ((Node *)node)->right == nil)
        x = ((Node *)node);
    else
        x = (Node*)FUN_00247f80(((Node *)tree), ((Node *)node));
    Node* y;
    if (x->left != nil)
        y = x->left;
    else
        y = x->right;
    y->parent = x->parent;
    if (x->parent == nil)
        ((Node *)tree)->left = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    int flag = (x->data == 0);
    if (x != ((Node *)node)) {
        x->parent = ((Node *)node)->parent;
        x->left = ((Node *)node)->left;
        x->right = ((Node *)node)->right;
        x->data = ((Node *)node)->data;
        if (x->parent != nil) {
            if (x->parent->left == ((Node *)node))
                x->parent->left = x;
            else
                x->parent->right = x;
        } else
            ((Node *)tree)->left = x;
        if (x->left != nil)
            x->left->parent = x;
        if (x->right->parent != nil)
            x->right->parent = x;
    }
    if (flag)
        FUN_00247fc0(((Node *)tree), y);
}
} // namespace fn_00248ac0

namespace fn_f9a518a5 {

// 0x00248bf0 FUN_00248bf0 (75 B): matches/0x00248bf0.cpp
// sym: _FUN_00248bf0
extern "C" N_248bf0* __cdecl FUN_00248bf0(N_248bf0* s, N_248bf0* n) {
    N_248bf0* x = n->l;
    N_248bf0* end = (N_248bf0*)((char*)s + 4);
    if (x != end) {
        while (x->next != end)
            x = x->next;
    } else {
        x = n->r;
        if (x != end) {
            do {
                if (n != x->l)
                    break;
                n = x;
                x = x->r;
            } while (x != end);
        }
    }
    return x == end ? 0 : x;
}

} // namespace fn_f9a518a5

// 0x00248c50 FUN_00248c50 (75 B): equivalent/0x00248c50.cpp [wrapped: merged class would differ: Tree: field sentinel: Field(+0x4 Node sentinel) vs Field(+0x4 Node sentinel)]
// sym: ?FUN_00248c50@fn_00248c50@@YAPAUNode@1@PAUTree@1@PAU21@@Z
namespace fn_00248c50 {
// STATUS: equivalent (tools/equiv.py level 3: 195 inputs, branch coverage 15/16, incomplete)
// FUN_00248c50 @ 0x00248c50
struct Node { Node *left; Node *parent; Node *right; }; struct Tree { Node *root; Node sentinel; }; Node* __cdecl FUN_00248c50(Tree* tree, Node* node) { Node* nil = &tree->sentinel; Node* p = node->parent; if (p != nil) { Node* q = p->left; while (q != nil) { p = q; q = p->left; } return p == nil ? 0 : p; } p = node->right; if (p != nil) { while (node == p->parent) { node = p; p = p->right; if (p == nil) break; } } return p == nil ? 0 : p; }
} // namespace fn_00248c50

namespace fn_f9a518a5 {

// 0x00248d40 FUN_00248d40 (604 B): equivalent/0x00248d40.cpp
// sym: _FUN_00248d40
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00248d40 @ 0x00248d40
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_00248d40(void * tree_, void * x_)
{
    RbTree_248d40 * tree = (RbTree_248d40 *)tree_;
    RbNode_248d40 * x = (RbNode_248d40 *)x_;
    RbNode_248d40* nil = &tree->nil;
    RbNode_248d40* y;
    RbNode_248d40* z;
    RbNode_248d40* p;
    RbNode_248d40* c;

    if (x == tree->root) {
        x->color = 0;
        return;
    }
    while (x->color == 0 /* black */) {
        if (x == x->parent->left) {
            y = x->parent->right;
            if (y->color == 1) {
                y->color = 0;
                x->parent->color = 1;
                p = x->parent;
                z = p->right;
                p->right = z->left;
                if (z->left != nil)
                    z->left->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->left = p;
                p->parent = z;
                y = x->parent->right;
            }
            if (y->left->color == 0 && y->right->color == 0) {
                y->color = 1;
                x = x->parent;
            } else {
                if (y->right->color == 0) {
                    y->left->color = 0;
                    z = y->left;
                    y->color = 1;
                    y->left = z->right;
                    if (z->right != nil)
                        z->right->parent = y;
                    z->parent = y->parent;
                    if (y->parent == nil)
                        tree->root = z;
                    else if (y == y->parent->left)
                        y->parent->left = z;
                    else
                        y->parent->right = z;
                    z->right = y;
                    y->parent = z;
                    y = x->parent->right;
                }
                y->color = x->parent->color;
                x->parent->color = 0;
                y->right->color = 0;
                p = x->parent;
                z = p->right;
                p->right = z->left;
                if (z->left != nil)
                    z->left->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->left = p;
                p->parent = z;
                x = tree->root;
            }
        } else {
            y = x->parent->left;
            if (y->color == 1) {
                y->color = 0;
                x->parent->color = 1;
                p = x->parent;
                z = p->left;
                p->left = z->right;
                if (z->right != nil)
                    z->right->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->right = p;
                p->parent = z;
                y = x->parent->left;
            }
            if (y->right->color == 0 && y->left->color == 0) {
                y->color = 1;
                x = x->parent;
            } else {
                if (y->left->color == 0) {
                    y->right->color = 0;
                    z = y->right;
                    y->color = 1;
                    y->right = z->left;
                    if (z->left != nil)
                        z->left->parent = y;
                    z->parent = y->parent;
                    if (y->parent == nil)
                        tree->root = z;
                    else if (y == y->parent->left)
                        y->parent->left = z;
                    else
                        y->parent->right = z;
                    z->left = y;
                    y->parent = z;
                    y = x->parent->left;
                }
                y->color = x->parent->color;
                x->parent->color = 0;
                y->left->color = 0;
                p = x->parent;
                z = p->left;
                p->left = z->right;
                if (z->right != nil)
                    z->right->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->right = p;
                p->parent = z;
                x = tree->root;
            }
        }
        if (x == tree->root)
            break;
    }
    x->color = 0;
}


// 0x00248fa0 FUN_00248fa0 (604 B): equivalent/0x00248fa0.cpp
// sym: _FUN_00248fa0
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00248fa0 @ 0x00248fa0
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_00248fa0(void * tree_, void * x_)
{
    RbTree_248fa0 * tree = (RbTree_248fa0 *)tree_;
    RbNode_248fa0 * x = (RbNode_248fa0 *)x_;
    RbNode_248fa0* nil = &tree->nil;
    RbNode_248fa0* y;
    RbNode_248fa0* z;
    RbNode_248fa0* p;
    RbNode_248fa0* c;

    if (x == tree->root) {
        x->color = 0;
        return;
    }
    while (x->color == 0 /* black */) {
        if (x == x->parent->left) {
            y = x->parent->right;
            if (y->color == 1) {
                y->color = 0;
                x->parent->color = 1;
                p = x->parent;
                z = p->right;
                p->right = z->left;
                if (z->left != nil)
                    z->left->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->left = p;
                p->parent = z;
                y = x->parent->right;
            }
            if (y->left->color == 0 && y->right->color == 0) {
                y->color = 1;
                x = x->parent;
            } else {
                if (y->right->color == 0) {
                    y->left->color = 0;
                    z = y->left;
                    y->color = 1;
                    y->left = z->right;
                    if (z->right != nil)
                        z->right->parent = y;
                    z->parent = y->parent;
                    if (y->parent == nil)
                        tree->root = z;
                    else if (y == y->parent->left)
                        y->parent->left = z;
                    else
                        y->parent->right = z;
                    z->right = y;
                    y->parent = z;
                    y = x->parent->right;
                }
                y->color = x->parent->color;
                x->parent->color = 0;
                y->right->color = 0;
                p = x->parent;
                z = p->right;
                p->right = z->left;
                if (z->left != nil)
                    z->left->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->left = p;
                p->parent = z;
                x = tree->root;
            }
        } else {
            y = x->parent->left;
            if (y->color == 1) {
                y->color = 0;
                x->parent->color = 1;
                p = x->parent;
                z = p->left;
                p->left = z->right;
                if (z->right != nil)
                    z->right->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->right = p;
                p->parent = z;
                y = x->parent->left;
            }
            if (y->right->color == 0 && y->left->color == 0) {
                y->color = 1;
                x = x->parent;
            } else {
                if (y->left->color == 0) {
                    y->right->color = 0;
                    z = y->right;
                    y->color = 1;
                    y->right = z->left;
                    if (z->left != nil)
                        z->left->parent = y;
                    z->parent = y->parent;
                    if (y->parent == nil)
                        tree->root = z;
                    else if (y == y->parent->left)
                        y->parent->left = z;
                    else
                        y->parent->right = z;
                    z->left = y;
                    y->parent = z;
                    y = x->parent->left;
                }
                y->color = x->parent->color;
                x->parent->color = 0;
                y->left->color = 0;
                p = x->parent;
                z = p->left;
                p->left = z->right;
                if (z->right != nil)
                    z->right->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->right = p;
                p->parent = z;
                x = tree->root;
            }
        }
        if (x == tree->root)
            break;
    }
    x->color = 0;
}


// 0x00249200 FUN_00249200 (604 B): equivalent/0x00249200.cpp
// sym: _FUN_00249200
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_00249200 @ 0x00249200
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_00249200(void * tree_, void * x_)
{
    RbTree_249200 * tree = (RbTree_249200 *)tree_;
    RbNode_249200 * x = (RbNode_249200 *)x_;
    RbNode_249200* nil = &tree->nil;
    RbNode_249200* y;
    RbNode_249200* z;
    RbNode_249200* p;
    RbNode_249200* c;

    if (x == tree->root) {
        x->color = 0;
        return;
    }
    while (x->color == 0 /* black */) {
        if (x == x->parent->left) {
            y = x->parent->right;
            if (y->color == 1) {
                y->color = 0;
                x->parent->color = 1;
                p = x->parent;
                z = p->right;
                p->right = z->left;
                if (z->left != nil)
                    z->left->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->left = p;
                p->parent = z;
                y = x->parent->right;
            }
            if (y->left->color == 0 && y->right->color == 0) {
                y->color = 1;
                x = x->parent;
            } else {
                if (y->right->color == 0) {
                    y->left->color = 0;
                    z = y->left;
                    y->color = 1;
                    y->left = z->right;
                    if (z->right != nil)
                        z->right->parent = y;
                    z->parent = y->parent;
                    if (y->parent == nil)
                        tree->root = z;
                    else if (y == y->parent->left)
                        y->parent->left = z;
                    else
                        y->parent->right = z;
                    z->right = y;
                    y->parent = z;
                    y = x->parent->right;
                }
                y->color = x->parent->color;
                x->parent->color = 0;
                y->right->color = 0;
                p = x->parent;
                z = p->right;
                p->right = z->left;
                if (z->left != nil)
                    z->left->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->left = p;
                p->parent = z;
                x = tree->root;
            }
        } else {
            y = x->parent->left;
            if (y->color == 1) {
                y->color = 0;
                x->parent->color = 1;
                p = x->parent;
                z = p->left;
                p->left = z->right;
                if (z->right != nil)
                    z->right->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->right = p;
                p->parent = z;
                y = x->parent->left;
            }
            if (y->right->color == 0 && y->left->color == 0) {
                y->color = 1;
                x = x->parent;
            } else {
                if (y->left->color == 0) {
                    y->right->color = 0;
                    z = y->right;
                    y->color = 1;
                    y->right = z->left;
                    if (z->left != nil)
                        z->left->parent = y;
                    z->parent = y->parent;
                    if (y->parent == nil)
                        tree->root = z;
                    else if (y == y->parent->left)
                        y->parent->left = z;
                    else
                        y->parent->right = z;
                    z->left = y;
                    y->parent = z;
                    y = x->parent->left;
                }
                y->color = x->parent->color;
                x->parent->color = 0;
                y->left->color = 0;
                p = x->parent;
                z = p->left;
                p->left = z->right;
                if (z->right != nil)
                    z->right->parent = p;
                z->parent = p->parent;
                if (p->parent == nil)
                    tree->root = z;
                else if (p == p->parent->left)
                    p->parent->left = z;
                else
                    p->parent->right = z;
                z->right = p;
                p->parent = z;
                x = tree->root;
            }
        }
        if (x == tree->root)
            break;
    }
    x->color = 0;
}


// 0x002495c0 FUN_002495c0 (32 B): matches/0x002495c0.cpp
// sym: _FUN_002495c0
extern "C" Node* __cdecl FUN_002495c0(Node* p) {
    Node* end = (Node*)((char*)p + 0x1c);
    Node* cur = *(Node**)((char*)p + 0x18);
    if (cur == end)
        return 0;
    while (cur->next != end)
        cur = cur->next;
    return cur;
}

} // namespace fn_f9a518a5

// 0x002495e0 FUN_002495e0 (16 B): equivalent/0x002495e0.cpp [wrapped: conflict: FUN_00248bf0]
// sym: ?FUN_002495e0@fn_002495e0@@YAHPAUObject@1@PAX@Z
namespace fn_002495e0 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_002495e0 @ 0x002495e0
struct Object { char pad[24]; char data; };
int __cdecl FUN_00248bf0(void *, void *);
hulk_intptr __cdecl FUN_002495e0(Object *object, void *other) {
    return FUN_00248bf0(&object->data, other);
}
} // namespace fn_002495e0

namespace fn_f9a518a5 {

// 0x002495f0 FUN_002495f0 (8 B): matches/0x002495f0.cpp
// sym: _FUN_002495f0
extern "C" hulk_uintptr __cdecl FUN_002495f0(A_2495f0* p) {
    return p->value;
}


// 0x00249600 FUN_00249600 (7 B): matches/0x00249600.cpp
// sym: _FUN_00249600
extern "C" u32_249600 __cdecl FUN_00249600(u32_249600 unused, u32_249600* value) {
    return *value;
}


// 0x00249610 FUN_00249610 (23 B): matches/0x00249610.cpp
// sym: _FUN_00249610
extern "C" int __cdecl FUN_00249610(void* unused, void* p) {
    volatile char* q = *(char**)((char*)p + 8);
    q += 0x40;
    u32_249610 x = *(volatile u32_249610*)q;
    return x ? (int)x - 4 : 0;
}


// 0x00249630 FUN_00249630 (232 B): equivalent/0x00249630.cpp
// sym: ?target@fn_f9a518a5@@YAXPAUObject@1@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_00249630 @ 0x00249630
// equiv-conv: target edi stack
void __cdecl target(Object* self, hulk_intptr delta) {
 if(self->state == 1 || self->state == 3) {
  double step = (double)delta / self->duration;
  if (step >= 0.1f) step = 0.1f;
  if(self->state == 1) {
   double a = (double)self->amount - step;
   self->amount = (float)a;
   if(a <= 0.0f) { self->amount=0.0f; self->state=0; }
  } else {
   double a = (double)self->amount + step;
   self->amount=(float)a;
   if(a >= 1.0f) { self->amount=1.0f; self->state=2; }
  }
 }
 float scale = self->amount * self->scale;
 float base = self->base;
 int key = self->key;
 for(Node* n=self->nodes; n; n=n->next) {
  scale = FUN_00241700(key,n->value) * scale;
  base = FUN_00241710(key,n->value) * base;
 }
 self->outputScale=scale;
 self->outputBase=base;
}

} // namespace fn_f9a518a5

// 0x00249750 FUN_00249750 (143 B): equivalent/0x00249750.cpp [wrapped: conflict: FUN_00247550]
// sym: ?FUN_00249750@fn_00249750@@YAHPAUNode@1@@Z
namespace fn_00249750 {
// STATUS: equivalent (tools/equiv.py level 3: 171 inputs, branch coverage 14/14)
// FUN_00249750 @ 0x00249750
// FUN_00249750 @ 0x00249750

struct Node;
struct Owner_249750 { char pad[16]; Node* head; Node* tail; int count; };
struct Link_249750 { Link_249750* next; Link_249750* prev; };
struct ListOwner_249750 { char pad[72]; Link_249750* head; Link_249750* tail; };
struct Payload_249750 { void FUN_0025def0(); };
extern void* __cdecl FUN_0025d3d0(Payload_249750*);
extern int __cdecl FUN_00247550(void*, void*);
struct Node { Node* next; Owner_249750* owner; Payload_249750* payload; char pad[36]; ListOwner_249750* list; Link_249750* forward; Link_249750* backward; };
// equiv-conv: FUN_00249750 esi
int FUN_00249750(Node* node) {
 --node->owner->count;
 Owner_249750* owner = node->owner;
 Node* previous = 0;
 Node* cursor = owner->head;
 while(cursor != node) { previous = cursor; cursor = cursor->next; }
 if(previous) previous->next = node->next;
 else owner->head = node->next;
 if(!node->next) owner->tail = previous;
 ListOwner_249750* list = node->list;
 if(!node->backward) list->head = node->forward;
 else node->backward->next = node->forward;
 if(!node->forward) list->tail = node->backward;
 else node->forward->prev = node->backward;
 Payload_249750* payload = node->payload;
 if(payload) {
  payload->FUN_0025def0();
  void* pool = FUN_0025d3d0(payload);
  FUN_00247550(pool,payload);
 }
 return FUN_00247550(((char*)((char*)&DAT_004e6038)),node);
}
} // namespace fn_00249750

namespace fn_f9a518a5 {

// 0x002497e0 FUN_002497e0 (41 B): equivalent/0x002497e0.cpp
// sym: _FUN_002497e0
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 6/6)
// FUN_002497e0 @ 0x002497e0
// FUN_002497e0 @ 0x002497e0
// equiv-conv: FUN_00249750 esi
extern "C" unsigned short __cdecl FUN_002497e0(Item* item) { --item->count; if (item->count != 0) return item->count; if (item->link != 0) return (unsigned short)(hulk_uintptr)item->link; Owner* owner = item->owner; Flags* flags = owner->flags; if (flags->bits & 2) return (unsigned short)(hulk_uintptr)owner; unsigned short result = (unsigned short)FUN_00249750(item); volatile unsigned short saved = result; return saved; }

} // namespace fn_f9a518a5

// 0x00249810 FUN_00249810 (182 B): equivalent/0x00249810.cpp [wrapped: conflict: Node]
// sym: _FUN_00249810
namespace fn_00249810 {
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 22/22)
// FUN_00249810 @ 0x00249810

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

struct Payload_249810 { float value;  void FUN_0025dfc0(int, unsigned int); };
struct Node;
struct Link_249810 { Link_249810* next; };
struct List_249810 { char pad[0x48]; Link_249810* first; };
struct Node { char pad0[8]; Payload_249810* payload; int state; unsigned char flag; char pad11[3]; int field14; char pad18[12]; float value; int field28; char pad2c[4]; List_249810* list; Link_249810 link; };
extern "C" void __cdecl FUN_00247b30(int, Node*, int, int*);
// equiv-conv: FUN_00249810 esi stack
extern "C" void FUN_00249810(void * self, int argument) {
 int status=((owners::Object_25d3e0 *)(((Node *)self)->payload))->FUN_0025d3e0();
 if(status==3) { ((Node *)self)->state=4; ((Node *)self)->value=1.0f; ((Node *)self)->field28=2; return; }
 if(status==2) { ((Node *)self)->state=2; return; }
 if(status!=0) return;
 int result=0;
 if(((Node *)self)->field14==0) {
  Link_249810* link=((Node *)self)->list->first;
  while(link) {
   Node* node=reinterpret_cast<Node*>(reinterpret_cast<char*>(link)-0x34);
   if(node!=((Node *)self) && node->state!=0 && node->state!=5) { FUN_00247b30(argument,node,0,&result); break; }
   link=node->link.next;
  }
 }
 ((Node *)self)->payload->value=(float)sqrt(((Node *)self)->value);
 ((Node *)self)->payload->FUN_0025dfc0(result,((Node *)self)->flag);
}
} // namespace fn_00249810

namespace fn_f9a518a5 {

// 0x002498d0 FUN_002498d0 (234 B): equivalent/0x002498d0.cpp
// sym: ?run@fn_f9a518a5@@YAXPAUItem_2498d0@1@@Z
// STATUS: equivalent (tools/equiv.py level 3: 2983 inputs, branch coverage 32/32)
// FUN_002498d0 @ 0x002498d0
// equiv-conv: run ebx
void run(Item_2498d0* self) {
 for (;;) {
  int old=((owners::Object_25d3e0 *)(self->voice))->FUN_0025d3e0();
  if(old==0) {
   unsigned result=0;
   if(self->blocked==0) {
    Link_2498d0* p=self->list->head;
    while(p) {
     Item_2498d0* item=reinterpret_cast<Item_2498d0*>(reinterpret_cast<char*>(p)-0x34);
     if(item!=self && item->state!=0 && item->state!=5) {
      item->state=5; item->a=0; item->b=0; item->d=0; item->c=0;
      int status=((owners::Object_25d3e0 *)(item->voice))->FUN_0025d3e0();
      if(status>=1 && status<=4) ((owners::Obj_25d3f0 *)(item->voice))->FUN_0025d3f0((int *)(&result));
      else result=0;
      break;
     }
     p=item->link.next;
    }
   }
   self->voice->value=(float)sqrt(self->magnitude);
   self->voice->FUN_0025dfc0(result,self->flag);
  } else if(old>1 && old<=4) self->state=4;
  if(old==((owners::Object_25d3e0 *)(self->voice))->FUN_0025d3e0()) break;
 }
}

} // namespace fn_f9a518a5

// 0x00249a90 FUN_00249a90 (168 B): equivalent/0x00249a90.cpp [wrapped: conflict: Node]
// sym: _FUN_00249a90
namespace fn_00249a90 {
// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 31/32, incomplete)
// FUN_00249a90 @ 0x00249a90
struct Item_249a90 {
    Item_249a90* next;
    char pad04[8];
    unsigned state;
    char pad10[8];
    unsigned value0;
    unsigned value1;
    unsigned field20;
    unsigned field24;
    unsigned field28;
};
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    unsigned field0c;
    Item_249a90* items;
};
struct Tree_249a90 {
    char pad00[0x18];
    Node* root;
    Node sentinel;
};
struct Values_249a90 { unsigned first; unsigned second; };
extern "C" void __cdecl FUN_00249a90(Tree_249a90* tree, const Values_249a90* values) {
    Node* end = &tree->sentinel;
    Node* node = tree->root;
    if (node == end) return;
    while (node->left != end) node = node->left;
    for (;;) {
        for (Item_249a90* item = node->items; item != 0; item = item->next) {
            if (item->state != 0 && item->state != 5) {
                item->state = 5;
                if (values) {
                    item->value0 = values->first;
                    item->value1 = values->second;
                } else {
                    item->value0 = 0;
                    item->value1 = 0;
                }
                item->field28 = 0;
                item->field20 = 0;
            }
        }
        if (node->right != end) {
            node = node->right;
            while (node->left != end) node = node->left;
        } else {
            Node* parent = node->parent;
            if (parent == end) return;
            while (node == parent->right) {
                node = parent;
                parent = parent->parent;
                if (parent == end) return;
            }
            node = parent;
        }
        if (node == end || node == 0) return;
    }
}
} // namespace fn_00249a90

namespace fn_f9a518a5 {

// 0x00249b40 FUN_00249b40 (132 B): equivalent/0x00249b40.cpp
// sym: _FUN_00249b40
// STATUS: equivalent (tools/equiv.py level 3: 115 inputs, branch coverage 29/30, incomplete)
// FUN_00249b40 @ 0x00249b40
extern "C" int FUN_00249b40(Tree_249b40 *tree)
{
    TreeNode_249b40 *end = &tree->nil;
    char found = 0;
    TreeNode_249b40 *cur = tree->root;
    if (cur != end) {
        while (cur->left != end)
            cur = cur->left;
        do {
            for (Entry_249b40 *e = cur->entries; e != 0; e = e->next) {
                if (e->value != 0)
                    found = 1;
            }
            TreeNode_249b40 *next = cur->right;
            if (next != end) {
                while (next->left != end)
                    next = next->left;
            } else {
                TreeNode_249b40 *from = cur;
                next = cur->parent;
                if (next != end) {
                    while (from == next->right) {
                        from = next;
                        next = next->parent;
                        if (next == end)
                            break;
                    }
                }
            }
            cur = next;
        } while (cur != end && cur != 0);
    }
    return found == 0;
}


// 0x00249bd0 FUN_00249bd0 (77 B): equivalent/0x00249bd0.cpp
// sym: _FUN_00249bd0
// STATUS: equivalent (tools/equiv.py level 3: 2984 inputs, branch coverage 8/8)
// FUN_00249bd0 @ 0x00249bd0
extern "C" void __cdecl FUN_00249bd0(hulk_intptr unused, Container *container, Pair *pair) { Node *node = container->head; while (node && (node->state == 5 || node->state == 0)) node = node->next; if (!node) return; node->state = 5; if (pair) { node->value0 = pair->first; node->value1 = pair->second; } else { node->value0 = 0; node->value1 = 0; } node->finalValue = 0; node->other = 0; }

} // namespace fn_f9a518a5

// 0x00249c20 FUN_00249c20 (182 B): equivalent/0x00249c20.cpp [wrapped: conflict: Node]
// sym: _FUN_00249c20
namespace fn_00249c20 {
// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_00249c20 @ 0x00249c20
struct Node { Node *left; Node *right; Node *parent; int color; };
struct Tree_249c20 { Node *root; Node sentinel; };
struct Entry_249c20 { int value; Node node; };
extern Node* __cdecl FUN_00247d10(Tree_249c20*,Node*);
extern "C++" __declspec(nothrow) void __cdecl FUN_00248d40(void *, void *);
extern "C" void __cdecl FUN_00249c20(void * tree_, void * entry_) {
    Tree_249c20 * tree = (Tree_249c20 *)tree_;
    Entry_249c20 * entry = (Entry_249c20 *)entry_;
    Node* node = &entry->node;
    Node* nil = &tree->sentinel;
    Node* removed;
    if (node->left != nil && node->right != nil)
        removed = FUN_00247d10(tree,node);
    else
        removed = node;
    Node* child = removed->left;
    if (child == nil) child = removed->right;
    child->parent = removed->parent;
    Node* parent = removed->parent;
    if (parent == nil) tree->root = child;
    else if (parent->left == removed) parent->left = child;
    else parent->right = child;
    bool rebalance = removed->color == 0;
    if (removed != node) {
        removed->parent = node->parent;
        removed->left = node->left;
        removed->right = node->right;
        removed->color = node->color;
        parent = removed->parent;
        if (parent != nil) {
            if (parent->left == node) parent->left = removed;
            else parent->right = removed;
        } else tree->root = removed;
        if (removed->left != nil) removed->left->parent = removed;
        if (removed->right->parent != nil) removed->right->parent = removed;
    }
    if (rebalance) FUN_00248d40((Tree_249c20 *)tree,(Node *)child);
}
} // namespace fn_00249c20


// 0x00249ce0 FUN_00249ce0 (467 B): equivalent/0x00249ce0.cpp [wrapped: conflict: Node]
// sym: ?FUN_00249ce0@fn_00249ce0@@YADPAUTree_249ce0@1@PAUNode@1@PBI@Z
namespace fn_00249ce0 {
// STATUS: equivalent (tools/equiv.py level 3: 178 inputs, branch coverage 35/40, incomplete)
// FUN_00249ce0 @ 0x00249ce0
struct Payload_249ce0 {
    char pad[0x38];
    unsigned key;
};

struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    char pad10[0x1c - 0x10];
    Payload_249ce0* payload;
};

struct Tree_249ce0 {
    Node* root;
    Node nil;
};

extern "C" void FUN_00247eb0(Tree_249ce0* tree, Node* node);
extern "C" void FUN_00247f00(Tree_249ce0* tree, Node* node);

// Red-black tree unique-key insert with rebalance. color: 1 = red, 0 = black.
char FUN_00249ce0(Tree_249ce0* tree, Node* nodeArg, const unsigned* keyPtr)
{
    Node* nil = &tree->nil;
    Node* node = nodeArg;
    unsigned key = *keyPtr;
    Node* cur = tree->root;
    Node* parent = nil;

    while (cur != nil) {
        parent = cur;
        if (key < cur->payload->key) {
            cur = cur->left;
        } else if (key == cur->payload->key) {
            return 0;
        } else {
            cur = cur->right;
        }
    }

    node->parent = parent;
    if (parent == nil) {
        tree->root = node;
    } else if (*keyPtr < parent->payload->key) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    node->left = nil;
    node->right = nil;
    node->color = 1;

    while (node != tree->root && node->parent->color == 1) {
        Node* p = node->parent;
        Node* g = p->parent;
        if (p == g->left) {
            Node* uncle = g->right;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                g->color = 1;
                node = g;
            } else {
                if (node == p->right) {
                    node = p;
                    FUN_00247eb0(tree, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                Node* gg = node->parent->parent;
                Node* pv = gg->left;
                gg->left = pv->right;
                if (pv->right != nil)
                    pv->right->parent = gg;
                pv->parent = gg->parent;
                Node* gp = gg->parent;
                if (gp == nil) {
                    tree->root = pv;
                } else if (gg == gp->left) {
                    gp->left = pv;
                } else {
                    gp->right = pv;
                }
                pv->right = gg;
                gg->parent = pv;
            }
        } else {
            Node* uncle = g->left;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                g->color = 1;
                node = g;
            } else {
                if (node == p->left) {
                    node = p;
                    FUN_00247f00(tree, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                Node* gg = node->parent->parent;
                Node* pv = gg->right;
                gg->right = pv->left;
                if (pv->left != nil)
                    pv->left->parent = gg;
                pv->parent = gg->parent;
                Node* gp = gg->parent;
                if (gp == nil) {
                    tree->root = pv;
                } else if (gg == gp->left) {
                    gp->left = pv;
                } else {
                    gp->right = pv;
                }
                pv->left = gg;
                gg->parent = pv;
            }
        }
    }
    tree->root->color = 0;
    return 1;
}
} // namespace fn_00249ce0


// 0x00249ec0 FUN_00249ec0 (178 B): matches/0x00249ec0.cpp [wrapped: conflict: Node]
// sym: _FUN_00249ec0
namespace fn_00249ec0 {
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int data;
};
void* FUN_00248240(void*, void*);
extern "C++" __declspec(nothrow) void __cdecl FUN_00248fa0(void *, void *);
extern "C" void FUN_00249ec0(void * tree, void * node) {
    Node* nil = (Node*)((char*)((Node *)tree) + 4);
    Node* x;
    if (((Node *)node)->left == nil || ((Node *)node)->right == nil)
        x = ((Node *)node);
    else
        x = (Node*)FUN_00248240(((Node *)tree), ((Node *)node));
    Node* y;
    if (x->left != nil)
        y = x->left;
    else
        y = x->right;
    y->parent = x->parent;
    if (x->parent == nil)
        ((Node *)tree)->left = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    int flag = (x->data == 0);
    if (x != ((Node *)node)) {
        x->parent = ((Node *)node)->parent;
        x->left = ((Node *)node)->left;
        x->right = ((Node *)node)->right;
        x->data = ((Node *)node)->data;
        if (x->parent != nil) {
            if (x->parent->left == ((Node *)node))
                x->parent->left = x;
            else
                x->parent->right = x;
        } else
            ((Node *)tree)->left = x;
        if (x->left != nil)
            x->left->parent = x;
        if (x->right->parent != nil)
            x->right->parent = x;
    }
    if (flag)
        FUN_00248fa0(((Node *)tree), y);
}
} // namespace fn_00249ec0


// 0x00249f80 FUN_00249f80 (49 B): equivalent/0x00249f80.cpp [wrapped: conflict: Tree]
// sym: _FUN_00249f80
namespace fn_00249f80 {
// STATUS: equivalent (tools/equiv.py level 3: 731 inputs, branch coverage 8/8)
// FUN_00249f80 @ 0x00249f80
struct Entry { Entry* left; Entry* right; char pad[0x14]; struct Data* data; }; struct Data { char pad[0x38]; unsigned key; }; struct Tree { Entry* root; Entry sentinel; }; extern "C" void * __cdecl FUN_00249f80(void * tree_, const unsigned* key) {
    Tree * tree = (Tree *)tree_; Entry* node=tree->root; Entry* end=&tree->sentinel; while(node!=end) { unsigned value=node->data->key; if(*key<value) node=node->left; else if(*key==value) return (Entry *)node; else node=node->right; } return (Entry *)0; }
} // namespace fn_00249f80


// 0x00249fc0 FUN_00249fc0 (44 B): equivalent/0x00249fc0.cpp [wrapped: conflict: Node]
// sym: _FUN_00249fc0
namespace fn_00249fc0 {
// STATUS: equivalent (tools/equiv.py level 3: 702 inputs, branch coverage 8/8)
// FUN_00249fc0 @ 0x00249fc0
struct Node { Node *left; Node *right; char pad[8]; unsigned int key; }; struct Tree { Node *root; Node sentinel; }; extern "C" void *__cdecl FUN_00249fc0(void * tree_, const unsigned int *key) {
    Tree * tree = (Tree *)tree_; Node *node = tree->root; Node *end = &tree->sentinel; while (node != end) { if (*key < node->key) node = node->left; else if (*key == node->key) return (Node *)node; else node = node->right; } return (Node *)0; }
} // namespace fn_00249fc0


// 0x00249ff0 FUN_00249ff0 (451 B): equivalent/0x00249ff0.cpp [wrapped: conflict: Node]
// sym: _FUN_00249ff0
namespace fn_00249ff0 {
// STATUS: equivalent (tools/equiv.py level 3: 181 inputs, branch coverage 37/40, incomplete)
// FUN_00249ff0 @ 0x00249ff0
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    unsigned key;
};

struct Tree_249ff0 {
    Node* root;
    Node nil;
};

extern "C++" __declspec(nothrow) void __cdecl FUN_002482a0(void *, void *);
extern "C" void FUN_002482f0(Tree_249ff0* tree, Node* node);

// Red-black tree unique-key insert with rebalance. color: 1 = red, 0 = black.
extern "C" char FUN_00249ff0(void * tree_, void * nodeArg, const unsigned* keyPtr)
{
    Tree_249ff0 * tree = (Tree_249ff0 *)tree_;
    Node* nil = &tree->nil;
    Node* node = ((Node *)nodeArg);
    unsigned key = *keyPtr;
    Node* cur = tree->root;
    Node* parent = nil;

    while (cur != nil) {
        parent = cur;
        if (key < cur->key) {
            cur = cur->left;
        } else if (key == cur->key) {
            return 0;
        } else {
            cur = cur->right;
        }
    }

    node->parent = parent;
    if (parent == nil) {
        tree->root = node;
    } else if (*keyPtr < parent->key) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    node->left = nil;
    node->right = nil;
    node->color = 1;

    while (node != tree->root && node->parent->color == 1) {
        Node* p = node->parent;
        Node* g = p->parent;
        if (p == g->left) {
            Node* uncle = g->right;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                g->color = 1;
                node = g;
            } else {
                if (node == p->right) {
                    node = p;
                    FUN_002482a0((Tree_249ff0 *)tree, (Node *)node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                Node* gg = node->parent->parent;
                Node* pv = gg->left;
                gg->left = pv->right;
                if (pv->right != nil)
                    pv->right->parent = gg;
                pv->parent = gg->parent;
                Node* gp = gg->parent;
                if (gp == nil) {
                    tree->root = pv;
                } else if (gg == gp->left) {
                    gp->left = pv;
                } else {
                    gp->right = pv;
                }
                pv->right = gg;
                gg->parent = pv;
            }
        } else {
            Node* uncle = g->left;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                g->color = 1;
                node = g;
            } else {
                if (node == p->left) {
                    node = p;
                    FUN_002482f0(tree, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                Node* gg = node->parent->parent;
                Node* pv = gg->right;
                gg->right = pv->left;
                if (pv->left != nil)
                    pv->left->parent = gg;
                pv->parent = gg->parent;
                Node* gp = gg->parent;
                if (gp == nil) {
                    tree->root = pv;
                } else if (gg == gp->left) {
                    gp->left = pv;
                } else {
                    gp->right = pv;
                }
                pv->left = gg;
                gg->parent = pv;
            }
        }
    }
    tree->root->color = 0;
    return 1;
}
} // namespace fn_00249ff0


// 0x0024a1c0 FUN_0024a1c0 (182 B): equivalent/0x0024a1c0.cpp [wrapped: conflict: Node]
// sym: _FUN_0024a1c0
namespace fn_0024a1c0 {
// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_0024a1c0 @ 0x0024a1c0
struct Node { Node* left; Node* right; Node* parent; int color; };
struct Tree_24a1c0 { Node* root; Node sentinel; };
struct Entry_24a1c0 { int data; Node node; };
Node* __cdecl FUN_00248370(Tree_24a1c0*, Node*);
extern "C++" __declspec(nothrow) void __cdecl FUN_00249200(void *, void *);
extern "C" void __cdecl FUN_0024a1c0(void * tree_, void * entry_) {
    Tree_24a1c0 * tree = (Tree_24a1c0 *)tree_;
    Entry_24a1c0 * entry = (Entry_24a1c0 *)entry_;
    Node* target = &entry->node;
    Node* nil = &tree->sentinel;
    Node* removed;
    if (target->left != nil && target->right != nil)
        removed = FUN_00248370(tree, target);
    else removed = target;
    Node* replacement = removed->left;
    if (replacement == nil) replacement = removed->right;
    replacement->parent = removed->parent;
    Node* parent = removed->parent;
    if (parent == nil) tree->root = replacement;
    else if (parent->left == removed) parent->left = replacement;
    else parent->right = replacement;
    bool fix = removed->color == 0;
    if (removed != target) {
        removed->parent = target->parent;
        removed->left = target->left;
        removed->right = target->right;
        removed->color = target->color;
        parent = removed->parent;
        if (parent == nil) tree->root = removed;
        else if (parent->left == target) parent->left = removed;
        else parent->right = removed;
        if (removed->left != nil) removed->left->parent = removed;
        if (removed->right->parent != nil) removed->right->parent = removed;
    }
    if (fix) FUN_00249200((Tree_24a1c0 *)tree, (Node *)replacement);
}
} // namespace fn_0024a1c0


// 0x0024a280 FUN_0024a280 (227 B): equivalent/0x0024a280.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_0024a280@Owner_24a280@fn_0024a280@@QAEXH@Z
namespace fn_0024a280 {
// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 41/42, incomplete)
// FUN_0024a280 @ 0x0024a280
struct Node {
    Node *left;
    Node *right;
    Node *parent;
};

struct Tree_24a280 {
    Node *root;
    Node nil;
};

class Owner_24a280;

// An entry is an object whose tree node sits at offset 4, right after the vptr.
class Entry_24a280 {
public:
    virtual ~Entry_24a280() throw();
    virtual bool vfunc_1(Owner_24a280 *owner, int arg);
    Node node;
};

extern "C++" __declspec(nothrow) void __cdecl FUN_00249c20(void *, void *);

static Entry_24a280 *EntryOf(Node *n)
{
    return (Entry_24a280 *)((char *)n - 4);
}

class Owner_24a280 {
public:
    char pad00[0x14];
    Tree_24a280 tree;

    void FUN_0024a280(int arg);
};

// Calls every entry's callback in tree order and removes and deletes the ones that return true.
void Owner_24a280::FUN_0024a280(int arg)
{
    Node *nil = &tree.nil;
    Node *n = tree.root;
    if (n == nil)
        return;
    while (n->left != nil)
        n = n->left;
    Entry_24a280 *e = EntryOf(n);
    if (!e)
        return;
    do {
        bool remove = e->vfunc_1(this, arg);

        // in-order successor of e->node
        Node *cur = &e->node;
        Node *next = cur->right;
        if (next == nil) {
            next = cur->parent;
            while (next != nil && cur == next->right) {
                cur = next;
                next = next->parent;
            }
        } else {
            while (next->left != nil)
                next = next->left;
        }
        Entry_24a280 *following = next == nil ? 0 : EntryOf(next);

        if (remove) {
            FUN_00249c20((Tree_24a280 *)(&tree), (Entry_24a280 *)e);
            if (e)
                delete e;
        }
        e = following;
    } while (e);
}
} // namespace fn_0024a280


// 0x0024a370 FUN_0024a370 (16 B): equivalent/0x0024a370.cpp [wrapped: conflict: Object]
// sym: _FUN_0024a370
namespace fn_0024a370 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_0024a370 @ 0x0024a370
struct Object { char padding[24]; };
extern "C++" __declspec(nothrow) void * __cdecl FUN_00249f80(void *, const unsigned *);
extern "C" void* __cdecl FUN_0024a370(Object* object, const unsigned int* key) {
    return FUN_00249f80(&object->padding[24], (const unsigned *)(const unsigned int *)key);
}
} // namespace fn_0024a370


// 0x0024a390 FUN_0024a390 (45 B): equivalent/0x0024a390.cpp [wrapped: conflict: Node; Tree]
// sym: _FUN_0024a390
namespace fn_0024a390 {
// STATUS: equivalent (tools/equiv.py level 3: 700 inputs, branch coverage 8/8)
// FUN_0024a390 @ 0x0024a390
struct Node { Node* left; Node* right; char pad[8]; unsigned int key; }; struct Tree { char pad[0x48]; Node* root; Node sentinel; }; extern "C" Node* __cdecl FUN_0024a390(Tree* tree, const unsigned int* key) { Node* node = tree->root; Node* end = &tree->sentinel; while (node != end) { if (*key < node->key) node = node->left; else if (*key == node->key) return node; else node = node->right; } return 0; }
} // namespace fn_0024a390

namespace fn_f9a518a5 {

// 0x0024a3c0 FUN_0024a3c0 (115 B): equivalent/0x0024a3c0.cpp
// sym: ?FUN_0024a3c0@fn_f9a518a5@@YA_NPAUObj_24a3c0@1@HHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2612 inputs, branch coverage 11/11)
// FUN_0024a3c0 @ 0x0024a3c0
// FUN_0024a3c0 @ 0x0024a3c0
// equiv-conv: FUN_00249810 esi stack
// equiv-conv: FUN_002498d0 ebx
// equiv-conv: FUN_00248670 edi esi stack
// equiv-conv: FUN_00248780 esi stack
// equiv-conv: FUN_0024a3c0 eax ecx stack stack
bool FUN_0024a3c0(Obj_24a3c0 *o, int x, int unused, int a)
{
    int s;
    do {
        s = o->state;
        switch (s) {
        case 1:
            FUN_00249810((Obj_24a3c0 *)o, x);
            break;
        case 3:
            FUN_002498d0(o);
            break;
        case 4:
            FUN_00248670((void *)(hulk_uintptr)(int)x, (Obj_24a3c0 *)o, (int)a);
            break;
        case 5:
            FUN_00248780((Obj_24a3c0 *)o, (int)a);
            break;
        }
        o->link->FUN_0025dd00(a);
    } while (s != o->state);
    return o->state == 0;
}

} // namespace fn_f9a518a5

// 0x0024a450 FUN_0024a450 (71 B): equivalent/0x0024a450.cpp [wrapped: conflict: Node]
// sym: _FUN_0024a450
namespace fn_0024a450 {
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 7/8, incomplete)
// FUN_0024a450 @ 0x0024a450
struct Link { Link* next; }; struct Node { virtual void destroy(unsigned int); Link link; }; struct List { Link* first; Link sentinel; }; extern "C++" __declspec(nothrow) void __cdecl FUN_00249c20(void *, void *); extern "C" void __cdecl FUN_0024a450(void * list_) {
    List * list = (List *)list_; Link* end = &list->sentinel; while (list->first != end) { Link* cur = list->first; while (cur->next != end) cur = cur->next; Node* node = (Node*)((char*)cur - 4); if (!node) break; FUN_00249c20((List *)list,(Node *)node); node->destroy(1); } }
} // namespace fn_0024a450


// 0x0024a4a0 FUN_0024a4a0 (71 B): equivalent/0x0024a4a0.cpp [wrapped: conflict: List; Node]
// sym: _FUN_0024a4a0
namespace fn_0024a4a0 {
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 8/8)
// FUN_0024a4a0 @ 0x0024a4a0
struct Link { Link* next; };
struct Node {
    virtual void FUN_0024a450(int);
    Link link;
};
struct List {
    Link* first;
    Link end;
};
extern "C++" __declspec(nothrow) void __cdecl FUN_0024a1c0(void *, void *);
extern "C" void __cdecl FUN_0024a4a0(void * list_) {
    List * list = (List *)list_;
    while (list->first != &list->end) {
        Link* last = list->first;
        while (last->next != &list->end)
            last = last->next;
        Node* node = reinterpret_cast<Node*>(reinterpret_cast<char*>(last) - 4);
        if (!node) break;
        FUN_0024a1c0((List *)list, (Node *)node);
        node->FUN_0024a450(1);
    }
}
} // namespace fn_0024a4a0

namespace fn_f9a518a5 {

// 0x0024a4f0 FUN_0024a4f0 (23 B): matches/0x0024a4f0.cpp
// sym: ?FUN_0024a4f0@fn_f9a518a5@@YIXPAUObj_24a4f0@1@@Z
void __fastcall FUN_0024a4f0(Obj_24a4f0* self) {
    FUN_0024a450((char*)self + 0x14);
    FUN_0024a4a0((Obj_24a4f0 *)self);
}


// 0x0024a510 FUN_0024a510 (122 B): equivalent/0x0024a510.cpp
// sym: ?FUN_0024a510@Settings_24a510@fn_f9a518a5@@QAEPAV12@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0024a510 @ 0x0024a510
Settings_24a510* Settings_24a510::FUN_0024a510(int ownerArg) {
    owner = ownerArg;
    pScaleA = &DAT_004cc22c;
    pScaleB = &DAT_004cc228;
    pLimit = &DAT_004cc230;
    pMode = &DAT_004cc234;
    pCounter = ((int*)&DAT_004e5fa0);
    pRate = &DAT_004cc23c;
    zero2c = 0;
    zero3c = 0;
    zero40 = 0;
    zero44 = 0;
    scale0 = 1.0f;
    scale1 = 1.0f;
    scale2 = 1.0f;
    zero48 = 0;
    zero4c = 0;
    ListLink* a = &listA[0];
    listA[0].next = a;
    listA[1].next = a;
    listA[2].next = a;
    link50 = a;
    zero60 = 0;
    ListLink* b = &listB[0];
    listB[0].next = b;
    listB[1].next = b;
    listB[2].next = b;
    zero74 = 0;
    link64 = b;
    return this;
}


// 0x0024a590 FUN_0024a590 (54 B): matches/0x0024a590.cpp
// sym: ?target@fn_f9a518a5@@YIXPAUObj_24a590@1@PAX@Z
void __fastcall target(Obj_24a590* p, void*) {
    F47550((void*)((hulk_intptr)((char*)((char*)&DAT_004e6158))), p->m40);
    F47550((void*)((hulk_intptr)DAT_004e6110), p->m3c);
    char* q = (char*)p + 0x50;
    FUN_0024a450(q + 0x14);
    FUN_0024a4a0(q);
}


// 0x0024a5d0 FUN_0024a5d0 (460 B): equivalent/0x0024a5d0.cpp
// sym: ??0StreamVoice@fn_f9a518a5@@QAE@HHPAUSource_24a5d0@1@PAXHPAVStreamPlayerAllocator_24a5d0@audio@@@Z
// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 20/20)
// FUN_0024a5d0 @ 0x0024a5d0
StreamVoice::StreamVoice(int a0, int a1, Source_24a5d0 *a2, void *a3, int a4, audio::StreamPlayerAllocator_24a5d0 *a5)
{
    nodes.Init();
    keyHead = 0;
    keyTail = 0;
    list48.Init();
    list5c.Init();
    list70.Init();
    FUN_00257e80(((char*)&DAT_004e5f98), this);
    owner = a3;
    source = a2;
    a2->refCount++;
    f84 = a1;
    f88 = a0;
    f8c = a4;
    f08 = 1.0f;
    f0c = 1.0f;
    f10 = 1.0f;
    f14 = 1.0f;
    f34 = 1.0f;
    mode = 2;
    f38 = 0;
    ownAllocator.flags &= 0xfc;
    f9c = 0;
    fa0 = 0;
    fa4 = 0;
    f90 = 0;
    f94 = 0;
    f98 = 0;
    fa8 = 1.0f;
    if (a5)
        allocator = a5;
    else
        allocator = &ownAllocator;

    ItemLink *l = source->itemHead;
    Item_24a5d0 *item = 0;
    if (l)
        item = (Item_24a5d0 *)((char *)l - 0x14);
    while (item) {
        SrcNode *node = (SrcNode *)FUN_00247530(((Pool_24a5d0*)&DAT_004e5ff0));
        if (node) {
            node->f10 = 0;
            node->f14 = 0;
        }
        node->owner = item;
        node->f18 = 0;
        FUN_00249ce0(&nodes, node, &item->attr);
        l = item->link.next;
        if (l)
            item = (Item_24a5d0 *)((char *)l - 0x14);
        else
            item = 0;
    }

    if (a3) {
        Entry_24a5d0 *e = a2->FUN_00257250();
        while (e) {
            void *h = FUN_00242ce0(a3, &e->key);
            KeyNode *kn = (KeyNode *)FUN_00247530(((Pool_24a5d0*)&DAT_004e6080));
            kn->key = h;
            kn->next = 0;
            if (keyTail == 0)
                keyHead = kn;
            else
                keyTail->next = kn;
            keyTail = kn;
            e = ((Entry_24a5d0 *)((owners::C_257270 *)a2)->FUN_00257270((hulk_uintptr)(Entry_24a5d0 *)e));
        }
    }
}


// 0x0024a7a0 FUN_0024a7a0 (82 B): matches/0x0024a7a0.cpp
// sym: ?Update@Obj_24a7a0@fn_f9a518a5@@QAEPAV12@E@Z
Obj_24a7a0* Obj_24a7a0::Update(u8_24a7a0 flag) {
    Copy((void*)((hulk_intptr)((char*)((char*)&DAT_004e6158))), m40);
    Copy((void*)((hulk_intptr)DAT_004e6110), m3c);
    char* base = (char*)this + 0x50;
    FUN_0024a450(base + 0x14);
    FUN_0024a4a0(base);
    if (flag & 1)
        Copy((void*)((hulk_intptr)DAT_004e60c8), (hulk_intptr)this);
    return this;
}

} // namespace fn_f9a518a5

// 0x0024a800 FUN_0024a800 (307 B): equivalent/0x0024a800.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: _FUN_0024a800
namespace fn_0024a800 {
// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 55/56, incomplete)
// FUN_0024a800 @ 0x0024a800
// FUN_0024a800 @ 0x0024a800
struct Context;

struct Sub {
    void FUN_0024a280(Context *ctx);
};

struct TreeLink {
    TreeLink *left;
    TreeLink *right;
    TreeLink *parent;
};

struct Flags {
    char pad00[0x44];
    unsigned char bits;
};

struct Entry {
    Entry *next;
    char pad04[0x3c - 4];
    short state;
};

struct ChildNode : TreeLink {
    char pad0c[0x50 - 0xc];
    Sub sub;
};

struct GroupNode : TreeLink {
    char pad0c[4];
    Entry *entries;
    char pad14[0x1c - 0x14];
    Flags *flags;
};

struct Scene;

// equiv-conv: FUN_00249630 edi stack
void __cdecl FUN_00249630(Scene *scene, Context *ctx);
// equiv-conv: FUN_0024a3c0 eax ecx stack stack
char __cdecl FUN_0024a3c0(Entry *entry, Scene *scene, GroupNode *group, Context *ctx);
// equiv-conv: FUN_00249750 esi
void __cdecl FUN_00249750(Entry *entry);

struct Scene {
    char pad00[0x18];
    GroupNode *groupRoot;
    TreeLink groupNil;
    char pad28[0x48 - 0x28];
    ChildNode *childRoot;
    TreeLink childNil;
    char pad58[0x5c - 0x58];
    Sub sub;
};

// In-order successor in a tree whose empty links point at the nil node.
static TreeLink *Successor(TreeLink *n, TreeLink *nil)
{
    if (n->right != nil) {
        TreeLink *c = n->right;
        while (c->left != nil)
            c = c->left;
        return c;
    }
    TreeLink *p = n->parent;
    while (p != nil && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}

extern "C" void FUN_0024a800(Scene *scene, Context *ctx)
{
    scene->sub.FUN_0024a280(ctx);
    FUN_00249630(scene, ctx);

    TreeLink *childNil = &scene->childNil;
    TreeLink *node = scene->childRoot;
    if (node != childNil) {
        while (node->left != childNil)
            node = node->left;
        for (;;) {
            static_cast<ChildNode *>(node)->sub.FUN_0024a280(ctx);
            node = Successor(node, childNil);
            if (node == childNil || node == 0)
                break;
        }
    }

    TreeLink *groupNil = &scene->groupNil;
    node = scene->groupRoot;
    if (node != groupNil) {
        while (node->left != groupNil)
            node = node->left;
        for (;;) {
            GroupNode *group = static_cast<GroupNode *>(node);
            Entry *e = group->entries;
            while (e != 0) {
                if (FUN_0024a3c0(e, scene, group, ctx) && e->state == 0 && (group->flags->bits & 2) == 0) {
                    Entry *dead = e;
                    e = e->next;
                    FUN_00249750(dead);
                } else {
                    e = e->next;
                }
            }
            node = Successor(node, groupNil);
            if (node == groupNil || node == 0)
                break;
        }
    }
}
} // namespace fn_0024a800


// 0x0024a940 FUN_0024a940 (127 B): equivalent/0x0024a940.cpp [wrapped: conflict: Node]
// sym: _FUN_0024a940
namespace fn_0024a940 {
// STATUS: equivalent (tools/equiv.py level 3: 717 inputs, branch coverage 12/12)
// FUN_0024a940 @ 0x0024a940

struct Node {
    Node* left;             // 0x00
    Node* right;            // 0x04
    char pad8[8];
    unsigned int key;       // 0x10
    Node* FUN_0024a510(unsigned int key);
};

struct Tree_24a940 {
    Node* root;             // 0x00
    Node nil;               // 0x04 (sentinel)
};

struct Map_24a940 {
    char pad0[0x48];
    Tree_24a940 tree;              // 0x48
};

Node* __cdecl FUN_00247530(char* pool);
extern "C++" __declspec(nothrow) char __cdecl FUN_00249ff0(void *, void *, const unsigned *);

// Finds the node for *key, creating and linking a new one when it is missing.
extern "C" Node* FUN_0024a940(Map_24a940* map, const unsigned int* key)
{
    Tree_24a940* tree = &map->tree;
    Node* nil = &tree->nil;
    Node* n = tree->root;
    // volatile: keeps the null test on the hit, which MSVC otherwise drops because the node was dereferenced
    Node* volatile found = 0;
    unsigned int k = *key;
    while (n != nil) {
        if (k < n->key) {
            n = n->left;
        } else if (k <= n->key) {
            found = n;
            break;
        } else {
            n = n->right;
        }
    }
    if (found)
        return found;
    Node* mem = FUN_00247530((char*)DAT_004e60c8);
    Node* created = 0;
    if (mem)
        created = mem->FUN_0024a510(*key);
    FUN_00249ff0((Tree_24a940 *)tree, (Node *)created, (const unsigned *)(const unsigned int *)key);
    return created;
}
} // namespace fn_0024a940


// 0x0024a9c0 FUN_0024a9c0 (640 B): equivalent/0x0024a9c0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: _FUN_0024a9c0
namespace fn_0024a9c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3075 inputs, branch coverage 34/36, incomplete)
// FUN_0024a9c0 @ 0x0024a9c0

extern "C" int __cdecl _sprintf(char *buf, const char *fmt, ...);


struct Link_24a9c0 {
    Link_24a9c0 *next;
    Link_24a9c0 *prev;
};

struct Inner_24a9c0 {
    char data[4];
};

struct Sub_24a9c0 {
    char pad[0x14];
    Inner_24a9c0 inner;
};

struct Node {
    Node *left;
    Node *right;
    char pad08[8];
    unsigned int key;
    char pad14[0x3c - 0x14];
    void *poolA;
    void *poolB;
    char pad44[4];
    Link_24a9c0 *head;
    Link_24a9c0 *tail;
    Sub_24a9c0 sub;
    Node *FUN_0024a510(unsigned int key);
};

struct Tree_24a9c0 {
    Node *root;
    char nilMarker[4];
};

struct Y_24a9c0;

struct Entry_24a9c0 {
    Entry_24a9c0 *next;
    Y_24a9c0 *owner;
    void *extra;
    int f0c;
    char pad10[0x24 - 0x10];
    int f24;
    char pad28[0x30 - 0x28];
    Node *node;
    Link_24a9c0 link;
    short f3c;
};

struct Z {
    char pad[0x3c];
    unsigned int name;
    unsigned int limit;
};

struct Y_24a9c0 {
    char pad[0x10];
    Entry_24a9c0 *head;
    Entry_24a9c0 *tail;
    unsigned int count;
    Z *z;
};

struct Ctx_24a9c0 {
    char pad[0x48];
    Tree_24a9c0 tree;
};

struct Extra_24a9c0 {
};

extern "C" unsigned int __cdecl FUN_002673a0(const char *s, int flag);
void *__cdecl FUN_00247530(void *pool);
void __cdecl FUN_00247550(void *pool, void *p);
extern "C++" __declspec(nothrow) void * __cdecl FUN_00249fc0(void *, const unsigned int *);
extern "C++" __declspec(nothrow) char __cdecl FUN_00249ff0(void *, void *, const unsigned *);
extern "C++" __declspec(nothrow) void __cdecl FUN_00249ec0(void *, void *);
extern "C++" __declspec(nothrow) void __cdecl FUN_0024a450(void *);
extern "C++" __declspec(nothrow) void __cdecl FUN_0024a4a0(void *);
void *__cdecl FUN_0025d3d0();

static Entry_24a9c0 *EntryFromLink(Link_24a9c0 *l)
{
    return (Entry_24a9c0 *)((char *)l - 0x34);
}

extern "C" void *FUN_0024a9c0(void * ctx_, void * y_)
{
    Ctx_24a9c0 * ctx = (Ctx_24a9c0 *)ctx_;
    Y_24a9c0 * y = (Y_24a9c0 *)y_;
    struct Frame {
        unsigned int tmp;
        char buf[256];
    } fr;
    Node *node;

    if (y->count >= (y->z->limit & 0x1f))
        return (Entry_24a9c0 *)0;

    unsigned int emptyHash = FUN_002673a0("", 0);
    Tree_24a9c0 *tree = &ctx->tree;
    if (y->z->name != emptyHash) {
        node = ((Node *)FUN_00249fc0((Tree_24a9c0 *)tree, &y->z->name));
        if (node == 0) {
            void *p = FUN_00247530(DAT_004e60c8);
            if (p != 0)
                node = ((Node *)p)->FUN_0024a510(y->z->name);
            else
                node = 0;
            FUN_00249ff0((Tree_24a9c0 *)tree, (Node *)node, (const unsigned *)(unsigned int *)(&node->key));
        }
    } else {
        Node *nil = (Node *)tree->nilMarker;
        fr.tmp = 0;
        bool create = true;
        for (;;) {
            _sprintf(fr.buf, "unnamed %d", fr.tmp);
            unsigned int h = FUN_002673a0(fr.buf, 0);
            Node *n = tree->root;
            while (n != nil) {
                unsigned int *kp = &n->key;
                if (h < *kp) {
                    n = n->left;
                } else if (h <= *kp) {
                    break;
                } else {
                    n = n->right;
                }
            }
            if (n == nil)
                break;
            node = n;
            if (n == 0)
                break;
            Link_24a9c0 *l = n->head;
            if (l != 0 && EntryFromLink(l) != 0) {
                Link_24a9c0 *again = n->head;
                if (again == 0 || EntryFromLink(again) == 0) {
                    create = false;
                    break;
                }
                fr.tmp++;
                continue;
            }
            FUN_00249ec0((Tree_24a9c0 *)tree, (Node *)n);
            FUN_00247550(((char*)((char*)&DAT_004e6158)), n->poolB);
            FUN_00247550(DAT_004e6110, n->poolA);
            Sub_24a9c0 *s = &n->sub;
            FUN_0024a450((Inner_24a9c0 *)(&s->inner));
            FUN_0024a4a0((Sub_24a9c0 *)s);
            FUN_00247550(DAT_004e60c8, n);
            break;
        }
        if (create) {
            void *p = FUN_00247530(DAT_004e60c8);
            if (p != 0)
                node = ((Node *)p)->FUN_0024a510(FUN_002673a0(fr.buf, 0));
            else
                node = 0;
            fr.tmp = FUN_002673a0(fr.buf, 0);
            FUN_00249ff0((Tree_24a9c0 *)tree, (Node *)node, (const unsigned *)(unsigned int *)(&fr.tmp));
        }
    }

    Entry_24a9c0 *e = (Entry_24a9c0 *)FUN_00247530(((char*)((char*)&DAT_004e6038)));
    if (e != 0) {
        int *w = (int *)e;
        for (int i = 0; i < 16; i++)
            w[i] = 0;
    }
    Link_24a9c0 *link = &e->link;
    if (node->head == 0) {
        node->head = link;
        link->prev = 0;
    } else {
        node->tail->next = link;
        link->prev = node->tail;
    }
    node->tail = link;
    link->next = 0;
    e->next = y->head;
    y->head = e;
    if (e->next == 0)
        y->tail = e;
    e->f0c = 0;
    e->f24 = 0;
    e->owner = y;
    e->node = node;
    void *pool = FUN_00247530(FUN_0025d3d0());
    if (pool != 0)
        e->extra = ((Extra_24a9c0 *)((owners::Scheduler_25df40 *)(((Extra_24a9c0 *)pool)))->FUN_0025df40((hulk_intptr)(Node *)node, (hulk_intptr)(Z *)(y->z), (hulk_intptr)(Ctx_24a9c0 *)ctx));
    else
        e->extra = 0;
    y->count++;
    e->f3c = 0;
    return (Entry_24a9c0 *)e;
}
} // namespace fn_0024a9c0


// 0x0024ac40 FUN_0024ac40 (155 B): equivalent/0x0024ac40.cpp [wrapped: conflict: Node]
// sym: _FUN_0024ac40
namespace fn_0024ac40 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_0024ac40 @ 0x0024ac40
// FUN_0024ac40: find the first open (type 0/1/2) node of a list and fill it in, else append a new one
struct Node {
    Node *next;
    char pad04[8];
    int type;
    char flag;
    char pad11[3];
    int value;
    int srcLo;
    int srcHi;
    int f20;
    float f24;
    int f28;
};

struct Owner_24ac40 {
    char pad00[0x10];
    Node *head;
};

struct Pair_24ac40 {
    int lo;
    int hi;
};

extern "C++" __declspec(nothrow) void * __cdecl FUN_0024a9c0(void *, void *);
extern "C" void __cdecl FUN_00247ae0(void *a, Node *n, int b, int c, Pair_24ac40 *d);

extern "C" void __cdecl FUN_0024ac40(void *ctx, Owner_24ac40 *owner, int flag, int value, Pair_24ac40 *src)
{
    for (Node *n = owner->head; n != 0; n = n->next) {
        if (n->type == 0 || n->type == 1 || n->type == 2) {
            n->flag = (char)flag;
            n->type = 3;
            n->value = value;
            if (src != 0) {
                n->srcLo = src->lo;
                n->srcHi = src->hi;
            } else {
                n->srcLo = 0;
                n->srcHi = 0;
            }
            n->f28 = 0;
            n->f20 = 0;
            if (n->srcHi == 0)
                n->f24 = 1.0f;
            else
                *(int *)&n->f24 = 0;
            return;
        }
    }
    Node *fresh = ((Node *)FUN_0024a9c0(ctx, (Owner_24ac40 *)owner));
    if (fresh != 0)
        FUN_00247ae0(ctx, fresh, flag, value, src);
}
} // namespace fn_0024ac40

namespace fn_f9a518a5 {

// 0x0024ace0 FUN_0024ace0 (58 B): matches/0x0024ace0.cpp
// sym: _FUN_0024ace0
extern "C" int __cdecl FUN_0024ace0(int a, hulk_intptr b, int c, int d, int e, hulk_intptr f) {
    Obj_24ace0* p = (Obj_24ace0*)GetThing((void*)((hulk_intptr)DAT_004e5fa8));
    if (p)
        return p->Do(a, b, c, d, e, f);
    return 0;
}


// 0x0024ad20 FUN_0024ad20 (301 B): equivalent/0x0024ad20.cpp
// sym: ?FUN_0024ad20@Registry@fn_f9a518a5@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 24/24)
// FUN_0024ad20 @ 0x0024ad20
// equiv-conv: FUN_00249750 esi
void Registry::FUN_0024ad20()
{
    for (;;) {
        Node1 *n = list1.first;
        Node1 *end = (Node1 *)&list1.last;
        if (n == end)
            break;
        while (n->next != end)
            n = n->next;
        Child *c;
        while ((c = n->children) != 0)
            FUN_00249750(c);
        FUN_00248ac0((List1 *)(&list1), (Node1 *)n);
        FUN_00247550(((char*)&DAT_004e5ff0), n);
    }

    for (;;) {
        Node2 *n = list2.first;
        Node2 *end = (Node2 *)&list2.last;
        if (n == end)
            break;
        while (n->next != end)
            n = n->next;
        FUN_00249ec0((List2 *)(&list2), (Node2 *)n);
        FUN_00247550(((char*)((char*)&DAT_004e6158)), (void *)n->value40);
        FUN_00247550(((char*)&DAT_004e6110), (void *)n->value3c);
        FUN_0024a450(&n->sub50.inner);
        FUN_0024a4a0(&n->sub50);
        FUN_00247550(((char*)&DAT_004e60c8), n);
    }

    FUN_00257f00(((char*)&DAT_004e5f98), this);

    SNode *s;
    while ((s = head) != 0) {
        FUN_00242d70(pool44, s->payload);
        SNode *prev = 0;
        SNode *cur = head;
        if (cur != s) {
            do {
                prev = cur;
                cur = cur->next;
            } while (cur != s);
        }
        if (prev == 0)
            head = s->next;
        else
            prev->next = s->next;
        if (s->next == 0)
            tail = prev;
        FUN_00247550(((char*)&DAT_004e6080), s);
    }

    owner->count--;
    FUN_0024a450(&sub5c.inner);
    FUN_0024a4a0(&sub5c);
}


// 0x0024ae50 FUN_0024ae50 (35 B): matches/0x0024ae50.cpp
// sym: ?Bar@Obj_24ae50@fn_f9a518a5@@QAEPAU12@E@Z
Obj_24ae50* Obj_24ae50::Bar(unsigned char flag) {
    Helper();
    if (flag & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e5fa8), this);
    return this;
}


// 0x0024af00 FUN_0024af00 (32 B): matches/0x0024af00.cpp
// sym: _FUN_0024af00
extern "C" void __cdecl FUN_0024af00(Obj_24af00* object) {
    if (object) {
        object->Clean();
        FUN_00247550(((char*)&DAT_004e5fa8), object);
    }
}


// 0x0024af90 FUN_0024af90 (49 B): matches/0x0024af90.cpp
// sym: ?target@fn_f9a518a5@@YAIPAUX@1@@Z
unsigned int __cdecl target(X* p) {
    unsigned int n = ((unsigned int)FUN_0025e2b0((X *)p));
    hulk_freg f = (hulk_freg)(unsigned int)p->value * p->scale;
    return n <= (unsigned int)(int)(__int64)f;
}


// 0x0024afe0 FUN_0024afe0 (11 B): matches/0x0024afe0.cpp
// sym: _FUN_0024afe0
extern "C" u32_24afe0 __cdecl FUN_0024afe0(void* p) {
    return *(u32_24afe0*)((char*)p + 0xc0);
}


// 0x0024b030 FUN_0024b030 (16 B): matches/0x0024b030.cpp
// sym: ?FUN_0024b030@fn_f9a518a5@@YAHPAX@Z
hulk_intptr __cdecl FUN_0024b030(void* p) {
    return FUN_0025d060(*(u32_24b030*)((char*)p + 0x0c));
}


// 0x0024b040 FUN_0024b040 (16 B): equivalent/0x0024b040.cpp
// sym: ?FUN_0024b040@fn_f9a518a5@@YAXPAUItem@1@M@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_0024b040 @ 0x0024b040
void __cdecl FUN_0024b040(Item *item, float amount) {
    FUN_00258b80(item->value, amount);
}


// 0x0024b050 FUN_0024b050 (16 B): equivalent/0x0024b050.cpp
// sym: ?FUN_0024b050@fn_f9a518a5@@YAXPAUArgument@1@PAUEntry_24b050@1@I@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_0024b050 @ 0x0024b050
void __cdecl FUN_0024b050(Argument* argument, Entry_24b050* entries, unsigned count) {
    FUN_00258ba0(argument->value, entries, count);
}

} // namespace fn_f9a518a5

// 0x0024b060 FUN_0024b060 (16 B): equivalent/0x0024b060.cpp [wrapped: conflict: Item]
// sym: ?FUN_0024b060@fn_0024b060@@YAXPAUItem@1@PAUPair_24b060@1@H@Z
namespace fn_0024b060 {
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_0024b060 @ 0x0024b060
struct Item { char pad[8]; void* value; };
struct Pair_24b060;
extern "C" void __cdecl FUN_00258bf0(void*, Pair_24b060*, int);
void __cdecl FUN_0024b060(Item* item, Pair_24b060* pairs, int count) { FUN_00258bf0(item->value, pairs, count); }
} // namespace fn_0024b060

namespace fn_f9a518a5 {

// 0x0024b080 FUN_0024b080 (16 B): equivalent/0x0024b080.cpp
// sym: ?FUN_0024b080@fn_f9a518a5@@YAHPAUObject@1@M@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_0024b080 @ 0x0024b080
int __cdecl FUN_0024b080(Object* object, float amount) {
    return FUN_00258c80(object->value, amount);
}

} // namespace fn_f9a518a5

// 0x0024b0c0 FUN_0024b0c0 (16 B): equivalent/0x0024b0c0.cpp [wrapped: conflict: Object]
// sym: ?FUN_0024b0c0@fn_0024b0c0@@YAHPAUObject@1@H@Z
namespace fn_0024b0c0 {
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_0024b0c0 @ 0x0024b0c0
struct Object { char pad[8]; void *value; };
extern "C" int __cdecl FUN_00258cb0(void *, int);
int __cdecl FUN_0024b0c0(Object *object, int arg) {
    return FUN_00258cb0(object->value, arg);
}
} // namespace fn_0024b0c0

namespace fn_f9a518a5 {

// 0x0024b0d0 FUN_0024b0d0 (11 B): matches/0x0024b0d0.cpp
// sym: _FUN_0024b0d0
extern "C" u32_24b0d0 __cdecl FUN_0024b0d0(Outer_24b0d0* p) {
    return p->inner->value;
}


// 0x0024b170 FUN_0024b170 (140 B): equivalent/0x0024b170.cpp
// sym: _FUN_0024b170
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 14/14)
// FUN_0024b170 @ 0x0024b170
// Pump a streaming ring buffer: refill what the play cursor has consumed and switch to the
// "finished" state (5) once the data runs out.
// equiv-conv: FUN_0024b170 eax
extern "C" bool FUN_0024b170(void * s)
{
    unsigned int pos = FUN_00258f00(((Stream *)s)->handle);
    Ring_24b170* r = ((Stream *)s)->ring;
    unsigned int start = r->readPos;
    unsigned int count;
    if (start > pos) {
        count = r->size - start + pos;
    } else {
        count = pos - start;
    }
    if (count != 0) {
        if (!FUN_0025e350(r, count)) {
            return false;
        }
        r = ((Stream *)s)->ring;
        if (r->filled >= r->fillEnd) {
            if (r->pending > 0 || ((Stream *)s)->mode == 5) {
                if (((int)(hulk_uintptr)FUN_00259c50(((Stream *)s)->handle)) == 1) {
                    FUN_00258e50(((Stream *)s)->handle);
                }
                ((Stream *)s)->state = 5;
                ((Stream *)s)->ring->filled = ((Stream *)s)->ring->fillEnd;
            }
        }
    }
    return true;
}


// 0x0024b200 FUN_0024b200 (20 B): matches/0x0024b200.cpp
// sym: _FUN_0024b200
extern "C" bool FUN_0024b200(void* object) {
    return *((u8*)object + 0xb9) >= *((u8*)object + 0xba);
}


// 0x0024b220 FUN_0024b220 (12 B): matches/0x0024b220.cpp
// sym: _FUN_0024b220
extern "C" int __cdecl FUN_0024b220(Obj_24b220* p) {
    return p->value;
}

} // namespace fn_f9a518a5

// 0x0024b270 FUN_0024b270 (42 B): matches/0x0024b270.cpp
// sym: ?FUN_0024b270@Target_24b270@owners@@QAEHXZ
int owners::Target_24b270::FUN_0024b270() {
    Obj_24b270* o = ((Obj_24b270**)this)[index * 3];
    if (o)
        o->f12();
    int v = (int)index + 1;
    int d = (int)divisor;
    int q = v / d;
    index = (unsigned char)(v % d);
    count--;
    return q;
}


// 0x0024b2a0 FUN_0024b2a0 (42 B): matches/0x0024b2a0.cpp [wrapped: conflict: Node]
// sym: ?Remove@Obj_24b2a0@fn_0024b2a0@@QAEXXZ
namespace fn_0024b2a0 {
struct Node {
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
};
struct Obj_24b2a0 {
    char pad[0x78];
    unsigned char a;
    unsigned char b;
    unsigned char c;
    void Remove();
};
void Obj_24b2a0::Remove() {
    int i = ((int)a + (int)b - 1) % (int)c;
    Node* p = (Node*)*(void**)((char*)this + i * 12);
    if (p)
        p->v12();
    --b;
}
} // namespace fn_0024b2a0


// 0x0024b2d0 FUN_0024b2d0 (21 B): matches/0x0024b2d0.cpp
// sym: ?FUN_0024b2d0@Obj_24b2d0@owners@@QAEPAU12@XZ
owners::Obj_24b2d0* owners::Obj_24b2d0::FUN_0024b2d0() {
    if (!enabled)
        return 0;
    return (owners::Obj_24b2d0*)((char*)this + index * 12);
}


// 0x0024b310 FUN_0024b310 (72 B): matches/0x0024b310.cpp
// sym: ?FUN_0024b310@X_24b310@owners@@QAEHPAX@Z
hulk_intptr owners::X_24b310::FUN_0024b310(void* p) {
    hulk_intptr i = ((char*)p - (char*)this) / 12;
    if (i == ((int)b + (int)a - 1) % (int)c)
        return 0;
    return (hulk_intptr)this + ((i + 1) % (unsigned int)c) * 12;
}

namespace fn_f9a518a5 {

// 0x0024b480 FUN_0024b480 (115 B): equivalent/0x0024b480.cpp
// sym: _FUN_0024b480
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_0024b480 @ 0x0024b480
// equiv-conv: FUN_0024b270 ecx
// equiv-conv: FUN_0024b480 eax
extern "C" void FUN_0024b480(void *m)
{
    if (((Machine *)m)->ring.count == 0)
        return;
    Handler_24b480 *h = ((Machine *)m)->ring.slots[((Machine *)m)->ring.current].handler;
    if (h == 0)
        return;
    if (h->State() == 0) {
        h->v0();
    } else if (h->State() != 1 && h->State() == 3) {
        ((Machine *)m)->ring.FUN_0024b270();
        return;
    }
    int before;
    int after;
    do {
        before = h->State();
        h->v11();
        after = h->State();
    } while (before != after);
}


// 0x0024b550 FUN_0024b550 (962 B): equivalent/0x0024b550.cpp
// sym: _FUN_0024b550
// STATUS: equivalent (tools/equiv.py level 3: 3034 inputs, branch coverage 64/66, incomplete)
// FUN_0024b550 @ 0x0024b550
// equiv-conv: FUN_0024b550 esi
extern "C" void FUN_0024b550(void * p_)
{
    Player_24b550 * p = (Player_24b550 *)p_;
    Frame_24b550 f;
    Queue_24b550 *q = &p->queue;
    Slot_24b550 *slot = 0;
    if (q->enabled) {
        slot = &q->slots[q->current];
    }
    Sink_24b550 *sink = 0;
    bool ok;
    if (slot == 0) {
        ok = false;
    } else {
        sink = slot->sink;
        if (sink != 0 && sink->state() != 2) {
            sink = 0;
            ok = false;
        } else {
            ok = true;
        }
    }
    bool bad = !ok;

    int state = p->state;
    if (state == 0) {
        Chunk *c = p->chunk;
        f.x = ((unsigned int)FUN_0025e2b0((Chunk *)c));
        unsigned int limit = (unsigned int)((float)c->f4 * c->fc);
        if (f.x > limit) {
            if (p->mode != 1) {
                return;
            }
        }
        hulk_uintptr amount = FUN_0025e090(p->chunk);
        if (p->region == 0 && sink != 0) {
            amount = FUN_0026fd80(amount, sink->v3());
        }
        if (amount == 0 || bad) {
            return;
        }
        if (sink == 0 && (p->region == 0 || FUN_0025e310(p->region) == 0)) {
            if (!FUN_0025cf70(p->h0c, p->chunk->f14, amount, &f.x)) {
                return;
            }
            p->pos = f.x;
            p->t2c = f.x;
            p->t24 = FUN_00267f80();
            p->state = 5;
            return;
        }
        if (p->region == 0) {
            if (!FUN_0025d070(p->h0c, p->chunk->f14, amount, 0, &f.z, &f.y, &f.x)) {
                return;
            }
            p->t30 = FUN_00267f80();
            p->n1c++;
            p->t18 = FUN_00267f80();
            sink->write(f.z, f.y, f.x);
            p->mark28 = f.x;
            p->state = 2;
            p->pos = f.x;
            return;
        }
        unsigned int avail = FUN_0025e310(p->region);
        if (avail == 0) {
            return;
        }
        if (avail < amount) {
            amount = avail;
        }
        if (!FUN_0025d070(p->h0c, p->chunk->f14, amount, 1, &f.y, &f.z, &f.x)) {
            return;
        }
        p->t34 = FUN_00267f80();
        Region_24b550 *r = p->region;
        p->stream = FUN_002703c0(f.y, f.z, r->extra + r->pos, r->len, f.x);
        p->stream->start();
        p->mark28 = f.x;
        p->state = 3;
        p->pos = f.x;
        return;
    }
    if (state == 2) {
        Slot_24b550 *s2 = 0;
        if (q->enabled) {
            s2 = &q->slots[q->current];
        }
        Sink_24b550 *sk = s2->sink;
        if (!sk->poll(&f.x)) {
            return;
        }
        FUN_0025d0f0(p->h0c, f.x);
        if (p->pos > f.x) {
            ((owners::Target_24b270 *)q)->FUN_0024b270();
            p->pos = f.x;
        }
        p->state = 4;
        p->t20 = FUN_00267f80();
        return;
    }
    if (state == 3) {
        if (!p->stream->done()) {
            return;
        }
        FUN_0025d0f0(p->h0c, p->pos);
        FUN_0025e350(p->region, p->pos);
        p->stream->stop();
        p->stream = 0;
        p->state = 4;
        p->t20 = FUN_00267f80();
        return;
    }
    if (state == 4) {
        if (!FUN_0025d010(p->h0c)) {
            return;
        }
        if (p->region != 0) {
            p->t3c += FUN_00267f80() - p->t34;
        } else {
            p->t38 += FUN_00267f80() - p->t30;
        }
        FUN_0025e0b0(p->chunk, p->pos, 0);
        p->pos = 0;
        p->state = 0;
        return;
    }
    if (state == 5) {
        if (!FUN_0025d010(p->h0c)) {
            return;
        }
        FUN_0025e0b0(p->chunk, p->pos, 1);
        p->state = 0;
        p->pos = 0;
    }
}

} // namespace fn_f9a518a5

// 0x0024b920 FUN_0024b920 (328 B): equivalent/0x0024b920.cpp [wrapped: conflict: FUN_00267f80]
// sym: _FUN_0024b920
namespace fn_0024b920 {
// STATUS: equivalent (tools/equiv.py level 3: 17486 inputs, branch coverage 25/26, incomplete)
// FUN_0024b920 @ 0x0024b920
// FUN_0024b920 @ 0x0024b920
class Sink_24b920 {
public:
    virtual void v0();
    virtual int state();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void write(unsigned int addr, unsigned int a, unsigned int b);
    virtual void v7();
    virtual char poll(unsigned int *out);
};

struct Source_24b920 {
    unsigned int base;
    char pad4[4];
    unsigned int f8;
    char padc[0x14 - 0xc];
    unsigned int off;
};

struct Slot_24b920 {
    Sink_24b920 *sink;
    char rest[8];
};

struct Queue_24b920 {
    Slot_24b920 slots[10];
};

extern "C" char FUN_0025e450(Source_24b920 *src, int size);
char FUN_0024af90(Source_24b920 *src);
Source_24b920 *FUN_0025e090(Source_24b920 *src);
unsigned int FUN_0026fd80(Source_24b920 *src, int size);
void FUN_0025e0b0(Source_24b920 *src, unsigned int v, int zero);
int FUN_00267f80();

struct Player_24b920 {
    char pad0[0x14];
    Source_24b920 *source;
    int f18;
    int f1c;
    char pad20[0x40 - 0x20];
    Queue_24b920 queue;
    unsigned char current;
    unsigned char enabled;
    char pad_ba[0xc8 - 0xba];
    int started;
    char pad_cc[4];
    unsigned int pending;
};

// equiv-conv: FUN_0024b920 esi
extern "C" void FUN_0024b920(void * p_)
{
    Player_24b920 * p = (Player_24b920 *)p_;
    unsigned int got;

    if (p->source == 0)
        return;
    if (!p->enabled)
        return;
    Slot_24b920 *slot = &p->queue.slots[p->current];
    if (slot == 0)
        return;
    Sink_24b920 *sink = slot->sink;
    if (sink != 0) {
        if (sink->state() != 2)
            return;
    }
    if (p->started == 0) {
        if (!FUN_0025e450(p->source, 0x800))
            return;
        if (!FUN_0024af90(p->source))
            return;
        if (sink == 0)
            return;
        if (sink->state() != 2)
            return;
        unsigned int n = FUN_0026fd80(FUN_0025e090(p->source), 0x800);
        if (n == 0)
            return;
        p->f1c++;
        p->f18 = FUN_00267f80();
        sink->write(p->source->off + p->source->base, p->source->f8, n);
        p->pending = n;
        p->started = 1;
    } else {
        if (!sink->poll(&got))
            return;
        FUN_0025e0b0(p->source, got, 0);
        if (p->pending > got)
            ((owners::Target_24b270 *)&(p->queue))->FUN_0024b270();
        p->pending = 0;
        p->started = 0;
    }
}
} // namespace fn_0024b920

namespace fn_f9a518a5 {

// 0x0024ba70 FUN_0024ba70 (100 B): matches/0x0024ba70.cpp
// sym: _FUN_0024ba70
extern "C" int __cdecl FUN_0024ba70(Obj_24ba70* self, int value, int amount) {
    int old = self->total;
    int index = ((int)self->head + (int)self->count) % (int)self->size;
    Entry_24ba70* e = (Entry_24ba70*)((char*)self + 0x40) + index;
    e->a = value;
    e->c = self->total;
    e->b = amount;
    self->total = self->total + amount;
    self->count = self->count + 1;
    return old;
}


// 0x0024bae0 FUN_0024bae0 (152 B): equivalent/0x0024bae0.cpp
// sym: ?FUN_0024bae0@fn_f9a518a5@@YAXPAURing_24bae0@1@D@Z
// STATUS: equivalent (tools/equiv.py level 3: 2254 inputs, branch coverage 10/10)
// FUN_0024bae0 @ 0x0024bae0
// Pops entries off the back of the ring until `count` drops to `keep`.
void __cdecl FUN_0024bae0(Ring_24bae0* r, char dropAll)
{
    int keep = (dropAll == 0);
    while (r->count > keep) {
        if (r->total != 0)
            r->total -= r->slots[(r->count + r->start - 1) % r->cap].size;
        Obj_24bae0* o = r->slots[(r->start + r->count - 1) % r->cap].obj;
        if (o)
            o->Release();
        r->count--;
    }
}


// 0x0024bc70 FUN_0024bc70 (329 B): equivalent/0x0024bc70.cpp
// sym: _FUN_0024bc70
// STATUS: equivalent (tools/equiv.py level 3: 19606 inputs, branch coverage 36/36)
// FUN_0024bc70 @ 0x0024bc70
// FUN_0024bc70 @ 0x0024bc70
// equiv-conv: FUN_0024b170 eax
// equiv-conv: FUN_0024b480 eax
// equiv-conv: FUN_0024b550 esi
// equiv-conv: FUN_0024b920 esi
// equiv-conv: FUN_0024bc70 eax
extern "C" void FUN_0024bc70(void *p)
{
    int state = ((Player_24bc70 *)p)->state;
    if (state == 1) {
        unsigned int end = ((Player_24bc70 *)p)->span->length + ((Player_24bc70 *)p)->span->start;
        if (end >= FUN_0025d040(((Player_24bc70 *)p)->limit) && ((Player_24bc70 *)p)->f0c4 == 0) {
            ((Player_24bc70 *)p)->state = 4;
            return;
        }
    } else if (state == 2 || state == 3) {
        if (state == 3 && ((int)(hulk_uintptr)FUN_00259c50((void *)(hulk_uintptr)(int)(((Player_24bc70 *)p)->handle))) == 0 && ((Player_24bc70 *)p)->f0c4 == 0) {
            ((Player_24bc70 *)p)->state = 4;
            return;
        }
        FUN_0024b170((Player_24bc70 *)((Player_24bc70 *)p));
    } else if (state == 5) {
        if (((int)(hulk_uintptr)FUN_00259c50((void *)(hulk_uintptr)(int)(((Player_24bc70 *)p)->handle))) == 0 && ((Player_24bc70 *)p)->f0c4 == 0 && ((Player_24bc70 *)p)->f0c8 == 0) {
            int found = 0;
            for (Slot_24bc70 *s = ((Slot_24bc70 *)((owners::Obj_24b2d0 *)&(((Player_24bc70 *)p)->queue))->FUN_0024b2d0()); s != 0; s = ((Slot_24bc70 *)((owners::X_24b310 *)&(((Player_24bc70 *)p)->queue))->FUN_0024b310((Slot_24bc70 *)s))) {
                Sink_24bc70 *sink = s->sink;
                if (sink != 0) {
                    int r = sink->state();
                    if (r == 1) {
                        found = r;
                        s->sink->finish();
                    }
                }
            }
            if (found == 0) {
                FUN_0024bae0(((Player_24bc70 *)p), 1);
                FUN_00258ea0(((Player_24bc70 *)p)->handle, 0);
                ((Player_24bc70 *)p)->state = 0;
                ((Player_24bc70 *)p)->f0bc = 0;
                FUN_0025e290(((Player_24bc70 *)p)->span);
                if (((Player_24bc70 *)p)->res != 0)
                    FUN_0025e290(((Player_24bc70 *)p)->res);
            }
        }
        if (((Player_24bc70 *)p)->state != 5)
            return;
    } else {
        return;
    }
    FUN_0024b480((Player_24bc70 *)((Player_24bc70 *)p));
    FUN_0024b550((Player_24bc70 *)((Player_24bc70 *)p));
    FUN_0024b920((Player_24bc70 *)((Player_24bc70 *)p));
}


// 0x0024be00 FUN_0024be00 (398 B): equivalent/0x0024be00.cpp
// sym: _FUN_0024be00
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 12/12)
// FUN_0024be00 @ 0x0024be00
extern "C" void *FUN_0024be00(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Rec_24be00 *r = (Rec_24be00 *)FUN_00247530(((Pool_24be00*)&DAT_004e61a0));
    if (r)
        memset(r, 0, sizeof(Rec_24be00));
    r->handle = 0;
    r->fc = 0;
    r->fc0 = 0;
    r->fc4 = 0;
    r->fc8 = 0;
    r->fcc = 0;
    r->fd0 = 0;
    r->fd4 = 0;
    r->fc = FUN_0025d340(a3, a4, 1);
    if (r->fc == 0) {
        FUN_00247550(((Pool_24be00*)&DAT_004e61a0), r);
        return (Rec_24be00 *)0;
    }
    if ((*(Rec_24be00**)&DAT_004e61e8) == 0) {
        (*(Rec_24be00**)&DAT_004e61e8) = r;
        r->prev = 0;
    } else {
        (*(Rec_24be00**)&DAT_004e61ec)->next = r;
        r->prev = (*(Rec_24be00**)&DAT_004e61ec);
    }
    (*(Rec_24be00**)&DAT_004e61ec) = r;
    r->next = 0;
    r->handle = FUN_00259610(a1, a2, r->fc);
    FUN_00258b40(r->handle, 1);
    Sub_24be00 *s = (Sub_24be00 *)FUN_00247530((void *)FUN_0025e070());
    if (s) {
        s->f28 = 0;
        s->f2c = 0;
    }
    r->f10 = s;
    FUN_0025e550(r->f10, 0, 0, FUN_0025d040(r->fc));
    if (a5) {
        Sub_24be00 *s2 = (Sub_24be00 *)FUN_00247530((void *)FUN_0025e070());
        if (s2) {
            s2->f28 = 0;
            s2->f2c = 0;
        }
        r->f14 = s2;
        r->f10->f0c = 1.0f;
        FUN_0025e550(r->f14, a5, a7, a6);
    } else {
        r->f14 = 0;
    }
    r->b9 = 0;
    r->b8 = 0;
    r->fbc = 0;
    r->ba = 10;
    for (int i = 0; i < 10; i++)
        r->f18[i] = 0;
    return (Rec_24be00 *)r;
}


// 0x0024bf90 FUN_0024bf90 (176 B): matches/0x0024bf90.cpp
// sym: _FUN_0024bf90
extern "C" void FUN_0024bf90(void * p) {
    F24bae0(((Obj_24bf90 *)p), 1);
    FUN_00259b40(((Obj_24bf90 *)p)->c);
    FUN_0025d300(((Obj_24bf90 *)p)->d);
    FUN_0025e280(((Obj_24bf90 *)p)->e);
    if (((Obj_24bf90 *)p)->e)
        F247550(F25e070(), ((Obj_24bf90 *)p)->e);
    if (((Obj_24bf90 *)p)->f) {
        FUN_0025e280(((Obj_24bf90 *)p)->f);
        if (((Obj_24bf90 *)p)->f)
            F247550(F25e070(), ((Obj_24bf90 *)p)->f);
    }
    if (!((Obj_24bf90 *)p)->b)
        (*(void**)&DAT_004e61e8) = ((Obj_24bf90 *)p)->a;
    else
        *(void**)((Obj_24bf90 *)p)->b = ((Obj_24bf90 *)p)->a;
    if (!((Obj_24bf90 *)p)->a)
        (*(void**)&DAT_004e61ec) = ((Obj_24bf90 *)p)->b;
    else
        *(void**)((char*)((Obj_24bf90 *)p)->a + 4) = ((Obj_24bf90 *)p)->b;
    F247550(((char*)&DAT_004e61a0), ((Obj_24bf90 *)p));
}


// 0x0024c060 FUN_0024c060 (41 B): equivalent/0x0024c060.cpp
// sym: _FUN_0024c060
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// FUN_0024c060 @ 0x0024c060
// equiv-conv: FUN_0024bc70 eax
extern "C" void FUN_0024c060() { for (Item* item = (*(Item**)&DAT_004e61e8); item; item = item->next) { do { FUN_0024bc70((Item *)item); } while (item->state == 3); } }


// 0x0024c090 FUN_0024c090 (34 B): equivalent/0x0024c090.cpp
// sym: _FUN_0024c090
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0024c090 @ 0x0024c090
// equiv-conv: FUN_0024bc70 eax
extern "C" void __cdecl FUN_0024c090(Task* task) {
    task->active = 1;
    do {
        FUN_0024bc70((Task *)task);
    } while (task->state == 3);
}

} // namespace fn_f9a518a5

// 0x0024c0c0 FUN_0024c0c0 (82 B): equivalent/0x0024c0c0.cpp [wrapped: conflict: Stream]
// sym: _FUN_0024c0c0
namespace fn_0024c0c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_0024c0c0 @ 0x0024c0c0
struct Stream {
    char pad0[8];
    int handle;
    char pad0c[0xb4];
    int state;
    int status;
};

extern "C" void * __cdecl FUN_00259c50(void *);
void __cdecl FUN_00258e50(int handle);
// equiv-conv: FUN_0024bc70 eax
extern "C++" __declspec(nothrow) void __cdecl FUN_0024bc70(void *);

extern "C" void __cdecl FUN_0024c0c0(Stream* s)
{
    if (s->state == 0 || s->state == 5)
        return;
    if (s->state == 2) {
        if (((int)(hulk_uintptr)FUN_00259c50((void *)(hulk_uintptr)(int)(s->handle))) == 1)
            FUN_00258e50(s->handle);
    }
    s->state = 5;
    do {
        FUN_0024bc70((Stream *)s);
    } while (s->status == 3);
}
} // namespace fn_0024c0c0

namespace fn_f9a518a5 {

// 0x0024c120 FUN_0024c120 (50 B): equivalent/0x0024c120.cpp
// sym: _FUN_0024c120
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0024c120 @ 0x0024c120
// equiv-conv: FUN_0024bc70 eax
extern "C" void __cdecl FUN_0024c120(State* state) { FUN_00259be0(state->resource); state->status = 2; do { FUN_0024bc70((State *)state); } while (state->repeat == 3); }

} // namespace fn_f9a518a5

// 0x0024c160 FUN_0024c160 (66 B): equivalent/0x0024c160.cpp [wrapped: conflict: State]
// sym: _FUN_0024c160
namespace fn_0024c160 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0024c160 @ 0x0024c160
struct State { char pad0[8]; int item; char pad1[0xb4]; int mode; int status; };
extern "C" void * __cdecl FUN_00259c50(void *);
void __cdecl FUN_00258e50(int);
// equiv-conv: FUN_0024bc70 eax
extern "C++" __declspec(nothrow) void __cdecl FUN_0024bc70(void *);
extern "C" void __cdecl FUN_0024c160(State* state) {
    if (((int)(hulk_uintptr)FUN_00259c50((void *)(hulk_uintptr)(int)(state->item))) == 1) FUN_00258e50(state->item);
    state->mode = 3;
    do {
        FUN_0024bc70((State *)state);
    } while (state->status == 3);
}
} // namespace fn_0024c160

