// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00272a40..0x00272f00 (kind game, layer engine, confidence high), dominant class core::Drive
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#include "gen/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f59a9783 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f59a9783 {} using namespace fn_f59a9783;
namespace fn_f59a9783 { extern "C" char DAT_0042b85c[], DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f59a9783 {
class Inner_272a40 {
  public:
    virtual void A();
    virtual void B();
};
class Other_272a40 {
  public:
    void FUN_00273120(int);
};
class Drive_272a40 : public CoreDrive {
  public:
    void Target(int);
};
class Inner_272a80 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_272a80 : public CoreDrive {
  public:
    unsigned char target();
};
class Inner_272aa0 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_272aa0 : public CoreDrive {
  public:
    void Run(hulk_intptr);
};
extern "C" void __cdecl FUN_0026d8a0(hulk_uintptr*);
struct Guard_272ae0 {
    virtual void begin();
    virtual void end();
};
struct Provider_272ae0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual unsigned int getSecond();
    virtual unsigned int getFirst();
};
struct Object {
    char reserved[12];
    Guard_272ae0 guard;
    char unused[0x54 - 0x10];
    unsigned char available;
    char padding[3];
    Provider_272ae0 *provider;
    bool FUN_00272ae0(unsigned int *first, unsigned int *second);
};
class X_272b50 : public CoreDrive {
};
class B_272b60 {
  public:
    int FUN_00272fc0(void*, int, char);
};
class A_272b60 : public CoreDrive {
  public:
    int run(void*, int, int);
};
class B_272b70 {
  public:
    void FUN_00273050(int, int);
};
class A_272b70 : public CoreDrive {
  public:
    void run(int, int);
};
class B_272b80 {
  public:
    bool FUN_002730c0();
};
class A_272b80 : public CoreDrive {
  public:
    bool run();
};
struct C_272ba0 {
    void FUN_00277570(hulk_intptr);
};
struct D : CoreDrive {
    void f(hulk_intptr);
};
struct Obj_272bc0 : CoreDrive {
};
class IRefCount_272c10 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
class Object_272c10 {
  public:
    virtual void d();
};
class BaseObject_272c10 {
  public:
    virtual void e();
};
class SafeRefCount_272c10 {
  public:
    virtual void f();
};
class IMutable_272c10 {
  public:
    virtual void g();
};
namespace fight {
class Condition_272c30 {
  public:
    virtual int vfunc_3();
};
}
namespace fight {
class Param_272c30 {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
}
class Drive_272c30 : public ::core::IRefCount, public fight::Condition_272c30, public fight::Param_272c30 {
  public:
    virtual int vfunc_0(int);
};
namespace fight {
class Condition_272c40 {
  public:
    virtual int vfunc_3();
};
}
namespace fight {
class Param_272c40 {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
}
class Drive_272c40 : public ::core::IRefCount, public fight::Condition_272c40, public fight::Param_272c40 {
  public:
    virtual int vfunc_0(int);
};
namespace fight {
class Condition_272c50 {
  public:
    virtual int vfunc_3();
};
}
namespace fight {
class Param_272c50 {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
}
class Drive_272c50 : public ::core::IRefCount, public fight::Condition_272c50, public fight::Param_272c50 {
  public:
    virtual int vfunc_0(int);
};
class Drive {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(int);
    int a;
    int b;
};
class XboxDrive : public Drive, public IBase {
  public:
    XboxDrive() {}
    virtual void v0();
    virtual void v1();
    virtual void v2(int);
};
class IMutable_272ce0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public IMutable_272ce0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
extern "C" void FUN_00266f00(unsigned, void*);
class Part_272d90 {
  public:
    void Fini_00277540() throw();
};
struct Drive_272d90 {
    void* v0;
    void* v4;
    unsigned p8;
    void* vc;
    int pad;
    Part_272d90 part;
    Drive_272d90* Dtor(unsigned char flag) throw();
};
struct Node { virtual void destroy(int); virtual void n1(); virtual void n2(); virtual void n3(); virtual void n4(); virtual void n5(); virtual void n6(); virtual void process(); Node* next; bool FUN_00273680(CoreThread*); };
struct Lock_272df0 { virtual void acquire(); virtual void release(); virtual void x(); };
struct Provider_272df0 { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual unsigned get(unsigned); virtual unsigned convert(unsigned); };
struct Callback_272df0 { virtual unsigned run(unsigned,unsigned); };
typedef unsigned (Callback_272df0::*CallbackMethod)(unsigned,unsigned);
struct CallbackTable { void* run; };
struct DriveSlots_272df0 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual unsigned vfunc_4(unsigned); };
extern "C" CoreThread* __cdecl FUN_0026dbb0();
} // namespace fn_f59a9783
namespace core {
struct Drive_272df0 : CoreDrive { void vfunc_3(); void FUN_00272a40(unsigned); };
}

namespace fn_f59a9783 {

// 0x00272a40 FUN_00272a40 (50 B): matches/0x00272a40.cpp
// sym: ?Target@Drive_272a40@fn_f59a9783@@QAEXH@Z
void Drive_272a40::Target(int arg) {
    ((Inner_272a40*)&vftableMutable)->A();
    active = 0;
    request = 0;
    ((Inner_272a40*)&vftableMutable)->B();
    ((Other_272a40*)driveThread)->FUN_00273120(arg);
}


// 0x00272a80 FUN_00272a80 (31 B): matches/0x00272a80.cpp
// sym: ?target@Obj_272a80@fn_f59a9783@@QAEEXZ
unsigned char Obj_272a80::target() {
    ((Inner_272a80*)&vftableMutable)->A();
    unsigned char v = active;
    ((Inner_272a80*)&vftableMutable)->B();
    return v;
}


// 0x00272aa0 FUN_00272aa0 (64 B): matches/0x00272aa0.cpp
// sym: ?Run@Obj_272aa0@fn_f59a9783@@QAEXH@Z
void Obj_272aa0::Run(hulk_intptr arg) {
    ((Inner_272aa0*)&vftableMutable)->A();
    request = (void*)arg;
    active = 1;
    if (signal != 0) {
        ((Inner_272aa0*)&vftableMutable)->B();
        FUN_0026d8a0(signal);
    } else {
        ((Inner_272aa0*)&vftableMutable)->B();
    }
}


// 0x00272ae0 FUN_00272ae0 (84 B): equivalent/0x00272ae0.cpp
// sym: ?FUN_00272ae0@Object@fn_f59a9783@@QAE_NPAI0@Z @caeedb54f514 @wce41a8582698
// STATUS: equivalent (tools/equiv.py level 3: 20017 inputs, branch coverage 2/2)
// FUN_00272ae0 @ 0x00272ae0
bool Object::FUN_00272ae0(unsigned int *first, unsigned int *second) {
    (&guard)->begin();
    if (available) {
        *first = provider->getFirst();
        *second = provider->getSecond();
        (&guard)->end();
        return true;
    }
    (&guard)->end();
    return false;
}

} // namespace fn_f59a9783

// 0x00272b40 FUN_00272b40 (10 B): matches/0x00272b40.cpp
// sym: ?FUN_00272b40@C_272b40@owners@@QAEXE@Z
void owners::C_272b40::FUN_00272b40(unsigned char x) {
    value = x;
}

namespace fn_f59a9783 {

// 0x00272b50 FUN_00272b50 (4 B): matches/0x00272b50.cpp
// sym: ?target@fn_f59a9783@@YIEPAVX_272b50@1@PAX@Z
// core::Drive (records.h CoreDrive): the flag at +0x5c
unsigned char __fastcall target(X_272b50* self, void*) {
    return self->flag5c;
}


// 0x00272b60 FUN_00272b60 (11 B): matches/0x00272b60.cpp
// sym: ?run@A_272b60@fn_f59a9783@@QAEHPAXHH@Z
// the drive thread's queue (0x00272fc0: the request, its priority, to the front; its result is the semaphore
// release's, which the requests return)
int A_272b60::run(void* a0, int a1, int a2) {
    return ((B_272b60*)driveThread)->FUN_00272fc0(a0, a1, (char)a2);
}


// 0x00272b70 FUN_00272b70 (11 B): matches/0x00272b70.cpp
// sym: ?run@A_272b70@fn_f59a9783@@QAEXHH@Z
void A_272b70::run(int a0, int a1) {
    ((B_272b70*)driveThread)->FUN_00273050(a0, a1);
}


// 0x00272b80 FUN_00272b80 (11 B): matches/0x00272b80.cpp
// sym: ?run@A_272b80@fn_f59a9783@@QAE_NXZ
bool A_272b80::run() {
    return ((B_272b80*)driveThread)->FUN_002730c0();
}


// 0x00272ba0 FUN_00272ba0 (8 B): matches/0x00272ba0.cpp
// sym: ?f@D@fn_f59a9783@@QAEXH@Z
// the library list (records.h CoreDriveLibraryList): appends (0x00277570)
void D::f(hulk_intptr a0) {
    ((C_272ba0*)&libraries)->FUN_00277570(a0);
}

} // namespace fn_f59a9783

// 0x00272bb0 FUN_00272bb0 (8 B): matches/0x00272bb0.cpp [wrapped: same definition as 0x00272ba0 in this TU]
// sym: ?f@D@fn_00272bb0@@QAEXH@Z
namespace fn_00272bb0 {

// the library list (records.h CoreDriveLibraryList): unlinks (0x002775b0)
struct C_272bb0 {
    void FUN_002775b0(hulk_intptr);
};
// core::Drive (records.h CoreDrive): removes a cement library from its list at +0x14
struct D : CoreDrive {
    void f(hulk_intptr);
};
void D::f(hulk_intptr a0) {
    ((C_272bb0*)&libraries)->FUN_002775b0(a0);
}
} // namespace fn_00272bb0

namespace fn_f59a9783 {

// 0x00272bc0 FUN_00272bc0 (4 B): matches/0x00272bc0.cpp
// sym: ?target@fn_f59a9783@@YIPAXPAUObj_272bc0@1@@Z
// core::Drive (records.h CoreDrive): its library list at +0x14
void* __fastcall target(Obj_272bc0* self) {
    return &self->libraries;
}

} // namespace fn_f59a9783

// 0x00272bd0 core::Drive::vfunc_5 (7 B): matches/0x00272bd0.cpp
// sym: ?vfunc_5@Drive@core@@UAEHHH@Z
int core::Drive::vfunc_5(hulk_intptr a, int b) {
    return b;
}


// 0x00272be0 core::Drive::vfunc_11 (8 B): matches/0x00272be0.cpp
// sym: ?vfunc_11@Drive@core@@UAEHPAX0@Z
int core::Drive::vfunc_11(void* __p0, void* __p1) {
    return 1;
}


// 0x00272bf0 core::Drive::vfunc_8 (5 B): matches/0x00272bf0.cpp
// sym: ?vfunc_8@Drive@core@@UAEHHHHHH@Z
int core::Drive::vfunc_8(int , int , int , int , int ) {
    return 0;
}


// 0x00272c00 core::Drive::vfunc_9 (5 B): matches/0x00272c00.cpp
// sym: ?vfunc_9@Drive@core@@UAEHHHHHHHH@Z
int core::Drive::vfunc_9(int , int , int , int , int , int , int ) {
    return 0;
}


// 0x00272c10 core::Drive::vfunc_13 (5 B): matches/0x00272c10.cpp
// sym: ?vfunc_13@Drive@core@@UAEHHHHHHHHHH@Z
int core::Drive::vfunc_13(int , int , int , int , int , int , int , int , int ) {
    return 0;
}

namespace fn_f59a9783 {

// 0x00272c20 core::Drive::vfunc_14 (3 B): matches/0x00272c20.cpp
// sym: ?GetZero@fn_f59a9783@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}


// 0x00272c30 core::Drive::vfunc_15 (5 B): matches/0x00272c30.cpp
// sym: ?vfunc_0@Drive_272c30@fn_f59a9783@@UAEHH@Z
// Same code shape as 0x00049c80 (propagated; names are from that function)
int Drive_272c30::vfunc_0(int) {
    return 0;
}


// 0x00272c40 core::Drive::vfunc_16 (5 B): matches/0x00272c40.cpp
// sym: ?vfunc_0@Drive_272c40@fn_f59a9783@@UAEHH@Z
// Same code shape as 0x00049c80 (propagated; names are from that function)
int Drive_272c40::vfunc_0(int) {
    return 0;
}


// 0x00272c50 core::Drive::vfunc_17 (5 B): matches/0x00272c50.cpp
// sym: ?vfunc_0@Drive_272c50@fn_f59a9783@@UAEHH@Z
// Same code shape as 0x00049c80 (propagated; names are from that function)
int Drive_272c50::vfunc_0(int) {
    return 0;
}


// 0x00272c60 core::Drive::vfunc_18 (5 B): matches/0x00272c60.cpp
// sym: ?FUN_00272c60@fn_f59a9783@@YGHHHHH@Z
// Same code shape as 0x001b4890 (propagated; names are from that function)
int __stdcall FUN_00272c60(int a, int b, int c, int d) {
    return 0;
}

} // namespace fn_f59a9783

// 0x00272c70 core::Drive::vfunc_19 (5 B): matches/0x00272c70.cpp
// sym: ?vfunc_19@Drive@core@@UAEHPAXH@Z
// Same code shape as 0x0026fe10 (propagated; names are from that function)
 // namespace core
int core::Drive::vfunc_19(void* __p0, int ) {
    return 0;
}


// 0x00272c80 core::Drive::vfunc_20 (8 B): matches/0x00272c80.cpp
// sym: ?vfunc_20@Drive@core@@UAEHH@Z
int core::Drive::vfunc_20(hulk_intptr ) {
    return 1;
}


// 0x00272c90 core::Drive::vfunc_21 (3 B): matches/0x00272c90.cpp
// sym: ?vfunc_21@Drive@core@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void core::Drive::vfunc_21(int a) {
    (void)a;
}


// 0x00272ca0 core::Drive::vfunc_0_adj4 (8 B): equivalent/0x00272ca0.cpp [wrapped: conflict: core::Drive; core::IRefCount; core::Object]
// sym: ?vfunc_0_adj4@Object@core@fn_00272ca0@@QAEXI@Z @003c2a31091b @wc0ab97093e5f
namespace fn_00272ca0 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// core::Drive::vfunc_0_adj4 @ 0x00272ca0
namespace core { struct IRefCount { virtual void vfunc_0(); }; struct Object { void vfunc_0_adj4(unsigned flags); }; struct Drive : IRefCount, Object { void vfunc_2_00272d90(unsigned flags); }; } void core::Object::vfunc_0_adj4(unsigned flags) { static_cast<core::Drive*>(this)->core::Drive::vfunc_2_00272d90(flags); }
} // namespace fn_00272ca0

namespace fn_f59a9783 {

// 0x00272cb0 core::Drive::vfunc_2_adjc (8 B): matches/0x00272cb0.cpp
// sym: ?v2@XboxDrive@fn_f59a9783@@WM@AEXH@Z
// Same code shape as 0x0026f540 (propagated; names are from that function)
XboxDrive* MakeXboxDrive() {
    return new XboxDrive();
}


// 0x00272ce0 core::SafeRefCount::vfunc_2 (31 B): matches/0x00272ce0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f59a9783@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0042b85c;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f59a9783

// 0x00272d00 FUN_00272d00 (132 B): matches/0x00272d00.cpp [wrapped: conflict: Drive]
// sym: ??0Drive@fn_00272d00@@QAE@XZ
namespace fn_00272d00 {

extern "C" void _ReadWriteBarrier();
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042b85c[];
extern "C" char DAT_0042b86c[];
extern "C" char DAT_0042b87c[];
extern "C" char DAT_0042b884[];
extern "C" int* FUN_002705f0();
// the library list's constructor 0x00277a40 (called as a member named by that address)
class Sub_272d00 {
  public:
    void FUN_00277a40();
};
// core::Drive (records.h CoreDrive): the bases' vftables (core::IRefCount, core::Object, core::SafeRefCount), then
// core::Drive's own (0x0042b884 / +4 0x0042b87c / +0xc 0x0042b86c)
class Drive : public CoreDrive {
  public:
    Drive();
};
Drive::Drive() {
    vftable = DAT_003f6098;
    vftableObject = DAT_0042afa8;
    heap = DAT_004cdbb0;
    FUN_002705f0();
    vftableMutable = DAT_0042b85c;
    _ReadWriteBarrier();
    refs = 1;
    _ReadWriteBarrier();
    vftable = DAT_0042b884;
    vftableObject = DAT_0042b87c;
    vftableMutable = DAT_0042b86c;
    ((Sub_272d00*)&libraries)->FUN_00277a40();
    requests = 0;
    lastRequest = 0;
    state = 0;
    signal = 0;
    thread = 0;
    callback = 0;
    argument = 0;
    active = 0;
    request = 0;
    flag5c = 1;
    busy = 0;
    error = 3;
    driveThread = 0;
    FUN_002705f0();
}
} // namespace fn_00272d00

namespace fn_f59a9783 {

// 0x00272d90 core::Drive::vfunc_2 (88 B): matches/0x00272d90.cpp
// sym: ?Dtor@Drive_272d90@fn_f59a9783@@QAEPAU12@E@Z
Drive_272d90* Drive_272d90::Dtor(unsigned char flag) throw() {
    v0 = vDrive;
    v4 = vD4;
    vc = vDc;
    part.Fini_00277540();
    vc = vSafe;
    _ReadWriteBarrier();
    unsigned t = p8;
    (*(unsigned*)&DAT_004cdbb0) = t;
    v4 = vBase;
    v0 = (void**)DAT_003f6098;
    if (flag & 1)
        FUN_00266f00((*(unsigned*)&DAT_004cdbb0), this);
    return this;
}

} // namespace fn_f59a9783

// 0x00272df0 core::Drive::vfunc_3 (259 B): equivalent/0x00272df0.cpp
// sym: ?vfunc_3@Drive_272df0@core@@QAEXXZ @aeb70e9f52ca @w5850eccf0b6f
// STATUS: equivalent (tools/equiv.py level 3: 20026 inputs, branch coverage 12/12)
// core::Drive::vfunc_3 @ 0x00272df0
// core::Drive::vfunc_3 (records.h CoreDrive): runs the pending requests that belong to the calling thread, then the
// drive's callback with the completed request's result (under the IMutable lock at +0xc)
void core::Drive_272df0::vfunc_3() {
 CoreThread* token=FUN_0026dbb0();
 Lock_272df0* lock=(Lock_272df0*)&vftableMutable;
 lock->acquire();
 Node** link=(Node**)&requests; Node* previous=0; Node* temporary;
 while (*link) {
  if ((*link)->FUN_00273680(token)) { Node* node=*link; *link=node->next; lock->release(); node->process(); lock->acquire(); node->destroy(1); }
  else { previous=*link; temporary=previous->next; link=&temporary; }
 }
 lastRequest=previous;
 if (active==1 && callback) {
  if (!busy) {
   busy=1; lock->release();
   CallbackTable* table=*(CallbackTable**)callback;
   Provider_272df0* p=(Provider_272df0*)request;
   unsigned value=p->get(argument);
   value=p->convert(value);
   unsigned kind=((DriveSlots_272df0*)this)->vfunc_4(value);
   union { void* address; CallbackMethod method; } entry; entry.address=table->run;
   unsigned result=(((Callback_272df0*)callback)->*entry.method)((unsigned)error,kind);
   FUN_00272a40(result);
   busy=0;
  } else lock->release();
 } else lock->release();
}

