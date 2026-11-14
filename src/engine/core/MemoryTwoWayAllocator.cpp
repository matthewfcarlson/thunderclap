// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0026cf60..0x0026d480 (kind game, layer engine, confidence high), dominant class core::MemoryTwoWayAllocator
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_ffa6521f {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ffa6521f {} using namespace fn_ffa6521f;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_ffa6521f {
struct Align_26cf60 {
    static hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr, unsigned int);
};
struct MemoryDlAllocator_nv_26cf60 {
    void* FUN_0026ce90(unsigned char, void*, int, const char*);
};
extern "C" void* FUN_00266e00(int, hulk_intptr);
struct MemoryDlAllocator_nv_26cfa0 {
    void* FUN_0026ce90(unsigned char, void*, int, const char*);
};
class RefCount {
  public:
    void* vftable;
    int mRef;
    void* mParam;
    RefCount(int x);
};
class Object_26d1e0 {
  public:
    virtual void vfunc_0();
};
class RefCount_26d1e0 : public Object_26d1e0 {
  public:
    int field;
    virtual RefCount_26d1e0* vfunc_0(unsigned char);
};
extern void __cdecl FUN_00266f00(int, RefCount_26d1e0*);
class IB_26d270 {
  public:
    void helper_0026d280();
};
class MemoryTwoWayAllocator_26d270 : public core::IMemoryTwoWayAllocator, public IB_26d270 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Y_26d280 {
  public:
    virtual void G(int);
    char pad[4];
    int count;
    void F();
};
class MemoryTwoWayAllocator {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual int vfunc_5(unsigned int);
    virtual void vfunc_6(unsigned int, unsigned int);
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual void _m_vf15();
    char _m_pad_4[0xc];
    unsigned int a;
    unsigned int b;
    void helper_0026d320(unsigned int, unsigned int);
};
typedef unsigned int uint_26d320;
extern "C" hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr, uint_26d320);
extern "C" hulk_uintptr __cdecl FUN_0026fd80(hulk_uintptr, uint_26d320);
class MemoryTwoWayAllocator_26d320 {
  public:
    char p[24];
    hulk_uintptr a, b, c, d, flag;
    hulk_uintptr f(uint_26d320 x, uint_26d320 y);
};
struct ThisCall_0026d320 {
    void FUN_0026d320(unsigned int, unsigned int);
};


// 0x0026cf60 FUN_0026cf60 (49 B): matches/0x0026cf60.cpp
// sym: ?FUN_0026cf60@fn_ffa6521f@@YAPAXPAXHPBD@Z
// 0x0026fd50 rounds a size up to an alignment (a class-scope declaration: the TU's C declaration of it is spelled
// with another source's typedef)
// a dl allocator placed at the start of [base, base + total): its arena is the rest
void* __cdecl FUN_0026cf60(void* base, int total, const char* name) {
    int size = (int)Align_26cf60::FUN_0026fd50(sizeof(core::MemoryDlAllocator), 4);
    if (base != 0)
        return ((MemoryDlAllocator_nv_26cf60*)base)->FUN_0026ce90(1, (char*)base + size, total - size, name);
    return 0;
}


// 0x0026cfa0 FUN_0026cfa0 (55 B): matches/0x0026cfa0.cpp
// sym: _FUN_0026cfa0
// data: gState_26cfa0 = DAT_004cdbb0
extern "C" void* FUN_0026cfa0(void* base, int size, int id, const char* name) {
    DAT_004cdbb0 = id;
    void* p = FUN_00266e00(id, sizeof(core::MemoryDlAllocator));
    if (p)
        return ((MemoryDlAllocator_nv_26cfa0*)p)->FUN_0026ce90(0, base, size, name);
    return 0;
}

} // namespace fn_ffa6521f

// 0x0026d0b0 core::MemoryTwoWayAllocator::vfunc_13 (10 B): matches/0x0026d0b0.cpp
// sym: ?vfunc_13@MemoryTwoWayAllocator@core@@UAEXH@Z
// Same code shape as 0x00083d70 (propagated; names are from that function)
void core::MemoryTwoWayAllocator::vfunc_13(int x) {
    this->f_28 = x;
}


// 0x0026d0c0 core::MemoryTwoWayAllocator::vfunc_14 (4 B): matches/0x0026d0c0.cpp
// sym: ?vfunc_14@MemoryTwoWayAllocator@core@@UAEIXZ
// Same code shape as 0x000862a0 (propagated; names are from that function)
unsigned int core::MemoryTwoWayAllocator::vfunc_14() {
    return (*(unsigned int *)&this->f_28);
}


// 0x0026d0d0 core::MemoryTwoWayAllocator::vfunc_15 (34 B): matches/0x0026d0d0.cpp
// sym: ?vfunc_15@MemoryTwoWayAllocator@core@@UAEXH@Z
void core::MemoryTwoWayAllocator::vfunc_15(int param) {
    if (param == 0) {
        this->f_18 = this->f_10;
        this->f_20 = 0;
    } else {
        this->f_1c = this->f_14;
        this->f_24 = 0;
    }
}


// 0x0026d100 core::MemoryTwoWayAllocator::vfunc_9 (79 B): matches/0x0026d100.cpp
// sym: ?vfunc_9@MemoryTwoWayAllocator@core@@UAE_NPAX000@Z
bool core::MemoryTwoWayAllocator::vfunc_9(void* __p0, void* __p1, void* __p2, void* __p3) { int * p = (int *)__p0; int * q = (int *)__p1; int * r = (int *)__p2; int * s = (int *)__p3;

    if (p)
        *p = this->f_1c - this->f_18;
    if (q)
        *q = this->f_1c - this->f_18;
    if (r)
        *r = this->f_24 + this->f_20;
    if (s)
        *s = ((this->f_18 - this->f_1c) - this->f_10) + this->f_14;
    return true;
}


// 0x0026d150 core::MemoryTwoWayAllocator::vfunc_11 (7 B): matches/0x0026d150.cpp
// sym: ?vfunc_11@MemoryTwoWayAllocator@core@@UAEHXZ
int core::MemoryTwoWayAllocator::vfunc_11() {
    return this->f_14 - this->f_10;
}

namespace fn_ffa6521f {

// 0x0026d1b0 FUN_0026d1b0 (46 B): matches/0x0026d1b0.cpp
// sym: ??0RefCount@fn_ffa6521f@@QAE@H@Z
// data: g_unknown_26d1b0 = DAT_004cdbb0
RefCount::RefCount(int x) {
    vftable = (void*)((hulk_intptr)DAT_0042afa8);
    mRef = DAT_004cdbb0;
    Init();
    vftable = (void*)((hulk_intptr)DAT_0042b3a4);
    mParam = (void*)x;
    Init();
}


// 0x0026d1e0 core::RefCount::vfunc_0 (46 B): matches/0x0026d1e0.cpp
// sym: ?vfunc_0@RefCount_26d1e0@fn_ffa6521f@@UAEPAV12@E@Z
// data: g_saved = DAT_004cdbb0
RefCount_26d1e0* RefCount_26d1e0::vfunc_0(unsigned char param) {
    (*(volatile int*)&DAT_004cdbb0) = field;
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042af64);
    if (param & 1)
        FUN_00266f00((*(volatile int*)&DAT_004cdbb0), this);
    return this;
}

} // namespace fn_ffa6521f

// 0x0026d210 FUN_0026d210 (66 B): matches/0x0026d210.cpp [wrapped: conflict: core::BaseObject; core::IRefCount; core::MemoryTwoWayAllocator]
// sym: ??1MemoryTwoWayAllocator@core@fn_0026d210@@UAE@XZ
namespace fn_0026d210 {

extern "C" void __cdecl FUN_00267090(void*);
namespace core {
struct IRefCount {
    virtual void Fnf_0026d260();
    ~IRefCount() {}
};
struct BaseObject {
    virtual void f();
    ~BaseObject() {}
};
struct Stamp {
    int unknown;
    ~Stamp() { DAT_004cdbb0 = unknown; }
};
struct Memory {
    void* memory;
    int a, b, c;
    ~Memory() {
        memory = 0;
        a = 0;
        b = 0;
        c = 0;
    }
};
struct MemoryTwoWayAllocator : IRefCount, BaseObject {
    Stamp stamp;
    int unknown2;
    Memory mem;
    virtual ~MemoryTwoWayAllocator();
};
} // namespace core
core::MemoryTwoWayAllocator::~MemoryTwoWayAllocator() {
    FUN_00267090(mem.memory);
}
} // namespace fn_0026d210


// 0x0026d260 core::MemoryTwoWayAllocator::vfunc_0 (4 B): matches/0x0026d260.cpp
// sym: ?vfunc_0@MemoryTwoWayAllocator@core@@UAEXXZ
// Same code shape as 0x00267ba0 (propagated; names are from that function)
void core::MemoryTwoWayAllocator::vfunc_0() {
    ++this->f_0c;
}

namespace fn_ffa6521f {

// 0x0026d270 core::MemoryTwoWayAllocator::vfunc_1 (8 B): matches/0x0026d270.cpp
// sym: ?vfunc_1@MemoryTwoWayAllocator_26d270@fn_ffa6521f@@UAEXXZ
void MemoryTwoWayAllocator_26d270::vfunc_1() {
    IB_26d270::helper_0026d280();
}


// 0x0026d280 FUN_0026d280 (19 B): matches/0x0026d280.cpp
// sym: ?F@Y_26d280@fn_ffa6521f@@QAEXXZ
void Y_26d280::F() {
    int* p = &count;
    *p = *p - 1;
    if (*p == 0) {
        *p = 0x5dc;
        G(1);
    }
}

} // namespace fn_ffa6521f

// 0x0026d2a0 core::MemoryTwoWayAllocator::vfunc_0_adj4 (8 B): matches/0x0026d2a0.cpp [wrapped: conflict: core::MemoryTwoWayAllocator]
// sym: ?vfunc_2@MemoryTwoWayAllocator@core@fn_0026d2a0@@W3AEXXZ
namespace fn_0026d2a0 {
namespace core {
class Primary {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class Secondary {
  public:
    virtual void vfunc_2();
};
class __declspec(dllexport) MemoryTwoWayAllocator : public Primary, public Secondary {
  public:
    virtual void vfunc_2();
};
void MemoryTwoWayAllocator::vfunc_2() {
    extern void action();
    action();
}
} // namespace core
} // namespace fn_0026d2a0

namespace fn_ffa6521f {

// 0x0026d2e0 core::MemoryTwoWayAllocator::vfunc_5 (27 B): matches/0x0026d2e0.cpp
// sym: ?vfunc_5@MemoryTwoWayAllocator@fn_ffa6521f@@UAEHI@Z
int MemoryTwoWayAllocator::vfunc_5(unsigned int x) {
    if (x >= a && x < b)
        return 1;
    return 0;
}

} // namespace fn_ffa6521f

// 0x0026d300 core::MemoryTwoWayAllocator::vfunc_8 (27 B): matches/0x0026d300.cpp [wrapped: same definition as 0x0026d2e0 in this TU]
// sym: ?vfunc_5@MemoryTwoWayAllocator@fn_0026d300@@UAEHI@Z
namespace fn_0026d300 {
// Same code shape as 0x0026d2e0 (propagated; names are from that function)
class MemoryTwoWayAllocator {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int vfunc_5(unsigned int);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    char pad[0x10 - 4];
    unsigned int a;
    unsigned int b;
};
int MemoryTwoWayAllocator::vfunc_5(unsigned int x) {
    if (x >= a && x < b)
        return 1;
    return 0;
}
} // namespace fn_0026d300

namespace fn_ffa6521f {

// 0x0026d320 FUN_0026d320 (94 B): matches/0x0026d320.cpp
// sym: ?f@MemoryTwoWayAllocator_26d320@fn_ffa6521f@@QAEIII@Z
hulk_uintptr MemoryTwoWayAllocator_26d320::f(uint_26d320 x, uint_26d320 y) {
    hulk_uintptr r;
    if (flag == 0) {
        r = FUN_0026fd50(a, y);
        if (r + x < b) {
            a = r + x;
            ++c;
            return r;
        }
    } else {
        r = FUN_0026fd80(b - x, y);
        if (r > a) {
            b = r;
            ++d;
            return r;
        }
    }
    return 0;
}

} // namespace fn_ffa6521f

// 0x0026d3a0 core::MemoryTwoWayAllocator::vfunc_2 (94 B): equivalent/0x0026d3a0.cpp [wrapped: conflict: core::BaseObject; core::IRefCount; core::MemoryTwoWayAllocator]
// sym: ?vfunc_2@MemoryTwoWayAllocator@core@fn_0026d3a0@@UAEPAU123@E@Z @a124b81b1181 @w61aea731c1ad
inline void* __cdecl operator new(size_t, void* storage) { return storage; }
namespace fn_0026d3a0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::MemoryTwoWayAllocator::vfunc_2 @ 0x0026d3a0

/* size_t: tree_prelude.h */

extern "C" void __cdecl FUN_00267090(void*);
extern "C++" void __cdecl FUN_00266f00(unsigned int, void*);
namespace core {
struct IRefCount { virtual void vfunc_0(); virtual void vfunc_1(); };
struct BaseObject { virtual void vfunc_0_adj4(); };
struct MemoryTwoWayAllocator : IRefCount, BaseObject {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual MemoryTwoWayAllocator* vfunc_2(unsigned char);
 virtual void vfunc_3_0026d410(int); virtual void vfunc_4_0026d420(void*); virtual int vfunc_5_0026d2e0(int); virtual void vfunc_6_0026d440(int, int); virtual void vfunc_7_0026d460(void*); virtual int vfunc_8_0026d300(int); virtual bool vfunc_9_0026d100(void*, void*, void*, void*); virtual void vfunc_10(); virtual void vfunc_11_0026d150(); virtual void vfunc_12_00267060(); virtual void vfunc_13_0026d0b0(int); virtual void vfunc_14_0026d0c0(); virtual void vfunc_15_0026d0d0(int);
 virtual void vfunc_0_adj4();
 unsigned int allocator, reserved; void* memory; unsigned int low, high, end;
};
MemoryTwoWayAllocator* MemoryTwoWayAllocator::vfunc_2(unsigned char flags) {
 void* block = memory;
 new (this) MemoryTwoWayAllocator;
 FUN_00267090(block);
 memory = 0; low = high = end = 0;
 (*(unsigned int*)&DAT_004cdbb0) = allocator;
 new (static_cast<BaseObject*>(this)) BaseObject;
 new (static_cast<IRefCount*>(this)) IRefCount;
 if (flags & 1) FUN_00266f00((*(unsigned int*)&DAT_004cdbb0), this);
 return this;
}
}
} // namespace fn_0026d3a0


// 0x0026d410 core::MemoryTwoWayAllocator::vfunc_3 (15 B): matches/0x0026d410.cpp
// sym: ?vfunc_3@MemoryTwoWayAllocator@core@@UAEXH@Z
void core::MemoryTwoWayAllocator::vfunc_3(int __p0) { unsigned int p = (unsigned int)__p0;

    ((ThisCall_0026d320*)(this))->FUN_0026d320(p, 4);
}


// 0x0026d420 core::MemoryTwoWayAllocator::vfunc_4 (25 B): matches/0x0026d420.cpp
// sym: ?vfunc_4@MemoryTwoWayAllocator@core@@UAEXPAX@Z
void core::MemoryTwoWayAllocator::vfunc_4(void* __p0) { hulk_uintptr n = (hulk_uintptr)__p0;

    if (n) {
        if (n < (*(unsigned int *)&this->f_1c))
            --this->f_20;
        else
            --this->f_24;
    }
}

namespace fn_ffa6521f {

// 0x0026d440 core::MemoryTwoWayAllocator::vfunc_6 (23 B): matches/0x0026d440.cpp
// sym: ?vfunc_6@MemoryTwoWayAllocator@fn_ffa6521f@@UAEXII@Z
void MemoryTwoWayAllocator::vfunc_6(unsigned int x, unsigned int y) {
    if (y <= 4)
        y = 4;
    helper_0026d320(x, y);
}

} // namespace fn_ffa6521f

// 0x0026d460 core::MemoryTwoWayAllocator::vfunc_7 (25 B): matches/0x0026d460.cpp
// sym: ?vfunc_7@MemoryTwoWayAllocator@core@@UAEXPAX@Z
// Same code shape as 0x0026d420 (propagated; names are from that function)
void core::MemoryTwoWayAllocator::vfunc_7(void* __p0) { hulk_uintptr n = (hulk_uintptr)__p0;

    if (n) {
        if (n < (*(unsigned int *)&this->f_1c))
            --this->f_20;
        else
            --this->f_24;
    }
}

