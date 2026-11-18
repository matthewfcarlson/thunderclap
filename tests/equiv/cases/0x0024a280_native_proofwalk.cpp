// STATUS: equivalent (tools/equiv.py --wine level 3, 3,000 compared)
// (integ2, D100, proofwalk) a red-black tree walk over fuzzed nodes ending at &tree.nil: the walk-sentinel inputs keep
// going while the proof draws on (their 512 runs were spent before: 430 compared of 40,000 drawn).
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
extern "C++" void __cdecl FUN_00249810(void *, int);
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
extern void __cdecl F47550_00247550(void*, u32_24a590);
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
    virtual void v0_00247ba0(int, int, int, int);
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
extern void Copy_00247550(void*, hulk_intptr);
struct Obj_24ace0 {
    int Do_0024a5d0(int, int, int, int, int, int);
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
extern "C++" void __cdecl FUN_00248ac0(void *, void *);
extern "C++" void __cdecl FUN_00249ec0(void *, void *);
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
    void Helper_0024ad20();
    Obj_24ae50* Bar(unsigned char flag);
};
void __cdecl FUN_00247550(void*, Obj_24ae50*);
struct Obj_24af00 {
    void Clean_0024ad20();
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
extern "C++" void __cdecl FUN_0024b920(void *);
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
extern void F24bae0_0024bae0(void*, int);
extern "C" void FUN_00259b40(void*);
extern "C" void FUN_0025d300(void*);
extern "C" void FUN_0025e280(void*);
extern void* F25e070_0025e070();
extern void F247550_00247550(void*, void*);
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
extern "C++" void * __cdecl FUN_0024be00(int, int, int, int, int, int, int);
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
    Node* nil = (Node*)((char*)&head->b);
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
    N_247f80* s = (N_247f80*)((char*)&head->r);
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
// sym: _FUN_00247fc0 @394c7c009b90 @w3415c875f53d @v994b74608afa
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
    Node* h = (Node*)((char*)&n->b);
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
// sym: _FUN_00248670 @707b0ad366a4 @wb2b77bd84280 @vfde1285daf95
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
// sym: _FUN_00248780 @451f4a7b689f @w5716f0e5cc57 @v6fe5dd2e5098
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
extern "C++" void __cdecl FUN_00247fc0(void *, void *);
extern "C" void FUN_00248ac0(void * tree, void * node) {
    Node* nil = (Node*)((char*)&((Node *)tree)->right);
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
    N_248bf0* end = (N_248bf0*)((char*)&s->l);
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
// sym: ?FUN_00248c50@fn_00248c50@@YAPAUNode@1@PAUTree@1@PAU21@@Z @853b28fe7849 @we7802cd32f96
namespace fn_00248c50 {
// STATUS: equivalent (tools/equiv.py level 3: 195 inputs, branch coverage 15/16, incomplete)
// FUN_00248c50 @ 0x00248c50
struct Node { Node *left; Node *parent; Node *right; }; struct Tree { Node *root; Node sentinel; }; Node* __cdecl FUN_00248c50(Tree* tree, Node* node) { Node* nil = &tree->sentinel; Node* p = node->parent; if (p != nil) { Node* q = p->left; while (q != nil) { p = q; q = p->left; } return p == nil ? 0 : p; } p = node->right; if (p != nil) { while (node == p->parent) { node = p; p = p->right; if (p == nil) break; } } return p == nil ? 0 : p; }
} // namespace fn_00248c50

namespace fn_f9a518a5 {

// 0x00248d40 FUN_00248d40 (604 B): equivalent/0x00248d40.cpp
// sym: _FUN_00248d40 @394c7c009b90 @w3415c875f53d @vb2c3c8531971
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
// sym: _FUN_00248fa0 @394c7c009b90 @w3415c875f53d @vc1bd3af1b252
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
// sym: _FUN_00249200 @394c7c009b90 @w3415c875f53d @v37d37e0288e7
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
    Node* end = (Node*)((char*)&p->value1);
    Node* cur = *(Node**)((char*)&p->value0);
    if (cur == end)
        return 0;
    while (cur->next != end)
        cur = cur->next;
    return cur;
}

} // namespace fn_f9a518a5

// 0x002495e0 FUN_002495e0 (16 B): equivalent/0x002495e0.cpp [wrapped: conflict: FUN_00248bf0]
// sym: ?FUN_002495e0@fn_002495e0@@YAHPAUObject@1@PAX@Z @5a9887714535 @wf56c58e805db @vc8f9193507c4
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
// sym: ?target@fn_f9a518a5@@YAXPAUObject@1@H@Z @08a176d125ef @wdf9fd0a48cd4 @va18d952fcdaf
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
// sym: ?FUN_00249750@fn_00249750@@YAHPAUNode@1@@Z @f999e417849e @wcb32f4b955f9
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
// sym: _FUN_002497e0 @894a6d6eea74 @w30a28d94f118 @v4157816d1905
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 6/6)
// FUN_002497e0 @ 0x002497e0
// FUN_002497e0 @ 0x002497e0
// equiv-conv: FUN_00249750 esi
extern "C" unsigned short __cdecl FUN_002497e0(Item* item) { --item->count; if (item->count != 0) return item->count; if (item->link != 0) return (unsigned short)(hulk_uintptr)item->link; Owner* owner = item->owner; Flags* flags = owner->flags; if (flags->bits & 2) return (unsigned short)(hulk_uintptr)owner; unsigned short result = (unsigned short)FUN_00249750(item); volatile unsigned short saved = result; return saved; }

} // namespace fn_f9a518a5

// 0x00249810 FUN_00249810 (182 B): equivalent/0x00249810.cpp [wrapped: conflict: Node]
// sym: _FUN_00249810 @9792bfbef62b @w909c74459406 @v47594608a0ed
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
// sym: ?run@fn_f9a518a5@@YAXPAUItem_2498d0@1@@Z @ca1502b341f8 @w0b9a247c7b4b @va458f1156cee
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
// sym: _FUN_00249a90 @fccb18b450ae @w89e795285847
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
// sym: _FUN_00249b40 @d9a400817e62 @w6f12f0684428
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
// sym: _FUN_00249bd0 @15a34f38004d @we3db6efaef60 @v9168e2e0a62f
// STATUS: equivalent (tools/equiv.py level 3: 2984 inputs, branch coverage 8/8)
// FUN_00249bd0 @ 0x00249bd0
extern "C" void __cdecl FUN_00249bd0(hulk_intptr unused, Container *container, Pair *pair) { Node *node = container->head; while (node && (node->state == 5 || node->state == 0)) node = node->next; if (!node) return; node->state = 5; if (pair) { node->value0 = pair->first; node->value1 = pair->second; } else { node->value0 = 0; node->value1 = 0; } node->finalValue = 0; node->other = 0; }

} // namespace fn_f9a518a5

// 0x00249c20 FUN_00249c20 (182 B): equivalent/0x00249c20.cpp [wrapped: conflict: Node]
// sym: _FUN_00249c20 @3eb26b704c0a @wcac687290db1 @v9e4a732f316d
namespace fn_00249c20 {
// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_00249c20 @ 0x00249c20
struct Node { Node *left; Node *right; Node *parent; int color; };
struct Tree_249c20 { Node *root; Node sentinel; };
struct Entry_249c20 { int value; Node node; };
extern Node* __cdecl FUN_00247d10(Tree_249c20*,Node*);
extern "C++" void __cdecl FUN_00248d40(void *, void *);
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
// sym: ?FUN_00249ce0@fn_00249ce0@@YADPAUTree_249ce0@1@PAUNode@1@PBI@Z @53826b63519c @wfdf951794c10 @v4ac1cae1d82f
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
extern "C++" void __cdecl FUN_00248fa0(void *, void *);
extern "C" void FUN_00249ec0(void * tree, void * node) {
    Node* nil = (Node*)((char*)&((Node *)tree)->right);
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
// sym: _FUN_00249f80 @424eadbca0c9 @w6612ff3a6d77 @v21bd2f4c5708
namespace fn_00249f80 {
// STATUS: equivalent (tools/equiv.py level 3: 731 inputs, branch coverage 8/8)
// FUN_00249f80 @ 0x00249f80
struct Entry { Entry* left; Entry* right; char pad[0x14]; struct Data* data; }; struct Data { char pad[0x38]; unsigned key; }; struct Tree { Entry* root; Entry sentinel; }; extern "C" void * __cdecl FUN_00249f80(void * tree_, const unsigned* key) {
    Tree * tree = (Tree *)tree_; Entry* node=tree->root; Entry* end=&tree->sentinel; while(node!=end) { unsigned value=node->data->key; if(*key<value) node=node->left; else if(*key==value) return (Entry *)node; else node=node->right; } return (Entry *)0; }
} // namespace fn_00249f80


// 0x00249fc0 FUN_00249fc0 (44 B): equivalent/0x00249fc0.cpp [wrapped: conflict: Node]
// sym: _FUN_00249fc0 @ded505639a0e @w4261c46d710e @v396218334768
namespace fn_00249fc0 {
// STATUS: equivalent (tools/equiv.py level 3: 702 inputs, branch coverage 8/8)
// FUN_00249fc0 @ 0x00249fc0
struct Node { Node *left; Node *right; char pad[8]; unsigned int key; }; struct Tree { Node *root; Node sentinel; }; extern "C" void *__cdecl FUN_00249fc0(void * tree_, const unsigned int *key) {
    Tree * tree = (Tree *)tree_; Node *node = tree->root; Node *end = &tree->sentinel; while (node != end) { if (*key < node->key) node = node->left; else if (*key == node->key) return (Node *)node; else node = node->right; } return (Node *)0; }
} // namespace fn_00249fc0


// 0x00249ff0 FUN_00249ff0 (451 B): equivalent/0x00249ff0.cpp [wrapped: conflict: Node]
// sym: _FUN_00249ff0 @156002aed514 @w497b166f31fd @v8e072be26bec
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

extern "C++" void __cdecl FUN_002482a0(void *, void *);
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
// sym: _FUN_0024a1c0 @95bbc0abb930 @wfa0c0c6eb314 @v3daabd5b3f2c
namespace fn_0024a1c0 {
// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_0024a1c0 @ 0x0024a1c0
struct Node { Node* left; Node* right; Node* parent; int color; };
struct Tree_24a1c0 { Node* root; Node sentinel; };
struct Entry_24a1c0 { int data; Node node; };
Node* __cdecl FUN_00248370(Tree_24a1c0*, Node*);
extern "C++" void __cdecl FUN_00249200(void *, void *);
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
// sym: ?FUN_0024a280@Owner_24a280@fn_0024a280@@QAEXH@Z @c73cea3d4368 @w5e0b3365a29b
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
    virtual ~Entry_24a280();
    virtual char vfunc_1(Owner_24a280 *owner, int arg);    // tested as a whole byte (test al, al)
    Node node;
};

extern "C++" void __cdecl FUN_00249c20(void *, void *);

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
        char remove = e->vfunc_1(this, arg);

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


