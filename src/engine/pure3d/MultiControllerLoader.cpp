// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002b23c0..0x002b37a0 (kind game, layer engine, confidence high), dominant class pure3d::MultiControllerLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f35e48b8 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f35e48b8 {} using namespace fn_f35e48b8;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f35e48b8 {
class FrameController_2b26c0 {
  public:
    FrameController_2b26c0();
    virtual void vf();
    char pad[0x14];
};
struct Tail {
    int l, m;
    Tail(int x) : l(x), m(x) {}
};
class MultiController : public FrameController_2b26c0 {
  public:
    MultiController();
    virtual void vf();
    int a;
    float b, c;
    int d, e, f, x;
    float g;
    int h, i;
    char j;
    char pad2[3];
    int k;
    Tail tail;
};
class Allocated_2b2920 {
  public:
    hulk_intptr method_002b27d0(pure3d::MultiController*);
};
extern Allocated_2b2920* alloc_00263ea0(int);
class DynamicCaster_2b2c00 {
  public:
    virtual void cast();
};
class Inventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void* find(DynamicCaster_2b2c00*, __int64);
};
extern __int64 __cdecl getKey_0027b020(void*);
class DynamicCaster_2b2c30 {
  public:
    virtual void cast();
};
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void* doIt(DynamicCaster_2b2c30*, U64);
};

} // namespace fn_f35e48b8

// 0x002b23c0 pure3d::MultiControllerLoader::vfunc_2 (31 B): matches/0x002b23c0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002b23c0@@UAEPAV123@E@Z
namespace fn_002b23c0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2b23c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2b23c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002b23c0


// 0x002b2400 pure3d::OldMultiControllerLoader::vfunc_2 (31 B): matches/0x002b2400.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002b2400@@UAEPAV123@E@Z
namespace fn_002b2400 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2b2400 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2b2400 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002b2400

namespace fn_f35e48b8 {

// 0x002b26c0 FUN_002b26c0 (75 B): matches/0x002b26c0.cpp
// sym: ??0MultiController@fn_f35e48b8@@QAE@XZ
MultiController::MultiController()
    : a(0), b(30.0f), c(1.0f), d(0), e(0), f(0), x(0), g(3.402823466e38f), h(0), i(0), j(1), k(0), tail(0) {}

} // namespace fn_f35e48b8

// 0x002b2710 FUN_002b2710 (179 B): equivalent/0x002b2710.cpp [wrapped: conflict: pure3d::MultiController]
// sym: ??0MultiController@pure3d@fn_002b2710@@QAE@IMM@Z
namespace fn_002b2710 {
// STATUS: equivalent (tools/equiv.py level 3: 155 inputs, branch coverage 10/10)
// FUN_002b2710 @ 0x002b2710
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
struct FUN_00284a70 { virtual void dummy(); char pad[20]; FUN_00284a70(); };
namespace pure3d {
struct MultiController : FUN_00284a70 {
 unsigned int state; float rate; float weight; unsigned int a,b; float step; float duration; float maxTime; unsigned int c,d; unsigned char enabled; char padding[3]; unsigned int e; unsigned int* entries; unsigned int* end;
 virtual void dummy();
 MultiController(unsigned int count,float durationArg,float rateArg);
};
MultiController::MultiController(unsigned int count,float durationArg,float rateArg) {
 rate=rateArg; state=0; weight=1.0f; a=0; b=0;
 double t=(double)durationArg-1.0f;
 if(t<0.0f) t=0.0f;
 duration=durationArg; maxTime=3.402823466e+38f; c=0; d=0; enabled=1; e=0;
 step=(float)(t/rateArg);
 if(count) { entries=(unsigned int*)FUN_0008d6d0(count*4); if(entries) end=(unsigned int*)((char*)entries+count*4); else { entries=0; end=0; } }
 else { entries=0; end=0; }
 for(unsigned int i=0;i<count;++i) entries[i]=0;
}
}
} // namespace fn_002b2710


// 0x002b27d0 FUN_002b27d0 (256 B): equivalent/0x002b27d0.cpp [wrapped: conflict: pure3d::MultiController]
// sym: ??0MultiController@pure3d@fn_002b27d0@@QAE@ABU012@@Z
namespace fn_002b27d0 {
// STATUS: equivalent (tools/equiv.py level 3: 153 inputs, branch coverage 12/12)
// FUN_002b27d0 @ 0x002b27d0
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
struct Item_2b27d0 {
 virtual void retain();
 virtual void release();
 virtual void slot2();
 virtual void slot3();
 virtual Item_2b27d0* clone();
};
namespace pure3d {
struct MultiController;
}
struct FUN_00284a90 {
 virtual void slot0();
 char baseData[20];
 FUN_00284a90(const pure3d::MultiController&);
};
namespace pure3d {
struct MultiController : FUN_00284a90 {
 unsigned int fields[10];
 unsigned char flag;
 char padding[3];
 unsigned int count;
 Item_2b27d0** begin;
 Item_2b27d0** end;
 virtual void slot0();
 MultiController(const MultiController& source);
};
MultiController::MultiController(const MultiController& source) : FUN_00284a90(source) {
 for(unsigned int j=0;j<10;++j) fields[j]=source.fields[j];
 flag=source.flag;
 count=source.count;
 unsigned int n=(unsigned int)((int)((hulk_uintptr)source.end-(hulk_uintptr)source.begin)>>2);
 if(n>0) {
 begin=(Item_2b27d0 **)FUN_0008d6d0(n * sizeof(Item_2b27d0 *));
 if(begin) end=begin+n;
 else {begin=0;end=0;}
 } else {begin=0;end=0;}
 for(unsigned int i=0;i<count;++i) {
 begin[i]=0;
 Item_2b27d0* value=source.begin[i]->clone();
 Item_2b27d0** slot=begin+i;
 if(value) value->retain();
 if(*slot) (*slot)->release();
 *slot=value;
 }
}
}
} // namespace fn_002b27d0


// 0x002b28d0 FUN_002b28d0 (78 B): matches/0x002b28d0.cpp [wrapped: conflict: MultiController]
// sym: ?FUN_002b28d0@fn_002b28d0@@YIXPAVMultiController@1@@Z
namespace fn_002b28d0 {
class Controller_2b28d0 {
  public:
    virtual void A();
    virtual void B();
};
class MultiController {
  public:
    char pad[0x44];
    unsigned int count;
    Controller_2b28d0** items;
    void Finish_00284ac0();
};
extern void* hulk_at_0042e4d4;
void Free_0008d340(void*);
void __fastcall FUN_002b28d0(MultiController* self) {
    unsigned int i = 0;
    unsigned int n = self->count;
    *(void**)self = &hulk_at_0042e4d4;
    if (n > 0) {
        do {
            Controller_2b28d0** slot = &self->items[i];
            Controller_2b28d0* c = *slot;
            if (c) {
                c->B();
                *slot = 0;
            }
            ++i;
        } while (i < self->count);
    }
    if (self->items)
        Free_0008d340(self->items);
    self->Finish_00284ac0();
}
} // namespace fn_002b28d0


// 0x002b2920 pure3d::MultiController::vfunc_4 (31 B): matches/0x002b2920.cpp
// sym: ?vfunc_4@MultiController@pure3d@@UAEPAXXZ
// Same code shape as 0x0029a170 (propagated; names are from that function)
void* pure3d::MultiController::vfunc_4() {
    Allocated_2b2920* p = alloc_00263ea0(0x58);
    if (p)
        return (void*)(p->method_002b27d0(this));
    return (void*)(0);
}


// 0x002b2be0 pure3d::MultiController::vfunc_2 (30 B): matches/0x002b2be0.cpp
// sym: ??_GMultiController@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::MultiController::~MultiController() {}

namespace fn_f35e48b8 {

// 0x002b2c00 FUN_002b2c00 (42 B): matches/0x002b2c00.cpp
// sym: _FUN_002b2c00
extern "C" void* __cdecl FUN_002b2c00(void * inv, void* name) {
    __int64 key = getKey_0027b020(name);
    DynamicCaster_2b2c00 caster;
    return ((Inventory *)inv)->find(&caster, key);
}


// 0x002b2c30 FUN_002b2c30 (42 B): matches/0x002b2c30.cpp
// sym: _FUN_002b2c30
extern "C" void* __cdecl FUN_002b2c30(void * obj, void* p) {
    U64 v = getValue(p);
    DynamicCaster_2b2c30 caster;
    return ((Obj *)obj)->doIt(&caster, v);
}

} // namespace fn_f35e48b8

// 0x002b2ea0 pure3d::MultiControllerLoader::vfunc_5 (1180 B): equivalent/0x002b2ea0.cpp [wrapped: macros]
// sym: ?vfunc_5@MultiControllerLoader@fn_002b2ea0@@QAEXPAPAVMultiController_2b2ea0@pure3d@2@PA_KPAUReader@2@PAUInventory@2@@Z
inline void *operator new(size_t, void *p) throw() { return p; }
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_002b2ea0 {
// STATUS: equivalent (tools/equiv.py level 3: 2757 inputs, branch coverage 58/58)
// pure3d::MultiControllerLoader::vfunc_5 @ 0x002b2ea0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)



struct Stream {
};

struct Reader {
    char pad[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};

struct NameField {
};

namespace pure3d {
class LightAnimationController_2b2ea0;
class PoseAnimationController_2b2ea0;
class CompDrawVisibilityAnimationController_2b2ea0;
class SceneGraphTransformAnimationController_2b2ea0;
class SceneGraphVisibilityAnimationController_2b2ea0;
class TextureAnimationController_2b2ea0;
class BillboardQuadGroupAnimationController_2b2ea0;
class ParticleController_2b2ea0;
class VertexAnimController_2b2ea0;
class ProceduralVertexAnimController_2b2ea0;
class ShaderAnimationController_2b2ea0;
class FrameController_2b2ea0;
}

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Inventory {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void *v3(void *caster, unsigned __int64 key);
};

namespace pure3d {

class MultiController_2b2ea0 {
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
    virtual void v16(int mode);
    virtual void v17();
    virtual void v18(int value);
    char pad4[4];
    NameField name;
    MultiController_2b2ea0 *FUN_002b2710(int a, int b, int c);
    void FUN_002b1eb0(void *ctrl);
};

}

void *FUN_00263ea0(unsigned int size);
extern "C++" __declspec(nothrow) void * __cdecl FUN_002b2c00(void *, void *);
extern "C++" __declspec(nothrow) void * __cdecl FUN_002b2c30(void *, void *);

class MultiControllerLoader {
public:
    void vfunc_5(pure3d::MultiController_2b2ea0 **out, unsigned __int64 *outId, Reader *r, Inventory *inv);
};

struct Frame {
    int c;
    char pad[3];
    unsigned char len;
    union {
        int i;
        float f;
    } v1;
    int type;
    int v4;
    char name2[0x100];
    char name[0x100];
};

#define MAKE_CASE(CLS) \
    { \
        unsigned __int64 key = FUN_0027b020(f.name2); \
        content::LoadInventory::DynamicCaster<pure3d::CLS> *caster = \
            new (&f.c) content::LoadInventory::DynamicCaster<pure3d::CLS>; \
        ctrl = inv->v3(caster, key); \
    }

void MultiControllerLoader::vfunc_5(pure3d::MultiController_2b2ea0 **out, unsigned __int64 *outId, Reader *r, Inventory *inv)
{
    Frame f;

    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v1.i), (hulk_intptr)1, 4, (hulk_intptr)1));
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1));
    unsigned int l1 = f.len;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.name), (hulk_intptr)l1, 1, (hulk_intptr)1));
    f.name[l1] = 0;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.type), (hulk_intptr)1, 4, (hulk_intptr)1));

    int sv;
    if (f.v1.i == 0) {
        ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v1.i), (hulk_intptr)1, 4, (hulk_intptr)1));
        sv = (int)f.v1.f;
    } else {
        ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v1.i), (hulk_intptr)1, 4, (hulk_intptr)1));
        sv = f.v1.i;
    }
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v1.i), (hulk_intptr)1, 4, (hulk_intptr)1));
    if (f.v1.i != 0)
        sv = 0;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v4), (hulk_intptr)1, 4, (hulk_intptr)1));
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v1.i), (hulk_intptr)1, 4, (hulk_intptr)1));
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.c), (hulk_intptr)1, 4, (hulk_intptr)1));

    void *mem = FUN_00263ea0(0x58);
    pure3d::MultiController_2b2ea0 *mc = 0;
    if (mem)
        mc = ((pure3d::MultiController_2b2ea0 *)mem)->FUN_002b2710(f.c, f.v4, f.v1.i);
    ((owners::Target_27b040 *)&(mc->name))->FUN_0027b040((hulk_uintptr)(f.name));

    switch (f.type) {
    case 0x44464b42:
        mc->v16(5);
        break;
    case 0x445746:
        mc->v16(2);
        break;
    case 0x444c4f48:
        mc->v16(1);
        break;
    case 0x4b424446:
        mc->v16(4);
        break;
    case 0x4b434142:
        mc->v16(3);
        break;
    default:
        mc->v16(0);
        break;
    }
    mc->v18(sv);

    if (r->FUN_002669f0()) {
        do {
            if (r->FUN_00266a30() == 0x121203) {
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v4), (hulk_intptr)1, 4, (hulk_intptr)1));
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1));
                unsigned int l2 = f.len;
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.name2), (hulk_intptr)l2, 1, (hulk_intptr)1));
                f.name2[l2] = 0;
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.type), (hulk_intptr)1, 4, (hulk_intptr)1));
                void *ctrl;
                switch (f.type) {
                case 0x4d4143:
                    ctrl = FUN_002b2c00((Inventory *)inv, (void *)(const char *)(f.name2));
                    break;
                case 0x505845:
                    ctrl = FUN_002b2c30((Inventory *)inv, (void *)(const char *)(f.name2));
                    break;
                case 0x475142:
                    MAKE_CASE(BillboardQuadGroupAnimationController_2b2ea0)
                    break;
                case 0x584554:
                    MAKE_CASE(TextureAnimationController_2b2ea0)
                    break;
                case 0x584645:
                    MAKE_CASE(ParticleController_2b2ea0)
                    break;
                case 0x44414853:
                    MAKE_CASE(ShaderAnimationController_2b2ea0)
                    break;
                case 0x4554494c:
                    MAKE_CASE(LightAnimationController_2b2ea0)
                    break;
                case 0x53495653:
                    MAKE_CASE(SceneGraphVisibilityAnimationController_2b2ea0)
                    break;
                case 0x4e525450:
                    MAKE_CASE(PoseAnimationController_2b2ea0)
                    break;
                case 0x4e525453:
                    MAKE_CASE(SceneGraphTransformAnimationController_2b2ea0)
                    break;
                case 0x53495650:
                    MAKE_CASE(CompDrawVisibilityAnimationController_2b2ea0)
                    break;
                case 0x54525650:
                    MAKE_CASE(ProceduralVertexAnimController_2b2ea0)
                    break;
                case 0x58545256:
                    MAKE_CASE(VertexAnimController_2b2ea0)
                    break;
                default:
                    MAKE_CASE(FrameController_2b2ea0)
                    break;
                }
                if (ctrl)
                    mc->FUN_002b1eb0(ctrl);
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }
    *out = mc;
    *outId = FUN_002672f0(f.name, 0, 0);
}
} // namespace fn_002b2ea0
#undef MAKE_CASE
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002b3340 pure3d::OldMultiControllerLoader::vfunc_5 (735 B): equivalent/0x002b3340.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase; pure3d::OldMultiControllerLoader]
// sym: ?vfunc_5@OldMultiControllerLoader@pure3d@fn_002b3340@@UAE_KPAPAUMultiController_2b3340@3@PA_KPAUStream@3@PAUFactory_2b3340@3@@Z
namespace fn_002b3340 {
// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 14/14)
// pure3d::OldMultiControllerLoader::vfunc_5 @ 0x002b3340
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)



namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { class FrameController; }

void *__cdecl thunk_FUN_0008d690(unsigned int size);

struct Reader {
    void FUN_002647e0(void *buf, int a, int b, int c);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct ResourceName_2b3340 {
    char data[12];
    void FUN_0027b040(const char *name);
};

struct Controller_2b3340 {
    virtual void v0();
};

struct Factory_2b3340 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Controller_2b3340 *f3(content::LoadInventory::DynamicCaster<pure3d::FrameController> *caster,
                           unsigned int lo, unsigned int hi);
};

struct MultiController_2b3340 {
    char pad0[8];
    ResourceName_2b3340 name;
    MultiController_2b3340 *FUN_002b2710(int a, int b, int c);
    void FUN_002b1eb0(Controller_2b3340 *c);
};

namespace pure3d {

class OldMultiControllerLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual unsigned __int64 vfunc_5(MultiController_2b3340 **out, unsigned __int64 *id, Stream *s, Factory_2b3340 *factory);
};

unsigned __int64 OldMultiControllerLoader::vfunc_5(MultiController_2b3340 **out, unsigned __int64 *id, Stream *s, Factory_2b3340 *factory)
{
    struct Frame {
        char pad0[2];
        unsigned char len;
        unsigned char len2;
        int v10;
        int v14;
        int v18;
        int s1c;
        int s20;
        int s24;
        int s28;
        int s2c;
        int s30;
        char name[0x100];
        char name2[0x100];
        char name3[0x100];
    } f;

    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    unsigned int len = f.len;
    s->reader->FUN_002647e0(f.name, len, 1, 1);
    f.name[len] = 0;
    s->reader->FUN_002647e0(&f.v10, 1, 4, 1);
    s->reader->FUN_002647e0(&f.v18, 1, 4, 1);
    s->reader->FUN_002647e0(&f.v14, 1, 4, 1);
    s->reader->FUN_002647e0(&f.v10, 1, 4, 1);
    MultiController_2b3340 *loaded = (MultiController_2b3340 *)thunk_FUN_0008d690(0x58);
    if (loaded != 0)
        loaded = loaded->FUN_002b2710(f.v10, f.v18, f.v14);
    loaded->name.FUN_0027b040(f.name);
    if (s->FUN_002669f0()) {
        do {
            int chunk = s->FUN_00266a30();
            if (chunk == 0x48a1) {
                s->reader->FUN_002647e0(&f.v18, 1, 4, 1);
                int n = f.v18;
                if (n > 0) {
                    f.v14 = n;
                    do {
                        s->reader->FUN_002647e0(&f.len2, 1, 1, 1);
                        unsigned int l2 = f.len2;
                        s->reader->FUN_002647e0(f.name3, l2, 1, 1);
                        f.name3[l2] = 0;
                        unsigned __int64 h = FUN_0027b020(f.name3);
                        new ((void *)&f.v10) content::LoadInventory::DynamicCaster<pure3d::FrameController>;
                        Controller_2b3340 *c = factory->f3(
                            (content::LoadInventory::DynamicCaster<pure3d::FrameController> *)&f.v10,
                            (unsigned int)h, (unsigned int)(h >> 32));
                        loaded->FUN_002b1eb0(c);
                        s->reader->FUN_002647e0(&f.s2c, 1, 4, 1);
                        s->reader->FUN_002647e0(&f.s20, 1, 4, 1);
                        s->reader->FUN_002647e0(&f.s24, 1, 4, 1);
                        f.v14--;
                    } while (f.v14 != 0);
                }
            } else if (chunk == 0x48a2) {
                s->reader->FUN_002647e0(&f.len, 1, 1, 1);
                unsigned int l2 = f.len;
                s->reader->FUN_002647e0(f.name2, l2, 1, 1);
                f.name2[l2] = 0;
                unsigned __int64 h = FUN_0027b020(f.name2);
                new ((void *)&f.v10) content::LoadInventory::DynamicCaster<pure3d::FrameController>;
                Controller_2b3340 *c = factory->f3(
                    (content::LoadInventory::DynamicCaster<pure3d::FrameController> *)&f.v10,
                    (unsigned int)h, (unsigned int)(h >> 32));
                loaded->FUN_002b1eb0(c);
                s->reader->FUN_002647e0(&f.s30, 1, 4, 1);
                s->reader->FUN_002647e0(&f.s1c, 1, 4, 1);
                s->reader->FUN_002647e0(&f.s28, 1, 4, 1);
            }
            s->FUN_00266be0();
        } while (s->FUN_002669f0());
    }
    *out = loaded;
    return *id = FUN_002672f0(f.name, 0, 0);
}

}
} // namespace fn_002b3340
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

