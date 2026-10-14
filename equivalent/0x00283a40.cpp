// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00283a40 @ 0x00283a40
namespace pure3d { class DrawableHierarchy; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
struct Key_283a40 { unsigned a,b; };
struct Hierarchy_283a40 { virtual void acquire(); virtual void release(); };
struct Item_283a40 { virtual void v0(); virtual void v1(); virtual void v2(); virtual Item_283a40* lookup(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*,unsigned,unsigned); virtual Hierarchy_283a40* hierarchy(); };
struct Inventory_283a40 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void size(unsigned*,unsigned,unsigned,unsigned); };
Inventory_283a40* __cdecl FUN_00266f40(unsigned);
unsigned __cdecl FUN_00266da0(unsigned);
struct Context { unsigned FUN_00280380(Hierarchy_283a40*,unsigned,unsigned,unsigned,unsigned); };
struct Target_283a40 { Item_283a40* source; unsigned id; unsigned pad; Context* context; void FUN_0027fff0(Hierarchy_283a40*,unsigned); unsigned FUN_00283a40(Key_283a40*,unsigned,unsigned,unsigned); };
unsigned Target_283a40::FUN_00283a40(Key_283a40* key,unsigned a,unsigned b,unsigned c) {
 if (!source) return 0;
 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
 Item_283a40* item=source->lookup(&caster,key->a,key->b);
 if (!item) return 0;
 unsigned size;
 FUN_00266f40(id)->size(&size,0,0,0);
 if(size<0xc800) return 0;
 unsigned saved=FUN_00266da0(id);
 Hierarchy_283a40* h=item->hierarchy();
 FUN_00266da0(saved);
 h->acquire();
 FUN_0027fff0(h,c);
 unsigned result=context->FUN_00280380(h,0,0,a,b);
 h->release();
 return result;
}