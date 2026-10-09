typedef unsigned int u32; typedef unsigned char u8;
extern void* Alloc(unsigned int);
class InitBase { public: void Init(int); };
struct TargetDistanceYCondition : InitBase { u32 vptr; u32 pad1; u32 pad2; int a; int b; u8 c,d,e; };
class ConditionFactoryTemplate { public: virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3(); virtual void q4(); virtual TargetDistanceYCondition* vfunc_5(); };
TargetDistanceYCondition* ConditionFactoryTemplate::vfunc_5() {
  TargetDistanceYCondition* p = (TargetDistanceYCondition*)Alloc(0x18);
  if (p != 0) {
    p->Init(0);
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->vptr = 0x40fdd4;
    return p;
  }
  return 0;
}