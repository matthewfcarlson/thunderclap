// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// physics::CollisionSolverAgent::vfunc_9 @ 0x002f8920
#include "gen/physics.h"

struct Vec3_2f8920 { float x,y,z; };
struct Body_2f8920 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual bool slot11(); virtual void slot12(); virtual void slot13(); virtual float slot14(); virtual float slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(Vec3_2f8920*,Vec3_2f8920*,int); virtual void slot26(); virtual void slot27(int);
};
struct AgentInput {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual Body_2f8920* slot9(int);
 char pad[0x68]; int mode;
};
namespace physics {  }
int physics::CollisionSolverAgent::vfunc_9(int __p0, int index) { AgentInput * input = (AgentInput *)__p0;

 Body_2f8920* body=input->slot9(index);
 if(input->mode!=1) { body->slot27(-1); return 0; }
 if(!body->slot11() || index>0) return 0;
 Vec3_2f8920 a,b;
 body->slot25(&a,&b,-1);
 float r=body->slot14();
 if(!((r+r)*(r+r) >= a.z*a.z+a.x*a.x+a.y*a.y)) return 0;
 r=body->slot15();
 if(!((r+r)*(r+r) >= b.z*b.z+b.y*b.y+b.x*b.x)) return 0;
 body->slot27(-1);
 return 1;
}
