// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00272f00..0x00273500 (kind game, layer engine, confidence high), dominant class core::DriveThread
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_f30ddaac {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f30ddaac {} using namespace fn_f30ddaac;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f30ddaac {
extern char hulk_at_0042b8f8[], hulk_at_0042b8f0[], hulk_at_0042b8e0[], hulk_at_0042b85c[], hulk_at_0042af64[], hulk_at_003f6098[];
void FnA_0026d8a0(void*);
extern "C" void FUN_0026d780(void*);
extern "C" void FUN_0026dad0(void*);
extern "C" void FUN_0026d880(void*);
struct DriveThread_272f00 {
    int* v0;
    int* v4;
    int f8;
    int* vc;
    char pad[0x64 - 0x10];
    char flag;
    char pad2[3];
    int a[1];
    char pad3[0x84 - 0x6c];
    int b[1];
    void Fn();
};
class X_272f70 {
  public:
    virtual void f();
    virtual void g();
    int n;
};
class DriveThread_272f70 {
  public:
    virtual void vfunc_0();
    const void* vftableObject;
    int heap;
    X_272f70 x;
};
class IRefCount_272f90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Param {
  public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
};
class Helper_272f90 {
  public:
    void Fnf_0026f160();
};
class DriveThread_272f90 : public IRefCount_272f90, public Param {
  public:
    virtual void vfunc_5();
    virtual void vfunc_6();
};
class DriveThreadMutable_272fa0 {
  public:
    const void* vftableMutable;
    int refs;
    void* lock;
    void vfunc_0_adjc();
};
class DriveThreadMutable_272fb0 {
  public:
    const void* vftableMutable;
    int refs;
    void* lock;
    void vfunc_0_adjc();
};
class Item_273050 {
  public:
    virtual void Release(int);
    virtual void Skip();
    virtual bool Match(int);
    Item_273050* next;
};
class List_273050 {
  public:
    virtual void Begin();
    virtual void End();
};
class Owner_273050 {
  public:
    char pad0[0x0c];
    List_273050 list;
    char pad10[0x5c];
    Item_273050* slots[3];
    Item_273050* tails[4];
    void Run(int, int);
};
void Clean_0026d890(void*);
class Thing_2730c0 {
  public:
    virtual void A();
    virtual void B();
};
class Target_2730c0 {
    char pad[0x0c];
    Thing_2730c0 mThing;
    char pad2[0x7c];
    int mValue;

  public:
    bool F();
};
typedef unsigned char u8_273120;
class Thing_273120 : public CoreDriveThread {
};
extern "C" void __cdecl FUN_0026d8a0(hulk_uintptr*);
struct Lock_273140 {
    virtual void acquire();
    virtual void release();
};
struct Node {
    hulk_uintptr value;
    Node* next;
};
struct Queue_273140 : CoreDriveThread {
    Node* FUN_00273140(unsigned int* index);
};
struct A_2731b0 {
    virtual void f0();
    virtual void f1();
    virtual void f(int);
};
struct B_2731b0 {
    virtual void f(int);
};
struct C_2731b0 : A_2731b0, B_2731b0 {
    C_2731b0();
    void f(int);
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
struct Item_2731d0;
struct Worker_2731d0 { int FUN_00272880(); int FUN_00272a20(); unsigned char FUN_00272b50(); void FUN_00272aa0(Item_2731d0*); };
struct Item_2731d0 { virtual void destroy(int); virtual int result(); virtual void unused(); virtual Worker_2731d0* worker(); virtual int process(); Item_2731d0* next; };
struct Lock_2731d0 { virtual void enter(); virtual void leave(); };
extern "C" void __cdecl FUN_0026d890(hulk_uintptr*);
struct State_2731d0 : CoreDriveThread { Item_2731d0* FUN_00273140(int*); };
extern "C" char DAT_003f6098[], DAT_0042afa8[], DAT_0042b85c[], DAT_0042b8e0[], DAT_0042b8f0[], DAT_0042b8f8[];
extern "C" int* FUN_002705f0();
extern "C" void __cdecl FUN_0026d860(hulk_uintptr*, int);
extern "C" int __cdecl FUN_002731d0(hulk_intptr);
extern "C" void __cdecl FUN_0026dce0(CoreThread*, int (__cdecl*)(hulk_intptr), hulk_intptr, int, unsigned long, hulk_uintptr);
struct DriveThread_2733c0 : CoreDriveThread {
 DriveThread_2733c0* FUN_002733c0(hulk_uintptr, hulk_uintptr);
};
typedef unsigned char u8_273480;
extern "C" void __cdecl FUN_00266f00(int, void*);
class DriveThread_273480 {
  public:
    void cleanup_00272f00();
    virtual void f0();
    virtual void f1();
    virtual DriveThread_273480* f2(u8_273480);
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


// 0x00272f00 FUN_00272f00 (107 B): matches/0x00272f00.cpp
// sym: ?Fn@DriveThread_272f00@fn_f30ddaac@@QAEXXZ
// data: g_last = DAT_004cdbb0
void DriveThread_272f00::Fn() {
    v0 = (int*)hulk_at_0042b8f8;
    v4 = (int*)hulk_at_0042b8f0;
    vc = (int*)hulk_at_0042b8e0;
    flag = 1;
    FnA_0026d8a0(&a);
    FUN_0026d780(&pad[0x18 - 0x10]);
    FUN_0026dad0(&pad[0x18 - 0x10]);
    FUN_0026d880(&a);
    FUN_0026d880(&b);
    int** q = &vc;
    *q = (int*)hulk_at_0042b85c;
    DAT_004cdbb0 = f8;
    int** q2 = &v4;
    *q2 = (int*)hulk_at_0042af64;
    v0 = (int*)hulk_at_003f6098;
}


// 0x00272f70 core::DriveThread::vfunc_0 (26 B): matches/0x00272f70.cpp
// sym: ?vfunc_0@DriveThread_272f70@fn_f30ddaac@@UAEXXZ
// Same code shape as 0x0026f130 (propagated; names are from that function)
void DriveThread_272f70::vfunc_0() {
    X_272f70* p = &x;
    p->f();
    ++p->n;
    p->g();
}


// 0x00272f90 core::DriveThread::vfunc_1 (8 B): matches/0x00272f90.cpp
// sym: ?vfunc_6@DriveThread_272f90@fn_f30ddaac@@UAEXXZ
// Same code shape as 0x0023c920 (propagated; names are from that function)
void DriveThread_272f90::vfunc_6() {
    ((Helper_272f90*)((char*)this + 0xc))->Fnf_0026f160();
}


// 0x00272fa0 core::DriveThread::vfunc_0_adjc (11 B): matches/0x00272fa0.cpp
// sym: ?vfunc_0_adjc@DriveThreadMutable_272fa0@fn_f30ddaac@@QAEXXZ
// core::DriveThread's IMutable base (+0xc of records.h CoreDriveThread): enters the device's critical section
void DriveThreadMutable_272fa0::vfunc_0_adjc() {
    FUN_0026d850(lock);
}


// 0x00272fb0 core::DriveThread::vfunc_1_adjc (11 B): matches/0x00272fb0.cpp
// sym: ?vfunc_0_adjc@DriveThreadMutable_272fb0@fn_f30ddaac@@QAEXXZ
// Same code shape as 0x00272fa0 (propagated; names are from that function)
// core::DriveThread's IMutable base (+0xc of records.h CoreDriveThread): leaves the device's critical section
void DriveThreadMutable_272fb0::vfunc_0_adjc() {
    FUN_0026d840(lock);
}

} // namespace fn_f30ddaac

// 0x00272fc0 FUN_00272fc0 (132 B): matches/0x00272fc0.cpp [wrapped: macros]
// sym: ?FUN_00272fc0@Queue_272fc0@fn_00272fc0@@QAEXPAUNode@2@HD@Z
namespace fn_00272fc0 {

struct Lock_272fc0 {
    virtual void enter();
    virtual void leave();
};
struct Node {
    hulk_uintptr data;
    Node* next;
};
extern "C++" __declspec(nothrow) int __cdecl FUN_0026d8a0(hulk_uintptr*);
// The function ends with the semaphore release, and the drives' requests return what it leaves in eax (0x00272b60's
// callers): the 64-bit builds return it (the 32-bit spelling with a result allocates registers differently)
#if defined(HULK_PTR64)
typedef int Result_272fc0;
#else
typedef void Result_272fc0;
#endif
// core::DriveThread (records.h CoreDriveThread): queues a request by priority and signals the worker; the lock is
// its IMutable base at +0xc
struct Queue_272fc0 : CoreDriveThread {
    Result_272fc0 FUN_00272fc0(Node* node, int index, char front);
};
Result_272fc0 Queue_272fc0::FUN_00272fc0(Node* node, int index, char front) {
    ((Lock_272fc0*)&vftableMutable)->enter();
    if (front) {
        if (!tails[index])
            tails[index] = node;
        node->next = (Node*)heads[index];
        heads[index] = node;
    } else {
        if (!heads[index])
            heads[index] = node;
        else
            ((Node*)tails[index])->next = node;
        node->next = 0;
        tails[index] = node;
    }
    ++count;
    ((Lock_272fc0*)&vftableMutable)->leave();
    return (Result_272fc0)FUN_0026d8a0(&ready);
}
} // namespace fn_00272fc0

namespace fn_f30ddaac {

// 0x00273050 FUN_00273050 (109 B): matches/0x00273050.cpp
// sym: ?Run@Owner_273050@fn_f30ddaac@@QAEXHH@Z
void Owner_273050::Run(int arg, int index) {
    list.Begin();
    Item_273050** p = &slots[index];
    Item_273050* cur = *p;
    Item_273050* prev = 0;
    while (cur != 0) {
        if ((*p)->Match(arg)) {
            Item_273050* x = *p;
            *p = x->next;
            x->Release(1);
            Clean_0026d890((char*)this + 0x68);
        } else {
            prev = *p;
            p = &prev->next;
        }
        cur = *p;
    }
    tails[index] = prev;
    list.End();
}


// 0x002730c0 FUN_002730c0 (39 B): matches/0x002730c0.cpp
// sym: ?F@Target_2730c0@fn_f30ddaac@@QAE_NXZ
bool Target_2730c0::F() {
    mThing.A();
    bool r = mValue != 0;
    mThing.B();
    return r;
}


// 0x00273120 FUN_00273120 (26 B): matches/0x00273120.cpp
// sym: ?Target@fn_f30ddaac@@YIXPAVThing_273120@1@PAXE@Z
void __fastcall Target(Thing_273120* self, void*, u8_273120 value) {
    self->requeue = value;
    FUN_0026d8a0(&self->done);
}


// 0x00273140 FUN_00273140 (108 B): equivalent/0x00273140.cpp
// sym: ?FUN_00273140@Queue_273140@fn_f30ddaac@@QAEPAUNode@2@PAI@Z
// STATUS: equivalent (tools/equiv.py level 3: 19878 inputs, branch coverage 8/8)
// FUN_00273140 @ 0x00273140
Node* Queue_273140::FUN_00273140(unsigned int* index) {
    Lock_273140* lock = (Lock_273140*)&vftableMutable;
    lock->acquire();
    Node* result = 0;
    for (unsigned int i = 0; i < 3; ++i) {
        if (heads[i]) {
            result = (Node*)heads[i];
            if (result == tails[i]) tails[i] = 0;
            heads[i] = result->next;
            result->next = 0;
            if (index) *index = i;
            break;
        }
    }
    lock->release();
    return result;
}


// 0x002731b0 core::DriveThread::vfunc_0_adj4 (8 B): matches/0x002731b0.cpp
// sym: ?f@C_2731b0@fn_f30ddaac@@W3AEXH@Z
C_2731b0::C_2731b0() {}


// 0x002731c0 core::DriveThread::vfunc_2_adjc (8 B): matches/0x002731c0.cpp
// sym: ?v2@XboxDrive@fn_f30ddaac@@WM@AEXH@Z
// Same code shape as 0x0026f540 (propagated; names are from that function)
XboxDrive* MakeXboxDrive() {
    return new XboxDrive();
}


// 0x002731d0 FUN_002731d0 (481 B): equivalent/0x002731d0.cpp
// sym: _FUN_002731d0
// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 29/36, incomplete)
// FUN_002731d0 @ 0x002731d0
// core::DriveThread's worker (0x002733c0 starts it with the thread object, records.h CoreDriveThread): runs the
// queued requests until stopped. A request's slot 3 is its drive (the core::Drive accessors 0x00272880 error,
// 0x00272a20 state, 0x00272b50 flag, 0x00272aa0 completes), its link to the next request is at +4.
extern "C" int __cdecl FUN_002731d0(hulk_intptr argument) {
 State_2731d0* s=(State_2731d0*)argument;
 Lock_2731d0* lock=(Lock_2731d0*)&s->vftableMutable;
 unsigned char pending=0;
 FUN_0026d890(&s->ready);
 while (!s->stopped) {
  int index;
  Item_2731d0* item=s->FUN_00273140(&index);
  Worker_2731d0* w=item->worker();
  int result;
  if(w->FUN_00272880()!=0 && w->FUN_00272880()!=1) { result=item->process(); if(result==1) result=item->result(); }
  else result=item->result();
  if(pending==1 && w->FUN_00272880()==0 && w->FUN_00272a20()==2 && w->FUN_00272b50()==1) { w->FUN_00272aa0(item); FUN_0026d890(&s->done); pending=0; }
  bool enqueue=false, dispose=false, special=false;
  if(result==2) enqueue=true;
  else if(result==1) dispose=true;
  else if(result==0) {
   int mode=w->FUN_00272a20();
   if(mode==0) dispose=true;
   else if(mode==1) enqueue=true;
   else if(mode==2) { w->FUN_00272aa0(item); FUN_0026d890(&s->done); if(s->requeue) { enqueue=true; special=true; } else dispose=true; }
  }
  if(enqueue) { lock->enter(); if(!s->tails[index]) s->tails[index]=item; item->next=(Item_2731d0*)s->heads[index]; s->heads[index]=item; ++s->count; lock->leave(); FUN_0026d8a0(&s->ready); if(special) { s->requeue=0; pending=1; } }
  else if(dispose) item->destroy(1);
  lock->enter(); --s->count; lock->leave(); FUN_0026d890(&s->ready);
 }
 return 0;
}


// 0x002733c0 FUN_002733c0 (180 B): equivalent/0x002733c0.cpp
// sym: ?FUN_002733c0@DriveThread_2733c0@fn_f30ddaac@@QAEPAU12@II@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002733c0 @ 0x002733c0
DriveThread_2733c0* DriveThread_2733c0::FUN_002733c0(hulk_uintptr arg1, hulk_uintptr arg2) {
 vftable=DAT_003f6098; vftableObject=DAT_0042afa8; heap=DAT_004cdbb0;
 FUN_002705f0();
 vftableMutable=DAT_0042b85c; refs=1;
 vftable=DAT_0042b8f8; vftableObject=DAT_0042b8f0; vftableMutable=DAT_0042b8e0;
 lock=(void*)arg1; stopped=0; requeue=0; count=0; unknown90=0;
 FUN_002705f0();
 heads[0]=0; tails[0]=0; heads[1]=0; tails[1]=0; heads[2]=0; tails[2]=0;
 FUN_0026d860(&ready,0);
 FUN_0026d860(&done,0);
 FUN_0026dce0(&worker,FUN_002731d0,(hulk_intptr)this,4,0x2000,arg2);
 return this;
}


// 0x00273480 core::DriveThread::vfunc_2 (36 B): matches/0x00273480.cpp
// sym: ?f2@DriveThread_273480@fn_f30ddaac@@UAEPAV12@E@Z
// Same code shape as 0x00269560 (propagated; names are from that function)
// data: globalValue = DAT_004cdbb0
DriveThread_273480* DriveThread_273480::f2(u8_273480 flag) {
    cleanup_00272f00();
    if (flag & 1)
        FUN_00266f00(DAT_004cdbb0, this);
    return this;
}

} // namespace fn_f30ddaac
