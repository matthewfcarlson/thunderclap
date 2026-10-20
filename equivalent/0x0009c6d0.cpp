// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CCameraManager,void,bool,bool,bool,bool>::vfunc_2 @ 0x0009c6d0
#include "gen/global.h"

struct CCameraManager_9c6d0 { void FUN_0009c6d0_placeholder(unsigned, unsigned, unsigned, unsigned); };
struct BoolArguments { unsigned char first; char pad0[3]; unsigned char second; char pad1[3]; unsigned char third; char pad2[3]; unsigned char fourth; };

template <> void Closure4<CCameraManager, void, bool, bool, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; BoolArguments * args = (BoolArguments *)__p1; void * other = (void *)__p2;

  unsigned first = ((unsigned)this & 0xffffff00U) | args->first;
  unsigned second = ((unsigned)args & 0xffffff00U) | args->second;
  ((*(CCameraManager_9c6d0 * *)&this->f_20)->*(*(void (CCameraManager_9c6d0::**)(unsigned int, unsigned int, unsigned int, unsigned int))&this->f_1c))(first, second, args->third, args->fourth);
}
