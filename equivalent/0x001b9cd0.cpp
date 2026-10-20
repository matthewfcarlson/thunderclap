// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CRenderManager,void,int,int,int>::vfunc_2 @ 0x001b9cd0
#include "gen/global.h"

struct CRenderManager_1b9cd0 { };
struct Function_1b9cd0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method3<CRenderManager, void, int, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CRenderManager_1b9cd0 * object = (CRenderManager_1b9cd0 *)__p0; const int * args = (const int *)__p1; void * unused = (void *)__p2;

    (object->*(*(void (CRenderManager_1b9cd0::**)(int, int, int))&this->f_1c))(args[0], args[1], args[2]);
}
