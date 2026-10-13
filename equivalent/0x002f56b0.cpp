// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// physics::PhysicsObject::vfunc_6 @ 0x002f56b0
struct Vec { float x,y,z; };
struct Matrix { unsigned int words[16]; void FUN_0022c1b0(); void FUN_0022b9f0(); void FUN_0022c2b0(Vec*,Vec*); };
struct Bounds { char data[44]; void FUN_0022b370(Matrix*); };
struct Filter { void FUN_002fd020(Vec*,Vec*); };
struct Body {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 char pad[12]; Matrix transform; char pad50[12]; Vec velocity; unsigned int scaleBits;
};
namespace physics {
struct PhysicsObject {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(unsigned char reset);
 virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(unsigned int); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
 char pad04[12]; Body* body; char pad14[44]; unsigned int value40; char pad44[20]; Matrix inverse; Vec position; unsigned char useTranslation; char padA5[3]; Vec offset; Vec adjustment; Vec velocity; Bounds bounds; Filter filter;
};
void PhysicsObject::vfunc_6(unsigned char reset) {
 Body* source=body;
 for(int i=0;i<16;++i) inverse.words[i]=source->transform.words[i];
 if(source->scaleBits!=0x3f800000) inverse.FUN_0022c1b0();
 inverse.FUN_0022b9f0();
 vfunc_39();
 bounds.FUN_0022b370(&inverse);
 if(useTranslation) {
 position = *reinterpret_cast<Vec*>(&body->transform.words[12]);
 } else {
 Vec sum;
 sum.x=offset.x+adjustment.x;
 sum.y=offset.y+adjustment.y;
 sum.z=offset.z+adjustment.z;
 body->transform.FUN_0022c2b0(&sum,&position);
 }
 if(reset) {
 vfunc_37();
 velocity.z=0.0f; velocity.y=0.0f; velocity.x=0.0f;
 body->s7();
 } else filter.FUN_002fd020(&body->velocity,&velocity);
 vfunc_35(value40);
}
}