// STATUS: equivalent (tools/equiv.py level 3: 1590 inputs, branch coverage 14/14)
// FUN_001d6000 @ 0x001d6000
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
typedef unsigned int uint;
extern int __cdecl FUN_00096600(const char*, const char*);
struct Property_1d6000 { uint low, high; const char* value; uint unused; };
struct Item_1d6000 { char pad[0x3c]; int count; Property_1d6000* properties; };
struct Collection_1d6000 { char pad[0x1c]; Item_1d6000** begin; Item_1d6000** end; };
struct Object { char pad[0x90]; Collection_1d6000* collection; bool check(int index); };
bool Object::check(int index) {
 uint low,high;
 if (!((*(uint*)&DAT_004e2428) & 1)) {
  (*(uint*)&DAT_004e2428) |= 1;
  unsigned __int64 key = FUN_0027b020("climbable");
  low=(uint)key; high=(uint)(key>>32);
  (*(uint*)&DAT_004e2420)=low; (*(uint*)&DAT_004e2424)=high;
 } else { low=(*(uint*)&DAT_004e2420); high=(*(uint*)&DAT_004e2424); }
 if(index<0) return false;
 Collection_1d6000* c=collection;
 hulk_intptr n=c->end-c->begin;
 if(index>=n) return false;
 Item_1d6000* item=c->begin[index];
 int count=item->count;
 if(count<=0) return false;
 Property_1d6000* p=item->properties;
 for(int i=0;i<count;++i,++p) {
  if(p->low==low && p->high==high) return FUN_00096600(p->value,"true")==0;
 }
 return false;
}