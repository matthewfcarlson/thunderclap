// STATUS: equivalent (tools/equiv.py level 3: 2230 inputs, branch coverage 20/20)
// FUN_001e30f0 @ 0x001e30f0
class CSPHulkProp;
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
struct Object;
struct Entry { unsigned low, high; int unused; int index; };
struct Table { char pad[0x24]; int count; Entry* entries; };
struct Info { char pad[0x1c]; Table** tables; };
struct Object { Info* FUN_001d4fc0(); void FUN_0027e760(unsigned); };
struct Inventory { virtual void v0(); virtual void v1(); virtual void v2(); virtual Object* find(content::LoadInventory::DynamicCaster<CSPHulkProp>*, unsigned, unsigned); };
struct Provider { Inventory* FUN_00203d70(); };
struct Context { Provider* FUN_000862a0(); };
struct Owner { char pad[0x54]; Context* context; };
unsigned __int64 __cdecl FUN_0027b020(unsigned);
struct Record { char pad[8]; unsigned key1,key2; char pad2[8]; Object* object; char pad3[4]; short state; short type; char pad4[2]; signed char table; char pad5; };
struct Flag { unsigned flags; char pad[16]; };
struct Game { char pad[0x608]; Record records[1923]; char rest[0x14618-0x608-1923*40]; Flag flags[2073]; char tail[0x1e830-0x14618-2073*20]; Owner* owner; int FUN_001dbfe0(unsigned); void target(unsigned id,unsigned value); };
void Game::target(unsigned id,unsigned value) {
 int n=FUN_001dbfe0(id); if(n<0) return;
 Record* r=&records[n];
 if((flags[r->type].flags&1) && r->object) { r->object->FUN_0027e760(value); return; }
 unsigned k1=r->key1,k2=r->key2;
 Provider* p=owner->context->FUN_000862a0();
 Inventory* inv=p->FUN_00203d70();
 content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
 Object* obj=inv->find(&caster,k1,k2);
 if(!obj) return;
 unsigned __int64 key=FUN_0027b020(value);
 Info* info=obj->FUN_001d4fc0();
 int ti=r->table; if(ti<0) return;
 Table* t=info->tables[ti];
 for(int i=0;i<t->count;++i) { Entry& e=t->entries[i]; if(e.low==(unsigned)key && e.high==(unsigned)(key>>32)) { if(e.index!=-1) { r->table=(signed char)e.index; r->state=0; } return; } }
}
