// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CCameraManager,void,bool,bool,bool,bool>::vfunc_2 @ 0x0009ad00
#include "gen/global.h"

struct CCameraManager_9ad00 { void FUN_0009ad00(unsigned, unsigned, unsigned, unsigned); };
struct Function_9ad00 { virtual void vfunc_0(); virtual void vfunc_1(); };

template <> void Method4<CCameraManager, void, bool, bool, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CCameraManager_9ad00 * manager = (CCameraManager_9ad00 *)__p0; const unsigned char * args = (const unsigned char *)__p1;

    (manager->*(*(void (CCameraManager_9ad00::**)(unsigned int, unsigned int, unsigned int, unsigned int))&this->f_1c))(((unsigned)this & 0xffffff00u) | args[0],
                         ((unsigned)args & 0xffffff00u) | args[4],
                         args[8], args[12]);
}
