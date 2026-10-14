// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00283b10 @ 0x00283b10
namespace pure3d { struct DrawableHierarchy { virtual void retain(); virtual void release(); }; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
struct Key_283b10 { unsigned first, second; };
struct Item_283b10 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual pure3d::DrawableHierarchy* get(); };
struct Inventory_283b10 { virtual void f0(); virtual void f1(); virtual void f2(); virtual Item_283b10* find(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*, unsigned, unsigned); };
struct Status_283b10 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void query(unsigned*, unsigned, unsigned, unsigned); };
extern Status_283b10* __cdecl FUN_00266f40(unsigned);
extern unsigned __cdecl FUN_00266da0(unsigned);
struct Builder { unsigned FUN_00280380(pure3d::DrawableHierarchy*, unsigned, unsigned, unsigned, unsigned); };
struct Target_283b10 { Inventory_283b10* inventory; unsigned context; unsigned unused; Builder* builder; void FUN_0027fff0(pure3d::DrawableHierarchy*, unsigned); unsigned run(Key_283b10*,unsigned,unsigned,unsigned,unsigned,unsigned); };
unsigned Target_283b10::run(Key_283b10* key,unsigned a,unsigned b,unsigned c,unsigned d,unsigned e) {
 if (!inventory) return 0;
 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
 Item_283b10* item=inventory->find(&caster,key->first,key->second);
 if (!item) return 0;
 unsigned amount;
 FUN_00266f40(context)->query(&amount,0,0,0);
 if(amount<0xc800) return 0;
 unsigned saved=FUN_00266da0(context);
 pure3d::DrawableHierarchy* drawable=item->get();
 FUN_00266da0(saved);
 drawable->retain();
 FUN_0027fff0(drawable,e);
 unsigned result=builder->FUN_00280380(drawable,a,b,c,d);
 drawable->release();
 return result;
}