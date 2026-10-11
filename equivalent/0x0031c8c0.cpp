// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::pddiRenderState::vfunc_0 @ 0x0031c8c0
struct Context {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
 virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
 virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43(); virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47(); virtual void slot48(); virtual void slot49();
 virtual void slot50(); virtual void slot51(); virtual void slot52(); virtual void slot53();
 virtual void set54(unsigned int); virtual void slot55();
 virtual void set56(unsigned int,unsigned int,unsigned int,unsigned int); virtual void slot57();
 virtual void set58(unsigned int); virtual void slot59();
 virtual void set60(unsigned int); virtual void slot61();
 virtual void set62(unsigned int); virtual void slot63();
 virtual void slot64(); virtual void slot65(); virtual void slot66(); virtual void slot67(); virtual void slot68(); virtual void slot69(); virtual void slot70(); virtual void slot71(); virtual void slot72(); virtual void slot73(); virtual void slot74(); virtual void slot75();
 virtual void set76(unsigned int);
};
namespace pure3d {
struct pddiState { virtual void vfunc_0(Context*); };
struct pddiRenderState : pddiState {
 unsigned int mode;
 unsigned char flag8; char padding9[3];
 unsigned int modeC;
 unsigned char flag10; char padding11[3];
 unsigned int mode14;
 unsigned char red,green,blue,alpha;
 virtual void vfunc_0(Context*);
};
void pddiRenderState::vfunc_0(Context* context) {
 context->set54(mode);
 context->set56(red,green,blue,alpha);
 context->set58(flag8);
 context->set60(modeC);
 context->set62(flag10);
 context->set76(mode14);
}
}
