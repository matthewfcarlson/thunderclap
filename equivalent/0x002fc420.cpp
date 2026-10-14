// STATUS: equivalent (tools/equiv.py level 3: 1114 inputs, branch coverage 12/12)
// FUN_002fc420 @ 0x002fc420
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct TypeInfo_2fc420 { unsigned int value; }; extern TypeInfo_2fc420 DAT_004c60bc, DAT_004d2d90;
struct JointSet { char pad[0x1f8]; void **joints; int unused; int count; };
extern "C" JointSet* __cdecl FUN_00344e74(void*, int, TypeInfo_2fc420*, TypeInfo_2fc420*, int);
extern "C" void* __cdecl FUN_00263ea0(unsigned int);
struct FUN_0030eb10 { FUN_0030eb10(); virtual void slot0(); char pad[0x14]; void* target; int extra; };
namespace physics {
struct PhysicsJointMatrixModifier : FUN_0030eb10 { virtual void slot0(); };
struct RootMatrixDriver : FUN_0030eb10 { virtual void slot0(); };
}
struct Container_2fc420 { void FUN_0030fda0(int, FUN_0030eb10*); };
struct State_2fc420 { char pad[0x70]; unsigned char active; void FUN_003046f0(int); };
struct Object { virtual void slot0(); char pad[0x6c]; void* source; State_2fc420* state; void FUN_002ef8b0(int); };
struct Controller_2fc420 { char pad[8]; int mode; unsigned char flag; char pad2[3]; Object* object; Container_2fc420* container; void FUN_002fc420(); };
void Controller_2fc420::FUN_002fc420() {
 if(container) {
  JointSet* set=FUN_00344e74(object->source,0,&DAT_004c60bc,&DAT_004d2d90,0);
  if(set) for(int i=0;i<set->count;++i) {
   void* joint=set->joints[i];
   void* mem=FUN_00263ea0(0x20);
   FUN_0030eb10* mod=0;
   if(mem) { mod=new(mem) physics::PhysicsJointMatrixModifier; mod->target=joint; }
   container->FUN_0030fda0(1,mod);
  }
  void* mem=FUN_00263ea0(0x20);
  FUN_0030eb10* mod=0;
  if(mem) { void* target=(char*)object+0x10; mod=new(mem) physics::RootMatrixDriver; mod->target=target; }
  container->FUN_0030fda0(0,mod);
 }
 object->slot0(); object->state->active=1; object->FUN_002ef8b0(0); object->state->FUN_003046f0(0); mode=2; flag=0;
}