// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/movie.h"
#include "decls/data/game/unknown.h"
#include "gen/movie.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f964084a {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f964084a {} using namespace fn_f964084a;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f964084a {
typedef unsigned int uint_335270;
extern "C" char DAT_00434300[];
extern void* hulk_at_00434300;
struct Value_3353e0 {
    int f0;
    int f4;
    int type;
    void* data;     // 0xc
};
class Slots_3353e0 {
public:
    int f0;
    int f4;
    int* base;      // 0x8
    void FUN_003353e0(int index, Value_3353e0* v);
};
struct Obj {
  public:
    virtual void* m_vf0_00338010(char);
    Obj();
    void* get_00337980();
    const char* Get_00337980();
    void FUN_00337ea0();
};
extern "C" char __cdecl convert(void*);
struct Parser {
    const char* Get_00337980();
};
} // namespace fn_f964084a
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned strlen(const char*);
#endif
namespace fn_f964084a {
inline void copy(char* d, const char* s) {
    char c;
    do {
        c = *s;
        ++s;
        *d = c;
        ++d;
    } while (c);
}
class Source {
  public:
    char* Lookup_00337980();
};
class Heap {
  public:
    void* Allocate_00337d60(hulk_uintptr, unsigned);
};
class Owner_336180 {
  public:
    int Get_00337980();
    void Advance_003379b0();
};
extern float __cdecl FUN_003458c1(int);
class Reader {
  public:
    int Get_00337980();
    void Adv_003379b0();
    char* GetText_00337980();
    void Advance_003379b0();
};
float __cdecl Conv(int);
struct Parser_336380 { const char* FUN_00337980(); void FUN_003379b0(); };
struct Context {
  public:
    char _m_pad_0[0xc];
    int* type;
    char* FUN_00338a10();
};
struct Allocator { void* FUN_00337d60(unsigned int size, int alignment); };
int __cdecl FUN_00337f20(int);
struct Owner_336380;
typedef bool (__fastcall *Handler_336380)(Owner_336380*, Context*, void*, Parser_336380*, Context*, int);
struct Owner_336380 { bool FUN_00336380(void** output, Parser_336380* parser, Context* context, void* unused); };
class Lookup {
  public:
    char* Get_00337980();
};
inline void Copy(char* dst, const char* src) {
    char c;
    do {
        c = *src++;
        *dst++ = c;
    } while (c);
}
class Helper_336490 {
  public:
    int run_00337130(int a);
};
class Thing_336490 {
  public:
    int pad;
    Helper_336490* member;
    void consume_00335480(int x, int b);
    void combine(hulk_intptr a, hulk_intptr b);
};
class Helper_3364c0 {
  public:
    int run_00337130(int a);
};
class Thing_3364c0 {
  public:
    int pad;
    Helper_3364c0* member;
    void consume_003354c0(int x, int b);
    void combine(hulk_intptr a, hulk_intptr b);
};
class Helper_3364f0 {
  public:
    int run_00337130(int a);
};
class Thing_3364f0 {
  public:
    int pad;
    Helper_3364f0* member;
    void consume_00335500(int x, int b);
    void combine(hulk_intptr a, hulk_intptr b);
};
class B_3365b0 {
  public:
    int FnG_00337130(int);
};
class C_3365b0 {
  public:
    char pad[4];
    B_3365b0* b;
    hulk_intptr F(hulk_intptr);
    int FnH_00335640(int);
};
typedef unsigned int U_336600;
struct Inner_336600 {
    U_336600 call_00337130(U_336600);
};
struct Obj_336600 {
    int pad;
    Inner_336600* p;
    U_336600 second_003356d0(U_336600, U_336600, U_336600, U_336600);
    U_336600 target(hulk_uintptr, hulk_uintptr, hulk_uintptr, hulk_uintptr);
};
class Helper_336690 {
  public:
    int run_00337130(int a);
};
class Thing_336690 {
  public:
    int pad;
    Helper_336690* member;
    void consume_003358a0(int x, int b);
    void combine(hulk_intptr a, hulk_intptr b);
};
class D {
  public:
    int helper_00337130(int);
    void Fnf_00338d80();
};
class C_3366f0 {
  public:
    char pad[4];
    D* sub;
    int second_00335970(int, int, int);
    int target(hulk_intptr, int, hulk_intptr);
};
class CAction_336f10 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_336f10* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
extern void __fastcall SetVtable_003352b0(void*);
extern void thunk_FUN_00267090(movie::BinkCallback*);
struct Item_337040 {
    void Init_00337ea0();
};
struct Obj_337040 {
    char pad0[4];
    unsigned char b;
    char pad1[0x3f];
    unsigned int a;
    char pad2[0];
};
struct Ent_3370b0 {
    int x;
    const char* name;
    int pad[4];
};
struct T_3370b0 {
    char pad[0x44];
    int count;
    Ent_3370b0 ents[1];
    Ent_3370b0* Find(const char* s);
};
struct Entry_337130 {
    const char* name;
    char pad[20];
};
class Table_337130 {
    char pad[0x44];
    int count;
    char pad2[4];
    Entry_337130 entries[1];

  public:
    int Find(const char* name);
};
struct Item_3371b0 {
    void Init_00338000();
};
struct Obj_3371b0 {
    hulk_uintptr v;
    char pad[0x44];
    Item_3371b0 items[0x18];
    void Finish_00337040();
};
struct Element_3371e0 {
    char pad[0x18];
    void Fnf_00337e90();
};
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_003371e0 {
    void FUN_003371e0();
};
extern void thunk_FUN_00267090(CCollisionAction*);
class Child_337460 {
  public:
    char pad[0x81c];
    int value;
    int Check_00338a10();
};
class Obj_337460 {
  public:
    char pad[0x5108];
    int result;
    Child_337460* child;
    hulk_intptr Run();
};
class C_3374a0 {
  public:
    char pad[0x510c];
    D* p;
    void f();
};
} // namespace fn_f964084a
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char *, const char *, ...);
#endif
namespace fn_f964084a {
struct Token_3374c0 { const char * FUN_00338a10(); };
struct Parser_3374c0 {
 char pad[0x5108];
 unsigned error;
 Token_3374c0 *token;
 const char * FUN_003374c0();
};
struct Obj_3375a0 {
    char pad[0x510c];
    void* p;
};
class Elem_3375f0 {
  public:
    void Init_003371b0();
};
class Container_3375f0 {
  public:
    hulk_intptr m_vptr;         // 0x00
    int field4;         // 0x04
    char elems[0x5100]; // 0x08 .. 0x5108
    int f5108;          // 0x5108
    int f510c;          // 0x510c

    Container_3375f0* Init();
};
class Obj_337870 {
  public:
    hulk_intptr vft;
    int a;
    int b;
    Obj_337870();
};
class Ref_337890 {
  public:
    virtual void F(int);
};
class Obj_337890 {
  public:
    hulk_uintptr a;
    unsigned b;
    Ref_337890* member;
    void Go();
};
struct ParseError {
    char pad0[4];
    unsigned int code;
    Context* context;
};
struct Obj_337980 {
    char pad[0x81c];
    int result;
    int Query_00338a10();
};
struct S_337980 {
    char pad[4];
    int value;
    Obj_337980* obj;
    hulk_intptr run();
};
class X_337c00 {
  public:
    X_337c00();
    int* p;
};
struct X_337d20 {
    void* v;
    char* a;
    int b;
    char* c;
    X_337d20(void* p, int q);
};
struct X_337ea0 {
    char pad[4];
    int a;
    int b;
    int c;
    unsigned char d;
    char pad2[3];
    int e;
};
void __cdecl thunk_FUN_00267090(void*);
class Inner_3385f0 {
  public:
    virtual void v0();
    virtual bool Test(int);
};
class Target_3385f0 {
  public:
    char pad[4];
    Inner_3385f0* obj;
    char pad2[0x824 - 8];
    int state;
    bool Run(hulk_intptr x);
};
class A_338630 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
struct B_338630 {
    char pad[4];
    A_338630* p;
};
struct Src_3386a0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int Read(char*, int);
    virtual bool More();
};
struct Rd_3386a0 {
    int pad0;
    Src_3386a0* src;
    int size;
    int pos;
    int len;
    int pad14;
    char* buf;
    bool Get(char* out);
};
static inline hulk_uintptr strlen_inline(const char *s)
{
    const char *p = s;
    while (*p)
        p++;
    return p - s;
}
static inline int strcmp_inline(const char *a, const char *b)
{
    while (*a && *a == *b) {
        a++;
        b++;
    }
    return (unsigned char)*a - (unsigned char)*b;
}
int __stdcall FUN_00338710(int, void *, int);
class Source_338a10 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Read(char *buf, int size);
    virtual bool AtEnd();
};
class Tokenizer {
public:
    char pad00[4];
    Source_338a10 *source;
    int bufSize;
    int pos;
    int len;
    char pad14[4];
    char *buf;
    char tok[0x400];
    char cur[0x400];
    int status;
    char done;
    char flag821;
    char pad822[2];
    int lineno;
    char saved;
    char pad829[3];
    char *savedEnd;
    char savedQuote;
    char savedFlagB;
    char pad832[0x85a - 0x832];
    char delim[0x18];
    char flag872;
    char *FUN_00338a10();
    char *FUN_00338800(char *s);
    bool FUN_003387d0(int ch);
    bool FUN_003387a0(int ch);
    bool FUN_00338860(char *s);
};


// 0x00335270 FUN_00335270 (40 B): matches/0x00335270.cpp
// sym: ?FUN_00335270@fn_f964084a@@YAII@Z
hulk_uintptr FUN_00335270(hulk_uintptr x) {
    return (x & 0xff00 | x << 16) << 8 | (x & 0xff0000 | x >> 16) >> 8;
}

} // namespace fn_f964084a

// 0x003352a0 FUN_003352a0 (16 B): matches/0x003352a0.cpp
// sym: ?FUN_003352a0@BinkCallback@movie@@QAEPAV12@XZ
movie::BinkCallback* movie::BinkCallback::FUN_003352a0() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00434300);
    this->f_0c = 0;
    return (BinkCallback*)(this);
}

namespace fn_f964084a {

// 0x003352b0 FUN_003352b0 (7 B): matches/0x003352b0.cpp
// sym: ?FUN_003352b0@fn_f964084a@@YIXPAX@Z
// Same code shape as 0x001b6820 (propagated; names are from that function)
void __fastcall FUN_003352b0(void* self) {
    *(void**)self = &hulk_at_00434300;
}


// 0x003353e0 FUN_003353e0 (113 B): equivalent/0x003353e0.cpp
// sym: ?FUN_003353e0@Slots_3353e0@fn_f964084a@@QAEXHPAUValue_3353e0@2@@Z @a4cfab7d8580 @w92a6c76079b2
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 13/13)
// FUN_003353e0 @ 0x003353e0
// Copies the value's payload into slot `index`, according to its type.
void Slots_3353e0::FUN_003353e0(int index, Value_3353e0* v)
{
    int* slot = base + index;
    switch (v->type) {
    case 0:
        *(char*)slot = *(char*)v->data;
        return;
    case 1:
    case 2:
    case 3:
        *slot = *(int*)v->data;
        return;
    case 4: {
        const char* src = *(const char**)v->data;
        char* dst = *(char**)slot;
        char c;
        do {
            c = *src++;
            *dst++ = c;
        } while (c != 0);
        return;
    }
    case 5:
    case 7: {
        int* src = (int*)v->data;
        int* dst = *(int**)slot;
        dst[0] = src[0];
        dst[1] = src[1];
        return;
    }
    case 6:
    case 8: {
        int* src = (int*)v->data;
        int* dst = *(int**)slot;
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        return;
    }
    }
}


// 0x00335fe0 FUN_00335fe0 (70 B): matches/0x00335fe0.cpp
// sym: _FUN_00335fe0@16
extern "C" char __stdcall FUN_00335fe0(char** out, Obj* obj, int unused, char direct) {
    void* p = obj->get_00337980();
    if (!p)
        return 0;
    if (direct) {
        *(char*)out = convert(p);
        return 1;
    }
    char* q = *out;
    *q = convert(p);
    return 1;
}


// 0x00336030 FUN_00336030 (70 B): matches/0x00336030.cpp
// sym: _FUN_00336030@16
extern "C" char __stdcall FUN_00336030(int** p, Parser* parser, int unused, char direct) {
    const char* s = parser->Get_00337980();
    if (!s)
        return 0;
    if (direct) {
        *(int*)p = atol(s);
        return 1;
    }
    int* q = *p;
    *q = atol(s);
    return 1;
}


// 0x00336080 FUN_00336080 (70 B): matches/0x00336080.cpp
// sym: ?FUN_00336080@fn_f964084a@@YGERAPAJPAUObj@1@HE@Z
unsigned char __stdcall FUN_00336080(long** volatile p, Obj* out, int x, unsigned char flag) {
    const char* s = out->Get_00337980();
    if (!s)
        return 0;
    if (flag) {
        *p = (long*)atol(s);
        return 1;
    }
    long* q = *p;
    *q = atol(s);
    return 1;
}

} // namespace fn_f964084a

// 0x003360d0 FUN_003360d0 (70 B): matches/0x003360d0.cpp [wrapped: conflict: Obj]
// sym: _FUN_003360d0@16
namespace fn_003360d0 {
extern "C++" float __cdecl FUN_003458c1(const char*);
class Obj {
  public:
    const char* get_00337980();
};
extern "C" char __stdcall FUN_003360d0(float** out, Obj* obj, int unused, char direct) {
    const char* p = obj->get_00337980();
    if (!p)
        return 0;
    if (direct) {
        *(float*)out = FUN_003458c1(p);
        return 1;
    }
    float* dest = *out;
    *dest = FUN_003458c1(p);
    return 1;
}
} // namespace fn_003360d0

namespace fn_f964084a {

// 0x00336120 FUN_00336120 (81 B): matches/0x00336120.cpp
// sym: _FUN_00336120@16
// data: gHeap = DAT_0055dbb0
extern "C" bool __stdcall FUN_00336120(char** out, Source* src, int b, int c) {
    char* s = src->Lookup_00337980();
    if (!s)
        return false;
    char* d = (char*)(*(Heap*)&DAT_0055dbb0).Allocate_00337d60(strlen(s) + 1, 4);
    *out = d;
    copy(d, s);
    return true;
}


// 0x00336180 FUN_00336180 (98 B): matches/0x00336180.cpp
// sym: _FUN_00336180@16
extern "C" char __stdcall FUN_00336180(float* out, Owner_336180* owner, int c, char inPlace) {
    int v = owner->Get_00337980();
    if (!v)
        return 0;
    float* p;
    if (inPlace)
        p = out;
    else
        p = (float*)*(hulk_intptr*)out;
    *p = FUN_003458c1(v);
    owner->Advance_003379b0();
    v = owner->Get_00337980();
    if (!v)
        return 0;
    p[1] = FUN_003458c1(v);
    return 1;
}


// 0x003361f0 FUN_003361f0 (130 B): matches/0x003361f0.cpp
// sym: _FUN_003361f0@16
extern "C" char __stdcall FUN_003361f0(float** out, Reader* r, int d, char direct) {
    int v = r->Get_00337980();
    if (!v)
        return 0;
    float* p;
    if (direct)
        p = (float*)out;
    else
        p = *out;
    *p = Conv(v);
    ++p;
    r->Adv_003379b0();
    v = r->Get_00337980();
    if (!v)
        return 0;
    *p = Conv(v);
    r->Adv_003379b0();
    v = r->Get_00337980();
    if (!v)
        return 0;
    p[1] = Conv(v);
    return 1;
}


// 0x00336280 FUN_00336280 (98 B): matches/0x00336280.cpp
// sym: _FUN_00336280@16
extern "C" char __stdcall FUN_00336280(long* output, Reader* reader, void* unused, char indirect) {
    char* text = reader->GetText_00337980();
    if (!text)
        return 0;
    long* destination;
    if (indirect)
        destination = output;
    else
        destination = (long*)*(hulk_intptr*)output;
    *destination = atol(text);
    reader->Advance_003379b0();
    text = reader->GetText_00337980();
    if (!text)
        return 0;
    destination[1] = atol(text);
    return 1;
}

} // namespace fn_f964084a

// 0x003362f0 FUN_003362f0 (130 B): matches/0x003362f0.cpp [wrapped: conflict: Reader]
// sym: _FUN_003362f0@16
namespace fn_003362f0 {
class Reader {
  public:
    char* Get_00337980();
    void Next_003379b0();
};

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" long __cdecl atol(const char*);
#endif

extern "C" char __stdcall FUN_003362f0(long* out, Reader* reader, int unused, char inPlace) {
    char* s = reader->Get_00337980();
    if (!s)
        return 0;
    long* dest = inPlace ? out : (long*)*out;
    *dest = atol(s);
    dest++;
    reader->Next_003379b0();
    s = reader->Get_00337980();
    if (!s)
        return 0;
    *dest = atol(s);
    reader->Next_003379b0();
    s = reader->Get_00337980();
    if (!s)
        return 0;
    dest[1] = atol(s);
    return 1;
}
} // namespace fn_003362f0

namespace fn_f964084a {

// 0x00336380 FUN_00336380 (173 B): equivalent/0x00336380.cpp
// sym: ?FUN_00336380@Owner_336380@fn_f964084a@@QAE_NPAPAXPAUParser_336380@2@PAUContext@2@PAX@Z @32aeb377b30d @wdc26912ae2d9
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 8/8)
// FUN_00336380 @ 0x00336380
bool Owner_336380::FUN_00336380(void** output, Parser_336380* parser, Context* context, void* unused) {
 const char* text = parser->FUN_00337980();
 if (!text) return false;
 int* type = context->type;
 int count = atol(text);
 int stride = FUN_00337f20(*type);
 char* data = (char*)(*(Allocator*)&DAT_0055dbb0).FUN_00337d60(count * stride + 4, 4);
 *output = data;
 *(int*)data = count;
 data += 4;
 for (int i=0; i<count; ++i) {
  parser->FUN_003379b0();
  if (!((Handler_336380*)&DAT_004d9800)[*type](this, context, data, parser, context, 1)) return false;
  data += stride;
 }
 return true;
}


// 0x00336430 FUN_00336430 (81 B): matches/0x00336430.cpp
// sym: _FUN_00336430@16
// data: gHeap = DAT_0055dbb0
extern "C" bool __stdcall FUN_00336430(char** out, Lookup* lookup, int a, int b) {
    char* s = lookup->Get_00337980();
    if (!s)
        return false;
    char* d = ((char *)((owners::Allocator_337d60 *)&((*(Heap*)&DAT_0055dbb0)))->FUN_00337d60((unsigned int)(strlen(s) + 1), 4));
    *out = d;
    Copy(d, s);
    return true;
}


// 0x00336490 FUN_00336490 (33 B): matches/0x00336490.cpp
// sym: ?combine@Thing_336490@fn_f964084a@@QAEXHH@Z
void Thing_336490::combine(hulk_intptr a, hulk_intptr b) {
    consume_00335480(member->run_00337130(a), b);
}


// 0x003364c0 FUN_003364c0 (33 B): matches/0x003364c0.cpp
// sym: ?combine@Thing_3364c0@fn_f964084a@@QAEXHH@Z
// Same code shape as 0x00336490 (propagated; names are from that function)
void Thing_3364c0::combine(hulk_intptr a, hulk_intptr b) {
    consume_003354c0(member->run_00337130(a), b);
}


// 0x003364f0 FUN_003364f0 (33 B): matches/0x003364f0.cpp
// sym: ?combine@Thing_3364f0@fn_f964084a@@QAEXHH@Z
// Same code shape as 0x00336490 (propagated; names are from that function)
void Thing_3364f0::combine(hulk_intptr a, hulk_intptr b) {
    consume_00335500(member->run_00337130(a), b);
}


// 0x003365b0 FUN_003365b0 (28 B): matches/0x003365b0.cpp
// sym: ?F@C_3365b0@fn_f964084a@@QAEHH@Z
hulk_intptr C_3365b0::F(hulk_intptr param) {
    int x = b->FnG_00337130(param);
    return FnH_00335640(x);
}


// 0x00336600 FUN_00336600 (43 B): matches/0x00336600.cpp
// sym: ?target@Obj_336600@fn_f964084a@@QAEIIIII@Z
U_336600 Obj_336600::target(hulk_uintptr a, hulk_uintptr b, hulk_uintptr c, hulk_uintptr d) {
    return second_003356d0(p->call_00337130(a), b, c, d);
}


// 0x00336690 FUN_00336690 (33 B): matches/0x00336690.cpp
// sym: ?combine@Thing_336690@fn_f964084a@@QAEXHH@Z
// Same code shape as 0x00336490 (propagated; names are from that function)
void Thing_336690::combine(hulk_intptr a, hulk_intptr b) {
    consume_003358a0(member->run_00337130(a), b);
}


// 0x003366f0 FUN_003366f0 (38 B): matches/0x003366f0.cpp
// sym: ?target@C_3366f0@fn_f964084a@@QAEHHHH@Z
int C_3366f0::target(hulk_intptr a, int b, hulk_intptr c) {
    return second_00335970(sub->helper_00337130(a), b, c);
}

} // namespace fn_f964084a

// 0x00336d90 FUN_00336d90 (52 B): matches/0x00336d90.cpp
// sym: ?FUN_00336d90@Obj_336d90@owners@@QAEXXZ
// data: gBase = DAT_0055dbb4
void owners::Obj_336d90::FUN_00336d90() {
    int* p = (*(int**)&DAT_0055dbbc) - 3;
    b = *p + (*(int*)&DAT_0055dbb4);
    ++p;
    c = *p + (*(int*)&DAT_0055dbb4);
    ++p;
    a = *p + (*(int*)&DAT_0055dbb4);
}

namespace fn_f964084a {

// 0x00336ee0 FUN_00336ee0 (21 B): matches/0x00336ee0.cpp
// sym: ?target@fn_f964084a@@YGXH@Z
// data: gBase = DAT_0055dbb4, gResult_336ee0 = DAT_0055dbbc
void __stdcall target(int value) {
    (*(int*)&DAT_0055dbbc) = (*(int*)&DAT_0055dbb4) + value;
}


// 0x00336f00 FUN_00336f00 (6 B): matches/0x00336f00.cpp
// sym: ?FUN_00336f00@fn_f964084a@@YAHPAX@Z
// Same code shape as 0x00085cd0 (propagated; names are from that function)
int FUN_00336f00(void* /*this, unused: callers pass it (unb4)*/) {
    return (*(int*)&DAT_0055dbb4);
}

} // namespace fn_f964084a

// 0x00336f10 movie::BinkCallback::vfunc_1 (30 B): matches/0x00336f10.cpp
// sym: ?vfunc_1_BinkCallback@BinkCallback@movie@@UAEPAXE@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
void* movie::BinkCallback::vfunc_1_BinkCallback(unsigned char flags) {
    SetVtable_003352b0((void*)(this));
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return (void*)(this);
}

namespace fn_f964084a {

// 0x00337040 FUN_00337040 (34 B): matches/0x00337040.cpp
// sym: ?target@fn_f964084a@@YIXPAUObj_337040@1@@Z
void __fastcall target(Obj_337040* p) {
    p->a = 0;
    p->b = 0;
    Item_337040* q = (Item_337040*)((char*)p + 0x48);
    int i = 0x18;
    do {
        q->Init_00337ea0();
        q = (Item_337040*)((char*)q + 0x18);
        --i;
    } while (i);
}

} // namespace fn_f964084a

// 0x00337070 FUN_00337070 (29 B): matches/0x00337070.cpp
// sym: ?FUN_00337070@Obj_337070@owners@@QAEXPAD@Z
void owners::Obj_337070::FUN_00337070(char* s) {
    char* dst = (char*)this + 4;
    char* p = s;
    char c;
    do {
        c = *p;
        *(dst + (p - s)) = c;
        ++p;
    } while (c);
}


// 0x00337090 FUN_00337090 (28 B): matches/0x00337090.cpp
// sym: ?FUN_00337090@Thing_337090@owners@@QAEPAXH@Z
void* owners::Thing_337090::FUN_00337090(int i) {
    if (i >= 0 && i < count)
        return (void*)((char*)this + (i * 3 + 9) * 8);
    return 0;
}

namespace fn_f964084a {

// 0x003370b0 FUN_003370b0 (114 B): matches/0x003370b0.cpp
// sym: ?Find@T_3370b0@fn_f964084a@@QAEPAUEnt_3370b0@2@PBD@Z
Ent_3370b0* T_3370b0::Find(const char* s) {
    for (int i = 0; i < count; i++) {
        if (strcmp(s, ents[i].name) == 0)
            return &ents[i];
    }
    return 0;
}


// 0x00337130 FUN_00337130 (94 B): matches/0x00337130.cpp
// sym: ?Find@Table_337130@fn_f964084a@@QAEHPBD@Z
int Table_337130::Find(const char* name) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(name, entries[i].name) == 0)
            return i;
    }
    return -1;
}

} // namespace fn_f964084a

// 0x00337190 FUN_00337190 (23 B): matches/0x00337190.cpp
// sym: ?FUN_00337190@Thing_337190@owners@@QAEPAXXZ
void* owners::Thing_337190::FUN_00337190() {
    if (index >= 0x18)
        return 0;
    return (char*)this + (index++ * 3 + 9) * 8;
}

namespace fn_f964084a {

// 0x003371b0 FUN_003371b0 (45 B): matches/0x003371b0.cpp
// sym: ?FUN_003371b0@fn_f964084a@@YIPAUObj_3371b0@1@PAU21@PAX@Z
Obj_3371b0* __fastcall FUN_003371b0(Obj_3371b0* self, void*) {
    self->v = ((hulk_intptr)((char*)&DAT_00434318));
    Item_3371b0* p = (Item_3371b0*)((char*)self + 0x48);
    int n = 0x18;
    do {
        p->Init_00338000();
        p = (Item_3371b0*)((char*)p + 0x18);
        --n;
    } while (n);
    self->Finish_00337040();
    return self;
}

} // namespace fn_f964084a

// 0x003371e0 FUN_003371e0 (35 B): matches/0x003371e0.cpp
// sym: ?FUN_003371e0@Obj_3371e0@owners@@QAEXXZ
void owners::Obj_3371e0::FUN_003371e0() {
    *(void**)this = (void*)((hulk_intptr)((char*)&DAT_00434318));
    Element_3371e0* p = (Element_3371e0*)((char*)this + 0x288);
    int i = 0x18;
    do {
        p--;
        p->Fnf_00337e90();
        --i;
    } while (i);
}

namespace fn_f964084a {

// 0x00337330 FUN_00337330 (30 B): matches/0x00337330.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f964084a@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_003371e0*)(this))->FUN_003371e0();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00337370 FUN_00337370 (69 B): equivalent/0x00337370.cpp
// sym: ?FUN_00337370@fn_f964084a@@YAEPBD@Z @1868bc8e1157 @w228b9087ab13
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00337370 @ 0x00337370
unsigned char __cdecl FUN_00337370(const char* text)
{
    int i;
    for (i = 0; i < 8 && text[i] == DAT_00434330[i]; ++i) {}
    if (i == 8) return 1;
    for (i = 0; i < 8 && text[i] == DAT_004277e8[i]; ++i) {}
    if (i == 8) return 1;
    for (i = 0; i < 2 && text[i] == DAT_0043432c[i]; ++i) {}
    return i == 2;
}

} // namespace fn_f964084a

// 0x003373e0 FUN_003373e0 (120 B): matches/0x003373e0.cpp
// sym: ?FUN_003373e0@Table_3373e0@owners@@QAEPADPBD@Z
char* owners::Table_3373e0::FUN_003373e0(const char* s) {
    for (int i = 0; i < count; i++) {
        char* e = first + 4 + i * 0x288;
        if (strcmp(s, e) == 0)
            return (char*)this + 8 + i * 0x288;
    }
    return 0;
}

namespace fn_f964084a {

// 0x00337460 FUN_00337460 (49 B): matches/0x00337460.cpp
// sym: ?Run@Obj_337460@fn_f964084a@@QAEHXZ
hulk_intptr Obj_337460::Run() {
    int r;
    int v;
    do {
        r = child->Check_00338a10();
        v = child->value;
        result = v;
    } while (r == 0 && v == 0);
    return r;
}


// 0x003374a0 FUN_003374a0 (11 B): matches/0x003374a0.cpp
// sym: ?f@C_3374a0@fn_f964084a@@QAEXXZ
void C_3374a0::f() {
    p->Fnf_00338d80();
}


// 0x003374c0 FUN_003374c0 (176 B): equivalent/0x003374c0.cpp
// sym: ?FUN_003374c0@Parser_3374c0@fn_f964084a@@QAEPBDXZ @292cf1516659 @w7b1f50630a05
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_003374c0 @ 0x003374c0
const char * Parser_3374c0::FUN_003374c0() {
 ((char*)&DAT_0055dbc0)[0] = 0;
 const char *name = token ? token->FUN_00338a10() : 0;
 if (!name) name = "<?>";
 switch(error) {
 case 0: return "No error.";
 case 1: return "Hit EOF, no error.";
 case 2: return "Ending quotation \" expected.";
 case 3: return "Token size is too big. Did you forget a quotation?";
 case 4: sprintf(((char*)&DAT_0055dbc0), "Syntax error, bad command '%s'.", name); return ((char*)&DAT_0055dbc0);
 case 5: return "Too many object definitions. Increase MAX_OBJECT_DEFINITIONS in datadefinition.h";
 case 6: return "Too many attribute definitions for a single object. Increase MAX_ATTRIBUTE_DEFIN";
 case 7: sprintf(((char*)&DAT_0055dbc0), "Duplicate object name '%s'.", name); return ((char*)&DAT_0055dbc0);
 case 8: sprintf(((char*)&DAT_0055dbc0), "Duplicate attribute name '%s'.", name); return ((char*)&DAT_0055dbc0);
 case 9: return "File was not found";
 case 10: sprintf(((char*)&DAT_0055dbc0), "Unknown data type '%s'.", name); return "Nesting of array data definitions is not supported at this time.";
 case 11: return "Nesting of array data definitions is not supported at this time.";
 default: return "Unknown Error...something is really wrong";
 }
}


// 0x003375a0 FUN_003375a0 (21 B): matches/0x003375a0.cpp
// sym: ?FUN_003375a0@fn_f964084a@@YIHPAUObj_3375a0@1@@Z
int __fastcall FUN_003375a0(Obj_3375a0* self) {
    if (self->p)
        return *(int*)((char*)self->p + 0x824);
    return -1;
}


// 0x003375f0 FUN_003375f0 (58 B): matches/0x003375f0.cpp
// sym: ?Init@Container_3375f0@fn_f964084a@@QAEPAV12@XZ
// data: g_vtbl = DAT_00434574
Container_3375f0* Container_3375f0::Init() {
    this->m_vptr = (hulk_intptr)((char*)&DAT_00434574);
    char* p = elems;
    for (int i = 0x20; i != 0; --i) {
        ((Elem_3375f0*)p)->Init_003371b0();
        p += 0x288;
    }
    field4 = 0;
    f5108 = 0;
    f510c = 0;
    return this;
}

} // namespace fn_f964084a

// 0x00337680 FUN_00337680 (90 B): matches/0x00337680.cpp
// sym: ?FUN_00337680@Thing_337680@owners@@QAEHH@Z
hulk_intptr owners::Thing_337680::FUN_00337680(hulk_intptr arg) {
    if (Check(((int)arg))) {
        state = 7;
        return 0;
    }
    int i = count;
    if (i >= 32) {
        state = 5;
        return 0;
    }
    ((owners::Thing_337680*)((char*)this + i * 0x288 + 8))->Init(((int)arg));
    count++;
    return (hulk_intptr)((char*)this + i * 0x288 + 8);
}


// 0x003376e0 FUN_003376e0 (30 B): matches/0x003376e0.cpp [wrapped: same definition as 0x00337330 in this TU]
// sym: ?vfunc_2@CCollisionAction@fn_003376e0@@UAEPAV12@E@Z
namespace fn_003376e0 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_00337630 {
    void FUN_00337630();
};
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_00337630*)(this))->FUN_00337630();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_003376e0


// 0x00337700 FUN_00337700 (360 B): equivalent/0x00337700.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?Load@XmlLoader@fn_00337700@@QAE_NPAX0@Z @8c005f33f2e5 @waeefe29224f5
namespace fn_00337700 {
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 28/28)
// FUN_00337700 @ 0x00337700

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" long atol(const char* s);
#endif

void* __cdecl FUN_0008d690(unsigned int size);

class AttrDef_337700 {
  public:
    bool FUN_00337210(void* loader);
};

class XmlReader {
  public:
    virtual ~XmlReader();
    XmlReader* FUN_003388d0(void* src, int bufSize);
    bool FUN_003385f0(void* arg);
    void FUN_00338630();
};

class XmlLoader {
  public:
    char pad0[0x5108];
    int status;
    XmlReader* reader;
    const char* FUN_00337460();
    void FUN_003374a0();
    bool Load(void* src, void* arg);
};

static bool Match(const char* text, const char* pattern, int count) {
    for (int i = 0; i < count; ++i) {
        if (text[i] != pattern[i])
            return false;
    }
    return true;
}

bool XmlLoader::Load(void* src, void* arg) {
    if (reader != 0)
        delete reader;
    void* memory = FUN_0008d690(0x874);
    XmlReader* newReader = 0;
    if (memory != 0)
        newReader = ((XmlReader*)memory)->FUN_003388d0(src, 0x2000);
    reader = newReader;
    status = 0;
    if (!newReader->FUN_003385f0(arg)) {
        status = 9;
    } else {
        AttrDef_337700* definition = 0;
        const char* token = FUN_00337460();
        while (token != 0) {
            if (Match(token, "version", 8)) {
                FUN_003374a0();
                const char* value = FUN_00337460();
                if (value == 0)
                    break;
                atol(value);
                FUN_003374a0();
            } else if (token[0] == '[' && token[1] == 0) {
                FUN_003374a0();
                const char* name = FUN_00337460();
                if (name == 0)
                    break;
                definition = ((AttrDef_337700 *)((owners::Thing_337680 *)this)->FUN_00337680((hulk_intptr)name));
                if (definition == 0)
                    break;
                FUN_003374a0();
                FUN_003374a0();
            } else if (Match(token, "attrDef", 8)) {
                if (!definition->FUN_00337210(this))
                    break;
            } else {
                status = 4;
                break;
            }
            token = FUN_00337460();
        }
        reader->FUN_00338630();
    }
    return status == 0 || status == 1;
}
} // namespace fn_00337700

namespace fn_f964084a {

// 0x00337870 FUN_00337870 (17 B): matches/0x00337870.cpp
// sym: ??0Obj_337870@fn_f964084a@@QAE@XZ
Obj_337870::Obj_337870() {
    vft = ((hulk_intptr)((char*)&DAT_00434578));
    a = 0;
    b = 0;
}


// 0x00337890 FUN_00337890 (20 B): matches/0x00337890.cpp
// sym: ?Go@Obj_337890@fn_f964084a@@QAEXXZ
void Obj_337890::Go() {
    a = ((hulk_intptr)((char*)&DAT_00434578));
    if (member)
        member->F(1);
}


// 0x003378c0 FUN_003378c0 (123 B): equivalent/0x003378c0.cpp
// sym: ?FUN_003378c0@fn_f964084a@@YIPBDPAUParseError@1@@Z @76ade42338c9 @wf0cd6794dafc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/13)
// FUN_003378c0 @ 0x003378c0
const char* __fastcall FUN_003378c0(ParseError* err) {
    DAT_0055ddc0[0] = 0;
    const char* name;
    if (err->context == 0 || (name = err->context->FUN_00338a10()) == 0)
        name = "<?>";
    const char* fmt;
    switch (err->code) {
    case 0:
        return "No error.";
    case 1:
        return "Hit EOF, no error.";
    case 2:
        return "Ending quotation \" expected.";
    case 3:
        return "Token size is too big. Did you forget a quotation?";
    case 4:
        fmt = "Syntax error, bad command '%s'.";
        break;
    case 5:
        fmt = "No object definition found for '%s'.";
        break;
    case 6:
        fmt = "No attribute definition found for '%s'.";
        break;
    default:
        return "Unknown Error...something is really wrong";
    }
    sprintf(DAT_0055ddc0, fmt, name);
    return DAT_0055ddc0;
}


// 0x00337980 FUN_00337980 (33 B): matches/0x00337980.cpp
// sym: ?run@S_337980@fn_f964084a@@QAEHXZ
hulk_intptr S_337980::run() {
    int r;
    int x;
    do {
        r = obj->Query_00338a10();
        x = obj->result;
        value = x;
        if (r != 0)
            return r;
    } while (x == 0);
    return r;
}


// 0x003379c0 FUN_003379c0 (69 B): equivalent/0x003379c0.cpp
// sym: ?FUN_003379c0@fn_f964084a@@YA_NPBD@Z @3f8d70d544e7 @wcc2090e2087f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_003379c0 @ 0x003379c0
bool __cdecl FUN_003379c0(const char* text)
{
    const char* attr = "attr";
    const char* object = "object";
    const char* version = "version";
    int i;
    for (i = 0; i < 5; ++i)
        if (text[i] != attr[i]) break;
    if (i == 5) return true;
    for (i = 0; i < 7; ++i)
        if (text[i] != object[i]) break;
    if (i == 7) return true;
    for (i = 0; i < 8; ++i)
        if (text[i] != version[i]) return false;
    return true;
}

} // namespace fn_f964084a

// 0x00337a10 FUN_00337a10 (30 B): matches/0x00337a10.cpp [wrapped: same definition as 0x00337330 in this TU]
// sym: ?vfunc_2@CCollisionAction@fn_00337a10@@UAEPAV12@E@Z
namespace fn_00337a10 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_00337890 {
    void FUN_00337890();
};
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_00337890*)(this))->FUN_00337890();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00337a10

namespace fn_f964084a {

// 0x00337c00 FUN_00337c00 (9 B): matches/0x00337c00.cpp
// sym: ??0X_337c00@fn_f964084a@@QAE@XZ
// data: vtable_337c00 = DAT_004345dc
X_337c00::X_337c00() {
    p = ((int*)&DAT_004345dc);
}


// 0x00337c10 FUN_00337c10 (7 B): matches/0x00337c10.cpp
// sym: ?FUN_00337c10@fn_f964084a@@YIXPAX@Z
// Same code shape as 0x001b6820 (propagated; names are from that function)
// data: IRefCount_vftable_337c10 = DAT_004345dc
void __fastcall FUN_00337c10(void* self) {
    *(void**)self = ((void**)&DAT_004345dc);
}

} // namespace fn_f964084a

// 0x00337d00 FUN_00337d00 (30 B): matches/0x00337d00.cpp [wrapped: same definition as 0x00337330 in this TU]
// sym: ?vfunc_2@CCollisionAction@fn_00337d00@@UAEPAV12@E@Z
namespace fn_00337d00 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
extern void __fastcall FUN_00337c10(void*);
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_00337c10((void*)(this));
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00337d00

namespace fn_f964084a {

// 0x00337d20 FUN_00337d20 (28 B): matches/0x00337d20.cpp
// sym: ??0X_337d20@fn_f964084a@@QAE@PAXH@Z
// data: vtable_337d20 = DAT_004345e0
// A buffer object over caller-owned memory: the vftable, the buffer, its size, and the current position (the start).
X_337d20::X_337d20(void* p, int q) {
    v = ((int*)&DAT_004345e0);
    a = (char*)p;
    b = q;
    c = (char*)p;
}


// 0x00337d40 FUN_00337d40 (7 B): matches/0x00337d40.cpp
// sym: ?FUN_00337d40@fn_f964084a@@YIXPAX@Z
// Same code shape as 0x001b6820 (propagated; names are from that function)
// data: IRefCount_vftable_337d40 = DAT_004345e0
void __fastcall FUN_00337d40(void* self) {
    *(void**)self = ((void**)&DAT_004345e0);
}

} // namespace fn_f964084a

// 0x00337d50 FUN_00337d50 (7 B): matches/0x00337d50.cpp
// sym: ?FUN_00337d50@A_337d50@owners@@QAEXXZ
void owners::A_337d50::FUN_00337d50() {
    y = x;
}


// 0x00337d60 FUN_00337d60 (63 B): equivalent/0x00337d60.cpp
// sym: ?FUN_00337d60@Allocator_337d60@owners@@QAEIII@Z @7ae0e8ae2789 @w961741c5a638
// STATUS: equivalent (tools/equiv.py level 3: 2041 inputs, branch coverage 6/6)
// FUN_00337d60 @ 0x00337d60
hulk_uintptr owners::Allocator_337d60::FUN_00337d60(unsigned int size, unsigned int alignment) {
    if (size == 0) return 0;
    while (offset % alignment != 0) ++offset;
    unsigned int result = offset;
    offset = result + size;
    return result;
}


// 0x00337da0 FUN_00337da0 (30 B): matches/0x00337da0.cpp [wrapped: same definition as 0x00337330 in this TU]
// sym: ?vfunc_2@CCollisionAction@fn_00337da0@@UAEPAV12@E@Z
namespace fn_00337da0 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
extern void __fastcall FUN_00337d40(void*);
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_00337d40((void*)(this));
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00337da0

namespace fn_f964084a {

// 0x00337dc0 FUN_00337dc0 (102 B): matches/0x00337dc0.cpp
// sym: ?Find@fn_f964084a@@YAHPBD@Z
// data: g_tab = DAT_004d982c
int Find(const char* s) {
    for (int i = 0; i < 11; i++) {
        if (strcmp(s, ((const char**)&DAT_004d982c)[i]) == 0)
            return i;
    }
    return -1;
}


// 0x00337e50 FUN_00337e50 (26 B): matches/0x00337e50.cpp
// sym: ?FUN_00337e50@fn_f964084a@@YADPBD@Z
char FUN_00337e50(const char* s) {
    return strcmp(s, "true") == 0;
}


// 0x00337e90 FUN_00337e90 (7 B): matches/0x00337e90.cpp
// sym: ?FUN_00337e90@fn_f964084a@@YIXPAX@Z
// Same code shape as 0x001b6820 (propagated; names are from that function)
// data: IRefCount_vftable_337e90 = DAT_0043462c
void __fastcall FUN_00337e90(void* self) {
    *(void**)self = ((void**)&DAT_0043462c);
}


// 0x00337ea0 FUN_00337ea0 (21 B): matches/0x00337ea0.cpp
// sym: ?target@fn_f964084a@@YIXPAUX_337ea0@1@PAX@Z
void __fastcall target(X_337ea0* p, void*) {
    p->a = 0;
    p->b = -1;
    p->c = 0;
    p->d = 0;
    p->e = -1;
}

} // namespace fn_f964084a

// 0x00337ec0 FUN_00337ec0 (48 B): equivalent/0x00337ec0.cpp
// sym: ?FUN_00337ec0@Object_337ec0@owners@@QAEHXZ @50ad68bc2520 @w4111432d41fa
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 13/13)
// FUN_00337ec0 @ 0x00337ec0
int owners::Object_337ec0::FUN_00337ec0() { switch (kind) { case 0: return 1; case 1: case 3: return 16; case 2: case 5: case 7: case 9: return 8; case 4: return 4; case 6: case 8: return 12; default: return 0; } }

namespace fn_f964084a {

// 0x00337f20 FUN_00337f20 (43 B): equivalent/0x00337f20.cpp
// sym: ?FUN_00337f20@fn_f964084a@@YAII@Z @e40bf3f105ca @w9f7333a02693
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 13/13)
// FUN_00337f20 @ 0x00337f20
unsigned int __cdecl FUN_00337f20(unsigned int value)
{
    switch (value) {
    case 0: return 1;
    case 1: case 2: case 3: case 4: case 9: case 10: return 4;
    case 5: case 7: return 8;
    case 6: case 8: return 12;
    default: return 0;
    }
}

} // namespace fn_f964084a

// 0x00337f80 FUN_00337f80 (61 B): equivalent/0x00337f80.cpp
// sym: ?FUN_00337f80@Value_337f80@owners@@QAEIXZ @97c48eab0a4e @w9e5fa82188ea
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 15/15)
// FUN_00337f80 @ 0x00337f80
unsigned int owners::Value_337f80::FUN_00337f80() { switch (type) { case 0: return 1; case 1: case 2: case 3: return 4; case 4: { const char *p = *text; unsigned int size = 1; while (*p++) ++size; return size; } case 5: case 7: return 8; case 6: case 8: return 12; default: return 0; } }

namespace fn_f964084a {

// 0x00338000 FUN_00338000 (14 B): equivalent/0x00338000.cpp
// sym: ??0Obj@fn_f964084a@@QAE@XZ @b3d96546a8f5 @w5f3dd28890f8
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00338000 @ 0x00338000
Obj::Obj() {
    FUN_00337ea0();
}

} // namespace fn_f964084a

// 0x00338010 FUN_00338010 (30 B): matches/0x00338010.cpp [wrapped: same definition as 0x00337330 in this TU]
// sym: ?vfunc_2@CCollisionAction@fn_00338010@@UAEPAV12@E@Z
namespace fn_00338010 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
extern void __fastcall FUN_00337e90(void*);
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_00337e90((void*)(this));
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00338010


// 0x00338030 FUN_00338030 (1209 B): equivalent/0x00338030.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_00338030@AttrDef_338030@fn_00338030@@QAE_NPAVLoader_338030@2@@Z @67f453423d27 @w3208f2fe5d48
namespace fn_00338030 {
// STATUS: equivalent (tools/equiv.py level 3: 3083 inputs, branch coverage 88/88)
// FUN_00338030 @ 0x00338030


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" long atol(const char *s);
#endif

extern "C++" double __cdecl FUN_003458c1(const char *s);
extern "C" int __cdecl FUN_00337dc0(const char *s);
extern "C++" char __cdecl FUN_00337e50(const char *s);
extern "C++" char __cdecl FUN_00337370(const char *s);

class Pool_338030 {
public:
    void *FUN_00337d60(unsigned int size, int align);
};

class Loader_338030 {
public:
    char pad0[0x5108];
    int status;
    const char *FUN_00337460();
    void FUN_003374a0();
    void FUN_003375a0();
};

class AttrDef_338030 {
public:
    char pad0[4];
    char *name;
    int type;
    char *value;
    bool FUN_00338030(Loader_338030 *ld);
};

static void CopyString(char **slot, const char *src)
{
    const char *e = src;
    while (*e++ != 0) {
    }
    char *d = (char *)(*(Pool_338030*)&DAT_00565fc0).FUN_00337d60((unsigned int)(e - src), 4);
    *slot = d;
    char c;
    do {
        c = *src++;
        *d++ = c;
    } while (c != 0);
}

bool AttrDef_338030::FUN_00338030(Loader_338030 *ld)
{
    const char *tok = ld->FUN_00337460();
    if (tok == 0)
        return false;
    CopyString(&name, tok);
    ld->FUN_003374a0();

    tok = ld->FUN_00337460();
    if (tok == 0)
        return false;
    type = FUN_00337dc0(tok);
    if (type == -1) {
        ld->status = 10;
        return false;
    }
    ld->FUN_003374a0();
    char *v = (char *)(*(Pool_338030*)&DAT_00565fc0).FUN_00337d60(((owners::Object_337ec0 *)this)->FUN_00337ec0(), 4);
    value = v;

    switch (type) {
    case 0:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *v = FUN_00337e50(tok);
        ld->FUN_003374a0();
        return true;
    case 1: {
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)v = atol(tok);
        ld->FUN_003375a0();
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        if (FUN_00337370(tok)) {
            v[4] = 0;
            return true;
        }
        v[4] = 1;
        *(int *)(v + 8) = atol(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)(v + 0xc) = atol(tok);
        ld->FUN_003374a0();
        return true;
    }
    case 2:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)v = atol(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        CopyString((char **)(v + 4), tok);
        ld->FUN_003374a0();
        return true;
    case 3: {
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)v = (float)FUN_003458c1(tok);
        ld->FUN_003375a0();
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        if (FUN_00337370(tok)) {
            v[4] = 0;
            return true;
        }
        v[4] = 1;
        *(float *)(v + 8) = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)(v + 0xc) = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        return true;
    }
    case 4:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        CopyString((char **)v, tok);
        ld->FUN_003374a0();
        return true;
    case 5:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)v = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)(v + 4) = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        return true;
    case 6:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)v = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)(v + 4) = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(float *)(v + 8) = (float)FUN_003458c1(tok);
        ld->FUN_003374a0();
        return true;
    case 7:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)v = atol(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)(v + 4) = atol(tok);
        ld->FUN_003374a0();
        return true;
    case 8:
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)v = atol(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)(v + 4) = atol(tok);
        ld->FUN_003374a0();
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        *(int *)(v + 8) = atol(tok);
        ld->FUN_003374a0();
        return true;
    case 9: {
        tok = ld->FUN_00337460();
        if (tok == 0)
            return false;
        int r = FUN_00337dc0(tok);
        *(int *)v = r;
        *(int *)(v + 4) = 0;
        if (r == -1) {
            ld->status = 10;
            return false;
        }
        if (r == 9) {
            ld->status = 11;
            return false;
        }
        ld->FUN_003374a0();
        if (*(int *)v == 2) {
            tok = ld->FUN_00337460();
            if (tok == 0)
                return false;
            CopyString((char **)(v + 4), tok);
            ld->FUN_003374a0();
        }
        return true;
    }
    }
    return true;
}
} // namespace fn_00338030


// 0x00338520 FUN_00338520 (17 B): matches/0x00338520.cpp
// sym: ?FUN_00338520@Obj_338520@owners@@QAEXXZ
void owners::Obj_338520::FUN_00338520() {
    vptr = ((int*)&DAT_00434630);
    thunk_FUN_00267090(m);
}

namespace fn_f964084a {

// 0x003385f0 FUN_003385f0 (51 B): matches/0x003385f0.cpp
// sym: ?Run@Target_3385f0@fn_f964084a@@QAE_NH@Z
bool Target_3385f0::Run(hulk_intptr x) {
    if (obj->Test(x)) {
        state = 1;
        return true;
    }
    state = 0;
    return false;
}


// 0x00338630 FUN_00338630 (8 B): matches/0x00338630.cpp
// sym: ?target@fn_f964084a@@YIXPAUB_338630@1@@Z
void __fastcall target(B_338630* self) {
    self->p->f2();
}

} // namespace fn_f964084a

// 0x00338640 FUN_00338640 (44 B): matches/0x00338640.cpp [wrapped: conflict: Copy]
// sym: ?Copy@fn_00338640@@YGXPADPBD@Z
namespace fn_00338640 {
void __stdcall Copy(char* dst, const char* src) {
    bool keep = true;
    char c;
    do {
        c = *src;
        if (!(c != 0 || keep))
            break;
        keep = c != 0;
        *dst = c;
        ++dst;
        ++src;
    } while (1);
    *dst = 0;
}
} // namespace fn_00338640

namespace fn_f964084a {

// 0x003386a0 FUN_003386a0 (100 B): matches/0x003386a0.cpp
// sym: ?Get@Rd_3386a0@fn_f964084a@@QAE_NPAD@Z
bool Rd_3386a0::Get(char* out) {
    if (pos < len) {
        *out = buf[pos];
        pos++;
        return true;
    }
    if (src->More()) {
        len = src->Read(buf, size);
        pos = 0;
        if (len > 0) {
            *out = *buf;
            pos++;
            return true;
        }
    }
    return false;
}


// 0x00338710 FUN_00338710 (129 B): equivalent/0x00338710.cpp
// sym: ?FUN_00338710@fn_f964084a@@YG_NPBD0H@Z @4f89a69facfd @w75dcb0861e58
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 18/18)
// FUN_00338710 @ 0x00338710
// 0x00338710: true if str (of length len, or its strlen when len <= 0) ends with suffix
bool __stdcall FUN_00338710(const char* str, const char* suffix, int len)
{
    if (len <= 0)
        len = (int)(__int64)strlen_inline(str);
    int suffixLen = (int)(__int64)strlen_inline(suffix);
    if (suffixLen > len)
        return false;
    return strcmp_inline(suffix, str + (len - suffixLen)) == 0;
}

} // namespace fn_f964084a

// 0x003387a0 FUN_003387a0 (42 B): matches/0x003387a0.cpp
// sym: ?FUN_003387a0@Obj_3387a0@owners@@QAE_ND@Z
bool owners::Obj_3387a0::FUN_003387a0(char c) {
    char* p = str;
    while (*p) {
        if (*p == c)
            return true;
        ++p;
    }
    return false;
}


// 0x003387d0 FUN_003387d0 (42 B): matches/0x003387d0.cpp
// sym: ?FUN_003387d0@Obj_3387d0@owners@@QAEED@Z
unsigned char owners::Obj_3387d0::FUN_003387d0(char c) {
    char* p = s;
    while (*p != 0) {
        if (*p == c)
            return 1;
        ++p;
    }
    return 0;
}


// 0x00338800 FUN_00338800 (83 B): matches/0x00338800.cpp
// sym: ?FUN_00338800@Obj_338800@owners@@QAEPADPBD@Z
char* owners::Obj_338800::FUN_00338800(const char* name) {
    char* s = text;
    hulk_uintptr len = strlen(name);
    while (*s) {
        if (Match(name, s, len))
            return s;
        s += strlen(s) + 1;
    }
    return 0;
}


// 0x00338860 FUN_00338860 (22 B): equivalent/0x00338860.cpp
// sym: ?FUN_00338860@Object_338860@owners@@QAEHH@Z @0deba1ff42c4 @w92a6c6846121
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00338860 @ 0x00338860
// FUN_00338860 @ 0x00338860
int owners::Object_338860::FUN_00338860(hulk_intptr value) { return FUN_00338710(((int)value), &field, 0); }


// 0x003388c0 FUN_003388c0 (15 B): matches/0x003388c0.cpp
// sym: ?FUN_003388c0@C_3388c0@owners@@QAEXXZ
void owners::C_3388c0::FUN_003388c0() {
    a = 0;
    b = 0;
}


// 0x003389d0 FUN_003389d0 (30 B): matches/0x003389d0.cpp [wrapped: same definition as 0x00337330 in this TU]
// sym: ?vfunc_2@CCollisionAction@fn_003389d0@@UAEPAV12@E@Z
namespace fn_003389d0 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_00338520 {
    void FUN_00338520();
};
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_00338520*)(this))->FUN_00338520();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_003389d0

namespace fn_f964084a {

// 0x00338a10 FUN_00338a10 (880 B): equivalent/0x00338a10.cpp
// sym: ?FUN_00338a10@Tokenizer@fn_f964084a@@QAEPADXZ @8bd2934cce14 @w7d2dc0ff8543
// STATUS: equivalent (tools/equiv.py level 3: 3041 inputs, branch coverage 76/82, incomplete)
// FUN_00338a10 @ 0x00338a10
char *Tokenizer::FUN_00338a10()
{
    struct Frame {
        char pad[2];
        char flagB;
        char inQuote;
        char *tokstart;
        char *curp;
        union {
            char c;
            int w;
        } ch;
    } f;
    char *out;
    char c;

    if (status)
        return 0;
    if (done)
        return tok;

    out = tok;
    f.tokstart = out;
    f.inQuote = 0;
    f.flagB = 0;
    if (saved) {
        f.inQuote = savedQuote;
        f.flagB = savedFlagB;
        out = savedEnd;
        saved = 0;
    } else {
        *out = 0;
    }

    f.curp = cur;
    c = cur[0];
    if (c != 0) {
        if (c == '"') {
            f.inQuote = 1;
        } else {
            if (FUN_00338800(cur)) {
                char *d = f.tokstart;
                char *s = cur;
                char t;
                do {
                    t = *s;
                    *d = t;
                    s++;
                    d++;
                } while (t);
                cur[0] = t;
                done = 1;
                return f.tokstart;
            }
            if (c == '\n')
                lineno++;
        }
    }
    cur[0] = 0;

    for (;;) {
        if (pos < len) {
            c = buf[pos];
            pos++;
        } else {
            if (!source->AtEnd()) {
                if (source->AtEnd()) {
                    savedEnd = out;
                    savedQuote = f.inQuote;
                    saved = 1;
                    savedFlagB = f.flagB;
                    return 0;
                }
                status = (f.inQuote != 0) + 1;
                return done ? f.tokstart : 0;
            }
            len = source->Read(buf, bufSize);
            pos = 0;
            if (len <= 0) {
                if (source->AtEnd()) {
                    savedEnd = out;
                    savedQuote = f.inQuote;
                    saved = 1;
                    savedFlagB = f.flagB;
                    return 0;
                }
                status = (f.inQuote != 0) + 1;
                return done ? f.tokstart : 0;
            }
            c = buf[0];
            pos = 1;
        }
        f.ch.c = c;
        int chw = f.ch.w;
        if (FUN_003387d0(chw))
            continue;
        if (!f.inQuote && !f.flagB) {
            if (FUN_003387a0(chw)) {
                if (out - tok <= 0)
                    continue;
                break;
            }
        }
        if (c == '\n') {
            if (!f.inQuote) {
                if (out - tok > 0) {
                    if (f.flagB)
                        flag821 = 1;
                    cur[0] = '\n';
                    cur[1] = 0;
                    break;
                }
                lineno = lineno + 1;
                f.flagB = 0;
                continue;
            }
            lineno++;
        }
        if (!f.flagB && c == '"') {
            if (f.inQuote)
                break;
            if (out - tok > 0) {
                cur[0] = '"';
                cur[1] = 0;
                break;
            }
            f.inQuote = 1;
            continue;
        }
        if (flag872 != 0 || f.flagB == 0) {
            if (out - tok >= 0x3ff) {
                status = 3;
                return 0;
            }
            *out = c;
            out++;
            *out = 0;
        }
        if (f.inQuote)
            continue;
        {
            char *ts = f.tokstart;
            if (!f.flagB) {
                char *m = FUN_00338800(ts);
                if (m) {
                    int l1 = 0;
                    while (ts[l1])
                        l1++;
                    int l2 = 0;
                    while (m[l2])
                        l2++;
                    if (l1 > l2) {
                        char *d = f.curp;
                        char *s = m;
                        char t;
                        do {
                            t = *s;
                            *d = t;
                            s++;
                            d++;
                        } while (t);
                        tok[l1 - l2] = t;
                    }
                    break;
                }
            }
            if (!FUN_00338860(ts))
                continue;
            out = f.tokstart;
            int l1 = 0;
            while (out[l1])
                l1++;
            int l2 = 0;
            while (delim[l2])
                l2++;
            if (l1 > l2) {
                char *d = f.curp;
                char *s = delim;
                char t;
                do {
                    t = *s;
                    *d = t;
                    s++;
                    d++;
                } while (t);
                tok[l1 - l2] = t;
                break;
            }
            f.flagB = 1;
            *out = 0;
        }
    }
    done = 1;
    return f.tokstart;
}

} // namespace fn_f964084a

// 0x00338d80 FUN_00338d80 (16 B): matches/0x00338d80.cpp
// sym: ?FUN_00338d80@Obj_338d80@owners@@QAEXXZ
// Same code shape as 0x00236820 (propagated; names are from that function)
void owners::Obj_338d80::FUN_00338d80() {
    A();
    B();
}

