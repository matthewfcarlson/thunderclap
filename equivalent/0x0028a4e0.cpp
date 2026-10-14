// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 6/6)
// pure3d::Vector1DOFChannel::vfunc_4 @ 0x0028a4e0
namespace pure3d {
struct Vector { float x,y,z; };
struct Vector1DOFChannel {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(float time, Vector* out); virtual void vfunc_5();
 int enabled; char pad[12]; short* times; int axis; Vector base; float* values;
 bool FUN_00289f80(float time, int* first, int* second);
};
void Vector1DOFChannel::vfunc_4(float time, Vector* out) {
 out->x=base.x; out->y=base.y; out->z=base.z;
 int first, second;
 if (FUN_00289f80(time,&first,&second) && enabled) {
  double delta=(double)time-(int)times[first];
  if(delta==0.0f) { (&out->x)[axis]=values[first]; return; }
  (&out->x)[axis]=(float)(((double)values[second]-values[first])/((int)times[second]-(int)times[first])*delta+values[first]);
 } else { (&out->x)[axis]=values[first]; }
}
}
