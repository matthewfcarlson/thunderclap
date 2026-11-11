// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a3660..0x002a3e70 (kind game, layer engine, confidence high), dominant class pure3d::ParticleSystem
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f1899950 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f1899950 {} using namespace fn_f1899950;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f1899950 {
extern "C" char DAT_0042d88c[];
struct ThisCall_002a4e10 {
    void* FUN_002a4e10(void*);
};
void FUN_0022b980();
struct Sub_2a3660 {
    void Init_0022b980();
};
class ParticleSystem {
  public:
    hulk_uintptr vt;
    char p[0x54];
    unsigned char flag;
    char p2[3];
    float x;
    float y;
    Sub_2a3660 sub;
    char p3[0x3c];
    int a;
    int b;
    ParticleSystem* Build(void* arg);
};
class ParamValue_2a36b0 {
  public:
    virtual void f0();
    virtual int f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
extern int hulk_at_0042d88c;
class Ref_2a3950 {
  public:
    virtual void f0();
    virtual void Release();
};
class DrawableContainer_2a3950 {
  public:
    void* vptr;
    ~DrawableContainer_2a3950() throw();
};
class ParticleSystem_2a3950 : public DrawableContainer_2a3950 {
  public:
    char pa4[160];
    Ref_2a3950* aa4;
    Ref_2a3950* aa8;
    ~ParticleSystem_2a3950() throw();
};
class Item {
  public:
    virtual void FUN_00000000();
    virtual void FUN_00000001();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void FUN_00000005(Owner *);
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual int count();
    virtual void _m_vf14();
    virtual void Act();
    virtual void _m_vf16();
    virtual void apply(int, int);
    virtual void _m_vf18();
    virtual void f19(int);
};
struct Entry {
  public:
    union { Item* item; Item* p; Item* ptr; };
    char _m_pad_4[0xc];
};
class Owner {
  public:
    char _m_pad_0[0x48];
    union { Entry* begin; Entry* first; };
    union { Entry* end; Entry* last; };
    char _m_pad_50[0x54];
    Item *item;
    int total();
    void Run();
    void Run(int x);
    void FUN_002a3c80(Item *next);
};
class Holder {
    char pad[0x48];

  public:
    Entry* begin;
    Entry* end;
    void Run(int a, int b);
};
class Helper_2a3e20 {
  public:
    hulk_intptr call_002a3d90(pure3d::ParticleSystem*);
};
extern void* __cdecl alloc_00263ea0(int);
class Callback_2a3e50 {
  public:
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void Invoke(int);
};
struct ThisCall_002a3b60 {
    void FUN_002a3b60();
};


// 0x002a3660 FUN_002a3660 (65 B): matches/0x002a3660.cpp
// sym: ?Build@ParticleSystem@fn_f1899950@@QAEPAV12@PAX@Z
ParticleSystem* ParticleSystem::Build(void* arg) {
    ((ThisCall_002a4e10*)(this))->FUN_002a4e10(arg);
    vt = ((hulk_intptr)DAT_0042d88c);
    flag = 1;
    x = 100.0f;
    y = 30.0f;
    a = 0;
    b = 0;
    sub.Init_0022b980();
    return this;
}

} // namespace fn_f1899950

// 0x002a36b0 pure3d::ParticleSystem::vfunc_15 (6 B): matches/0x002a36b0.cpp
// sym: ?vfunc_15@ParticleSystem@pure3d@@UAEHXZ
// Same code shape as 0x00055210 (propagated; names are from that function)
int pure3d::ParticleSystem::vfunc_15() {
    return 4;
}


// 0x002a36c0 pure3d::ParticleSystem::vfunc_3 (3 B): matches/0x002a36c0.cpp
// sym: ?vfunc_3@ParticleSystem@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ParticleSystem::vfunc_3() {
    return true;
}


// 0x002a36d0 pure3d::ParticleSystem::vfunc_6 (101 B): matches/0x002a36d0.cpp [wrapped: conflict: ParticleSystem]
// sym: ?vfunc_6@ParticleSystem@fn_002a36d0@@UAEXPAXH@Z
namespace fn_002a36d0 {
// data: globalManager = DAT_0052c2ac

class Other_2a36d0;
class DrawableContainer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void vfunc_6(void*, int);
};
class ParticleSystem : public DrawableContainer {
  public:
    char pad[0xa0];
    Other_2a36d0* emitter;
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    void vfunc_6(void*, int);
};
class Other_2a36d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(void*, int);
    virtual void h();
};
class Manager_2a36d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q(int);
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    virtual void x(int, void*);
};
void ParticleSystem::vfunc_6(void* a, int b) {
    if (emitter)
        emitter->g(a, b);
    if ((char)b == 1) {
        (*(*(Manager_2a36d0***)&DAT_0052c2ac))->x(0, (char*)this + 0x64);
        emitter->h();
    }
    DrawableContainer::vfunc_6(a, b);
    if ((char)b == 1)
        (*(*(Manager_2a36d0***)&DAT_0052c2ac))->q(0);
}
} // namespace fn_002a36d0


// 0x002a3740 pure3d::ParticleSystem::vfunc_7 (34 B): equivalent/0x002a3740.cpp [wrapped: conflict: pure3d::DrawableContainer; pure3d::ParticleSystem]
// sym: ?vfunc_7@ParticleSystem@pure3d@fn_002a3740@@QAEXXZ @fc3f24fb87a9 @w61b30096e132
namespace fn_002a3740 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::ParticleSystem::vfunc_7 @ 0x002a3740
namespace pure3d {
struct Controller {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual bool slot22();
};
struct DrawableContainer { void vfunc_7_002a4150(); };
struct ParticleSystem : DrawableContainer {
    char pad[0xa4];
    Controller *controller;
    void vfunc_7();
};
void ParticleSystem::vfunc_7() {
    if (controller && !controller->slot22()) return;
    DrawableContainer::vfunc_7_002a4150();
}
}
} // namespace fn_002a3740


// 0x002a3770 pure3d::ParticleSystem::vfunc_16 (22 B): matches/0x002a3770.cpp [wrapped: conflict: ParticleSystem]
// sym: ?vfunc_16@ParticleSystem@fn_002a3770@@QAEHXZ
namespace fn_002a3770 {
class DrawableContainer {
  public:
    int vfunc_16_002a4410();
};
class ParticleSystem : public DrawableContainer {
  public:
    char pad[0xa4 - sizeof(DrawableContainer)];
    int mValue;
    int vfunc_16();
};
int ParticleSystem::vfunc_16() {
    if (mValue)
        return DrawableContainer::vfunc_16_002a4410() + 1;
    return DrawableContainer::vfunc_16_002a4410();
}
} // namespace fn_002a3770


// 0x002a3790 pure3d::ParticleSystem::vfunc_18 (31 B): matches/0x002a3790.cpp [wrapped: conflict: pure3d::DrawableContainer; pure3d::ParticleSystem]
// sym: ?vfunc_18@ParticleSystem@pure3d@fn_002a3790@@UAEHH@Z
namespace fn_002a3790 {
namespace pure3d {
struct DrawableContainer {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual int vfunc_18(int index);
};
struct ParticleSystem : DrawableContainer {
    char padding[0xa0];
    int particle;
    virtual int vfunc_18(int index);
};
int ParticleSystem::vfunc_18(int index) {
    if (particle) {
        if (index == 0)
            return particle;
        --index;
    }
    return DrawableContainer::vfunc_18(index);
}
} // namespace pure3d
} // namespace fn_002a3790


// 0x002a37b0 pure3d::ParticleSystem::vfunc_17 (46 B): equivalent/0x002a37b0.cpp [wrapped: conflict: pure3d::DrawableContainer; pure3d::ParticleSystem]
// sym: ?vfunc_17@ParticleSystem@pure3d@fn_002a37b0@@QAEXHH@Z @42467b477c7a @wde3fd3b616fb
namespace fn_002a37b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// pure3d::ParticleSystem::vfunc_17 @ 0x002a37b0
namespace pure3d {
struct DrawableContainer {
    void vfunc_17_002a4440(int, int);
};
struct ParticleEntry {
    char padding[8];
    int first;
    int second;
};
struct ParticleSystem : DrawableContainer {
    char padding[0xa4 - sizeof(DrawableContainer)];
    ParticleEntry* current;
    void vfunc_17(int first, int second);
};
void ParticleSystem::vfunc_17(int first, int second) {
    if (!current || current->first != first || current->second != second)
        DrawableContainer::vfunc_17_002a4440(first, second);
}
}
} // namespace fn_002a37b0

namespace fn_f1899950 {

// 0x002a3950 FUN_002a3950 (67 B): matches/0x002a3950.cpp
// sym: ??1ParticleSystem_2a3950@fn_f1899950@@QAE@XZ
ParticleSystem_2a3950::~ParticleSystem_2a3950() throw() {
    vptr = &hulk_at_0042d88c;
    _ReadWriteBarrier();
    if (aa4) {
        aa4->Release();
        aa4 = 0;
    }
    if (aa8) {
        aa8->Release();
        aa8 = 0;
    }
}

} // namespace fn_f1899950

// 0x002a39a0 pure3d::ParticleSystem::vfunc_8 (312 B): equivalent/0x002a39a0.cpp [wrapped: macros]
// sym: ?run@ParticleSystem@fn_002a39a0@@QAEXPAURenderer_2a39a0@2@H@Z @20dbfe4b85dd @w7b17b3df77ea
namespace fn_002a39a0 {
// STATUS: equivalent (tools/equiv.py level 3: 112 inputs, branch coverage 18/18)
// pure3d::ParticleSystem::vfunc_8 @ 0x002a39a0

class Device_2a39a0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23(int a, void* p);
};

class Child_2a39a0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7();
    virtual void v8(int a);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22(void* out);
};

#if defined(__clang__)
typedef int (__fastcall *Fn0)(void*, int);
typedef void (__fastcall *Fn1)(void*, int, int);
typedef int (__fastcall *Fn1r)(void*, int, int);
#endif
class Helper_2a39a0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int a);
    virtual int v4(int a);
};

class Lifecycle {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

struct Mat_2a39a0 {
    float m[16];
};

struct Elem_2a39a0 {
    Child_2a39a0* child;
    char pad[12];
    void FUN_002a4060();
};

struct Renderer_2a39a0 {
    void FUN_0029b9d0(void* system, unsigned int index, Mat_2a39a0* mat, int arg);
};


class ParticleSystem {
public:
    void run(Renderer_2a39a0* renderer, int arg);
    char p0[0x10];
    Helper_2a39a0* helper;
    char p1[0x48 - 0x14];
    Elem_2a39a0* begin;
    Elem_2a39a0* end;
    char p2[0x64 - 0x50];
    char block64[0xa4 - 0x64];
    Lifecycle* life;
};

void ParticleSystem::run(Renderer_2a39a0* renderer, int arg)
{
    (*(*(Device_2a39a0***)&DAT_0052c2ac))->v23(0, block64);
    if (life != 0)
        life->v7();

    if (renderer == 0) {
        unsigned int count = (unsigned int)(end - begin);
        if (helper != 0) {
            for (unsigned int i = 0; i < count; i++) {
                Child_2a39a0* c = begin[i].child;
#if defined(__clang__)
                {
                    // the original loads both vptrs before the first call and reads the slots after it
                    void** cvt = *(void***)c;
                    void** hvt = *(void***)helper;
                    int a = ((Fn0)cvt[7])(c, 0);
                    int b = ((Fn1r)hvt[3])(helper, 0, a);
                    ((Fn1)cvt[8])(c, 0, b);
                }
#else
                c->v8(helper->v3(c->v7()));
#endif
                begin[i].FUN_002a4060();
#if defined(__clang__)
                {
                    // the original loads both vptrs before the first call and reads the slots after it
                    void** cvt = *(void***)c;
                    void** hvt = *(void***)helper;
                    int a = ((Fn0)cvt[7])(c, 0);
                    int b = ((Fn1r)hvt[4])(helper, 0, a);
                    ((Fn1)cvt[8])(c, 0, b);
                }
#else
                c->v8(helper->v4(c->v7()));
#endif
            }
        } else {
            for (unsigned int i = 0; i < count; i++)
                begin[i].FUN_002a4060();
        }
    } else {
        unsigned int count = (unsigned int)(end - begin);
        for (unsigned int i = 0; i < count; i++) {
            Mat_2a39a0 mat;
            begin[i].child->v22(&mat);
            renderer->FUN_0029b9d0(this, i, &mat, arg);
        }
    }
    (*(*(Device_2a39a0***)&DAT_0052c2ac))->v16(0);
}
} // namespace fn_002a39a0

namespace fn_f1899950 {

// 0x002a3b10 FUN_002a3b10 (71 B): matches/0x002a3b10.cpp
// sym: ?total@Owner@fn_f1899950@@QAEHXZ
int Owner::total() {
    int sum = 0;
    for (unsigned i = 0; i < (unsigned)(end - begin); ++i)
        sum += begin[i].p->count();
    return sum;
}


// 0x002a3b60 FUN_002a3b60 (54 B): matches/0x002a3b60.cpp
// sym: ?Run@Owner@fn_f1899950@@QAEXXZ
void Owner::Run() {
    for (unsigned i = 0; i < (unsigned)(last - first); ++i)
        first[i].item->Act();
}

} // namespace fn_f1899950

// 0x002a3ba0 FUN_002a3ba0 (54 B): matches/0x002a3ba0.cpp [wrapped: conflict: Item]
// sym: ?Run@Owner@fn_002a3ba0@@QAEXXZ
namespace fn_002a3ba0 {
class Item {
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
    virtual void Act();
};
struct Entry {
    Item* item;
    char pad[12];
};
class Owner {
    char pad[0x48];
    Entry* begin;
    Entry* end;

  public:
    void Run();
};
void Owner::Run() {
    for (unsigned i = 0; i < (unsigned)(end - begin); ++i)
        begin[i].item->Act();
}
} // namespace fn_002a3ba0

namespace fn_f1899950 {

// 0x002a3be0 FUN_002a3be0 (73 B): matches/0x002a3be0.cpp
// sym: ?Run@Holder@fn_f1899950@@QAEXHH@Z
void Holder::Run(int a, int b) {
    for (unsigned i = 0; i < (unsigned)(end - begin); ++i)
        begin[i].ptr->apply(a, b);
}


// 0x002a3c30 FUN_002a3c30 (68 B): matches/0x002a3c30.cpp
// sym: ?Run@Owner@fn_f1899950@@QAEXH@Z
void Owner::Run(int x) {
    for (unsigned i = 0; i < (unsigned)(end - begin); ++i)
        begin[i].item->f19(x);
}


// 0x002a3c80 FUN_002a3c80 (58 B): equivalent/0x002a3c80.cpp
// sym: ?FUN_002a3c80@Owner@fn_f1899950@@QAEXPAVItem@2@@Z @399694e73503 @w9e5b535f1127
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002a3c80 @ 0x002a3c80
void Owner::FUN_002a3c80(Item *next) {
    if (next) next->FUN_00000000();
    if (item) item->FUN_00000001();
    item = next;
    if (next) next->FUN_00000005(this);
}

} // namespace fn_f1899950

// 0x002a3d30 pure3d::ParticleSystem::vfunc_2 (88 B): matches/0x002a3d30.cpp [wrapped: conflict: ParticleSystem]
// sym: ?vfunc_2@ParticleSystem@fn_002a3d30@@QAEPAV12@E@Z
namespace fn_002a3d30 {
extern "C" char DAT_0042d88c[];

class Ref_2a3d30 {
  public:
    virtual void vfunc0();
    virtual void Release();
};

extern "C" void __cdecl FUN_00263f30(void*);

class ParticleSystem {
  public:
    char pad[0xa4];
    Ref_2a3d30* volatile a;
    Ref_2a3d30* volatile b;
    void Cleanup_002a4ff0();
    ParticleSystem* vfunc_2(unsigned char p);
};

ParticleSystem* ParticleSystem::vfunc_2(unsigned char p) {
    volatile int* q = (volatile int*)this;
    *q = (hulk_intptr)DAT_0042d88c;
    Ref_2a3d30* x = a;
    if (x) {
        x->Release();
        a = 0;
    }
    Ref_2a3d30* y = b;
    if (y) {
        y->Release();
        b = 0;
    }
    Cleanup_002a4ff0();
    if (p & 1) {
        FUN_00263f30(this);
    }
    return this;
}
} // namespace fn_002a3d30


// 0x002a3d90 FUN_002a3d90 (135 B): equivalent/0x002a3d90.cpp [wrapped: conflict: pure3d::ParticleSystem]
// sym: ??0ParticleSystem@pure3d@fn_002a3d90@@QAE@PBV012@@Z @9a6e0180f5c4 @we399a3bc6a43
namespace fn_002a3d90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002a3d90 @ 0x002a3d90
struct Matrix {
    float m[16];
    void FUN_0022b980();
};

namespace pure3d {
class ParticleSystem;
}

class Emitter_2a3d90 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual Emitter_2a3d90 *Clone();
    virtual void Attach(pure3d::ParticleSystem *owner);
};

namespace pure3d {

class __declspec(novtable) DrawableContainerBase_2a3d90 {
public:
    virtual void v0();
    char pad04[0x54];
    void FUN_002a4e40(const ParticleSystem *src);
    DrawableContainerBase_2a3d90(const ParticleSystem *src) { FUN_002a4e40(src); }
};

class ParticleSystem : public DrawableContainerBase_2a3d90 {
public:
    virtual void v0();
    unsigned char flag58;
    char pad59[3];
    int f5c;
    int f60;
    Matrix transform;
    Emitter_2a3d90 *emitter;
    int fa8;
    ParticleSystem(const ParticleSystem *src);
};

ParticleSystem::ParticleSystem(const ParticleSystem *src) : DrawableContainerBase_2a3d90(src)
{
    flag58 = src->flag58;
    f5c = src->f5c;
    f60 = src->f60;
    emitter = 0;
    fa8 = 0;
    transform.FUN_0022b980();
    if (src->emitter != 0) {
        Emitter_2a3d90 *copy = src->emitter->Clone();
        if (copy != 0)
            copy->AddRef();
        if (emitter != 0)
            emitter->Release();
        emitter = copy;
        if (copy != 0)
            copy->Attach(this);
    }
}

}
} // namespace fn_002a3d90


// 0x002a3e20 pure3d::ParticleSystem::vfunc_4 (34 B): matches/0x002a3e20.cpp
// sym: ?vfunc_4@ParticleSystem@pure3d@@UAEPAXXZ
// Same code shape as 0x002974d0 (propagated; names are from that function)
void* pure3d::ParticleSystem::vfunc_4() {
    void* p = alloc_00263ea0(0xb0);
    if (p)
        return (void*)(((Helper_2a3e20*)p)->call_002a3d90(this));
    return (void*)(0);
}


// 0x002a3e50 pure3d::ParticleSystem::vfunc_9 (29 B): matches/0x002a3e50.cpp
// sym: ?vfunc_9@ParticleSystem@pure3d@@UAEXXZ
void pure3d::ParticleSystem::vfunc_9() {
    ((ThisCall_002a3b60*)(this))->FUN_002a3b60();
    if ((*(class Callback_2a3e50 * *)&this->f_a4))
        (*(class Callback_2a3e50 * *)&this->f_a4)->Invoke(0);
}

