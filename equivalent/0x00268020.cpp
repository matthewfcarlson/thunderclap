// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// core::TimerList::vfunc_5 @ 0x00268020
namespace XAPILIB { int __stdcall QueryPerformanceCounter(__int64 *); }
extern unsigned int DAT_00528380;
extern unsigned int DAT_00528384;
unsigned int __cdecl FUN_00267e20(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
namespace core {
struct TimerList {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4(unsigned int);
 virtual void vfunc_5();
};
void TimerList::vfunc_5() {
 __int64 counter;
 XAPILIB::QueryPerformanceCounter(&counter);
 void **vtable = *(void ***)this;
 unsigned int result = FUN_00267e20((unsigned int)counter, (unsigned int)(counter >> 32), 1000, 0, DAT_00528380, DAT_00528384);
 void (__fastcall *callback)(TimerList *, void *, unsigned int) = (void (__fastcall *)(TimerList *, void *, unsigned int))vtable[4];
 callback(this, 0, result);
}
}