// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002e16f0..0x002e1920 (kind game, layer engine, confidence medium), dominant class pure3d::BoneMatrixList
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa9c7cf4 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa9c7cf4 {} using namespace fn_fa9c7cf4;
namespace fn_fa9c7cf4 { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fa9c7cf4 {
extern void* Alloc_0008d6d0(hulk_uintptr);
extern "C" void FUN_002e1440(void*, unsigned int, void*);
struct Mat_2e1750 {
    char d[64];
    void Init_0022b980();
};
class NonCopyable_2e1750 {
  public:
    NonCopyable_2e1750() { a = 0; }
    virtual void f0();
    int a;
};
class BoneMatrixList : public NonCopyable_2e1750 {
  public:
    BoneMatrixList(unsigned n);
    virtual void f0();
    Mat_2e1750* b;
    Mat_2e1750* c;
};
struct Mat_2e17c0 {
    char d[64];
};
void *__cdecl FUN_0008d6d0(unsigned int n);
struct MatVec {
    char pad0[8];
    Mat_2e17c0 *begin;
    Mat_2e17c0 *end;
};
namespace pure3d {
class BoneMatrixList {
public:
    BoneMatrixList(MatVec *src);
    virtual void f0_00018b30();
    int f4;
    Mat_2e17c0 *begin;
    Mat_2e17c0 *end;
};
}
extern "C" char DAT_0042fce4[];
extern "C" void __cdecl Release(void*);
class MatrixPaletteList {
  public:
    char pad[8];
    void* volatile p;
    void Destroy();
};
extern void* g_vftable_0042fcd4[];
} // namespace fn_fa9c7cf4
void operator delete(void*);
namespace fn_fa9c7cf4 {
class NonCopyable_2e18e0 {
  public:
    void* vptr;
};
class BoneMatrixList_2e18e0 : public NonCopyable_2e18e0 {
  public:
    char pad[4];
    void* m8;
    BoneMatrixList_2e18e0* f2(unsigned char flags);
};

} // namespace fn_fa9c7cf4

// 0x002e16f0 FUN_002e16f0 (95 B): matches/0x002e16f0.cpp
// sym: ?FUN_002e16f0@Buffer_2e16f0@owners@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool owners::Buffer_2e16f0::FUN_002e16f0(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            FUN_002e1440(p, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}

namespace fn_fa9c7cf4 {

// 0x002e1750 FUN_002e1750 (104 B): matches/0x002e1750.cpp
// sym: ??0BoneMatrixList@fn_fa9c7cf4@@QAE@I@Z
BoneMatrixList::BoneMatrixList(unsigned n) {
    if (n > 0 && (b = (Mat_2e1750*)Alloc_0008d6d0(n * 64)) != 0) {
        c = b + n;
    } else {
        b = 0;
        c = 0;
    }
    for (unsigned i = 0; i < n; i++)
        b[i].Init_0022b980();
}


// 0x002e17c0 FUN_002e17c0 (117 B): equivalent/0x002e17c0.cpp
// sym: ??0BoneMatrixList@pure3d@fn_fa9c7cf4@@QAE@PAUMatVec@2@@Z @bada2f6a719c @w95fb3f2fe9f9
// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 8/8)
// FUN_002e17c0 @ 0x002e17c0
pure3d::BoneMatrixList::BoneMatrixList(MatVec *src)
{
    f4 = 0;
    hulk_uintptr n = src->end - src->begin;
    if (n != 0) {
        hulk_uintptr bytes = n * 64;
        begin = (Mat_2e17c0 *)FUN_0008d6d0(bytes);
        if (begin != 0) {
            end = (Mat_2e17c0 *)((char *)begin + bytes);
        } else {
            begin = 0;
            end = 0;
        }
    } else {
        begin = 0;
        end = 0;
    }
    n = src->end - src->begin;
    for (unsigned int i = 0; i < n; i++)
        begin[i] = src->begin[i];
}

} // namespace fn_fa9c7cf4

// 0x002e1840 FUN_002e1840 (33 B): matches/0x002e1840.cpp [wrapped: conflict: BoneMatrixList]
// sym: ?Destroy@BoneMatrixList@fn_002e1840@@QAEXXZ
namespace fn_002e1840 {
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042fcd4[];
extern "C" void _ReadWriteBarrier();
extern void __cdecl ReleaseThing_0008d340(void*);
struct BoneMatrixList {
    void* vptr;
    char pad[4];
    void* item;
    void Destroy();
};
void BoneMatrixList::Destroy() {
    *(volatile void**)&vptr = (void*)((hulk_intptr)DAT_0042fcd4);
    _ReadWriteBarrier();
    void* p = *(void* volatile*)&item;
    if (p)
        ReleaseThing_0008d340(p);
    vptr = (void*)((hulk_intptr)DAT_003f6098);
}
} // namespace fn_002e1840

namespace fn_fa9c7cf4 {

// 0x002e1890 FUN_002e1890 (33 B): matches/0x002e1890.cpp
// sym: ?Destroy@MatrixPaletteList@fn_fa9c7cf4@@QAEXXZ
void MatrixPaletteList::Destroy() {
    *(volatile hulk_ulongptr*)this = ((hulk_intptr)DAT_0042fce4);
    void* q = p;
    if (q)
        Release(q);
    *(volatile hulk_ulongptr*)this = ((hulk_intptr)DAT_003f6098);
}

} // namespace fn_fa9c7cf4

// 0x002e18c0 FUN_002e18c0 (27 B): matches/0x002e18c0.cpp
// sym: ?FUN_002e18c0@Object_2e18c0@owners@@QAEHH@Z
int owners::Object_2e18c0::FUN_002e18c0(int value) {
    int output = 0;
    return FUN_002e16f0(value, &output);
}

namespace fn_fa9c7cf4 {

// 0x002e18e0 pure3d::BoneMatrixList::vfunc_2 (53 B): matches/0x002e18e0.cpp
// sym: ?f2@BoneMatrixList_2e18e0@fn_fa9c7cf4@@QAEPAV12@E@Z
BoneMatrixList_2e18e0* BoneMatrixList_2e18e0::f2(unsigned char flags) {
    vptr = g_vftable_0042fcd4;
    _ReadWriteBarrier();
    if (m8)
        operator delete[](m8);
    vptr = (void**)DAT_003f6098;
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fa9c7cf4
