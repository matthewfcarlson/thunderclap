// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001af650 @ 0x001af650
#include "decls/address.h"
struct Vec_1af650 { unsigned x,y,z; };
struct Query_1af650 { void FUN_001b6000(Vec_1af650*, unsigned*, int*); };
struct World { char pad[16]; Query_1af650* query; };
struct Result_1af650 { int index; unsigned status; };
struct Object {
 bool FUN_001af540(Vec_1af650*,Vec_1af650*,unsigned,unsigned,unsigned,Vec_1af650*,unsigned*,int*,unsigned);
 unsigned FUN_001ae450(unsigned,Vec_1af650*,unsigned,int);
 unsigned target(Vec_1af650* start,Vec_1af650* end,unsigned* value,unsigned a4,unsigned a5,unsigned a6,Vec_1af650* output,unsigned a8,unsigned a9);
};
unsigned Object::target(Vec_1af650* start,Vec_1af650* end,unsigned* value,unsigned a4,unsigned a5,unsigned a6,Vec_1af650* output,unsigned a8,unsigned a9) {
 Vec_1af650 first=*start;
 unsigned firstExtra=0; int firstId=-1;
 DAT_004dd700->query->FUN_001b6000(&first,&firstExtra,&firstId);
 Vec_1af650 second=*end;
 unsigned secondExtra=0; int secondId=-1;
 DAT_004dd700->query->FUN_001b6000(&second,&secondExtra,&secondId);
 Result_1af650 result; result.status=2;
 if(firstId==-1) return result.status;
 result.index=-1;
 if(FUN_001af540(&first,&second,*value,a4,a6,output,&a6,&result.index,a9))
   return FUN_001ae450(a6,output,0,result.index);
 output->x=start->x; output->y=start->y; output->z=start->z;
 return result.status;
}