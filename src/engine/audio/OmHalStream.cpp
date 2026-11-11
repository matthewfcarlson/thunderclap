// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0025aa50..0x0025d640 (kind game, layer engine, confidence high), dominant class audio::OmHalStream
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/audio.h"
#include "decls/data/platform/xbox/unknown.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd6abdd0 {
#define TREE_TU_END }
namespace fn_fd6abdd0 {} using namespace fn_fd6abdd0;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fd6abdd0 {
extern int __cdecl FUN_00246f50(void*, const char*, ...);
typedef unsigned char BYTE;
struct Obj_25aa80 {
    bool Query(BYTE*, int, int, int);
};
extern int __cdecl FUN_00246f50(const char*, const char*, ...);
extern int __cdecl FUN_00246f50(int, const char*, ...);
class Handler {
  public:
    int Fn(int, int, int, int);
};
extern "C" int __cdecl FUN_00246f50(unsigned int, const char*, ...);
struct Writer_25ac30 {
    Stream *stream;
};
char __cdecl FUN_00246f50(Stream *s, const char *format, ...);
struct Str_25ad30 {
    char data[12];
    const char* FUN_0023fb00();
};
struct Record_25ad30 {
    char pad00[0x10];
    Str_25ad30 name;
};
struct Pair_25ade0 {
    int a;
    int b;
};
extern Pair_25ade0 __cdecl FUN_00262800();
struct Target_25ade0 {
    int first;
    int pad;
    Pair_25ade0 value;
};
struct Node {
  public:
    union { Node* a; Node* left; };
    union { Node* b; Node* parent; };
    union { Node* c; Node* right; };
};
struct Tree_25af20 {
    Node* root;
};
struct Tree_25af70 {
    Node* root;
    Node head;
};
struct RbNode_25b010 {
    RbNode_25b010* left;
    RbNode_25b010* right;
    RbNode_25b010* parent;
    int color; // 0 = black, 1 = red
};
struct RbTree_25b010 {
    RbNode_25b010* root;
    RbNode_25b010 nil;
};
struct E_25b2c0 {
    char x[12];
    void Init();
};
struct A_25b2c0 {
    char pad[0x10];
    E_25b2c0 a;
    E_25b2c0 b;
    E_25b2c0 c[10];
};
typedef unsigned int u32_25b730;
struct Helper_25b730 {
};
struct Obj_25b730 {
    u32_25b730 first;
    void Target(void*, u32_25b730);
};
extern "C++" __declspec(nothrow) void __cdecl FUN_0025b5b0(void *, void *);
extern "C++" __declspec(nothrow) char __cdecl FUN_0025b320(void *, void *, const void *);
struct Elem {
    char pad[12];
};
struct Obj {
  public:
    Handler* volatile handler;
    char _m_pad_4[0xc];
    Elem a;
    Elem b;
    Elem arr[10];
    int Fn(int, int, int, int);
    void call(int, int, int, int);
    int DoThing(void*, int, int, int);
};
struct Holder {
    Obj* volatile obj;
};
void freeobj(void*, Obj*);
extern "C++" __declspec(nothrow) void __cdecl FUN_0025b7d0(void *);
extern void __cdecl FuncB(void*);
class Target_25b940 {
  public:
    void* p;
    void run();
};
typedef unsigned int u32_25bbd0;
void thunk_FUN_00267090(u32_25bbd0);
struct S_25bbd0 {
    u32_25bbd0 value;
};
class C_25bcb0 {
  public:
    int Get();
};
const char format[] = "\"%s\"";
struct Reader {
    bool FUN_00246f00(char *buf, int size, int a, int b);
};
struct Printer_25bce0 {
};
struct Holder_25bce0 {
    Reader *reader;
};
bool __cdecl FUN_0025abd0(Holder_25bce0 *h, int *len);
extern "C" int __cdecl FUN_0024c310(int);
extern "C" int __cdecl FUN_0024c2f0(int);
class A_25bec0 {
  public:
    virtual void f0();
    virtual void* f1();
    virtual void* f2();
};
extern void* __cdecl helper(A_25bec0*);
extern "C" bool __cdecl Check(void*, void*);
void __fastcall helper(void* p);
class HalStream_25c0b0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
};
class HalStream_25c2b0 {
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
struct AudioDevice {
    void** vt;
};
struct Header_25c320 { unsigned int flags; };
struct Row_25c320 { unsigned int values[4]; };
extern bool __cdecl FUN_0025aad0(Reader*, signed char*);
extern bool __cdecl FUN_0025abd0(Reader*, unsigned int*);
extern "C" int __cdecl FUN_0025abd0(void*, unsigned int*);
class Str_25c920 {
public:
    char* data;
    short mode;
    short pad6;
    short length;
    short pad10;

    Str_25c920* FUN_0023fd20(int capacity);
    Str_25c920* FUN_0023fc40(const char* text, int flag);
    Str_25c920* FUN_0023fc90(const char* text, int len, int mode);
    Str_25c920* FUN_00240190(const Str_25c920* other);
    Str_25c920* FUN_0023ff50(const Str_25c920* other);
    Str_25c920* FUN_00240170(const Str_25c920* other);
    void FUN_00240060();
    const char* FUN_0023fb00();
};
Str_25c920* __cdecl FUN_00262700(Str_25c920* path, const Str_25c920* part);
extern void __stdcall init();
struct Pair {
    int a, b;
};
struct Key_25cab0 { int w0, w1; char flags; char pad[7]; char data[1]; };
struct Tmp_25cab0 {
    int w[3];
    void* FUN_0023fb00();
};
struct Holder_25cab0 { void* FUN_0023fb00(); };
void* __cdecl FUN_00240780();
void __cdecl FUN_0025c920(Tmp_25cab0* out, int a1, Key_25cab0* id, void* x);
Holder_25cab0* __cdecl FUN_0024c710();
void* __cdecl FUN_002631f0(void* a, void* b, int c, int d, int e, void* f, int g);
extern "C" char DAT_0042a850[];
struct Inner_25cc70 {
};
class OmHalStream {
  public:
    hulk_intptr vf;
    char pad[0x1b8];
    Inner_25cc70 inner;
    OmHalStream* Init(unsigned char flag);
};
struct Temp_25ccf0 {
    char pad[12];
    void Init();
    int Get();
};
unsigned char __cdecl Work(int, Temp_25ccf0*);
struct Receiver_25ccf0 {
    void Send(int);
};
struct Pair_25cda0 {
    int a, b;
};
class Header_25cda0;
bool __cdecl FUN_0025ccf0(Stream *s, Header_25cda0 *h);
bool __cdecl FUN_0025aa80(Stream *s, char *out);
bool __cdecl FUN_0025abd0(Stream *s, unsigned int *out);
extern "C" bool __cdecl FUN_0025c490(void *, unsigned int *);
class Header_25cda0 {
public:
    char pad0[8];
    unsigned char enabled : 1;      // 0x8, bit 0
    char pad9[3];
    unsigned int id : 31;           // 0xc, low 31 bits
    unsigned int reserved : 1;
    Pair_25cda0 range;                     // 0x10

    bool FUN_0025cda0(Stream *s);
};
struct FileState { char padding[0x24]; int count; };
extern "C++" __declspec(nothrow) unsigned char __cdecl FUN_00246f50(FileState *, const char *, ...);
struct Inner_25cf10 {
    void f();
};
struct Obj_25cf10 {
    char pad[0x1c];
    Inner_25cf10 inner;
    Obj_25cf10* target();
};
} // namespace fn_fd6abdd0
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memset(void *, int, unsigned int);
#endif
namespace fn_fd6abdd0 {
struct Surface_25cf70 {
    char pad00[0x10];
    char *base;
    unsigned int flags;
    int state;
};
extern "C" unsigned char __cdecl FUN_0025d010(void* p);
struct Obj_25d010 {
    char pad[0x18];
    int state;
};
struct Global_25d010 {
    char pad[0x10];
    volatile int value;
};
typedef unsigned int u32_25d040;
struct Obj_25d040 {
    char pad[12];
    u32_25d040 value;
};
struct Slot_25d070 {
    char pad00[4];
    unsigned int limit;
    int field_08;
    int current;
    void* owner;
};
struct Obj_25d070 {
    char pad00[0x14];
    int link;
    int claimed;
};
int __cdecl FUN_0024c2f0(int* link);
extern "C" unsigned int __cdecl FUN_0026fd80(unsigned int a, int b);
struct Source_25d0f0 {
    char pad00[8];
    unsigned f08;
    unsigned char *base;
};
struct Texture {
    char pad00[0xc];
    unsigned height;
    unsigned char *dst;
    unsigned flags;
    int state;
};
struct Obj_25d2d0 {
    char pad[0x1c];
    int member;
    Obj_25d2d0* target(int flags);
};
struct Helper_25d2d0 {
};
extern void __cdecl FUN_00247550(void*, Obj_25d2d0*);
extern "C" void __cdecl FUN_00257f00(void*, void*);
extern "C" void __cdecl FUN_00240c60(void*);
struct At {
    char pad[0x1c];
};
struct Obj_25d300 {
    char pad[0x10];
    void* p;
    char pad2[8];
};
void __cdecl f247550(void*, void*);
extern "C" int FUN_0024afe0(int);


// 0x0025aa50 FUN_0025aa50 (40 B): matches/0x0025aa50.cpp
// sym: _FUN_0025aa50
extern "C" int __cdecl FUN_0025aa50(void** value, char flag) {
    const char* s = "true";
    if (!flag)
        s = "false";
    void* v = *value;
    return FUN_00246f50(v, "%s", s);
}


// 0x0025aa80 FUN_0025aa80 (47 B): matches/0x0025aa80.cpp
// sym: ?Target@fn_fd6abdd0@@YA_NIPA_N@Z
bool __cdecl Target(hulk_uintptr a, bool* out) {
    Obj_25aa80* o = *(Obj_25aa80**)a;
    BYTE* b = (BYTE*)&a;
    if (o->Query(b, 1, 1, 1)) {
        *out = *b != 0;
        return true;
    }
    return false;
}


// 0x0025aab0 FUN_0025aab0 (27 B): matches/0x0025aab0.cpp
// sym: _FUN_0025aab0
extern "C" int __cdecl FUN_0025aab0(const char** value, signed char number) {
    int n = number;
    const char* s = *value;
    return FUN_00246f50(s, "%d", n);
}


// 0x0025aad0 FUN_0025aad0 (23 B): matches/0x0025aad0.cpp
// sym: ?FUN_0025aad0@fn_fd6abdd0@@YAHPAUHolder@1@H@Z
int __cdecl FUN_0025aad0(Holder* p, int n) {
    Obj* o = p->obj;
    return o->Fn(n, 1, 1, 1);
}


// 0x0025aaf0 FUN_0025aaf0 (27 B): matches/0x0025aaf0.cpp
// sym: _FUN_0025aaf0
extern "C" int __cdecl FUN_0025aaf0(const int* value, unsigned char flag) {
    int n = *value;
    unsigned int f = flag;
    return FUN_00246f50(n, "%d", f);
}


// 0x0025ab10 FUN_0025ab10 (23 B): matches/0x0025ab10.cpp
// sym: ?FUN_0025ab10@fn_fd6abdd0@@YAHPAUObj@1@H@Z
int __cdecl FUN_0025ab10(Obj* p, int v) {
    Handler* h = p->handler;
    return h->Fn(v, 1, 1, 1);
}

} // namespace fn_fd6abdd0

// 0x0025ab30 FUN_0025ab30 (26 B): equivalent/0x0025ab30.cpp [wrapped: conflict: FUN_00246f50]
// sym: _FUN_0025ab30
namespace fn_0025ab30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0025ab30 @ 0x0025ab30
extern "C++" __declspec(nothrow) void __cdecl FUN_00246f50(int, const char *, ...);
extern "C" void __cdecl FUN_0025ab30(const int *value, int argument)
{
    FUN_00246f50(*value, "%d", argument);
}
} // namespace fn_0025ab30

namespace fn_fd6abdd0 {

// 0x0025ab50 FUN_0025ab50 (23 B): matches/0x0025ab50.cpp
// sym: _FUN_0025ab50
extern "C" void FUN_0025ab50(Holder* a, int b) {
    Obj* o = a->obj;
    o->call(b, 4, 1, 1);
}


// 0x0025abb0 FUN_0025abb0 (26 B): matches/0x0025abb0.cpp
// sym: _FUN_0025abb0
extern "C" int __cdecl FUN_0025abb0(const unsigned int* value, unsigned int arg) {
    unsigned int x = *value;
    return FUN_00246f50(x, "%u", arg);
}

} // namespace fn_fd6abdd0

// 0x0025abd0 FUN_0025abd0 (23 B): matches/0x0025abd0.cpp [wrapped: conflict: Target]
// sym: ?FUN_0025abd0@fn_0025abd0@@YAHPAVObj@1@H@Z
namespace fn_0025abd0 {
class Target {
  public:
    int Fn(int, int, int, int);
};
class Obj {
  public:
    Target* volatile p;
};
int __cdecl FUN_0025abd0(Obj* o, int v) {
    Target* t = o->p;
    return t->Fn(v, 4, 1, 1);
}
} // namespace fn_0025abd0

namespace fn_fd6abdd0 {

// 0x0025abf0 FUN_0025abf0 (31 B): equivalent/0x0025abf0.cpp
// sym: _FUN_0025abf0
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_0025abf0 @ 0x0025abf0
// FUN_0025abf0 @ 0x0025abf0
extern "C" int __cdecl FUN_0025abf0(void** value, float number)
{
    return FUN_00246f50(*value, "%f", (double)number);
}

} // namespace fn_fd6abdd0

// 0x0025ac10 FUN_0025ac10 (23 B): matches/0x0025ac10.cpp [wrapped: conflict: Obj; Target]
// sym: _FUN_0025ac10
namespace fn_0025ac10 {
struct Target {};
struct Obj {
    Target* p;
};
int __fastcall Do(Target*, int, int, int, int, int);
extern "C" int __cdecl FUN_0025ac10(Obj* a, int b) {
    Target* p = *(Target* volatile*)&a->p;
    return Do(p, b, b, 4, 1, 1);
}
} // namespace fn_0025ac10

namespace fn_fd6abdd0 {

// 0x0025ac30 FUN_0025ac30 (134 B): equivalent/0x0025ac30.cpp
// sym: ?FUN_0025ac30@fn_fd6abdd0@@YADPAUWriter_25ac30@1@_K@Z
// STATUS: equivalent (tools/equiv.py level 3: 4853 inputs, branch coverage 8/10, incomplete)
// FUN_0025ac30 @ 0x0025ac30
// FUN_0025ac30 @ 0x0025ac30
char FUN_0025ac30(Writer_25ac30 *w, unsigned __int64 value)
{
    char out[0x100];
    char digits[0x100];
    int n = 0;
    do {
        digits[n++] = (char)('0' + (int)(value % 10));
        value = value / 10;
    } while (value != 0);
    for (int i = 0; i < n; i++)
        out[i] = digits[n - 1 - i];
    out[n] = 0;
    return FUN_00246f50(w->stream, "%s", out);
}


// 0x0025acc0 FUN_0025acc0 (23 B): matches/0x0025acc0.cpp
// sym: ?Target@fn_fd6abdd0@@YAHPCRAUObj@1@PAX@Z
int Target(Obj* volatile* a, void* b) {
    Obj* obj = *a;
    return obj->DoThing(b, 8, 1, 1);
}


// 0x0025ad30 FUN_0025ad30 (129 B): matches/0x0025ad30.cpp
// sym: _FUN_0025ad30
// FUN_0025ad30 @ 0x0025ad30
// 0x0025ad30: compare the text of a (copied) string with the string stored in b, strcmp style
extern "C" int FUN_0025ad30(void * a, void * b)
{
    Str_25ad30 copy;
    Str_25ad30* t = ((Str_25ad30 *)((owners::String_23fc40 *)&copy)->FUN_0023fc40(((Str_25ad30 *)a)->FUN_0023fb00(), (hulk_intptr)0));
    const char* other = ((Record_25ad30 *)b)->name.FUN_0023fb00();
    int result = strcmp(t->FUN_0023fb00(), other);
    ((owners::Str_240060 *)&copy)->FUN_00240060();
    return result;
}


// 0x0025ade0 FUN_0025ade0 (24 B): matches/0x0025ade0.cpp
// sym: ?FUN_0025ade0@fn_fd6abdd0@@YIPAUTarget_25ade0@1@PAU21@@Z
Target_25ade0* __fastcall FUN_0025ade0(Target_25ade0* self) {
    self->first = 0;
    self->value = FUN_00262800();
    return self;
}

} // namespace fn_fd6abdd0

// 0x0025ae90 FUN_0025ae90 (16 B): matches/0x0025ae90.cpp [wrapped: conflict: FUN_00262800]
// sym: ?FUN_0025ae90@Obj_25ae90@fn_0025ae90@@QAEXXZ
namespace fn_0025ae90 {
typedef unsigned __int64 U64_25ae90;
U64_25ae90 __cdecl FUN_00262800();
struct Obj_25ae90 {
    char pad[8];
    U64_25ae90 value;
    void FUN_0025ae90();
};
void Obj_25ae90::FUN_0025ae90() {
    value = FUN_00262800();
}
} // namespace fn_0025ae90

namespace fn_fd6abdd0 {

// 0x0025af20 FUN_0025af20 (78 B): matches/0x0025af20.cpp
// sym: _FUN_0025af20
// Same code shape as 0x00241880 (propagated; names are from that function)
extern "C" void FUN_0025af20(void * tree, void * node) {
    Node* child = ((Node *)node)->b;
    ((Node *)node)->b = child->a;
    if (child->a != (Node*)(((Tree_25af20 *)tree) + 1)) {
        child->a->c = ((Node *)node);
    }
    child->c = ((Node *)node)->c;
    Node* parent = ((Node *)node)->c;
    if (parent == (Node*)(((Tree_25af20 *)tree) + 1)) {
        *reinterpret_cast<Node**>(((Tree_25af20 *)tree)) = child;
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


// 0x0025af70 FUN_0025af70 (81 B): matches/0x0025af70.cpp
// sym: ?swap_node@fn_fd6abdd0@@YAXPAUTree_25af70@1@PAUNode@1@@Z
// Same code shape as 0x002418d0 (propagated; names are from that function)
void swap_node(Tree_25af70* tree, Node* node) {
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


// 0x0025afd0 FUN_0025afd0 (55 B): matches/0x0025afd0.cpp
// sym: ?FUN_0025afd0@fn_fd6abdd0@@YAPAUNode@1@PAU21@0@Z
Node* __cdecl FUN_0025afd0(Node* head, Node* node) {
    Node* sentinel = (Node*)((char*)head + 4);
    Node* p = node->parent;
    if (p != sentinel) {
        while (p->left != sentinel)
            p = p->left;
        return p;
    }
    p = node->right;
    while (p != sentinel && node == p->parent) {
        node = p;
        p = p->right;
    }
    return p;
}


// 0x0025b010 FUN_0025b010 (604 B): equivalent/0x0025b010.cpp
// sym: _FUN_0025b010
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 60/60)
// FUN_0025b010 @ 0x0025b010
// Red-black tree erase rebalancing: 'x' is the node that carries the extra black.
extern "C" void FUN_0025b010(void * tree_, void * x_)
{
    RbTree_25b010 * tree = (RbTree_25b010 *)tree_;
    RbNode_25b010 * x = (RbNode_25b010 *)x_;
    RbNode_25b010* nil = &tree->nil;
    RbNode_25b010* y;
    RbNode_25b010* z;
    RbNode_25b010* p;
    RbNode_25b010* c;

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


// 0x0025b2c0 FUN_0025b2c0 (51 B): matches/0x0025b2c0.cpp
// sym: ?Target@fn_fd6abdd0@@YIPAUA_25b2c0@1@PAU21@@Z
A_25b2c0* __fastcall Target(A_25b2c0* self) {
    self->a.Init();
    self->b.Init();
    int i = 10;
    do {
        self->c[10 - i].Init();
        --i;
    } while (i != 0);
    return self;
}

} // namespace fn_fd6abdd0

// 0x0025b320 FUN_0025b320 (470 B): equivalent/0x0025b320.cpp [wrapped: conflict: Node]
// sym: _FUN_0025b320
namespace fn_0025b320 {
// STATUS: equivalent (tools/equiv.py level 3: 131 inputs, branch coverage 40/40)
// FUN_0025b320 @ 0x0025b320
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    int key;
};

struct Tree_25b320 {
    Node* root;
    Node nil;
};

extern "C++" __declspec(nothrow) int __cdecl FUN_0025ad30(void *, void *);
extern "C++" __declspec(nothrow) void __cdecl FUN_0025af20(void *, void *);
extern "C" void FUN_0025af70(Tree_25b320* tree, Node* node);

// Red-black tree unique-key insert with rebalance. color: 1 = red, 0 = black.
extern "C" char FUN_0025b320(void * tree_, void * node_, const void* key)
{
    Tree_25b320 * tree = (Tree_25b320 *)tree_;
    Node * node = (Node *)node_;
    Node* nil = &tree->nil;
    Node* cur = tree->root;
    Node* parent = nil;

    while (cur != nil) {
        parent = cur;
        int c = FUN_0025ad30((void *)(const void *)key, (void *)(const Node *)cur);
        if (c < 0) {
            cur = cur->left;
        } else if (c <= 0) {
            return 0;
        } else {
            cur = cur->right;
        }
    }

    node->parent = parent;
    if (parent == nil) {
        tree->root = node;
    } else if (FUN_0025ad30((void *)(const void *)key, (void *)(const Node *)parent) < 0) {
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
                    FUN_0025af20((Tree_25b320 *)tree, (Node *)node);
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
                    FUN_0025af70(tree, node);
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
} // namespace fn_0025b320


// 0x0025b500 FUN_0025b500 (59 B): matches/0x0025b500.cpp [wrapped: conflict: Node]
// sym: ?findNode@fn_0025b500@@YAPAUNode@1@PAUTree@1@PAX@Z
namespace fn_0025b500 {
struct Node {
    Node* left;
    Node* right;
};
struct Tree {
    Node* root;
    Node sentinel;
};
extern "C++" __declspec(nothrow) int __cdecl FUN_0025ad30(void *, void *);
Node* __cdecl findNode(Tree* tree, void* key) {
    Node* p = tree->root;
    Node* end = &tree->sentinel;
    while (p != end) {
        int n = FUN_0025ad30(key, (Node *)p);
        if (n < 0)
            p = p->left;
        else if (n > 0)
            p = p->right;
        else
            return p;
    }
    return 0;
}
} // namespace fn_0025b500


// 0x0025b560 FUN_0025b560 (75 B): matches/0x0025b560.cpp [wrapped: conflict: Tree]
// sym: ?FUN_0025b560@fn_0025b560@@YAPAUNode@1@PAUTree@1@PAU21@@Z
namespace fn_0025b560 {
struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree {
    char pad[4];
    Node sentinel;
};
Node* __cdecl FUN_0025b560(Tree* tree, Node* node) {
    Node* current = node->parent;
    Node* end = &tree->sentinel;
    if (current != end) {
        while (current->left != end)
            current = current->left;
    } else {
        current = node->right;
        while (current != end && node == current->parent) {
            node = current;
            current = current->right;
        }
    }
    return current == end ? 0 : current;
}
} // namespace fn_0025b560


// 0x0025b5b0 FUN_0025b5b0 (178 B): matches/0x0025b5b0.cpp [wrapped: conflict: Node]
// sym: _FUN_0025b5b0
namespace fn_0025b5b0 {
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int data;
};
void* FUN_0025afd0(void*, void*);
extern "C++" __declspec(nothrow) void __cdecl FUN_0025b010(void *, void *);
extern "C" void FUN_0025b5b0(void * tree, void * node) {
    Node* nil = (Node*)((char*)((Node *)tree) + 4);
    Node* x;
    if (((Node *)node)->left == nil || ((Node *)node)->right == nil)
        x = ((Node *)node);
    else
        x = (Node*)FUN_0025afd0(((Node *)tree), ((Node *)node));
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
        FUN_0025b010(((Node *)tree), y);
}
} // namespace fn_0025b5b0

namespace fn_fd6abdd0 {

// 0x0025b730 FUN_0025b730 (53 B): matches/0x0025b730.cpp
// sym: ?Target@Obj_25b730@fn_fd6abdd0@@QAEXPAXI@Z
void Obj_25b730::Target(void* a, u32_25b730 b) {
    FUN_0025b5b0((void *)(hulk_uintptr)(unsigned int)first, a);
    ((owners::Text_240190 *)(((Helper_25b730*)((char*)a + 0x10))))->FUN_00240190((const owners::Text_240190 *)(hulk_uintptr)(unsigned int)b);
    FUN_0025b320((void *)(hulk_uintptr)(unsigned int)first, a, (const void *)(hulk_uintptr)(unsigned int)b);
}

} // namespace fn_fd6abdd0

// 0x0025b7d0 FUN_0025b7d0 (118 B): equivalent/0x0025b7d0.cpp [wrapped: conflict: Node]
// sym: _FUN_0025b7d0
namespace fn_0025b7d0 {
// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 8/8)
// FUN_0025b7d0 @ 0x0025b7d0

struct Item_25b7d0 {
    char d[12];
};

struct Link_25b7d0 {
    Link_25b7d0 *left;
};

struct Node : Link_25b7d0 {
    char pad4[0xc];
    Item_25b7d0 items[12];
};

struct Tree_25b7d0 {
    Link_25b7d0 *first;
    Link_25b7d0 head;
};

extern "C++" __declspec(nothrow) void __cdecl FUN_0025b5b0(void *, void *);
void __cdecl FUN_00247550(void *pool, Node *n);

extern "C" void __cdecl FUN_0025b7d0(void * t_)
{
    Tree_25b7d0 * t = (Tree_25b7d0 *)t_;
    while (t->first != &t->head) {
        Link_25b7d0 *l = t->first;
        while (l->left != &t->head)
            l = l->left;
        Node *n = (Node *)l;
        FUN_0025b5b0((Tree_25b7d0 *)t, (Node *)n);
        for (int i = 11; i >= 0; i--)
            ((owners::Str_240060 *)&(n->items[i]))->FUN_00240060();
        FUN_00247550(((char*)((char*)&DAT_004e7778)), n);
    }
}
} // namespace fn_0025b7d0

namespace fn_fd6abdd0 {

// 0x0025b850 FUN_0025b850 (83 B): matches/0x0025b850.cpp
// sym: ?target@fn_fd6abdd0@@YAXPAXPAUObj@1@@Z
// data: bss = DAT_004e7778
void __cdecl target(void* p, Obj* o) {
    FUN_0025b5b0(p, (Obj *)o);
    if (o) {
        Elem* e = o->arr + 10;
        int n = 10;
        do {
            --e;
            ((owners::Str_240060 *)e)->FUN_00240060();
        } while (--n);
        ((owners::Str_240060 *)&(o->b))->FUN_00240060();
        ((owners::Str_240060 *)&(o->a))->FUN_00240060();
        freeobj(((char*)((char*)&DAT_004e7778)), o);
    }
}

} // namespace fn_fd6abdd0

// 0x0025b8e0 FUN_0025b8e0 (91 B): equivalent/0x0025b8e0.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ?FUN_0025b8e0@fn_0025b8e0@@YAHPAUTree@1@@Z
namespace fn_0025b8e0 {
// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 18/22, incomplete)
// FUN_0025b8e0 @ 0x0025b8e0
// Number of nodes of a red-black tree (sentinel node `nil` stored right after the root pointer),
// counted by an in-order walk.
struct Node {
    Node* left;
    Node* right;
    Node* parent;
};

struct Tree {
    Node* root;
    Node nil;
};

static Node* Leftmost(Node* n, Node* nil)
{
    while (n->left != nil)
        n = n->left;
    return n;
}

// in-order successor; returns nil past the last node
static Node* Next(Node* n, Node* nil)
{
    if (n->right != nil)
        return Leftmost(n->right, nil);
    Node* p = n->parent;
    if (p == nil)
        return nil;
    while (n == p->right) {
        n = p;
        p = p->parent;
        if (p == nil)
            break;
    }
    return p;
}

int __cdecl FUN_0025b8e0(Tree* tree)
{
    Node* nil = &tree->nil;
    Node* cur = tree->root;
    int count = 0;
    if (cur == nil)
        return 0;
    cur = Leftmost(cur, nil);
    do {
        count++;
        cur = Next(cur, nil);
    } while (cur != nil && cur != 0);
    return count;
}
} // namespace fn_0025b8e0

namespace fn_fd6abdd0 {

// 0x0025b940 FUN_0025b940 (35 B): matches/0x0025b940.cpp
// sym: ?run@Target_25b940@fn_fd6abdd0@@QAEXXZ
void Target_25b940::run() {
    void* q = p;
    if (q)
        FUN_0025b7d0(q);
    q = *(void* volatile*)&p;
    if (q)
        FuncB(q);
}

} // namespace fn_fd6abdd0

// 0x0025b970 FUN_0025b970 (517 B): equivalent/0x0025b970.cpp [wrapped: conflict: Node]
// sym: ?FUN_0025b970@Section_25b970@fn_0025b970@@QAEDPAUWriter_25b970@2@@Z
namespace fn_0025b970 {
// STATUS: equivalent (tools/equiv.py level 3: 430 inputs, branch coverage 60/60)
// FUN_0025b970 @ 0x0025b970
struct Str_25b970 {
    char data[12];
    const char* FUN_0023fb00();
    char FUN_00240410(const char* s);
};

struct Stream {
    char pad00[0x24];
    int indent;
};

struct Writer_25b970 {
    Stream* out;
};

struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    Str_25b970 name;
    Str_25b970 defaultValue;
    Str_25b970 values[10];
};

struct Tree_25b970 {
    Node* root;
    Node nil;
};

char FUN_00246f50(Stream* s, const char* fmt, ...);
char FUN_0025ac30(Writer_25b970* w, int a, int b);
extern "C" const char* FUN_00262820(int index);

class Section_25b970 {
public:
    Tree_25b970* tree;
    char pad04[4];
    int dirtyTimeLo;
    int dirtyTimeHi;

    char FUN_0025b970(Writer_25b970* w);
};

char Section_25b970::FUN_0025b970(Writer_25b970* w)
{
    char ok;

    if (!FUN_00246f50(w->out, "[\n")) {
        ok = 0;
    } else {
        w->out->indent++;
        if (!FUN_00246f50(w->out, "DirtyTime : ")) {
            ok = 0;
        } else if (!FUN_0025ac30(w, dirtyTimeLo, dirtyTimeHi)) {
            ok = 0;
        } else if (!FUN_00246f50(w->out, "\n")) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (tree != 0) {
        Node* nil = &tree->nil;
        Node* node = 0;
        Node* first = tree->root;
        if (first != nil) {
            node = first;
            Node* left = node->left;
            if (left != nil) {
                do {
                    node = left;
                    left = node->left;
                } while (left != nil);
            }
        }
        // the original tests the first node for null even after walking down from it; the volatile read
        // keeps the compiler from assuming a dereferenced pointer is non-null
        Node* volatile first_node = node;
        node = first_node;

        while (node != 0) {
            if (ok) {
                Stream* s = w->out;
                if (FUN_00246f50(s, "\"%s\"\n[\n", node->name.FUN_0023fb00())) {
                    w->out->indent++;
                    ok = 1;
                } else {
                    ok = 0;
                }
            }

            if (node->defaultValue.FUN_00240410("")) {
                if (ok) {
                    Stream* s = w->out;
                    if (FUN_00246f50(s, "\"default\" : \"%s\"\n", node->defaultValue.FUN_0023fb00()))
                        ok = 1;
                    else
                        ok = 0;
                }
            }

            for (int i = 0; i < 10; i++) {
                if (node->values[i].FUN_00240410("")) {
                    if (ok) {
                        Stream* s = w->out;
                        const char* value = node->values[i].FUN_0023fb00();
                        if (FUN_00246f50(s, "\"%s\" : \"%s\"\n", FUN_00262820(i), value))
                            ok = 1;
                        else
                            ok = 0;
                    }
                }
            }

            if (ok) {
                w->out->indent--;
                if (FUN_00246f50(w->out, "]\n"))
                    ok = 1;
                else
                    ok = 0;
            } else {
                ok = 0;
            }

            // advance to the in-order successor
            Node* cur = node;
            Node* next = cur->right;
            nil = &tree->nil;
            if (next != nil) {
                while (next->left != nil)
                    next = next->left;
            } else {
                next = cur->parent;
                while (next != nil && cur == next->right) {
                    cur = next;
                    next = next->parent;
                }
            }
            node = (next == nil) ? 0 : next;
        }
    }

    if (ok) {
        w->out->indent--;
        if (FUN_00246f50(w->out, "]\n"))
            return 1;
    }
    return 0;
}
} // namespace fn_0025b970

namespace fn_fd6abdd0 {

// 0x0025bbd0 FUN_0025bbd0 (41 B): matches/0x0025bbd0.cpp
// sym: ?target@fn_fd6abdd0@@YIXPAUS_25bbd0@1@@Z
void __fastcall target(S_25bbd0* self) {
    if (self->value != 0) {
        FUN_0025b7d0((void *)(hulk_uintptr)(unsigned int)(self->value));
        if (self->value != 0)
            thunk_FUN_00267090(self->value);
        self->value = 0;
    }
}


// 0x0025bcb0 FUN_0025bcb0 (33 B): matches/0x0025bcb0.cpp
// sym: ?target@fn_fd6abdd0@@YAHPAHPAVC_25bcb0@1@@Z
int target(int* stream, C_25bcb0* item) {
    int value = *stream;
    int result = item->Get();
    return FUN_00246f50(value, format, result);
}


// 0x0025bce0 FUN_0025bce0 (117 B): equivalent/0x0025bce0.cpp
// sym: ?FUN_0025bce0@fn_fd6abdd0@@YA_NPAUHolder_25bce0@1@PAUPrinter_25bce0@1@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0025bce0 @ 0x0025bce0
bool __cdecl FUN_0025bce0(Holder_25bce0 *h, Printer_25bce0 *out)
{
    struct Frame {
        int len;
        char buf[0x400];
    } f;
    bool ok = FUN_0025abd0(h, &f.len);
    if (ok) {
        ok = h->reader->FUN_00246f00(f.buf, f.len + 1, 0, 1);
        if (!ok) {
            ((owners::String_23fe50 *)out)->FUN_0023fe50("");
            return false;
        }
        ((owners::String_23fe50 *)out)->FUN_0023fe50(f.buf);
    }
    return ok;
}


// 0x0025be60 FUN_0025be60 (29 B): equivalent/0x0025be60.cpp
// sym: _FUN_0025be60
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0025be60 @ 0x0025be60
extern "C" void __cdecl FUN_0025be60(unsigned int *source, unsigned int *destination)
{
    unsigned int value = *source;
    *destination = value;
    if ((*source & 15) == 4)
        *destination = value & ~15u;
}


// 0x0025be80 FUN_0025be80 (51 B): matches/0x0025be80.cpp
// sym: ?target@fn_fd6abdd0@@YAIHH@Z
unsigned int __cdecl target(int a, hulk_intptr b) {
    int x = FUN_0024c310(a);
    int y = FUN_0024c2f0(b);
    unsigned int z = FUN_0024c310(b);
    return (unsigned int)(y * x) / z;
}


// 0x0025bec0 FUN_0025bec0 (37 B): matches/0x0025bec0.cpp
// sym: _FUN_0025bec0
extern "C" void* __cdecl FUN_0025bec0(A_25bec0* p) {
    void* q = p->f2();
    if ((*(unsigned int*)q & 15) == 4)
        return helper(p);
    return p;
}


// 0x0025bfc0 FUN_0025bfc0 (12 B): matches/0x0025bfc0.cpp
// sym: ?FUN_0025bfc0@fn_fd6abdd0@@YADPBX@Z
char __cdecl FUN_0025bfc0(const void* p) {
    return p ? 0 : 1;
}

} // namespace fn_fd6abdd0

// 0x0025c000 FUN_0025c000 (56 B): matches/0x0025c000.cpp
// sym: ?FUN_0025c000@Target_25c000@owners@@QAEHPAX@Z
int owners::Target_25c000::FUN_0025c000(void* p) {
    if (Check(p, this) && Check(p, (char*)this + 4))
        return 1;
    return 0;
}

namespace fn_fd6abdd0 {

// 0x0025c040 FUN_0025c040 (6 B): matches/0x0025c040.cpp
// sym: _FUN_0025c040
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0025c040() {
    return &(*(int*)&DAT_004e7808);
}

} // namespace fn_fd6abdd0

// 0x0025c080 audio::OmHalStream::vfunc_10 (11 B): matches/0x0025c080.cpp
// sym: ?vfunc_10@OmHalStream@audio@@UAEXXZ
void audio::OmHalStream::vfunc_10() {
    helper((char*)this + 0x1bc);
}

namespace fn_fd6abdd0 {

// 0x0025c090 audio::OmHalStream::vfunc_0 (1 B): matches/0x0025c090.cpp
// sym: ?FUN_0025c090@fn_fd6abdd0@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0025c090() {}

} // namespace fn_fd6abdd0

// 0x0025c0a0 audio::OmHalStream::vfunc_1 (6 B): matches/0x0025c0a0.cpp
// sym: ?vfunc_1@OmHalStream@audio@@UAEHXZ
// Same code shape as 0x0004e0b0 (propagated; names are from that function)
int audio::OmHalStream::vfunc_1() {
    return 2;
}


// 0x0025c0b0 audio::OmHalStream::vfunc_2 (4 B): matches/0x0025c0b0.cpp
// sym: ?vfunc_2@OmHalStream@audio@@UAEPAXXZ
 // namespace audio
void* audio::OmHalStream::vfunc_2() {
    return (void*)((audio::OmHalStream*)((char*)this + 0xc));
}

namespace fn_fd6abdd0 {

// 0x0025c0c0 audio::OmHalStream::vfunc_4 (4 B): matches/0x0025c0c0.cpp
// sym: ?FUN_0025c0c0@fn_fd6abdd0@@YIHPAX@Z
// Same code shape as 0x00086320 (propagated; names are from that function)
int __fastcall FUN_0025c0c0(void* p) {
    return *(int*)((char*)p + 8);
}

} // namespace fn_fd6abdd0

// 0x0025c0d0 audio::OmHalStream::vfunc_7 (186 B): equivalent/0x0025c0d0.cpp [wrapped: conflict: audio::OmHalStream]
// sym: ?vfunc_7@OmHalStream@audio@fn_0025c0d0@@UAEIPAXHI@Z
namespace fn_0025c0d0 {
// STATUS: equivalent (tools/equiv.py level 3: 2980 inputs, branch coverage 10/10)
// audio::OmHalStream::vfunc_7 @ 0x0025c0d0

typedef unsigned int uint_25c0d0;
struct Reader { void FUN_00246f00(void*,uint_25c0d0,int,int); };
extern void* __cdecl FUN_00247530(void*);
extern void __cdecl FUN_00247550(void*,void*);
extern "C" void __cdecl FUN_00270390(void*,int,void*,int,uint_25c0d0);
namespace audio {
struct OmHalStream {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual uint_25c0d0 vfunc_7(void*,int,uint_25c0d0);
 Reader* reader; uint_25c0d0 capacity; char padding[0x1b4-12]; uint_25c0d0 count;
};
uint_25c0d0 OmHalStream::vfunc_7(void* output,int format,uint_25c0d0 requested) {
 count=requested>capacity?capacity:requested;
 if(format==1) { reader->FUN_00246f00(output,count,0,1); return count; }
 void* temporary=FUN_00247530(((char*)((char*)&DAT_004e7850)));
 uint_25c0d0 remaining=count;
 while(remaining!=0) {
 uint_25c0d0 chunk=((uint_25c0d0)DAT_004e7850->body.size);
 if(remaining<=chunk) chunk=remaining;
 reader->FUN_00246f00(temporary,chunk,0,1);
 FUN_00270390(output,format,temporary,1,chunk);
 output=(char*)output+chunk;
 remaining-=chunk;
 }
 FUN_00247550(((char*)((char*)&DAT_004e7850)),temporary);
 return count;
}
}
} // namespace fn_0025c0d0


// 0x0025c190 audio::OmHalStream::vfunc_6 (235 B): equivalent/0x0025c190.cpp [wrapped: conflict: audio::OmHalStream]
// sym: ?vfunc_6@OmHalStream@audio@fn_0025c190@@UAEXPAXII@Z
namespace fn_0025c190 {
// STATUS: equivalent (tools/equiv.py level 3: 2659 inputs, branch coverage 14/14)
// audio::OmHalStream::vfunc_6 @ 0x0025c190

struct Pool;
extern void* __cdecl FUN_00247530(Pool*);
extern void __cdecl FUN_00247550(Pool*, void*);
struct Device_25c190 { void FUN_00246f00(void*, unsigned int, int, int); };
struct Job_25c190 { virtual void start(); virtual void release(); virtual void slot2(); virtual bool done(); };
extern Job_25c190* __cdecl FUN_002703c0(void*, unsigned int, void*, int, unsigned int);
namespace audio {
struct OmHalStream {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(void*, unsigned int, unsigned int); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
Device_25c190* device; unsigned int size; char pad[0x1b4-0xc]; unsigned int count; void (__cdecl *wait)();
};
void OmHalStream::vfunc_6(void* dest, unsigned int mode, unsigned int requested) {
count = requested > size ? size : requested;
if (mode == 1) { device->FUN_00246f00(dest,count,0,1); return; }
void* buffer = FUN_00247530(((Pool*)((char*)&DAT_004e7850)));
unsigned int remaining=count;
while (remaining) {
unsigned int chunk = remaining > ((unsigned int)DAT_004e7850->body.size) ? ((unsigned int)DAT_004e7850->body.size) : remaining;
device->FUN_00246f00(buffer,chunk,0,1);
Job_25c190* job = FUN_002703c0(dest,mode,buffer,1,chunk);
job->start();
while (!job->done()) wait();
job->release();
dest = (char*)dest + chunk;
remaining -= chunk;
}
FUN_00247550(((Pool*)((char*)&DAT_004e7850)),buffer);
}
}
} // namespace fn_0025c190


// 0x0025c280 audio::OmHalStream::vfunc_8 (36 B): matches/0x0025c280.cpp
// sym: ?vfunc_8@OmHalStream@audio@@UAE_NPAX@Z
bool audio::OmHalStream::vfunc_8(void* __p0) { unsigned int * out = (unsigned int *)__p0;

    *out = this->f_1b4;
    int v = this->f_1b4;
    *(int*)((char*)this + 8) -= v;
    this->f_1b4 = 0;
    return true;
}


// 0x0025c2b0 audio::OmHalStream::vfunc_9 (17 B): matches/0x0025c2b0.cpp
// sym: ?vfunc_9@OmHalStream@audio@@UAEPAXH@Z
 // namespace audio
void* audio::OmHalStream::vfunc_9(int index) {
    return (void*)((char*)this + index * 16 + 0xb4);
}

namespace fn_fd6abdd0 {

// 0x0025c2d0 audio::OmHalStream::vfunc_11 (1 B): matches/0x0025c2d0.cpp
// sym: ?FUN_0025c2d0@fn_fd6abdd0@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0025c2d0() {}

} // namespace fn_fd6abdd0

// 0x0025c2e0 audio::OmHalStream::vfunc_5 (46 B): matches/0x0025c2e0.cpp
// sym: ?vfunc_5@OmHalStream@audio@@UAEXH@Z
void audio::OmHalStream::vfunc_5(int offset) {
    void* local;
    void** vt = (*(AudioDevice * *)&this->f_04)->vt;
    ((void (*)(void**, void**))vt[4])(vt, &local);
    vt = (*(AudioDevice * *)&this->f_04)->vt;
    ((void (*)(void**, void*))vt[5])(vt, (char*)local + offset);
}


// 0x0025c310 audio::OmHalStream::vfunc_3 (13 B): matches/0x0025c310.cpp [wrapped: conflict: audio::HalStream; audio::OmHalStream; helper]
// sym: ?vfunc_3@OmHalStream@audio@fn_0025c310@@UAEHXZ
namespace fn_0025c310 {
namespace audio {
class HalStream {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int vfunc_3();
};
class OmHalStream : public HalStream {
  public:
    char pad[8];
    char data[4];
    int vfunc_3();
};
} // namespace audio
int helper(void*);
int audio::OmHalStream::vfunc_3() {
    return helper(&data[0]);
}
} // namespace fn_0025c310

namespace fn_fd6abdd0 {

// 0x0025c320 FUN_0025c320 (212 B): equivalent/0x0025c320.cpp
// sym: ?FUN_0025c320@fn_fd6abdd0@@YAXPAUHeader_25c320@1@PAURow_25c320@1@EE@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 15/16, incomplete)
// FUN_0025c320 @ 0x0025c320
void __cdecl FUN_0025c320(Header_25c320* header, Row_25c320* output, unsigned char special, unsigned char extra)
{
    unsigned int count = (header->flags >> 4) & 31;
    if (count == 1) {
        unsigned int n;
        if (special) { output[0].values[0] = 8; n = 1; }
        else { output[0].values[0] = 1; output[0].values[1] = 2; n = 2; }
        if (extra) output[0].values[n++] = 7;
        while (n < 4) output[0].values[n++] = 0;
    } else {
        unsigned int i = 0;
        while (i < ((header->flags >> 4) & 31)) {
            output[i].values[0] = special ? 8 : ((i + 1) % 6);
            unsigned int n = 1;
            if (extra) output[i].values[n++] = 7;
            while (n < 4) output[i].values[n++] = 0;
            ++i;
        }
    }
}


// 0x0025c430 FUN_0025c430 (74 B): equivalent/0x0025c430.cpp
// sym: ?FUN_0025c430@fn_fd6abdd0@@YAEPAPAXI@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/7)
// FUN_0025c430 @ 0x0025c430
unsigned char __cdecl FUN_0025c430(void **destination, unsigned int encoding)
{
    const char *name;
    switch (encoding) {
    case 0: name = "HalEncodingType_Pcm"; break;
    case 1: name = "HalEncodingType_Vag"; break;
    case 2: name = "HalEncodingType_PcmBigEndian"; break;
    case 3: name = "HalEncodingType_XBoxAdpcm"; break;
    case 4: name = "HalEncodingType_RadicalAdpcm"; break;
    default: return 0;
    }
    return (unsigned char)FUN_00246f50(*destination, "%s", name);
}


// 0x0025c490 FUN_0025c490 (184 B): equivalent/0x0025c490.cpp
// sym: _FUN_0025c490
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0025c490 @ 0x0025c490
extern "C" bool __cdecl FUN_0025c490(void * reader, unsigned int* result)
{
    signed char kind;
    unsigned int first = 0, second = 0, third = 0;
    if (!FUN_0025aad0(((Reader *)reader), &kind)) return false;
    int savedKind = kind;
    if (!FUN_0025abd0(((Reader *)reader), &first)) return false;
    if (!FUN_0025abd0(((Reader *)reader), &second)) return false;
    if (!FUN_0025abd0(((Reader *)reader), &third)) return false;
    unsigned int packed = ((third & 31u) << 17) | (second & 0x1ffffu);
    packed = (packed << 5) | (first & 31u);
    *result = (packed << 4) | (*result & 0x80000000u) | (savedKind & 15);
    return true;
}

} // namespace fn_fd6abdd0

// 0x0025c6d0 FUN_0025c6d0 (239 B): equivalent/0x0025c6d0.cpp [wrapped: conflict: FUN_00246f50]
// sym: ?FUN_0025c6d0@fn_0025c6d0@@YA_NPAUContext@1@PBI@Z
namespace fn_0025c6d0 {
// STATUS: equivalent (tools/equiv.py level 3: 1155 inputs, branch coverage 12/12)
// FUN_0025c6d0 @ 0x0025c6d0

struct Stream { char pad[0x24]; int depth; };
struct Context { Stream* stream; };
struct Entry_25c6d0 { const char* text; unsigned int other; };
bool __cdecl FUN_00246f50(Stream*, const char*, ...);
struct Temp_25c6d0 { char data[12];   };
bool __cdecl FUN_0025bcb0(Context*, Temp_25c6d0*);
bool __cdecl FUN_0025c6d0(Context* context, const unsigned int* values) {
 if (!FUN_00246f50(context->stream, "\n[\n")) return false;
 ++context->stream->depth;
 for (unsigned int row=0; row<16; ++row) {
  for (unsigned int col=0; col<4; ++col) {
   Temp_25c6d0 temp;
   ((owners::String_23fc40 *)&temp)->FUN_0023fc40(((Entry_25c6d0*)&DAT_004cd1e4)[values[row*4+col]].text, (hulk_intptr)2);
   if (!FUN_0025bcb0(context, &temp)) { ((owners::Str_240060 *)&temp)->FUN_00240060(); return false; }
   if (!FUN_00246f50(context->stream, " ")) { ((owners::Str_240060 *)&temp)->FUN_00240060(); return false; }
   ((owners::Str_240060 *)&temp)->FUN_00240060();
  }
  if (!FUN_00246f50(context->stream, "\n")) return false;
 }
 --context->stream->depth;
 return FUN_00246f50(context->stream, "]\n") != 0;
}
} // namespace fn_0025c6d0

namespace fn_fd6abdd0 {

// 0x0025c7c0 FUN_0025c7c0 (76 B): equivalent/0x0025c7c0.cpp
// sym: _FUN_0025c7c0
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 6/6)
// FUN_0025c7c0 @ 0x0025c7c0
extern "C" int __cdecl FUN_0025c7c0(void* source, unsigned int* destination)
{
    unsigned int value;
    int result = 0;
    for (unsigned int row = 0; row < 64; row += 4) {
        for (unsigned int column = 0; column < 4; ++column) {
            result = FUN_0025abd0(source, &value);
            if (!(result & 255)) return result & ~255;
            destination[row + column] = value;
        }
    }
    return (result & ~255) | 1;
}


// 0x0025c920 FUN_0025c920 (359 B): equivalent/0x0025c920.cpp
// sym: ?FUN_0025c920@fn_fd6abdd0@@YAPAVStr_25c920@1@PAV21@PBV21@PB_K1@Z
// STATUS: equivalent (tools/equiv.py level 3: 12 inputs, branch coverage 6/8, incomplete)
// FUN_0025c920 @ 0x0025c920
Str_25c920* __cdecl FUN_0025c920(Str_25c920* out, const Str_25c920* dir, const unsigned long long* id, const Str_25c920* extra)
{
    Str_25c920 path;
    Str_25c920 tmp;
    Str_25c920 hex;
    char name[0x20];
    char ch[2];

    path.FUN_0023fd20(0x48);
    path.FUN_00240190(tmp.FUN_0023fc40("", 0));
    tmp.FUN_00240060();

    sprintf(name, "%8.8x", (unsigned int)(*id >> 32));
    sprintf(name + 8, "%8.8x", (unsigned int)*id);
    hex.FUN_0023fc90(name, 0x10, 2);

    if (dir)
        FUN_00262700(&path, dir);
    if (extra)
        FUN_00262700(&path, extra);

    ch[1] = 0;
    const char* p = hex.FUN_0023fb00();
    const char* end = p + DAT_004cd264;
    while (p < end) {
        ch[0] = *p;
        p++;
        FUN_00262700(&path, tmp.FUN_0023fc40(ch, 1));
        tmp.FUN_00240060();
    }
    FUN_00262700(&path, &hex);

    path.FUN_0023ff50(tmp.FUN_0023fc40(".rsd", 0));
    tmp.FUN_00240060();

    out->FUN_00240170(&path);
    hex.FUN_00240060();
    path.FUN_00240060();
    return out;
}


// 0x0025ca90 FUN_0025ca90 (24 B): matches/0x0025ca90.cpp
// sym: _FUN_0025ca90
extern "C" Pair* FUN_0025ca90(Pair* dst, Pair* src) {
    init();
    *dst = *src;
    return dst;
}


// 0x0025cab0 FUN_0025cab0 (138 B): matches/0x0025cab0.cpp
// sym: ?LookupKey@fn_fd6abdd0@@YAPAXHPAUKey_25cab0@1@HH@Z
// FUN_0025cab0 @ 0x0025cab0
void* LookupKey(int a1, Key_25cab0* key, int a3, int a4) {
    struct Frame { int id[2]; Tmp_25cab0 t; } f;
    f.id[0] = key->w0;
    f.id[1] = key->w1;
    FUN_0025c920(&f.t, a1, (Key_25cab0*)f.id, (key->flags & 1) ? FUN_00240780() : 0);
    void* r = FUN_002631f0(f.t.FUN_0023fb00(),
        FUN_0024c710()->FUN_0023fb00(), 0, 0, a3, (key->flags & 1) ? 0 : (void*)key->data, a4);
    ((owners::Str_240060 *)&(f.t))->FUN_00240060();
    return r;
}

} // namespace fn_fd6abdd0

// 0x0025cb40 FUN_0025cb40 (117 B): matches/0x0025cb40.cpp [wrapped: conflict: Check]
// sym: ?Run@Target_25cb40@fn_0025cb40@@QAEDPAPAUNode@2@@Z
namespace fn_0025cb40 {
extern "C++" __declspec(nothrow) char __cdecl Check(void*, const char*, ...);
extern "C" char __cdecl FUN_00252470(void*, const char*, void*);
struct Node {
    char pad[0x24];
    int count;
};
class Target_25cb40 {
  public:
    char Run(Node**);
};
char Target_25cb40::Run(Node** p) {
    if (Check(*p, "\n[\n")) {
        ++(*p)->count;
        if (FUN_00252470(p, "mMin", this)) {
            if (FUN_00252470(p, "mMax", (char*)this + 4)) {
                --(*p)->count;
                Node* n = *p;
                if (Check(n, "]"))
                    return 1;
            }
        }
    }
    return 0;
}
} // namespace fn_0025cb40


// 0x0025cbc0 FUN_0025cbc0 (173 B): matches/0x0025cbc0.cpp [wrapped: conflict: audio::OmHalStream]
// sym: ??0OmHalStream@audio@fn_0025cbc0@@QAE@PAUSource_25cbc0@2@III@Z
namespace fn_0025cbc0 {
struct Buffer_25cbc0 {
    char data[0x1a4];
};
struct State_25cbc0 {
    void FUN_0023fac0();
    void FUN_00240190(unsigned);
    char data[4];
};
struct SourceTable {
    void(__cdecl* slot0)();
    void(__cdecl* slot1)();
    void(__cdecl* slot2)();
    void(__cdecl* slot3)();
    void(__cdecl* get)(SourceTable*, unsigned*);
    void(__cdecl* set)(SourceTable*, unsigned);
};
struct Source_25cbc0 {
    SourceTable* table;
    void FUN_00246f00(Buffer_25cbc0*, unsigned, unsigned, unsigned);
};
extern "C" void __cdecl FUN_00263470(Buffer_25cbc0*);
void __cdecl FUN_00263480(unsigned*, Buffer_25cbc0*);
namespace audio {
struct OmHalStream {
    virtual void dummy();
    Source_25cbc0* source;
    unsigned remaining;
    unsigned result;
    Buffer_25cbc0 buffer;
    unsigned zero;
    unsigned option;
    State_25cbc0 state;
    OmHalStream(Source_25cbc0*, hulk_uintptr, hulk_uintptr, hulk_uintptr);
};
} // namespace audio
audio::OmHalStream::OmHalStream(Source_25cbc0* s, hulk_uintptr setup, hulk_uintptr count, hulk_uintptr opt) {
    source = s;
    remaining = count;
    zero = 0;
    option = opt;
    state.FUN_0023fac0();
    state.FUN_00240190(setup);
    unsigned position = 0;
    SourceTable* table = source->table;
    table->get(table, &position);
    source->FUN_00246f00(&buffer, 0x1a4, 0, 1);
    table = source->table;
    table->set(table, position + 0x800);
    remaining -= 0x800;
    FUN_00263470(&buffer);
    FUN_00263480(&result, &buffer);
}
} // namespace fn_0025cbc0

namespace fn_fd6abdd0 {

// 0x0025cc70 FUN_0025cc70 (47 B): matches/0x0025cc70.cpp
// sym: ?Init@OmHalStream@fn_fd6abdd0@@QAEPAV12@E@Z
OmHalStream* OmHalStream::Init(unsigned char flag) {
    vf = ((hulk_intptr)DAT_0042a850);
    ((owners::Str_240060 *)&inner)->FUN_00240060();
    if (flag & 1)
        Register((void*)((hulk_intptr)DAT_004e7808), this);
    return this;
}


// 0x0025ccf0 FUN_0025ccf0 (76 B): matches/0x0025ccf0.cpp
// sym: ?Target@fn_fd6abdd0@@YAEHPAUReceiver_25ccf0@1@@Z
unsigned char Target(int a, Receiver_25ccf0* b) {
    Temp_25ccf0 t;
    t.Init();
    unsigned char r = Work(a, &t);
    if (b)
        b->Send(t.Get());
    ((owners::Str_240060 *)&t)->FUN_00240060();
    return r;
}


// 0x0025cda0 FUN_0025cda0 (146 B): matches/0x0025cda0.cpp
// sym: ?FUN_0025cda0@Header_25cda0@fn_fd6abdd0@@QAE_NPAUStream@2@@Z
// FUN_0025cda0 @ 0x0025cda0
bool Header_25cda0::FUN_0025cda0(Stream *s)
{
    struct Frame {
        union {
            char bit;
            unsigned int slot;
        } enabled;
        unsigned int idBits;
    } f;
    f.enabled.bit = 0;
    f.idBits = 0;
    bool ok = FUN_0025ccf0(s, this)
        && FUN_0025aa80(s, &f.enabled.bit)
        && FUN_0025abd0(s, &f.idBits)
        && FUN_0025c490((Stream *)s, (unsigned int *)(Pair_25cda0 *)(&range));
    id = f.idBits;
    enabled = f.enabled.bit;
    return ok;
}


// 0x0025ce40 FUN_0025ce40 (61 B): equivalent/0x0025ce40.cpp
// sym: ?FUN_0025ce40@fn_fd6abdd0@@YGEPAPAUFileState@1@@Z
// STATUS: equivalent (tools/equiv.py level 3: 2758 inputs, branch coverage 2/2)
// FUN_0025ce40 @ 0x0025ce40
unsigned char __stdcall FUN_0025ce40(FileState **state)
{
    if (FUN_00246f50(*state, "\n[\n")) {
        ++(*state)->count;
        FUN_00246f50(*state, "%s ", "mFileName");
    }
    return 0;
}

} // namespace fn_fd6abdd0

// 0x0025ce80 audio::OmHalStream::vfunc_12 (40 B): matches/0x0025ce80.cpp [wrapped: conflict: audio::OmHalStream]
// sym: ?vfunc_12@OmHalStream@audio@fn_0025ce80@@QAEXXZ
namespace fn_0025ce80 {

namespace audio {
struct OmHalStream {
    void** vf;
    char pad[0x1b8];
    void vfunc_12();
};
} // namespace audio
extern int om_vftable;
struct Sub_25ce80 {
    void call();
};
extern void __cdecl FUN_00247550(void*, audio::OmHalStream*);
void audio::OmHalStream::vfunc_12() {
    if (this) {
        *(void**)this = &om_vftable;
        ((Sub_25ce80*)((char*)this + 0x1bc))->call();
        FUN_00247550((void*)((hulk_intptr)DAT_004e7808), this);
    }
}
} // namespace fn_0025ce80

namespace fn_fd6abdd0 {

// 0x0025cf10 FUN_0025cf10 (15 B): matches/0x0025cf10.cpp
// sym: ?target@Obj_25cf10@fn_fd6abdd0@@QAEPAU12@XZ
Obj_25cf10* Obj_25cf10::target() {
    inner.f();
    return this;
}


// 0x0025cf70 FUN_0025cf70 (160 B): equivalent/0x0025cf70.cpp
// sym: _FUN_0025cf70
// STATUS: equivalent (tools/equiv.py level 3: 1217 inputs, branch coverage 6/6)
// FUN_0025cf70 @ 0x0025cf70
// FUN_0025cf70 @ 0x0025cf70: fills each plane of a surface region with a constant byte and records the size
extern "C" char __cdecl FUN_0025cf70(Surface_25cf70 *s, unsigned int offset, unsigned int size, unsigned int *outSize)
{
    unsigned char fill = ((s->flags & 0x7c000000) == 0x20000000) ? 0x80 : 0;
    if (s->flags & 0x1f0) {
        unsigned int plane = 0;
        do {
            unsigned int planes = (s->flags >> 4) & 0x1f;
            memset(s->base + offset / planes, fill, size / planes);
            plane++;
        } while (plane < ((s->flags >> 4) & 0x1f));
    }
    *outSize = size;
    s->state = 3;
    return 1;
}


// 0x0025d010 FUN_0025d010 (37 B): matches/0x0025d010.cpp
// sym: _FUN_0025d010
unsigned char __cdecl FUN_0025d010(void* p) {
    Obj_25d010* o = (Obj_25d010*)p;
    if (o->state == 2)
        (*(Global_25d010* volatile*)&DAT_004e5ce0)->value = 0;
    o->state = 0;
    return 1;
}


// 0x0025d040 FUN_0025d040 (8 B): matches/0x0025d040.cpp
// sym: _FUN_0025d040
extern "C" u32_25d040 __cdecl FUN_0025d040(Obj_25d040* p) {
    return p->value;
}


// 0x0025d060 FUN_0025d060 (8 B): matches/0x0025d060.cpp
// sym: _FUN_0025d060
extern "C" int __cdecl FUN_0025d060(int base) {
    return base + 0x14;
}


// 0x0025d070 FUN_0025d070 (128 B): matches/0x0025d070.cpp
// sym: _FUN_0025d070
// FUN_0025d070 @ 0x0025d070
// 0x0025d070: claim the global slot for obj, reporting the current owner state through the out parameters
extern "C" bool FUN_0025d070(Obj_25d070* obj, int arg2, unsigned int arg3, int unused, int* out5, int* out6, unsigned int* out7)
{
    if ((*(Slot_25d070**)&DAT_004e5ce0)->owner != 0)
        return false;
    *out5 = (*(Slot_25d070**)&DAT_004e5ce0)->current;
    *out6 = 1;
    if (arg3 > (*(Slot_25d070**)&DAT_004e5ce0)->limit)
        *out7 = FUN_0026fd80((*(Slot_25d070**)&DAT_004e5ce0)->limit, FUN_0024c2f0(&obj->link));
    else
        *out7 = arg3;
    (*(Slot_25d070**)&DAT_004e5ce0)->field_08 = arg2;
    obj->claimed = 1;
    (*(Slot_25d070**)&DAT_004e5ce0)->owner = obj;
    return true;
}


// 0x0025d0f0 FUN_0025d0f0 (419 B): equivalent/0x0025d0f0.cpp
// sym: _FUN_0025d0f0
// STATUS: equivalent (tools/equiv.py level 3: 26 inputs, branch coverage 15/18, incomplete)
// FUN_0025d0f0 @ 0x0025d0f0
extern "C" void FUN_0025d0f0(Texture *t, int length)
{
    unsigned flags = t->flags;
    unsigned h = t->height;
    unsigned n = (flags >> 4) & 0x1f;
    unsigned rowStep = h / n;
    Source_25d0f0 *g = (*(Source_25d0f0**)&DAT_004e5ce0);
    unsigned char *end = g->base + length;
    unsigned bpp = (flags >> 0x1d) & 3;
    unsigned colStep = g->f08 / n;

    if ((flags & 0xf) == 0) {
        unsigned stride = n * bpp;
        if (n == 0) {
            t->state = 2;
            return;
        }
        unsigned rowOff = 0;
        unsigned colOff = 0;
        for (unsigned count = n; count != 0; count--) {
            unsigned char *dst = t->dst + rowOff + colStep;
            unsigned char *src = (*(Source_25d0f0**)&DAT_004e5ce0)->base + colOff;
            while (src < end) {
                *(unsigned short *)dst = *(unsigned short *)src;
                src += stride;
                dst += bpp;
            }
            rowOff += rowStep;
            colOff += bpp;
        }
        t->state = 2;
        return;
    }

    unsigned stride = n * 4;
    unsigned off = 0;
    for (unsigned j = 0; j < n; j++) {
        unsigned char *dst = t->dst + off + colStep;
        unsigned char *src = (*(Source_25d0f0**)&DAT_004e5ce0)->base + j * 4;
        while (src < end) {
            for (int k = 0; k < 9; k++) {
                *(unsigned *)dst = *(unsigned *)src;
                src += stride;
                dst += 4;
            }
        }
        off += rowStep;
    }
    t->state = 2;
}


// 0x0025d2d0 FUN_0025d2d0 (38 B): matches/0x0025d2d0.cpp
// sym: ?target@Obj_25d2d0@fn_fd6abdd0@@QAEPAU12@H@Z
Obj_25d2d0* Obj_25d2d0::target(int flags) {
    ((owners::Str_240060 *)(((Helper_25d2d0*)&member)))->FUN_00240060();
    if (flags & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e7898), this);
    return this;
}


// 0x0025d300 FUN_0025d300 (63 B): matches/0x0025d300.cpp
// sym: _FUN_0025d300
extern "C" void __cdecl FUN_0025d300(Obj_25d300* p) {
    FUN_00257f00((*(char**)&DAT_004e5ce0) + 0x14, p);
    if (p->p)
        FUN_00240c60(p->p);
    ((owners::Str_240060 *)(((At*)((char*)p + 0x1c))))->FUN_00240060();
    f247550(DAT_004e7898, p);
}

} // namespace fn_fd6abdd0

// 0x0025d340 FUN_0025d340 (126 B): matches/0x0025d340.cpp [wrapped: conflict: Node]
// sym: _FUN_0025d340
namespace fn_0025d340 {
// FUN_0025d340 @ 0x0025d340

struct Sub_25d340 {
    void FUN_0023fac0();
};

struct Node {
    char pad0[8];
    char flag;          // 0x08
    char pad9[3];
    int arg;            // 0x0c
    int handle;         // 0x10
    int value;          // 0x14
    int field18;        // 0x18
    Sub_25d340 sub;            // 0x1c
};

struct Registry_25d340 {
    char pad0[0x14];
    char list[4];       // 0x14
};

Node* __cdecl FUN_00247530(char* pool);
void __cdecl FUN_00247550(char* pool, Node* node);
extern "C" int __cdecl FUN_00240c20(int arg);
extern "C" void __cdecl FUN_00257e80(char* list, Node* node);

// Allocates and registers a node; frees it again when the handle lookup fails.
extern "C" Node* FUN_0025d340(int* src, int arg, char flag)
{
    Node* alloc = FUN_00247530((char*)DAT_004e7898);
    Node* n = alloc ? (alloc->sub.FUN_0023fac0(), alloc) : 0;
    n->flag = flag;
    n->value = *src;
    n->arg = arg;
    n->field18 = 0;
    n->handle = FUN_00240c20(arg);
    if (n->handle == 0) {
        ((owners::Str_240060 *)&(n->sub))->FUN_00240060();
        FUN_00247550((char*)DAT_004e7898, n);
        return 0;
    }
    FUN_00257e80((*(Registry_25d340**)&DAT_004e5ce0)->list, n);
    return n;
}
} // namespace fn_0025d340

namespace fn_fd6abdd0 {

// 0x0025d3d0 FUN_0025d3d0 (6 B): matches/0x0025d3d0.cpp
// sym: _FUN_0025d3d0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0025d3d0() {
    return &(*(int*)&DAT_004e78e0);
}

} // namespace fn_fd6abdd0

// 0x0025d3e0 FUN_0025d3e0 (4 B): matches/0x0025d3e0.cpp
// sym: ?FUN_0025d3e0@Object_25d3e0@owners@@QAEHXZ
int owners::Object_25d3e0::FUN_0025d3e0() {
    return mValue;
}


// 0x0025d3f0 FUN_0025d3f0 (82 B): matches/0x0025d3f0.cpp
// sym: ?FUN_0025d3f0@Obj_25d3f0@owners@@QAEXPAH@Z
void owners::Obj_25d3f0::FUN_0025d3f0(int* out) {
    if (out) {
        int v = value;
        if (v != 0) {
            int r = FUN_0024afe0(v);
            if (r == 2 && !flag) {
                *out = value;
                value = 0;
                state = 5;
                return;
            }
        } else {
            *out = 0;
        }
    }
    state = 5;
}


// 0x0025d480 FUN_0025d480 (173 B): equivalent/0x0025d480.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_0025d480@Target_25d480@fn_0025d480@@QAEII@Z
namespace fn_0025d480 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0025d480 @ 0x0025d480
struct Buffer_25d480 { unsigned int header; char data[256]; };
extern "C++" __declspec(nothrow) void __cdecl FUN_0025be60(unsigned int *, unsigned int *);
extern void __cdecl FUN_0025c320(Buffer_25d480*, void*, unsigned int, unsigned int);
extern unsigned int __cdecl FUN_0024c590(Buffer_25d480*, unsigned int);
extern unsigned int __cdecl FUN_0025be80(unsigned int, Buffer_25d480*);
extern "C" hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr, unsigned int);
struct Context;
struct Handler_25d480 { virtual unsigned int invoke(Context*, Buffer_25d480*, void*, unsigned int); };
struct Context { char pad0[0x8c]; unsigned int value; char pad90[0x1c]; Handler_25d480* handler; char padb0[4]; unsigned char flags; };
struct Owner_25d480 { char pad[0x44]; void* data; };
struct Target_25d480 { char pad0[4]; Owner_25d480* owner; char pad8[0x2c]; unsigned int result; char pad38[4]; Context* context; unsigned int FUN_0025d480(hulk_uintptr arg); };
unsigned int Target_25d480::FUN_0025d480(hulk_uintptr arg) {
 Buffer_25d480 buffer;
 FUN_0025be60((unsigned int *)(hulk_uintptr)(unsigned int)arg, (unsigned int *)(Buffer_25d480 *)(&buffer));
 void* data = owner->data;
 if (!data) {
  unsigned int flags = context->flags;
  data = buffer.data;
  FUN_0025c320(&buffer, data, flags & 1, (flags >> 1) & 1);
 }
 unsigned int a = FUN_0024c590(&buffer, context->value);
 unsigned int b = FUN_0025be80(arg, &buffer);
 hulk_uintptr c = FUN_0026fd50(a, b);
 Context* ctx = context;
 unsigned int r = ctx->handler->invoke(ctx, &buffer, data, c);
 result = r;
 return r;
}
} // namespace fn_0025d480

