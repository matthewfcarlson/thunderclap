// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a9cb0..0x002aa160 (kind game, layer engine, confidence high), dominant class pure3d::ExpressionAnimationController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ff685ee7 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_ff685ee7 {} using namespace fn_ff685ee7;
#include "engine/pure3d.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_ff685ee7 {
class SimpleFrameController_2a9cb0 {
  public:
    virtual void f();
    char pad[0x3c];
    SimpleFrameController_2a9cb0();
};
class ExpressionAnimationController : public SimpleFrameController_2a9cb0 {
  public:
    virtual void _m_vf1();
    ExpressionAnimationController();
    int a;
    int b;
    int c;
    int d;
    ExpressionAnimationController* vfunc_2(int flag);
};
extern void* hulk_at_0042df6c[];
class Ref_2a9de0 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
struct ExpressionAnimationController_nv_2a9de0 {
    void Fn_00285800();
};
class ExpressionAnimationController_2a9de0 {
  public:
    void* vptr;
    char p[0x3c];
    Ref_2a9de0* m40;
    Ref_2a9de0* m44;
    char p48[4];
    void* m4c;
    void f();
};
struct Elem_2a9e30 {
    int FUN_002afe80(void* key);
};
struct Anim_2a9e30 {
    char pad00[0x1c];
    int tag;
    char pad20[8];
    int count;
};
struct Inner_2a9e30 {
    char pad[0x10];
    Elem_2a9e30* elem;
};
void __cdecl thunk_FUN_00267090(void *p);
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);
class Source_2a9ea0 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x10];
    int *begin;
    int *end;
};
class ExpressionAnimationController_2a9ea0 {
public:
    char pad00[0x40];
    Source_2a9ea0 *source;
    char pad44[4];
    hulk_intptr count;
    int *values;
    void FUN_002a9ea0(Source_2a9ea0 *src);
};
class Ref_2a9f30 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_2a9f30 {
    char pad[0x44];
    Ref_2a9f30* mRef;

  public:
    void Set(class Source_2a9f30*);
};
class Source_2a9f30 {
  public:
    char pad[0x68];
    Ref_2a9f30* mRef;
};
extern char gVftable_2aa000[];
extern void __cdecl freefn_0008d340(void*);
extern void __cdecl opdel_00263f30(void*);
class RefObj_2aa000 {
  public:
    virtual void f0();
    virtual void Release();
};
class ExpressionAnimationController_2aa000 {
  public:
    void BaseDtor_00285800();
};
extern void* __cdecl alloc_00263ea0(hulk_uintptr);
} // namespace fn_ff685ee7
inline void* operator new(size_t, void* where) {
    return where;
}
namespace fn_ff685ee7 {
class SimpleFrameController_2aa0a0 {
  public:
    SimpleFrameController_2aa0a0(void* parent);
    virtual void b0();
    char pad[0x3c];
};
class ExpressionAnimationController_2aa0a0 : public SimpleFrameController_2aa0a0 {
  public:
    ExpressionAnimationController_2aa0a0(void* parent) : SimpleFrameController_2aa0a0(parent) {
        m[0] = 0;
        m[1] = 0;
        m[2] = 0;
        m[3] = 0;
    }
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual ExpressionAnimationController_2aa0a0* f4();
    void Fng_002a9ea0(int v);
    int m[4];
};


// 0x002a9cb0 FUN_002a9cb0 (32 B): matches/0x002a9cb0.cpp
// sym: ??0ExpressionAnimationController@fn_ff685ee7@@QAE@XZ
ExpressionAnimationController::ExpressionAnimationController() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
}

} // namespace fn_ff685ee7

// 0x002a9cd0 pure3d::ExpressionAnimationController::vfunc_3 (3 B): matches/0x002a9cd0.cpp
// sym: ?vfunc_3@ExpressionAnimationController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ExpressionAnimationController::vfunc_3() {
    return true;
}

namespace fn_ff685ee7 {

// 0x002a9de0 FUN_002a9de0 (67 B): matches/0x002a9de0.cpp
// sym: ?f@ExpressionAnimationController_2a9de0@fn_ff685ee7@@QAEXXZ
void ExpressionAnimationController_2a9de0::f() {
    vptr = hulk_at_0042df6c;
    _ReadWriteBarrier();
    if (m40) {
        m40->f1();
        m40 = 0;
    }
    if (m44) {
        m44->f1();
        m44 = 0;
    }
    operator delete[](m4c);
    ((ExpressionAnimationController_nv_2a9de0*)(((pure3d::ExpressionAnimationController*)this)))->Fn_00285800();
}

} // namespace fn_ff685ee7

// 0x002a9e30 pure3d::ExpressionAnimationController::vfunc_26 (102 B): equivalent/0x002a9e30.cpp
// sym: ?vfunc_26@ExpressionAnimationController@pure3d@@UAE_NPAX@Z @4ad4b9e7f5b6 @w26bc4d3da9bb
// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 13/14, incomplete)
// pure3d::ExpressionAnimationController::vfunc_26 @ 0x002a9e30
bool pure3d::ExpressionAnimationController::vfunc_26(void* __p0) { Anim_2a9e30 * a = (Anim_2a9e30 *)__p0;

    if (a == 0)
        return (bool)(0);
    if (a->count <= 0)
        return (bool)(0);
    if (a->tag != 0x505845)
        return (bool)(0);
    if ((*(Inner_2a9e30 * *)&this->f_40) != 0) {
        Elem_2a9e30* e = (*(Inner_2a9e30 * *)&this->f_40)->elem;
        int i = 0;
        do {
            void* item = ((void *)((owners::Target_288a10 *)a)->FUN_00288a10(i));
            if (e->FUN_002afe80((char*)item + 8) == -1)
                return (bool)(0);
            i++;
        } while (i < a->count);
    }
    return (bool)(1);
}

namespace fn_ff685ee7 {

// 0x002a9ea0 FUN_002a9ea0 (135 B): equivalent/0x002a9ea0.cpp
// sym: ?FUN_002a9ea0@ExpressionAnimationController_2a9ea0@fn_ff685ee7@@QAEXPAVSource_2a9ea0@2@@Z @80c2eb98712e @w9af7c7601a33
// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 8/8)
// FUN_002a9ea0 @ 0x002a9ea0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
// Switches to a new source and allocates one zeroed value per element it holds.
void ExpressionAnimationController_2a9ea0::FUN_002a9ea0(Source_2a9ea0 *src)
{
    count = 0;
    thunk_FUN_00267090(values);
    values = 0;
    if (src)
        src->AddRef();
    if (source)
        source->Release();
    source = src;
    count = src->end - src->begin;
    values = (int *)FUN_0008d6d0(count * 4);
    for (int i = 0; i < count; i++)
        values[i] = 0;
}


// 0x002a9f30 FUN_002a9f30 (41 B): matches/0x002a9f30.cpp
// sym: ?Set@Owner_2a9f30@fn_ff685ee7@@QAEXPAVSource_2a9f30@2@@Z
void Owner_2a9f30::Set(Source_2a9f30* src) {
    Ref_2a9f30* p = src->mRef;
    if (p)
        p->A();
    if (mRef)
        mRef->B();
    mRef = p;
}

} // namespace fn_ff685ee7

// 0x002a9f60 pure3d::ExpressionAnimationController::vfunc_7 (157 B): equivalent/0x002a9f60.cpp [wrapped: conflict: ExpressionAnimationController]
// sym: ?FUN_002a9f60@ExpressionAnimationController@fn_002a9f60@@QAEXXZ @99fe135fcf5e @wb6d40ac23e2f
namespace fn_002a9f60 {
// STATUS: equivalent (tools/equiv.py level 3: 59 inputs, branch coverage 10/10)
// pure3d::ExpressionAnimationController::vfunc_7 @ 0x002a9f60
// pure3d::ExpressionAnimationController::vfunc_7: reset the channel values, then refill them from the "FLT1" chunks
struct Channel {
    void FUN_0028a1c0(int a, float *out);
};

struct Chunk {
    Channel *FUN_00288960(int tagA, int tagB);
};

struct Chunks_2a9f60 {
    char pad00[0x28];
    int count;
    Chunk *FUN_00288a10(int index);
};

struct Index_2a9f60 {
    int FUN_002afe80(void *name);
};

struct Output_2a9f60 {
    char pad00[0x10];
    Index_2a9f60 *index;
    float *values;
    void FUN_002b0cd0(int arg);
};

class ExpressionAnimationController {
public:
    char pad00[0x34];
    int f34;
    char pad38[4];
    Chunks_2a9f60 *chunks;
    Output_2a9f60 *output;
    int f44;
    int count;
    int *zeros;

    void FUN_002a9f60();
};

void ExpressionAnimationController::FUN_002a9f60()
{
    for (int i = 0; i < count; i++)
        zeros[i] = 0;
    int n = chunks->count;
    for (int i = 0; i < n; i++) {
        Chunk *c = chunks->FUN_00288a10(i);
        Channel *ch = c->FUN_00288960(0x455453, 0x31544c46);
        if (ch != 0) {
            float v;
            ch->FUN_0028a1c0(f34, &v);
            float saved = v;
            int slot = output->index->FUN_002afe80((char *)c + 8);
            output->values[slot] = saved;
        }
    }
    output->FUN_002b0cd0(f44);
}
} // namespace fn_002a9f60

namespace fn_ff685ee7 {

// 0x002aa000 pure3d::ExpressionAnimationController::vfunc_2 (88 B): matches/0x002aa000.cpp
// sym: ?vfunc_2@ExpressionAnimationController@fn_ff685ee7@@QAEPAV12@H@Z
ExpressionAnimationController* ExpressionAnimationController::vfunc_2(int flag) {
    char* b = (char*)this;
    *(void**)b = (void*)&gVftable_2aa000;
    _ReadWriteBarrier();
    RefObj_2aa000* pA = *(RefObj_2aa000**)(b + 0x40);
    if (pA) {
        pA->Release();
        *(int*)(b + 0x40) = 0;
    }
    RefObj_2aa000* pB = *(RefObj_2aa000**)(b + 0x44);
    if (pB) {
        pB->Release();
        *(int*)(b + 0x44) = 0;
    }
    _ReadWriteBarrier();
    freefn_0008d340(*(void**)(b + 0x4c));
    ((ExpressionAnimationController_2aa000*)this)->BaseDtor_00285800();
    if (flag & 1) {
        opdel_00263f30(this);
    }
    return this;
}


// 0x002aa0a0 pure3d::ExpressionAnimationController::vfunc_4 (72 B): matches/0x002aa0a0.cpp
// sym: ?f4@ExpressionAnimationController_2aa0a0@fn_ff685ee7@@UAEPAV12@XZ
ExpressionAnimationController_2aa0a0* ExpressionAnimationController_2aa0a0::f4() {
    ExpressionAnimationController_2aa0a0* p = (ExpressionAnimationController_2aa0a0*)alloc_00263ea0(0x50);
    ExpressionAnimationController_2aa0a0* z = 0;
    if (p != z) {
        new (p) ExpressionAnimationController_2aa0a0(this);
        p->Fng_002a9ea0(m[0]);
        return p;
    }
    return z;
}

} // namespace fn_ff685ee7

// 0x002aa0f0 pure3d::ExpressionAnimationController::vfunc_5 (104 B): matches/0x002aa0f0.cpp [wrapped: conflict: ExpressionAnimationController]
// sym: ?vfunc_5@ExpressionAnimationController@fn_002aa0f0@@QAEXPAX@Z
namespace fn_002aa0f0 {
class SimpleFrameController_2aa0f0 {
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
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
};
extern int hulk_at_0048f610, hulk_at_004ce7fc, hulk_at_004cf460;
class ExpressionAnimationController : public SimpleFrameController_2aa0f0 {
    char pad[0x40];

  public:
    SimpleFrameController_2aa0f0* mField;
    void assign_002a9ea0(void*);
    void vfunc_5(void*);
};
void ExpressionAnimationController::vfunc_5(void* arg) {
    void* p = __RTDynamicCast(arg, 0, &hulk_at_0048f610, &hulk_at_004ce7fc, 0);
    if (p) {
        assign_002a9ea0(p);
        return;
    }
    p = __RTDynamicCast(arg, 0, &hulk_at_0048f610, &hulk_at_004cf460, 0);
    SimpleFrameController_2aa0f0* q = *(SimpleFrameController_2aa0f0**)((char*)p + 0x68);
    if (q)
        q->f0();
    if (mField)
        mField->f1();
    mField = q;
}
} // namespace fn_002aa0f0

