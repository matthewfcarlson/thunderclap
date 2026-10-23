// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method1<CSPManager,math::Vector,const_char_*>::vfunc_2 @ 0x001e0230
#include "gen/global.h"

struct Vector_1e0230 { float x,y,z; };
struct CSPManager_1e0230 {};
struct Function_1e0230 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };

template <> void Method1<CSPManager,math::Vector, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0230 * manager = (CSPManager_1e0230 *)__p0; const char ** name = (const char **)__p1; Vector_1e0230 * output = (Vector_1e0230 *)__p2;

 Vector_1e0230 value = (manager->*(*(Vector_1e0230 (CSPManager_1e0230::**)(const char *))&this->f_1c))(*name);
 if (output) *output = value;
}
