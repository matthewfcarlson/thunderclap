// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// pure3d::scenegraph::Scenegraph::vfunc_12 @ 0x00296cb0
namespace pure3d { namespace scenegraph {
struct BoundingVolumeUpdater { virtual void vfunc_0(); unsigned char flag; char pad[3]; float bounds[6]; };
}}
struct Sphere { float x,y,z,r; };
struct Bounds { float v[6]; Sphere* FUN_000a8890(Sphere* out); };
void __cdecl FUN_00296220(void* root, pure3d::scenegraph::BoundingVolumeUpdater* updater);
namespace pure3d { namespace scenegraph {
struct Scenegraph {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
 char pad[16]; Bounds bounds; Sphere sphere; char gap[4]; void* root;
};
void Scenegraph::vfunc_12() {
 if(root) {
 BoundingVolumeUpdater updater; updater.flag=0;
 for(int i=0;i<6;++i) updater.bounds[i]=0.0f;
 FUN_00296220(root,&updater);
 Bounds copy;
 for(int j=0;j<6;++j) copy.v[j]=updater.bounds[j];
 bounds=copy;
 Sphere* result=bounds.FUN_000a8890(reinterpret_cast<Sphere*>(&copy));
 sphere.x=result->x; sphere.y=result->y; sphere.z=result->z; sphere.r=result->r;
 } else {
 for(int k=0;k<6;++k) bounds.v[k]=0.0f;
 sphere.x=0.0f; sphere.y=0.0f; sphere.z=0.0f; sphere.r=0.0f;
 }
}
}}
