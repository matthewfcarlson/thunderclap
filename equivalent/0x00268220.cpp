// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::TimerList::vfunc_3 @ 0x00268220
#include "gen/core.h"

namespace core {
struct Timer_268220;
struct Source_268220 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
 virtual void vfunc_12(); virtual Timer_268220* vfunc_13();
};
struct Timer_268220 { unsigned FUN_00268070(core::TimerList* list, unsigned a, unsigned b, unsigned c, unsigned d, unsigned e); };

}
void core::TimerList::vfunc_3(int __p0, int __p1, int __p2, int __p3, int __p4, int __p5) { unsigned int * result = (unsigned int *)__p0; unsigned int a = (unsigned int)__p1; unsigned int b = (unsigned int)__p2; unsigned int c = (unsigned int)__p3; unsigned int d = (unsigned int)__p4; unsigned int e = (unsigned int)__p5;

 Timer_268220* timer = (*(Source_268220 * *)&this->f_18)->vfunc_13();
 if (timer) *result = timer->FUN_00268070(this, a, b, c, d, e);
 else *result = 0;
}
