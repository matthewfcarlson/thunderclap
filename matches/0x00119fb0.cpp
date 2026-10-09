typedef unsigned int u32;
extern int TypeA, TypeB;
struct MotionBoostTrack { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual int vfunc_10(u32 a,u32 b,void* p); };
struct Params { int Init(MotionBoostTrack*,void*); };
extern int IsKindOf(void*,int,int*,int*,int);
extern void* Alloc(unsigned int);
int MotionBoostTrack::vfunc_10(u32 a,u32 b,void* p) { if (IsKindOf(p,0,&TypeA,&TypeB,0)) { Params* q=(Params*)Alloc(0x34); if(q) return q->Init(this,p); } return 0; }