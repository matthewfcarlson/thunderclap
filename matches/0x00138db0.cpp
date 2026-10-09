class FlyingAttackTrack { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual int f10(int,int,int); };
extern int gTypeA, gTypeB;
extern int __cdecl TypeCheck(void*, int, const void*, const void*, int);
extern void* __cdecl Alloc(int);
struct Result { int Init(FlyingAttackTrack*, int); };
int FlyingAttackTrack::f10(int a, int b, int c) { if (TypeCheck((void*)c,0,&gTypeA,&gTypeB,0)) { Result* p=(Result*)Alloc(0x3c); if (p) return p->Init(this,c); } return 0; }