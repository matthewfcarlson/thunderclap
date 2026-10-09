struct WallJumpTrack { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual unsigned int vfunc_10(unsigned int,unsigned int,unsigned int); };
extern int IsType(void *, int, const void *, const void *, int);
extern void *Alloc(int);
struct Result { unsigned int init(WallJumpTrack *, unsigned int); };
extern Result *MakeResult(void *);
extern const int RT1; extern const int RT2;
unsigned int WallJumpTrack::vfunc_10(unsigned int a, unsigned int b, unsigned int c) {
 if (IsType((void *)c,0,&RT1,&RT2,0)) { Result *r=(Result *)MakeResult((void *)0x50); if(r) return r->init(this,c); } return 0;
}