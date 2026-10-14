// STATUS: equivalent (tools/equiv.py level 3: 144 inputs, branch coverage 6/6)
// pure3d::MultiController::vfunc_23 @ 0x002b1df0
namespace pure3d {
struct MultiController {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual float vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(float,float); virtual void vfunc_15(); virtual void vfunc_16(int); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
char pad04[0x14];
float start, rate, speed, current, rangeStart, rangeEnd, frames, minimum;
int state38, state3c;
char pad40[4]; unsigned count; MultiController** children;
};
void MultiController::vfunc_23() {
 start=0.0f; rate=30.0f; speed=1.0f; current=0.0f; rangeStart=0.0f;
 double end=(frames-1.0)*0.033333333333333333f;
 if(end<0.0) end=0.0;
 rangeEnd=(float)end;
 minimum=3.402823466e38f; state38=0; state3c=0;
 for(unsigned i=0;i<count;++i) {
 children[i]->vfunc_23();
 double length=children[i]->vfunc_10();
 children[i]->vfunc_14((float)(length*rangeStart),(float)(length*rangeEnd));
 children[i]->vfunc_16(0);
 }
}
}