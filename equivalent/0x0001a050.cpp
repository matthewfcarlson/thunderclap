// STATUS: equivalent (tools/equiv.py level 3: 1441 inputs, branch coverage 22/22)
// FUN_0001a050 @ 0x0001a050
struct Actor;
struct Link { Actor* FUN_00059a30(); };
struct Owner { Link* FUN_000592a0(); };
struct Actor {
 char pad0[0x12c]; int kind;
 char pad1[0x334-0x130]; Actor* related334; Actor* related338;
 char pad2[0x390-0x33c]; Actor* related390;
 char pad3[0x20b0-0x394]; int disabled;
 bool FUN_00035c30(int);
 int FUN_00038f90(int,int,int);
};
struct Collection { char pad[0xc]; int count; Actor* FUN_00024190(int); };
struct Global { char pad[0x20]; Collection* collection; };
extern Global* DAT_004dd700;
struct Config { char pad[0x2c]; int value; };
struct Target {
 char pad[0x1c]; Owner* owner; Config* config;
 void FUN_00019470(Actor*,int,int,int,float);
 bool FUN_00013ed0();
 void FUN_0001a050(int,int);
};
void Target::FUN_0001a050(int arg,int secondary) {
 Actor* self = owner->FUN_000592a0()->FUN_00059a30();
 Collection* list = DAT_004dd700->collection;
 int count = list->count;
 for(int i=0;i<count;++i) {
  Actor* other = list->FUN_00024190(i);
  if(other == self || !other || other->disabled || other == self->related338 || other == self->related334 || other == self->related390) continue;
  if(self->FUN_00035c30(other->kind)) continue;
  int value = config->value;
  int result = other->FUN_00038f90(arg,value,0);
  if(result) {
   FUN_00019470(other,result,arg,secondary,1.0f);
   if(FUN_00013ed0()) break;
  }
 }
}