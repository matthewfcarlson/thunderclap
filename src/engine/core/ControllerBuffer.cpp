// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00270610..0x002708c0 (kind game, layer engine, confidence high), dominant class core::ControllerBuffer
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_fd2c7460 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fd2c7460 {} using namespace fn_fd2c7460;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fd2c7460 {
class IRefCount {
  public:
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual ~IRefCount() throw() {}
};
class BaseObject {
  public:
    virtual ~BaseObject() throw() {}
};
class ControllerBuffer : public IRefCount, public BaseObject {
  public:
    int mUnk8;
    char pad_C[4];
    int mUnk10;
    char pad_24[0x10];
    int mUnk24;
    int mUnk28;

    ~ControllerBuffer() throw();
};
extern "C" void __cdecl FUN_00266f00(int, int);
class ControllerBuffer_270670 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[8];
    int mRefCount;
};
typedef unsigned int u32_2706a0;
extern void Free_00266f00(void*, void*);
extern "C" void* FUN_00266e00(void*, u32_2706a0);
} // namespace fn_fd2c7460
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_fd2c7460 {
typedef unsigned int uint_270790;
} // namespace fn_fd2c7460
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, uint_270790);
#endif

namespace fn_fd2c7460 {

// 0x00270610 FUN_00270610 (69 B): matches/0x00270610.cpp
// sym: ??1ControllerBuffer@fn_fd2c7460@@UAE@XZ
// data: g_Global_4CDBB0 = DAT_004cdbb0
ControllerBuffer::~ControllerBuffer() throw() {
    int a = mUnk10;
    int b = mUnk28;
    FUN_00266f00(b, a);

    int c = mUnk24;
    int d = mUnk28;
    FUN_00266f00(d, c);

    DAT_004cdbb0 = mUnk8;
}

} // namespace fn_fd2c7460

// 0x00270660 core::ControllerBuffer::vfunc_0 (4 B): matches/0x00270660.cpp
// sym: ?vfunc_0@ControllerBuffer@core@@UAEXXZ
// Same code shape as 0x00267ba0 (propagated; names are from that function)
void core::ControllerBuffer::vfunc_0() {
    ++this->f_0c;
}

namespace fn_fd2c7460 {

// 0x00270670 core::ControllerBuffer::vfunc_1 (13 B): matches/0x00270670.cpp
// sym: ?f1@ControllerBuffer_270670@fn_fd2c7460@@UAEXXZ
// Same code shape as 0x00267bb0 (propagated; names are from that function)
void ControllerBuffer_270670::f1() {
    if (--mRefCount == 0)
        f2(1);
}

} // namespace fn_fd2c7460

// 0x00270680 core::ControllerBuffer::vfunc_3 (20 B): matches/0x00270680.cpp
// sym: ?vfunc_3@ControllerBuffer@core@@UAEXHH@Z
void core::ControllerBuffer::vfunc_3(int a, int b) {
    (*(int *)&this->f_18) = b;
    vfunc_4(a);
}


// 0x002706a0 core::ControllerBuffer::vfunc_4 (156 B): matches/0x002706a0.cpp
// sym: ?vfunc_4@ControllerBuffer@core@@UAEXH@Z
void core::ControllerBuffer::vfunc_4(int __p0) { u32_2706a0 n = (u32_2706a0)__p0;

    if ((*(u32_2706a0 *)&this->f_14) == n)
        return;
    if ((*(void * *)&this->f_10) && (*(void * *)&this->f_24)) {
        Free_00266f00((*(void * *)&this->f_28), (*(void * *)&this->f_10));
        Free_00266f00((*(void * *)&this->f_28), (*(void * *)&this->f_24));
    }
    (*(u32_2706a0 *)&this->f_14) = n;
    (*(void * *)&this->f_10) = FUN_00266e00((*(void * *)&this->f_28), (*(u32_2706a0 *)&this->f_18) * n);
    (*(void * *)&this->f_24) = FUN_00266e00((*(void * *)&this->f_28), (*(u32_2706a0 *)&this->f_14) * 4);
    for (u32_2706a0 i = 0; i < (*(u32_2706a0 *)&this->f_14); ++i)
        ((void**)(*(void * *)&this->f_24))[i] = (char*)(*(void * *)&this->f_10) + (*(u32_2706a0 *)&this->f_18) * i;
    (*(u32_2706a0 *)&this->f_1c) = 0;
    (*(u32_2706a0 *)&this->f_20) = 0;
}


// 0x00270740 core::ControllerBuffer::vfunc_5 (70 B): matches/0x00270740.cpp
// sym: ?vfunc_5@ControllerBuffer@core@@UAEIPAX@Z
unsigned int core::ControllerBuffer::vfunc_5(void* __p0) { const void * src = (const void *)__p0;

    memcpy((void*)(*(unsigned int * *)&this->f_24)[this->f_20], src, this->f_18);
    unsigned int n = (this->f_20 + 1) % this->f_14;
    unsigned int r = this->f_1c;
    this->f_20 = n;
    if (n == r) {
        r = r + 1;
        this->f_1c = r % this->f_14;
        return r / this->f_14;
    }
    return r;
}


// 0x00270790 core::ControllerBuffer::vfunc_6 (52 B): matches/0x00270790.cpp
// sym: ?vfunc_6@ControllerBuffer@core@@UAE_NHH@Z
bool core::ControllerBuffer::vfunc_6(hulk_intptr __p0, int __p1) { void * dst = (void *)__p0; uint_270790 size = (uint_270790)__p1;

    if ((*(int *)&this->f_1c) == (*(int *)&this->f_20))
        return false;
    memcpy(dst, (*(char ** *)&this->f_24)[(*(int *)&this->f_1c)], size);
    return true;
}


// 0x002707d0 core::ControllerBuffer::vfunc_7 (66 B): matches/0x002707d0.cpp
// sym: ?vfunc_7@ControllerBuffer@core@@UAE_NPAX@Z
bool core::ControllerBuffer::vfunc_7(void* __p0) { void * output = (void *)__p0;

    if (this->f_1c == this->f_20)
        return false;
    memcpy(output, (void*)(*(unsigned int * *)&this->f_24)[this->f_1c], this->f_18);
    this->f_1c = (this->f_1c + 1) % this->f_14;
    return true;
}


// 0x00270820 core::ControllerBuffer::vfunc_8 (9 B): matches/0x00270820.cpp
// sym: ?vfunc_8@ControllerBuffer@core@@UAEXXZ
void core::ControllerBuffer::vfunc_8() {
    (*(int *)&this->f_1c) = 0;
    (*(int *)&this->f_20) = 0;
}


// 0x00270830 core::ControllerBuffer::vfunc_0_adj4 (8 B): matches/0x00270830.cpp [wrapped: conflict: core::ControllerBuffer; core::IControllerBuffer; core::IRefCount]
// sym: ?f2@ControllerBuffer@core@fn_00270830@@W3AEXXZ
namespace fn_00270830 {
namespace core {
void external();
class IControllerBuffer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class IRefCount {
  public:
    virtual void f2();
};
class ControllerBuffer : public IControllerBuffer, public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
ControllerBuffer obj;
void ControllerBuffer::f2() {
    external();
}
} // namespace core
} // namespace fn_00270830


// 0x00270840 core::ControllerBuffer::vfunc_2 (97 B): equivalent/0x00270840.cpp [wrapped: conflict: core::ControllerBuffer]
// sym: ?vfunc_2@ControllerBuffer@core@fn_00270840@@QAEPAU123@E@Z @cdae33217425 @wabcbd6077bb7
namespace fn_00270840 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::ControllerBuffer::vfunc_2 @ 0x00270840

void __cdecl FUN_00266f00(void*, void*);
extern void* DAT_0042b688[];
extern void* DAT_0042b680[];
extern void* DAT_0042af64[];
extern void* DAT_003f6098[];
namespace core {
struct ControllerBuffer {
 void** vtable;
 void** baseVtable;
 void* owner;
 char unusedC[4];
 void* first;
 char unused14[16];
 void* second;
 void* context;
 ControllerBuffer* vfunc_2(unsigned char flags);
};
ControllerBuffer* ControllerBuffer::vfunc_2(unsigned char flags) {
 void* firstValue = first;
 void* contextValue = context;
 vtable = DAT_0042b688;
 baseVtable = DAT_0042b680;
 FUN_00266f00(contextValue, firstValue);
 FUN_00266f00(context, second);
 (*(void**)&DAT_004cdbb0) = owner;
 baseVtable = DAT_0042af64;
 vtable = DAT_003f6098;
 if (flags & 1) FUN_00266f00((*(void**)&DAT_004cdbb0), this);
 return this;
}
}
} // namespace fn_00270840

