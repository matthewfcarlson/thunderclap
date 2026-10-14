// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000ac2c0 @ 0x000ac2c0
struct Ref { virtual void retain(); virtual void release(); };
struct Filter : Ref { Filter* FUN_00292eb0(); void FUN_00293100(Ref*); };
struct Other : Ref { Other* FUN_002939a0(); };
struct Property { void FUN_0027b040(unsigned); };
struct Inventory;
struct Access { Inventory* FUN_00203d70(); };
struct Manager { Access* FUN_000862a0(); };
extern Manager* DAT_004dd6ec;
extern unsigned DAT_0049ed9c;
extern void* __cdecl FUN_00263ea0(unsigned);
extern unsigned __int64 __cdecl FUN_002672f0(const char*,int,int);
namespace pure3d { struct DrawableHierarchy; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; }; }
struct Inventory { virtual void a(); virtual void b(); virtual void c(); virtual Ref* find(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*,unsigned __int64); };
struct FUN_000a9400 { FUN_000a9400(); virtual void dummy(); char pad4[4]; Property property; char pad9[0xd0-9]; unsigned mode; char padD4[0x424-0xd4]; Filter* filter; Other* other; char pad42c[0x478-0x42c]; Ref* resource; };
struct CHypnoticCamera : FUN_000a9400 { CHypnoticCamera(); virtual void dummy(); };
CHypnoticCamera::CHypnoticCamera() {
 resource=0; mode=2; property.FUN_0027b040(DAT_0049ed9c);
 void* p=FUN_00263ea0(0x118); filter=p?((Filter*)p)->FUN_00292eb0():0; filter->retain();
 p=FUN_00263ea0(0xf8); other=p?((Other*)p)->FUN_002939a0():0; other->retain();
 filter->FUN_00293100(other);
 Inventory* inv=DAT_004dd6ec->FUN_000862a0()->FUN_00203d70();
 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
 Ref* result=inv->find(&caster,FUN_002672f0("hypnoticCamFilter",0,0));
 if(result) result->retain();
 if(resource) resource->release();
 resource=result;
}
