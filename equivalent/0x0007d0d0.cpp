// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CAmbientsManager,void,const_char_*,int,bool>::vfunc_2 @ 0x0007d0d0
#include "gen/global.h"

class CAmbientsManager_7d0d0 {};
struct AmbientArgs { const char* name; int value; unsigned char enabled; };
class Function_7d0d0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method3<CAmbientsManager, void, const char *, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CAmbientsManager_7d0d0 * manager = (CAmbientsManager_7d0d0 *)__p0; AmbientArgs * args = (AmbientArgs *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CAmbientsManager_7d0d0::**)(const char *, int, int))&this->f_1c))(args->name, args->value, args->enabled);
}
