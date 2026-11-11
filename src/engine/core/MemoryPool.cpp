// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0026fd50..0x00270370 (kind game, layer engine, confidence high), dominant class core::MemoryPool
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#include "gen/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4a2a4cd {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f4a2a4cd {} using namespace fn_f4a2a4cd;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f4a2a4cd {
typedef unsigned int uint_26fd80;
class MemPoolParent {
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
    virtual char Stats(int* a, int* b, int* c, int* d);
};
class IMemoryPool_26ff40 {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
    virtual int vfunc_11();
    virtual int f12();
    virtual int f13();
    virtual int f14();
};
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042b5ac[];
extern "C" char DAT_0042b5b4[];
class Ref_26ff90 {
  public:
    virtual void X();
    virtual void A();
};
extern "C" void FUN_00266f20(int, void*);
class MemoryPool_26ff90 : public CoreMemoryPool {
  public:
    void Destroy();
};
class IB_270000 {
  public:
    void FUN_0026d280();
};
class MemoryPool_270000 : public core::IMemoryPool, public IB_270000 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class PoolOther {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void*);
};
typedef unsigned char u8_270130;
extern "C" void __cdecl FUN_00266f00(int, void*);
class MemoryPool_270130 {
  public:
    void FUN_0026ff90();
    virtual void f0();
    virtual void f1();
    virtual MemoryPool_270130* f2(u8_270130);
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
extern "C" char DAT_0042b5f4[];
void FUN_002705f0();
class MemoryPool_270170 : public CoreMemoryPool {
  public:
    MemoryPool_270170();
};
} // namespace fn_f4a2a4cd
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char*, const char*, ...);
#endif
namespace fn_f4a2a4cd {
extern "C" void* FUN_00266e00(int a, int b);
} // namespace fn_f4a2a4cd
inline void* operator new(size_t, void* p) { return p; }
namespace fn_f4a2a4cd {
class FUN_00270170 : public CoreMemoryPool {
  public:
    FUN_00270170();
};
class Obj_2702a0 {
  public:
    virtual void Finish();
};


// 0x0026fd50 FUN_0026fd50 (35 B): matches/0x0026fd50.cpp
// sym: _FUN_0026fd50
extern "C" hulk_uintptr FUN_0026fd50(hulk_uintptr value, unsigned int alignment) {
    if (alignment != 0 && value % alignment != 0)
        return (value - value % alignment) + alignment;
    return value;
}


// 0x0026fd80 FUN_0026fd80 (20 B): matches/0x0026fd80.cpp
// sym: _FUN_0026fd80
extern "C" hulk_uintptr FUN_0026fd80(hulk_uintptr value, uint_26fd80 alignment) {
    if (alignment != 0)
        value = (value / alignment) * alignment;
    return value;
}

} // namespace fn_f4a2a4cd

// 0x0026fe00 core::MemoryPool::vfunc_3 (8 B): matches/0x0026fe00.cpp
// sym: ?vfunc_3@MemoryPool@core@@UAEXH@Z
void core::MemoryPool::vfunc_3(int ) {
    vfunc_13();
}


// 0x0026fe10 core::MemoryPool::vfunc_6 (5 B): matches/0x0026fe10.cpp
// sym: ?vfunc_6@MemoryPool@core@@UAEHPAXH@Z
 // namespace core
int core::MemoryPool::vfunc_6(void* __p0, int ) {
    return 0;
}


// 0x0026fe20 core::MemoryPool::vfunc_7 (3 B): matches/0x0026fe20.cpp
// sym: ?vfunc_7@MemoryPool@core@@UAEXPAX@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void core::MemoryPool::vfunc_7(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    (void)a;
}


// 0x0026fe30 core::MemoryPool::vfunc_8 (5 B): matches/0x0026fe30.cpp
// sym: ?vfunc_8@MemoryPool@core@@UAE_NPAX@Z
// Same code shape as 0x00244f40 (propagated; names are from that function)
bool core::MemoryPool::vfunc_8(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    return false;
}


// 0x0026fe40 core::MemoryPool::vfunc_14 (108 B): matches/0x0026fe40.cpp
// sym: ?vfunc_14@MemoryPool@core@@UAEXPAX00@Z
void core::MemoryPool::vfunc_14(void* __p0, void* __p1, void* __p2) { int * p = (int *)__p0; int * q = (int *)__p1; int * r = (int *)__p2;

    if (p)
        *p = 0;
    if (q)
        *q = 0;
    if (r)
        *r = 0;
    if ((*(core::MemoryPool * *)&this->f_30))
        (*(core::MemoryPool * *)&this->f_30)->vfunc_14(p, q, r);
    if (p)
        *p += this->f_1c;
    if (q)
        *q += this->f_20 - this->f_28;
    if (r)
        *r += this->f_28;
}


// 0x0026feb0 core::MemoryPool::vfunc_9 (142 B): matches/0x0026feb0.cpp
// sym: ?vfunc_9@MemoryPool@core@@UAE_NPAX000@Z
bool core::MemoryPool::vfunc_9(void* __p0, void* __p1, void* __p2, void* __p3) { int * a = (int *)__p0; int * b = (int *)__p1; int * c = (int *)__p2; int * d = (int *)__p3;

    if (a)
        *a = 0;
    if (b)
        *b = 0;
    if (c)
        *c = 0;
    if (d)
        *d = 0;
    if ((*(MemPoolParent * *)&this->f_30))
        (*(MemPoolParent * *)&this->f_30)->Stats(a, b, c, d);
    if (a)
        *a += (this->f_20 - this->f_28) * this->f_1c;
    if (b)
        *b += this->f_1c;
    if (c)
        *c += this->f_28;
    if (d)
        *d += this->f_2c * this->f_1c;
    return (bool)(1);
}


// 0x0026ff40 core::MemoryPool::vfunc_11 (8 B): matches/0x0026ff40.cpp
// sym: ?vfunc_11@MemoryPool@core@@UAEHXZ
int core::MemoryPool::vfunc_11() {
    return this->f_20 * this->f_1c;
}

namespace fn_f4a2a4cd {

// 0x0026ff90 FUN_0026ff90 (86 B): matches/0x0026ff90.cpp
// sym: ?Destroy@MemoryPool_26ff90@fn_f4a2a4cd@@QAEXXZ
// data: g_value_26ff90 = DAT_004cdbb0
void MemoryPool_26ff90::Destroy() {
    Ref_26ff90* p = (Ref_26ff90*)child;
    vftable = DAT_0042b5b4;
    object.vftable = DAT_0042b5ac;
    if (p) {
        p->A();
        child = 0;
    }
    if (heap >= 0)
        FUN_00266f20(heap, blocks);
    *(char* volatile*)&blocks = 0;
    DAT_004cdbb0 = *(volatile int*)&object.heap;
    object.vftable = DAT_0042af64;
    vftable = DAT_003f6098;
}

} // namespace fn_f4a2a4cd

// 0x0026fff0 core::MemoryPool::vfunc_0 (4 B): matches/0x0026fff0.cpp
// sym: ?vfunc_0@MemoryPool@core@@UAEXXZ
// Same code shape as 0x00267ba0 (propagated; names are from that function)
void core::MemoryPool::vfunc_0() {
    ++this->f_0c;
}

namespace fn_f4a2a4cd {

// 0x00270000 core::MemoryPool::vfunc_1 (8 B): matches/0x00270000.cpp
// sym: ?vfunc_1@MemoryPool_270000@fn_f4a2a4cd@@UAEXXZ
// Same code shape as 0x0026d270 (propagated; names are from that function)
void MemoryPool_270000::vfunc_1() {
    IB_270000::FUN_0026d280();
}

} // namespace fn_f4a2a4cd

// 0x00270010 core::MemoryPool::vfunc_0_adj4 (8 B): matches/0x00270010.cpp [wrapped: conflict: core::IMemoryAllocator; core::IMemoryPool; core::MemoryPool]
// sym: ?vfunc_2@MemoryPool@core@fn_00270010@@W3AEXXZ
namespace fn_00270010 {
namespace core {
class IMemoryPool {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class IMemoryAllocator {
  public:
    virtual void vfunc_2();
};
class MemoryPool : public IMemoryPool, public IMemoryAllocator {
  public:
    virtual void vfunc_2();
};
extern void work(MemoryPool*);
void MemoryPool::vfunc_2() {
    work(this);
}
MemoryPool instance;
} // namespace core
} // namespace fn_00270010


// 0x002700b0 core::MemoryPool::vfunc_4 (62 B): matches/0x002700b0.cpp
// sym: ?vfunc_4@MemoryPool@core@@UAEXPAX@Z
void core::MemoryPool::vfunc_4(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    hulk_uintptr a = (hulk_uintptr)p;
    hulk_uintptr b = this->f_18;
    if (a >= b && a < (*(unsigned int *)&this->f_20) * (*(unsigned int *)&this->f_1c) + b) {
        *(hulk_uintptr*)p = (hulk_uintptr)(*(unsigned int * *)&this->f_10);
        (*(unsigned int * *)&this->f_10) = p;
        --this->f_28;
        return;
    }
    if ((*(PoolOther * *)&this->f_30))
        (*(PoolOther * *)&this->f_30)->f4(p);
    --this->f_28;
}


// 0x002700f0 core::MemoryPool::vfunc_5 (54 B): matches/0x002700f0.cpp
// sym: ?vfunc_5@MemoryPool@core@@UAE_NPAX@Z
// core::MemoryPool::vfunc_5: does the address lie in this pool's block (or a child pool's)
bool core::MemoryPool::vfunc_5(void* __p0) {
    hulk_uintptr p = (hulk_uintptr)__p0;
    hulk_uintptr s = this->f_18;
    if (p >= s && p < this->f_20 * this->f_1c + s)
        return true;
    if (this->f_30)
        return ((core::MemoryPool*)this->f_30)->vfunc_5((void*)p);
    return false;
}

namespace fn_f4a2a4cd {

// 0x00270130 core::MemoryPool::vfunc_2 (36 B): matches/0x00270130.cpp
// sym: ?f2@MemoryPool_270130@fn_f4a2a4cd@@UAEPAV12@E@Z
// Same code shape as 0x00269560 (propagated; names are from that function)
// data: globalValue = DAT_004cdbb0
MemoryPool_270130* MemoryPool_270130::f2(u8_270130 flag) {
    FUN_0026ff90();
    if (flag & 1)
        FUN_00266f00(DAT_004cdbb0, this);
    return this;
}


// 0x00270170 FUN_00270170 (84 B): matches/0x00270170.cpp
// sym: ??0MemoryPool_270170@fn_f4a2a4cd@@QAE@XZ
// data: g_unknown_270170 = DAT_004cdbb0
MemoryPool_270170::MemoryPool_270170() {
    vftable = DAT_0042b5f4;
    object.vftable = DAT_0042afa8;
    object.heap = DAT_004cdbb0;
    FUN_002705f0();
    object.vftable = DAT_0042b3a4;
    refs = 0;
    FUN_002705f0();
    vftable = DAT_0042b5b4;
    object.vftable = DAT_0042b5ac;
    blocks = 0;
    child = 0;
    FUN_002705f0();
}

} // namespace fn_f4a2a4cd

// 0x002701d0 core::MemoryPool::vfunc_13 (193 B): matches/0x002701d0.cpp
// sym: ?vfunc_13@MemoryPool@core@@UAEPAXXZ
void* core::MemoryPool::vfunc_13() {
    char buf[0x80];
    if (!(*(unsigned int * *)&this->f_10)) {
        if (!(*(core::MemoryPool * *)&this->f_30) && this->f_24 > 0) {
            int a = this->f_14;
            DAT_004cdbb0 = a;
            HULK_SIZE32(FUN_00270170, 0x34);
            void* p = FUN_00266e00(a, (int)sizeof(FUN_00270170));
            (*(core::MemoryPool * *)&this->f_30) = p ? (core::MemoryPool*)new (p) FUN_00270170 : 0;
            if ((*(core::MemoryPool * *)&this->f_30)) {
                sprintf(buf, "child of %8.8X[MemoryPool]", this);
                (*(owners::Pool_270020 * *)&this->f_30)->FUN_00270020(0, (*(unsigned int *)&this->f_1c), this->f_24, this->f_24, (void*)(hulk_uintptr)this->f_14, (hulk_uintptr)buf, 1);
                (*(core::MemoryPool * *)&this->f_30)->vfunc_0();
            }
        }
        if ((*(core::MemoryPool * *)&this->f_30))
            return (void*)((*(core::MemoryPool * *)&this->f_30)->vfunc_13());
        return (void*)(0);
    }
    unsigned* p = (*(unsigned int * *)&this->f_10);
    (*(unsigned int * *)&this->f_10) = (unsigned*)*(hulk_uintptr*)p;
    (*(unsigned int *)&this->f_28)++;
    (*(unsigned int *)&this->f_2c) = (*(unsigned int *)&this->f_28) > (*(unsigned int *)&this->f_2c) ? (*(unsigned int *)&this->f_28) : (*(unsigned int *)&this->f_2c);
    return (void*)(p);
}

namespace fn_f4a2a4cd {

// 0x002702a0 FUN_002702a0 (90 B): matches/0x002702a0.cpp
// sym: ?Target@fn_f4a2a4cd@@YAXPAPAVObj_2702a0@1@HHHHHH@Z
void Target(Obj_2702a0** out, int a, int b, int c, int d, hulk_intptr e, int f) {
    DAT_004cdbb0 = d;
    HULK_SIZE32(FUN_00270170, 0x34);
    void* p = FUN_00266e00(d, (int)sizeof(FUN_00270170));
    Obj_2702a0* obj;
    if (p)
        obj = (Obj_2702a0*)new (p) FUN_00270170;
    else
        obj = 0;
    ((owners::Pool_270020 *)obj)->FUN_00270020((void *)(hulk_uintptr)(int)0, (unsigned)a, (unsigned)b, (unsigned)c, (void *)(hulk_uintptr)(int)d, (hulk_uintptr)e, (unsigned)f);
    obj->Finish();
    *out = obj;
}

} // namespace fn_f4a2a4cd
