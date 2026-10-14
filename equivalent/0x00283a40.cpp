// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00283a40 @ 0x00283a40
namespace pure3d { class DrawableHierarchy; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
struct Key { unsigned a,b; };
struct Hierarchy { virtual void acquire(); virtual void release(); };
struct Item { virtual void v0(); virtual void v1(); virtual void v2(); virtual Item* lookup(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*,unsigned,unsigned); virtual Hierarchy* hierarchy(); };
struct Inventory { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void size(unsigned*,unsigned,unsigned,unsigned); };
Inventory* __cdecl FUN_00266f40(unsigned);
unsigned __cdecl FUN_00266da0(unsigned);
struct Context { unsigned FUN_00280380(Hierarchy*,unsigned,unsigned,unsigned,unsigned); };
struct Target { Item* source; unsigned id; unsigned pad; Context* context; void FUN_0027fff0(Hierarchy*,unsigned); unsigned FUN_00283a40(Key*,unsigned,unsigned,unsigned); };
unsigned Target::FUN_00283a40(Key* key,unsigned a,unsigned b,unsigned c) {
 if (!source) return 0;
 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
 Item* item=source->lookup(&caster,key->a,key->b);
 if (!item) return 0;
 unsigned size;
 FUN_00266f40(id)->size(&size,0,0,0);
 if(size<0xc800) return 0;
 unsigned saved=FUN_00266da0(id);
 Hierarchy* h=item->hierarchy();
 FUN_00266da0(saved);
 h->acquire();
 FUN_0027fff0(h,c);
 unsigned result=context->FUN_00280380(h,0,0,a,b);
 h->release();
 return result;
}