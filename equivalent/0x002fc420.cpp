// STATUS: equivalent (tools/equiv.py level 3: 1114 inputs, branch coverage 12/12)
// FUN_002fc420 @ 0x002fc420
#include "gen/physics.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct TypeInfo_2fc420 { unsigned int value; }; extern TypeInfo_2fc420 DAT_004c60bc, DAT_004d2d90;
struct JointSet { char pad[0x1f8]; void **joints; int unused; int count; };
extern "C" JointSet* __cdecl FUN_00344e74(void*, int, TypeInfo_2fc420*, TypeInfo_2fc420*, int);
extern "C" void* __cdecl FUN_00263ea0(unsigned int);
struct FUN_0030eb10 { FUN_0030eb10(); virtual void slot0(); char pad[0x14]; void* target; int extra; };
namespace physics {
struct PhysicsJointMatrixModifier_2fc420 : FUN_0030eb10 { virtual void slot0(); };
struct RootMatrixDriver_2fc420 : FUN_0030eb10 { virtual void slot0(); };
}
struct Container_2fc420 { void FUN_0030fda0(int, FUN_0030eb10*); };
struct State_2fc420 { char pad[0x70]; unsigned char active; void FUN_003046f0(int); };
struct Object_2fc420 { virtual void slot0(); char pad[0x6c]; void* source; State_2fc420* state; void FUN_002ef8b0(int); };

void physics::PhysicsInstance::FUN_002fc420() {
 if((*(Container_2fc420 * *)&this->f_14)) {
  JointSet* set=FUN_00344e74((*(Object_2fc420 * *)&this->f_10)->source,0,&DAT_004c60bc,&DAT_004d2d90,0);
  if(set) for(int i=0;i<set->count;++i) {
   void* joint=set->joints[i];
   void* mem=FUN_00263ea0(0x20);
   FUN_0030eb10* mod=0;
   if(mem) { mod=new(mem) physics::PhysicsJointMatrixModifier_2fc420; mod->target=joint; }
   (*(Container_2fc420 * *)&this->f_14)->FUN_0030fda0(1,mod);
  }
  void* mem=FUN_00263ea0(0x20);
  FUN_0030eb10* mod=0;
  if(mem) { void* target=(char*)(*(Object_2fc420 * *)&this->f_10)+0x10; mod=new(mem) physics::RootMatrixDriver_2fc420; mod->target=target; }
  (*(Container_2fc420 * *)&this->f_14)->FUN_0030fda0(0,mod);
 }
 (*(Object_2fc420 * *)&this->f_10)->slot0(); (*(Object_2fc420 * *)&this->f_10)->state->active=1; (*(Object_2fc420 * *)&this->f_10)->FUN_002ef8b0(0); (*(Object_2fc420 * *)&this->f_10)->state->FUN_003046f0(0); this->f_08=2; (*(unsigned char *)&this->f_0c)=0;
}
