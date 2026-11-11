// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002aa160..0x002ad790 (kind game, layer engine, confidence high), dominant class pure3d::ParticleSystemLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/content.h"
#include "decls/data/engine/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f07ae39e {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f07ae39e {} using namespace fn_f07ae39e;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f07ae39e {
typedef void (*Code)();
void FUN_002d12f0();
void FUN_002d1310();
void FUN_002d1330();
void FUN_002d1370();
void FUN_002d1390();
void FUN_002d1410();
void FUN_002d12d0();
void FUN_002d12e0();
void FUN_002d15f0();
void FUN_002d1620();
void FUN_002d1650();
void FUN_002d1670();
void FUN_002d1490();
void FUN_002d1540();
void FUN_002d1680();
void FUN_002d16d0();
void FUN_002d16e0();
void FUN_002d1730();
void FUN_002d1740();
void FUN_002d17a0();
void FUN_002d17b0();
void FUN_002d1850();
void FUN_002d18b0();
void FUN_002d1970();
void FUN_002d1a00();
void FUN_002d1b00();
void FUN_002d1bc0();
void FUN_002d1cc0();
extern "C" void *FUN_0008d690(unsigned int size);
struct SpriteParticleUpdater_nv_2aa160 {
    pure3d::SpriteParticleUpdater* FUN_002d11f0();
    void FUN_002d1240(Code a, Code b);
    void FUN_002d1260(Code a, Code b);
    void FUN_002d1280(Code a, Code b);
    void FUN_002d12a0(Code a, Code b);
};
typedef void (*Callback_2aa300)();
extern "C" void FUN_002d12c0();
struct SpriteParticleUpdater_nv_2aa300 {
    pure3d::SpriteParticleUpdater *FUN_002d11f0();
    void FUN_002d1240(Callback_2aa300 a, Callback_2aa300 b);
    void FUN_002d1260(Callback_2aa300 a, Callback_2aa300 b);
    void FUN_002d1280(Callback_2aa300 a, Callback_2aa300 b);
    void FUN_002d12a0(Callback_2aa300 a, Callback_2aa300 b);
};
} // namespace fn_f07ae39e
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
#endif
namespace fn_f07ae39e {
class Item {
  public:
    virtual void AddRef();
};
class List {
    char pad[8];
    int count;
    Item* items[1];

  public:
    void Add(Item* item);
};
class Item_2aa500 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool Test(int);
};
class Collection_2aa500 {
  public:
    char pad[8];
    unsigned int count;
    Item_2aa500* items[1];
    Item_2aa500* Find(int arg);
};
class Item_2aa550 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool Test(void*);
};
class C_2aa550 {
  public:
    char pad[8];
    unsigned count;
    Item_2aa550* items[1];
    bool target(void* arg);
};
class Elem_2aa590 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(void*);
    virtual int v4(Elem_2aa590* a, int b);
};
class Arg_2aa590 {
  public:
    void* Get_00266c30();
};
struct Container_2aa590 {
    int m_a;
    int m_b;
    unsigned m_count;
    Elem_2aa590* arr[1];
    hulk_intptr Find(Elem_2aa590* arg, hulk_intptr p2);
};
class ParticleGeneratorHandler_2aa5e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual unsigned char vfunc_3(unsigned int);
    virtual void f4();
};
class Holder {
    char pad[8];
    unsigned int count;
    Item* first;

  public:
    void Add(Item* p);
};
class Item_2aa680 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool Test(int);
};
class Collection_2aa680 {
  public:
    char pad[8];
    unsigned int count;
    Item_2aa680* items[1];
    Item_2aa680* Find(int arg);
};
class Item_2aa6d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool Test(void*);
};
class C_2aa6d0 {
  public:
    char pad[8];
    unsigned count;
    Item_2aa6d0* items[1];
    bool target(void* arg);
};
class Obj_2aa710 {
  public:
    char pad[0x2c];
    int value;
};
class Arg_2aa720 {
  public:
    int Convert_00266c30();
};
class Item_2aa720 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual char Test(int);
    virtual void Run(int, Arg_2aa720*, int, int);
};
class Group_2aa720 {
    char pad[8];

  public:
    unsigned count;
    Item_2aa720* items[8];
    int extra;
    void Fn(hulk_intptr a, Arg_2aa720* b, int c);
};
class ParticleEmitterHandlerBase_2aa790 {
  public:
    ParticleEmitterHandlerBase_2aa790();
    virtual void B();
};
class ParticleEmitterLoader {
  public:
    class ParticleEmitterHandler : public ParticleEmitterHandlerBase_2aa790 {
      public:
        ParticleEmitterHandler();
        virtual void F();
    };
};
class Obj_2aa860 {
  public:
    char pad[0x38];
    int value;
    int Get();
};
class RenderObjectLoader_2aa870 {
  public:
    RenderObjectLoader_2aa870();
    virtual void A();
};
class OldParticleEmitterLoader : public RenderObjectLoader_2aa870 {
  public:
    OldParticleEmitterLoader();
};
class Ref_2aae10 {
  public:
    virtual void a();
    virtual void Release();
};
extern int hulk_at_0042dffc;
extern int hulk_at_003f6098;
class ParticleGeneratorLoader {
  public:
    int* vptr;
    int pad;
    unsigned count;
    Ref_2aae10* items[1];
    void cleanup();
};
extern "C" char DAT_0042e064[];
class Ref_2aae80 {
  public:
    virtual void A();
    virtual void Release();
};
class ParticleEmitterLoader_2aae80 {
  public:
    int* vt;
    int pad4;
    unsigned count;
    Ref_2aae80* items[8];
    Ref_2aae80* last;
    void BaseDestroy_002a3e90();
    void F();
};
class ParticleEmitterHandler_2aaed0 {
  public:
    virtual void Emit();
    ParticleEmitterHandler_2aaed0();
};
class DefaultParticleEmitterHandler : public ParticleEmitterHandler_2aaed0 {
  public:
    virtual void Handle();
    DefaultParticleEmitterHandler();
};
extern int hulk_at_0042e08c;
extern int vtRef_2aaf10;
class Ref_2aaf10 {
  public:
    virtual void V0();
    virtual void Release();
};
class ParticleSystemLoader_2aaf10 {
  public:
    unsigned char pad[0x14];
    unsigned int count;
    Ref_2aaf10* items[8];
    void Destroy();
};
class Item_2aaf60 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual int Key();
};
class Container_2aaf60 {
  public:
    char pad[0x14];
    unsigned count;
    Item_2aaf60* items[1];
    void Put(Item_2aaf60*);
};
class Item_2aafe0 {
  public:
    virtual void A();
    virtual void B();
};
class Container_2aafe0 {
  public:
    char pad[0x14];
    unsigned count;
    Item_2aafe0* items[1];
    void Remove(unsigned i);
};
typedef unsigned __int64 Key_2ab030;
extern char DAT_0049c7dc[];
extern char DAT_004ce770[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern void *__cdecl FUN_00263ea0(unsigned int size);
struct V3_2ab030 {
    float x, y, z;
};
struct Mat4_2ab030 {
    float m[16];
};
struct Quat_2ab030 {
    float x, y, z, w;
    void FUN_0022b650(Mat4_2ab030 *out);
};
struct NameHolder_2ab030 {
    char data[8];
    void FUN_0027af70(const NameHolder_2ab030 *other);
};
struct Stream {
};
struct Reader {
    char pad0[0x284];
    Stream *stream;
    bool FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c30();
};
class Object {
public:
    virtual void retain();
    virtual void release();
};
class Factory_2ab030 {
public:
    virtual void retain();
    virtual void release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void create(Object **out, unsigned *aux, Reader *reader, unsigned arg);
};
struct Manager_2ab030 {
};
class Emitter_2ab030 {
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
    virtual int v11();
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
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(Object *arg);
};
struct Slot16_2ab030 {
    Emitter_2ab030 *emitter;
    char pad[12];
};
class Gen_2ab030 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};
class Binder_2ab030 {
public:
    char pad0[0x38];
    struct Bind *dummy;
};
struct BindTable {
    char FUN_002aa6d0(int id);
    void FUN_002aa720(Slot16_2ab030 *slot, Reader *r, unsigned arg);
};
class ParticleSystem_2ab030 {
public:
    virtual void v0();
    char pad4[4];
    NameHolder_2ab030 name;      // 8
    char pad10[4];
    V3_2ab030 v14;
    V3_2ab030 v20;
    V3_2ab030 v2c;
    float f38;
    char pad3c[4];
    float f40;
    char pad44[4];
    Slot16_2ab030 *slots;        // 0x48
    char pad4c[0xc];
    char b58;
    float f5c;
    int f60;
    Mat4_2ab030 mat;             // 0x64
    char pad_a4_[0xa4 - 0xa4];
    ParticleSystem_2ab030 *FUN_002a3660(int a);
    void FUN_002a3c80(void *child);
};
class ParticleController_2ab030 {
public:
    char pad0[8];
    NameHolder_2ab030 name;
    ParticleController_2ab030 *FUN_002a73d0();
};
struct Frame_2ab030 {
    char pad10[3];
    unsigned char nameLen;          // 0x13
    unsigned f14;
    unsigned f18;
    int f1c;
    Object *f20;
    void *self;
    float f28;
    float f2c;
    int f30;
    float f34;
    V3_2ab030 pos;
    unsigned aux;
    char pad48[4];
    Quat_2ab030 quat;
    char name[0x100];
};
class ParticleSystemLoader_2ab030 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    char pad4[0x10];
    unsigned count;
    Gen_2ab030 *list[8];
    BindTable *table;
    unsigned FUN_002ab030(ParticleSystem_2ab030 **out, Key_2ab030 *outId, Reader *reader, unsigned arg);
};
extern int hulk_at_0042e0a8, vt2;
class Ref_2ab4b0 {
  public:
    virtual void f0();
    virtual void Release();
};
class OldParticleSystemLoader_2ab4b0 {
  public:
    void* vptr;
    char p[0x10];
    Ref_2ab4b0* a14;
    Ref_2ab4b0* a18;
    ~OldParticleSystemLoader_2ab4b0() throw();
};
struct Block { unsigned int words[16]; };
} // namespace fn_f07ae39e
void* operator new(size_t);
namespace fn_f07ae39e {
struct RenderObjectLoader_2ab7c0 {
    virtual void f0();
    virtual void f1();
    RenderObjectLoader_2ab7c0() throw();
    int x;
};
struct OldParticleEmitterLoader_2ab7c0 : RenderObjectLoader_2ab7c0 {
    OldParticleEmitterLoader_2ab7c0() throw() {}
    virtual void f0();
};
struct SimpleChunkHandler_2ab7c0 {
    virtual void f0();
    virtual void f1();
    int a;
    int b;
    int c;
    int d;
    SimpleChunkHandler_2ab7c0() throw() {
        a = 0;
        b = 0x15800;
        c = 0;
        d = 0;
    }
};
struct OldParticleSystemLoader_2ab7c0 : SimpleChunkHandler_2ab7c0 {
    OldParticleSystemLoader_2ab7c0();
    virtual void f0();
    int m14;
    RenderObjectLoader_2ab7c0* m18;
};
extern void* g_vftable_2ab830[];
class Ref_2ab830 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class OldParticleSystemLoader_2ab830 {
  public:
    void* vptr;
    char p[0x10];
    Ref_2ab830* m14;
    Ref_2ab830* m18;
    OldParticleSystemLoader_2ab830* f2(unsigned char flags);
};
} // namespace fn_f07ae39e
void operator delete(void*);
namespace fn_f07ae39e {
extern void* Alloc_0008d6d0(hulk_uintptr);
struct Buffer { char* begin; char* end; unsigned char FUN_002aba80(unsigned int count, int extra); };
void* __cdecl FUN_0008d6d0(unsigned int size);
extern "C" void * __cdecl FUN_002ab640(void *, unsigned int, const void *);
extern char DAT_004ce974[];
struct GeneratorBlendState_nv_2abba0 {
    pure3d::ParticlePointGenerator::GeneratorBlendState *FUN_002d2130(void *src);
};
class Item_2abba0 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad4[0x24];
    int count;
};
class Stream_2abba0 {
public:
};
class Reader_2abba0 {
public:
    char pad0[0x284];
    Stream_2abba0 *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};
class Parser_2abba0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(Item_2abba0 **out, int *flag, Reader_2abba0 *r, int arg);
    int FUN_00288e90();
    void FUN_00288e80(int state);
};
struct NodeVec_2abba0 {
    pure3d::ParticlePointGenerator::GeneratorBlendState **data;
    char pad4[8];
};
class Factory_2abba0 {
public:
};
class ParticlePointGenerator_2abba0 {
public:
    char pad0[0x1c];
    int used;
    char pad20[8];
    Item_2abba0 *item;
    NodeVec_2abba0 nodes;
    int a38;
    int a3c;
    int a40;
    char pad44[0x50 - 0x44];
    ParticlePointGenerator_2abba0 *FUN_002d3740();
};
struct Frame_2abba0 {
    Item_2abba0 *it;
    int count;
    int fill;
    int state;
    int flag;
    int unused;
};
struct Stream_2abd90 {
    bool FUN_002647e0(void *dst, int a, int b, int c);
};
struct Reader_2abd90 {
    char pad0[0x284];
    Stream_2abd90 *stream;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};
class AnimObj {
public:
    virtual void v0();
    virtual void v1();
    char pad04[0x28 - 4];
    int count;
};
struct GeneratorBlendState_nv_2abd90 {
    ::pure3d::ParticlePlaneGenerator::GeneratorBlendState *FUN_002d2570(void *channels);
};
struct ElemArray_2abd90 {
    ::pure3d::ParticlePlaneGenerator::GeneratorBlendState **data;
    char pad[8];
};
class ParticlePlaneGenerator_2abd90 {
public:
    virtual void v0();
    char pad04[0x1c - 4];
    int used;
    char pad20[0x28 - 0x20];
    AnimObj *anim;
    ElemArray_2abd90 array;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    char pad4c[0x60 - 0x4c];
    ParticlePlaneGenerator_2abd90 *FUN_002d3930();
};
} // namespace fn_f07ae39e
namespace content {
class ObjectLoader_2abd90 {
public:
    virtual void v0();
};
}
namespace pure3d {
class AnimationLoader_2abd90 : public content::ObjectLoader_2abd90 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned __int64 v5(AnimObj **out, unsigned __int64 *hash, Reader_2abd90 *r, int flag);
    int FUN_00288e90();
    void FUN_00288e80(int value);
};
}
namespace fn_f07ae39e {
struct Registry_2abd90 {
};
struct Stream_2abfb0 {
    char pad[0xc];
};
struct Source_2abfb0;
struct Reader_2abfb0 {
    char pad000[0x284];
    Stream_2abfb0* stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};
struct Item_2abfb0 {
};
class Releasable_2abfb0 {
public:
    virtual void AddRef();
    virtual void Release();
};
} // namespace fn_f07ae39e
namespace content {
class ObjectLoader_2abfb0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Load(Source_2abfb0** out0, unsigned int* out1, Reader_2abfb0* r, void* arg);
};
}
namespace pure3d {
class AnimationLoader_2abfb0 : public content::ObjectLoader_2abfb0 {
public:
    int FUN_00288e90();
    void FUN_00288e80(int v);
};
}
namespace fn_f07ae39e {
struct Registry_2abfb0 {
};
struct GeneratorBlendState_nv_2abfb0 {
    ::pure3d::ParticleSphereGenerator::GeneratorBlendState* FUN_002d2bd0(Item_2abfb0* item);
};
struct Source_2abfb0 : public Releasable_2abfb0 {
    char pad04[0x24];
    int count;
    Item_2abfb0** items;
};
struct ElementList_2abfb0 {
    ::pure3d::ParticleSphereGenerator::GeneratorBlendState** begin;
    ::pure3d::ParticleSphereGenerator::GeneratorBlendState** end;
    char FUN_002aba00(unsigned int n, ::pure3d::ParticleSphereGenerator::GeneratorBlendState* const* fill);
};
class ParticleSphereGenerator_2abfb0 {
public:
    virtual void v0();
    char pad04[0x18];
    int used;
    char pad20[8];
    Releasable_2abfb0* source;
    ElementList_2abfb0 elements;
    char pad34[4];
    unsigned int dim0;
    unsigned int dim1;
    char pad40[8];
    ParticleSphereGenerator_2abfb0* FUN_002d3b40();
};
struct Frame_2abfb0 {
    Source_2abfb0* out0;
    unsigned int y;
    void* z;
    unsigned int old;
    unsigned int out1;
    unsigned int pad14;
};
extern "C" char DAT_0042e0c4[];
extern "C" void thunk_FUN_00267090(void*);
class ParticleAllocatorTemplate {
  public:
    virtual ~ParticleAllocatorTemplate() {}
    char _pad1[8];
    void* mCallback1;
    char _pad2[8];
    void* mCallback2;
    void FUN_002ac570();
    void FUN_002d3d80();
};
class Chunk_2ac5b0 {
  public:
    int Type_00266c30();
};
struct DefaultParticleGeneratorHandler_nv_2ac5b0 {
    int FnA_002abba0(Chunk_2ac5b0*, int);
    int FnB_002abd90(Chunk_2ac5b0*, int);
    int FnC_002abfb0(Chunk_2ac5b0*, int);
};
typedef unsigned int u32_2ad510;
struct HandlerBase {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(u32_2ad510, u32_2ad510, u32_2ad510, u32_2ad510);
};
struct Query_2ad510 {
    void* GetType_00266c30();
};
struct DefaultParticleEmitterHandler_nv_2ad510 {
    void Dispatch_002ac610(u32_2ad510, hulk_uintptr, u32_2ad510, u32_2ad510);
};


// 0x002aa160 FUN_002aa160 (360 B): equivalent/0x002aa160.cpp
// sym: ?FUN_002aa160@fn_f07ae39e@@YAPAVSpriteParticleUpdater@pure3d@@I@Z @16d7f9ce903b @w663315fef1a8
// STATUS: equivalent (tools/equiv.py level 3: 20036 inputs, branch coverage 22/26, incomplete)
// FUN_002aa160 @ 0x002aa160
pure3d::SpriteParticleUpdater* __cdecl FUN_002aa160(unsigned int n)
{
    unsigned int code = n / 3;
    unsigned int kind = n % 3;
    unsigned int s0 = code & 3;
    unsigned int s1 = (code >> 2) & 3;
    unsigned int s2 = (code >> 4) & 3;

    void* mem = FUN_0008d690(0x28);
    pure3d::SpriteParticleUpdater* e = 0;
    if (mem)
        e = ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(((pure3d::SpriteParticleUpdater*)mem)))))->FUN_002d11f0();

    switch (kind) {
    case 0: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1240(FUN_002d1310, FUN_002d12f0); break;
    case 1: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1240(FUN_002d1370, FUN_002d1330); break;
    case 2: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1240(FUN_002d1410, FUN_002d1390); break;
    }
    switch (s0) {
    case 0: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1260(FUN_002d12e0, FUN_002d12d0); break;
    case 1: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1260(FUN_002d1620, FUN_002d15f0); break;
    case 2: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1260(FUN_002d1670, FUN_002d1650); break;
    case 3: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1260(FUN_002d1540, FUN_002d1490); break;
    }
    switch (s1) {
    case 0: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1280(FUN_002d12e0, FUN_002d12d0); break;
    case 1: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1280(FUN_002d16d0, FUN_002d1680); break;
    case 2: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1280(FUN_002d1730, FUN_002d16e0); break;
    case 3: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1280(FUN_002d17a0, FUN_002d1740); break;
    }
    switch (s2) {
    case 0: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d12a0(FUN_002d1850, FUN_002d17b0); break;
    case 1: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d12a0(FUN_002d1970, FUN_002d18b0); break;
    case 2: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d12a0(FUN_002d1b00, FUN_002d1a00); break;
    case 3: ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d12a0(FUN_002d1cc0, FUN_002d1bc0); break;
    }
    return e;
}


// 0x002aa300 FUN_002aa300 (387 B): equivalent/0x002aa300.cpp
// sym: ?FUN_002aa300@fn_f07ae39e@@YAPAVSpriteParticleUpdater@pure3d@@IIIMM@Z @640fcc0e8232 @w08a604f7f2d0
// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 26/26)
// FUN_002aa300 @ 0x002aa300
pure3d::SpriteParticleUpdater *FUN_002aa300(unsigned int kind, unsigned int mode, unsigned int format, float a4, float a5)
{
    pure3d::SpriteParticleUpdater *e = 0;
    void *mem = FUN_0008d690(0x28);
    if (mem)
        e = ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(((pure3d::SpriteParticleUpdater *)mem)))))->FUN_002d11f0();

    if (a4 > 0.0f) {
        if (a5 > 0.0f)
            ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d12a0(FUN_002d1cc0, FUN_002d1bc0);
        else
            ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d12a0(FUN_002d1970, FUN_002d18b0);
    } else {
        if (a5 > 0.0f)
            ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d12a0(FUN_002d1b00, FUN_002d1a00);
        else
            ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d12a0(FUN_002d12e0, FUN_002d12c0);
    }

    if (format == 0x424752)
        ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1280(FUN_002d16d0, FUN_002d1680);
    else if (format == 0x41)
        ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1280(FUN_002d1730, FUN_002d16e0);
    else if (format == 0x41424752)
        ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1280(FUN_002d17a0, FUN_002d1740);
    else
        ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d12a0(FUN_002d12e0, FUN_002d12c0);

    if (mode == 0x4e494c)
        ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1260(FUN_002d1620, FUN_002d15f0);
    else if (mode == 0x444e4152)
        ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1260(FUN_002d1540, FUN_002d1490);
    else if (mode == 0x43455053)
        ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1260(FUN_002d1670, FUN_002d1650);
    else
        ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1260(FUN_002d12e0, FUN_002d12d0);

    if (kind == 0x43455053)
        ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1240(FUN_002d1370, FUN_002d1330);
    else if (kind == 0x4c414f4d)
        ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1240(FUN_002d1410, FUN_002d1390);
    else
        ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater*)(e))))->FUN_002d1240(FUN_002d1310, FUN_002d12f0);
    return e;
}


// 0x002aa4c0 FUN_002aa4c0 (53 B): matches/0x002aa4c0.cpp
// sym: ?Add@List@fn_f07ae39e@@QAEXPAVItem@2@@Z
void List::Add(Item* item) {
    if (item) {
        memmove(&items[1], &items[0], count * 4);
        items[0] = item;
        item->AddRef();
        ++count;
    }
}


// 0x002aa500 FUN_002aa500 (65 B): matches/0x002aa500.cpp
// sym: ?Find@Collection_2aa500@fn_f07ae39e@@QAEPAVItem_2aa500@2@H@Z
Item_2aa500* Collection_2aa500::Find(int arg) {
    unsigned int i = 0;
    if (count > 0) {
        do {
            if (items[i]->Test(arg) == true)
                return items[i];
            ++i;
        } while (i < count);
    }
    return 0;
}


// 0x002aa550 FUN_002aa550 (63 B): matches/0x002aa550.cpp
// sym: ?target@C_2aa550@fn_f07ae39e@@QAE_NPAX@Z
bool C_2aa550::target(void* arg) {
    unsigned i = 0;
    while (i < count) {
        if (items[i]->Test(arg) == 1)
            return true;
        ++i;
    }
    return false;
}


// 0x002aa590 FUN_002aa590 (74 B): matches/0x002aa590.cpp
// sym: ?Find@Container_2aa590@fn_f07ae39e@@QAEHPAVElem_2aa590@2@H@Z
hulk_intptr Container_2aa590::Find(Elem_2aa590* arg, hulk_intptr p2) {
    unsigned i = 0;
    Elem_2aa590** p = arr;
    if (m_count > 0) {
        do {
            if (arr[i]->v3(((Arg_2aa590*)arg)->Get_00266c30()) == 1)
                return arr[i]->v4(arg, p2);
            i++;
        } while (i < m_count);
    }
    return 0;
}

} // namespace fn_f07ae39e

// 0x002aa5e0 pure3d::DefaultParticleGeneratorHandler::vfunc_3 (28 B): matches/0x002aa5e0.cpp
// sym: ?vfunc_3@DefaultParticleGeneratorHandler@pure3d@@UAEEI@Z
unsigned char pure3d::DefaultParticleGeneratorHandler::vfunc_3(unsigned int x) {
    return x >= 0x15b00 && x <= 0x15b02;
}


// 0x002aa620 pure3d::ParticleGeneratorLoader::ParticleGeneratorHandler::vfunc_2 (31 B): matches/0x002aa620.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002aa620@@UAEPAV123@E@Z
namespace fn_002aa620 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class NonCopyable_2aa620 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public NonCopyable_2aa620 {
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
} // namespace fn_002aa620

namespace fn_f07ae39e {

// 0x002aa640 FUN_002aa640 (53 B): matches/0x002aa640.cpp
// sym: ?Add@Holder@fn_f07ae39e@@QAEXPAVItem@2@@Z
void Holder::Add(Item* p) {
    if (p) {
        memmove(&first + 1, &first, count * 4);
        first = p;
        p->AddRef();
        ++count;
    }
}


// 0x002aa680 FUN_002aa680 (65 B): matches/0x002aa680.cpp
// sym: ?Find@Collection_2aa680@fn_f07ae39e@@QAEPAVItem_2aa680@2@H@Z
// Same code shape as 0x002aa500 (propagated; names are from that function)
Item_2aa680* Collection_2aa680::Find(int arg) {
    unsigned int i = 0;
    if (count > 0) {
        do {
            if (items[i]->Test(arg) == true)
                return items[i];
            ++i;
        } while (i < count);
    }
    return 0;
}


// 0x002aa6d0 FUN_002aa6d0 (63 B): matches/0x002aa6d0.cpp
// sym: ?target@C_2aa6d0@fn_f07ae39e@@QAE_NPAX@Z
// Same code shape as 0x002aa550 (propagated; names are from that function)
bool C_2aa6d0::target(void* arg) {
    unsigned i = 0;
    while (i < count) {
        if (items[i]->Test(arg) == 1)
            return true;
        ++i;
    }
    return false;
}


// 0x002aa710 FUN_002aa710 (4 B): matches/0x002aa710.cpp
// sym: ?FUN_002aa710@fn_f07ae39e@@YIHPAVObj_2aa710@1@@Z
int __fastcall FUN_002aa710(Obj_2aa710* self) {
    return self->value;
}


// 0x002aa720 FUN_002aa720 (94 B): matches/0x002aa720.cpp
// sym: ?Fn@Group_2aa720@fn_f07ae39e@@QAEXHPAVArg_2aa720@2@H@Z
void Group_2aa720::Fn(hulk_intptr a, Arg_2aa720* b, int c) {
    unsigned i = 0;
    if (count > 0) {
        Item_2aa720** p = items;
        do {
            if ((*p)->Test(b->Convert_00266c30()) == 1) {
                items[i]->Run(a, b, c, extra);
                return;
            }
            ++i;
            ++p;
        } while (i < count);
    }
}

} // namespace fn_f07ae39e

// 0x002aa780 pure3d::DefaultParticleEmitterHandler::vfunc_3 (14 B): matches/0x002aa780.cpp
// sym: ?vfunc_3@DefaultParticleEmitterHandler@pure3d@@UAEDH@Z
char pure3d::DefaultParticleEmitterHandler::vfunc_3(hulk_intptr __p0) { const void * p = (const void *)__p0;

    return p == (const char*)0x15900;
}

namespace fn_f07ae39e {

// 0x002aa790 FUN_002aa790 (18 B): matches/0x002aa790.cpp
// sym: ??0ParticleEmitterHandler@ParticleEmitterLoader@fn_f07ae39e@@QAE@XZ
ParticleEmitterLoader::ParticleEmitterHandler::ParticleEmitterHandler() {}

} // namespace fn_f07ae39e

// 0x002aa7c0 pure3d::ParticleEmitterLoader::ParticleEmitterHandler::vfunc_2 (30 B): matches/0x002aa7c0.cpp
// sym: ??_GParticleEmitterHandler@ParticleEmitterLoader@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::ParticleEmitterLoader::ParticleEmitterHandler::~ParticleEmitterHandler() {}

namespace fn_f07ae39e {

// 0x002aa860 FUN_002aa860 (4 B): matches/0x002aa860.cpp
// sym: ?Get@Obj_2aa860@fn_f07ae39e@@QAEHXZ
int Obj_2aa860::Get() {
    return value;
}


// 0x002aa870 FUN_002aa870 (18 B): matches/0x002aa870.cpp
// sym: ??0OldParticleEmitterLoader@fn_f07ae39e@@QAE@XZ
OldParticleEmitterLoader::OldParticleEmitterLoader() : RenderObjectLoader_2aa870() {}


// 0x002aae10 FUN_002aae10 (61 B): matches/0x002aae10.cpp
// sym: ?cleanup@ParticleGeneratorLoader@fn_f07ae39e@@QAEXXZ
void ParticleGeneratorLoader::cleanup() {
    vptr = &hulk_at_0042dffc;
    for (unsigned i = 0; i < count; ++i) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
    }
    vptr = &hulk_at_003f6098;
}

} // namespace fn_f07ae39e

// 0x002aae60 pure3d::DefaultParticleGeneratorHandler::vfunc_2 (31 B): matches/0x002aae60.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002aae60@@UAEPAV123@E@Z
namespace fn_002aae60 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ParticleGeneratorHandler_2aae60 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public ParticleGeneratorHandler_2aae60 {
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
} // namespace fn_002aae60

namespace fn_f07ae39e {

// 0x002aae80 FUN_002aae80 (80 B): matches/0x002aae80.cpp
// sym: ?F@ParticleEmitterLoader_2aae80@fn_f07ae39e@@QAEXXZ
void ParticleEmitterLoader_2aae80::F() {
    unsigned i = 0;
    vt = (int*)((hulk_intptr)DAT_0042e064);
    if (count > 0) {
        do {
            if (items[i]) {
                items[i]->Release();
                items[i] = 0;
            }
            ++i;
        } while (i < count);
    }
    if (last) {
        last->Release();
        last = 0;
    }
    BaseDestroy_002a3e90();
}


// 0x002aaed0 FUN_002aaed0 (18 B): matches/0x002aaed0.cpp
// sym: ??0DefaultParticleEmitterHandler@fn_f07ae39e@@QAE@XZ
DefaultParticleEmitterHandler::DefaultParticleEmitterHandler() {}


// 0x002aaf10 FUN_002aaf10 (80 B): matches/0x002aaf10.cpp
// sym: ?Destroy@ParticleSystemLoader_2aaf10@fn_f07ae39e@@QAEXXZ
void ParticleSystemLoader_2aaf10::Destroy() {
    unsigned int i = 0;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_0042e08c;
    while (i < count) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
        ++i;
    }
    if (items[8]) {
        items[8]->Release();
        items[8] = 0;
    }
    *(hulk_intptr*)this = (hulk_intptr)&vtRef_2aaf10;
}


// 0x002aaf60 FUN_002aaf60 (116 B): matches/0x002aaf60.cpp
// sym: ?Put@Container_2aaf60@fn_f07ae39e@@QAEXPAVItem_2aaf60@2@@Z
void Container_2aaf60::Put(Item_2aaf60* item) {
    if (item) {
        unsigned i = 0;
        while (i < count && items[i]->Key() != item->Key())
            ++i;
        item->A();
        if (items[i])
            items[i]->B();
        items[i] = item;
        if (i == count)
            ++count;
    }
}


// 0x002aafe0 FUN_002aafe0 (74 B): matches/0x002aafe0.cpp
// sym: ?Remove@Container_2aafe0@fn_f07ae39e@@QAEXI@Z
void Container_2aafe0::Remove(unsigned i) {
    if (i < count) {
        Item_2aafe0* p = items[i];
        if (p) {
            p->B();
            items[i] = 0;
        }
        unsigned j = i + 1;
        if (j < count) {
            do {
                items[j - 1] = items[j];
                ++j;
            } while (j < count);
        }
        --count;
    }
}


// 0x002ab030 pure3d::ParticleSystemLoader::vfunc_5 (1105 B): equivalent/0x002ab030.cpp
// sym: ?FUN_002ab030@ParticleSystemLoader_2ab030@fn_f07ae39e@@QAEIPAPAVParticleSystem_2ab030@2@PA_KPAUReader@2@I@Z @02c0af997e56 @wc86fdc0b9542
// STATUS: equivalent (tools/equiv.py level 3: 5724 inputs, branch coverage 43/44, incomplete)
// pure3d::ParticleSystemLoader::vfunc_5 @ 0x002ab030
// pure3d::ParticleSystemLoader::vfunc_5 @ 0x002ab030
unsigned ParticleSystemLoader_2ab030::FUN_002ab030(ParticleSystem_2ab030 **out, Key_2ab030 *outId, Reader *reader, unsigned arg)
{
    Frame_2ab030 f;
    f.self = this;
    ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&f.f28), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&f.nameLen), (hulk_intptr)1, 1, (hulk_intptr)1);
    unsigned char len = f.nameLen;
    ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(f.name), (hulk_intptr)len, 1, (hulk_intptr)1);
    f.name[len] = 0;
    ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&f.f1c), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&f.f18), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&f.f14), (hulk_intptr)1, 4, (hulk_intptr)1);
    bool flag = f.f14 != 0;
    ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&f.quat), (hulk_intptr)4, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&f.pos), (hulk_intptr)3, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&f.f14), (hulk_intptr)1, 4, (hulk_intptr)1);
    void *mem = FUN_00263ea0(0xb0);
    ParticleSystem_2ab030 *p;
    if (mem)
        p = ((ParticleSystem_2ab030 *)mem)->FUN_002a3660(f.f14);
    else
        p = 0;
    ((owners::Target_27b040 *)&(p->name))->FUN_0027b040((hulk_uintptr)(f.name));
    p->f60 = f.f1c;
    p->f5c = (float)f.f18;
    p->b58 = flag;
    f.quat.FUN_0022b650(&p->mat);
    ((owners::Target_22be40 *)&(p->mat))->FUN_0022be40((const int *)(const V3_2ab030 *)(&f.pos));
    int off = 0;
    while (reader->FUN_002669f0()) {
        int id = reader->FUN_00266a30();
        switch (id) {
        case 0x10003:
            ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&p->v14), (hulk_intptr)3, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&p->v20), (hulk_intptr)3, 4, (hulk_intptr)1);
            break;
        case 0x10004:
            ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&p->v2c), (hulk_intptr)3, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&f.f2c), (hulk_intptr)1, 4, (hulk_intptr)1);
            p->f38 = f.f2c;
            break;
        case 0x121201: {
            Factory_2ab030 *factory = (Factory_2ab030 *)FUN_00344e74(((void *)((owners::Obj_265310 *)((*(Manager_2ab030**)&DAT_00527c58)))->FUN_00265310((hulk_intptr)0x121201)), 0, DAT_0049c7dc, DAT_004ce770, 0);
            factory->retain();
            f.f20 = 0;
            factory->create(&f.f20, &f.aux, reader, arg);
            if (f.f20) {
                void *child = FUN_00344e74(f.f20, 0, DAT_0049fd74, DAT_0049fd9c, 0);
                if (child) {
                    p->FUN_002a3c80(child);
                    factory->release();
                    break;
                }
                if (f.f20) {
                    f.f20->release();
                    f.f20 = 0;
                }
            }
            factory->release();
            break;
        }
        case 0x122000: {
            ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&f.f34), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(reader->stream))->FUN_002647e0((hulk_intptr)(&f.f28), (hulk_intptr)1, 4, (hulk_intptr)1);
            float v = f.f28;
            if (v >= 0.0f) {
                if (!(v <= 1.0f))
                    v = 1.0f;
            } else {
                v = 0.0f;
            }
            p->f40 = v;
            break;
        }
        default: {
            ParticleSystemLoader_2ab030 *self = (ParticleSystemLoader_2ab030 *)f.self;
            if (self->table->FUN_002aa6d0(reader->FUN_00266c30()) == 1) {
                self->table->FUN_002aa720(&p->slots[off], reader, arg);
                Emitter_2ab030 *e = p->slots[off].emitter;
                unsigned i;
                for (i = 0; i < self->count; i++) {
                    f.f30 = self->list[i]->v3();    // the original keeps the id in this frame word across the call
                    if (f.f30 == e->v11()) {
                        e->v25((Object *)self->list[i]);
                        break;
                    }
                }
                off++;
            }
            break;
        }
        }
        reader->FUN_00266be0();
    }
    if (*(void **)((char *)p + 0xa4) == 0) {
        void *m2 = FUN_00263ea0(0x60);
        ParticleController_2ab030 *c;
        if (m2)
            c = ((ParticleController_2ab030 *)m2)->FUN_002a73d0();
        else
            c = 0;
        c->name.FUN_0027af70(&p->name);
        p->FUN_002a3c80(c);
    }
    *out = p;
    Key_2ab030 key = FUN_002672f0(f.name, 0, 0);
    *outId = key;
    return (unsigned)key;
}

} // namespace fn_f07ae39e

// 0x002ab490 pure3d::OldParticleSystemLoader::OldParticleEmitterLoader::vfunc_2 (30 B): matches/0x002ab490.cpp
// sym: ??_GOldParticleEmitterLoader@OldParticleSystemLoader@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::OldParticleSystemLoader::OldParticleEmitterLoader::~OldParticleEmitterLoader() {}

namespace fn_f07ae39e {

// 0x002ab4b0 FUN_002ab4b0 (55 B): matches/0x002ab4b0.cpp
// sym: ??1OldParticleSystemLoader_2ab4b0@fn_f07ae39e@@QAE@XZ
OldParticleSystemLoader_2ab4b0::~OldParticleSystemLoader_2ab4b0() throw() {
    vptr = &hulk_at_0042e0a8;
    _ReadWriteBarrier();
    if (a14) {
        a14->Release();
        a14 = 0;
    }
    if (a18) {
        a18->Release();
        a18 = 0;
    }
    vptr = &vt2;
}


// 0x002ab530 FUN_002ab530 (40 B): matches/0x002ab530.cpp
// sym: ?copyWords@fn_f07ae39e@@YAPAHPAHHPBH@Z
int* copyWords(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}

} // namespace fn_f07ae39e

// 0x002ab560 FUN_002ab560 (40 B): matches/0x002ab560.cpp [wrapped: same definition as 0x002ab530 in this TU]
// sym: ?copyWords@fn_002ab560@@YAPAHPAHHPBH@Z
namespace fn_002ab560 {
// Same code shape as 0x002ab530 (propagated; names are from that function)
int* copyWords(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}
} // namespace fn_002ab560


// 0x002ab590 FUN_002ab590 (40 B): matches/0x002ab590.cpp [wrapped: same definition as 0x002ab530 in this TU]
// sym: ?copyWords@fn_002ab590@@YAPAHPAHHPBH@Z
namespace fn_002ab590 {
// Same code shape as 0x002ab530 (propagated; names are from that function)
int* copyWords(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}
} // namespace fn_002ab590


// 0x002ab5c0 FUN_002ab5c0 (40 B): matches/0x002ab5c0.cpp [wrapped: same definition as 0x002ab530 in this TU]
// sym: ?copyWords@fn_002ab5c0@@YAPAHPAHHPBH@Z
namespace fn_002ab5c0 {
// Same code shape as 0x002ab530 (propagated; names are from that function)
int* copyWords(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}
} // namespace fn_002ab5c0


// 0x002ab5f0 FUN_002ab5f0 (40 B): matches/0x002ab5f0.cpp [wrapped: same definition as 0x002ab530 in this TU]
// sym: ?copyWords@fn_002ab5f0@@YAPAHPAHHPBH@Z
namespace fn_002ab5f0 {
// Same code shape as 0x002ab530 (propagated; names are from that function)
int* copyWords(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}
} // namespace fn_002ab5f0

namespace fn_f07ae39e {

// 0x002ab640 FUN_002ab640 (51 B): equivalent/0x002ab640.cpp
// sym: _FUN_002ab640 @e2ac412f5f8f @we6d3b59a8521
// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 6/6)
// FUN_002ab640 @ 0x002ab640
extern "C" void * __cdecl FUN_002ab640(void * destination_, unsigned int count, const void * source)
{
    Block * destination = (Block *)destination_;
    if (count == 0) return (Block *)destination;
    do {
        if (destination != 0) {
            for (int i = 0; i < 16; ++i)
                destination->words[i] = ((const Block *)source)->words[i];
        }
        ++destination;
    } while (--count != 0);
    return (Block *)destination;
}

} // namespace fn_f07ae39e

// 0x002ab680 pure3d::ParticleGeneratorLoader::vfunc_2 (30 B): matches/0x002ab680.cpp
// sym: ??_GParticleGeneratorLoader@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::ParticleGeneratorLoader::~ParticleGeneratorLoader() {}


// 0x002ab6a0 FUN_002ab6a0 (216 B): equivalent/0x002ab6a0.cpp [wrapped: conflict: memmove; pure3d::DefaultParticleGeneratorHandler; pure3d::ParticleEmitterLoader; pure3d::ParticleGeneratorLoader]
// sym: ?init@ParticleEmitterLoader@pure3d@fn_002ab6a0@@QAEPAU123@XZ @160e54774864 @wf37d415a0792
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_002ab6a0 {
// STATUS: equivalent (tools/equiv.py level 3: 195 inputs, branch coverage 10/10)
// FUN_002ab6a0 @ 0x002ab6a0
extern "C" void* __cdecl FUN_0008d690(unsigned int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
void* __cdecl memmove(void*, const void*, unsigned int);
#endif


namespace pure3d {
struct DefaultParticleGeneratorHandler {
 virtual void slot0();
 unsigned int value;
};
struct ParticleGeneratorLoader {
 virtual void slot0();
 virtual void slot1();
 unsigned int value;
 unsigned int count;
 DefaultParticleGeneratorHandler* handlers[8];
};
struct ParticleEmitterLoader {
 virtual void slot0();
 unsigned int baseValue;
 unsigned int value;
 unsigned int values[8];
 ParticleGeneratorLoader* loader;
 void FUN_002a3e80();
 ParticleEmitterLoader* init();
};
ParticleEmitterLoader* ParticleEmitterLoader::init() {
 FUN_002a3e80();
 new (this) ParticleEmitterLoader;
 value=0; loader=0;
 for(int i=0;i<8;++i) values[i]=0;
 ParticleGeneratorLoader* p=(ParticleGeneratorLoader*)FUN_0008d690((int)sizeof(ParticleGeneratorLoader));
 if(p) {
  new (p) ParticleGeneratorLoader;
  p->value=0; p->count=0;
  for(int j=0;j<8;++j) p->handlers[j]=0;
 }
 if(p) p->slot0();
 if(loader) loader->slot1();
 loader=p;
 DefaultParticleGeneratorHandler* h=(DefaultParticleGeneratorHandler*)FUN_0008d690((int)sizeof(DefaultParticleGeneratorHandler));
 if(h) { new(h) DefaultParticleGeneratorHandler; h->value=0; }
 p=loader;
 if(h) {
  memmove(p->handlers+1,p->handlers,p->count*4);
  p->handlers[0]=h;
  h->slot0();
  ++p->count;
 }
 return this;
}
}
} // namespace fn_002ab6a0


// 0x002ab780 pure3d::ParticleEmitterLoader::vfunc_2 (30 B): matches/0x002ab780.cpp
// sym: ??_GParticleEmitterLoader@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::ParticleEmitterLoader::~ParticleEmitterLoader() {}


// 0x002ab7a0 pure3d::ParticleSystemLoader::vfunc_2 (30 B): matches/0x002ab7a0.cpp
// sym: ??_GParticleSystemLoader@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::ParticleSystemLoader::~ParticleSystemLoader() {}

namespace fn_f07ae39e {

// 0x002ab7c0 FUN_002ab7c0 (99 B): matches/0x002ab7c0.cpp
// sym: ??0OldParticleSystemLoader_2ab7c0@fn_f07ae39e@@QAE@XZ
OldParticleSystemLoader_2ab7c0::OldParticleSystemLoader_2ab7c0() {
    m14 = 0;
    m18 = 0;
    OldParticleEmitterLoader_2ab7c0* t = new OldParticleEmitterLoader_2ab7c0;
    _ReadWriteBarrier();
    RenderObjectLoader_2ab7c0* e = t;
    if (e)
        e->f0();
    if (m18)
        m18->f1();
    m18 = e;
}


// 0x002ab830 pure3d::OldParticleSystemLoader::vfunc_2 (75 B): matches/0x002ab830.cpp
// sym: ?f2@OldParticleSystemLoader_2ab830@fn_f07ae39e@@QAEPAV12@E@Z
OldParticleSystemLoader_2ab830* OldParticleSystemLoader_2ab830::f2(unsigned char flags) {
    vptr = g_vftable_2ab830;
    _ReadWriteBarrier();
    if (m14) {
        m14->f1();
        m14 = 0;
    }
    if (m18) {
        m18->f1();
        m18 = 0;
    }
    vptr = g_base_vftable;
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f07ae39e

// 0x002ab880 FUN_002ab880 (95 B): matches/0x002ab880.cpp
// sym: ?FUN_002ab880@Buffer_2ab880@owners@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool owners::Buffer_2ab880::FUN_002ab880(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            Init(p, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}


// 0x002ab8e0 FUN_002ab8e0 (95 B): matches/0x002ab8e0.cpp
// sym: ?FUN_002ab8e0@Buffer_2ab8e0@owners@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool owners::Buffer_2ab8e0::FUN_002ab8e0(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            Init(p, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}


// 0x002ab940 FUN_002ab940 (95 B): matches/0x002ab940.cpp
// sym: ?FUN_002ab940@Buffer_2ab940@owners@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool owners::Buffer_2ab940::FUN_002ab940(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            Init(p, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}


// 0x002ab9a0 FUN_002ab9a0 (95 B): matches/0x002ab9a0.cpp
// sym: ?FUN_002ab9a0@Buffer_2ab9a0@owners@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool owners::Buffer_2ab9a0::FUN_002ab9a0(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            Init(p, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}


// 0x002aba00 FUN_002aba00 (95 B): matches/0x002aba00.cpp
// sym: ?FUN_002aba00@Buffer_2aba00@owners@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool owners::Buffer_2aba00::FUN_002aba00(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            Init(p, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}

namespace fn_f07ae39e {

// 0x002aba80 FUN_002aba80 (93 B): equivalent/0x002aba80.cpp
// sym: ?FUN_002aba80@Buffer@fn_f07ae39e@@QAEEIH@Z @91fb665a4e56 @w79e4002785b8
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002aba80 @ 0x002aba80
unsigned char Buffer::FUN_002aba80(unsigned int count, int extra) {
    if (begin) return 0;
    if (count) {
        char* memory = (char*)FUN_0008d6d0(count * 64);
        begin = memory;
        if (memory) {
            end = memory + count * 64;
            FUN_002ab640(memory, count, (const void *)(hulk_uintptr)(int)extra);
            return 1;
        }
    }
    begin = 0;
    end = 0;
    return 0;
}


// 0x002abba0 FUN_002abba0 (481 B): equivalent/0x002abba0.cpp
// sym: ?FUN_002abba0@fn_f07ae39e@@YGPAVParticlePointGenerator_2abba0@1@PAVReader_2abba0@1@H@Z @1950946819ff @wdead471cacde
// STATUS: equivalent (tools/equiv.py level 3: 15667 inputs, branch coverage 18/18)
// FUN_002abba0 @ 0x002abba0
ParticlePointGenerator_2abba0 *__stdcall FUN_002abba0(Reader_2abba0 *r, int arg)
{
    Frame_2abba0 f;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.state), (hulk_intptr)1, 4, (hulk_intptr)1);
    void *mem = FUN_00263ea0(0x50);
    ParticlePointGenerator_2abba0 *res;
    if (mem)
        res = ((ParticlePointGenerator_2abba0 *)mem)->FUN_002d3740();
    else
        res = 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    res->a38 = f.count;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    res->a3c = f.count;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    res->a40 = f.count;

    while (r->FUN_002669f0()) {
        int id = r->FUN_00266a30();
        if (id == 0x121000) {
            Parser_2abba0 *p = (Parser_2abba0 *)FUN_00344e74(((void *)((owners::Obj_265310 *)((*(Factory_2abba0**)&DAT_00527c58)))->FUN_00265310((hulk_intptr)id)), 0, DAT_0049c7dc, DAT_004ce974, 0);
            p->AddRef();
            f.state = p->FUN_00288e90();
            p->FUN_00288e80(1);
            p->v5(&f.it, &f.flag, r, arg);
            Item_2abba0 *it = f.it;
            if (it) {
                it->AddRef();
                if (res->item)
                    res->item->Release();
                res->item = it;
                f.count = f.it->count;
                f.fill = 0;
                ((owners::Buffer_2ab940 *)&(res->nodes))->FUN_002ab940((unsigned int)(f.count), &f.fill);
                for (int i = 0; i < f.count; i++) {
                    pure3d::ParticlePointGenerator::GeneratorBlendState *n;
                    void *m = FUN_0008d690(0x14);
                    if (m)
                        n = ((GeneratorBlendState_nv_2abba0*)(((pure3d::ParticlePointGenerator::GeneratorBlendState*)(((pure3d::ParticlePointGenerator::GeneratorBlendState *)m)))))->FUN_002d2130(((void *)((owners::Target_288a10 *)(f.it))->FUN_00288a10(i)));
                    else
                        n = 0;
                    res->nodes.data[res->used] = n;
                    res->nodes.data[res->used]->vfunc_0();
                    res->used++;
                }
            }
            p->FUN_00288e80(f.state);
            p->Release();
        }
        r->FUN_00266be0();
    }
    return res;
}


// 0x002abd90 FUN_002abd90 (543 B): equivalent/0x002abd90.cpp
// sym: ?FUN_002abd90@fn_f07ae39e@@YGPAVParticlePlaneGenerator_2abd90@1@PAUReader_2abd90@1@H@Z @c6818c7e2e0e @wdd76bf600ef5
// STATUS: equivalent (tools/equiv.py level 3: 15652 inputs, branch coverage 18/18)
// FUN_002abd90 @ 0x002abd90
ParticlePlaneGenerator_2abd90 * __stdcall FUN_002abd90(Reader_2abd90 *r, int flag)
{
    struct Frame {
        AnimObj *obj;
        int b;
        int d;
        int a;
        unsigned __int64 hash;
    } fr;

    r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
    void *mem = FUN_00263ea0(0x60);
    ParticlePlaneGenerator_2abd90 *g = 0;
    if (mem)
        g = ((ParticlePlaneGenerator_2abd90 *)mem)->FUN_002d3930();
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    g->f38 = fr.b;
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    g->f3c = fr.b;
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    g->f40 = fr.b;
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    g->f44 = fr.b;
    r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
    g->f48 = fr.b;

    if (r->FUN_002669f0()) {
        do {
            int id = r->FUN_00266a30();
            if (id == 0x121000) {
                pure3d::AnimationLoader_2abd90 *al = dynamic_cast<pure3d::AnimationLoader_2abd90 *>(((content :: ObjectLoader_2abd90 *)((owners::Obj_265310 *)((*(Registry_2abd90**)&DAT_00527c58)))->FUN_00265310((hulk_intptr)id)));
                al->v0();
                fr.a = al->FUN_00288e90();
                al->FUN_00288e80(1);
                al->v5(&fr.obj, &fr.hash, r, flag);
                AnimObj *o = fr.obj;
                if (o != 0) {
                    o->v0();
                    if (g->anim != 0)
                        g->anim->v1();
                    g->anim = o;
                    fr.b = fr.obj->count;
                    fr.d = 0;
                    ((owners::Buffer_2ab9a0 *)&(g->array))->FUN_002ab9a0(fr.b, &fr.d);
                    for (int i = 0; i < fr.b; i++) {
                        ::pure3d::ParticlePlaneGenerator::GeneratorBlendState *e = (::pure3d::ParticlePlaneGenerator::GeneratorBlendState *)FUN_0008d690((int)sizeof(::pure3d::ParticlePlaneGenerator::GeneratorBlendState));
                        if (e != 0)
                            e = ((GeneratorBlendState_nv_2abd90*)(((::pure3d::ParticlePlaneGenerator::GeneratorBlendState*)(e))))->FUN_002d2570(((void *)((owners::Target_288a10 *)(fr.obj))->FUN_00288a10(i)));
                        g->array.data[g->used] = e;
                        g->array.data[g->used]->vfunc_0();
                        g->used++;
                    }
                }
                al->FUN_00288e80(fr.a);
                al->v1();
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }
    return g;
}


// 0x002abfb0 FUN_002abfb0 (457 B): equivalent/0x002abfb0.cpp
// sym: ?FUN_002abfb0@fn_f07ae39e@@YGPAVParticleSphereGenerator_2abfb0@1@PAUReader_2abfb0@1@PAX@Z @b6059c8e9a31 @w31d642e99121
// STATUS: equivalent (tools/equiv.py level 3: 15709 inputs, branch coverage 18/18)
// FUN_002abfb0 @ 0x002abfb0
ParticleSphereGenerator_2abfb0* __stdcall FUN_002abfb0(Reader_2abfb0* r, void* arg)
{
    Frame_2abfb0 f;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.old), (hulk_intptr)1, 4, (hulk_intptr)1));
    ParticleSphereGenerator_2abfb0* gen = 0;
    void* mem = FUN_00263ea0(0x48);
    if (mem != 0)
        gen = ((ParticleSphereGenerator_2abfb0*)mem)->FUN_002d3b40();
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.y), (hulk_intptr)1, 4, (hulk_intptr)1));
    gen->dim0 = f.y;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.y), (hulk_intptr)1, 4, (hulk_intptr)1));
    gen->dim1 = f.y;
    while (r->FUN_002669f0() != 0) {
        if (r->FUN_00266a30() == 0x121000) {
            pure3d::AnimationLoader_2abfb0* loader = dynamic_cast<pure3d::AnimationLoader_2abfb0*>(((content :: ObjectLoader_2abfb0 *)((owners::Obj_265310 *)((*(Registry_2abfb0**)&DAT_00527c58)))->FUN_00265310((hulk_intptr)0x121000)));
            loader->AddRef();
            f.old = loader->FUN_00288e90();
            loader->FUN_00288e80(1);
            loader->Load(&f.out0, &f.out1, r, arg);
            if (f.out0 != 0) {
                Source_2abfb0* src = f.out0;
                src->AddRef();
                if (gen->source != 0)
                    gen->source->Release();
                gen->source = src;
                f.y = f.out0->count;
                f.z = 0;
                gen->elements.FUN_002aba00(f.y, (::pure3d::ParticleSphereGenerator::GeneratorBlendState* const*)&f.z);
                for (int i = 0; i < (int)f.y; i++) {
                    ::pure3d::ParticleSphereGenerator::GeneratorBlendState* e = (::pure3d::ParticleSphereGenerator::GeneratorBlendState*)FUN_0008d690((int)sizeof(::pure3d::ParticleSphereGenerator::GeneratorBlendState));
                    f.z = e;
                    if (e != 0)
                        e = ((GeneratorBlendState_nv_2abfb0*)(((::pure3d::ParticleSphereGenerator::GeneratorBlendState*)(e))))->FUN_002d2bd0(((Item_2abfb0 *)((owners::Target_288a10 *)(f.out0))->FUN_00288a10(i)));
                    gen->elements.begin[gen->used] = e;
                    gen->elements.begin[gen->used]->vfunc_0();
                    gen->used++;
                }
            }
            loader->FUN_00288e80(f.old);
            loader->Release();
        }
        r->FUN_00266be0();
    }
    return gen;
}

} // namespace fn_f07ae39e

// 0x002ac180 FUN_002ac180 (787 B): equivalent/0x002ac180.cpp [wrapped: conflict: Reader]
// sym: ?FUN_002ac180@fn_002ac180@@YGPAVGenerator_2ac180@1@PAUReader@1@PAXH@Z @bbb8d6b1e846 @w3dd1cd8b9bd0
namespace fn_002ac180 {
// STATUS: equivalent (tools/equiv.py level 3: 168 inputs, branch coverage 49/52, incomplete)
// FUN_002ac180 @ 0x002ac180

void* FUN_00263ea0(unsigned int size);
extern "C" void* FUN_0008d690(unsigned int size);

struct Stream {
    char pad[0xc];
};

struct Source_2ac180;
struct Reader {
    char pad000[0x284];
    Stream* stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};

struct Item_2ac180 {
};

class Releasable_2ac180 {
public:
    virtual void AddRef();
    virtual void Release();
};

namespace content {
class ObjectLoader_2ac180 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Load(Source_2ac180** out0, unsigned int* out1, Reader* r, void* arg);
};
}

namespace pure3d {
class AnimationLoader_2ac180 : public content::ObjectLoader_2ac180 {
public:
    int FUN_00288e90();
    void FUN_00288e80(int v);
};
}

struct Registry_2ac180 {
};


class Element_2ac180 {
public:
    virtual void AddRef();
    Element_2ac180* FUN_002d2bd0(Item_2ac180* item);
    Element_2ac180* FUN_002d2570(Item_2ac180* item);
    Element_2ac180* FUN_002d2130(Item_2ac180* item);
};

struct Source_2ac180 : public Releasable_2ac180 {
    char pad04[0x24];
    int count;
    Item_2ac180** items;
};

struct ElementList_2ac180 {
    Element_2ac180** begin;
    Element_2ac180** end;
    char FUN_002aba00(unsigned int n, Element_2ac180* const* fill);
    char FUN_002ab9a0(unsigned int n, Element_2ac180* const* fill);
    char FUN_002ab940(unsigned int n, Element_2ac180* const* fill);
};

class Generator_2ac180 {
public:
    virtual void v0();
    char pad04[0x18];
    int used;
    char pad20[8];
    Releasable_2ac180* source;
    ElementList_2ac180 elements;
    char pad34[0x60 - 0x34];
    Generator_2ac180* FUN_002d3b40();
    Generator_2ac180* FUN_002d3930();
    Generator_2ac180* FUN_002d3740();
};

struct Frame_2ac180 {
    Source_2ac180* out0;
    pure3d::AnimationLoader_2ac180* loader;
    void* z;
    unsigned int old;
    unsigned int out1[2];
};

Generator_2ac180* __stdcall FUN_002ac180(Reader* r, void* arg, int kind)
{
    Frame_2ac180 f;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.old), (hulk_intptr)1, 4, (hulk_intptr)1));
    f.loader = dynamic_cast<pure3d::AnimationLoader_2ac180*>(((content :: ObjectLoader_2ac180 *)((owners::Obj_265310 *)((*(Registry_2ac180**)&DAT_00527c58)))->FUN_00265310((hulk_intptr)0x121000)));
    f.loader->AddRef();
    f.old = f.loader->FUN_00288e90();
    f.loader->FUN_00288e80(1);
    Generator_2ac180* gen = 0;
    if (r->FUN_002669f0() != 0) {
        do {
            if (r->FUN_00266a30() == 0x121000) {
                f.out0 = 0;
                f.loader->Load(&f.out0, f.out1, r, arg);
                if (f.out0 != 0) {
                    if (kind == 0x15b02) {
                        void* mem = FUN_00263ea0(0x48);
                        gen = 0;
                        if (mem != 0)
                            gen = ((Generator_2ac180*)mem)->FUN_002d3b40();
                        Source_2ac180* src = f.out0;
                        if (src != 0)
                            src->AddRef();
                        if (gen->source != 0)
                            gen->source->Release();
                        gen->source = src;
                        int n = f.out0->count;
                        f.z = 0;
                        gen->elements.FUN_002aba00(n, (Element_2ac180* const*)&f.z);
                        for (int i = 0; i < n; i++) {
                            Element_2ac180* e = (Element_2ac180*)FUN_0008d690(0x10);
                            f.z = e;
                            if (e != 0)
                                e = e->FUN_002d2bd0(((Item_2ac180 *)((owners::Target_288a10 *)(f.out0))->FUN_00288a10(i)));
                            gen->elements.begin[gen->used] = e;
                            gen->elements.begin[gen->used]->AddRef();
                            gen->used++;
                        }
                    } else if (kind == 0x15b01) {
                        void* mem = FUN_00263ea0(0x60);
                        gen = 0;
                        if (mem != 0)
                            gen = ((Generator_2ac180*)mem)->FUN_002d3930();
                        Source_2ac180* src = f.out0;
                        if (src != 0)
                            src->AddRef();
                        if (gen->source != 0)
                            gen->source->Release();
                        gen->source = src;
                        int n = f.out0->count;
                        f.z = 0;
                        gen->elements.FUN_002ab9a0(n, (Element_2ac180* const*)&f.z);
                        for (int i = 0; i < n; i++) {
                            Element_2ac180* e = (Element_2ac180*)FUN_0008d690(0x1c);
                            f.z = e;
                            if (e != 0)
                                e = e->FUN_002d2570(((Item_2ac180 *)((owners::Target_288a10 *)(f.out0))->FUN_00288a10(i)));
                            gen->elements.begin[gen->used] = e;
                            gen->elements.begin[gen->used]->AddRef();
                            gen->used++;
                        }
                    } else if (kind == 0x15b00) {
                        void* mem = FUN_00263ea0(0x50);
                        gen = 0;
                        if (mem != 0)
                            gen = ((Generator_2ac180*)mem)->FUN_002d3740();
                        Source_2ac180* src = f.out0;
                        if (src != 0)
                            src->AddRef();
                        if (gen->source != 0)
                            gen->source->Release();
                        gen->source = src;
                        int n = f.out0->count;
                        f.z = 0;
                        gen->elements.FUN_002ab940(n, (Element_2ac180* const*)&f.z);
                        for (int i = 0; i < n; i++) {
                            Element_2ac180* e = (Element_2ac180*)FUN_0008d690(0x14);
                            f.z = e;
                            if (e != 0)
                                e = e->FUN_002d2130(((Item_2ac180 *)((owners::Target_288a10 *)(f.out0))->FUN_00288a10(i)));
                            gen->elements.begin[gen->used] = e;
                            gen->elements.begin[gen->used]->AddRef();
                            gen->used++;
                        }
                    }
                }
            }
            r->FUN_00266be0();
            if (gen != 0)
                break;
        } while (r->FUN_002669f0() != 0);
    }
    f.loader->FUN_00288e80(f.old);
    f.loader->Release();
    return gen;
}
} // namespace fn_002ac180


// 0x002ac4a0 FUN_002ac4a0 (149 B): equivalent/0x002ac4a0.cpp [wrapped: conflict: pure3d::ParticleAllocator; pure3d::ParticleAllocatorTemplate]
// sym: ??0?$ParticleAllocatorTemplate@USpriteParticle@pure3d@fn_002ac4a0@@@pure3d@fn_002ac4a0@@QAE@I@Z @ecb11b160541 @w466897c79c15
namespace fn_002ac4a0 {
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 4/4)
// FUN_002ac4a0 @ 0x002ac4a0
// equiv-map: ??0ParticleAllocator@pure3d@@QAE@XZ = 0x002d3d90

namespace pure3d {

struct SpriteParticle {
    char data[0x40];
};

class ParticleAllocator {
public:
    ParticleAllocator();
    virtual void v0();
    char pad04[4];
};

struct IndexVec {
    unsigned int *begin;
    unsigned int *end;
    bool FUN_002ab880(unsigned int n, const unsigned int *def);
};

template <class T>
struct ParticleVec {
    T *begin;
    T *end;
    bool FUN_002aba80(unsigned int n, const T *def);
};

template <class T>
class ParticleAllocatorTemplate : public ParticleAllocator {
public:
    unsigned int count;     // 8
    IndexVec free;          // 0xc
    char pad14[4];
    ParticleVec<T> pool;    // 0x18
    ParticleAllocatorTemplate(unsigned int bytes);
    virtual void v0();
};

template <>
ParticleAllocatorTemplate<SpriteParticle>::ParticleAllocatorTemplate(unsigned int bytes)
{
    free.begin = 0;
    free.end = 0;
    pool.begin = 0;
    pool.end = 0;
    count = bytes >> 6;
    bytes = 0;
    free.FUN_002ab880(count, &bytes);
    char proto[0x4c];   // callee takes a pointer 0xc bytes into this scratch
    pool.FUN_002aba80(count, (const SpriteParticle *)(proto + 0xc));
    for (unsigned int i = 0; i < count; i++)
        free.begin[i] = (hulk_uintptr)(pool.begin + (count - i - 1));
}

}
} // namespace fn_002ac4a0

// 0x002ac540 pure3d::ParticleAllocatorTemplate<pure3d::SpriteParticle>::vfunc_3 (5 B): not yet verified

// 0x002ac550 pure3d::ParticleAllocatorTemplate<pure3d::SpriteParticle>::vfunc_2 (30 B): matches/0x002ac550.cpp
// sym: ??_G?$ParticleAllocatorTemplate@USpriteParticle@pure3d@@@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> pure3d::ParticleAllocatorTemplate<pure3d::SpriteParticle>::~ParticleAllocatorTemplate() {}
#if defined(HULK_PTR64)
template class pure3d::ParticleAllocatorTemplate<pure3d::SpriteParticle>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2ac550)
#endif

namespace fn_f07ae39e {

// 0x002ac570 FUN_002ac570 (49 B): matches/0x002ac570.cpp
// sym: ?FUN_002ac570@ParticleAllocatorTemplate@fn_f07ae39e@@QAEXXZ
void ParticleAllocatorTemplate::FUN_002ac570() {
    *(void**)this = (void*)((hulk_intptr)DAT_0042e0c4);
    _ReadWriteBarrier();
    if (mCallback2)
        thunk_FUN_00267090(mCallback2);
    if (mCallback1)
        thunk_FUN_00267090(mCallback1);
    FUN_002d3d80();
}

} // namespace fn_f07ae39e

// 0x002ac5b0 pure3d::DefaultParticleGeneratorHandler::vfunc_4 (96 B): matches/0x002ac5b0.cpp
// sym: ?vfunc_4@DefaultParticleGeneratorHandler@pure3d@@UAEHHH@Z
int pure3d::DefaultParticleGeneratorHandler::vfunc_4(hulk_intptr __p0, int arg) { Chunk_2ac5b0 * chunk = (Chunk_2ac5b0 *)__p0;

    int result = 0;
    switch (chunk->Type_00266c30()) {
    case 0x15b00:
        result = ((DefaultParticleGeneratorHandler_nv_2ac5b0*)this)->FnA_002abba0(chunk, arg);
        break;
    case 0x15b01:
        result = ((DefaultParticleGeneratorHandler_nv_2ac5b0*)this)->FnB_002abd90(chunk, arg);
        break;
    case 0x15b02:
        result = ((DefaultParticleGeneratorHandler_nv_2ac5b0*)this)->FnC_002abfb0(chunk, arg);
        break;
    }
    return result;
}


// 0x002acc60 FUN_002acc60 (261 B): equivalent/0x002acc60.cpp [wrapped: conflict: memmove; pure3d::DefaultParticleEmitterHandler; pure3d::ParticleSystemLoader]
// sym: ??0ParticleSystemLoader@pure3d@fn_002acc60@@QAE@XZ @9c49b8dc1ca4 @wa5f8aeb68b5b
namespace fn_002acc60 {
// STATUS: equivalent (tools/equiv.py level 3: 126 inputs, branch coverage 16/16)
// FUN_002acc60 @ 0x002acc60

extern "C" void* __cdecl FUN_0008d690(unsigned int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
void* __cdecl memmove(void*, const void*, unsigned int);
#endif


struct Ref_2acc60 { virtual void Add(); virtual void Release(); };
struct ParticleAllocatorTemplate_2acc60 : Ref_2acc60 { ParticleAllocatorTemplate_2acc60* FUN_002ac4a0(int); };
struct ParticleEmitterLoader_2acc60 : Ref_2acc60 { int reserved; int count; Ref_2acc60* items[9]; ParticleEmitterLoader_2acc60* FUN_002ab6a0(); };
struct FUN_002a3e80 : Ref_2acc60 { FUN_002a3e80(); };
namespace pure3d {
struct DefaultParticleEmitterHandler : FUN_002a3e80 { virtual void Add(); virtual void Release(); };
struct ParticleSystemLoader { virtual void V0(); int a,id,b,c,flag; Ref_2acc60* refs[8]; ParticleEmitterLoader_2acc60* list; ParticleSystemLoader(); };
}
pure3d::ParticleSystemLoader::ParticleSystemLoader() : a(0),id(0x1580c),b(0),c(0),flag(1),list(0) {
 for(int i=0;i<8;++i) refs[i]=0;
 ParticleAllocatorTemplate_2acc60* p=(ParticleAllocatorTemplate_2acc60*)FUN_0008d690(0x24);
 if(p) p=p->FUN_002ac4a0(DAT_004cfb20);
 if(p) p->Add();
 if(refs[0]) refs[0]->Release();
 refs[0]=p;
 ParticleEmitterLoader_2acc60* q=(ParticleEmitterLoader_2acc60*)FUN_0008d690(0x30);
 if(q) q=q->FUN_002ab6a0();
 if(q) q->Add();
 if(list) list->Release();
 list=q;
 void* storage=FUN_0008d690(8);
 Ref_2acc60* h= storage ? new(storage) DefaultParticleEmitterHandler : 0;
 ParticleEmitterLoader_2acc60* l=list;
 if(h) { memmove(&l->items[1],&l->items[0],l->count*4); l->items[0]=h; h->Add(); ++l->count; }
}
} // namespace fn_002acc60


// 0x002acd70 FUN_002acd70 (1941 B): equivalent/0x002acd70.cpp [wrapped: conflict: Reader; content::LoadInventory::DynamicCaster; content::ObjectLoader; pure3d::AnimationLoader]
// sym: ?FUN_002acd70@Loader_2acd70@fn_002acd70@@QAEPAVObj_2acd70@2@PAVReader@2@PAVInv_2acd70@2@@Z @e8d760d3c2fd @we17a3bc51d19
namespace fn_002acd70 {
// STATUS: equivalent (tools/equiv.py level 3: 300 inputs, branch coverage 68/86, incomplete)
// FUN_002acd70 @ 0x002acd70
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




class Ref_2acd70 {
public:
    virtual void AddRef();
    virtual void Release();
};

namespace content {
class ObjectLoader : public Ref_2acd70 {
public:
    virtual void o2();
    virtual void o3();
    virtual void o4();
};
namespace LoadInventory {
template<class T> struct DynamicCaster { virtual void cast(); };
}
}

namespace pure3d {
class Shader;
class AnimationLoader : public content::ObjectLoader {
public:
    virtual void *a5(int *out, int *id, void *reader, void *inv);
    int FUN_00288e90();
    void FUN_00288e80(int v);
};
}

void *thunk_FUN_0008d690(unsigned int size);
extern "C" void *__cdecl FUN_0008d690(unsigned int size);
void *__cdecl FUN_0008d6d0(unsigned int size);
void *__cdecl FUN_002aa300(int a, int b, int c, int d, int e);

struct Stream {
    int FUN_002647e0(void *buf, int count, int size, int flag);
};

class Reader {
public:
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

class Inv_2acd70 {
public:
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void *i3(void *caster, unsigned __int64 key);
};

struct NameHolder_2acd70 {
    char pad[8];
    void FUN_0027b040(const char *name);
};

struct Mat_2acd70 {
    float m[16];
    void FUN_0022b980();
};


class Child_2acd70 : public Ref_2acd70 {
public:
    Child_2acd70 *FUN_002d4040(void *r);
};

struct IntVec_2acd70 {
    Child_2acd70 **data;
    void FUN_002ab8e0(unsigned int n, int *fill);
};

class Yobj {
public:
    void *FUN_00288960(int a, int b);
};

class Xobj : public Ref_2acd70 {
public:
    char pad04[0x28 - 4];
    int f28;
    Yobj *FUN_00288a10(int i);
};

class Sink_2acd70 : public Ref_2acd70 {
public:
    char pad04[0x24 - 4];
    int f24;
    int f28;
};

class Wrap_2acd70 : public Ref_2acd70 {
public:
    Wrap_2acd70 *FUN_002d5640(Xobj *z, int a, float b);
};

class Tail_2acd70 : public Ref_2acd70 {
public:
    Tail_2acd70 *FUN_002d6760();
};

class Obj_2acd70 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void *shader);
    char pad04[4];
    NameHolder_2acd70 name;
    char pad10[0x88 - 0x10];
    Ref_2acd70 *f88;
    Ref_2acd70 *f8c;
    Ref_2acd70 *f90;
    int f94;
    char pad98[0xa5 - 0x98];
    char ba5;
    char ba6;
    char pada7[0x130 - 0xa7];
    void *f130;
    void *f134;
    char pad138[4];
    void *f13c;
    Mat_2acd70 *f140;
    int f144;
    int f148;
    char pad14c[0x15c - 0x14c];
    char b15c;
    char pad15d[0x184 - 0x15d];
    int f184;
    float f188;
    char pad18c[0x1bc - 0x18c];
    Sink_2acd70 *f1bc;
    Ref_2acd70 *f1c0;
    Ref_2acd70 *f1c4;
    int *f1c8;
    int *f1cc;
    char pad1d0[4];
    IntVec_2acd70 vec1d4;
    Obj_2acd70 *FUN_002d63a0();
};

class Loader_2acd70 {
public:
    Ref_2acd70 *FUN_002ac180(Reader *r, Inv_2acd70 *i, int tag);
    Obj_2acd70 *FUN_002acd70(Reader *R, Inv_2acd70 *a1);
};

class Node {
public:
    virtual void n0();
};

class Pool_2acd70 {
public:
    Node *FUN_00265310(int v);
};

struct Frame_2acd70 {
    char len;           // 0x00
    char b21;           // 0x01
    char b22;           // 0x02
    char b13;           // 0x03
    int x4;             // 0x04
    Ref_2acd70 *x8;            // 0x08
    void *xc;           // 0x0c
    int x10;            // 0x10
    Ref_2acd70 *x14;           // 0x14
    int x18;            // 0x18
    void *x1c;          // 0x1c
    int x20;            // 0x20
    int x24;            // 0x24
    int x28;            // 0x28
    int x2c;            // 0x2c
    int x30;            // 0x30
    int x34;            // 0x34
    int x38;            // 0x38
    int x3c;            // 0x3c
    pure3d::AnimationLoader *x40;   // 0x40
    int x44;            // 0x44
    int x48;            // 0x48
    int x4c;            // 0x4c
    int x50;            // 0x50
    int x54;            // 0x54
    int x58;            // 0x58
    int id5c[2];        // 0x5c
    int id64[2];        // 0x64
    char name1[0x100];  // 0x6c
    char name2[0x100];  // 0x16c
    char name3[0x100];  // 0x26c
};

Obj_2acd70 *Loader_2acd70::FUN_002acd70(Reader *R, Inv_2acd70 *a1)
{
    Frame_2acd70 f;
    Obj_2acd70 *obj = 0;
    unsigned int n;

    f.x1c = this;
    R->stream->FUN_002647e0(&f.x24, 1, 4, 1);
    R->stream->FUN_002647e0(&f.len, 1, 1, 1);
    n = (unsigned char)f.len;
    R->stream->FUN_002647e0(f.name1, n, 1, 1);
    f.name1[n] = 0;
    R->stream->FUN_002647e0(&f.len, 1, 1, 1);
    n = (unsigned char)f.len;
    R->stream->FUN_002647e0(f.name2, n, 1, 1);
    f.name2[n] = 0;
    R->stream->FUN_002647e0(&f.x28, 1, 4, 1);
    R->stream->FUN_002647e0(&f.x38, 1, 4, 1);
    R->stream->FUN_002647e0(&f.x24, 1, 4, 1);
    R->stream->FUN_002647e0(&f.x3c, 1, 4, 1);
    R->stream->FUN_002647e0(&f.x34, 1, 4, 1);
    if (!R->FUN_002669f0())
        return 0;
    do {
        int k = R->FUN_00266a30();
        if (k == 0x15805) {
            R->stream->FUN_002647e0(&f.x50, 1, 4, 1);
            R->stream->FUN_002647e0(&f.len, 1, 1, 1);
            n = (unsigned char)f.len;
            R->stream->FUN_002647e0(f.name3, n, 1, 1);
            f.name3[n] = 0;
            R->stream->FUN_002647e0(&f.x54, 1, 4, 1);
            R->stream->FUN_002647e0(&f.x2c, 1, 4, 1);
            R->stream->FUN_002647e0(&f.x4c, 1, 4, 1);
            f.b21 = (f.x4c != 0);
            R->stream->FUN_002647e0(&f.x48, 1, 4, 1);
            f.b22 = (f.x48 != 0);
            R->stream->FUN_002647e0(&f.x58, 1, 4, 1);
            R->stream->FUN_002647e0(&f.x20, 1, 4, 1);
            R->stream->FUN_002647e0(&f.x30, 1, 4, 1);
            f.b13 = (f.x30 != 0);
            R->stream->FUN_002647e0(&f.x10, 1, 4, 1);
            R->stream->FUN_002647e0(&f.x18, 1, 4, 1);

            void *mem = thunk_FUN_0008d690(0x1e0);
            if (mem != 0)
                obj = ((Obj_2acd70 *)mem)->FUN_002d63a0();
            else
                obj = 0;
            obj->name.FUN_0027b040(f.name1);
            unsigned __int64 key = FUN_0027b020(f.name2);
            obj->v8(a1->i3(new (&f.xc) content::LoadInventory::DynamicCaster<pure3d::Shader>, key));
            obj->f144 = f.x18;
            obj->f184 = f.x38;
            obj->ba5 = f.b21;
            obj->ba6 = f.b22;
            obj->f148 = f.x10;
            obj->b15c = f.b13;
            if (f.x28 == 0x444e4152)
                obj->f188 = 3.1415927410125732f;
            else
                obj->f188 = 0.0f;
            if (obj->f1c8 == 0) {
                unsigned int cnt = f.x20;
                if (cnt != 0) {
                    int *arr = (int *)FUN_0008d6d0(cnt * 4);
                    obj->f1c8 = arr;
                    if (arr != 0) {
                        obj->f1cc = (int *)((char *)arr + cnt * 4);
                        unsigned int c = f.x20;
                        do {
                            if (arr != 0)
                                *arr = 0;
                            arr++;
                            c--;
                        } while (c != 0);
                    } else {
                        obj->f1c8 = 0;
                        obj->f1cc = 0;
                    }
                } else {
                    obj->f1c8 = 0;
                    obj->f1cc = 0;
                }
            }
            if (*(float *)&f.x18 > 0.0f || *(float *)&f.x10 > 0.0f) {
                Mat_2acd70 *m = (Mat_2acd70 *)FUN_0008d690((int)sizeof(Mat_2acd70));
                obj->f140 = m;
                m->FUN_0022b980();
            }
            pure3d::AnimationLoader *ab = dynamic_cast<pure3d::AnimationLoader *>(
                (content::ObjectLoader *)(*(Pool_2acd70**)&DAT_00527c58)->FUN_00265310(0x121000));
            f.x40 = ab;
            ab->AddRef();
            f.x44 = ab->FUN_00288e90();
            ab->FUN_00288e80(1);
            while (R->FUN_002669f0()) {
                int k2 = R->FUN_00266a30();
                if (k2 == 0x15808) {
                    R->FUN_00266a30();
                    f.x14 = 0;
                    ab->a5((int *)&f.x14, f.id5c, R, a1);
                    if (f.x14 != 0) {
                        Ref_2acd70 *z = f.x14;
                        z->AddRef();
                        if (obj->f1c4 != 0)
                            obj->f1c4->Release();
                        obj->f1c4 = z;
                        void *mem2 = FUN_0008d690(0x30);
                        Wrap_2acd70 *w;
                        if (mem2 != 0) {
                            unsigned int u = f.x34;
                            w = ((Wrap_2acd70 *)mem2)->FUN_002d5640((Xobj *)f.x14, f.x3c, (float)u);
                        } else {
                            w = 0;
                        }
                        if (w != 0)
                            w->AddRef();
                        if (obj->f1bc != 0)
                            obj->f1bc->Release();
                        obj->f1bc = (Sink_2acd70 *)w;
                    }
                    R->FUN_00266be0();
                } else if (k2 == 0x15809) {
                    R->FUN_00266a30();
                    f.x8 = 0;
                    ab->a5((int *)&f.x8, f.id64, R, a1);
                    if (f.x8 != 0) {
                        Xobj *X = (Xobj *)f.x8;
                        X->AddRef();
                        if (obj->f1c0 != 0)
                            obj->f1c0->Release();
                        obj->f1c0 = X;
                        f.xc = (void *)((Xobj *)f.x8)->f28;
                        f.x4 = 0;
                        obj->vec1d4.FUN_002ab8e0((hulk_uintptr)f.xc, &f.x4);
                        int i;
                        for (i = 0; i < (hulk_intptr)f.xc; i++) {
                            void *mem3 = FUN_0008d690(0x4c);
                            f.x4 = (hulk_intptr)mem3;
                            Child_2acd70 *ch;
                            if (mem3 != 0)
                                ch = ((Child_2acd70 *)f.x4)->FUN_002d4040(((Xobj *)f.x8)->FUN_00288a10(i));
                            else
                                ch = 0;
                            obj->vec1d4.data[obj->f94] = ch;
                            obj->vec1d4.data[obj->f94]->AddRef();
                            obj->f94 = obj->f94 + 1;
                        }
                        Yobj *Y = ((Xobj *)f.x8)->FUN_00288a10(0);
                        obj->f130 = Y->FUN_00288960(0x415254, 0x54434556);
                        obj->f134 = Y->FUN_00288960(0x544f52, 0x544f52);
                        obj->f13c = Y->FUN_00288960(0x534956, 0x4c4f4f42);
                        ab = f.x40;
                    }
                    R->FUN_00266be0();
                } else if (k2 == 0x1580a) {
                    int tag;
                    if (f.x2c == 0x4e4c50)
                        tag = 0x15b01;
                    else if (f.x2c == 0x544e50)
                        tag = 0x15b00;
                    else if (f.x2c == 0x52485053)
                        tag = 0x15b02;
                    else
                        tag = 0;
                    if (tag != 0) {
                        obj->f88 = ((Loader_2acd70 *)f.x1c)->FUN_002ac180(R, a1, tag);
                        obj->f88->AddRef();
                    }
                }
                R->FUN_00266be0();
            }
            ab = f.x40;
            ab->FUN_00288e80(f.x44);
            ab->Release();
            void *mem4 = FUN_0008d690(8);
            Tail_2acd70 *tl;
            if (mem4 != 0)
                tl = ((Tail_2acd70 *)mem4)->FUN_002d6760();
            else
                tl = 0;
            obj->f90 = tl;
            tl->AddRef();
            unsigned int tag = 0x454e4f4e;
            Sink_2acd70 *sk = obj->f1bc;
            if (sk != 0) {
                if (sk->f24 != 0) {
                    if (sk->f28 != 0)
                        tag = 0x41424752;
                    else
                        tag = 0x424752;
                } else if (sk->f28 != 0) {
                    tag = 0x41;
                }
            }
            Ref_2acd70 *r = (Ref_2acd70 *)FUN_002aa300(f.x28, f.x24, tag, f.x18, f.x10);
            if (r != 0)
                r->AddRef();
            if (obj->f8c != 0)
                obj->f8c->Release();
            obj->f8c = r;
        }
        R->FUN_00266be0();
        if (obj != 0)
            break;
    } while (R->FUN_002669f0());
    return obj;
}
} // namespace fn_002acd70
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002ad510 pure3d::DefaultParticleEmitterHandler::vfunc_4 (50 B): matches/0x002ad510.cpp
// sym: ?vfunc_4@DefaultParticleEmitterHandler@pure3d@@UAEXHHHH@Z
void pure3d::DefaultParticleEmitterHandler::vfunc_4(int __p0, int __p1, int __p2, int __p3) { u32_2ad510 first = (u32_2ad510)__p0; hulk_uintptr obj = (u32_2ad510)__p1; u32_2ad510 third = (u32_2ad510)__p2; u32_2ad510 fourth = (u32_2ad510)__p3;

    if ((hulk_uintptr)((Query_2ad510*)obj)->GetType_00266c30() == 0x15900)
        ((DefaultParticleEmitterHandler_nv_2ad510*)this)->Dispatch_002ac610(first, obj, third, fourth);
}


// 0x002ad550 pure3d::OldParticleSystemLoader::vfunc_5 (563 B): equivalent/0x002ad550.cpp [wrapped: conflict: Stream; content::ObjectLoader; pure3d::OldParticleSystemLoader]
// sym: ?vfunc_5@OldParticleSystemLoader@pure3d@fn_002ad550@@UAE_KPAPAUParticleSystem_2ad550@3@PA_KPAUReader@3@H@Z @4a341cfe9008 @wcac4b3021971
namespace fn_002ad550 {
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 16/18, incomplete)
// pure3d::OldParticleSystemLoader::vfunc_5 @ 0x002ad550
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char *strstr(const char *, const char *);
#endif


struct StrField_2ad550 {
    int a, b;
    void FUN_0027b040(const char *s);
};

class Item_2ad550 {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(int arg);
};

struct Slot;

struct Host_2ad550 {
    void FUN_002a46d0(void *slot, Item_2ad550 *item);
};

struct Wrapper;

struct Extra_2ad550 {
    char pad0[8];
    StrField_2ad550 name;
    char pad1[0x60 - 0x10];
    Extra_2ad550 *FUN_002a73d0();
};

struct Particle;

struct Table_2ad550 {
    char pad0[8];
    StrField_2ad550 name2;
    void FUN_0027af70(StrField_2ad550 *name);
};

struct ParticleSystem_2ad550 {
    char pad0[8];
    StrField_2ad550 name;
    char pad1[0x48 - 0x10];
    char *slots;
    char pad2[0x58 - 0x4c];
    unsigned char flag;
    char pad3[3];
    float count;
    int value;
    char pad4[0xa4 - 0x64];
    void *extra;
    ParticleSystem_2ad550 *FUN_002a3660(int arg);
    void FUN_002a3c80(void *extra);
};

struct ParticleController_2ad550 {
    char pad0[8];
    Table_2ad550 table;
    char pad1[0x60 - 0x8 - sizeof(Table_2ad550)];
    ParticleController_2ad550 *FUN_002a73d0();
};

struct Stream {
    bool FUN_002647e0(void *dst, int a, int b, int c);
};

namespace content {
class ObjectLoader {
public:
    virtual void v0();
};
}

struct Reader {
    char pad0[0x284];
    Stream *stream;
    bool FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};

void *FUN_00263ea0(unsigned int size);

namespace pure3d {
class OldParticleSystemLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual unsigned __int64 vfunc_5(ParticleSystem_2ad550 **out, unsigned __int64 *outHash, Reader *r, int flag);
    char pad04[0x14 - 4];
    int f14;
    Host_2ad550 *f18;
    Item_2ad550 *FUN_002acd70(Reader *r, int flag);
};
}

unsigned __int64 pure3d::OldParticleSystemLoader::vfunc_5(ParticleSystem_2ad550 **out, unsigned __int64 *outHash, Reader *r, int flag)
{
    struct Frame {
        union {
            unsigned char len;
            unsigned short s;
            unsigned char flag;
        } u;
        char pad[2];
        int slot14;
        int slot18;
        int slot1c;
        char buf[0x100];
    } fr;

    Stream *st = r->stream;
    st->FUN_002647e0(&fr.slot18, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.u.len, 1, 1, 1);
    unsigned int n = fr.u.len;
    r->stream->FUN_002647e0(fr.buf, n, 1, 1);
    fr.buf[n] = 0;
    r->stream->FUN_002647e0(&fr.slot1c, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.slot18, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.slot14, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.u.s, 1, 2, 1);
    fr.u.flag = (fr.u.s != 0);
    r->stream->FUN_002647e0(&fr.slot14, 1, 2, 1);
    r->stream->FUN_002647e0(&fr.slot14, 1, 4, 1);

    char *sep = strstr(fr.buf, "_factory");
    if (sep)
        *sep = 0;

    void *mem = FUN_00263ea0(0xb0);
    ParticleSystem_2ad550 *b = 0;
    if (mem)
        b = ((ParticleSystem_2ad550 *)mem)->FUN_002a3660(fr.slot14);
    b->name.FUN_0027b040(fr.buf);
    b->value = fr.slot1c;
    b->count = (float)(unsigned int)fr.slot18;
    b->flag = fr.u.flag;

    if (r->FUN_002669f0()) {
        int off = 0;
        do {
            if (r->FUN_00266a30() == 0x15806) {
                Item_2ad550 *item = FUN_002acd70(r, flag);
                item->v25(f14);
                f18->FUN_002a46d0(b->slots + off, item);
                off += 0x10;
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }

    if (b->extra == 0) {
        void *m2 = FUN_00263ea0(0x60);
        ParticleController_2ad550 *e = 0;
        if (m2)
            e = ((ParticleController_2ad550 *)m2)->FUN_002a73d0();
        e->table.FUN_0027af70(&b->name);
        b->FUN_002a3c80(e);
    }

    *out = b;
    unsigned __int64 h = FUN_002672f0(fr.buf, 0, 0);
    *outHash = h;
    return h;
}
} // namespace fn_002ad550
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

