// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// pure3d::QuaternionChannel::vfunc_5 @ 0x0028aa20
namespace pure3d {
struct Quaternion {
 float x,y,z,w;
 void FUN_0022b750(const Quaternion*, const Quaternion*, float);
};
struct QuaternionChannel {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5(float time, Quaternion* out);
 virtual void vfunc_6();
 int active;
 char pad[12];
 short* times;
 Quaternion* values;
 bool FUN_00289f80(float, int*, int*);
};
void QuaternionChannel::vfunc_5(float time, Quaternion* out) {
 int first, second;
 bool found = FUN_00289f80(time, &first, &second);
 if (found && active) {
   double delta = (double)time - (int)times[first];
   if (delta != 0.0f) {
     int span = (int)times[second] - (int)times[first];
     out->FUN_0022b750(&values[first], &values[second], (float)(delta / span));
     return;
   }
 }
 *out = values[first];
}
}
