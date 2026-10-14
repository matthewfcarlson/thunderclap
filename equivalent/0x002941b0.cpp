// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002941b0 @ 0x002941b0
struct Vec { float x,y,z; };
struct Source {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual void getFactors(float*,float*);
};
struct Screen {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual int height(); virtual int width();
};
extern Screen* DAT_0052c2a4;
struct Object {
 char pad[8]; float left,top,right,bottom; Source* source;
 void target(Vec* input, Vec* output);
};
void Object::target(Vec* input, Vec* output) {
 if (!source) return;
 union { Vec* pointer; float value; } factor;
 factor.pointer=output;
 float unused;
 output->z=0.0f;
 source->getFactors(&unused,&factor.value);
 output->x=(right-left)*(input->x+0.5f)+(left-0.5f);
 output->y=(factor.value*input->y-0.5f)*(bottom-top)+(0.5f-top);
 int width=DAT_0052c2a4->width();
 output->x=(output->x+0.5f)*width;
 int height=DAT_0052c2a4->height();
 output->y=(1.0f-(output->y+0.5f))*height;
}
