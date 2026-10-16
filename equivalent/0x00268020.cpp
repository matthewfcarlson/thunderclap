// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// core::TimerList::vfunc_5 @ 0x00268020
#include "gen/core.h"
#include "decls/data/engine/unknown.h"

namespace XAPILIB { int __stdcall QueryPerformanceCounter(__int64 *); }
unsigned int __cdecl FUN_00267e20(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
namespace core {

}
void core::TimerList::vfunc_5() {
 __int64 counter;
 XAPILIB::QueryPerformanceCounter(&counter);
 void **vtable = *(void ***)this;
 unsigned int result = FUN_00267e20((unsigned int)counter, (unsigned int)(counter >> 32), 1000, 0, (*(unsigned int*)&DAT_00528380), (*(unsigned int*)&DAT_00528384));
 void (__fastcall *callback)(core::TimerList *, void *, unsigned int) = (void (__fastcall *)(core::TimerList *, void *, unsigned int))vtable[4];
 callback(this, 0, result);
}
