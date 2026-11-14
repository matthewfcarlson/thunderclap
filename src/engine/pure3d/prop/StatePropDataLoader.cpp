// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0028fe80..0x00291bc0 (kind game, layer engine, confidence high), dominant class pure3d::prop::StatePropDataLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/loaders.h"
#include "gen/content.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f5d7895e {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
namespace fn_f5d7895e {} using namespace fn_f5d7895e;
namespace fn_f5d7895e { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/pure3d/prop.h"

// ---- declarations shared by the functions below
namespace fn_f5d7895e {
extern "C" void __cdecl releaseMem_0008d340(void*);
} // namespace fn_f5d7895e
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif
namespace fn_f5d7895e {
extern void __cdecl ReleaseThing_0008d340(int);
class Obj_290070 {
  public:
    char pad[8];
    int ptr;
    void Reset_0027af50();
    Obj_290070* Run(unsigned char flag);
};
struct Sub_2900f0 {
    int x;
    void Fnf_0027af50();
};
struct Obj_2900f0 {
    char pad[0x28];
    Sub_2900f0 a;
    char p2[4];
    Sub_2900f0 b;
    char p3[4];
    Sub_2900f0 c;
    char p4[4];
    Sub_2900f0 d;
    void FUN_002900f0();
};
class Obj_290340 {
  public:
    char pad[8];
    int field;
    void Init_0027af00();
    void Configure_0027af70(void*);
    Obj_290340* Run(void*);
};
extern void FUN_0027af50();
class Part_290470 {
  public:
    char x[8];
    void Clear_0027af50();
};
class Obj_290470 {
  public:
    char pad[0x28];
    Part_290470 a, b, c, d;
    Obj_290470* Run(unsigned char flag);
};
void Free_0008d330(Obj_290470*);
extern void* hulk_at_003f6098;
typedef unsigned int u32_290500;
struct Item_290500 {
    char pad[8];
    volatile u32_290500 handle;
    char rest[4];
    void Process_0027af50();
};
void __cdecl ReleaseHandle_0008d340(u32_290500);
typedef unsigned int u32_290590;
typedef unsigned int u32_2905c0;
extern "C" char DAT_0042cca0[];
class StatePropDataLoader : public HulkChunkHandler {
  public:
    StatePropDataLoader();
};
extern void* Alloc_0008d6d0(unsigned int);
extern "C" int * __cdecl FUN_002904d0(int *, int, const int *);
struct Obj_2907f0 {
    int a;
    int b;
};
extern "C" void __cdecl FUN_00290500(void *, void *);
extern void __cdecl Fng_0008d340(int);
class Item_290810 {
  public:
    char pad[8];
    int field;
    void Init_0027af00();
    void Configure_0027af70(Item_290810*);
};
void* __cdecl FUN_0008d6d0(unsigned size);
extern "C" void * __cdecl FUN_00290810(void *, int, void *);
struct Temp_290ad0 {
    char pad[8];
    hulk_intptr value;
    int extra;
    void Init_0027af00();
    void Fin_0027af50();
};
extern void Free_0008d340(void*);
class Obj_290ad0 {
  public:
    bool Run(int);
};

} // namespace fn_f5d7895e

// 0x0028fe80 FUN_0028fe80 (81 B): matches/0x0028fe80.cpp
// sym: ?FUN_0028fe80@Obj_28fe80@owners@@QAEXPBD@Z
void owners::Obj_28fe80::FUN_0028fe80(const char* src) {
    if (text) {
        releaseMem_0008d340(text);
        text = 0;
    }
    if (src) {
        text = (char*)allocMem(strlen(src) + 1);
        strcpy(text, src);
    }
}


// 0x0028ff00 FUN_0028ff00 (365 B): equivalent/0x0028ff00.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0StateData@prop@pure3d@fn_0028ff00@@QAE@HHHHHHH@Z @fa182d093ea4 @w98cf8ee7ce1b
namespace fn_0028ff00 {
// STATUS: equivalent (tools/equiv.py level 3: 19 inputs, branch coverage 10/10)
// FUN_0028ff00 @ 0x0028ff00
extern "C++" __declspec(nothrow) void *__cdecl FUN_0008d6d0(unsigned int size);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memset(void *dst, int c, unsigned int n);
#endif


struct Name_28ff00 {
    char data[8];
    void FUN_0027b040(const char *s);
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void e0_00038290();
    char pad4[4];
    Name_28ff00 name;
    void FUN_0027b070();
    Entity() throw() { FUN_0027b070(); }
};

namespace prop {
class StateData : public Entity {
public:
    virtual void x1_000382a0();
    virtual void x2();
    virtual void x3_0027afe0();
    char *base;
    int count4;
    char *area4;
    int count5;
    char *area5;
    int count1;
    char *area1;
    int count2;
    char *area2;
    int count3;
    char *area3;
    int count6;
    char *area6;
    int count7;
    char *area7;
    int f4c;
    char *buffer;
    StateData(int n1, int n2, int n3, int n4, int n5, int n6, int n7) throw();
};
}
}

static int Align4(int bytes)
{
    return (bytes + 3) & ~3;
}

pure3d::prop::StateData::StateData(int n1, int n2, int n3, int n4, int n5, int n6, int n7) throw()
{
    count4 = n4;
    int size4 = Align4(n4 * 16);
    count6 = n6;
    count7 = n7;
    count5 = n5;
    count3 = n3;
    count2 = n2;
    count1 = n1;
    base = 0;
    area4 = 0;
    area5 = 0;
    area1 = 0;
    area2 = 0;
    area3 = 0;
    area6 = 0;
    area7 = 0;
    f4c = 0;
    buffer = 0;
    int size6 = Align4(n6 * 16);
    int size5 = Align4(n5 * 32);
    int size3 = Align4(n3 * 16);
    int size1 = Align4(n1 * 16);
    int size7 = Align4(n7 * 0x58);
    int size2 = Align4(n2 * 48);
    int total = size6 + size5 + size4 + size3 + size7 + size1 + size2 + 0xc;
    buffer = (char *)FUN_0008d6d0(total);
    memset(buffer, 0, total);
    char *b = buffer;
    area4 = b + 0xc;
    int off = size4 + 0xc;
    area5 = b + off;
    off += size5;
    base = b;
    if (n1 > 0) {
        area1 = b + off;
        off += size1;
    }
    if (n2 > 0) {
        area2 = b + off;
        off += size2;
    }
    if (n3 > 0) {
        area3 = b + off;
        off += size3;
    }
    if (n7 > 0) {
        area7 = b + off;
        off += size7;
    }
    if (n6 > 0) {
        area6 = b + off;
    }
}
} // namespace fn_0028ff00

namespace fn_f5d7895e {

// 0x00290070 FUN_00290070 (55 B): matches/0x00290070.cpp
// sym: ?Run@Obj_290070@fn_f5d7895e@@QAEPAV12@E@Z
Obj_290070* Obj_290070::Run(unsigned char flag) {
    if (ptr != 0) {
        ReleaseThing_0008d340(ptr);
        ptr = 0;
    }
    Reset_0027af50();
    if (flag & 1) {
        ReleaseSelf((void*)this);
    }
    return this;
}


// 0x002900f0 FUN_002900f0 (36 B): matches/0x002900f0.cpp
// sym: ?FUN_002900f0@Obj_2900f0@fn_f5d7895e@@QAEXXZ
void Obj_2900f0::FUN_002900f0() {
    d.Fnf_0027af50();
    c.Fnf_0027af50();
    b.Fnf_0027af50();
    a.Fnf_0027af50();
}


// 0x00290340 FUN_00290340 (46 B): matches/0x00290340.cpp
// sym: ?Run@Obj_290340@fn_f5d7895e@@QAEPAV12@PAX@Z
Obj_290340* Obj_290340::Run(void* arg) {
    Init_0027af00();
    field = 0;
    Configure_0027af70(arg);
    ((owners::Obj_28fe80 *)this)->FUN_0028fe80((const char *)(hulk_uintptr)(int)(*(int*)((char*)arg + 8)));
    return this;
}


// 0x002903d0 FUN_002903d0 (30 B): matches/0x002903d0.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f5d7895e@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_0027af50();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f5d7895e

// 0x002903f0 FUN_002903f0 (30 B): matches/0x002903f0.cpp [wrapped: same definition as 0x002903d0 in this TU]
// sym: ?vfunc_2@CCollisionAction@fn_002903f0@@UAEPAV12@E@Z
namespace fn_002903f0 {
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
extern void FUN_0027af50();
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_0027af50();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002903f0


// 0x00290410 FUN_00290410 (30 B): matches/0x00290410.cpp [wrapped: same definition as 0x002903d0 in this TU]
// sym: ?vfunc_2@CCollisionAction@fn_00290410@@UAEPAV12@E@Z
namespace fn_00290410 {
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
extern void FUN_0027af50();
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_0027af50();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00290410


// 0x00290430 FUN_00290430 (30 B): matches/0x00290430.cpp [wrapped: same definition as 0x002903d0 in this TU]
// sym: ?vfunc_2@CCollisionAction@fn_00290430@@UAEPAV12@E@Z
namespace fn_00290430 {
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
extern void FUN_0027af50();
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_0027af50();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00290430


// 0x00290450 FUN_00290450 (30 B): matches/0x00290450.cpp [wrapped: same definition as 0x002903d0 in this TU]
// sym: ?vfunc_2@CCollisionAction@fn_00290450@@UAEPAV12@E@Z
namespace fn_00290450 {
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
extern void FUN_0027af50();
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_0027af50();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00290450

namespace fn_f5d7895e {

// 0x00290470 FUN_00290470 (57 B): matches/0x00290470.cpp
// sym: ?Run@Obj_290470@fn_f5d7895e@@QAEPAV12@E@Z
Obj_290470* Obj_290470::Run(unsigned char flag) {
    d.Clear_0027af50();
    c.Clear_0027af50();
    b.Clear_0027af50();
    a.Clear_0027af50();
    if (flag & 1)
        Free_0008d330(this);
    return this;
}


// 0x002904b0 FUN_002904b0 (7 B): matches/0x002904b0.cpp
// sym: ?FUN_002904b0@fn_f5d7895e@@YIXPAX@Z
// Same code shape as 0x001b6820 (propagated; names are from that function)
void __fastcall FUN_002904b0(void* self) {
    *(void**)self = &hulk_at_003f6098;
}


// 0x002904d0 FUN_002904d0 (40 B): matches/0x002904d0.cpp
// sym: _FUN_002904d0
// Same code shape as 0x002ab530 (propagated; names are from that function)
extern "C" int* FUN_002904d0(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}


// 0x00290500 FUN_00290500 (56 B): matches/0x00290500.cpp
// sym: _FUN_00290500
extern "C" void __cdecl FUN_00290500(void * begin, void * end) {
    Item_290500* p = ((Item_290500 *)begin);
    while (p != ((Item_290500 *)end)) {
        u32_290500 h = p->handle;
        if (h) {
            ReleaseHandle_0008d340(h);
            p->handle = 0;
        }
        p->Process_0027af50();
        p = (Item_290500*)((char*)p + 16);
    }
}

} // namespace fn_f5d7895e

// 0x00290590 content::LoadInventory::DynamicCaster<physics::CollisionObject>::vfunc_0 (30 B): matches/0x00290590.cpp
// sym: ?vfunc_0@?$DynamicCaster@VCollisionObject@physics@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<physics::CollisionObject>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002905c0 content::LoadInventory::DynamicCaster<physics::PhysicsObject>::vfunc_0 (30 B): matches/0x002905c0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VPhysicsObject@physics@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<physics::PhysicsObject>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002905e0 FUN_002905e0 (345 B): equivalent/0x002905e0.cpp [wrapped: conflict: core::IRefCount; pure3d::prop::StateData]
// sym: ?FUN_002905e0@StateData@prop@pure3d@fn_002905e0@@QAEXXZ @71d3e9ccd2fe @weaf4092cf7dd
inline void *operator new(size_t, void *p) { return p; }
namespace fn_002905e0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 32/32)
// FUN_002905e0 @ 0x002905e0


extern "C" void __cdecl FUN_0008d330(void *p);
extern "C" void __cdecl FUN_0008d340(void *p);

struct Part_2905e0 {
    char data[8];
    void FUN_0027af50();
};

struct Item10_2905e0 {
    char pad0[8];
    void *buffer;
    char pad1[4];
    void FUN_0027af50();
};

struct Item20 {
    char data[0x20];
    void FUN_0027af50();
};

struct Item30 {
    char data[0x30];
    void FUN_0027af50();
};

struct Item58 {
    char pad0[0x28];
    Part_2905e0 p28;
    Part_2905e0 p30;
    Part_2905e0 p38;
    Part_2905e0 p40;
    char pad1[0x58 - 0x48];
};

class Releasable_2905e0 {
public:
    virtual void vf0();
    virtual void release();
};

namespace core {
struct IRefCount {
    void FUN_0027afd0();
};
}

namespace pure3d {
namespace prop {
class StateData {
public:
    virtual void vfunc_0_00038290();
    virtual void vfunc_1_000382a0();
    virtual void vfunc_2();
    virtual void vfunc_3_0027afe0();
    virtual void vfunc_4_0027aff0();
    char pad04[0x14 - 4];
    int count14;
    Item10_2905e0 *items18;
    int count1c;
    Item20 *items20;
    int count24;
    Item10_2905e0 *items28;
    int count2c;
    Item30 *items30;
    int count34;
    Item10_2905e0 *items38;
    int count3c;
    Item10_2905e0 *items40;
    int count44;
    Item58 *items48;
    Releasable_2905e0 *owner4c;
    void *data50;

    void FUN_002905e0();
};
}
}

void pure3d::prop::StateData::FUN_002905e0()
{
    new (this) StateData;
    int i;
    for (i = 0; i < count14; i++)
        ((Part_2905e0 *)((char *)items18 + i * 0x10))->FUN_0027af50();
    for (i = 0; i < count1c; i++)
        ((Part_2905e0 *)((char *)items20 + i * 0x20))->FUN_0027af50();
    for (i = 0; i < count24; i++)
        ((Part_2905e0 *)((char *)items28 + i * 0x10))->FUN_0027af50();
    for (i = 0; i < count2c; i++)
        ((Part_2905e0 *)((char *)items30 + i * 0x30))->FUN_0027af50();
    for (i = 0; i < count34; i++)
        ((Part_2905e0 *)((char *)items38 + i * 0x10))->FUN_0027af50();
    for (i = 0; i < count44; i++) {
        Item58 *e = &items48[i];
        e->p40.FUN_0027af50();
        e->p38.FUN_0027af50();
        e->p30.FUN_0027af50();
        e->p28.FUN_0027af50();
    }
    for (i = 0; i < count3c; i++) {
        Item10_2905e0 *e = &items40[i];
        if (e->buffer) {
            FUN_0008d340(e->buffer);
            e->buffer = 0;
        }
        ((Part_2905e0 *)e)->FUN_0027af50();
    }
    if (owner4c) {
        owner4c->release();
        owner4c = 0;
    }
    FUN_0008d330(data50);
    ((core::IRefCount *)this)->FUN_0027afd0();
}
} // namespace fn_002905e0

namespace fn_f5d7895e {

// 0x00290740 FUN_00290740 (27 B): matches/0x00290740.cpp
// sym: ??0StatePropDataLoader@fn_f5d7895e@@QAE@XZ
StatePropDataLoader::StatePropDataLoader() {
    refs = 0;
    id = 0x802000a;
    f0c = 0;
    f10 = 0;
    vftable = (void*)DAT_0042cca0;
}

} // namespace fn_f5d7895e

// 0x00290760 pure3d::prop::StatePropDataLoader::vfunc_2 (31 B): matches/0x00290760.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00290760@@UAEPAV123@E@Z
namespace fn_00290760 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_290760 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_290760 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00290760


// 0x00290790 FUN_00290790 (95 B): matches/0x00290790.cpp
// sym: ?FUN_00290790@Buffer_290790@owners@@QAE_NIPAX@Z
bool owners::Buffer_290790::FUN_00290790(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            FUN_002904d0((int *)(void *)p, (unsigned int)count, (const int *)(void *)arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}

namespace fn_f5d7895e {

// 0x002907f0 FUN_002907f0 (32 B): matches/0x002907f0.cpp
// sym: ?target@fn_f5d7895e@@YIXPAUObj_2907f0@1@@Z
void __fastcall target(Obj_2907f0* self) {
    if (self->a) {
        FUN_00290500((void *)(hulk_uintptr)(int)(self->a), (void *)(hulk_uintptr)(int)(self->b));
        Fng_0008d340(self->a);
    }
}


// 0x00290810 FUN_00290810 (75 B): matches/0x00290810.cpp
// sym: _FUN_00290810
extern "C" void * __cdecl FUN_00290810(void * p, int count, void * arg) {
    if (count != 0) {
        Item_290810* q = ((Item_290810 *)p);
        int n = count;
        do {
            if (q != 0) {
                q->Init_0027af00();
                q->field = 0;
                q->Configure_0027af70(((Item_290810 *)arg));
                ((owners::Obj_28fe80 *)q)->FUN_0028fe80((const char *)(hulk_uintptr)(int)(((Item_290810 *)arg)->field));
            }
            q = (Item_290810*)((char*)q + 0x10);
            n--;
        } while (n != 0);
        return (Item_290810 *)q;
    }
    return (Item_290810 *)((Item_290810 *)p);
}

} // namespace fn_f5d7895e

// 0x002908f0 pure3d::prop::StateData::vfunc_2 (30 B): matches/0x002908f0.cpp
// sym: ??_GStateData@prop@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::prop::StateData::~StateData() {}


// 0x00290910 FUN_00290910 (176 B): equivalent/0x00290910.cpp [wrapped: conflict: pure3d::prop::StatePropData]
// sym: ??1StatePropData@prop@pure3d@fn_00290910@@UAE@XZ @42919a2991d8 @w6d4217936901
namespace fn_00290910 {
// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 16/16)
// FUN_00290910 @ 0x00290910
struct Ref_290910 { virtual void slot0(); virtual void release(); };
extern "C++" __declspec(nothrow) void __cdecl FUN_00290500(void *, void *);
void __cdecl FUN_0008d340(void*);
struct Entity_290910 { virtual void slot0_00038290(); char pad[12]; void FUN_0027afd0(); };
namespace pure3d { namespace prop {
struct StatePropData : Entity_290910 {
 Ref_290910* a; Ref_290910* b; Ref_290910* c; Ref_290910** begin; Ref_290910** end; Ref_290910** capacity; void* data; unsigned count;
 virtual ~StatePropData();
};
}}
pure3d::prop::StatePropData::~StatePropData() {
 if(a) { a->release(); a=0; }
 if(b) { b->release(); b=0; }
 if(c) { c->release(); c=0; }
 for(unsigned i=0; i<(unsigned)(end-begin); ++i) {
  Ref_290910** entry=begin+i;
  if(*entry) { (*entry)->release(); *entry=0; }
 }
 if(data) { FUN_00290500(data,(void *)(hulk_uintptr)(unsigned)count); FUN_0008d340(data); }
 if(begin) FUN_0008d340(begin);
 FUN_0027afd0();
}
} // namespace fn_00290910


// 0x002909c0 FUN_002909c0 (93 B): equivalent/0x002909c0.cpp
// sym: ?FUN_002909c0@Buffer_2909c0@owners@@QAE_NII@Z @2a59f40fe8ec @w392a9e2e36cf
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002909c0 @ 0x002909c0
bool owners::Buffer_2909c0::FUN_002909c0(unsigned count, hulk_uintptr value) {
    if (begin) return false;
    if (count) {
        void* data = FUN_0008d6d0(count * 16);
        begin = data;
        if (data) {
            end = (char*)data + count * 16;
            FUN_00290810(data, (unsigned)count, (void *)(hulk_uintptr)(unsigned)((unsigned)value));
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}


// 0x00290ab0 pure3d::prop::StatePropData::vfunc_2 (30 B): matches/0x00290ab0.cpp
// sym: ??_GStatePropData@prop@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::prop::StatePropData::~StatePropData() {}

namespace fn_f5d7895e {

// 0x00290ad0 FUN_00290ad0 (87 B): matches/0x00290ad0.cpp
// sym: ?Run@Obj_290ad0@fn_f5d7895e@@QAE_NH@Z
bool Obj_290ad0::Run(int arg) {
    Temp_290ad0 t;
    t.Init_0027af00();
    t.value = 0;
    bool r = ((owners::Buffer_2909c0 *)this)->FUN_002909c0((unsigned)arg, (hulk_uintptr)(Temp_290ad0 *)(&t));
    if (t.value) {
        Free_0008d340((void*)t.value);
        t.value = 0;
    }
    t.Fin_0027af50();
    return r;
}

} // namespace fn_f5d7895e

// 0x00290b30 FUN_00290b30 (185 B): equivalent/0x00290b30.cpp [wrapped: conflict: pure3d::prop::StatePropData]
// sym: ??0StatePropData@prop@pure3d@fn_00290b30@@QAE@PAURef_290b30@3@00II@Z @84e24feec56b @w0d2ebf70234d
namespace fn_00290b30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00290b30 @ 0x00290b30
struct Ref_290b30 { virtual void AddRef(); virtual void Release(); char pad[4]; unsigned a,b; };
struct Pair_290b30 { unsigned a,b; void FUN_0027af60(unsigned,unsigned); };
struct Storage_290b30 { unsigned a,b,c; void FUN_00290790(unsigned, unsigned*); };
struct Tail_290b30 { unsigned a,b; void FUN_00290ad0(unsigned); };
struct FUN_0027b070 { virtual void slot0(); char pad[4]; FUN_0027b070(); };
namespace pure3d { namespace prop {
struct StatePropData : FUN_0027b070 {
 virtual void slot0();
 Pair_290b30 data;
 Ref_290b30 *first,*second,*third;
 Storage_290b30 storage;
 Tail_290b30 tail;
 StatePropData(Ref_290b30*,Ref_290b30*,Ref_290b30*,hulk_uintptr,hulk_uintptr);
};
StatePropData::StatePropData(Ref_290b30* p,Ref_290b30* q,Ref_290b30* r,hulk_uintptr x,hulk_uintptr y) {
 first=0; second=0; third=0; storage.a=0; storage.b=0; tail.a=0; tail.b=0;
 data.FUN_0027af60(p->a,p->b);
 p->AddRef();
 if(first) first->Release();
 first=p;
 if(q) q->AddRef();
 if(second) second->Release();
 second=q;
 if(r) r->AddRef();
 if(third) third->Release();
 third=r;
 unsigned zero=0;
 storage.FUN_00290790(x,&zero);
 tail.FUN_00290ad0(y);
}
} }
} // namespace fn_00290b30

