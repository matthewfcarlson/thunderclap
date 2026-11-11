// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0026d480..0x0026de20 (kind game, layer platform/xbox, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_fc974b3c {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc974b3c {} using namespace fn_fc974b3c;
#include "platform/xbox/core.h"

// ---- declarations shared by the functions below
namespace fn_fc974b3c {
extern "C" char DAT_0042b3ac[];
extern "C" char DAT_0042b3b4[];
extern "C" char DAT_0042b3fc[];
void Init();
} // namespace fn_fc974b3c
inline void* operator new(size_t, void* p) {
    return p;
}
namespace fn_fc974b3c {
struct MemoryTwoWayAllocator_26d540 {
    char pad0[8];
    int size;
    char pad1[4];
    char* begin;
    char* end;
    char* cur;
    char* limit;
    char pad2[12];
    MemoryTwoWayAllocator_26d540();
};
extern "C" void* __cdecl Alloc(hulk_intptr, int);
extern "C" void __cdecl Other();
void __stdcall FUN_0020c723(int);
struct Task { char pad[0x38]; char busy; char pad2[3]; int result; };
extern void __stdcall DeleteFiber(void*);
extern "C" void(__stdcall* DAT_003f2d38)(void*);
extern "C" void(__stdcall* DAT_003f2c88)(void*);
extern "C" void(__stdcall* DAT_003f2c8c)(void*);
extern "C" hulk_uintptr __stdcall FUN_0020c2c9(hulk_uintptr, int, int, hulk_uintptr);
extern "C" int __stdcall FUN_0020bbc2(hulk_uintptr);
extern "C" unsigned int __stdcall FUN_0020c6f7(hulk_uintptr, int);
extern "C" int __stdcall FUN_0020c380(hulk_uintptr, int, hulk_uintptr);
struct Node_26d8f0 {
    Node_26d8f0* next;
    Node_26d8f0* previous;
};
struct Node {
    Node* next;
    Node* previous;
};
extern "C" int FUN_0020c14b();
namespace XAPILIB {
void* __stdcall ConvertThreadToFiber(void*);
}
namespace XAPILIB {
int __stdcall SetThreadPriority(void*, int);
}
struct ThreadList_26d990 {
    static void __cdecl FUN_0026d8f0(unsigned int *);
};
struct ThreadList_26da20 {
    static void __cdecl FUN_0026d940(void *);
};
extern "C" void FUN_00272540(void);
struct Thread_26da80 {
    static void __cdecl FUN_0026d990(void *);
};
extern "C" void f1();
extern "C" void f2();
struct ThreadList_26dad0 {
    static void __cdecl FUN_0026d940(void *);
};
extern "C++" __declspec(nothrow) void __stdcall FUN_0020bbc2(hulk_intptr);
extern "C++" __declspec(nothrow) void __stdcall FUN_0020c6f7(hulk_intptr, int);
namespace XAPILIB {
void __stdcall ExitThread(int);
}
typedef unsigned int u32_26db70;
extern "C" void* __stdcall ConvertThreadToFiber(void*);
extern CoreThread* FUN_0026dbb0();
namespace XAPILIB {
void __stdcall SwitchToFiber(void*);
}
struct Thread_26dc50 {
    static void __cdecl FUN_0026d8f0(unsigned int *);
    static int __stdcall FUN_0026db70(CoreThread *);
};
namespace XAPILIB {
void * __stdcall CreateThread(void *, unsigned long, unsigned long (__stdcall *)(void *), void *, unsigned long, unsigned long *);
}
int __stdcall FUN_0020bd91(void *);
} // namespace fn_fc974b3c
extern "C" void _ReadWriteBarrier(void);
namespace fn_fc974b3c {
int __cdecl FUN_0026dc50(CoreThread *worker, int (__cdecl *entry)(hulk_intptr), hulk_intptr argument, int priority, unsigned long stackSize);
extern "C" void __cdecl FUN_0026dc20();
extern "C" void* __stdcall CreateFiber(unsigned int, void*, void*);
struct Fiber_26dd70 {
    static void __cdecl FUN_0026dd10(CoreFiber*, void*, void*, unsigned int, unsigned int, unsigned int);
};

} // namespace fn_fc974b3c

// 0x0026d480 FUN_0026d480 (91 B): matches/0x0026d480.cpp
// sym: ?FUN_0026d480@MemoryTwoWayAllocator@core@@QAEPAHXZ
// data: gValue_26d480 = DAT_004cdbb0
int* core::MemoryTwoWayAllocator::FUN_0026d480() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042b3fc);
    ((hulk_intptr*)this)[1] = ((hulk_intptr)DAT_0042afa8);
    ((int*)this)[2] = DAT_004cdbb0;
    Init();
    ((hulk_intptr*)this)[1] = ((hulk_intptr)DAT_0042b3a4);
    ((int*)this)[3] = 0;
    Init();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042b3b4);
    ((hulk_intptr*)this)[1] = ((hulk_intptr)DAT_0042b3ac);
    ((int*)this)[4] = 0;
    ((int*)this)[5] = 0;
    ((int*)this)[6] = 0;
    ((int*)this)[7] = 0;
    ((int*)this)[8] = 0;
    ((int*)this)[9] = 0;
    ((int*)this)[10] = 0;
    Init();
    return (int*)((int*)this);
}

namespace fn_fc974b3c {

// 0x0026d540 FUN_0026d540 (81 B): matches/0x0026d540.cpp
// sym: ?Make@fn_fc974b3c@@YAPAUMemoryTwoWayAllocator_26d540@1@HH@Z
MemoryTwoWayAllocator_26d540* __cdecl Make(int n, int heap) {
    DAT_004cdbb0 = heap;
    void* p = Alloc(heap, 44);
    MemoryTwoWayAllocator_26d540* o = new (p) MemoryTwoWayAllocator_26d540;
    Other();
    char* q = (char*)Alloc(o->size, n);
    char* e = q + n;
    o->begin = q;
    o->cur = q;
    o->end = e;
    o->limit = e;
    return o;
}


// 0x0026d6d0 FUN_0026d6d0 (11 B): matches/0x0026d6d0.cpp
// sym: _FUN_0026d6d0
extern "C" void __cdecl FUN_0026d6d0(int value) {
    FUN_0020c723(value);
}


// 0x0026d780 FUN_0026d780 (26 B): equivalent/0x0026d780.cpp
// sym: _FUN_0026d780 @847b651456aa @w2d050da50a34
// STATUS: equivalent (tools/equiv.py level 3: 2892 inputs, branch coverage 2/2)
// FUN_0026d780 @ 0x0026d780
extern "C" int __cdecl FUN_0026d780(Task* task) {
    while (task->busy != 0) {
        FUN_0020c723(0);
    }
    return task->result;
}


// 0x0026d7a0 FUN_0026d7a0 (76 B): matches/0x0026d7a0.cpp
// sym: _FUN_0026d7a0
// data: gSpecial = DAT_0052a138
// a fiber off its thread's fiber list; its XAPI fiber is deleted unless it is a thread's own (the converted thread)
extern "C" void __cdecl FUN_0026d7a0(void * p_) {
    CoreFiber* p = (CoreFiber*)p_;
    if (p != &DAT_0052a130.main && p != &p->thread->main)
        DeleteFiber(p->fiber);
    CoreThread* parent = p->thread;
    if (p->previous == 0)
        parent->first = p->next;
    else
        p->previous->next = p->next;
    if (p->next == 0) {
        parent->last = p->previous;
        return;
    }
    p->next->previous = p->previous;
}


// 0x0026d820 FUN_0026d820 (12 B): matches/0x0026d820.cpp
// sym: _FUN_0026d820
   // kernel import slot RtlInitializeCriticalSection
extern "C" void FUN_0026d820(void* arg) {
    DAT_003f2d38(arg);
}


// 0x0026d830 FUN_0026d830 (1 B): matches/0x0026d830.cpp
// sym: _FUN_0026d830
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_0026d830() {}


// 0x0026d840 FUN_0026d840 (12 B): matches/0x0026d840.cpp
// sym: _FUN_0026d840
// Same code shape as 0x0026d820
   // kernel import slot RtlLeaveCriticalSection (the caller reads eax)
extern "C" int FUN_0026d840(void* arg) {
    return ((int(__stdcall*)(void*))DAT_003f2c88)(arg);
}


// 0x0026d850 FUN_0026d850 (12 B): matches/0x0026d850.cpp
// sym: _FUN_0026d850
// Same code shape as 0x0026d820
   // kernel import slot RtlEnterCriticalSection
extern "C" void FUN_0026d850(void* arg) {
    DAT_003f2c8c(arg);
}


// 0x0026d860 FUN_0026d860 (26 B): matches/0x0026d860.cpp
// sym: _FUN_0026d860
// CreateSemaphore (the XDK row 0x0020c2c9): the handle is pointer-sized on the 64-bit builds
extern "C" void __cdecl FUN_0026d860(hulk_uintptr* out, int value) {
    *out = FUN_0020c2c9(0, value, 32000, 0);
}


// 0x0026d880 FUN_0026d880 (13 B): matches/0x0026d880.cpp
// sym: _FUN_0026d880
// CloseHandle (the XDK row 0x0020bbc2) on the semaphore 0x0026d860 created
extern "C" void __cdecl FUN_0026d880(hulk_uintptr* handle) {
    FUN_0020bbc2(*handle);
}


// 0x0026d890 FUN_0026d890 (15 B): matches/0x0026d890.cpp
// sym: _FUN_0026d890
// WaitForSingleObject (the XDK row 0x0020c6f7) on the semaphore 0x0026d860 created
extern "C" void __cdecl FUN_0026d890(hulk_uintptr* p) {
    FUN_0020c6f7(*p, -1);
}


// 0x0026d8a0 FUN_0026d8a0 (17 B): matches/0x0026d8a0.cpp
// sym: _FUN_0026d8a0
// ReleaseSemaphore (the XDK row 0x0020c380) on the semaphore 0x0026d860 created; its result is the caller's (the
// drive thread's queue 0x00272fc0 and the drives' requests return it)
extern "C" int __cdecl FUN_0026d8a0(hulk_uintptr* handle) {
    return FUN_0020c380(*handle, 1, 0);
}


// 0x0026d8f0 FUN_0026d8f0 (78 B): matches/0x0026d8f0.cpp
// sym: _FUN_0026d8f0
// data: gFirst_26d8f0 = DAT_0052a180, gLast_26d8f0 = DAT_0052a17c, gLock_26d8f0 = DAT_0052a188
// the thread list (0x0026d940 unlinks, 0x0026dbb0 walks it): the node is the thread object's first two words
   // kernel import slot RtlLeaveCriticalSection
extern "C" void __cdecl FUN_0026d8f0(unsigned int* node_) {   // (the callers' declaration)
    Node_26d8f0* node = (Node_26d8f0*)node_;
    DAT_003f2c8c(((char*)&DAT_0052a188));
    if ((*(Node_26d8f0**)&DAT_0052a180) == 0) {
        (*(Node_26d8f0**)&DAT_0052a180) = node;
        node->previous = 0;
    } else {
        (*(Node_26d8f0**)&DAT_0052a17c)->next = node;
        node->previous = (*(Node_26d8f0**)&DAT_0052a17c);
    }
    (*(Node_26d8f0**)&DAT_0052a17c) = node;
    node->next = 0;
    DAT_003f2c88(((char*)&DAT_0052a188));
}


// 0x0026d940 FUN_0026d940 (80 B): matches/0x0026d940.cpp
// sym: _FUN_0026d940
extern "C" void __cdecl FUN_0026d940(void * node) {
    DAT_003f2c8c(((char*)&DAT_0052a188));
    if (((Node *)node)->previous == 0)
        (*(Node**)&DAT_0052a180) = ((Node *)node)->next;
    else
        ((Node *)node)->previous->next = ((Node *)node)->next;
    if (((Node *)node)->next == 0)
        (*(Node**)&DAT_0052a17c) = ((Node *)node)->previous;
    else
        ((Node *)node)->next->previous = ((Node *)node)->previous;
    DAT_003f2c88(((char*)&DAT_0052a188));
}


// 0x0026d990 FUN_0026d990 (133 B): equivalent/0x0026d990.cpp
// sym: _FUN_0026d990 @48e212580e40 @wd87400e12fb3
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 2/2)
// FUN_0026d990 @ 0x0026d990
// The calling thread becomes a scheduler thread: its record's own fiber is the converted thread.
extern "C" void __cdecl FUN_0026d990(void * self_) {
    CoreThread * self = (CoreThread *)self_;
    self->first = 0;
    self->last = 0;
    self->active = 1;
    int thread = FUN_0020c14b();
    self->threadId = thread;
    self->handle = (void*)(hulk_intptr)-2;
    self->main.state[2] = 0;
    self->main.entry = 0;
    self->main.argument = 0;
    self->main.fiber = XAPILIB::ConvertThreadToFiber(0);
    self->main.thread = self;
    self->main.state[0] = 0;
    self->main.state[1] = 0;
    self->current = &self->main;
    if (!self->first) {
        self->first = &self->main;
        self->main.previous = 0;
    } else {
        self->last->next = &self->main;
        self->main.previous = self->last;
    }
    self->last = &self->main;
    self->main.next = 0;
    ThreadList_26d990::FUN_0026d8f0((unsigned int *)self);
    self->priority = 2;
    XAPILIB::SetThreadPriority(self->handle, DAT_004cd9d8);
}


// 0x0026da20 FUN_0026da20 (87 B): equivalent/0x0026da20.cpp
// sym: ?FUN_0026da20@fn_fc974b3c@@YAXXZ @fe4aaf9ffc40 @w3094136c4164
// STATUS: equivalent (tools/equiv.py level 3: 2949 inputs, branch coverage 4/4)
// FUN_0026da20 @ 0x0026da20
// The main thread leaves the scheduler: its own fiber off its thread's fiber list, then the thread off the list.
// (class-scope declarations of the TU-mates' C functions: gen_tree gives a merged C definition's other C
// declarations C++ linkage, docs/native-build.md "A gen_tree bug"; bound by the address in the name)
void FUN_0026da20() {
    CoreThread* head = DAT_0052a130.main.thread;
    if (DAT_0052a130.main.previous == 0) head->first = DAT_0052a130.main.next; else DAT_0052a130.main.previous->next = DAT_0052a130.main.next;
    if (DAT_0052a130.main.next == 0) head->last = DAT_0052a130.main.previous; else DAT_0052a130.main.next->previous = DAT_0052a130.main.previous;
    ThreadList_26da20::FUN_0026d940(&DAT_0052a130);
}


// 0x0026da80 FUN_0026da80 (36 B): matches/0x0026da80.cpp
// sym: _FUN_0026da80
   // kernel import slot RtlInitializeCriticalSection
extern "C" void FUN_0026da80(int unused) {
    DAT_003f2d38((void*)((hulk_intptr)((char*)&DAT_0052a188)));
    *(volatile unsigned char*)((hulk_intptr)DAT_0052a184) = 1;
    FUN_00272540();
    Thread_26da80::FUN_0026d990(&DAT_0052a130);
}


// 0x0026dab0 FUN_0026dab0 (18 B): matches/0x0026dab0.cpp
// sym: _FUN_0026dab0
extern "C" void FUN_0026dab0() {
    f1();
    f2();
    (*(unsigned char*)&DAT_0052a184) = 0;
}


// 0x0026dad0 FUN_0026dad0 (151 B): matches/0x0026dad0.cpp
// sym: _FUN_0026dad0
// (class-scope declarations of the TU-mates' C functions: gen_tree gives a merged C definition's other C
// declarations C++ linkage, docs/native-build.md "A gen_tree bug"; bound by the address in the name)
extern "C" void __cdecl FUN_0026dad0(CoreThread* job) {
    ThreadList_26dad0::FUN_0026d940((CoreThread *)job);
    DAT_003f2c8c(((char*)&DAT_0052a188));
    if (job->active) {
        if (job->threadId == FUN_0020c14b()) {
            FUN_0026d7a0(&job->main);
            DAT_003f2c88(((char*)&DAT_0052a188));
            FUN_0020bbc2((hulk_intptr)job->handle);
            XAPILIB::ExitThread(0);
        }
        FUN_0026d7a0(&job->main);
        DAT_003f2c88(((char*)&DAT_0052a188));
        return;
    }
    FUN_0026d7a0(&job->main);
    DAT_003f2c88(((char*)&DAT_0052a188));
    FUN_0020c6f7((hulk_intptr)job->handle, -1);
    FUN_0020bbc2((hulk_intptr)job->handle);
}


// 0x0026db70 FUN_0026db70 (52 B): matches/0x0026db70.cpp
// sym: _FUN_0026db70@4
// a new thread's start routine (0x0026dc50): its own fiber runs the entry
extern "C" int __stdcall FUN_0026db70(CoreThread* p) {
    p->main.state[0] = 0;
    p->main.fiber = ConvertThreadToFiber(0);
    p->result = p->main.entry(p->main.argument);
    p->active = 0;
    p->main.state[2] = 0;
    return 0;
}

} // namespace fn_fc974b3c

// 0x0026dbb0 FUN_0026dbb0 (53 B): matches/0x0026dbb0.cpp [wrapped: conflict: DAT_003f2c88; DAT_003f2c8c]
// sym: _FUN_0026dbb0
namespace fn_0026dbb0 {

// the calling thread's record: the thread list (0x0052a180, 0x0026d8f0 appends) searched by thread id, under the
// list's critical section (0x0052a188)
typedef void(__stdcall* LockFn)(void*);
extern "C++" { extern LockFn DAT_003f2c8c; }
extern "C++" { extern LockFn DAT_003f2c88; }
extern "C" int __cdecl FUN_0020c14b();
extern "C" CoreThread* __cdecl FUN_0026dbb0() {
    CoreThread* p = *(CoreThread**)&DAT_0052a180;
    DAT_003f2c8c(DAT_0052a188);
    while (p != 0 && p->threadId != FUN_0020c14b())
        p = p->next;
    DAT_003f2c88(DAT_0052a188);
    return p;
}
} // namespace fn_0026dbb0

namespace fn_fc974b3c {

// 0x0026dbf0 FUN_0026dbf0 (14 B): matches/0x0026dbf0.cpp
// sym: _FUN_0026dbf0
// the fiber running on the calling thread
extern "C" CoreFiber* __cdecl FUN_0026dbf0() {
    CoreThread* p = FUN_0026dbb0();
    if (!p)
        return 0;
    return p->current;
}


// 0x0026dc00 FUN_0026dc00 (22 B): matches/0x0026dc00.cpp
// sym: _FUN_0026dc00
extern "C" void __cdecl FUN_0026dc00(CoreFiber* target) {
    CoreThread* p = FUN_0026dbb0();
    p->current = target;
    XAPILIB::SwitchToFiber(target->fiber);
}


// 0x0026dc20 FUN_0026dc20 (42 B): equivalent/0x0026dc20.cpp
// sym: ?FUN_0026dc20@fn_fc974b3c@@YGXH@Z @d76343dcd56c @w041b68de5f9c
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 1/1)
// FUN_0026dc20 @ 0x0026dc20
// equiv-dead: +0x7 not taken: the null-result path dereferences null (faults on every input)
// The start routine of the fibers 0x0026dd10 creates: the calling thread's current fiber runs its entry.
void __stdcall FUN_0026dc20(int unused)
{
    CoreThread* t = FUN_0026dbb0();
    CoreFiber* o;
    if (t != 0) {
        o = t->current;
        o->state[0] = 0;
    } else {
        // the original dereferences the null result here (faults); kept as is
        o = (CoreFiber*)t;
        o->state[0] = 0;
    }
    o->entry(o->argument);
}


// 0x0026dc50 FUN_0026dc50 (129 B): equivalent/0x0026dc50.cpp
// sym: ?FUN_0026dc50@fn_fc974b3c@@YAHPAUCoreThread@@P6AHH@ZHHK@Z @4912a605e6b7 @we27998c4c6e1
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// FUN_0026dc50 @ 0x0026dc50
// A new scheduler thread: its record's own fiber runs entry(argument) on a thread 0x0026db70 starts.
// (class-scope declarations of the TU-mates' C functions: gen_tree gives a merged C definition's other C
// declarations C++ linkage, docs/native-build.md "A gen_tree bug"; bound by the address in the name)
int __cdecl FUN_0026dc50(CoreThread *worker, int (__cdecl *entry)(hulk_intptr), hulk_intptr argument, int priority, unsigned long stackSize) {
    worker->active = 1;
    worker->current = &worker->main;
    worker->main.state[2] = 0;
    worker->main.entry = entry;
    worker->main.argument = argument;
    worker->main.thread = worker;
    worker->main.fiber = 0;
    worker->main.state[0] = 0;
    worker->main.state[1] = 0;
    worker->first = &worker->main;
    worker->main.previous = 0;
    worker->last = &worker->main;
    worker->main.next = 0;
    Thread_26dc50::FUN_0026d8f0((unsigned int *)worker);
    worker->handle = XAPILIB::CreateThread(0, stackSize, (unsigned long (__stdcall *)(void *))Thread_26dc50::FUN_0026db70, worker, 4, (unsigned long *)&worker->threadId);
    worker->main.state[1] = 0;
    worker->priority = priority;
    XAPILIB::SetThreadPriority(worker->handle, DAT_004cd9d0[priority]);
    return FUN_0020bd91(worker->handle);
}


// 0x0026dce0 FUN_0026dce0 (34 B): matches/0x0026dce0.cpp
// sym: _FUN_0026dce0
// A new scheduler thread (0x0026dc50 starts it: the record, its fiber's entry and argument, the priority, the stack)
extern "C" void __cdecl FUN_0026dce0(CoreThread *worker, int (__cdecl *entry)(hulk_intptr), hulk_intptr argument, int priority, unsigned long stackSize) {
    FUN_0026dc50(worker, entry, argument, priority, stackSize);
    _ReadWriteBarrier();
}


// 0x0026dd10 FUN_0026dd10 (91 B): matches/0x0026dd10.cpp
// sym: ?FUN_0026dd10@fn_fc974b3c@@YAXPAUCoreFiber@@PAX1III@Z
// a fiber on the calling thread (appended to its fiber list), started at 0x0026dc20: entry(argument)
void __cdecl FUN_0026dd10(CoreFiber* p, void* entry, void* argument, unsigned int unused, unsigned int stack, unsigned int unused2) {
    p->state[2] = 0;
    p->entry = (int(__cdecl*)(hulk_intptr))entry;
    p->argument = (hulk_intptr)argument;
    CoreThread* l = FUN_0026dbb0();
    p->thread = l;
    if (!l->first) {
        l->first = p;
        p->previous = 0;
    } else {
        l->last->next = p;
        p->previous = l->last;
    }
    l->last = p;
    p->next = 0;
    void* r = CreateFiber(stack, (void*)((hulk_intptr)(void (__cdecl*)())&FUN_0026dc20), p);
    p->state[1] = 0;
    p->state[0] = 0;
    p->fiber = r;
}


// 0x0026dd70 FUN_0026dd70 (36 B): matches/0x0026dd70.cpp
// sym: _FUN_0026dd70
// (a class-scope declaration of the TU-mate 0x0026dd10: bound by the address in the name)
// a fiber on the calling thread: 0x0026dd10 with an unused fourth argument
extern "C" void FUN_0026dd70(CoreFiber* fiber, void* entry, void* argument, unsigned int stack, unsigned int unused) {
    Fiber_26dd70::FUN_0026dd10(fiber, entry, argument, 0, stack, unused);
}

} // namespace fn_fc974b3c
