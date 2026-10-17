// STATUS: equivalent (tools/equiv.py level 3: 6665 inputs, branch coverage 4/4)
// FUN_001af650 @ 0x001af650
#include "decls/address.h"
struct Vec_1af650 { unsigned x,y,z; };
struct Query_1af650 { void FUN_001b6000(Vec_1af650*, unsigned*, int*); };
struct World { char pad[16]; Query_1af650* query; };
struct Object {
 bool FUN_001af540(Vec_1af650*,Vec_1af650*,unsigned,unsigned,unsigned,Vec_1af650*,unsigned*,int*,unsigned);
 unsigned FUN_001ae450(unsigned,Vec_1af650*,unsigned,int);
 unsigned target(Vec_1af650* start,Vec_1af650* end,unsigned* value,unsigned a4,unsigned a5,unsigned a6,Vec_1af650* output,unsigned a8,unsigned a9);
};
struct ArgSlots_1af650 { int index; unsigned status; };
// The original's 0x28-byte frame: each endpoint's copy with the two values the query fills.
struct Frame_1af650 {
 Vec_1af650 first; unsigned firstExtra; int firstId;
 Vec_1af650 second; unsigned secondExtra; int secondId;
};
unsigned Object::target(Vec_1af650* start,Vec_1af650* end,unsigned* value,unsigned a4,unsigned a5,unsigned a6,Vec_1af650* output,unsigned a8,unsigned a9) {
 Frame_1af650 f;
 Vec_1af650* from=start;
 f.first=*start;
 f.firstExtra=0; f.firstId=-1;
 DAT_004dd700->query->FUN_001b6000(&f.first,&f.firstExtra,&f.firstId);
 f.second=*end;
 f.secondExtra=0; f.secondId=-1;
 DAT_004dd700->query->FUN_001b6000(&f.second,&f.secondExtra,&f.secondId);
 // The found index and the status live in the dead start/end argument slots; the callee
 // gets a pointer to them.
 ArgSlots_1af650* slots=(ArgSlots_1af650*)&start;
 slots->status=2;
 if(f.firstId==-1) return slots->status;
 slots->index=-1;
 if(FUN_001af540(&f.first,&f.second,*value,a4,a6,output,&a6,&slots->index,a9))
   return FUN_001ae450(a6,output,0,slots->index);
 output->x=from->x; output->y=from->y; output->z=from->z;
 return slots->status;
}
