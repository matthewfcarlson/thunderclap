// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00283ca0 @ 0x00283ca0
namespace pure3d { struct DrawableHierarchy { virtual void AddRef(); virtual void Release(); }; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual T* Cast(void*); }; }; }
struct Key { unsigned a,b; };
struct Entry { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual pure3d::DrawableHierarchy* m4(); };
struct Inventory { virtual void m0(); virtual void m1(); virtual void m2(); virtual Entry* Find(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*,unsigned,unsigned); };
struct Stats { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void Query(unsigned*,unsigned,unsigned,unsigned); };
extern Stats* __cdecl FUN_00266f40(unsigned);
extern unsigned __cdecl FUN_00266da0(unsigned);
struct Destination { int FUN_00283510(pure3d::DrawableHierarchy*,unsigned,unsigned,unsigned); };
struct Target { Inventory* inventory; unsigned id; unsigned pad; Destination* dest; int FUN_00283ca0(Key*,unsigned,unsigned,unsigned); };
int Target::FUN_00283ca0(Key* key,unsigned a,unsigned b,unsigned c) {
 if (!inventory) return 0;
 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
 Entry* entry=inventory->Find(&caster,key->a,key->b);
 if (!entry) return 0;
 unsigned count;
 FUN_00266f40(id)->Query(&count,0,0,0);
 if(count<0xc800) return 0;
 unsigned handle=FUN_00266da0(id);
 pure3d::DrawableHierarchy* drawable=entry->m4();
 FUN_00266da0(handle);
 drawable->AddRef();
 int result=dest->FUN_00283510(drawable,a,b,c);
 drawable->Release();
 return result;
}