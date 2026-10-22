// STATUS: equivalent (tools/equiv.py level 3: 2230 inputs, branch coverage 20/20)
// FUN_001e30f0 @ 0x001e30f0
class CSPHulkProp;
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
struct Object;
struct Entry_1e30f0 { unsigned low, high; int unused; int index; };
struct Table_1e30f0 { char pad[0x24]; int count; Entry_1e30f0* entries; };
struct Info_1e30f0 { char pad[0x1c]; Table_1e30f0** tables; };
struct Object { Info_1e30f0* FUN_001d4fc0(); void FUN_0027e760(unsigned); };
struct Inventory_1e30f0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual Object* find(content::LoadInventory::DynamicCaster<CSPHulkProp>*, unsigned, unsigned); };
struct Provider_1e30f0 { Inventory_1e30f0* FUN_00203d70(); };
struct Context { Provider_1e30f0* FUN_000862a0(); };
struct Owner_1e30f0 { char pad[0x54]; Context* context; };
unsigned __int64 __cdecl FUN_0027b020(unsigned);
struct Record_1e30f0 { char pad[8]; unsigned key1,key2; char pad2[8]; Object* object; char pad3[4]; short state; short type; char pad4[2]; signed char table; char pad5; };
struct Flag_1e30f0 { unsigned flags; char pad[16]; };
struct CSPManager_1e30f0 { char pad[0x608]; Record_1e30f0 records[1923]; char rest[0x14618-0x608-1923*40]; Flag_1e30f0 flags[2073]; char tail[0x1e830-0x14618-2073*20]; Owner_1e30f0* owner; int FUN_001dbfe0(unsigned); void target(unsigned id,unsigned value); };
void CSPManager_1e30f0::target(unsigned id,unsigned value) {
 int n=FUN_001dbfe0(id); if(n<0) return;
 Record_1e30f0* r=&records[n];
 if((flags[r->type].flags&1) && r->object) { r->object->FUN_0027e760(value); return; }
 unsigned k1=r->key1,k2=r->key2;
 Provider_1e30f0* p=owner->context->FUN_000862a0();
 Inventory_1e30f0* inv=p->FUN_00203d70();
 content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
 Object* obj=inv->find(&caster,k1,k2);
 if(!obj) return;
 unsigned __int64 key=FUN_0027b020(value);
 Info_1e30f0* info=obj->FUN_001d4fc0();
 int ti=r->table; if(ti<0) return;
 Table_1e30f0* t=info->tables[ti];
 for(int i=0;i<t->count;++i) { Entry_1e30f0& e=t->entries[i]; if(e.low==(unsigned)key && e.high==(unsigned)(key>>32)) { if(e.index!=-1) { r->table=(signed char)e.index; r->state=0; } return; } }
}
