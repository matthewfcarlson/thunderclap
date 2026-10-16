// STATUS: equivalent (tools/equiv.py level 3: 1441 inputs, branch coverage 22/22)
// FUN_0001a050 @ 0x0001a050
#include "decls/address.h"
struct Actor_1a050;
struct Link_1a050 { Actor_1a050* FUN_00059a30(); };
struct Owner_1a050 { Link_1a050* FUN_000592a0(); };
struct Actor_1a050 {
 char pad0[0x12c]; int kind;
 char pad1[0x334-0x130]; Actor_1a050* related334; Actor_1a050* related338;
 char pad2[0x390-0x33c]; Actor_1a050* related390;
 char pad3[0x20b0-0x394]; int disabled;
 bool FUN_00035c30(int);
 int FUN_00038f90(int,int,int);
};
struct Collection_1a050 { char pad[0xc]; int count; Actor_1a050* FUN_00024190(int); };
struct World { char pad[0x20]; Collection_1a050* collection; };
struct Config_1a050 { char pad[0x2c]; int value; };
struct Target_1a050 {
 char pad[0x1c]; Owner_1a050* owner; Config_1a050* config;
 void FUN_00019470(Actor_1a050*,int,int,int,float);
 bool FUN_00013ed0();
 void FUN_0001a050(int,int);
};
void Target_1a050::FUN_0001a050(int arg,int secondary) {
 Actor_1a050* self = owner->FUN_000592a0()->FUN_00059a30();
 Collection_1a050* list = DAT_004dd700->collection;
 int count = list->count;
 for(int i=0;i<count;++i) {
  Actor_1a050* other = list->FUN_00024190(i);
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