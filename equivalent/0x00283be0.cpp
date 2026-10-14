// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00283be0 @ 0x00283be0
namespace pure3d { class DrawableHierarchy; }
namespace content { namespace LoadInventory {
template<class T> struct DynamicCaster { virtual void Cast(); };
} }
struct Pair { unsigned first, second; };
struct Item {
 virtual void AddRef();
 virtual void Release();
 virtual void slot2();
 virtual void slot3();
 virtual Item* GetItem();
};
struct Source {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual Item* Find(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*,unsigned,unsigned);
};
struct Stats {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
 virtual void Query(unsigned*,unsigned,unsigned,unsigned);
};
extern Stats* __cdecl FUN_00266f40(unsigned);
extern unsigned __cdecl FUN_00266da0(unsigned);
struct Manager { unsigned FUN_00280460(Item*,unsigned,unsigned); };
struct Target {
 Source* source; unsigned id; unsigned pad; Manager* manager;
 void FUN_0027fff0(Item*,unsigned);
 unsigned FUN_00283be0(Pair*,unsigned,unsigned,unsigned);
};
unsigned Target::FUN_00283be0(Pair* pair,unsigned a,unsigned b,unsigned c) {
 if (!source) return 0;
 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
 Item* item=source->Find(&caster,pair->first,pair->second);
 if (!item) return 0;
 unsigned size;
 Stats* stats=FUN_00266f40(id);
 stats->Query(&size,0,0,0);
 if(size<0xc800u) return 0;
 unsigned handle=FUN_00266da0(id);
 item=item->GetItem();
 FUN_00266da0(handle);
 item->AddRef();
 FUN_0027fff0(item,c);
 unsigned result=manager->FUN_00280460(item,a,b);
 item->Release();
 return result;
}
