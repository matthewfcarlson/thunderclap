// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::CollisionMesh::vfunc_16 @ 0x002f3d00
struct Vec { float x,y,z; };
struct Ray { char data[0x84]; void FUN_00306ef0(const Vec*,const Vec*,float); void FUN_00306fb0(); };
extern "C" double __cdecl sqrt(double);
namespace physics { struct CollisionMesh {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual bool vfunc_15(Ray*,void*); virtual bool vfunc_16(const Vec*,const Vec*,void*);
}; }
bool physics::CollisionMesh::vfunc_16(const Vec* start,const Vec* end,void* out) {
Vec direction;
 double dx=(double)end->x-start->x;
 double dy=(double)end->y-start->y;
 direction.z=end->z-start->z;
 float length=(float)sqrt((double)(end->z-start->z)*direction.z+dx*dx+dy*dy);
 volatile float inverse=1.0f/length;
 direction.x=(float)(dx*inverse); direction.y=(float)(dy*inverse); direction.z*=inverse;
 Ray ray; ray.FUN_00306ef0(start,&direction,length);
 bool result=vfunc_15(&ray,out);
 ray.FUN_00306fb0(); return result;
}