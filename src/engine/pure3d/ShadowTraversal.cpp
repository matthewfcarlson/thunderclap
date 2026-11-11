// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a1310..0x002a18a0 (kind game, layer engine, confidence high), dominant class pure3d::ShadowTraversal
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f2e163a0 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f2e163a0 {} using namespace fn_f2e163a0;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f2e163a0 {
extern int hulk_at_003f6098;
class Sub_2a1310 {
  public:
    void Init_002a3120();
};
class IRefCount_2a1310 {
  public:
    hulk_intptr vtable;
    char pad[8 - 4];
    Sub_2a1310 sub;
    void Init();
};
} // namespace fn_f2e163a0
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned int);
#endif
namespace fn_f2e163a0 {
struct Item_2a1550 {
    float key;
    void* owner;
    void* ptr;
    void* sub;
    void* extra;
};
struct Sub_2a1550 {
    char pad[0x48];
    char* begin;
    char* end;
};
struct Geom_2a1550 {
    char pad[0x40];
    Sub_2a1550* sub;
    void* extra;
};
struct LightGroup_nv_2a15d0 {
    pure3d::LightGroup* FUN_002a1140(unsigned int count);
};
void* __cdecl FUN_00263ea0(unsigned int bytes);
struct Holder {
    char pad0[0x2c];
    pure3d::LightGroup* item;
    char pad30[4];
    unsigned int count;
    void FUN_002a15d0(unsigned int newCount);
};
extern void* hulk_at_0042d714[];
} // namespace fn_f2e163a0
void operator delete(void*);
namespace fn_f2e163a0 {
class Ref_2a17c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class DisplayTraversal_2a17c0 {
  public:
    void* vptr;
    void Fin_002c6aa0();
};
struct Sub_2a17c0 {
    char c;
    void Fini_002a3120();
};
class ShadowTraversal_2a17c0 : public DisplayTraversal_2a17c0 {
  public:
    char pad[0x18 - 4];
    void* m18;
    int m1c;
    Sub_2a17c0 sub;
    char pad2[0x2c - 0x21];
    Ref_2a17c0* m2c;
    char pad3[0x3c - 0x30];
    void* m3c;
    ~ShadowTraversal_2a17c0();
};
extern void* g_vftable_2a1810[];
extern void* g_ref_2a1810[];
class Ref_2a1810 {
  public:
    virtual void F0();
    virtual void Release();
};
class Mem_2a1810 {
  public:
    ~Mem_2a1810();
};
class DisplayTraversal_2a1810 {
  public:
    void* vptr;
    void Fin_002c6aa0();
};
class ShadowTraversal_2a1810 : public DisplayTraversal_2a1810 {
  public:
    char pad[0x14];
    void* vptr2;
    char pad1[4];
    Mem_2a1810 m20;
    char pad2[0x0b];
    Ref_2a1810* m2c;
    char pad3[0x0c];
    void* m3c;
    ShadowTraversal_2a1810* f2(unsigned char flags);
};


// 0x002a1310 FUN_002a1310 (19 B): matches/0x002a1310.cpp
// sym: ?Init@IRefCount_2a1310@fn_f2e163a0@@QAEXXZ
void IRefCount_2a1310::Init() {
    sub.Init_002a3120();
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f6098;
}


// 0x002a1330 pure3d::ShadowTraversal::vfunc_3 (1 B): matches/0x002a1330.cpp
// sym: ?FUN_002a1330@fn_f2e163a0@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002a1330() {}

} // namespace fn_f2e163a0

// 0x002a1340 FUN_002a1340 (10 B): matches/0x002a1340.cpp
// sym: ?FUN_002a1340@C_2a1340@owners@@QAEXH@Z
void owners::C_2a1340::FUN_002a1340(int x) {
    value = x;
}


// 0x002a1400 pure3d::ShadowTraversal::vfunc_4 (277 B): equivalent/0x002a1400.cpp [wrapped: conflict: pure3d::ShadowTraversal]
// sym: ?vfunc_4@ShadowTraversal@pure3d@fn_002a1400@@UAEXXZ
namespace fn_002a1400 {
// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 10/10)
// pure3d::ShadowTraversal::vfunc_4 @ 0x002a1400

struct RenderState_2a1400 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
 virtual void set(float); virtual float get();
 virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void commit();
};
struct Context { char pad[24]; RenderState_2a1400* state; };
struct Engine_2a1400 { char pad[8]; Context* context; };
struct Renderer_2a1400 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
 virtual void select(unsigned, unsigned); virtual void begin(unsigned); virtual void end(unsigned);
};
struct RenderRoot { Renderer_2a1400* renderer; };
struct Drawable { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void draw(); };
struct DrawHandle { Drawable* drawable; };
struct Entry_2a1400 { unsigned unused; unsigned key; DrawHandle* handle; unsigned rest[2]; };
struct Scope_2a1400 { void FUN_002a31d0(); void FUN_002a31a0(unsigned); void FUN_002a3250(); char data[12]; };
namespace pure3d {
struct ShadowTraversal {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 char pad04[16]; unsigned enabled; char pad18[8]; Scope_2a1400 scope; unsigned active; unsigned mode; unsigned unused34; unsigned count; Entry_2a1400* entries;
};
void ShadowTraversal::vfunc_4() {
 if (!count || !active || !enabled) return;
 float old = (*(Engine_2a1400**)&DAT_0052c2b4)->context->state->get();
 (*(Engine_2a1400**)&DAT_0052c2b4)->context->state->set(old * 0.995f);
 (*(Engine_2a1400**)&DAT_0052c2b4)->context->state->commit();
 (*(RenderRoot**)&DAT_0052c2ac)->renderer->begin(0);
 scope.FUN_002a31d0();
 scope.FUN_002a31a0(mode);
 for (unsigned i=0; i<count; ++i) {
 (*(RenderRoot**)&DAT_0052c2ac)->renderer->select(0, entries[i].key);
 entries[i].handle->drawable->draw();
 }
 scope.FUN_002a3250();
 (*(RenderRoot**)&DAT_0052c2ac)->renderer->end(0);
 (*(Engine_2a1400**)&DAT_0052c2b4)->context->state->set(old);
 (*(Engine_2a1400**)&DAT_0052c2b4)->context->state->commit();
}
}
} // namespace fn_002a1400


// 0x002a1520 pure3d::ShadowTraversal::vfunc_5 (42 B): matches/0x002a1520.cpp
// sym: ?vfunc_5@ShadowTraversal@pure3d@@UAEXXZ
void pure3d::ShadowTraversal::vfunc_5() {
    memset((*(void * *)&this->f_3c), 0, this->f_38 * 20);
    this->f_38 = 0;
}


// 0x002a1550 pure3d::ShadowTraversal::vfunc_6 (125 B): matches/0x002a1550.cpp
// sym: ?vfunc_6@ShadowTraversal@pure3d@@UAEXPAXIM@Z
 // namespace pure3d
void pure3d::ShadowTraversal::vfunc_6(void* __p0, unsigned int idx, float key) { Geom_2a1550 * g = (Geom_2a1550 *)__p0;

    Sub_2a1550* s = g->sub;
    if (!s)
        return;
    if (idx >= (unsigned)((s->end - s->begin) >> 4))
        return;
    (*(Item_2a1550 * *)&this->f_3c)[(*(int *)&this->f_38)].key = key;
    (*(Item_2a1550 * *)&this->f_3c)[(*(int *)&this->f_38)].owner = g;
    (*(Item_2a1550 * *)&this->f_3c)[(*(int *)&this->f_38)].ptr = g->sub->begin + (idx << 4);
    (*(Item_2a1550 * *)&this->f_3c)[(*(int *)&this->f_38)].sub = g->sub;
    (*(Item_2a1550 * *)&this->f_3c)[(*(int *)&this->f_38)].extra = g->extra;
    (*(int *)&this->f_38)++;
}

namespace fn_f2e163a0 {

// 0x002a15d0 FUN_002a15d0 (99 B): equivalent/0x002a15d0.cpp
// sym: ?FUN_002a15d0@Holder@fn_f2e163a0@@QAEXI@Z
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 12/12)
// FUN_002a15d0 @ 0x002a15d0
void Holder::FUN_002a15d0(unsigned int newCount) {
    if (newCount != count) {
        if (item) {
            item->vfunc_1();
            item = 0;
        }
        if (newCount != 0) {
            pure3d::LightGroup* created = 0;
            void* memory = FUN_00263ea0(0x28);
            if (memory) created = ((LightGroup_nv_2a15d0*)(((pure3d::LightGroup*)(((pure3d::LightGroup*)memory)))))->FUN_002a1140(newCount);
            if (created) created->vfunc_0();
            if (item) item->vfunc_1();
            item = created;
        }
        count = newCount;
    }
}

} // namespace fn_f2e163a0

// 0x002a16c0 FUN_002a16c0 (245 B): equivalent/0x002a16c0.cpp [wrapped: conflict: pure3d::ShadowGenerator; pure3d::ShadowTraversal]
// sym: ??0ShadowTraversal@pure3d@fn_002a16c0@@QAE@II@Z
namespace fn_002a16c0 {
// STATUS: equivalent (tools/equiv.py level 3: 19969 inputs, branch coverage 10/10)
// FUN_002a16c0 @ 0x002a16c0
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
void* __cdecl FUN_00263ea0(unsigned int);
struct Element_2a16c0 { char data[20]; };
struct DirectionalLight_2a16c0 { char pad[0x12]; unsigned char enabled; DirectionalLight_2a16c0* FUN_002a2e70(); void FUN_002a2ef0(float,float,float); void FUN_002a07a0(int); };
struct LightGroup_2a16c0 { virtual void slot0(); LightGroup_2a16c0* FUN_002a1140(unsigned int); void FUN_002a1180(int); void FUN_002a0fc0(int,DirectionalLight_2a16c0*); };
struct Setup_2a16c0 { void FUN_002a30a0(); char bytes[12]; };
struct FUN_002c6a80 { FUN_002c6a80(); virtual void baseSlot(); char p4[8]; unsigned int flags; unsigned int mode; char p14[4]; };
namespace pure3d {
struct ShadowGenerator { virtual void generatorSlot(); unsigned int zero; Setup_2a16c0 setup; LightGroup_2a16c0* list; };
struct ShadowTraversal : FUN_002c6a80 { virtual void traversalSlot(); ShadowGenerator generator; unsigned int color,count,used; Element_2a16c0 *begin,*end; ShadowTraversal(unsigned int capacity,unsigned int n); };
ShadowTraversal::ShadowTraversal(unsigned int capacity,unsigned int n) {
 generator.zero=0;
 generator.setup.FUN_002a30a0();
 color=0xffcfcfcf; count=n; used=0;
 if(capacity>0) { unsigned int bytes=capacity*20; begin=(Element_2a16c0*)FUN_0008d6d0(bytes); if(begin) end=(Element_2a16c0*)((char*)begin+bytes); else { begin=0;end=0; } } else {begin=0;end=0;}
 flags=0x230;mode=2;
 if(count>0) {
 LightGroup_2a16c0* p=(LightGroup_2a16c0*)FUN_00263ea0(0x28);
 if(p) p=p->FUN_002a1140(count);
 generator.list=p;
 p->slot0();
 DirectionalLight_2a16c0* light=(DirectionalLight_2a16c0*)FUN_00263ea0(0x68);
 if(light) light=light->FUN_002a2e70();
 light->FUN_002a2ef0(0.2018f,-0.9397f,0.2761f);
 light->FUN_002a07a0(-1);
 light->enabled=1;
 generator.list->FUN_002a1180(1);
 generator.list->FUN_002a0fc0(0,light);
 }
}
}
} // namespace fn_002a16c0

namespace fn_f2e163a0 {

// 0x002a17c0 FUN_002a17c0 (67 B): matches/0x002a17c0.cpp
// sym: ??1ShadowTraversal_2a17c0@fn_f2e163a0@@QAE@XZ
ShadowTraversal_2a17c0::~ShadowTraversal_2a17c0() {
    vptr = hulk_at_0042d714;
    _ReadWriteBarrier();
    if (m2c) {
        m2c->Release();
        m2c = 0;
    }
    if (m3c)
        operator delete(m3c);
    sub.Fini_002a3120();
    m18 = g_vftable2;
    Fin_002c6aa0();
}


// 0x002a1810 pure3d::ShadowTraversal::vfunc_2 (88 B): matches/0x002a1810.cpp
// sym: ?f2@ShadowTraversal_2a1810@fn_f2e163a0@@QAEPAV12@E@Z
ShadowTraversal_2a1810* ShadowTraversal_2a1810::f2(unsigned char flags) {
    vptr = g_vftable_2a1810;
    _ReadWriteBarrier();
    if (m2c) {
        m2c->Release();
        m2c = 0;
    }
    if (m3c)
        operator delete[](m3c);
    m20.~Mem_2a1810();
    vptr2 = g_ref_2a1810;
    Fin_002c6aa0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f2e163a0
