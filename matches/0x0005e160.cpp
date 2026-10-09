struct CProceduralDurationAnimationTrack { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual CProceduralDurationAnimationTrack* vfunc_5(int); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); };
struct H { void f(); };
extern void __cdecl thunk_FUN_00267090(CProceduralDurationAnimationTrack*);
extern int vftable;
CProceduralDurationAnimationTrack* CProceduralDurationAnimationTrack::vfunc_5(int param) {
 *(int*)this=(int)&vftable;
 ((H*)((char*)this+0x38))->f();
 ((H*)((char*)this+0x18))->f();
 ((H*)this)->f();
 if(param&1) thunk_FUN_00267090(this);
 return this;
}