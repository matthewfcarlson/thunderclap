// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00319270 @ 0x00319270
struct Vec3 { float x,y,z; };
struct Input { char pad[0x44]; Vec3 axis; };
struct Object { char pad[0x48]; float scale[3]; Vec3 axes[3]; void FUN_002fb990(Vec3* out,int axis,int side); };
struct Solver { char pad[0x14]; Vec3 direction; void FUN_00316410(Object*,Vec3*,Vec3*,float,Input*,float,float,int); void target(Object*,Input*); };
void Solver::target(Object* obj,Input* input) {
 float projection = (input->axis.z * direction.z + input->axis.y * direction.y) + input->axis.x * direction.x;
 Vec3 point;
 for(int i=0;i<3;++i) {
  float component = ((obj->axes[i].z * input->axis.z + obj->axes[i].y * input->axis.y) + input->axis.x * obj->axes[i].x) * obj->scale[i];
  for(int j=0;j<2;++j) {
   obj->FUN_002fb990(&point,i,j);
   FUN_00316410(obj,&point,&obj->axes[i],obj->scale[i],input,projection,component,0);
  }
 }
}
