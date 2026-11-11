// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ac2c0..0x000ac610 (kind game, layer game, confidence high), dominant class CNISCamera
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#define TREE_TU_BEGIN namespace fn_fe577214 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe577214 {} using namespace fn_fe577214;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe577214 {
struct Ref_ac2c0 { virtual void retain(); virtual void release(); };
struct Filter_ac2c0 : Ref_ac2c0 { Filter_ac2c0* FUN_00292eb0(); void FUN_00293100(Ref_ac2c0*); };
struct Other_ac2c0 : Ref_ac2c0 { Other_ac2c0* FUN_002939a0(); };
struct Property_ac2c0 { void FUN_0027b040(unsigned); };
struct Inventory_ac2c0;
struct Access_ac2c0 { Inventory_ac2c0* FUN_00203d70(); };
} // namespace fn_fe577214
struct Singleton_4dd6ec { Access_ac2c0* FUN_000862a0(); };
namespace fn_fe577214 {
extern void* __cdecl FUN_00263ea0(unsigned);
namespace pure3d {
struct DrawableHierarchy;
}
namespace content {
struct LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; };
}
struct Inventory_ac2c0 { virtual void a(); virtual void b(); virtual void c(); virtual Ref_ac2c0* find(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*,unsigned __int64); };
struct FUN_000a9400 { FUN_000a9400(); virtual void dummy(); char pad4[4]; Property_ac2c0 property; char pad9[0xd0-9]; unsigned mode; char padD4[0x424-0xd4]; Filter_ac2c0* filter; Other_ac2c0* other; char pad42c[0x478-0x42c]; Ref_ac2c0* resource; };
struct CHypnoticCamera : FUN_000a9400 { CHypnoticCamera(); virtual void dummy(); };
extern "C" char DAT_00405b2c[];
typedef unsigned int u32_ac3c0;
class CNISCamera_ac3c0 {
  public:
    void BaseInit();
};
class Sub_ac3c0 {
  public:
    void Init(void* p);
};
extern void* g_vftable_ac4c0[];
class Ref_ac4c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CGameCamera_ac4c0 {
  public:
    void* vptr;
    void Fin();
};
class CNISCamera_ac4c0 : public CGameCamera_ac4c0 {
  public:
    char pad[0x170 - 4];
    Ref_ac4c0* m170;
    ~CNISCamera_ac4c0();
};
struct Vec3_ac4f0 { float x, y, z; };
struct CameraPose {
    char pad00[0x20];
    Vec3_ac4f0 a;
    float pad2c;
    Vec3_ac4f0 b;
};
struct Ref { virtual void FUN_00000000(); virtual void FUN_00000004(); };
struct Owner { char pad[0x170]; Ref* ref; void FUN_000ac560(Ref* value); };
extern int vtable_ac5a0;
class Ref_ac5a0 {
  public:
    virtual void f0();
    virtual void f1();
};
class CNISCamera {
  public:
    virtual void _m_vf0();
    virtual void f1();
    virtual CNISCamera* vfunc_2(unsigned char flag);
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual CameraPose* GetPose();
    char _m_pad_4[0x16c];
    Ref_ac5a0* mRef;
    Vec3_ac4f0* FUN_000ac4f0(Vec3_ac4f0* out);
};
extern "C" void __fastcall FUN_000a9620(CNISCamera*);
void __cdecl thunk(CNISCamera*);


// 0x000ac2c0 FUN_000ac2c0 (248 B): equivalent/0x000ac2c0.cpp
// sym: ??0CHypnoticCamera@fn_fe577214@@QAE@XZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000ac2c0 @ 0x000ac2c0
CHypnoticCamera::CHypnoticCamera() {
 resource=0; mode=2; property.FUN_0027b040((*(hulk_uintptr*)&DAT_0049ed9c));
 void* p=FUN_00263ea0(0x118); filter=p?((Filter_ac2c0*)p)->FUN_00292eb0():0; filter->retain();
 p=FUN_00263ea0(0xf8); other=p?((Other_ac2c0*)p)->FUN_002939a0():0; other->retain();
 filter->FUN_00293100(other);
 Inventory_ac2c0* inv=DAT_004dd6ec->FUN_000862a0()->FUN_00203d70();
 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
 Ref_ac2c0* result=inv->find(&caster,FUN_002672f0("hypnoticCamFilter",0,0));
 if(result) result->retain();
 if(resource) resource->release();
 resource=result;
}


// 0x000ac3c0 FUN_000ac3c0 (52 B): matches/0x000ac3c0.cpp
// sym: ?target@fn_fe577214@@YIPAVCNISCamera@1@PAV21@@Z
CNISCamera* __fastcall target(CNISCamera* self) {
    ((CNISCamera_ac3c0*)self)->BaseInit();
    void* p = (*(void**)&DAT_0049edd0);
    *(hulk_uintptr*)self = ((hulk_intptr)DAT_00405b2c);
    *(u32_ac3c0*)((char*)self + 0xd0) = 3;
    ((Sub_ac3c0*)((char*)self + 8))->Init(p);
    *(u32_ac3c0*)((char*)self + 0x170) = 0;
    return self;
}


// 0x000ac400 CNISCamera::vfunc_28 (1 B): matches/0x000ac400.cpp
// sym: ?FUN_000ac400@fn_fe577214@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000ac400() {}


// 0x000ac410 CNISCamera::vfunc_29 (1 B): matches/0x000ac410.cpp
// sym: ?FUN_000ac410@fn_fe577214@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000ac410() {}


// 0x000ac4c0 FUN_000ac4c0 (42 B): matches/0x000ac4c0.cpp
// sym: ??1CNISCamera_ac4c0@fn_fe577214@@QAE@XZ
CNISCamera_ac4c0::~CNISCamera_ac4c0() {
    vptr = g_vftable_ac4c0;
    _ReadWriteBarrier();
    if (m170) {
        m170->Release();
        m170 = 0;
    }
    Fin();
}


// 0x000ac4f0 CNISCamera::vfunc_27 (101 B): equivalent/0x000ac4f0.cpp
// sym: ?FUN_000ac4f0@CNISCamera@fn_fe577214@@QAEPAUVec3_ac4f0@2@PAU32@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// CNISCamera::vfunc_27 @ 0x000ac4f0
Vec3_ac4f0* CNISCamera::FUN_000ac4f0(Vec3_ac4f0* out) {
    CameraPose* p = GetPose();
    float x = p->a.x * 10.0f;
    float y = p->a.y * 10.0f;
    float z = p->a.z * 10.0f;
    CameraPose* q = GetPose();
    out->x = x + q->b.x;
    out->y = y + q->b.y;
    out->z = z + q->b.z;
    return out;
}


// 0x000ac560 FUN_000ac560 (56 B): equivalent/0x000ac560.cpp
// sym: ?FUN_000ac560@Owner@fn_fe577214@@QAEXPAURef@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 5/6, incomplete)
// FUN_000ac560 @ 0x000ac560
void Owner::FUN_000ac560(Ref* value) { if (ref) { ref->FUN_00000004(); ref = 0; } ref = value; if (value) value->FUN_00000000(); }


// 0x000ac5a0 CNISCamera::vfunc_2 (63 B): matches/0x000ac5a0.cpp
// sym: ?vfunc_2@CNISCamera@fn_fe577214@@UAEPAV12@E@Z
CNISCamera* CNISCamera::vfunc_2(unsigned char flag) {
    *(volatile hulk_intptr*)this = (hulk_intptr)&vtable_ac5a0;
    Ref_ac5a0* r = *(Ref_ac5a0* volatile*)&mRef;
    if (r) {
        r->f1();
        mRef = 0;
    }
    FUN_000a9620(this);
    if (flag & 1)
        thunk(this);
    return this;
}

} // namespace fn_fe577214
