// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// pure3d::Vector3DOFChannel::vfunc_4 @ 0x0028a7c0
namespace pure3d {
struct Vector { float x,y,z; };
struct Vector3DOFChannel {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4(float time, Vector* out);
 virtual void vfunc_5();
 int interpolate;
 char pad[12];
 short* frames;
 Vector* values;
 bool FUN_00289f80(float time, int* first, int* second);
};
void Vector3DOFChannel::vfunc_4(float time, Vector* out) {
 int first, second;
 bool found = FUN_00289f80(time, &first, &second);
 if (found && interpolate) {
  double delta = (double)time - frames[first];
  if (delta != 0.0) {
   double t = delta / (int)(frames[second] - frames[first]);
   out->x = (float)(((double)values[second].x - values[first].x) * t + values[first].x);
   out->y = (float)(((double)values[second].y - values[first].y) * t + values[first].y);
   out->z = (float)(((double)values[second].z - values[first].z) * t + values[first].z);
   return;
  }
 }
 *out = values[first];
}
}
