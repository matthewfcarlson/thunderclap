// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00267070..0x00267280 (kind game, layer engine, confidence high), dominant class core::MemoryAllocatorMalloc
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/records.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f03133a3 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f03133a3 {} using namespace fn_f03133a3;
namespace fn_f03133a3 { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f03133a3 {
struct Obj_267070 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h(int);
};
struct Handle_267070 {
    Obj_267070* p;
};
extern "C" Handle_267070* __cdecl FUN_00266f90(void*, int);
struct Obj_267090 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void*);
};
extern "C" Obj_267090** FUN_00266f50(void*, void*);
struct Obj_2670b0 {
    virtual void F();
};
struct Object { virtual void unused(); virtual void FUN_00000000(); };
extern char hulk_at_0042af2c;
void InitAllocator_002705f0();
struct MemoryAllocatorMalloc {
    void* vptr;
    MemoryAllocatorMalloc* Init();
};
extern "C" void* __cdecl FUN_00270540(unsigned int size);
struct MemoryAllocatorMalloc_267210 {
    void* vfunc_3(unsigned int size);
};
extern "C" void thunk_FUN_003479bc(void*);
extern "C" void* __cdecl FUN_00270570(int size, unsigned alignment);
class MemoryAllocatorMalloc_267230 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void* vfunc_6(int size, unsigned alignment);
};
void FUN_002705b0(void*);
namespace pure3d {
class NonCopyable_267260 : public ::core::IMemoryAllocator {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_267260* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable_267260*);


// 0x00267070 FUN_00267070 (29 B): matches/0x00267070.cpp
// sym: _FUN_00267070
extern "C" void __cdecl FUN_00267070(int x) {
    Handle_267070* h = FUN_00266f90((void*)((hulk_intptr)((char*)&DAT_00527f40)), x);
    h->p->h(x);
}


// 0x00267090 FUN_00267090 (29 B): matches/0x00267090.cpp
// sym: _FUN_00267090
// Free a block: the heap tree's owner of the block (0x00266f50) frees it through its slot 4 (core::IMemoryAllocator's
// free, which takes the block as a pointer).
extern "C" void FUN_00267090(void* ptr) {
    Obj_267090** p = FUN_00266f50(((char*)&DAT_00527f40), ptr);
    (*p)->f4(ptr);
}


// 0x002670b0 FUN_002670b0 (81 B): matches/0x002670b0.cpp
// sym: _FUN_002670b0
extern "C" void FUN_002670b0(int a, int b, Obj_2670b0* obj) {
    MemoryHeapSlot* dest = &DAT_00527c60[a];
    MemoryHeapSlot* list;
    if (b == 45)
        list = &DAT_00527f40;
    else {
        list = &DAT_00527c60[b];
        if (list->parent == 0)
            list = &DAT_00527f40;
    }
    obj->F();
    dest->allocator = (void*)obj;
    dest->parent = list;
    dest->child = 0;
    dest->next = list->child;
    list->child = dest;
}


// 0x00267110 FUN_00267110 (102 B): equivalent/0x00267110.cpp
// sym: _FUN_00267110 @58e7779c2097 @w17f85fa92935
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 7/8, incomplete)
// FUN_00267110 @ 0x00267110
extern "C" void __cdecl FUN_00267110(unsigned int index) {
    MemoryHeapSlot* entry = &DAT_00527c60[index];
    MemoryHeapSlot* list = entry->parent;
    MemoryHeapSlot* current = list->child;
    MemoryHeapSlot* previous = 0;
    if (!current) return;
    while (current != entry) {
        previous = current;
        current = current->next;
        if (!current) return;
    }
    if (previous) previous->next = entry->next;
    else list->child = entry->next;
    ((Object*)entry->allocator)->FUN_00000000();
    entry->allocator = (*(void**)&DAT_00527f58);
    entry->child = 0;
    entry->parent = 0;
    entry->next = 0;
}


// 0x00267180 FUN_00267180 (18 B): matches/0x00267180.cpp
// sym: ?Init@MemoryAllocatorMalloc@fn_f03133a3@@QAEPAU12@XZ
MemoryAllocatorMalloc* MemoryAllocatorMalloc::Init() {
    vptr = &hulk_at_0042af2c;
    InitAllocator_002705f0();
    return this;
}


// 0x002671a0 core::MemoryAllocatorMalloc::vfunc_0 (1 B): matches/0x002671a0.cpp
// sym: ?FUN_00025410@fn_f03133a3@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00025410() {}

} // namespace fn_f03133a3

// 0x002671b0 core::MemoryAllocatorMalloc::vfunc_1 (1 B): matches/0x002671b0.cpp [wrapped: same definition as 0x002671a0 in this TU]
// sym: ?FUN_00025410@fn_002671b0@@YAXXZ
namespace fn_002671b0 {
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00025410() {}
} // namespace fn_002671b0


// 0x002671c0 core::MemoryAllocatorMalloc::vfunc_5 (5 B): matches/0x002671c0.cpp
// sym: ?vfunc_5@MemoryAllocatorMalloc@core@@UAE_NPAX@Z
// Same code shape as 0x00013980 (propagated; names are from that function)
bool core::MemoryAllocatorMalloc::vfunc_5(void* __p0) {
    return true;
}


// 0x002671d0 core::MemoryAllocatorMalloc::vfunc_8 (5 B): matches/0x002671d0.cpp
// sym: ?vfunc_8@MemoryAllocatorMalloc@core@@UAE_NPAX@Z
// Same code shape as 0x00013980 (propagated; names are from that function)
bool core::MemoryAllocatorMalloc::vfunc_8(void* __p0) {
    return true;
}


// 0x002671e0 core::MemoryAllocatorMalloc::vfunc_9 (31 B): matches/0x002671e0.cpp [wrapped: conflict: MemoryAllocatorMalloc]
// sym: ?vfunc_9@MemoryAllocatorMalloc@fn_002671e0@@UAEHHHHH@Z
namespace fn_002671e0 {
class MemoryAllocatorMalloc {
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
    virtual int vfunc_9(int a, int b, int c, int d);
};
extern int helper_002705d0(int, int, int, int);
int MemoryAllocatorMalloc::vfunc_9(int a, int b, int c, int d) {
    return helper_002705d0(a, b, c, d);
}
} // namespace fn_002671e0

// 0x00267200 core::MemoryAllocatorMalloc::vfunc_11 (5 B): not yet verified
namespace fn_f03133a3 {

// 0x00267210 core::MemoryAllocatorMalloc::vfunc_3 (16 B): matches/0x00267210.cpp
// sym: ?vfunc_3@MemoryAllocatorMalloc_267210@fn_f03133a3@@QAEPAXI@Z
// core::MemoryAllocatorMalloc::vfunc_3 (slot 3: allocate)
void* MemoryAllocatorMalloc_267210::vfunc_3(unsigned int size) {
    return FUN_00270540(size);
}

} // namespace fn_f03133a3

// 0x00267220 core::MemoryAllocatorMalloc::vfunc_4 (14 B): matches/0x00267220.cpp
// sym: ?vfunc_4@MemoryAllocatorMalloc@core@@UAEXPAX@Z
void core::MemoryAllocatorMalloc::vfunc_4(void* __p0) { void * p = (void *)__p0;

    thunk_FUN_003479bc(p);
}

namespace fn_f03133a3 {

// 0x00267230 core::MemoryAllocatorMalloc::vfunc_6 (21 B): matches/0x00267230.cpp
// sym: ?vfunc_6@MemoryAllocatorMalloc_267230@fn_f03133a3@@UAEPAXHI@Z
// core::MemoryAllocatorMalloc::vfunc_6 (slot 6: allocate aligned)
void* MemoryAllocatorMalloc_267230::vfunc_6(int size, unsigned alignment) {
    return FUN_00270570(size, alignment);
}

} // namespace fn_f03133a3

// 0x00267250 core::MemoryAllocatorMalloc::vfunc_7 (14 B): matches/0x00267250.cpp
// sym: ?vfunc_7@MemoryAllocatorMalloc@core@@UAEXPAX@Z
void core::MemoryAllocatorMalloc::vfunc_7(void* __p0) { void * p = (void *)__p0;

    FUN_002705b0(p);
}

namespace fn_f03133a3 {

// 0x00267260 core::MemoryAllocatorMalloc::vfunc_2 (31 B): matches/0x00267260.cpp
// sym: ?f2@NonCopyable_267260@pure3d@fn_f03133a3@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_267260* pure3d::NonCopyable_267260::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f03133a3
