// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001af650 @ 0x001af650
struct Vec { unsigned x,y,z; };
struct Query { void FUN_001b6000(Vec*, unsigned*, int*); };
struct Manager { char pad[16]; Query* query; };
extern Manager* DAT_004dd700;
struct Result { int index; unsigned status; };
struct Object {
 bool FUN_001af540(Vec*,Vec*,unsigned,unsigned,unsigned,Vec*,unsigned*,int*,unsigned);
 unsigned FUN_001ae450(unsigned,Vec*,unsigned,int);
 unsigned target(Vec* start,Vec* end,unsigned* value,unsigned a4,unsigned a5,unsigned a6,Vec* output,unsigned a8,unsigned a9);
};
unsigned Object::target(Vec* start,Vec* end,unsigned* value,unsigned a4,unsigned a5,unsigned a6,Vec* output,unsigned a8,unsigned a9) {
 Vec first=*start;
 unsigned firstExtra=0; int firstId=-1;
 DAT_004dd700->query->FUN_001b6000(&first,&firstExtra,&firstId);
 Vec second=*end;
 unsigned secondExtra=0; int secondId=-1;
 DAT_004dd700->query->FUN_001b6000(&second,&secondExtra,&secondId);
 Result result; result.status=2;
 if(firstId==-1) return result.status;
 result.index=-1;
 if(FUN_001af540(&first,&second,*value,a4,a6,output,&a6,&result.index,a9))
   return FUN_001ae450(a6,output,0,result.index);
 output->x=start->x; output->y=start->y; output->z=start->z;
 return result.status;
}