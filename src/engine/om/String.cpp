// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00260d00..0x00261a80 (kind game, layer engine, confidence medium), dominant class om::String
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/engine/om.h"
#include "decls/data/records.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6df0856 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6df0856 {} using namespace fn_f6df0856;
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace fn_f6df0856 {
typedef unsigned int U_260de0;
struct H {
    void* vt;
    char pad[sizeof(OmType) - sizeof(void*)];  // the rest of an om::Type (records.h)
    void Fnf_002584d0(void*, void*, int, int);
    void Fng_002580e0();
};
extern U_260de0 __cdecl f2475_00247530(void*);
extern char hulk_at_0042aad0[];
class Part_260e60 {
  public:
};
struct TypeT_260e60 {
    char b[0x48];
    TypeT_260e60* Init_00260c70() throw();
    ~TypeT_260e60() throw();
};
struct DynAttrT_260e60;
extern "C" void FUN_00247550(TypeT_260e60*, DynAttrT_260e60*);
struct DynAttrT_260e60 {
    void* vf;
    char pad[0x14];
    Part_260e60 part;
    DynAttrT_260e60* Dtor(unsigned char flag) throw();
};
struct Node { Node* left; Node* right; char pad[8]; unsigned key; unsigned value; };
struct Tree { Node* root; Node sentinel; };
} // namespace fn_f6df0856
inline void* operator new(size_t, void* p) { return p; }
inline void operator delete(void*, void*) {}
namespace fn_f6df0856 {
void* __cdecl FUN_00247530(void* pool);
struct Registry;
extern "C++" __declspec(nothrow) char __cdecl FUN_00260f10(void *, void *, const unsigned *);
namespace om {
class String {
public:
    char data[8];
    String() throw();
    void FUN_00240190(const String* s);
};
}
namespace om {
class Type {
public:
    virtual void v0();
    unsigned int reserved04;  // records.h OmType
    OmTypeBody body;
    Type(void* a, void* b, int c, int d) throw();
    void FUN_002580e0();
};
}
namespace om {
template <class T> class TypeT : public Type {
public:
    virtual void v0();
    TypeT(void* a, void* b, int c, int d) throw() : Type(a, b, c, d) {}
};
}
namespace om {
class DynAttr {
public:
    virtual void v0();
    char pad[0x10];
    int key;
    DynAttr(const int* k) throw() : key(*k) {}
};
}
namespace om {
template <class T> class DynAttrT : public DynAttr {
public:
    virtual void v0();
    T value;
    DynAttrT(const int* k) : DynAttr(k) {}
};
}
struct Interp_2611b0;
struct Builtin {
    const char *name;
    const char *(__cdecl *fn)(Interp_2611b0 *in);
};
struct Str_2611b0 {
    char data[0x10];
    Str_2611b0 *FUN_0023fc40(const char *text, int len);
    const char *FUN_0023fb00();
    void FUN_00240060();
};
struct Symbols;
struct Interp_2611b0 {
    Symbols *symbols;        // 0x0000
    char pad04[0x2004 - 4];
    char *out;               // 0x2004
    char *cur;               // 0x2008
    char *end;               // 0x200c
};
void __cdecl FUN_00260b30(Interp_2611b0 *in);
int __cdecl FUN_002673a0(const char *text, int radix);
Str_2611b0 *__cdecl FUN_002610e0(Symbols *symbols, int *key);
struct Str_2613b0 {
    char data[0xc];
    Str_2613b0 *FUN_0023fc40(const char *text, int len);
    const char *FUN_0023fb00();
    int FUN_0023f990();
    void FUN_00240060();
    void FUN_00240190(Str_2613b0 *src);
};
struct Interp_2613b0 {
    Symbols *symbols;        // 0x0000
    char buf[0x2000];
    char *out;               // 0x2004
    char *cur;               // 0x2008
    char *end;               // 0x200c
};
const char *__cdecl FUN_002611b0(Interp_2613b0 *in);
struct Iter_261460 {
    int v;
};
int FUN_002611b0(int* p);
int FUN_002673a0(int a, int b);
hulk_intptr FUN_002610e0(int m, int* k);
void FUN_00261120(int m, int* k, Iter_261460* it);
struct Helper_261460 {
    char d[16];
    int Get_0023fb00();
};
struct Ctx_261500 {
    char pad[0x2004];
    char* out;
};
const char* Next_002611b0(Ctx_261500*);
extern "C" const char* __cdecl FUN_002611b0(const char*);
extern "C" char* __cdecl getText_002611b0(char*);
extern "C++" __declspec(nothrow) void* __cdecl FUN_002611b0(void*);
extern "C" hulk_freg __cdecl FUN_00260d00(void*);
struct Parser;
const char* __cdecl FUN_002611b0(Parser* p);
hulk_freg __cdecl FUN_00260d00(const char* text);
extern "C++" __declspec(nothrow) char* __cdecl FUN_002611b0(char*);
extern "C++" __declspec(nothrow) hulk_freg __cdecl FUN_00260d00(char*);
extern "C" void __cdecl FUN_00260be0(char*, float);
void __cdecl FUN_00260be0(const char *s, float v);
typedef unsigned int U_261980;
extern char* GetText_002611b0(U_261980);
extern "C" U_261980 FUN_00260b60(U_261980);
struct Parser_2619c0 {
    char pad[0x2004];
    char *cursor;
};
char *__cdecl FUN_002611b0(Parser_2619c0 *p);


// 0x00260d00 FUN_00260d00 (217 B): equivalent/0x00260d00.cpp
// sym: ?FUN_00260d00@fn_f6df0856@@YAMPBD@Z @4eb4d8cec31a @w5a0aae2a1182
// STATUS: equivalent (tools/equiv.py level 3: 20100 inputs, branch coverage 20/22, incomplete)
// FUN_00260d00 @ 0x00260d00
// atof-style parser: optional '-', digits, optional '.', up to six fractional digits.
// Any other character gives 0.
hulk_freg __cdecl FUN_00260d00(const char *s)
{
    int whole = 0;
    int frac = 0;
    int digits = 0;
    bool negative = false;
    bool inWhole = true;

    if (*s == '-') {
        negative = true;
        s++;
    }
    for (const char *p = s; *p; p++) {
        char c = *p;
        if (c == '.') {
            inWhole = false;
        } else if (c < '0' || c > '9') {
            return 0.0f;
        } else if (inWhole) {
            whole = whole * 10 + (c - '0');
        } else if (digits < 6) {
            frac = frac * 10 + (c - '0');
            digits++;
        }
    }

    int scale = 10;
    for (int k = 1; k < digits; k++)
        scale *= 10;
    hulk_freg value = whole + (1.0f / scale) * frac;
    if (negative)
        value = -value;
    return value;
}


// 0x00260de0 FUN_00260de0 (66 B): matches/0x00260de0.cpp
// sym: ?target@fn_f6df0856@@YAIXZ
U_260de0 __cdecl target() {
    H h;
    h.Fnf_002584d0((void*)((hulk_intptr)DAT_004e58d0), (void*)((hulk_intptr)DAT_004e58c8), 0x24, 4);
    h.vt = hulk_at_0042aad0;
    U_260de0 r = f2475_00247530(&h);
    h.Fng_002580e0();
    return r;
}


// 0x00260e60 om::DynAttrT<om::String>::vfunc_0 (70 B): matches/0x00260e60.cpp
// sym: ?Dtor@DynAttrT_260e60@fn_f6df0856@@QAEPAU12@E@Z
DynAttrT_260e60* DynAttrT_260e60::Dtor(unsigned char flag) throw() {
    vf = vA;
    ((owners::Str_240060 *)&part)->FUN_00240060();
    vf = vB;
    if (flag & 1) {
        TypeT_260e60 l;
        FUN_00247550(l.Init_00260c70(), this);
    }
    return this;
}

} // namespace fn_f6df0856

// 0x00260f10 FUN_00260f10 (451 B): equivalent/0x00260f10.cpp [wrapped: merged class would differ: Tree_260f10: field nil: Field(+0x4 Node nil) vs Field(+0x4 Node nil)]
// sym: _FUN_00260f10 @63535a0d0efb @w0efe3539a2d2
namespace fn_00260f10 {
// STATUS: equivalent (tools/equiv.py level 3: 169 inputs, branch coverage 39/40, incomplete)
// FUN_00260f10 @ 0x00260f10
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    unsigned key;
};

struct Tree_260f10 {
    Node* root;
    Node nil;
};

struct Holder_260f10 {
    int prefix;
    Node node;
};

extern "C" void FUN_002483b0(Tree_260f10* tree, Node* node);
extern "C" void FUN_00248400(Tree_260f10* tree, Node* node);

// Red-black tree unique-key insert with rebalance. color: 1 = red, 0 = black.
extern "C" char FUN_00260f10(void * tree_, void * nodeArg_, const unsigned* keyPtr)
{
    Tree_260f10 * tree = (Tree_260f10 *)tree_;
    Holder_260f10 * nodeArg = (Holder_260f10 *)nodeArg_;
    Node* nil = &tree->nil;
    Node* node = &nodeArg->node;
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
                    FUN_002483b0(tree, node);
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
                    FUN_00248400(tree, node);
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
} // namespace fn_00260f10

namespace fn_f6df0856 {

// 0x002610e0 FUN_002610e0 (54 B): equivalent/0x002610e0.cpp
// sym: ?FUN_002610e0@fn_f6df0856@@YAPAXPAUTree@1@PBI@Z @7117333b1e3d @w66b99381d8b1
// STATUS: equivalent (tools/equiv.py level 3: 702 inputs, branch coverage 10/10)
// FUN_002610e0 @ 0x002610e0
void* __cdecl FUN_002610e0(Tree* tree, const unsigned* key) { Node* node = tree->root; Node* end = &tree->sentinel; while (node != end) { if (*key < node->key) node = node->left; else if (*key > node->key) node = node->right; else { if (node == reinterpret_cast<Node*>(sizeof(Node*))) return 0; return &node->value; } } return 0; }


// 0x00261120 FUN_00261120 (137 B): equivalent/0x00261120.cpp
// sym: ?RegisterString@fn_f6df0856@@YAPAVString@om@1@PAURegistry@1@PAHPBV231@@Z @e787bc82d6ae @wbe14c23fd64f
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 2/2)
// FUN_00261120 @ 0x00261120
// equiv-map: ??0Type@om@@QAE@PAX0HH@Z = 0x002584d0
// equiv-map: ??0String@om@@QAE@XZ = 0x0023fac0
om::String* RegisterString(Registry* reg, int* key, const om::String* text) {
    om::TypeT<om::DynAttrT<om::String> > pool(((int*)&DAT_004e58d0), ((int*)&DAT_004e58c8), 0x24, 4);
    void* mem = FUN_00247530(&pool);
    pool.FUN_002580e0();
    om::DynAttrT<om::String>* attr = 0;
    if (mem)
        attr = new (mem) om::DynAttrT<om::String>(key);
    om::String* s = &attr->value;
    s->FUN_00240190(text);
    FUN_00260f10((Registry *)reg, attr, (const unsigned *)(int *)key);
    return s;
}


// 0x002611b0 FUN_002611b0 (499 B): equivalent/0x002611b0.cpp
// sym: ?FUN_002611b0@fn_f6df0856@@YAPBDPAUInterp_2611b0@1@@Z @030305cea058 @we6cdb1af7b6b
// STATUS: equivalent (tools/equiv.py level 3: 400 inputs, branch coverage 38/40, incomplete; run with --inputs 12000)
// FUN_002611b0 @ 0x002611b0
const char *__cdecl FUN_002611b0(Interp_2611b0 *in)
{
    if (in->cur >= in->end)
        return "";

    FUN_00260b30(in);
    char *p = in->cur;
    if (*p == '(') {
        in->cur = p + 1;
        const char *result = FUN_002611b0(in);
        FUN_00260b30(in);
        char *q = in->cur;
        if (!(q < in->end) && *q != ')')
            return "Missing )";
        in->cur = q + 1;
        return result;
    }

    char *token = in->out;
    while (p < in->end) {
        char c = *p;
        if (c == ' ' || c == '(' || c == ')')
            break;
        *in->out = c;
        in->out++;
        p++;
    }
    *in->out = 0;
    in->out++;
    in->cur = p;

    if (*token != '$')
        return token;

    Str_2611b0 name;
    int key = FUN_002673a0(name.FUN_0023fc40(token + 1, 2)->FUN_0023fb00(), 0);
    Str_2611b0 *found = FUN_002610e0(in->symbols, &key);
    name.FUN_00240060();

    if (found != 0) {
        char *start = in->out;
        const char *s = found->FUN_0023fb00();
        while (*s != 0) {
            *in->out = *s;
            in->out++;
            s++;
        }
        *in->out = 0;
        in->out++;
        return start;
    }

    for (int i = 0; i < DAT_004cd418; i++) {
        if (strcmp(token + 1, ((Builtin*)&DAT_004cd388)[i].name) == 0)
            return ((Builtin*)&DAT_004cd388)[i].fn(in);
    }
    return "Undefined symbol";
}


// 0x002613b0 FUN_002613b0 (164 B): matches/0x002613b0.cpp
// sym: _FUN_002613b0
// FUN_002613b0 @ 0x002613b0
extern "C" void __cdecl FUN_002613b0(Symbols *symbols, Str_2613b0 *dest, Str_2613b0 *src)
{
    Interp_2613b0 in;
    in.symbols = symbols;
    in.out = in.buf;
    in.cur = (char *)src->FUN_0023fb00();
    in.end = in.cur + src->FUN_0023f990();

    const char *last = "";
    for (const char *r = FUN_002611b0(&in); *r != 0; r = FUN_002611b0(&in))
        last = r;

    Str_2613b0 tmp;
    dest->FUN_00240190(tmp.FUN_0023fc40(last, 2));
    tmp.FUN_00240060();
}


// 0x00261460 FUN_00261460 (156 B): matches/0x00261460.cpp
// sym: _FUN_00261460
extern "C" int __cdecl FUN_00261460(int* p) {
    int a = FUN_002611b0(p);
    int b = FUN_002611b0(p);
    char tmp[12];
    int key;
    Helper_261460* h = ((Helper_261460 *)((owners::String_23fc40 *)(((Helper_261460*)tmp)))->FUN_0023fc40((const char *)(hulk_uintptr)(int)a, (hulk_intptr)2));
    int r = h->Get_0023fb00();
    key = FUN_002673a0(r, 0);
    ((owners::Str_240060 *)(((Helper_261460*)tmp)))->FUN_00240060();
    Helper_261460* f = (Helper_261460*)FUN_002610e0(*p, &key);
    if (!f) {
        Helper_261460* g = ((Helper_261460 *)((owners::String_23fc40 *)(((Helper_261460*)tmp)))->FUN_0023fc40((const char *)(hulk_uintptr)(int)b, (hulk_intptr)2));
        FUN_00261120(*p, &key, (Iter_261460*)g);
        ((owners::Str_240060 *)(((Helper_261460*)tmp)))->FUN_00240060();
        return b;
    }
    ((owners::String_23fe50 *)f)->FUN_0023fe50((const char *)(hulk_uintptr)(int)b);
    return b;
}


// 0x00261500 FUN_00261500 (108 B): matches/0x00261500.cpp
// sym: _FUN_00261500
extern "C" char* FUN_00261500(Ctx_261500* c) {
    char* start = c->out;
    *start = 0;
    char* d = start;
    const char* s = Next_002611b0(c);
    while (*s) {
        c->out = d;
        const char* p = s;
        char ch = *p;
        while (ch) {
            *d = ch;
            p++;
            d++;
            c->out = c->out + 1;
            ch = *p;
        }
        s = Next_002611b0(c);
    }
    *d = 0;
    c->out++;
    return start;
}


// 0x00261570 FUN_00261570 (95 B): matches/0x00261570.cpp
// sym: _FUN_00261570
extern "C" const char* __cdecl FUN_00261570(const char* s) {
    const char* x = FUN_002611b0(s);
    const char* y = FUN_002611b0(s);
    return strcmp(x, y) == 0 ? DAT_00429b50 : DAT_004269b4;
}


// 0x002615d0 FUN_002615d0 (95 B): matches/0x002615d0.cpp
// sym: _FUN_002615d0
// data: yesStr = DAT_00429b50
extern "C" char* __cdecl FUN_002615d0(char* p) {
    char* a = getText_002611b0(p);
    char* b = getText_002611b0(p);
    return strcmp(a, b) ? ((char*)&DAT_00429b50) : ((char*)&DAT_004269b4);
}


// 0x00261630 FUN_00261630 (67 B): matches/0x00261630.cpp
// sym: _FUN_00261630
extern "C" char* __cdecl FUN_00261630(void* value) {
    void* first = FUN_002611b0(value);
    void* second = FUN_002611b0(value);
    float firstValue = FUN_00260d00(first);
    float secondValue = FUN_00260d00(second);
    return firstValue > secondValue ? ((char*)&DAT_00429b50) : ((char*)&DAT_004269b4);
}


// 0x00261680 FUN_00261680 (67 B): matches/0x00261680.cpp
// sym: _FUN_00261680
extern "C" const char* __cdecl FUN_00261680(void* value) {
    void* first = FUN_002611b0(value);
    void* second = FUN_002611b0(value);
    float firstValue = FUN_00260d00(first);
    float secondValue = FUN_00260d00(second);
    return firstValue < secondValue ? ((char*)&DAT_00429b50) : ((char*)&DAT_004269b4);
}


// 0x002616d0 FUN_002616d0 (67 B): matches/0x002616d0.cpp
// sym: _FUN_002616d0
extern "C" const char* __cdecl FUN_002616d0(Parser* p) {
    const char* a = FUN_002611b0(p);
    const char* b = FUN_002611b0(p);
    float fa = FUN_00260d00(a);
    float fb = FUN_00260d00(b);
    return (fa >= fb) ? "t" : "nil";
}


// 0x00261720 FUN_00261720 (67 B): matches/0x00261720.cpp
// sym: _FUN_00261720
extern "C" const char* __cdecl FUN_00261720(void* value) {
    void* first = FUN_002611b0(value);
    void* second = FUN_002611b0(value);
    float left = FUN_00260d00(first);
    float right = FUN_00260d00(second);
    return left <= right ? ((char*)&DAT_00429b50) : ((char*)&DAT_004269b4);
}


// 0x00261770 FUN_00261770 (83 B): matches/0x00261770.cpp
// sym: _FUN_00261770
extern "C" void __cdecl FUN_00261770(char* s) {
    float sum = FUN_00260d00(FUN_002611b0(s));
    char* p = FUN_002611b0(s);
    while (*p) {
        sum += FUN_00260d00(p);
        p = FUN_002611b0(s);
    }
    FUN_00260be0(s, sum);
}

} // namespace fn_f6df0856

// 0x002617d0 FUN_002617d0 (83 B): matches/0x002617d0.cpp [wrapped: conflict: FUN_002611b0]
// sym: _FUN_002617d0
namespace fn_002617d0 {
extern "C++" __declspec(nothrow) char* __cdecl FUN_002611b0(const char*);
extern "C++" __declspec(nothrow) hulk_freg __cdecl FUN_00260d00(const char*);
extern "C++" __declspec(nothrow) void __cdecl FUN_00260be0(const char*, float);
extern "C" void __cdecl FUN_002617d0(const char* s) {
    float v = FUN_00260d00(FUN_002611b0(s));
    char* p = FUN_002611b0(s);
    while (*p) {
        v -= FUN_00260d00(p);
        p = FUN_002611b0(s);
    }
    FUN_00260be0(s, v);
}
} // namespace fn_002617d0

namespace fn_f6df0856 {

// 0x00261830 FUN_00261830 (107 B): matches/0x00261830.cpp
// sym: _FUN_00261830
// FUN_00261830 @ 0x00261830
extern "C" void FUN_00261830(const char *s)
{
    float t = FUN_00260d00(FUN_002611b0(s));
    const char *p = FUN_002611b0(s);
    while (*p != 0) {
        float f = FUN_00260d00(p);
        if (f != 0.0f)
            t = t / f;
        p = FUN_002611b0(s);
    }
    FUN_00260be0(s, t);
}

} // namespace fn_f6df0856

// 0x002618a0 FUN_002618a0 (122 B): matches/0x002618a0.cpp [wrapped: conflict: FUN_002611b0]
// sym: _FUN_002618a0
namespace fn_002618a0 {
// FUN_002618a0 @ 0x002618a0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double fmod(double x, double y);
#endif


struct Node {
    char pad0;
};
extern "C++" __declspec(nothrow) Node* __cdecl FUN_002611b0(void* owner);
extern "C++" __declspec(nothrow) hulk_freg __cdecl FUN_00260d00(void* node);
extern "C++" __declspec(nothrow) void __cdecl FUN_00260be0(void* owner, float value);

extern "C" void FUN_002618a0(void* owner) {
    float result = FUN_00260d00(FUN_002611b0(owner));
    char* node = (char*)FUN_002611b0(owner);
    while (*node) {
        float factor = FUN_00260d00(node);
        if (factor != 0.0f)
            result = (float)fmod(result, factor);
        node = (char*)FUN_002611b0(owner);
    }
    FUN_00260be0(owner, result);
}
} // namespace fn_002618a0

namespace fn_f6df0856 {

// 0x00261920 FUN_00261920 (83 B): matches/0x00261920.cpp
// sym: _FUN_00261920
extern "C" void __cdecl FUN_00261920(char* s) {
    float x = FUN_00260d00(FUN_002611b0(s));
    char* p = FUN_002611b0(s);
    while (*p) {
        x *= FUN_00260d00(p);
        p = FUN_002611b0(s);
    }
    FUN_00260be0(s, x);
}


// 0x00261980 FUN_00261980 (61 B): matches/0x00261980.cpp
// sym: _FUN_00261980
extern "C" hulk_uintptr __cdecl FUN_00261980(U_261980 param) {
    char* p = GetText_002611b0(param);
    if (*p == 't') {
        hulk_uintptr result = (hulk_uintptr)GetText_002611b0(param);
        FUN_00260b60(param);
        return result;
    }
    FUN_00260b60(param);
    return (hulk_uintptr)GetText_002611b0(param);
}


// 0x002619c0 FUN_002619c0 (111 B): equivalent/0x002619c0.cpp
// sym: _FUN_002619c0 @27602ca93ac1 @w4f80e911fe91
// STATUS: equivalent (tools/equiv.py level 3: 1006 inputs, branch coverage 9/10, incomplete)
// FUN_002619c0 @ 0x002619c0
extern "C" char *FUN_002619c0(Parser_2619c0 *p)
{
    char *start = p->cursor;
    p->cursor = start + 1;
    *start = 0;
    bool first = true;
    char *out = start;
    char *tok = FUN_002611b0(p);
    while (*tok != 0) {
        if (first) {
            first = false;
        } else {
            *out = ' ';
            out++;
        }
        while (*tok != 0) {
            *out = *tok;
            out++;
            tok++;
        }
        p->cursor = out + 1;
        tok = FUN_002611b0(p);
    }
    *out = 0;
    return start;
}

} // namespace fn_f6df0856
