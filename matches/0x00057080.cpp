extern "C" void* __cdecl Allocate(unsigned int);
extern "C" int AxisVtable;
class CAxisSpeedCondition { public: virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3(); int a,b,c,d,e; void Initialize(int); };
class ConditionFactoryTemplate { public: CAxisSpeedCondition* vfunc_5(); };
CAxisSpeedCondition* ConditionFactoryTemplate::vfunc_5() {
 CAxisSpeedCondition* p=(CAxisSpeedCondition*)Allocate(0x18);
 if(p) { p->Initialize(0); p->c=0; *(int*)p=(int)&AxisVtable; p->d=4; p->e=0; return p; }
 return 0;
}