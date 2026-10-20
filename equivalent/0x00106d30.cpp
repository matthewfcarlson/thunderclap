// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure3<CPatrolPathManager,bool,const_char_*,int,math::Vector>::vfunc_2 @ 0x00106d30
#include "gen/global.h"

struct Vector_106d30 { float x,y,z; };
struct CPatrolPathManager_106d30 { bool invoke(const char*, int, Vector_106d30); };
struct Arguments { const char* name; int index; Vector_106d30 position; };

template <> void Closure3<CPatrolPathManager, bool, const char *, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const Arguments * arguments = (const Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CPatrolPathManager_106d30 * *)&this->f_20)->*(*(bool (CPatrolPathManager_106d30::**)(const char *, int, Vector_106d30))&this->f_1c))(arguments->name, arguments->index, arguments->position);
    if (result) *result = value;
}
