typedef unsigned char u8;
extern void thunk_FUN_00267090(void*);
extern void* timerVftable;
extern void* refVftable;
class Timer { public: virtual void f0(); virtual void f1(); virtual Timer* vfunc_2(int); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void vfunc_10(); virtual void f11(); virtual void f12(); virtual void f13(); char pad[12]; u8 active; };
Timer* Timer::vfunc_2(int flag) {
 *(void**)this = &timerVftable;
 if (active) Timer::vfunc_10();
 *(void**)this = &refVftable;
 if (flag & 1) thunk_FUN_00267090(this);
 return this;
}