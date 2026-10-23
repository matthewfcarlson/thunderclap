// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CCameraManager,void,float,float,math::Vector,float>::vfunc_2 @ 0x0009a890
#include "gen/global.h"

struct Vector_9a890 { float x,y,z; };
struct Args { float first, second; Vector_9a890 direction; float last; };
struct CCameraManager_9a890 { int unused; };

template <> void Method4<CCameraManager, void, float, float,math::Vector, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CCameraManager_9a890 * manager = (CCameraManager_9a890 *)__p0; const Args * args = (const Args *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CCameraManager_9a890::**)(float, float, Vector_9a890, float))&this->f_1c))(args->first,args->second,args->direction,args->last);
}
