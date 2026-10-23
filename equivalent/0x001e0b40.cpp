// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSPManager,void,int,int,const_char_*>::vfunc_2 @ 0x001e0b40
#include "gen/global.h"

struct CSPManager_1e0b40 { void FUN_001e0b40(int, int, const char *); };
struct Function_1e0b40 { virtual void vfunc_0(); virtual void vfunc_1(); };

template <> void Method3<CSPManager, void, int, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0b40 * object = (CSPManager_1e0b40 *)__p0; const int * args = (const int *)__p1; void * unused = (void *)__p2;

    (object->*(*(void (CSPManager_1e0b40::**)(int, int, const char *))&this->f_1c))(args[0], args[1], (const char *)args[2]);
}
