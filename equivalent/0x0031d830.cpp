// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::pddiBaseContext::vfunc_33 @ 0x0031d830
struct Matrix { float elements[16]; void FUN_0022b980(); };
struct Renderer { void FUN_00328270(unsigned a, unsigned b, unsigned c, float scale, unsigned d); };
struct State { char pad[0x24]; float values[4]; };
namespace pure3d {
struct pddiBaseContext {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(unsigned); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(unsigned); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(unsigned); virtual unsigned vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(unsigned,unsigned,unsigned,unsigned);
char pad04[0x44]; State* state; char pad4c[0xf8]; Renderer* renderer; char pad148; unsigned char active;
};
void pddiBaseContext::vfunc_33(unsigned a,unsigned b,unsigned c,unsigned d) {
active=1;
unsigned previous=vfunc_25();
State* savedState=state;
float saved[4];
saved[0]=savedState->values[0]; saved[1]=savedState->values[1]; saved[2]=savedState->values[2]; saved[3]=savedState->values[3];
savedState->values[0]=saved[0]*0.5f; savedState->values[1]=saved[0];
vfunc_24(2);
Matrix matrix; matrix.FUN_0022b980();
vfunc_21(0);
renderer->FUN_00328270(a,b,c,saved[0]*0.75f,d);
vfunc_16(0);
savedState->values[0]=saved[0]; savedState->values[1]=saved[1]; savedState->values[2]=saved[2]; savedState->values[3]=saved[3];
vfunc_24(previous);
active=0;
}
}
