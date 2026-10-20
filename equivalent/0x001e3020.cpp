// STATUS: equivalent (tools/equiv.py level 3: 725 inputs, branch coverage 18/18)
// FUN_001e3020 @ 0x001e3020
#include "compat/ptr.h"
class CSPHulkProp;
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; }}
struct Entry_1e3020 { char pad[8]; int key1; int key2; };
struct Inventory_1e3020 { char pad[0x1c]; Entry_1e3020 **begin; Entry_1e3020 **end; };
struct Prop_1e3020 { Inventory_1e3020 *FUN_001d4fc0(); };
struct Linked_1e3020 { char pad[0xec]; Prop_1e3020 *prop; };
struct Resolver_1e3020 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Prop_1e3020 *find(content::LoadInventory::DynamicCaster<CSPHulkProp> *, int, int); };
struct Service_1e3020 { Resolver_1e3020 *FUN_00203d70(); };
struct Provider_1e3020 { Service_1e3020 *FUN_000862a0(); };
struct Owner_1e3020 { char pad[0x54]; Provider_1e3020 *provider; };
struct Record_1e3020 { char pad[8]; int key1; int key2; char pad2[8]; Linked_1e3020 *linked; char pad3[6]; short type; char pad4[4]; };
struct Flags_1e3020 { unsigned char flags; char pad[19]; };
struct Game_1e3020 { char pad[0x608]; Record_1e3020 records[0x704]; char rest[0x14618 - 0x608 - 0x704*40]; Flags_1e3020 flags[0x800]; char rest2[0x1e830 - 0x14618 - 0x800*20]; Owner_1e3020 *owner; int FUN_001e3020(int index,int key1,int key2); };
int Game_1e3020::FUN_001e3020(int index,int key1,int key2) {
 if(index < 0) return -1;
 Record_1e3020 &r=records[index];
 Prop_1e3020 *p;
 if((flags[r.type].flags & 1) && r.linked) p=r.linked->prop;
 else { int a=r.key1,b=r.key2; Service_1e3020 *s=owner->provider->FUN_000862a0(); Resolver_1e3020 *v=s->FUN_00203d70(); content::LoadInventory::DynamicCaster<CSPHulkProp> caster; p=v->find(&caster,a,b); if(!p) return -1; }
 Inventory_1e3020 *inv=p->FUN_001d4fc0();
 if(!inv) return -1;
 Entry_1e3020 **entries=inv->begin; hulk_intptr count=inv->end-entries;
 for(int i=0;i<count;++i) { Entry_1e3020 *e=entries[i]; if(e->key1==key1 && e->key2==key2) return i; }
 return -1;
}