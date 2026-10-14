// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00319270 @ 0x00319270
struct Vec3_319270 { float x,y,z; };
struct Input_319270 { char pad[0x44]; Vec3_319270 axis; };
struct Object { char pad[0x48]; float scale[3]; Vec3_319270 axes[3]; void FUN_002fb990(Vec3_319270* out,int axis,int side); };
struct Solver_319270 { char pad[0x14]; Vec3_319270 direction; void FUN_00316410(Object*,Vec3_319270*,Vec3_319270*,float,Input_319270*,float,float,int); void target(Object*,Input_319270*); };
void Solver_319270::target(Object* obj,Input_319270* input) {
 float projection = (input->axis.z * direction.z + input->axis.y * direction.y) + input->axis.x * direction.x;
 Vec3_319270 point;
 for(int i=0;i<3;++i) {
  float component = ((obj->axes[i].z * input->axis.z + obj->axes[i].y * input->axis.y) + input->axis.x * obj->axes[i].x) * obj->scale[i];
  for(int j=0;j<2;++j) {
   obj->FUN_002fb990(&point,i,j);
   FUN_00316410(obj,&point,&obj->axes[i],obj->scale[i],input,projection,component,0);
  }
 }
}
