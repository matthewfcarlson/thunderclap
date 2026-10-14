// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 7/8, incomplete)
// AICollisionSolverAgent::vfunc_9 @ 0x001b0fb0
struct Vec_1b0fb0 { float x,y,z; float FUN_0022d110(); };
struct Body_1b0fb0 { char pad[0x14c]; unsigned char enabled; };
struct Contact_1b0fb0 { char pad0[8]; Body_1b0fb0* body; int type; char pad1[0x40]; Vec_1b0fb0 velocity; };
struct Manager_1b0fb0 { bool FUN_00079950(void*); };
struct World { char pad[0x4c]; Manager_1b0fb0* manager; };
extern World* DAT_004dd700;
extern "C" double __cdecl sqrt(double);
class AICollisionSolverAgent { public: int vfunc_9(Contact_1b0fb0*, void*); };
int AICollisionSolverAgent::vfunc_9(Contact_1b0fb0* contact, void*) {
 if(contact->type == 5 && contact->body->enabled) {
  if(!DAT_004dd700->manager->FUN_00079950((char*)contact->body + 8)) {
   Vec_1b0fb0 v = contact->velocity;
   if (!(sqrt((double)v.z*v.z + (double)v.x*v.x + (double)v.y*v.y) < 100.0f)) {
    v.FUN_0022d110();
    contact->velocity.x = v.x * 100.0f;
    contact->velocity.y = v.y * 100.0f;
    contact->velocity.z = v.z * 100.0f;
   }
  }
 }
 return 0;
}