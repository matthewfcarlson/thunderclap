// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// pure3d::scenegraph::Scenegraph::vfunc_12 @ 0x00296cb0
#include "gen/pure3d.h"

namespace pure3d { namespace scenegraph {
struct BoundingVolumeUpdater_296cb0 { virtual void vfunc_0(); unsigned char flag; char pad[3]; float bounds[6]; };
}}
struct Sphere_296cb0 { float x,y,z,r; };
struct Bounds_296cb0 { float v[6]; Sphere_296cb0* FUN_000a8890(Sphere_296cb0* out); };
void __cdecl FUN_00296220(void* root, pure3d::scenegraph::BoundingVolumeUpdater_296cb0* updater);
namespace pure3d { namespace scenegraph {

}}
void pure3d::scenegraph::Scenegraph::vfunc_12() {
 if((*(void * *)&this->f_40)) {
 BoundingVolumeUpdater_296cb0 updater; updater.flag=0;
 for(int i=0;i<6;++i) updater.bounds[i]=0.0f;
 FUN_00296220((*(void * *)&this->f_40),&updater);
 Bounds_296cb0 copy;
 for(int j=0;j<6;++j) copy.v[j]=updater.bounds[j];
 (*(Bounds_296cb0 *)&this->f_14)=copy;
 Sphere_296cb0* result=(*(Bounds_296cb0 *)&this->f_14).FUN_000a8890(reinterpret_cast<Sphere_296cb0*>(&copy));
 (*(Sphere_296cb0 *)&this->f_2c).x=result->x; (*(Sphere_296cb0 *)&this->f_2c).y=result->y; (*(Sphere_296cb0 *)&this->f_2c).z=result->z; (*(Sphere_296cb0 *)&this->f_2c).r=result->r;
 } else {
 for(int k=0;k<6;++k) (*(Bounds_296cb0 *)&this->f_14).v[k]=0.0f;
 (*(Sphere_296cb0 *)&this->f_2c).x=0.0f; (*(Sphere_296cb0 *)&this->f_2c).y=0.0f; (*(Sphere_296cb0 *)&this->f_2c).z=0.0f; (*(Sphere_296cb0 *)&this->f_2c).r=0.0f;
 }
}
