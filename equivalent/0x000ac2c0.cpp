// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000ac2c0 @ 0x000ac2c0
#include "decls/address.h"
struct Ref_ac2c0 { virtual void retain(); virtual void release(); };
struct Filter_ac2c0 : Ref_ac2c0 { Filter_ac2c0* FUN_00292eb0(); void FUN_00293100(Ref_ac2c0*); };
struct Other_ac2c0 : Ref_ac2c0 { Other_ac2c0* FUN_002939a0(); };
struct Property_ac2c0 { void FUN_0027b040(unsigned); };
struct Inventory_ac2c0;
struct Access_ac2c0 { Inventory_ac2c0* FUN_00203d70(); };
struct Singleton_4dd6ec { Access_ac2c0* FUN_000862a0(); };
extern unsigned DAT_0049ed9c;
extern void* __cdecl FUN_00263ea0(unsigned);
namespace pure3d { struct DrawableHierarchy; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; }; }
struct Inventory_ac2c0 { virtual void a(); virtual void b(); virtual void c(); virtual Ref_ac2c0* find(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*,unsigned __int64); };
struct FUN_000a9400 { FUN_000a9400(); virtual void dummy(); char pad4[4]; Property_ac2c0 property; char pad9[0xd0-9]; unsigned mode; char padD4[0x424-0xd4]; Filter_ac2c0* filter; Other_ac2c0* other; char pad42c[0x478-0x42c]; Ref_ac2c0* resource; };
struct CHypnoticCamera : FUN_000a9400 { CHypnoticCamera(); virtual void dummy(); };
CHypnoticCamera::CHypnoticCamera() {
 resource=0; mode=2; property.FUN_0027b040(DAT_0049ed9c);
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
