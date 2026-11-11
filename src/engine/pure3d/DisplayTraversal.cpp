// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c6a80..0x002c6d30 (kind game, layer engine, confidence medium), dominant class pure3d::DisplayTraversal
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fa8bb1a6 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa8bb1a6 {} using namespace fn_fa8bb1a6;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fa8bb1a6 {
extern void* gVtable_2c6a80;
extern "C" char DAT_0042ef74[];
class Ref_2c6ad0 {
  public:
    virtual void F0();
    virtual void Release();
};
class DisplayTraversal {
  public:
    DisplayTraversal();
    union { volatile hulk_intptr vf; void* vptr; };
    int a;
    unsigned char flag;
    char _m_pad_9[0x3];
    int c;
    int d;
    union { int e; Ref_2c6ad0* volatile mRef; };
    DisplayTraversal* F2(unsigned int);
};
extern void Destroy(DisplayTraversal*);


// 0x002c6a80 FUN_002c6a80 (31 B): matches/0x002c6a80.cpp
// sym: ??0DisplayTraversal@fn_fa8bb1a6@@QAE@XZ
DisplayTraversal::DisplayTraversal() {
    a = 0;
    vptr = &gVtable_2c6a80;
    flag = 1;
    c = -1;
    d = 0;
    e = 0;
}

} // namespace fn_fa8bb1a6

// 0x002c6aa0 FUN_002c6aa0 (36 B): matches/0x002c6aa0.cpp [wrapped: conflict: DisplayTraversal]
// sym: ?Fn@DisplayTraversal@fn_002c6aa0@@QAEXXZ
namespace fn_002c6aa0 {
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042ef74[];
extern "C" void _ReadWriteBarrier();
class IRefCount {
  public:
    virtual void A();
    virtual void Release();
};
class DisplayTraversal {
  public:
    volatile int* vptr;
    char pad[16];
    IRefCount* mRef;
    void Fn();
};
void DisplayTraversal::Fn() {
    vptr = (volatile int*)((hulk_intptr)DAT_0042ef74);
    _ReadWriteBarrier();
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    vptr = (volatile int*)((hulk_intptr)DAT_003f6098);
}
} // namespace fn_002c6aa0

namespace fn_fa8bb1a6 {

// 0x002c6ad0 pure3d::DisplayTraversal::vfunc_2 (56 B): matches/0x002c6ad0.cpp
// sym: ?F2@DisplayTraversal@fn_fa8bb1a6@@QAEPAV12@I@Z
DisplayTraversal* DisplayTraversal::F2(unsigned int flags) {
    vf = ((hulk_intptr)DAT_0042ef74);
    Ref_2c6ad0* r = mRef;
    if (r) {
        r->Release();
        mRef = 0;
    }
    vf = ((hulk_intptr)DAT_003f6098);
    if (flags & 1)
        Destroy(this);
    return this;
}

} // namespace fn_fa8bb1a6
