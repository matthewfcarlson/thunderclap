// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// physics::ArticulatedPhysicsObject::vfunc_24 @ 0x00310910
struct Vec3_310910 { float x,y,z; };
namespace physics {
struct SimulatedObject {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void vfunc_22(Vec3_310910*);
 int unused; int count; int next;
 char pad[0xd4-0x10]; Vec3_310910 position; char pad2[0xec-0xe0]; unsigned char active;
};
struct ArticulatedPhysicsObject {
 char pad[0x1fc]; SimulatedObject **nodes;
 bool vfunc_24(const Vec3_310910 *point, Vec3_310910 *result, int index);
};
}
bool physics::ArticulatedPhysicsObject::vfunc_24(const Vec3_310910 *point, Vec3_310910 *result, int index) {
 bool changed=false;
 SimulatedObject *node=nodes[index];
 while(node) {
  if(node->count<=0) break;
  if(node->active) {
   Vec3_310910 delta; delta.x=point->x-node->position.x; delta.y=point->y-node->position.y; delta.z=point->z-node->position.z;
   Vec3_310910 velocity; node->vfunc_22(&velocity);
   float z=velocity.x*delta.y-velocity.y*delta.x;
   result->x += velocity.y*delta.z-velocity.z*delta.y;
   result->y += velocity.z*delta.x-velocity.x*delta.z;
   result->z += z;
   changed=true;
  }
  node=nodes[node->next];
 }
 return changed;
}