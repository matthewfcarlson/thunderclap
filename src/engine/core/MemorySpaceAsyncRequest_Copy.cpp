// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00270370..0x00270610 (kind game, layer engine, confidence high), dominant class core::MemorySpaceAsyncRequest_Copy
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/game/unknown.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_ff2c3197 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff2c3197 {} using namespace fn_ff2c3197;
namespace fn_ff2c3197 { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/core.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, size_t);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
namespace fn_ff2c3197 {
class IRefCount_270400 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};
class MemorySpaceAsyncRequest_Copy {
  public:
    virtual ~MemorySpaceAsyncRequest_Copy();
    int value;
    MemorySpaceAsyncRequest_Copy();
};
void FUN_002705f0();
namespace pure3d {
class NonCopyable_2704f0 : public ::core::IMemorySpaceCopyRequest {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_2704f0* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable_2704f0*);
extern "C" void __stdcall FUN_00209f01(void*);
extern "C" void FUN_003479bc(void*);


// 0x00270370 FUN_00270370 (1 B): matches/0x00270370.cpp
// sym: _FUN_00270370
extern "C" void FUN_00270370() {}


// 0x00270380 FUN_00270380 (1 B): matches/0x00270380.cpp
// sym: _FUN_00270380
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_00270380() {}


// 0x00270390 FUN_00270390 (33 B): matches/0x00270390.cpp
// sym: _FUN_00270390
extern "C" void* __cdecl FUN_00270390(void* dest, void* param2, const void* src, void* param4, unsigned int count) {
    memcpy(dest, src, count);
    return dest;
}


// 0x002703c0 FUN_002703c0 (36 B): matches/0x002703c0.cpp
// sym: _FUN_002703c0
extern "C" void* __cdecl FUN_002703c0(void* dst, unsigned int a2, const void* src, unsigned int a4,
                                      unsigned int n) {
    memcpy(dst, src, n);
    return (void*)((hulk_intptr)((char*)&DAT_004cdb4c));
}

} // namespace fn_ff2c3197

// 0x00270400 core::MemorySpaceAsyncRequest_Copy::vfunc_0 (4 B): matches/0x00270400.cpp
// sym: ?vfunc_0@MemorySpaceAsyncRequest_Copy@core@@UAEXXZ
// Same code shape as 0x00018b30 (propagated; names are from that function)
void core::MemorySpaceAsyncRequest_Copy::vfunc_0() {
    ++this->f_04;
}


// 0x00270410 core::MemorySpaceAsyncRequest_Copy::vfunc_1 (4 B): matches/0x00270410.cpp
// sym: ?vfunc_1@MemorySpaceAsyncRequest_Copy@core@@UAEXXZ
// Same code shape as 0x00268590 (propagated; names are from that function)
 // namespace core
void core::MemorySpaceAsyncRequest_Copy::vfunc_1() {
    --this->f_04;
}


// 0x00270420 core::MemorySpaceAsyncRequest_Copy::vfunc_3 (3 B): matches/0x00270420.cpp
// sym: ?vfunc_3@MemorySpaceAsyncRequest_Copy@core@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool core::MemorySpaceAsyncRequest_Copy::vfunc_3() {
    return true;
}

namespace fn_ff2c3197 {

// 0x002704d0 FUN_002704d0 (25 B): matches/0x002704d0.cpp
// sym: ??0MemorySpaceAsyncRequest_Copy@fn_ff2c3197@@QAE@XZ
MemorySpaceAsyncRequest_Copy::MemorySpaceAsyncRequest_Copy() {
    value = 0;
    FUN_002705f0();
}


// 0x002704f0 core::MemorySpaceAsyncRequest_Copy::vfunc_2 (31 B): matches/0x002704f0.cpp
// sym: ?f2@NonCopyable_2704f0@pure3d@fn_ff2c3197@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_2704f0* pure3d::NonCopyable_2704f0::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00270510 FUN_00270510 (26 B): matches/0x00270510.cpp
// sym: _FUN_00270510
extern "C" void __cdecl FUN_00270510(void) {
    char local[32];
    FUN_00209f01(local);
    (*(int*)&DAT_00528410) = *(int*)(local + 12);
}


// 0x00270530 FUN_00270530 (1 B): matches/0x00270530.cpp
// sym: _FUN_00270530
extern "C" void FUN_00270530() {}


// 0x00270540 FUN_00270540 (22 B): matches/0x00270540.cpp
// sym: _FUN_00270540
extern "C" void* __cdecl FUN_00270540(unsigned int size) {
    if (size == 0)
        size = 1;
    return malloc(size);
}

// 0x00270560 thunk_FUN_003479bc (5 B): not yet verified

// 0x00270570 FUN_00270570 (54 B): matches/0x00270570.cpp
// sym: _FUN_00270570
// aligned allocate: the block malloc returned is kept in the pointer-sized word below the aligned address
extern "C" void* FUN_00270570(int size, unsigned alignment) {
    if (alignment < sizeof(void*))
        alignment = sizeof(void*);
    unsigned total = size + alignment;
    if (total == 0)
        total = 1;
    void* p = malloc(total);
    unsigned rem = (hulk_uintptr)p % alignment;
    hulk_uintptr q = (hulk_uintptr)p - rem + alignment;
    *(void**)(q - sizeof(void*)) = p;
    return (void*)q;
}


// 0x002705b0 FUN_002705b0 (21 B): matches/0x002705b0.cpp
// sym: ?FUN_002705b0@fn_ff2c3197@@YAXPAX@Z
// aligned free (0x00270570's blocks): frees the block kept below the aligned address
void FUN_002705b0(void* ptr) {
    if (ptr) {
        FUN_003479bc(*(void**)((char*)ptr - sizeof(void*)));
    }
}


// 0x002705d0 FUN_002705d0 (3 B): matches/0x002705d0.cpp
// sym: ?vfunc_2@ParamValue@fn_ff2c3197@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char ParamValue::vfunc_2() {
    return 0;
}


// 0x002705e0 FUN_002705e0 (6 B): matches/0x002705e0.cpp
// sym: ?FUN_002705e0@fn_ff2c3197@@YAHXZ
// Same code shape as 0x00085cd0 (propagated; names are from that function)
int FUN_002705e0(void) {
    return (*(int*)&DAT_00528410);
}

} // namespace fn_ff2c3197

// 0x002705f0 FUN_002705f0 (6 B): matches/0x002705f0.cpp [wrapped: conflict: FUN_002705f0]
// sym: _FUN_002705f0
namespace fn_002705f0 {
// Same code shape as 0x0008ceb0 (propagated; names are from that function)

extern "C" int* FUN_002705f0() {
    return &(*(int*)&DAT_0042b674);
}
} // namespace fn_002705f0

