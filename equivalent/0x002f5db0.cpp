// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// physics::PhysicsObject::vfunc_19 @ 0x002f5db0
struct Vec { float x,y,z; };
struct Matrix { char pad[0x24]; void FUN_002fd020(Vec*,Vec*); };
struct State { char pad[0x40]; Vec position; char gap[4]; Vec velocity; Vec result; };
namespace physics {
struct PhysicsObject {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual bool vfunc_11(); virtual void v12(); virtual void vfunc_13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void vfunc_19(int,int,int);
 char p4[12]; State* state; char p14[0x84]; Vec position; char pa4[0x1c]; Vec angular; char pcc[0x48]; Matrix matrix; char p138[0x10]; unsigned char applied; char p149[3]; Vec linearImpulse; Vec angularImpulse; char p164[0x68]; int pending;
};
void PhysicsObject::vfunc_19(int,int,int) {
 if (!applied) {
  if(vfunc_11()) vfunc_13();
  Vec transformed; matrix.FUN_002fd020(&angularImpulse,&transformed);
  State* s=state;
  float dx=position.x-s->position.x;
  float dy=position.y-s->position.y;
  float dz=position.z-s->position.z;
  volatile float cx=dy*transformed.z-dz*transformed.y;
  volatile float cy=dz*transformed.x-dx*transformed.z;
  float cz=dx*transformed.y-dy*transformed.x;
  float vx=cx+linearImpulse.x;
  volatile float vy=cy+linearImpulse.y;
  volatile float vz=cz+linearImpulse.z;
  s->velocity.x=vx+s->velocity.x;
  s->velocity.y=vy+s->velocity.y;
  s->velocity.z=vz+s->velocity.z;
  angular.x=angular.x+angularImpulse.x;
  angular.y=angularImpulse.y+angular.y;
  angular.z=angularImpulse.z+angular.z;
  matrix.FUN_002fd020(&angular,&state->result);
  pending=0;
 }
 applied=1;
}
}