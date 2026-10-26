// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 8/8)
// physics::ArticulatedPhysicsObject::vfunc_24 @ 0x00310910
#include "compat/ptr.h"
#include "gen/physics.h"

struct Vec3_310910 { float x,y,z; };
namespace physics {
struct SimulatedObject_310910 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void vfunc_22(Vec3_310910*);
 int unused; int count; int next;
 char pad[0xd4-0x10]; Vec3_310910 position; char pad2[0xec-0xe0]; unsigned char active;
};
}
bool physics::ArticulatedPhysicsObject::vfunc_24(hulk_intptr __p0, hulk_intptr __p1, int index) { const Vec3_310910 * point = (const Vec3_310910 *)__p0; Vec3_310910 * result = (Vec3_310910 *)__p1;

 bool changed=false;
 SimulatedObject_310910 *node=(*(SimulatedObject_310910 ** *)&this->f_1fc)[index];
 while(node) {
  if(node->count<=0) break;
  if(node->active) {
   Vec3_310910 delta; delta.x=point->x-node->position.x; delta.y=point->y-node->position.y; delta.z=point->z-node->position.z;
   Vec3_310910 velocity; node->vfunc_22(&velocity);
   volatile float z=velocity.x*delta.y-velocity.y*delta.x; // the original rounds z through its frame
   result->x += velocity.y*delta.z-velocity.z*delta.y;
   result->y += velocity.z*delta.x-velocity.x*delta.z;
   result->z += z;
   changed=true;
  }
  node=(*(SimulatedObject_310910 ** *)&this->f_1fc)[node->next];
 }
 return changed;
}
