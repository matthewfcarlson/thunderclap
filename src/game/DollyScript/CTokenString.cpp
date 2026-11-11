// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f9870..0x000fb3b0 (kind game, layer game, confidence high), dominant class DollyScript::CTokenString
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/DollyScript.h"
#include "decls/data/game/global.h"
#include "gen/content.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd8937bc {
#define TREE_TU_END }
namespace fn_fd8937bc {} using namespace fn_fd8937bc;
#include "game/DollyScript.h"

// ---- declarations shared by the functions below
namespace fn_fd8937bc {
class CTokenString {
  public:
    virtual void vfunc_0();
    virtual unsigned long long vfunc_1();
    virtual void vfunc_2();
};
extern "C" char DAT_0040ce5c[];
class CTokenFloat {
  public:
    virtual ~CTokenFloat();
    int m1;
    int m2;
    int m3;
    int m4;
    CTokenFloat(int a, int b, int c);
};
typedef unsigned long long u64_f9910;
struct CScriptToken_f9910 {
    virtual void vfunc_0();
    virtual u64_f9910 vfunc_1();
    virtual void vfunc_2();
};
struct CTokenSectionStart_f9910 : CScriptToken_f9910 {
    virtual u64_f9910 vfunc_1();
};
typedef unsigned long long u64_f9940;
struct CScriptToken_f9940 {
    virtual void vfunc_0();
    virtual u64_f9940 vfunc_1();
    virtual void vfunc_2();
};
struct CTokenSectionEnd_f9940 : CScriptToken_f9940 {
    virtual u64_f9940 vfunc_1();
};
struct FUN_0027b070 { FUN_0027b070(); virtual void dummy(); char pad[12]; int first; int second; int third; };
struct CRawScript_f9980 : FUN_0027b070 { CRawScript_f9980(int a, int b); };
extern void __cdecl thunk_0008d340(int);
struct Reader { char pad[0x10]; char *begin; int length; char *cursor; bool FUN_000f99d0(char *output); };
void thunk_FUN_00267090(hulk_intptr);
extern "C" void __cdecl free__0008d340(void* p);
extern "C" void* __cdecl alloc__0008d6d0(hulk_intptr n);
} // namespace fn_fd8937bc
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int strlen(const char*);
#endif
namespace fn_fd8937bc {
class StrHolder_f9ab0 {
  public:
    int mPad;
    char* mStr;
    void Set(char* src);
};
extern void* hulk_at_0040ce4c;
extern void* hulk_at_0040ce3c;
extern void __cdecl thunk_FUN_00267090(void*);
struct Token_f9b60 {
    void* vptr;
    char pad[12];
    void* p;
};
extern void Release_0008d340(void*);
extern int hulk_at_0040ceac;
extern int vtString;
extern int vtToken;
struct Obj_f9bc0 {
    int* vf;
    char pad[12];
    void* p;
};
class CTokenStatement {
  public:
    virtual void vfunc_0();
    virtual __int64 vfunc_1();
    virtual void vfunc_2();
};
extern "C" char DAT_0040cebc[];
extern "C" unsigned __int64 __cdecl MakeToken_0027b020(int);
class CTokenHashed {
  public:
    void* vftable;
    int a, b, c, d, e;
    CTokenHashed* Target(hulk_intptr p1, int p2, int p3, int p4);
};
typedef unsigned __int64 TypeId;
struct Node {
  public:
    virtual void Release(int);
    virtual TypeId type();
    Node* next;
    union { int count; int depth; int state; };
    void F(int _m_a0) { Release(_m_a0); }
};
struct Obj_f9a80 {
    Node* head;
    int value;
};
class Holder_f9b00 {
  public:
    Node* head;
    void Set(Node*);
};
struct Entry_f9d20 {
    int a;
    int b;
    Node* head;
    int pad;
};
extern char DAT_004a1934, DAT_004a13e4;
struct List_f9d70 { Node* first; };
extern void* __cdecl FUN_00344e74(Node*, int, const void*, const void*, int);
struct Cursor_f9d70 {
 char pad0[4];
 List_f9d70* list;
 Node* current;
 char pad1[9];
 unsigned char disabled;
 void* FUN_000f9d70();
};
class Item_f9e90 {
  public:
    char pad[4];
    Item_f9e90* next;
    int state;
};
class Owner_f9e90 {
  public:
    char pad[8];
    Item_f9e90* item;
    Item_f9e90* alternate;
    char pad2[4];
    char flag;
};
struct Result_f9ef0 {
    virtual void pad();
    virtual long long Get();
};
struct Head_f9ef0 {
    int pad;
    Node* first;
};
struct Owner_f9ef0 {
    char pad[8];
    Head_f9ef0* head;
};
struct Data {
    unsigned int a, b, c, d;
    unsigned char x, y;
};
struct Source {
    char pad[4];
    unsigned int a, b, c, d;
    unsigned char byte0, byte1;
    Data FUN_000fa0b0();
};
struct S_fa100 {
    char pad[0x10];
    unsigned char x;
    unsigned char y;
};
class C_fa100 {
    char p[4];

  public:
    int key;
    char q[0x0c];
    unsigned char out14;
    unsigned char out15;
    void f(S_fa100* src);
};
class CScriptToken_fa3d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
} // namespace fn_fd8937bc
namespace pure3d {
class NonCopyable_0fa3d0 : public CScriptToken_fa3d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_0fa3d0* f2(unsigned char);
};
}
namespace fn_fd8937bc {
void thunk_FUN_00267090(pure3d::NonCopyable_0fa3d0*);
class CScriptToken_fa430 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
} // namespace fn_fd8937bc
namespace pure3d {
class NonCopyable_0fa430 : public CScriptToken_fa430 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_0fa430* f2(unsigned char);
};
}
namespace fn_fd8937bc {
void thunk_FUN_00267090(pure3d::NonCopyable_0fa430*);
class CScriptToken_fa490 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
} // namespace fn_fd8937bc
namespace pure3d {
class NonCopyable_0fa490 : public CScriptToken_fa490 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_0fa490* f2(unsigned char);
};
}
namespace fn_fd8937bc {
void thunk_FUN_00267090(pure3d::NonCopyable_0fa490*);
struct Item_fa870 {
    int a;
    Item_fa870* next;
};
struct Hdr_fa870 {
    int count;
    void First_000f9b00(Item_fa870*);
};
struct Lst {
    Hdr_fa870* h;
    void Put(Item_fa870* it);
};
} // namespace fn_fd8937bc
namespace pure3d {
class NonCopyable_0fa920 : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_0fa920* f2(unsigned char);
};
}
namespace fn_fd8937bc {
void thunk_FUN_00267090(pure3d::NonCopyable_0fa920*);
class CScriptToken_fa9a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
} // namespace fn_fd8937bc
namespace pure3d {
class NonCopyable_0fa9a0 : public CScriptToken_fa9a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_0fa9a0* f2(unsigned char);
};
}
namespace fn_fd8937bc {
void thunk_FUN_00267090(pure3d::NonCopyable_0fa9a0*);
extern "C" char DAT_0040bf84[];
struct CScriptParser {
    void* vt;
    int arg;
    int a;
    int b;
    int c;
    unsigned char d;
    unsigned char e;
    CScriptParser(hulk_intptr);
};
struct Base_fad90 {
    int a;
    int b;
    int c;
};
struct Obj_fad90 {
    char pad0[8];
    Base_fad90* mRoot;
    Base_fad90* mCur;
    char pad10[4];
    unsigned char mDone;
};
extern hulk_intptr __cdecl GetThing(Base_fad90*, int, void*, void*, int);
extern int hulk_at_004a13e4;
extern int hulk_at_004a140c;
struct Vec3_fae50 {
    float x, y, z;
};
class Obj_fae50 {
    char pad[8];
    int active;

  public:
    float Next_000fad30();
    void Get(Vec3_fae50* out);
};
struct Obj {
    virtual void a();
    virtual __int64 b();   // returns 64 bits in edx:eax (callers 0x000f0590, 0x000f3270 push both)
};
extern Obj* __cdecl cast(Node*, int, void*, void*, int);
class Iter {
  public:
    char pad[8];
    Node* head;
    Node* current;
    char pad2[4];
    char done;
    __int64 Run();
};
typedef unsigned int u32_faf20;
extern void __cdecl Cast(hulk_uintptr, int, const int*, const int*, int);
} // namespace fn_fd8937bc
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace DollyScript {
class CScriptToken {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CScriptToken* vfunc_2();
    int zero;
    char pad[8];
    float value;
    CScriptToken(const CScriptToken&) throw();
};
}
namespace DollyScript {
class CTokenFloat : public CScriptToken {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CTokenFloat* vfunc_2();
    CTokenFloat(const CTokenFloat& a) throw() : CScriptToken(a) { value = a.value; }
};
}
namespace fn_fd8937bc {
struct ThisCall_000f9d70 {
    int GetThing_000f9d70();
};
extern "C" int __cdecl Setup(int, int, void*, void*, int);
extern int hulk_at_004a1934;
extern int RTTI2_fb110;
struct Obj_fb110 {
    char pad[8];
    int field8;
    int fieldc;
    char pad10[4];
    unsigned char field14;
    unsigned char field15;
};
struct Obj_fb150 {
    char pad0[8];
    Node* root;
    Node* cur;
    char pad10[4];
    char done;
    hulk_intptr next();
};
} // namespace fn_fd8937bc
extern "C" __int64 FUN_0027b020(hulk_intptr);
namespace fn_fd8937bc {
struct DynamicCaster_fb1c0 {
    virtual void cast();
};
struct Inventory {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int get(DynamicCaster_fb1c0*, __int64);
    virtual void d();
    virtual void use(int);
};
inline int find(Inventory* inv, __int64 key) {
    DynamicCaster_fb1c0 caster;
    return inv->get(&caster, key);
}
struct Loader {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3(void **caster, unsigned int low, unsigned int high);
};
extern char DAT_0040ced4[];
} // namespace fn_fd8937bc
extern __int64 __cdecl FUN_0027b020(void *item);

namespace fn_fd8937bc {

// 0x000f9870 DollyScript::CTokenString::vfunc_1 (8 B): matches/0x000f9870.cpp
// sym: ?vfunc_1@CTokenString@fn_fd8937bc@@UAE_KXZ
unsigned long long CTokenString::vfunc_1() {
    return 2;
}


// 0x000f9880 FUN_000f9880 (39 B): matches/0x000f9880.cpp
// sym: ??0CTokenFloat@fn_fd8937bc@@QAE@HHH@Z
CTokenFloat::CTokenFloat(int a, int b, int c) {
    m4 = a;
    m1 = 0;
    *(void**)this = (void*)((hulk_intptr)DAT_0040ce5c);
    m2 = b;
    m3 = c;
}

} // namespace fn_fd8937bc

// 0x000f98b0 DollyScript::CTokenFloat::vfunc_1 (8 B): matches/0x000f98b0.cpp [wrapped: conflict: CTokenFloat]
// sym: ?vfunc_1@CTokenFloat@fn_000f98b0@@UAE_KXZ
namespace fn_000f98b0 {
class CScriptToken {
  public:
    virtual void vfunc_0();
    virtual unsigned long long vfunc_1();
    virtual void vfunc_2();
};
class CTokenFloat : public CScriptToken {
  public:
    unsigned long long vfunc_1();
};
unsigned long long CTokenFloat::vfunc_1() {
    return 1;
}
} // namespace fn_000f98b0


// 0x000f98c0 FUN_000f98c0 (33 B): matches/0x000f98c0.cpp [wrapped: conflict: CScriptToken]
// sym: ??0CScriptToken@fn_000f98c0@@QAE@ABV01@@Z
namespace fn_000f98c0 {
class CScriptToken {
  public:
    virtual ~CScriptToken();
    int a;
    int b;
    int c;
    CScriptToken(const CScriptToken&);
};
CScriptToken::CScriptToken(const CScriptToken& other) {
    a = other.a;
    b = other.b;
    c = other.c;
}
} // namespace fn_000f98c0

namespace fn_fd8937bc {

// 0x000f9910 DollyScript::CTokenSectionStart::vfunc_1 (12 B): matches/0x000f9910.cpp
// sym: ?vfunc_1@CTokenSectionStart_f9910@fn_fd8937bc@@UAE_KXZ
// data: g_value_f9910 = DAT_004e0a08
u64_f9910 CTokenSectionStart_f9910::vfunc_1() {
    return (*(u64_f9910*)&DAT_004e0a08);
}


// 0x000f9940 DollyScript::CTokenSectionEnd::vfunc_1 (12 B): matches/0x000f9940.cpp
// sym: ?vfunc_1@CTokenSectionEnd_f9940@fn_fd8937bc@@UAE_KXZ
// Same code shape as 0x000f9910 (propagated; names are from that function)
// data: g_value_f9940 = DAT_004e0a10
u64_f9940 CTokenSectionEnd_f9940::vfunc_1() {
    return (*(u64_f9940*)&DAT_004e0a10);
}


// 0x000f9980 FUN_000f9980 (37 B): equivalent/0x000f9980.cpp
// sym: ??0CRawScript_f9980@fn_fd8937bc@@QAE@HH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000f9980 @ 0x000f9980
CRawScript_f9980::CRawScript_f9980(int a, int b) { first=a; third=a; second=b; }


// 0x000f99b0 FUN_000f99b0 (29 B): matches/0x000f99b0.cpp
// sym: ?run@CRawScript@fn_fd8937bc@@QAEXXZ
void CRawScript::run() {
    vptr = &rawVtable;
    thunk_0008d340(mArg);
    finish();
}


// 0x000f99d0 FUN_000f99d0 (84 B): equivalent/0x000f99d0.cpp
// sym: ?FUN_000f99d0@Reader@fn_fd8937bc@@QAE_NPAD@Z
// STATUS: equivalent (tools/equiv.py level 3: 104 inputs, branch coverage 9/10, incomplete)
// FUN_000f99d0 @ 0x000f99d0
bool Reader::FUN_000f99d0(char *output) { char *dest=output; if ((int)(cursor-begin)<length) { do { *dest++=*cursor; ++cursor; if (*cursor=='\n') { ++cursor; break; } } while ((int)(cursor-begin)<length); } *dest=0; return dest!=output; }


// 0x000f9a80 FUN_000f9a80 (46 B): matches/0x000f9a80.cpp
// sym: @FUN_000f9a80@4
extern "C" void __fastcall FUN_000f9a80(Obj_f9a80* self) {
    Node* p = self->head;
    while (p) {
        Node* n = p->next;
        p->F(1);
        p = n;
    }
    thunk_FUN_00267090(self->value);
}


// 0x000f9ab0 FUN_000f9ab0 (79 B): matches/0x000f9ab0.cpp
// sym: ?Set@StrHolder_f9ab0@fn_fd8937bc@@QAEXPAD@Z
void StrHolder_f9ab0::Set(char* src) {
    free__0008d340(mStr);
    if (src != 0) {
        mStr = (char*)alloc__0008d6d0(strlen(src) + 1);
        strcpy(mStr, src);
    }
}


// 0x000f9b00 FUN_000f9b00 (52 B): matches/0x000f9b00.cpp
// sym: ?Set@Holder_f9b00@fn_fd8937bc@@QAEXPAUNode@2@@Z
void Holder_f9b00::Set(Node* value) {
    Node* p = head;
    if (p) {
        do {
            Node* n = p->next;
            p->Release(1);
            p = n;
        } while (p);
    }
    head = value;
}

} // namespace fn_fd8937bc

// 0x000f9b40 FUN_000f9b40 (30 B): matches/0x000f9b40.cpp
// sym: ?FUN_000f9b40@Node_f9b40@owners@@QAEXPAU12@@Z
void owners::Node_f9b40::FUN_000f9b40(owners::Node_f9b40* p) {
    owners::Node_f9b40* cur = this;
    if (cur != p) {
        do {
            if (cur->next == 0) {
                cur->next = p;
                return;
            }
            cur = cur->next;
        } while (cur != p);
    }
}

namespace fn_fd8937bc {

// 0x000f9b60 FUN_000f9b60 (40 B): matches/0x000f9b60.cpp
// sym: ?FUN_000f9b60@fn_fd8937bc@@YIXPAUToken_f9b60@1@@Z
void __fastcall FUN_000f9b60(Token_f9b60* self) {
    self->vptr = &hulk_at_0040ce4c;
    if (self->p) {
        thunk_FUN_00267090(self->p);
        self->p = 0;
    }
    self->vptr = &hulk_at_0040ce3c;
}


// 0x000f9bc0 FUN_000f9bc0 (69 B): matches/0x000f9bc0.cpp
// sym: ?FUN_000f9bc0@fn_fd8937bc@@YIXPAUObj_f9bc0@1@@Z
void __fastcall FUN_000f9bc0(Obj_f9bc0* o) {
    o->vf = &hulk_at_0040ceac;
    if (o->p) {
        Release_0008d340(o->p);
        o->p = 0;
    }
    o->vf = &vtString;
    if (o->p) {
        Release_0008d340(o->p);
        o->p = 0;
    }
    o->vf = &vtToken;
}


// 0x000f9c10 DollyScript::CTokenStatement::vfunc_1 (8 B): matches/0x000f9c10.cpp
// sym: ?vfunc_1@CTokenStatement@fn_fd8937bc@@UAE_JXZ
__int64 CTokenStatement::vfunc_1() {
    return 3;
}


// 0x000f9c20 FUN_000f9c20 (59 B): matches/0x000f9c20.cpp
// sym: ?Target@CTokenHashed@fn_fd8937bc@@QAEPAV12@HHHH@Z
CTokenHashed* CTokenHashed::Target(hulk_intptr p1, int p2, int p3, int p4) {
    a = 0;
    b = 0;
    c = 0;
    vftable = (void*)((hulk_intptr)DAT_0040cebc);
    unsigned __int64 v = MakeToken_0027b020(p1);
    d = (int)v;
    e = (int)(v >> 32);
    b = p2;
    c = p3;
    return this;
}

} // namespace fn_fd8937bc

// 0x000f9ca0 DollyScript::CTokenHashed::vfunc_1 (7 B): matches/0x000f9ca0.cpp [wrapped: conflict: CScriptToken; CTokenHashed]
// sym: ?vfunc_1@CTokenHashed@fn_000f9ca0@@UAE_KXZ
namespace fn_000f9ca0 {
typedef unsigned long long U64_f9ca0;
class CScriptToken {
  public:
    virtual void vfunc_0();
    virtual U64_f9ca0 vfunc_1();
    virtual void vfunc_2();
};
class CTokenHashed : public CScriptToken {
  public:
    char pad[12];
    virtual U64_f9ca0 vfunc_1();
};
U64_f9ca0 CTokenHashed::vfunc_1() {
    return *(U64_f9ca0*)((char*)this + 0x10);
}
} // namespace fn_000f9ca0

namespace fn_fd8937bc {

// 0x000f9d20 FUN_000f9d20 (70 B): matches/0x000f9d20.cpp
// sym: ?ClearEntries@fn_fd8937bc@@YIXPAUEntry_f9d20@1@@Z
void __fastcall ClearEntries(Entry_f9d20* p) {
    int i = 128;
    do {
        if (p->a | p->b) {
            Node* n = p->head;
            while (n) {
                Node* nx = n->next;
                n->Release(1);
                n = nx;
            }
            p->a = 0;
            p->b = 0;
        }
        p++;
    } while (--i != 0);
}


// 0x000f9d70 FUN_000f9d70 (221 B): equivalent/0x000f9d70.cpp
// sym: ?FUN_000f9d70@Cursor_f9d70@fn_fd8937bc@@QAEPAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 33/34, incomplete)
// FUN_000f9d70 @ 0x000f9d70
void* Cursor_f9d70::FUN_000f9d70() {
 if (disabled == 1) return 0;
 Node* node = current ? current->next : list->first;
 int nesting = 0;
 if (node) {
  TypeId t = node->type();
  if ((unsigned long)t == (*(unsigned long*)&DAT_004e0a08) && (unsigned long)(t >> 32) == (*(unsigned long*)((char*)&DAT_004e0a08 + 4))) nesting = 1;
  else {
   t = node->type();
   if ((unsigned long)t == (*(unsigned long*)&DAT_004e0a10) && (unsigned long)(t >> 32) == (*(unsigned long*)((char*)&DAT_004e0a10 + 4))) nesting = -1;
  }
  while (node->depth > 1 || nesting > 0) {
   node = node->next;
   if (!node) break;
   t = node->type();
   if ((unsigned long)t == (*(unsigned long*)&DAT_004e0a08) && (unsigned long)(t >> 32) == (*(unsigned long*)((char*)&DAT_004e0a08 + 4))) ++nesting;
   else {
    t = node->type();
    if ((unsigned long)t == (*(unsigned long*)&DAT_004e0a10) && (unsigned long)(t >> 32) == (*(unsigned long*)((char*)&DAT_004e0a10 + 4))) --nesting;
   }
  }
  if (node) {
   t = node->type();
   if ((unsigned long)t == (*(unsigned long*)&DAT_004e0a10) && (unsigned long)(t >> 32) == (*(unsigned long*)((char*)&DAT_004e0a10 + 4)) && nesting == 0) node = node->next;
  }
 }
 return FUN_00344e74(node, 0, &DAT_004a13e4, &DAT_004a1934, 0);
}

} // namespace fn_fd8937bc

// 0x000f9e50 FUN_000f9e50 (12 B): matches/0x000f9e50.cpp
// sym: ?FUN_000f9e50@ThisWrap_000f9e50@owners@@QAE_NXZ
bool owners::ThisWrap_000f9e50::FUN_000f9e50(void) {
    return this->FUN_000f9d70() != 0;
}

namespace fn_fd8937bc {

// 0x000f9e90 FUN_000f9e90 (50 B): matches/0x000f9e90.cpp
// sym: ?FUN_000f9e90@fn_fd8937bc@@YI_NPAVOwner_f9e90@1@@Z
bool __fastcall FUN_000f9e90(Owner_f9e90* self) {
    Item_f9e90* p = self->item;
    if (p != 0 && self->flag != 1) {
        Item_f9e90* q = self->alternate;
        if (q == 0)
            p = p->next;
        else
            p = q->next;
        if (p != 0 && p->state < 2)
            p = 0;
    } else
        p = 0;
    return p != 0;
}


// 0x000f9ef0 FUN_000f9ef0 (56 B): matches/0x000f9ef0.cpp
// sym: ?FUN_000f9ef0@fn_fd8937bc@@YI_NPAUOwner_f9ef0@1@@Z
// data: g_val = DAT_004e0a08
bool __fastcall FUN_000f9ef0(Owner_f9ef0* self) {
    Head_f9ef0* h = self->head;
    if (h) {
        Node* n = h->first;
        while (n) {
            if (n->count <= 1) {
                long long v = ((Result_f9ef0*)n)->Get();
                if (v == (*(long long*)&DAT_004e0a08))
                    return true;
                return false;
            }
            n = n->next;
        }
    }
    return false;
}

} // namespace fn_fd8937bc

// 0x000f9f30 FUN_000f9f30 (119 B): equivalent/0x000f9f30.cpp [wrapped: conflict: Node]
// sym: ?FUN_000f9f30@Chain_f9f30@fn_000f9f30@@QAEXXZ
namespace fn_000f9f30 {
// STATUS: equivalent (tools/equiv.py level 3: 1911 inputs, branch coverage 22/22)
// FUN_000f9f30 @ 0x000f9f30

class Node {
public:
    virtual void v0();
    virtual unsigned __int64 Key();
    Node* next;
    int depth;
};


struct Chain_f9f30 {
    char pad0[8];
    Node* head;
    int pad0c;
    int count;
    void FUN_000f9f30();
};

void Chain_f9f30::FUN_000f9f30() {
    if (head == 0)
        return;
    Node* n = head->next;
    if (n == 0)
        return;
    while (n->depth > 1) {
        n = n->next;
        if (n == 0)
            return;
    }
    if (n->Key() != (*(unsigned __int64*)&DAT_004e0a08))
        return;
    Node* m = head->next;
    if (m == 0)
        return;
    while (m->depth > 1) {
        m = m->next;
        if (m == 0)
            return;
    }
    if (m->Key() != (*(unsigned __int64*)&DAT_004e0a08))
        return;
    count++;
    head = m;
}
} // namespace fn_000f9f30


// 0x000f9fb0 FUN_000f9fb0 (116 B): equivalent/0x000f9fb0.cpp [wrapped: conflict: Node]
// sym: ?FUN_000f9fb0@NodeList_f9fb0@fn_000f9fb0@@QAEXXZ
namespace fn_000f9fb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 19/20, incomplete)
// FUN_000f9fb0 @ 0x000f9fb0

class Node {
public:
    virtual void v0();
    virtual unsigned __int64 Kind();
    Node *next;
};

class NodeList_f9fb0 {
public:
    char pad0[8];
    Node *cur;
    int f0c;
    int depth;
    void FUN_000f9fb0();
};

void NodeList_f9fb0::FUN_000f9fb0()
{
    Node *n = cur;
    if (n == 0)
        return;
    int level = 0;
    while (level >= 0) {
        n = n->next;
        if (n == 0)
            return;
        if (n->Kind() == (*(unsigned __int64*)&DAT_004e0a08))
            level++;
        else if (n->Kind() == (*(unsigned __int64*)&DAT_004e0a10))
            level--;
    }
    if (n != 0 && n->Kind() == (*(unsigned __int64*)&DAT_004e0a10)) {
        depth--;
        cur = n;
    }
}
} // namespace fn_000f9fb0

namespace fn_fd8937bc {

// 0x000fa0a0 FUN_000fa0a0 (1 B): matches/0x000fa0a0.cpp
// sym: ?FUN_000fa0a0@fn_fd8937bc@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000fa0a0() {}


// 0x000fa0b0 FUN_000fa0b0 (65 B): matches/0x000fa0b0.cpp
// sym: ?FUN_000fa0b0@Source@fn_fd8937bc@@QAE?AUData@2@XZ
Data Source::FUN_000fa0b0() {
    Data t;
    t.a = a;
    t.b = b;
    t.c = c;
    t.d = d;
    t.x = byte1;
    t.y = byte0;
    return t;
}


// 0x000fa100 FUN_000fa100 (44 B): matches/0x000fa100.cpp
// sym: ?f@C_fa100@fn_fd8937bc@@QAEXPAUS_fa100@2@@Z
void C_fa100::f(S_fa100* src) {
    if (*(int*)src == key) {
        *(int*)((char*)this + 8) = *(int*)((char*)src + 4);
        *(int*)((char*)this + 0xc) = *(int*)((char*)src + 8);
        *(int*)((char*)this + 0x10) = *(int*)((char*)src + 0xc);
        out14 = src->y;
        out15 = src->x;
    }
}

} // namespace fn_fd8937bc

// 0x000fa300 DollyScript::CTokenString::vfunc_0 (60 B): matches/0x000fa300.cpp [wrapped: conflict: CTokenString]
// sym: ?vfunc_0@CTokenString@fn_000fa300@@QAEPAV12@E@Z
namespace fn_000fa300 {
extern "C++" __declspec(nothrow) void __cdecl thunk_FUN_00267090_a(void*);
extern "C++" __declspec(nothrow) void __cdecl thunk_FUN_00267090_b(void*);
extern "C++" { extern void* g_vtStr[]; }
extern "C++" { extern void* g_vtBase[]; }

class CTokenString {
  public:
    void** mVptr;
    char pad[0xC];
    void* mPtr;
    CTokenString* vfunc_0(unsigned char param);
};

CTokenString* CTokenString::vfunc_0(unsigned char param) {
    this->mVptr = g_vtStr;
    if (this->mPtr != 0) {
        thunk_FUN_00267090_a(this->mPtr);
        this->mPtr = 0;
    }
    this->mVptr = g_vtBase;
    if (param & 1) {
        thunk_FUN_00267090_b((void*)this);
    }
    return this;
}
} // namespace fn_000fa300


// 0x000fa370 DollyScript::CTokenStatement::vfunc_0 (89 B): matches/0x000fa370.cpp [wrapped: conflict: CTokenStatement]
// sym: ?vfunc_0@CTokenStatement@fn_000fa370@@QAEPAXI@Z
void __cdecl operator delete(void* p);
namespace fn_000fa370 {
extern "C++" __declspec(nothrow) void __cdecl thunk_FUN_00267090(void* p);

extern const int g_vt_statement;
extern const int g_vt_string;
extern const int g_vt_scripttoken;

struct CTokenStatement {
    void* vptr;
    char pad[0xc];
    void* m0x10;
    void* vfunc_0(unsigned int flags);
};

void* CTokenStatement::vfunc_0(unsigned int flags) {
    this->vptr = (void*)&g_vt_statement;
    if (this->m0x10) {
        thunk_FUN_00267090(this->m0x10);
        this->m0x10 = 0;
    }
    this->vptr = (void*)&g_vt_string;
    if (this->m0x10) {
        thunk_FUN_00267090(this->m0x10);
        this->m0x10 = 0;
    }
    this->vptr = (void*)&g_vt_scripttoken;
    if (flags & 1) {
        operator delete(this);
    }
    return this;
}
} // namespace fn_000fa370


// 0x000fa3d0 DollyScript::CTokenFloat::vfunc_0 (31 B): matches/0x000fa3d0.cpp
// sym: ?f2@NonCopyable_0fa3d0@pure3d@@UAEPAV12@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_0fa3d0* pure3d::NonCopyable_0fa3d0::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x000fa3f0 DollyScript::CTokenSectionStart::vfunc_2 (54 B): matches/0x000fa3f0.cpp [wrapped: merged class would differ: CTokenSectionStart: field value: Field(+0x14 int value) vs Field(+0x4 int value)]
// sym: ?f2@CTokenSectionStart@DollyScript@fn_000fa3f0@@UAEPAVCScriptToken@23@XZ
namespace fn_000fa3f0 {
/* size_t: tree_prelude.h */

namespace DollyScript {
class CScriptToken {
  public:
    CScriptToken(CScriptToken const&) throw();
    virtual void f0();
    virtual void f1();
    virtual CScriptToken* f2();
};
class CTokenSectionStart : public CScriptToken {
  public:
    int value;
    char pad[8];
    CTokenSectionStart(CTokenSectionStart const& src) throw() : CScriptToken(src) {}
    virtual CScriptToken* f2();
};
CScriptToken* CTokenSectionStart::f2() {
    CTokenSectionStart* p = new CTokenSectionStart(*this);
    p->value = 0;
    return p;
}
} // namespace DollyScript
} // namespace fn_000fa3f0


// 0x000fa430 DollyScript::CTokenSectionStart::vfunc_0 (31 B): matches/0x000fa430.cpp
// sym: ?f2@NonCopyable_0fa430@pure3d@@UAEPAV12@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_0fa430* pure3d::NonCopyable_0fa430::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x000fa450 DollyScript::CTokenSectionEnd::vfunc_2 (54 B): matches/0x000fa450.cpp [wrapped: merged class would differ: CTokenSectionEnd: field value: Field(+0x14 int value) vs Field(+0x4 int value)]
// sym: ?vfunc_2@CTokenSectionEnd@DollyScript@fn_000fa450@@UAEPAVCScriptToken@23@XZ
namespace fn_000fa450 {
/* size_t: tree_prelude.h */

namespace DollyScript {
class CScriptToken {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CScriptToken* vfunc_2();
    CScriptToken(CScriptToken*) throw();
};
class CTokenSectionEnd : public CScriptToken {
  public:
    int value;
    char pad[8];
    CTokenSectionEnd(CTokenSectionEnd* p) throw() : CScriptToken(p) {}
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CScriptToken* vfunc_2();
};
CScriptToken* CTokenSectionEnd::vfunc_2() {
    CTokenSectionEnd* p = new CTokenSectionEnd(this);
    p->value = 0;
    return p;
}
} // namespace DollyScript
} // namespace fn_000fa450


// 0x000fa490 DollyScript::CTokenSectionEnd::vfunc_0 (31 B): matches/0x000fa490.cpp
// sym: ?f2@NonCopyable_0fa490@pure3d@@UAEPAV12@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_0fa490* pure3d::NonCopyable_0fa490::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x000fa5a0 FUN_000fa5a0 (717 B): equivalent/0x000fa5a0.cpp [wrapped: merged class would differ: CTokenSectionStart: field a: Field(+0x18 int a) vs Field(+0x8 int a)]
// sym: ?FUN_000fa5a0@fn_000fa5a0@@YGPAVCToken@DollyScript@1@PAPADPBDHH1@Z
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_000fa5a0 {
// STATUS: equivalent (tools/equiv.py level 3: 253 inputs, branch coverage 76/76)
// FUN_000fa5a0 @ 0x000fa5a0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char *__cdecl strncpy(char *dst, const char *src, unsigned int n);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl isdigit(int c);
#endif



extern void *__cdecl FUN_0008d690(unsigned int size);
extern "C" char *__cdecl FUN_0008d6d0(unsigned int size);
extern char *__cdecl FUN_003465c6(char *s, const char *delims);
extern double __cdecl FUN_003458c1(const char *s);

namespace DollyScript {

class CToken {
public:
    virtual void vfunc_0();
    virtual unsigned long long vfunc_1();
    virtual void vfunc_2();
    int next;
    int a;
    int b;
};

class CTokenStatement {
public:
    CTokenStatement(char *t, int a_, int b_) : next(0), a(a_), b(b_), text(t) {}
    virtual void vfunc_0();
    virtual unsigned long long vfunc_1();
    virtual void vfunc_2();
    int next;
    int a;
    int b;
    char *text;
};

class CTokenString {
public:
    CTokenString(char *t, int a_, int b_) : next(0), a(a_), b(b_), text(t) {}
    virtual void vfunc_0();
    virtual unsigned long long vfunc_1();
    virtual void vfunc_2();
    int next;
    int a;
    int b;
    char *text;
};

class CTokenSectionStart {
public:
    CTokenSectionStart(int b_) : next(0), a(0), b(b_) {}
    virtual void vfunc_0();
    virtual unsigned long long vfunc_1();
    virtual void vfunc_2();
    int next;
    int a;
    int b;
};

class CTokenSectionEnd {
public:
    CTokenSectionEnd(int b_) : next(0), a(0), b(b_) {}
    virtual void vfunc_0();
    virtual unsigned long long vfunc_1();
    virtual void vfunc_2();
    int next;
    int a;
    int b;
};

class CTokenHashed {
public:
    CTokenHashed *FUN_000f9c20(const char *name, int a, int b, int c);
};

class CTokenNumber {
public:
    CTokenNumber *FUN_000f9880(float v, int a, int b);
};

}


DollyScript::CToken * __stdcall FUN_000fa5a0(char **cur, const char *base, int a, int b, const char *copy)
{
    char c = **cur;
    if (c == '#')
        return 0;
    if (c == '(') {
        const char *start = (*cur - base) + copy;
        const char *q = start;
        int depth = 0;
        if (*start != 0) {
            do {
                char ch = *q;
                if (ch == '(')
                    depth++;
                else if (ch == ')')
                    depth--;
                q++;
                if (depth == 0)
                    break;
            } while (*q != 0);
        }
        hulk_uintptr len = q - start;
        char *buf = FUN_0008d6d0(len + 1);
        strncpy(buf, start, len);
        buf[len] = 0;
        void *mem = FUN_0008d690((int)sizeof(DollyScript::CTokenStatement));
        DollyScript::CTokenStatement *t = 0;
        if (mem != 0)
            t = new (mem) DollyScript::CTokenStatement(buf, a, b);
        const char *endp = q + (base - copy);
        char *cursor = *cur;
        if (cursor != 0) {
            while (*cur < endp) {
                *cur = FUN_003465c6(0, " \t\n\r");
                if (*cur == 0)
                    break;
            }
        }
        return (DollyScript::CToken *)(void *)t;
    }
    if (c == '"') {
        const char *s = (*cur - base) + copy + 1;
        unsigned int count = 0;
        const char *p = s;
        char ch = *p;
        if (ch != 0 && ch != '"') {
            for (;;) {
                if (ch == '\\') {
                    ch = p[1];
                    p++;
                    if (ch == 0) {
                        count++;
                        break;
                    }
                }
                ch = p[1];
                count++;
                p++;
                if (ch == 0)
                    break;
                if (ch == '"')
                    break;
            }
        }
        count++;
        char *out = FUN_0008d6d0(count);
        char *dst = out;
        if (*s != 0) {
            for (;;) {
                char d = *s;
                if (d == '"') {
                    s++;
                    break;
                }
                if (d == '\\') {
                    d = s[1];
                    s++;
                    if (d == 0) {
                        *dst = '\\';
                        dst++;
                        s++;
                        break;
                    }
                    if (d == 'n')
                        d = 10;
                    else if (d == 't')
                        d = 9;
                }
                *dst = d;
                dst++;
                s++;
                if (*s == 0)
                    break;
            }
        }
        *dst = 0;
        void *mem = FUN_0008d690((int)sizeof(DollyScript::CTokenString));
        DollyScript::CTokenString *t = 0;
        if (mem != 0)
            t = new (mem) DollyScript::CTokenString(out, a, b);
        char *cursor = *cur;
        const char *endp = s + (base - copy);
        if (cursor != 0) {
            while (*cur < endp) {
                *cur = FUN_003465c6(0, " \t\n\r");
                if (*cur == 0)
                    break;
            }
        }
        return (DollyScript::CToken *)(void *)t;
    }
    void *res = 0;
    if (c == '{') {
        void *mem = FUN_0008d690((int)sizeof(DollyScript::CTokenSectionStart));
        if (mem != 0)
            res = new (mem) DollyScript::CTokenSectionStart(b);
    } else if (c == '}') {
        void *mem = FUN_0008d690((int)sizeof(DollyScript::CTokenSectionEnd));
        if (mem != 0)
            res = new (mem) DollyScript::CTokenSectionEnd(b);
    } else if (isdigit((int)c) == 0 && **cur != '-' && **cur != '+' && **cur != '.') {
        void *mem = FUN_0008d690(0x18);
        if (mem != 0)
            res = ((DollyScript::CTokenHashed *)mem)->FUN_000f9c20(*cur, a, b, 0);
    } else {
        float v = (float)FUN_003458c1(*cur);
        void *mem = FUN_0008d690(0x14);
        if (mem != 0)
            res = ((DollyScript::CTokenNumber *)mem)->FUN_000f9880(v, a, b);
    }
    *cur = FUN_003465c6(0, " \t\n\r");
    return (DollyScript::CToken *)res;
}
} // namespace fn_000fa5a0

namespace fn_fd8937bc {

// 0x000fa870 FUN_000fa870 (111 B): matches/0x000fa870.cpp
// sym: ?Put@Lst@fn_fd8937bc@@QAEXPAUItem_fa870@2@@Z
void Lst::Put(Item_fa870* it) {
    if (!(*(unsigned char*)DAT_004e09fc & 1)) {
        *(unsigned*)DAT_004e09fc |= 1;
        *(Item_fa870**)((unsigned char*)&DAT_004e09f8) = it;
    }
    Item_fa870*& last = *(Item_fa870**)((unsigned char*)&DAT_004e09f8);
    if (h->count == 0) {
        h->First_000f9b00(it);
        last = it;
        return;
    }
    if (last != it) {
        Item_fa870* n = last->next;
        if (n) {
            ((owners::Node_f9b40 *)n)->FUN_000f9b40((owners::Node_f9b40 *)(Item_fa870 *)it);
            last = it;
            return;
        }
        last->next = it;
    }
    last = it;
}

} // namespace fn_fd8937bc

// 0x000fa8e0 DollyScript::CRawScript::vfunc_2 (50 B): matches/0x000fa8e0.cpp [wrapped: conflict: CRawScript]
// sym: ?vfunc_2@CRawScript@fn_000fa8e0@@QAEPAV12@E@Z
namespace fn_000fa8e0 {
extern void* hulk_at_0040ce8c;

class CRawScript {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual ~CRawScript();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad[12];
    hulk_intptr m_0x10;

    void Destroy_0027afd0();
    CRawScript* vfunc_2(unsigned char param);
};

void __cdecl FreeBuffer_0008d340(void* p);
void __cdecl DeleteSelf_00263f30(void* p);

CRawScript* CRawScript::vfunc_2(unsigned char param) {
    *(void**)this = &hulk_at_0040ce8c;
    FreeBuffer_0008d340((void*)m_0x10);
    Destroy_0027afd0();
    if (param & 1) {
        DeleteSelf_00263f30(this);
    }
    return this;
}
} // namespace fn_000fa8e0


// 0x000fa920 DollyScript::CScriptTokenizer::vfunc_0 (31 B): matches/0x000fa920.cpp
// sym: ?f2@NonCopyable_0fa920@pure3d@@UAEPAV12@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_0fa920* pure3d::NonCopyable_0fa920::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x000fa940 DollyScript::CTokenString::vfunc_2 (87 B): matches/0x000fa940.cpp [wrapped: conflict: CTokenString]
// sym: ?f2@CTokenString@fn_000fa940@@UAEPAV12@XZ
namespace fn_000fa940 {
typedef unsigned int uint;
void* Alloc_0008d690(hulk_uintptr);
uint CopyString_000f6610(uint);
extern char baseVftable[];
extern char stringVftable[];
class CScriptToken {
  public:
    virtual void f0();
    virtual void f1();
    virtual CScriptToken* f2();
    uint a, b, c;
};
class CTokenString : public CScriptToken {
  public:
    virtual void g0();
    virtual void g1();
    virtual CTokenString* f2();
    uint str;
};
CTokenString* CTokenString::f2() {
    CTokenString* p = (CTokenString*)Alloc_0008d690(0x14);
    CTokenString* r;
    if (p) {
        *(void**)p = (void*)&baseVftable[0];
        p->a = a;
        p->b = b;
        p->c = c;
        *(void**)p = (void*)&stringVftable[0];
        p->str = str;
        r = p;
    } else {
        r = 0;
    }
    uint v = CopyString_000f6610(str);
    r->str = v;
    r->a = 0;
    return r;
}
} // namespace fn_000fa940


// 0x000fa9a0 DollyScript::CTokenHashed::vfunc_0 (31 B): matches/0x000fa9a0.cpp
// sym: ?f2@NonCopyable_0fa9a0@pure3d@@UAEPAV12@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_0fa9a0* pure3d::NonCopyable_0fa9a0::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x000fa9c0 DollyScript::CTokenHashed::vfunc_2 (73 B): matches/0x000fa9c0.cpp [wrapped: conflict: operatornew]
// sym: ?vfunc_2@CTokenHashed@DollyScript@fn_000fa9c0@@UAEPAVCScriptToken@23@XZ
namespace fn_000fa9c0 {
/* size_t: tree_prelude.h */

namespace DollyScript {
class CScriptToken {
  public:
    virtual void f0();
    virtual void f1();
    virtual CScriptToken* vfunc_2();
    int a, b, c;
    CScriptToken(const CScriptToken& o) : a(o.a), b(o.b), c(o.c) {}
};
class CTokenHashed : public CScriptToken {
  public:
    virtual void f0();
    virtual void f1();
    virtual CScriptToken* vfunc_2();
    int d, e;
    CTokenHashed(const CTokenHashed& o) : CScriptToken(o), d(o.d), e(o.e) {}
};
CScriptToken* CTokenHashed::vfunc_2() {
    CTokenHashed* p = new CTokenHashed(*this);
    p->a = 0;
    return p;
}
} // namespace DollyScript
} // namespace fn_000fa9c0

namespace fn_fd8937bc {

// 0x000faa10 FUN_000faa10 (35 B): matches/0x000faa10.cpp
// sym: ??0CScriptParser@fn_fd8937bc@@QAE@H@Z
CScriptParser::CScriptParser(hulk_intptr x) {
    arg = x;
    vt = (void*)((hulk_intptr)DAT_0040bf84);
    a = 0;
    b = 0;
    c = 0;
    e = 0;
    d = 0;
}

} // namespace fn_fd8937bc

// 0x000fad30 FUN_000fad30 (85 B): matches/0x000fad30.cpp [wrapped: conflict: Node]
// sym: ?run@Obj_fad30@fn_000fad30@@QAEMXZ
namespace fn_000fad30 {
// data: zeroVal_fad30 = DAT_003f32e0

struct Node {
    char pad[4];
    Node* next;
    int type;
};
struct Type {
    int x;
};
extern Type tokType;
extern Type hulk_at_004a13bc;
Node* __cdecl GetToken(Node*, int, Type*, Type*, int);
class Obj_fad30 {
  public:
    char pad0[8];
    Node* root;
    Node* current;
    char pad10[4];
    unsigned char done;
    float run();
};
float Obj_fad30::run() {
    Node* ed = root;
    if (!ed)
        return (*(float*)&DAT_003f32e0);
    Node* eax;
    if (done == 1) {
        eax = 0;
    } else {
        Node* t = current;
        if (!t)
            eax = ed->next;
        else
            eax = t->next;
        if (eax && eax->type < 2)
            eax = 0;
    }
    current = eax;
    if (!eax)
        done = 1;
    Node* r = GetToken(eax, 0, &tokType, &hulk_at_004a13bc, 0);
    return *(float*)((char*)r + 16);
}
} // namespace fn_000fad30

namespace fn_fd8937bc {

// 0x000fad90 FUN_000fad90 (81 B): matches/0x000fad90.cpp
// sym: ?Target@fn_fd8937bc@@YIHPAUObj_fad90@1@@Z
hulk_intptr __fastcall Target(Obj_fad90* self) {
    Base_fad90* p = self->mRoot;
    if (!p)
        return 0;
    Base_fad90* q;
    if (self->mDone == 1)
        q = 0;
    else {
        q = self->mCur;
        if (q == 0)
            q = (Base_fad90*)*(hulk_intptr*)((char*)p + 4);
        else
            q = (Base_fad90*)*(hulk_intptr*)((char*)q + 4);
        if (q == 0 || *(int*)((char*)q + 8) >= 2) {
        } else
            q = 0;
    }
    self->mCur = q;
    if (q == 0)
        self->mDone = 1;
    return *(int*)((char*)GetThing(self->mCur, 0, &hulk_at_004a13e4, &hulk_at_004a140c, 0) + 16);
}


// 0x000fae50 FUN_000fae50 (90 B): matches/0x000fae50.cpp
// sym: ?Get@Obj_fae50@fn_fd8937bc@@QAEXPAUVec3_fae50@2@@Z
void Obj_fae50::Get(Vec3_fae50* out) {
    if (active == 0) {
        out->x = 0.0f;
        out->z = 0.0f;
        out->y = 0.0f;
    } else {
        float a = Next_000fad30();
        float b = Next_000fad30();
        float c = Next_000fad30();
        out->x = a;
        out->y = b;
        out->z = c;
    }
}


// 0x000faeb0 FUN_000faeb0 (84 B): matches/0x000faeb0.cpp
// sym: ?Run@Iter@fn_fd8937bc@@QAE_JXZ
__int64 Iter::Run() {
    Node* p = head;
    if (!p)
        return 0;
    Node* n;
    if (done == 1)
        n = 0;
    else {
        if (current == 0)
            n = p->next;
        else
            n = current->next;
        if (n && n->count < 2)
            n = 0;
    }
    current = n;
    if (!n)
        done = 1;
    return cast(n, 0, &desc1, &desc2, 0)->b();
}

} // namespace fn_fd8937bc

// 0x000faf20 content::LoadInventory::DynamicCaster<DollyScript::CRawScript>::vfunc_0 (30 B): matches/0x000faf20.cpp
// sym: ?vfunc_0@?$DynamicCaster@VCRawScript@DollyScript@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<DollyScript::CRawScript>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x000faf40 DollyScript::CTokenFloat::vfunc_2 (60 B): matches/0x000faf40.cpp
// sym: ?vfunc_2@CTokenFloat@DollyScript@@UAEPAV12@XZ
namespace DollyScript {
CTokenFloat* CTokenFloat::vfunc_2() {
    CTokenFloat* p = new CTokenFloat(*this);
    p->zero = 0;
    return p;
}
}

namespace fn_fd8937bc {

// 0x000fb110 FUN_000fb110 (50 B): matches/0x000fb110.cpp
// sym: ?Target@fn_fd8937bc@@YIHPAUObj_fb110@1@@Z
hulk_intptr __fastcall Target(Obj_fb110* self) {
    int x = ((ThisCall_000f9d70*)(self))->GetThing_000f9d70();
    self->field8 = x;
    if (x == 0)
        self->field15 = 1;
    self->field14 = 0;
    self->fieldc = 0;
    return Setup(x, 0, &RTTI2_fb110, &hulk_at_004a1934, 0);
}


// 0x000fb150 FUN_000fb150 (55 B): matches/0x000fb150.cpp
// sym: ?next@Obj_fb150@fn_fd8937bc@@QAEHXZ
hulk_intptr Obj_fb150::next() {
    Node* n = root;
    if (!n)
        return 0;
    hulk_intptr r;
    if (done != 1) {
        Node* c = cur;
        if (!c) {
            c = *(Node**)((char*)n + 4);
        } else {
            c = *(Node**)((char*)c + 4);
        }
        r = (hulk_intptr)c;
        if (c && c->state < 2)
            r = 0;
    } else
        r = 0;
    cur = (Node*)r;
    if (!r)
        done = 1;
    return r;
}


// 0x000fb1c0 FUN_000fb1c0 (72 B): matches/0x000fb1c0.cpp
// sym: _FUN_000fb1c0
// data: inventory = DAT_004dd9cc
extern "C" char FUN_000fb1c0(int id) {
    char result = 0;
    __int64 key = FUN_0027b020(id);
    int item = find((*(Inventory**)&DAT_004dd9cc), key);
    if (item) {
        (*(Inventory**)&DAT_004dd9cc)->use(item);
        result = 1;
    }
    return result;
}

} // namespace fn_fd8937bc

// 0x000fb240 FUN_000fb240 (80 B): equivalent/0x000fb240.cpp
// sym: ?FUN_000fb240@Inventory_fb240@owners@@QAEPAXPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// FUN_000fb240 @ 0x000fb240
// FUN_000fb240 @ 0x000fb240
void *owners::Inventory_fb240::FUN_000fb240(void *item) {
    __int64 value = FUN_0027b020(item);
    void *caster = DAT_0040ced4;
    int result = (*(Loader**)&DAT_004dd9cc)->slot3(&caster, (unsigned int)value, (unsigned int)(value >> 32));
    if (!result) {
        result = FUN_000fa4b0(item);
        if (!result) return 0;
    }
    return FUN_000faf80(result);
}

