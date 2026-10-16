// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_002ee140 @ 0x002ee140
#include "decls/data/game/global.h"

struct Vec_2ee140 { float x,y,z; float FUN_0022d110(); };
struct Owner_2ee140 { char pad[16]; void* value; };
struct Item_2ee140 { char pad0[32]; Owner_2ee140* owner; char pad1[44]; unsigned char filter; char pad2[33]; unsigned char enabled; };
struct Entry_2ee140 { char pad[4]; Item_2ee140* item; };
struct Results { int count; char pad[4]; Entry_2ee140* entries; };
struct Record_2ee140 { int zero; void* object; Owner_2ee140* owner; };
extern bool __cdecl FUN_002f1160(Vec_2ee140*,Vec_2ee140*,Vec_2ee140*,float,Record_2ee140*);
extern void __cdecl FUN_002f24f0(Results*,Record_2ee140*,Vec_2ee140*,Vec_2ee140*,float*);
struct World { void FUN_002edc20(Results*,Vec_2ee140*,Vec_2ee140*,Vec_2ee140*,float*,int); bool target(Results*,Vec_2ee140*,Vec_2ee140*,int); };
bool World::target(Results* results, Vec_2ee140* start, Vec_2ee140* end, int filter) {
 Vec_2ee140 difference; difference.x=end->x-start->x; difference.y=end->y-start->y; difference.z=end->z-start->z;
 Vec_2ee140 direction=difference;
 float length=direction.FUN_0022d110();
 if((*(unsigned char*)&DAT_00554c1c) && results->count>0) {
  Record_2ee140 record; record.zero=0; record.object=0; record.owner=0;
  Item_2ee140* item=results->entries->item;
  record.object=item;
  results->count=0;
  record.owner=item->owner;
  if(item->enabled && (!(filter & 255) || item->filter)) {
   if(FUN_002f1160(start,&direction,&difference,length,&record)) {
    record.object=record.owner->value;
    FUN_002f24f0(results,&record,&direction,&difference,&length);
   }
  }
 }
 FUN_002edc20(results,start,&direction,&difference,&length,filter);
 return results->count>0;
}