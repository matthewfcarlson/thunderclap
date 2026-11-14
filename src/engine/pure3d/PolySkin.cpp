// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x002b78a0..0x002b8040 (kind game, layer engine, confidence high), dominant class pure3d::PolySkin
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/loaders.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f0d4c6f4 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f0d4c6f4 {} using namespace fn_f0d4c6f4;
namespace fn_f0d4c6f4 { extern "C" char DAT_0042e6e4[], DAT_003f6098[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f0d4c6f4 {
class Ref_2b7900 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
class H {
  public:
    void two_002dfc90(void*, void*);
};
struct PolySkin_nv_2b7900 {
    void last_002a41e0(hulk_intptr, int);
};
class DrawableContainer {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual int vfunc_16();
};
class PolySkin : public DrawableContainer {
    char pad[0x6c - 4];

  public:
    int x;
    int y;
    int vfunc_16();
};
extern void* hulk_at_0042e694[];
class Ref_2b7c00 {
  public:
    virtual void F0();
    virtual void Release();
};
class DrawableContainer_2b7c00 {
  public:
    void* vptr;
    void Fin_002a4ff0();
};
class PolySkin_2b7c00 : public DrawableContainer_2b7c00 {
  public:
    char pad[0x54];
    Ref_2b7c00* m58;
    Ref_2b7c00* m5c;
    Ref_2b7c00* m60;
    Ref_2b7c00* m64;
    Ref_2b7c00* m68;
    Ref_2b7c00* m6c;
    Ref_2b7c00* m70;
    ~PolySkin_2b7c00();
};
class Thing_2b7c80 {
  public:
    virtual void A();
    virtual void B();
};
extern void* hulk_at_0042e6e4[];
} // namespace fn_f0d4c6f4
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_f0d4c6f4 {
class Ref_2b7d30 {
  public:
    virtual void AddRef();
    virtual void Release();
};
// (x64t7) the two loaders by their constructors' addresses (pure3d::PrimGroupLoader 0x002df7f0, OldPrimGroupLoader
// 0x002df850, src/engine/pure3d/PrimGroupStreamed.cpp: the local names had no definition natively) with those
// classes' words (pure3d::NonCopyable's reference count, 12 bytes natively, then the loader's own), so `new` takes
// their native size (as GeometryLoader 0x002c29b0 does)
HULK_REFCOUNT_PACK
class Base_2b7d30 : public Ref_2b7d30 {
  public:
    int refs;
};
HULK_REFCOUNT_PACK_END
class FUN_002df7f0 : public Base_2b7d30 {
  public:
    FUN_002df7f0() throw();
    int a, b;
    char c, d;
    short e;
    int f0, f1, f2, f3, f4, f5;
};
class FUN_002df850 : public Base_2b7d30 {
  public:
    FUN_002df850() throw();
    int a, b, c, d, e, f, g;
};
typedef char hulk_size32_2b7d30[(sizeof(void*) != 4 || (sizeof(FUN_002df7f0) == 0x2c && sizeof(FUN_002df850) == 0x24)) ? 1 : -1];
struct RP_2b7d30 {
    Ref_2b7d30* p;
    void Set(Ref_2b7d30* r) {
        if (r)
            r->AddRef();
        if (p)
            p->Release();
        p = r;
    }
};
struct Pad_2b7d30 {
    unsigned char b24, b25, b26, b27, b28, b29, b2a;
    void Set() {
        b27 = 0x20;
        b26 = 0x20;
        b25 = 0x20;
        b24 = 0x20;
        b28 = 0x20;
        b29 = 0x20;
        b2a = 0x20;
    }
};
class PolySkinLoader_2b7d30 {
  public:
    void* vptr;
    int m4;
    int m8;
    int mc;
    int m10;
    char m14;
    int m18;
    RP_2b7d30 m1c;
    RP_2b7d30 m20;
    Pad_2b7d30 pd;
    PolySkinLoader_2b7d30();
};
// (x64t8) this view is the words of decls/loaders.h's HulkGeometryLoader (the record 0x00291dc0 allocates): sizes checked on every build
typedef char hulk_rec_2b7d30[sizeof(PolySkinLoader_2b7d30) == sizeof(HulkGeometryLoader) ? 1 : -1];
// (x64t8) this view is the words of decls/loaders.h's HulkPrimGroupLoader (its PrimGroupLoader): sizes checked on every build
typedef char hulk_rec_2df7f0[sizeof(FUN_002df7f0) == sizeof(HulkPrimGroupLoader) ? 1 : -1];
extern void* g_vftable_0042e6e4[];
class Ref_2b7df0 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleChunkHandler_2b7df0 {
  public:
    void* vptr;
    void Fin();
};
class PolySkinLoader_2b7df0 : public SimpleChunkHandler_2b7df0 {
  public:
    char pad[0x1c - 4];
    Ref_2b7df0* m1c;
    Ref_2b7df0* m20;
    ~PolySkinLoader_2b7df0() throw();
};
struct Helper_2b8020 {
    hulk_intptr Fnf_002b7e50(pure3d::PolySkin*);
};

} // namespace fn_f0d4c6f4

// 0x002b78a0 pure3d::PolySkin::vfunc_15 (6 B): matches/0x002b78a0.cpp
// sym: ?vfunc_15@PolySkin@pure3d@@UAEHXZ
// Same code shape as 0x0004e0b0 (propagated; names are from that function)
int pure3d::PolySkin::vfunc_15() {
    return 2;
}


// 0x002b78b0 pure3d::PolySkin::vfunc_3 (3 B): matches/0x002b78b0.cpp
// sym: ?vfunc_3@PolySkin@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::PolySkin::vfunc_3() {
    return true;
}


// 0x002b78c0 pure3d::PolySkin::vfunc_6 (60 B): equivalent/0x002b78c0.cpp [wrapped: conflict: pure3d::DrawableContainer; pure3d::PolySkin]
// sym: ?vfunc_6@PolySkin@pure3d@fn_002b78c0@@QAEXHH@Z @8d644395f7f9 @w4fba3cb6053f
namespace fn_002b78c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::PolySkin::vfunc_6 @ 0x002b78c0
namespace pure3d {
struct Child {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(int, int);
};
struct DrawableContainer {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 void vfunc_6_002a40d0(int, int);
};
struct PolySkin : DrawableContainer {
 char pad[0x68];
 Child* first;
 Child* second;
 void vfunc_6(int a, int b);
};
void PolySkin::vfunc_6(int a, int b) {
 if (first) first->vfunc_6(a,b);
 if (second) second->vfunc_6(a,b);
 DrawableContainer::vfunc_6_002a40d0(a,b);
}
}
} // namespace fn_002b78c0


// 0x002b7900 pure3d::PolySkin::vfunc_8 (86 B): matches/0x002b7900.cpp
// sym: ?vfunc_8@PolySkin@pure3d@@UAEXHH@Z
void pure3d::PolySkin::vfunc_8(hulk_intptr a, int b) {
    if ((*(Ref_2b7900 * *)&this->f_6c))
        (*(Ref_2b7900 * *)&this->f_6c)->f6(0, 1);
    if ((*(Ref_2b7900 * *)&this->f_70))
        (*(Ref_2b7900 * *)&this->f_70)->f6(0, 1);
    ((owners::C_284820 *)(((H*)(*(void * *)&this->f_60))))->FUN_00284820((hulk_intptr)0);
    ((H*)(*(H * *)&this->f_58))->two_002dfc90((*(void * *)&this->f_5c), (*(void * *)&this->f_60));
    ((PolySkin_nv_2b7900*)this)->last_002a41e0(a, b);
}


// 0x002b7960 pure3d::PolySkin::vfunc_11 (4 B): matches/0x002b7960.cpp
// sym: ?vfunc_11@PolySkin@pure3d@@UAEIXZ
hulk_uintptr pure3d::PolySkin::vfunc_11() {
    return (*(unsigned int *)&this->f_60);
}

namespace fn_f0d4c6f4 {

// 0x002b7970 pure3d::PolySkin::vfunc_16 (26 B): matches/0x002b7970.cpp
// sym: ?vfunc_16@PolySkin@fn_f0d4c6f4@@UAEHXZ
int PolySkin::vfunc_16() {
    int n = DrawableContainer::vfunc_16();
    if (x)
        ++n;
    if (y)
        ++n;
    return n;
}

} // namespace fn_f0d4c6f4

// 0x002b7990 pure3d::PolySkin::vfunc_17 (64 B): equivalent/0x002b7990.cpp [wrapped: conflict: pure3d::DrawableContainer; pure3d::PolySkin]
// sym: ?vfunc_17@PolySkin@pure3d@fn_002b7990@@QAEXHH@Z @fc6e7b941cee @wd5219d9f83f6
namespace fn_002b7990 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// pure3d::PolySkin::vfunc_17 @ 0x002b7990
namespace pure3d {
struct Item { char pad[8]; int first; int second; };
struct DrawableContainer { void vfunc_17_002a4440(int, int); };
struct PolySkin : DrawableContainer {
    char pad[0x6c - sizeof(DrawableContainer)];
    Item* primary;
    Item* secondary;
    void vfunc_17(int first, int second);
};
void PolySkin::vfunc_17(int first, int second) {
    if ((!primary || primary->first != first || primary->second != second) &&
        (!secondary || secondary->first != first || secondary->second != second))
        DrawableContainer::vfunc_17_002a4440(first, second);
}
}
} // namespace fn_002b7990


// 0x002b79d0 pure3d::PolySkin::vfunc_18 (54 B): matches/0x002b79d0.cpp [wrapped: conflict: PolySkin]
// sym: ?vfunc_18@PolySkin@fn_002b79d0@@UAEHH@Z
namespace fn_002b79d0 {
class DrawableContainer {
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
    virtual int vfunc_18(int);
};
class PolySkin : public DrawableContainer {
  public:
    char pad[0x6c - 4];
    int a;
    int b;
    virtual int vfunc_18(int);
};
int PolySkin::vfunc_18(int n) {
    int x = a;
    if (x) {
        if (n == 0)
            return x;
        --n;
    }
    if (b) {
        if (n == 0 || (n == 1 && x))
            return b;
        --n;
    }
    return DrawableContainer::vfunc_18(n);
}
} // namespace fn_002b79d0

namespace fn_f0d4c6f4 {

// 0x002b7c00 FUN_002b7c00 (126 B): matches/0x002b7c00.cpp
// sym: ??1PolySkin_2b7c00@fn_f0d4c6f4@@QAE@XZ
PolySkin_2b7c00::~PolySkin_2b7c00() {
    vptr = hulk_at_0042e694;
    _ReadWriteBarrier();
    if (m58) {
        m58->Release();
        m58 = 0;
    }
    if (m5c) {
        m5c->Release();
        m5c = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    if (m68) {
        m68->Release();
        m68 = 0;
    }
    if (m6c) {
        m6c->Release();
        m6c = 0;
    }
    if (m70) {
        m70->Release();
        m70 = 0;
    }
    Fin_002a4ff0();
}

} // namespace fn_f0d4c6f4

// 0x002b7c80 pure3d::PolySkin::vfunc_10 (38 B): matches/0x002b7c80.cpp
// sym: ?vfunc_10@PolySkin@pure3d@@UAEXH@Z
// Same code shape as 0x000e9100 (propagated; names are from that function)
void pure3d::PolySkin::vfunc_10(hulk_intptr __p0) { Thing_2b7c80 * p = (Thing_2b7c80 *)__p0;

    if (p)
        p->A();
    if ((*(Thing_2b7c80 * *)&this->f_60))
        (*(Thing_2b7c80 * *)&this->f_60)->B();
    (*(Thing_2b7c80 * *)&this->f_60) = p;
}

namespace fn_f0d4c6f4 {

// 0x002b7d30 FUN_002b7d30 (179 B): matches/0x002b7d30.cpp
// sym: ??0PolySkinLoader_2b7d30@fn_f0d4c6f4@@QAE@XZ
PolySkinLoader_2b7d30::PolySkinLoader_2b7d30() {
    m8 = 0x10001;
    vptr = hulk_at_0042e6e4;
    m14 = 1;
    m18 = -1;
    m4 = 0;
    mc = 0;
    m10 = 0;
    m1c.p = 0;
    m20.p = 0;
    pd.Set();
    m1c.Set(new FUN_002df7f0);
    m20.Set(new FUN_002df850);
}


// 0x002b7df0 FUN_002b7df0 (55 B): matches/0x002b7df0.cpp
// sym: ??1PolySkinLoader_2b7df0@fn_f0d4c6f4@@QAE@XZ
PolySkinLoader_2b7df0::~PolySkinLoader_2b7df0() throw() {
    vptr = ((void**)DAT_0042e6e4);
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    vptr = ((void**)DAT_003f6098);
}

} // namespace fn_f0d4c6f4

// 0x002b7e30 pure3d::PolySkin::vfunc_2 (30 B): matches/0x002b7e30.cpp
// sym: ??_GPolySkin@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::PolySkin::~PolySkin() {}


// 0x002b7e50 FUN_002b7e50 (455 B): equivalent/0x002b7e50.cpp [wrapped: conflict: PolySkin; pure3d::DrawablePrimitive; pure3d::PrimGroupSkinnedOptimized; pure3d::PrimGroupSkinnedStreamed]
// sym: ??0PolySkin@fn_002b7e50@@QAE@PBV01@@Z @f0914bc04e60 @wd6caf72c3a94
namespace fn_002b7e50 {
// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 42/42)
// FUN_002b7e50 @ 0x002b7e50
extern "C" void* FUN_0008d690(unsigned int size);

struct RefObj_2b7e50 {
    virtual void AddRef();
    virtual void Release();
};

namespace pure3d {
class DrawablePrimitive {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int GetKind();
    DrawablePrimitive* FUN_002df7e0();
};
class PrimGroupSkinnedOptimized : public DrawablePrimitive {
public:
    void FUN_002e01a0(void* arg);
};
class PrimGroupSkinnedStreamed : public DrawablePrimitive {
public:
    void FUN_002e05f0(void* arg);
};
}

struct BoneMatrixList_2b7e50 : RefObj_2b7e50 {
    char pad04[0x10];
    BoneMatrixList_2b7e50(void* src);
    BoneMatrixList_2b7e50* FUN_002e17c0(void* src);
};

struct VertexAnimObject_2b7e50 : RefObj_2b7e50 {
    char pad04[0x14];
    VertexAnimObject_2b7e50* FUN_002d0fa0(void* owner);
};

struct LinkedA : RefObj_2b7e50 {
    virtual void a2();
    virtual void a3();
    virtual LinkedA* Clone();
    void FUN_002a9f30(void* owner);
};

struct LinkedB : RefObj_2b7e50 {
    virtual void b2();
    virtual void b3();
    virtual LinkedB* Clone();
    void FUN_002a6a20(void* owner);
};

struct Part_2b7e50 {
    pure3d::DrawablePrimitive* prim;
    char pad04[12];
};

class PolySkin;

class __declspec(novtable) DrawableContainer_2b7e50 {
public:
    virtual void v0();
    char pad04[0x44];
    Part_2b7e50* partsBegin;
    Part_2b7e50* partsEnd;
    char pad50[8];
    void FUN_002a4e40(const PolySkin* src);
    DrawableContainer_2b7e50(const PolySkin* src) { FUN_002a4e40(src); }
};

class PolySkin : public DrawableContainer_2b7e50 {
public:
    virtual void v0();
    BoneMatrixList_2b7e50* info;
    RefObj_2b7e50* shared;
    int field60;
    RefObj_2b7e50* binderShared;
    VertexAnimObject_2b7e50* binder;
    LinkedA* linkA;
    LinkedB* linkB;
    PolySkin(const PolySkin* src);
};

PolySkin::PolySkin(const PolySkin* src) : DrawableContainer_2b7e50(src)
{
    info = 0;
    shared = 0;
    field60 = 0;
    binderShared = 0;
    binder = 0;
    linkA = 0;
    linkB = 0;
    RefObj_2b7e50* s = src->shared;
    if (s != 0) {
        s->AddRef();
        if (shared != 0)
            shared->Release();
        shared = s;
        if (src->info != 0) {
            void* mem = FUN_0008d690(0x14);
            BoneMatrixList_2b7e50* n = 0;
            if (mem != 0) {
                n = (BoneMatrixList_2b7e50*)mem;
                n = n->FUN_002e17c0(src->info);
            }
            info = n;
            n->AddRef();
            for (unsigned int i = 0; i < (unsigned int)(partsEnd - partsBegin); i++) {
                pure3d::DrawablePrimitive* p = partsBegin[i].prim;
                if (p->GetKind() == 0x40)
                    p = p->FUN_002df7e0();
                pure3d::PrimGroupSkinnedOptimized* o = dynamic_cast<pure3d::PrimGroupSkinnedOptimized*>(p);
                if (o != 0) {
                    static_cast<pure3d::PrimGroupSkinnedOptimized*>(p)->FUN_002e01a0(info);
                } else {
                    pure3d::PrimGroupSkinnedStreamed* st = dynamic_cast<pure3d::PrimGroupSkinnedStreamed*>(p);
                    if (st != 0)
                        static_cast<pure3d::PrimGroupSkinnedStreamed*>(p)->FUN_002e05f0(info);
                }
            }
        }
    }
    RefObj_2b7e50* b = src->binderShared;
    if (b != 0)
        b->AddRef();
    if (binderShared != 0)
        binderShared->Release();
    binderShared = b;
    if (src->binder != 0) {
        void* mem = FUN_0008d690(0x18);
        VertexAnimObject_2b7e50* n = 0;
        if (mem != 0) {
            n = (VertexAnimObject_2b7e50*)mem;
            n = n->FUN_002d0fa0(this);
        }
        binder = n;
        n->AddRef();
    }
    if (src->linkA != 0) {
        LinkedA* c = src->linkA->Clone();
        if (c != 0)
            c->AddRef();
        if (linkA != 0)
            linkA->Release();
        linkA = c;
        if (c != 0)
            c->FUN_002a9f30(this);
    }
    if (src->linkB != 0) {
        LinkedB* c = src->linkB->Clone();
        if (c != 0)
            c->AddRef();
        if (linkB != 0)
            linkB->Release();
        linkB = c;
        if (c != 0)
            c->FUN_002a6a20(this);
    }
}
} // namespace fn_002b7e50


// 0x002b8020 pure3d::PolySkin::vfunc_4 (31 B): matches/0x002b8020.cpp
// sym: ?vfunc_4@PolySkin@pure3d@@UAEPAXXZ
void* pure3d::PolySkin::vfunc_4() {
    Helper_2b8020* p = (Helper_2b8020*)thunk_FUN_0008d690(0x78);
    if (p)
        return (void*)(p->Fnf_002b7e50(this));
    return (void*)(0);
}

