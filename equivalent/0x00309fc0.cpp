// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// physics::PhysicsJoint3D::vfunc_26 @ 0x00309fc0
struct Vec3_309fc0 { float x,y,z; };
struct JointData_309fc0 { void FUN_00310490(void*, Vec3_309fc0*, int); };
namespace physics {
struct PhysicsJoint3D {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual float vfunc_20(Vec3_309fc0*); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual bool vfunc_26(const Vec3_309fc0*,Vec3_309fc0*);
 char pad4[4]; void* body; char padc[12]; JointData_309fc0* data; char pad1c[200]; float strength;
};
bool PhysicsJoint3D::vfunc_26(const Vec3_309fc0* axis,Vec3_309fc0* output) {
 Vec3_309fc0 v;
 data->FUN_00310490(body,&v,0);
 double cy=(double)v.z*axis->x-(double)v.x*axis->z;
 double cz=(double)v.x*axis->y-(double)v.y*axis->x;
 double cx=(double)v.y*axis->z-(double)v.z*axis->y;
 output->x=(float)cx; output->y=(float)cy; output->z=(float)cz;
 double scale=-(2.0*(double)strength);
 output->x=(float)(scale*output->x);
 output->y=(float)(scale*cy);
 output->z=(float)(scale*cz);
 vfunc_20(output);
 float factor=vfunc_20(output);
 if(factor>0.0f) { output->x*=factor; output->y*=factor; output->z*=factor; return true; }
 return false;
}
}