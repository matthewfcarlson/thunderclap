// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// pure3d::pddiLightingState::vfunc_0 @ 0x0031c9b0
namespace pure3d {
struct Context {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
 virtual void lighting(unsigned); virtual void s36(); virtual void s37(); virtual void enable(int,unsigned); virtual void s39(); virtual void type(int,unsigned); virtual void s41(); virtual void color(int,unsigned); virtual void s43(); virtual void position(int,void*); virtual void s45(); virtual void direction(int,void*); virtual void s47(); virtual void range(int,unsigned); virtual void s49(); virtual void attenuation(int,unsigned,unsigned,unsigned); virtual void s51(); virtual void cone(int,unsigned,unsigned,unsigned);
};
struct Light {
 char position[32]; char direction[52]; unsigned range; unsigned attenuation0,attenuation1,attenuation2; unsigned cone0,cone1,cone2; unsigned type,color; unsigned char enabled; char padding[3];
};
struct pddiLightingState {
 virtual void vfunc_0(Context*);
 Light lights[8]; unsigned lighting;
};
void pddiLightingState::vfunc_0(Context* context) {
 context->lighting(lighting);
 for(int i=0;i<8;++i) {
  context->enable(i,lights[i].enabled);
  context->type(i,lights[i].type);
  context->color(i,lights[i].color);
  context->direction(i,lights[i].direction);
  context->position(i,lights[i].position);
  context->range(i,lights[i].range);
  context->attenuation(i,lights[i].attenuation0,lights[i].attenuation1,lights[i].attenuation2);
  context->cone(i,lights[i].cone0,lights[i].cone1,lights[i].cone2);
 }
}
}