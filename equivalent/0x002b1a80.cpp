// STATUS: equivalent (tools/equiv.py level 3: 147 inputs, branch coverage 17/18, incomplete)
// pure3d::MultiController::vfunc_14 @ 0x002b1a80
namespace pure3d {
struct FrameController {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual float vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(float,float); virtual void vfunc_15(); virtual void vfunc_16(int); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual float vfunc_20();
};
struct MultiController : FrameController {
 char pad[0x18]; float duration; float unused20; float current; float begin; float end; float unused30; float result; int unused38; int mode; unsigned char active; char pad41[3]; unsigned count; FrameController **children;
 virtual void vfunc_14(float first,float last);
};
void MultiController::vfunc_14(float first,float last) {
 double scale = 1.0 / duration;
 float start = (float)(first * scale);
 double finish = last * scale;
 if (start == begin && finish == end) return;
 end = (float)finish;
 begin = start;
 if (!(current >= first && current <= last)) {
 current = current > last ? last : first;
 }
 for (unsigned i=0;i<count;++i) {
 float length=children[i]->vfunc_10();
 children[i]->vfunc_16(mode);
 children[i]->vfunc_14(length*begin,length*end);
 }
 result=vfunc_20();
 active = mode != 3 && mode != 5;
}
}
