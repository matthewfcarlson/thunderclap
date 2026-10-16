// STATUS: equivalent (tools/equiv.py level 3: 631 inputs, branch coverage 12/12)
// VScroll::vfunc_0 @ 0x000f2980
#include "decls/address.h"
namespace pure3d { struct DrawableHierarchy; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual void vfunc_0(); }; }; }
struct Item_f2980 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual float vfunc_8(); virtual float vfunc_9();
};
struct Entry_f2980 { Item_f2980* item; int unused; float height; int unused2; };
struct Inventory_f2980 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual pure3d::DrawableHierarchy* vfunc_3(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*, unsigned int, unsigned int); };
extern Inventory_f2980* DAT_004dd9cc;
struct Dimensions { float x,y,z; };
extern void __cdecl FUN_000f69e0(pure3d::DrawableHierarchy*, Dimensions*);
struct FELayout {
 virtual void vfunc_0();
 char pad04[0x2c]; float height; char pad34[0xc];
 Entry_f2980 entries[32]; int count; char pad244[0x10]; float maximum; pure3d::DrawableHierarchy* backdrop; float scaleX,scaleY,scale;
 void FUN_000e23f0();
};
struct VScroll: FELayout { virtual void vfunc_0(); };
void VScroll::vfunc_0() {
 for(int i=0;i<count;++i) { entries[i].item->vfunc_3(); entries[i].height=entries[i].item->vfunc_8(); }
 for(int i=0;i<count;++i) { float w=entries[i].item->vfunc_9(); if(w>maximum) maximum=w; }
 FUN_000e23f0();
 Inventory_f2980* inventory=DAT_004dd9cc;
 unsigned __int64 hash=FUN_0027b020("S_backDropShape");
 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
 backdrop=inventory->vfunc_3(&caster,(unsigned int)hash,(unsigned int)(hash>>32));
 if(backdrop) { Dimensions d; FUN_000f69e0(backdrop,&d); scale=1.0f; scaleX=(maximum/d.x)*1.1f; scaleY=(height/d.z)*1.1f; }
}