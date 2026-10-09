void* __cdecl Allocate(unsigned int);
struct CCollisionPushbackYCondition { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); int pad0; int pad1; int a; int b; };
struct Initializer { void init(int); };
struct Factory { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual CCollisionPushbackYCondition* vfunc_5(); };
CCollisionPushbackYCondition* Factory::vfunc_5() {
 CCollisionPushbackYCondition* p=(CCollisionPushbackYCondition*)Allocate(0x14);
 if(p) { ((Initializer*)p)->init(0); *(unsigned int*)p=0x3f70a0; p->a=3; p->b=0; }
 else return (CCollisionPushbackYCondition*)0;
 return p;
}