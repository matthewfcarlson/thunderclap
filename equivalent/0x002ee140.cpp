// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_002ee140 @ 0x002ee140
struct Vec { float x,y,z; float FUN_0022d110(); };
struct Owner { char pad[16]; void* value; };
struct Item { char pad0[32]; Owner* owner; char pad1[44]; unsigned char filter; char pad2[33]; unsigned char enabled; };
struct Entry { char pad[4]; Item* item; };
struct Results { int count; char pad[4]; Entry* entries; };
struct Record { int zero; void* object; Owner* owner; };
extern unsigned char DAT_00554c1c;
extern bool __cdecl FUN_002f1160(Vec*,Vec*,Vec*,float,Record*);
extern void __cdecl FUN_002f24f0(Results*,Record*,Vec*,Vec*,float*);
struct World { void FUN_002edc20(Results*,Vec*,Vec*,Vec*,float*,int); bool target(Results*,Vec*,Vec*,int); };
bool World::target(Results* results, Vec* start, Vec* end, int filter) {
 Vec difference; difference.x=end->x-start->x; difference.y=end->y-start->y; difference.z=end->z-start->z;
 Vec direction=difference;
 float length=direction.FUN_0022d110();
 if(DAT_00554c1c && results->count>0) {
  Record record; record.zero=0; record.object=0; record.owner=0;
  Item* item=results->entries->item;
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