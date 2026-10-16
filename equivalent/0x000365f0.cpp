// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000365f0 @ 0x000365f0
#include "decls/address.h"
typedef unsigned long U32_365f0;
extern U32_365f0 DAT_004dc2b0, DAT_004dc2b4, DAT_004dc2b8;
struct Matrix {
 U32_365f0 elements[16];
 void FUN_0022b980();
 void FUN_0022ca90(const Matrix*,const Matrix*);
};
struct Names_365f0 { int FUN_0027b200(U32_365f0,U32_365f0); };
struct Skeleton { char pad[8]; Names_365f0* names; char pad2[16]; Matrix* matrices; };
struct Model_365f0 { char pad[0x64]; Skeleton* skeleton; };
struct Provider_365f0 { Model_365f0* FUN_00059a40(); };
struct Attachment_365f0 { void FUN_002ef8b0(int); };
struct Weapon_365f0 { char pad[0x100]; Attachment_365f0* attachment; void FUN_00080e50(Matrix*); };
struct Actor_365f0 { char pad[0x10]; Provider_365f0* provider; char pad2[0x618]; Weapon_365f0* weapon; void target(int,int); };
void Actor_365f0::target(int,int) {
 Model_365f0* model=provider->FUN_00059a40();
 Weapon_365f0* w=weapon;
 if(w) {
  if(!(DAT_004dc2b8 & 1)) {
   DAT_004dc2b8 |= 1;
   unsigned __int64 key=FUN_0027b020("Wealded_Weap_1");
   DAT_004dc2b0=(U32_365f0)key;
   DAT_004dc2b4=(U32_365f0)(key>>32);
  }
  int index=model->skeleton->names->FUN_0027b200(DAT_004dc2b0,DAT_004dc2b4);
  if(w->attachment) w->attachment->FUN_002ef8b0(0);
  Matrix bone=model->skeleton->matrices[index];
  Matrix identity;
  identity.FUN_0022b980();
  Matrix result;
  result.FUN_0022ca90(&identity,&bone);
  w->FUN_00080e50(&result);
 }
}
