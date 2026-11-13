// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00277110..0x00277ca0 (kind game, layer engine, confidence high), dominant class core::CementLibrary
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"
#include "gen/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6ff0ab7 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6ff0ab7 {} using namespace fn_f6ff0ab7;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f6ff0ab7 {
bool __cdecl FUN_002674f0(const char*, const char*);
int __cdecl FUN_0026fcf0(void **result, const char *path, int heap, char *details);
extern "C" void __cdecl FUN_00278a40(void **out, const char *name, int heap);
struct A_277380 {
    virtual void a();
};
struct Inner_277380 {
    virtual void f();
};
struct Obj_277380 : A_277380, Inner_277380 {};
struct CementLibrary {
    char pad[0xc];
    Obj_277380* p;
    void vfunc_0_adj10();
};
class V {
  public:
    virtual void f0();
    virtual void f1();
};
class Pad_277390 {
  public:
    virtual void z();
};
class Q_277390 : public Pad_277390, public V {};
class P_277390 {
  public:
    virtual void x0();
    virtual void x1();
    char pad[8];
    Q_277390* p;
};
class C_2773a0 {
    char pad[0x20];

  public:
    unsigned int value;
};
class Foo_2773f0 {
  public:
    virtual void f();
};
class Callback_277410 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int);
};
class Obj_277410 {
  public:
    char pad[0x20];
    int value;
    char pad2[0x48];
    Callback_277410* cb;
    int arg;
    void Set(int);
};
struct Dispatch_277500 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h(void*, int, int, int, int, int);
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
};
struct Node {
  public:
    virtual void _m_vf0();
    virtual void f1();
    char _m_pad_4[0x60];
    Node* next;
    int index;
};
class Owner_277540 {
  public:
    Node* head[2];
};
class Queue_277570 {
  public:
    void Push(Node* n);
    Node* heads[4];
};
struct Entry {
    char pad[0x64];
    Entry* next;
    int bucket;
};
struct Table {
    Entry* head[2];
    Entry* tail[2];
    void FUN_002775b0(Entry* entry);
};
class Obj {
    char pad[0x10];
    Node* node;

  public:
    Node* Advance();
};
extern "C" int __cdecl FUN_00270ba0();
extern "C" int __cdecl FUN_0026fd50(int, int);
extern int __cdecl f66eb0_00266eb0(int, int, int);
struct X_277670 {
    char pad[0x14];
    int a;
    int b;
    int refs;
    int arg;
    void f();
};
extern void __cdecl helper_00266f20(int, int);
class Inner_2777b0 {
  public:
    void call_0026f160();
};
class A_2777e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
};
class B_2777e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
    virtual void f3();
};
class C_2777e0 : public A_2777e0, public B_2777e0 {
  public:
    virtual void f2(int);
    C_2777e0();
};
struct Callback_277810 { virtual void s0(); virtual void release(); virtual void s2(); virtual void complete(unsigned); };
struct File { virtual void s0(); virtual void s1(); virtual void s2(); virtual void read(void*,unsigned,int); virtual void s4(); virtual void seek(unsigned); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void* get(); virtual void s17(); virtual void async(void*,int); virtual void s19(); virtual void s20(); virtual void s21(); virtual unsigned status(); virtual bool ready(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void mode(int); };
struct Result_277810 {  };
struct Owner_277810 { Result_277810* FUN_00272bc0(); void FUN_00272ba0(void*); };
void* __cdecl FUN_00266eb0(unsigned,unsigned,unsigned);
struct Whole { void FUN_00277410(int); };
struct LibraryBase { char pad0[8]; unsigned allocator; char padC[8]; Owner_277810* owner; File* file; unsigned state; unsigned char header[60]; void* buffer; char pad60[8]; Callback_277810* callback; unsigned context; void target(unsigned); };
struct Entry_2779b0 { unsigned int unused, value4, value8, valueC, value10; };
Entry_2779b0* __cdecl FUN_00277310(void* table, unsigned int stride, unsigned int count, unsigned int key);
struct Info_2779b0 { char pad[0x14]; unsigned int value14, value18; };
struct Provider_2779b0 { Info_2779b0* FUN_00272bc0(); };
struct Output_2779b0 { void FUN_00277c40(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); };
struct CementLibrary_2779b0 {
 char pad0[0x18]; Provider_2779b0* provider; unsigned int value1C; unsigned int state;
 char pad24[0x21]; unsigned char mode; char pad46[0x12]; unsigned int value58; void* table; unsigned int count;
 bool FUN_002779b0(unsigned int key, Output_2779b0* output);
};
class Thing_277a40 : public CoreDriveLibraryList {
  public:
    Thing_277a40();
};
extern "C" int* FUN_002705f0();
typedef unsigned char u8_277b10;
extern "C" void __cdecl FUN_00266f00(int, void*);
class CementLibrary_277b10 {
  public:
    void cleanup_002776c0();
    virtual void f0();
    virtual void f1();
    virtual CementLibrary_277b10* f2(u8_277b10);
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
extern "C" unsigned int __cdecl FUN_002698b0(char*);
struct CementLibrary_nv_277b40 {
    unsigned int Fnf_002779b0(unsigned int, unsigned int);
};
struct C_277b40 {
    unsigned int f(char*, unsigned int);
};
struct File_nv_277b70 {
    core::File* FUN_002764d0(unsigned int a,unsigned int b,int c,int d,int e,int f,int g,int h,int i);
};
struct CementLibrary_nv_277b70 {
    core::CementLibrary* FUN_00277a70(unsigned int a,core::File* b,unsigned int c);
};
extern "C" core::File* __cdecl FUN_00275d50(unsigned int size);
extern "C" core::CementLibrary* __cdecl FUN_00266e00(unsigned int a,hulk_uintptr size);
typedef CoreFileView X_277c00;
struct View_277c30 {
    void FUN_00277c30();
};
struct Resource_277c40 {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual unsigned int slot16();
};
struct State_277c40 : CoreFileView {
 void FUN_00277c40(Resource_277c40*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

} // namespace fn_f6ff0ab7

// 0x00277110 FUN_00277110 (114 B): matches/0x00277110.cpp [wrapped: conflict: core::IMutable; core::InstanceDrive]
// sym: ??0InstanceDrive@core@fn_00277110@@QAE@PAUSource_277110@2@PAUContext@2@@Z
namespace fn_00277110 {
namespace core {
struct IMutable {
    virtual void m() HULK_PURE64;
};
struct InstanceDrive;
} // namespace core
struct Source_277110 {
    virtual void first();
    void FUN_00272b60(void*, void*, int);
};
struct Context {
    void FUN_002705f0();
};
struct DriveOpenRequest_277110 {
    void* FUN_002756c0(core::InstanceDrive*);
};
void* __cdecl FUN_00273560(unsigned int);
namespace core {
struct Primary_277110 {
    virtual void p();
};
struct InstanceDrive : Primary_277110, IMutable {
    int refs;
    Source_277110* source;
    Context* context;
    int state;
    char pad[8];
    char flag;
    virtual void p();
    virtual void m();
    InstanceDrive(Source_277110*, Context*);
};
InstanceDrive::InstanceDrive(Source_277110* s, Context* c) {
    refs = 1;
    source = s;
    context = c;
    state = 0;
    flag = 0;
    c->FUN_002705f0();
    source->first();
    DriveOpenRequest_277110* h = (DriveOpenRequest_277110*)FUN_00273560(12);
    void* result = h ? h->FUN_002756c0(this) : 0;
    source->FUN_00272b60(result, context, 0);
}
} // namespace core
} // namespace fn_00277110

namespace fn_f6ff0ab7 {

// 0x00277190 FUN_00277190 (24 B): matches/0x00277190.cpp
// sym: _FUN_00277190
// data: gDrive = DAT_0042b50c ("D:", two bytes), its terminator the next item, s_empty_0042b50e (the original reads it
// by that item's address: as DAT_0042b50c + 2 the native builds read whatever their linker put after the 2-byte item)
extern "C" void FUN_00277190(char* p) {
    unsigned short v = *(volatile unsigned short*)((volatile char*)&DAT_0042b50c);
    *(unsigned short*)p = v;
    p[2] = *(volatile const char*)DAT_0042b50e;
}


// 0x002771b0 FUN_002771b0 (163 B): equivalent/0x002771b0.cpp
// sym: _FUN_002771b0 @30f13ce175d7 @we8646a395412
// STATUS: equivalent (tools/equiv.py level 3: 20055 inputs, branch coverage 20/20)
// FUN_002771b0 @ 0x002771b0
extern "C" bool __cdecl FUN_002771b0(const char* path)
{
    const char* prefixes[5] = {"D:", "T:", "Z:", "W:", "U:"};
    for (int i = 0; i < 5; ++i) {
        int j;
        for (j = 0; j < 3; ++j) {
            if (path[j] != prefixes[i][j]) break;
        }
        if (j == 3) return true;
    }
    if (!FUN_002674f0(path, "MEMCARD??:")) return false;
    int number = (signed char)path[7] - '1';
    int letter = (signed char)path[8] - 'A';
    return number >= 0 && number <= 3 && letter >= 0 && letter <= 1;
}


// 0x00277260 FUN_00277260 (111 B): equivalent/0x00277260.cpp
// sym: _FUN_00277260 @03b2881a60f8 @w90e3f49b52c0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00277260 @ 0x00277260
// FUN_00277260 @ 0x00277260
// equiv-conv: FUN_0026fcf0 stack stack stack stack
extern "C" void __cdecl FUN_00277260(void **arg1, const char *path, unsigned int arg3, char *arg4)
{
    const char *drives[4] = { "D:", "T:", "Z:", "W:" };
    for (int d = 0; d < 4; ++d) {
        int i;
        for (i = 0; i < 3 && path[i] == drives[d][i]; ++i) {}
        if (i == 3) { FUN_0026fcf0(arg1, path, (int)arg3, arg4); return; }
    }
    FUN_00278a40(arg1, path, (int)arg3);
}


// 0x00277310 FUN_00277310 (98 B): equivalent/0x00277310.cpp
// sym: ?FUN_00277310@fn_f6ff0ab7@@YAPAXIIPBXI@Z @da551913162e @we515ae39d878
// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 14/14)
// FUN_00277310 @ 0x00277310
// equiv-conv: FUN_00277310 eax edi stack stack
void* __cdecl FUN_00277310(unsigned int upper, unsigned int stride, const void* base, unsigned int key)
{
    if (upper == 0) return 0;
    unsigned int lower = 0;
    do {
        unsigned int middle = (upper >> 1) + (lower >> 1);
        if ((lower & 1) && (upper & 1)) ++middle;
        const char* entry = static_cast<const char*>(base) + middle * stride;
        unsigned int value = *reinterpret_cast<const unsigned int*>(entry);
        if (value == key) return const_cast<char*>(entry);
        if (value < key) lower = middle + 1;
        else {
            if (middle == 0) return 0;
            upper = middle - 1;
        }
    } while (lower <= upper);
    return 0;
}


// 0x00277380 core::CementLibrary::vfunc_0_adj10 (11 B): matches/0x00277380.cpp
// sym: ?vfunc_0_adj10@CementLibrary@fn_f6ff0ab7@@QAEXXZ
void CementLibrary::vfunc_0_adj10() {
    p->f();
}


// 0x00277390 core::CementLibrary::vfunc_1_adj10 (12 B): matches/0x00277390.cpp
// sym: ?x1@P_277390@fn_f6ff0ab7@@UAEXXZ
void P_277390::x1() {
    p->f1();
}


// 0x002773a0 core::CementLibrary::vfunc_3 (4 B): matches/0x002773a0.cpp
// sym: ?target@fn_f6ff0ab7@@YIIPAVC_2773a0@1@@Z
// Same code shape as 0x00086280 (propagated; names are from that function)
unsigned int __fastcall target(C_2773a0* self) {
    return self->value;
}

} // namespace fn_f6ff0ab7

// 0x002773b0 core::CementLibrary::vfunc_4 (40 B): matches/0x002773b0.cpp
// sym: ?vfunc_4@CementLibrary@core@@UAEXXZ
void core::CementLibrary::vfunc_4() {
    while (this->f_20 == 0) {
        thunk_FUN_00270a50();
        FUN_0026d6d0(0);
    }
}


// 0x002773e0 core::CementLibrary::vfunc_6 (12 B): matches/0x002773e0.cpp
// sym: ?vfunc_6@CementLibrary@core@@UAE_NXZ
bool core::CementLibrary::vfunc_6() {
    return this->f_20 == 1;
}


// 0x002773f0 core::CementLibrary::vfunc_5 (23 B): matches/0x002773f0.cpp
// sym: ?vfunc_5@CementLibrary@core@@UAEXPAXH@Z
void core::CementLibrary::vfunc_5(void* __p0, int value) { Foo_2773f0 * object = (Foo_2773f0 *)__p0;

    (*(Foo_2773f0 * *)&this->f_6c) = object;
    this->f_70 = value;
    object->f();
}

namespace fn_f6ff0ab7 {

// 0x00277410 FUN_00277410 (52 B): matches/0x00277410.cpp
// sym: ?Set@Obj_277410@fn_f6ff0ab7@@QAEXH@Z
void Obj_277410::Set(int x) {
    value = x;
    if (cb) {
        cb->f3(arg);
        cb->f1();
        cb = 0;
        arg = 0;
    }
}

} // namespace fn_f6ff0ab7

// 0x00277460 core::CementLibrary::vfunc_7 (150 B): equivalent/0x00277460.cpp [wrapped: conflict: core::CementLibrary]
// sym: ?vfunc_7@CementLibrary@core@fn_00277460@@UAEXPAPAUFile_277460@3@IIIII@Z @dda7a46ae8c1 @wa35d2687c369
namespace fn_00277460 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::CementLibrary::vfunc_7 @ 0x00277460
typedef unsigned int U_277460;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char*,const char*,...);
#endif

namespace core { struct CementLibrary; }
struct Manager_277460 { void FUN_00272b60(void*,U_277460,U_277460); };
struct File_277460 { File_277460* FUN_002764d0(Manager_277460*,const char*,U_277460,U_277460,U_277460,U_277460,U_277460,U_277460,U_277460); };
struct Request { Request* FUN_00274fc0(File_277460*,U_277460,core::CementLibrary*); };
extern File_277460* __cdecl FUN_00275d50(U_277460);
extern Request* __cdecl FUN_00273560(U_277460);
namespace core {
struct CementLibrary {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 virtual void vfunc_7(File_277460**,U_277460,U_277460,U_277460,U_277460,U_277460);
 virtual void vfunc_8();
 char pad[0x14]; Manager_277460* manager;
};
void CementLibrary::vfunc_7(File_277460** output,U_277460 id,U_277460 p4,U_277460 p5,U_277460 p6,U_277460 p7) {
 char name[16]; sprintf(name,"0x%X",id);
 File_277460* storage=FUN_00275d50(0x168);
 File_277460* result=0;
 if(storage) result=storage->FUN_002764d0(manager,name,0,0,p4,p5,p6,p7,0);
 *output=result;
 Request* allocation=FUN_00273560(0x14);
 Request* request=0;
 if(allocation) request=allocation->FUN_00274fc0(result,id,this);
 manager->FUN_00272b60(request,p4,0);
}
}
} // namespace fn_00277460


// 0x00277500 core::CementLibrary::vfunc_8 (51 B): matches/0x00277500.cpp
// sym: ?vfunc_8@CementLibrary@core@@UAEXPAXHHHHH@Z
void core::CementLibrary::vfunc_8(void* __p0, int a, int b, int c, int d, int e) { int ** p = (int **)__p0;

    Dispatch_277500* dsp = (Dispatch_277500*)this;
    dsp->h(p, a, b, c, d, e);
    Dispatch_277500* v = (Dispatch_277500*)*p;
    if (v)
        v->v();
}

namespace fn_f6ff0ab7 {

// 0x00277540 FUN_00277540 (40 B): matches/0x00277540.cpp
// sym: ?FUN_00277540@fn_f6ff0ab7@@YIXPAVOwner_277540@1@@Z
void __fastcall FUN_00277540(Owner_277540* self) {
    for (unsigned int i = 0; i < 2; ++i) {
        Node* p = self->head[i];
        while (p) {
            Node* c = p;
            p = c->next;
            c->f1();
        }
    }
}


// 0x00277570 FUN_00277570 (54 B): matches/0x00277570.cpp
// sym: ?Push@Queue_277570@fn_f6ff0ab7@@QAEXPAUNode@2@@Z
void Queue_277570::Push(Node* n) {
    int i = n->index;
    if (heads[i] == 0) {
        heads[i] = n;
        n->next = 0;
        heads[i + 2] = n;
    } else {
        Node* tail = heads[i + 2];
        tail->next = n;
        n->next = 0;
        heads[i + 2] = n;
    }
}


// 0x002775b0 FUN_002775b0 (62 B): matches/0x002775b0.cpp
// sym: ?FUN_002775b0@Table@fn_f6ff0ab7@@QAEXPAUEntry@2@@Z
void Table::FUN_002775b0(Entry* entry) {
    int bucket = entry->bucket;
    Entry* volatile* link = &head[bucket];
    Entry* previous = 0;
    if (*link) {
        do {
            Entry* cur = *link;
            if (cur == entry) {
                *link = (*link)->next;
                break;
            }
            link = &cur->next;
            previous = cur;
        } while (*link);
    }
    if (!*link)
        tail[bucket] = previous;
}

} // namespace fn_f6ff0ab7

// 0x002775f0 FUN_002775f0 (13 B): matches/0x002775f0.cpp
// sym: ?FUN_002775f0@X_2775f0@owners@@QAEXH@Z
void owners::X_2775f0::FUN_002775f0(int i) {
    value = data[i];
}

namespace fn_f6ff0ab7 {

// 0x00277600 FUN_00277600 (14 B): matches/0x00277600.cpp
// sym: ?Advance@Obj@fn_f6ff0ab7@@QAEPAUNode@2@XZ
Node* Obj::Advance() {
    Node* p = node;
    if (p)
        node = p->next;
    return p;
}

} // namespace fn_f6ff0ab7

// 0x00277630 FUN_00277630 (64 B): matches/0x00277630.cpp
// sym: ?FUN_00277630@Obj_277630@owners@@QAEXHHH@Z
void owners::Obj_277630::FUN_00277630(int a, hulk_intptr b, int c) {
    if (m1c == 0) {
        m20 = a;
        int x = FUN_0026fd50(FUN_00270ba0(), c);
        m18 = x;
        m14 = f66eb0_00266eb0(m20, x, ((int)b));
    }
    ++m1c;
}

namespace fn_f6ff0ab7 {

// 0x00277670 FUN_00277670 (38 B): matches/0x00277670.cpp
// sym: ?f@X_277670@fn_f6ff0ab7@@QAEXXZ
void X_277670::f() {
    if (refs == 1) {
        helper_00266f20(arg, a);
        a = 0;
        b = 0;
    }
    --refs;
}

} // namespace fn_f6ff0ab7

// 0x002776c0 FUN_002776c0 (193 B): matches/0x002776c0.cpp [wrapped: conflict: core::BaseObject; core::CementLibrary; core::IRefCount; core::SafeRefCount]
// sym: ??1CementLibrary@core@fn_002776c0@@QAE@XZ
namespace fn_002776c0 {

namespace core {
struct IRefCount {
    virtual void slot0() HULK_PURE64;
};
struct OtherRef : IRefCount {};
struct BaseObject {
    virtual void slot0();
    unsigned allocator;
};
struct SafeRefCount {
    virtual void slot0() HULK_PURE64;
    unsigned count;
};
} // namespace core
struct Resource_2776c0 {
    virtual void v0();
    virtual void release();
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void reset();
};
struct Entry_2776c0 {
    char pad[20];
    unsigned data;
    unsigned size;
    unsigned refs;
    unsigned allocator;
};
namespace core {
struct CementLibrary;
}
struct Manager_2776c0 : Resource_2776c0 {
    Entry_2776c0* FUN_00272bc0();
    void FUN_00272bb0(core::CementLibrary*);
};
void __cdecl FUN_00266f20(unsigned, unsigned);
namespace core {
struct CementLibrary : IRefCount, OtherRef, BaseObject, SafeRefCount {
    Manager_2776c0* manager;
    Resource_2776c0* resource;
    unsigned mode;
    char pad24[52];
    unsigned total;
    unsigned unknown;
    unsigned buffer;
    virtual void slot0();
    ~CementLibrary();
};
CementLibrary::~CementLibrary() {
    if (mode == 0)
        resource->reset();
    else if (mode == 1) {
        if (total > 0) {
            Entry_2776c0* e = manager->FUN_00272bc0();
            if (e->refs == 1) {
                FUN_00266f20(e->allocator, e->data);
                e->data = 0;
                e->size = 0;
            }
            --e->refs;
        }
        manager->FUN_00272bb0(this);
    }
    resource->release();
    resource = 0;
    manager->release();
    manager = 0;
    if (buffer)
        FUN_00266f20(allocator, buffer);
    static_cast<SafeRefCount*>(this)->SafeRefCount::SafeRefCount();
    (*(unsigned*)&DAT_004cdbb0) = allocator;
    static_cast<BaseObject*>(this)->BaseObject::BaseObject();
    static_cast<OtherRef*>(this)->IRefCount::IRefCount();
    static_cast<IRefCount*>(this)->IRefCount::IRefCount();
}
} // namespace core
} // namespace fn_002776c0


// 0x00277790 core::CementLibrary::vfunc_0 (26 B): matches/0x00277790.cpp
// sym: ?vfunc_0@CementLibrary@core@@UAEXXZ
void core::CementLibrary::vfunc_0() {
    struct Sub {
        virtual void first();
        virtual void second();
        int count;
    };
    Sub* p = (Sub*)((char*)this + 0x10);
    p->first();
    ++p->count;
    p->second();
}


// 0x002777b0 core::CementLibrary::vfunc_1 (8 B): matches/0x002777b0.cpp
// sym: ?vfunc_1@CementLibrary@core@@UAEXXZ
// Same code shape as 0x002226e0 (propagated; names are from that function)
void core::CementLibrary::vfunc_1() {
    ((Inner_2777b0*)((char*)this + 0x10))->call_0026f160();
}


// 0x002777c0 core::CementLibrary::vfunc_0_adj4 (8 B): matches/0x002777c0.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ?vfunc_0@CementLibrary@core@fn_002777c0@@W3AEXXZ
namespace fn_002777c0 {
namespace core {
class ICementLibrary {
  public:
    virtual void vfunc_0();
};
class IRefCount {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};
class CementLibrary : public ICementLibrary, public IRefCount {
  public:
    virtual void vfunc_0();
};
CementLibrary g;
} // namespace core
} // namespace fn_002777c0


// 0x002777d0 core::CementLibrary::vfunc_1_adj4 (8 B): matches/0x002777d0.cpp [wrapped: conflict: core::CementLibrary; core::ICementLibrary; core::IRefCount]
// sym: ?a@CementLibrary@core@fn_002777d0@@W3AEXXZ
namespace fn_002777d0 {
namespace core {
class ICementLibrary {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
class IRefCount {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
extern void work(void*);
class __declspec(dllexport) CementLibrary : public ICementLibrary, public IRefCount {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
void CementLibrary::b() {
    work(this);
}
} // namespace core
} // namespace fn_002777d0

namespace fn_f6ff0ab7 {

// 0x002777e0 core::CementLibrary::vfunc_2_adj4 (8 B): matches/0x002777e0.cpp
// sym: ?f2@C_2777e0@fn_f6ff0ab7@@W3AEXH@Z
C_2777e0::C_2777e0() {}

} // namespace fn_f6ff0ab7

// 0x002777f0 core::CementLibrary::vfunc_0_adj8 (8 B): matches/0x002777f0.cpp [wrapped: conflict: CementLibrary]
// sym: ?v2@CementLibrary@fn_002777f0@@W7AEXXZ
namespace fn_002777f0 {
class A_2777f0 {
  public:
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2();
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    virtual void v7() {}
    virtual void v8() {}
    int pad;
};
class B_2777f0 {
  public:
    virtual void v2();
};
class CementLibrary : public A_2777f0, public B_2777f0 {
  public:
    virtual void v2();
};
void CementLibrary::v2() {}
CementLibrary gObj_2777f0;
} // namespace fn_002777f0


// 0x00277800 core::CementLibrary::vfunc_2_adj10 (8 B): matches/0x00277800.cpp [wrapped: conflict: core::CementLibrary]
// sym: ?a@CementLibrary@core@fn_00277800@@WBA@AEXH@Z
namespace fn_00277800 {
namespace core {
struct I0 {
    virtual void a(int);
};
struct I1 {
    virtual void a(int);
};
struct Iextra {
    virtual void a(int);
    char pad[4];
};
struct I2 {
    virtual void a(int);
    virtual void b();
    virtual void c(unsigned);
};
struct __declspec(dllexport) CementLibrary : I0, I1, Iextra, I2 {
    void a(int);
    void b();
    void c(unsigned);
};
void CementLibrary::c(unsigned flags) {
    a(0);
}
} // namespace core
} // namespace fn_00277800

namespace fn_f6ff0ab7 {

// 0x00277810 core::CementLibrary::vfunc_3_adj4 (412 B): equivalent/0x00277810.cpp
// sym: ?target@LibraryBase@fn_f6ff0ab7@@QAEXI@Z @c5c2e7f85df1 @wcd648e7d85b8
// STATUS: equivalent (tools/equiv.py level 3: 3074 inputs, branch coverage 29/30; --wine 674 inputs)
// core::CementLibrary::vfunc_3_adj4 @ 0x00277810
void LibraryBase::target(unsigned step) {
 if(state==1) { state=2; if(callback) {callback->complete(context); callback->release(); callback=0; context=0;} return; }
 Whole* whole=(Whole*)((char*)this-4); void* cb=whole ? this : 0;
 if(step==0) { if(!file->ready()) {whole->FUN_00277410(2); return;} file->mode(1); file->seek(0); file->read(header,60,1); file->async(cb,1); }
 else if(step==1) { if(file->status()!=0) return; const char* magic="ATG CORE CEMENT LIBRARY"; bool valid=true; for(unsigned i=0;i<24;++i) if(header[i]!=(unsigned char)magic[i]) {valid=false; break;} if(header[32]!=2 || header[35]==0 || header[33]>=2 || header[34]!=0) valid=false;
 if(!valid) {whole->FUN_00277410(2); return;} buffer=FUN_00266eb0(allocator,*(unsigned*)(header+40),16); file->seek(*(unsigned*)(header+36)); file->read(buffer,*(unsigned*)(header+40),1); file->async(cb,2);
 } else if(step==2) { if(file->status()!=0) {whole->FUN_00277410(2); return;} file->mode(0); if(*(unsigned*)(header+52)>0) {unsigned a=allocator; void* gp=file->get(); ((owners::Obj_277630 *)(owner->FUN_00272bc0()))->FUN_00277630((int)a, (hulk_intptr)gp, 16);} owner->FUN_00272ba0(whole); whole->FUN_00277410(1); }
}


// 0x002779b0 FUN_002779b0 (139 B): equivalent/0x002779b0.cpp
// sym: ?FUN_002779b0@CementLibrary_2779b0@fn_f6ff0ab7@@QAE_NIPAUOutput_2779b0@2@@Z @f48613485a31 @w074dfc416474
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 8/8)
// FUN_002779b0 @ 0x002779b0
// equiv-conv: FUN_00277310 eax edi stack stack
bool CementLibrary_2779b0::FUN_002779b0(unsigned int key, Output_2779b0* output) {
 if (state != 1) return false;
 unsigned int stride = mode ? 12 : 20;
 Entry_2779b0* entry = FUN_00277310(table, stride, count, key);
 if (!entry) return false;
 unsigned int extra = 0;
 unsigned int selected = entry->value8;
 if (!mode) { extra = entry->value10; selected = entry->valueC; }
 Info_2779b0* info = provider->FUN_00272bc0();
 output->FUN_00277c40(value1C, entry->value4, selected, entry->value8, extra, info->value14, info->value18, value58);
 return true;
}


// 0x00277a40 FUN_00277a40 (42 B): matches/0x00277a40.cpp
// sym: ??0Thing_277a40@fn_f6ff0ab7@@QAE@XZ
// core::Drive's library list (records.h CoreDriveLibraryList), constructed in place by core::Drive's constructor
Thing_277a40::Thing_277a40() {
    cursor = 0;
    buffer = 0;
    size = 0;
    refs = 0;
    heap = 0;
    FUN_002705f0();
    heads[0] = 0;
    tails[0] = 0;
    heads[1] = 0;
    tails[1] = 0;
}

} // namespace fn_f6ff0ab7

// 0x00277a70 FUN_00277a70 (156 B): equivalent/0x00277a70.cpp [wrapped: conflict: FUN_002705f0; core::CementLibrary; core::ICementLibrary; core::IFileCompletionCallback (+2)]
// sym: ?FUN_00277a70@CementLibrary@core@fn_00277a70@@QAEPAU123@PAUResource_277a70@23@0I@Z @30c010adf921 @wc9048ed00e47
namespace fn_00277a70 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00277a70 @ 0x00277a70

typedef unsigned int uint_277a70;
void FUN_002705f0();
namespace core {
struct ICementLibrary { virtual void slot0() HULK_PURE64; };
struct IFileCompletionCallback { virtual void slot0() HULK_PURE64; };
struct Object { virtual void slot0(); uint_277a70 tag; };
struct SafeRefCount { virtual void slot0() HULK_PURE64; uint_277a70 refs; };
struct Resource_277a70 { virtual void slot0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(IFileCompletionCallback*,uint_277a70); };
struct CementLibrary : ICementLibrary, IFileCompletionCallback, Object, SafeRefCount {
virtual void slot0();
Resource_277a70 *a,*b; uint_277a70 zero20; char pad[60]; uint_277a70 x60,x64,x68,x6c,x70;
CementLibrary* FUN_00277a70(Resource_277a70*,Resource_277a70*,uint_277a70);
};
CementLibrary* CementLibrary::FUN_00277a70(Resource_277a70* aa,Resource_277a70* bb,uint_277a70 n) { this->ICementLibrary::ICementLibrary(); this->IFileCompletionCallback::IFileCompletionCallback(); this->Object::Object(); tag=(*(uint_277a70*)&DAT_004cdbb0); FUN_002705f0(); this->SafeRefCount::SafeRefCount(); refs=1; this->CementLibrary::CementLibrary(); a=aa;b=bb;zero20=0;x60=0;x64=0;x68=n;x6c=0;x70=0;FUN_002705f0();a->slot0();b->slot0();b->s18(this,0); return this; }
}
} // namespace fn_00277a70

namespace fn_f6ff0ab7 {

// 0x00277b10 core::CementLibrary::vfunc_2 (36 B): matches/0x00277b10.cpp
// sym: ?f2@CementLibrary_277b10@fn_f6ff0ab7@@UAEPAV12@E@Z
// Same code shape as 0x00269560 (propagated; names are from that function)
// data: globalValue = DAT_004cdbb0
CementLibrary_277b10* CementLibrary_277b10::f2(u8_277b10 flag) {
    cleanup_002776c0();
    if (flag & 1)
        FUN_00266f00(DAT_004cdbb0, this);
    return this;
}


// 0x00277b40 FUN_00277b40 (39 B): matches/0x00277b40.cpp
// sym: ?f@C_277b40@fn_f6ff0ab7@@QAEIPADI@Z
unsigned int C_277b40::f(char* path, unsigned int arg) {
    if (*path == '\\')
        ++path;
    unsigned int x = FUN_002698b0(path);
    return ((CementLibrary_nv_277b40*)(((core::CementLibrary*)this)))->Fnf_002779b0(x, arg);
}


// 0x00277b70 FUN_00277b70 (130 B): equivalent/0x00277b70.cpp
// sym: ?FUN_00277b70@fn_f6ff0ab7@@YAXPAPAVCementLibrary@core@@IIII@Z @51faba7cbb81 @wda1ddce58c1c
// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 4/4)
// FUN_00277b70 @ 0x00277b70
void __cdecl FUN_00277b70(core::CementLibrary** out,hulk_uintptr a,unsigned int b,unsigned int c,unsigned int d) {
 HULK_SIZE32(CoreCementLibrary, 0x74);
 core::File* p=FUN_00275d50(0x168);
 core::File* base=0;
 if(p) base=((File_nv_277b70*)(((core::File*)(p))))->FUN_002764d0(a,b,0,0,1,0,0,0,1);
 (*(unsigned int*)&DAT_004cdbb0)=d;
 core::CementLibrary* mem=FUN_00266e00(d,(hulk_uintptr)sizeof(CoreCementLibrary));
 core::CementLibrary* result=0;
 if(mem) result=((CementLibrary_nv_277b70*)(mem))->FUN_00277a70(a,base,c);
 base->vfunc_1();
 *out=result;
}


// 0x00277c00 FUN_00277c00 (37 B): matches/0x00277c00.cpp
// sym: ?FUN_00277c00@fn_f6ff0ab7@@YIPAUCoreFileView@@PAU2@@Z
// core::File's view of its cement library entry (records.h CoreFileView): cleared
X_277c00* __fastcall FUN_00277c00(X_277c00* p) {
    p->resource = 0;
    p->words[0] = 0;
    p->words[1] = 0;
    p->words[2] = 0;
    p->words[3] = 0;
    p->words[4] = 0;
    p->words[5] = 0;
    p->words[6] = 0;
    p->words[7] = 0;
    p->words[8] = 0;
    p->words[9] = 0;
    return p;
}


// 0x00277c30 FUN_00277c30 (1 B): matches/0x00277c30.cpp
// sym: ?FUN_00277c30@View_277c30@fn_f6ff0ab7@@QAEXXZ
// core::File's view (records.h CoreFileView): its destructor, empty (0x002765d0 calls it on the view)
void View_277c30::FUN_00277c30() {
    return;
}


// 0x00277c40 FUN_00277c40 (84 B): equivalent/0x00277c40.cpp
// sym: ?FUN_00277c40@State_277c40@fn_f6ff0ab7@@QAEXPAUResource_277c40@2@IIIIIII@Z @828e588cb3a9 @wf2283d56492c
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00277c40 @ 0x00277c40
void State_277c40::FUN_00277c40(Resource_277c40* object, unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, unsigned int g) {
 object->slot0();
 words[0] = a;
 words[1] = 0;
 words[3] = 0;
 words[4] = 0;
 words[6] = d;
 resource = object;
 words[2] = b;
 words[5] = c;
 words[7] = object->slot16();
 words[8] = e;
 words[9] = f;
}

} // namespace fn_f6ff0ab7
