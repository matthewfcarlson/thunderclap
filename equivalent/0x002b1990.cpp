// STATUS: equivalent (tools/equiv.py level 3: 148 inputs, branch coverage 16/16)
// pure3d::MultiController::vfunc_12 @ 0x002b1990
namespace pure3d {
struct MultiController {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual float vfunc_10(); virtual void vfunc_11(); virtual int vfunc_12(float frame); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(int mode); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual float vfunc_20();
 char pad04[0x18]; float rate; char pad20[4]; float current; float start; float end; char pad30[4]; float result; char pad38[4]; int mode; unsigned char active; char pad41[3]; unsigned count; MultiController **children;
};
int MultiController::vfunc_12(float frame) {
 double upper = (double)end * rate;
 float lower = start * rate;
 double selected;
 if (frame >= lower && frame <= upper) selected = frame;
 else if (frame > upper) selected = upper;
 else selected = lower;
 current = (float)selected;
 frame = selected > 0.0f ? (float)(selected / rate) : 0.0f;
 for (unsigned i=0; i<count; ++i) {
 float scale = children[i]->vfunc_10();
 children[i]->vfunc_16(mode);
 children[i]->vfunc_12(scale * frame);
 }
 result = vfunc_20();
 int enabled = mode != 3 && mode != 5;
 active = (unsigned char)enabled;
 return enabled;
}
}
