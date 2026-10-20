// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSPManager,void,float,float,float>::vfunc_2 @ 0x001e0be0
#include "gen/global.h"

struct CSPManager_1e0be0 {};
struct Triple { float x, y, z; };
struct Function_1e0be0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method3<CSPManager, void, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0be0 * manager = (CSPManager_1e0be0 *)__p0; Triple * values = (Triple *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CSPManager_1e0be0::**)(float, float, float))&this->f_1c))(values->x, values->y, values->z);
}
