// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::PhysicsObject::vfunc_18 @ 0x002f5c70
struct Vec_2f5c70 { float x,y,z; };
namespace physics {
struct PhysicsObject {
 char pad0[0x44]; float mass;
 char pad48[0x98-0x48]; Vec_2f5c70 position;
 char pada4[0x148-0xa4]; unsigned char flag; char pad149[3]; Vec_2f5c70 linear; Vec_2f5c70 angular;
 bool vfunc_18(const Vec_2f5c70* point, const Vec_2f5c70* force, unsigned a, unsigned b, unsigned c, unsigned d);
};
}
bool physics::PhysicsObject::vfunc_18(const Vec_2f5c70* point, const Vec_2f5c70* force, unsigned a, unsigned b, unsigned c, unsigned d) {
 float scale=mass;
 flag=0;
 linear.x=scale*force->x;
 linear.y=scale*force->y;
 linear.z=scale*force->z;
 angular.x=point->x-position.x;
 angular.y=point->y-position.y;
 angular.z=point->z-position.z;
 double y=(double)force->x*angular.z-(double)angular.x*force->z;
 double z=(double)force->y*angular.x-(double)force->x*angular.y;
 double x=(double)angular.y*force->z-(double)force->y*angular.z;
 angular.x=(float)x;
 angular.y=(float)y;
 angular.z=(float)z;
 return true;
}