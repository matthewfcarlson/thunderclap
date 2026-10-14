// STATUS: equivalent (tools/equiv.py level 3: 667 inputs, branch coverage 6/6)
// pure3d::prop::CMotionTrail::vfunc_10 @ 0x002827e0
struct Vector { float x,y,z; };
struct Sphere { float x,y,z,r; };
struct Bounds { float values[6]; void FUN_000a87f0(Vector*); Sphere* FUN_000a8890(Sphere*); };
namespace pure3d { namespace prop {
struct CMotionTrail {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
 char pad04[16]; Bounds bounds; Sphere sphere; char pad3c[8]; int active; int count; char pad4c[24]; char* samples; int index; int span;
};
void CMotionTrail::vfunc_10() {
 if(active) {
   int offset=0;
   for(int i=0;i<count;++i,offset+=12) {
     bounds.FUN_000a87f0((Vector*)(samples+index*160+offset));
     int sum=span+index;
     int next=(sum%(sum-1))%50;
     bounds.FUN_000a87f0((Vector*)(samples+next*160+offset));
   }
   Sphere temporary;
   Sphere* result=bounds.FUN_000a8890(&temporary);
   sphere.x=result->x; sphere.y=result->y; sphere.z=result->z; sphere.r=result->r;
 } else {
   for(int j=0;j<6;++j) bounds.values[j]=0.0f;
   sphere.x=0.0f; sphere.y=0.0f; sphere.z=0.0f; sphere.r=0.0f;
 }
}
}}
