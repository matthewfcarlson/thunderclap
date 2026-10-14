// STATUS: equivalent (tools/equiv.py level 3: 725 inputs, branch coverage 18/18)
// FUN_001e3020 @ 0x001e3020
class CSPHulkProp;
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; }}
struct Entry { char pad[8]; int key1; int key2; };
struct Inventory { char pad[0x1c]; Entry **begin; Entry **end; };
struct Prop { Inventory *FUN_001d4fc0(); };
struct Linked { char pad[0xec]; Prop *prop; };
struct Resolver { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Prop *find(content::LoadInventory::DynamicCaster<CSPHulkProp> *, int, int); };
struct Service { Resolver *FUN_00203d70(); };
struct Provider { Service *FUN_000862a0(); };
struct Owner { char pad[0x54]; Provider *provider; };
struct Record { char pad[8]; int key1; int key2; char pad2[8]; Linked *linked; char pad3[6]; short type; char pad4[4]; };
struct Flags { unsigned char flags; char pad[19]; };
struct Game { char pad[0x608]; Record records[0x704]; char rest[0x14618 - 0x608 - 0x704*40]; Flags flags[0x800]; char rest2[0x1e830 - 0x14618 - 0x800*20]; Owner *owner; int FUN_001e3020(int index,int key1,int key2); };
int Game::FUN_001e3020(int index,int key1,int key2) {
 if(index < 0) return -1;
 Record &r=records[index];
 Prop *p;
 if((flags[r.type].flags & 1) && r.linked) p=r.linked->prop;
 else { int a=r.key1,b=r.key2; Service *s=owner->provider->FUN_000862a0(); Resolver *v=s->FUN_00203d70(); content::LoadInventory::DynamicCaster<CSPHulkProp> caster; p=v->find(&caster,a,b); if(!p) return -1; }
 Inventory *inv=p->FUN_001d4fc0();
 if(!inv) return -1;
 Entry **entries=inv->begin; int count=inv->end-entries;
 for(int i=0;i<count;++i) { Entry *e=entries[i]; if(e->key1==key1 && e->key2==key2) return i; }
 return -1;
}