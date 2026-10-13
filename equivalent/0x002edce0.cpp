// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 19/20, incomplete)
// FUN_002edce0 @ 0x002edce0
struct Vec { float x,y,z; float FUN_0022d110(); };
struct Hit { char pad[8]; void* object; };
struct Entry { char p0[0x20]; void* object; char p1[0x2c]; unsigned char flag50; char p2[0x21]; unsigned char enabled; };
extern unsigned char __cdecl FUN_002f15a0(Vec*, Vec*, Vec*, float, void*, Hit*);
struct Manager { Entry** begin; Entry** end; unsigned char FUN_002edce0(Hit*, Vec*, Vec*, unsigned char); };
unsigned char Manager::FUN_002edce0(Hit* hit, Vec* start, Vec* finish, unsigned char filter) {
 Vec delta; delta.x=finish->x-start->x; delta.y=finish->y-start->y; delta.z=finish->z-start->z;
 Vec direction=delta;
 float length=direction.FUN_0022d110();
 unsigned char result=0;
 if(hit->object) { result=FUN_002f15a0(start,&direction,&delta,length,hit->object,hit); if(result) return result; }
 unsigned int i=0;
 if((unsigned int)(end-begin)>0) {
 do {
 Entry* entry=begin[i];
 if(entry->enabled && entry->object!=hit->object && (!filter || entry->flag50)) {
 result=FUN_002f15a0(start,&direction,&delta,length,entry->object,hit);
 if(result) return result;
 }
 ++i;
 } while(i<(unsigned int)(end-begin));
 }
 hit->object=0;
 return result;
}