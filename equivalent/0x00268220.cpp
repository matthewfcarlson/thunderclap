// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::TimerList::vfunc_3 @ 0x00268220
namespace core {
struct Timer;
struct Source_268220 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
 virtual void vfunc_12(); virtual Timer* vfunc_13();
};
struct TimerList {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
 virtual void vfunc_3(unsigned* result, unsigned a, unsigned b, unsigned c, unsigned d, unsigned e);
 virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x18 - 4]; Source_268220* source;
};
struct Timer { unsigned FUN_00268070(TimerList* list, unsigned a, unsigned b, unsigned c, unsigned d, unsigned e); };
void TimerList::vfunc_3(unsigned* result, unsigned a, unsigned b, unsigned c, unsigned d, unsigned e) {
 Timer* timer = source->vfunc_13();
 if (timer) *result = timer->FUN_00268070(this, a, b, c, d, e);
 else *result = 0;
}
}