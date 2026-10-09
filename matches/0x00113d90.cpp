typedef unsigned int uint;
extern void* __cdecl operator_new(unsigned int);
class Condition { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); char pad[0x14]; };
class Base { public: void Init(int); };
class Factory { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual Condition* Create(); };
Condition* Factory::Create() { Condition* p=(Condition*)operator_new(0x18); if(p) { ((Base*)p)->Init(0); *(uint*)p=0x40d984; *(uint*)((char*)p+0xc)=0; *((char*)p+0x10)=0; *(uint*)((char*)p+0x14)=0; return p; } return 0; }