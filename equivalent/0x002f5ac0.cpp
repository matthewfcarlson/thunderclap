// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// physics::PhysicsObject::vfunc_32 @ 0x002f5ac0
struct Vec { float x,y,z; };
namespace physics {
struct PhysicsObject {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual bool vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
char pad0[0x98-4]; Vec position; char pad1[0x130-0xa4]; Vec force; Vec torque; char pad2[0x1d0-0x148]; unsigned char dirty;
void vfunc_32(Vec* f, Vec* p);
};
void PhysicsObject::vfunc_32(Vec* f, Vec* p) {
force.x += f->x; force.y += f->y; force.z += f->z;
if(p) {
 double x=(double)p->x-position.x, y=(double)p->y-position.y, z=(double)p->z-position.z;
 float ty=(float)(z*f->x-x*f->z);
 float tz=(float)(x*f->y-y*f->x);
 torque.x=(float)(y*f->z-z*f->y+torque.x);
 torque.y += ty; torque.z += tz; dirty=1;
}
if(vfunc_11()) vfunc_13();
}
}