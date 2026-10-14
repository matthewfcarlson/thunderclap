// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000365f0 @ 0x000365f0
typedef unsigned long U32;
extern U32 DAT_004dc2b0, DAT_004dc2b4, DAT_004dc2b8;
extern unsigned __int64 __cdecl FUN_0027b020(const char*);
struct Matrix {
 U32 elements[16];
 void FUN_0022b980();
 void FUN_0022ca90(const Matrix*,const Matrix*);
};
struct Names { int FUN_0027b200(U32,U32); };
struct Skeleton { char pad[8]; Names* names; char pad2[16]; Matrix* matrices; };
struct Model { char pad[0x64]; Skeleton* skeleton; };
struct Provider { Model* FUN_00059a40(); };
struct Attachment { void FUN_002ef8b0(int); };
struct Weapon { char pad[0x100]; Attachment* attachment; void FUN_00080e50(Matrix*); };
struct Actor { char pad[0x10]; Provider* provider; char pad2[0x618]; Weapon* weapon; void target(int,int); };
void Actor::target(int,int) {
 Model* model=provider->FUN_00059a40();
 Weapon* w=weapon;
 if(w) {
  if(!(DAT_004dc2b8 & 1)) {
   DAT_004dc2b8 |= 1;
   unsigned __int64 key=FUN_0027b020("Wealded_Weap_1");
   DAT_004dc2b0=(U32)key;
   DAT_004dc2b4=(U32)(key>>32);
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
