// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSoundSystem,void,char_*,char_*,float>::vfunc_2 @ 0x001f0b70
#include "gen/global.h"

struct CSoundSystem_1f0b70 {};
struct CallArgs { char* first; char* second; float third; };

template <> void Method3<CSoundSystem, void, char *, char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundSystem_1f0b70 * object = (CSoundSystem_1f0b70 *)__p0; CallArgs * args = (CallArgs *)__p1; void * unused = (void *)__p2;

    (object->*(*(void (CSoundSystem_1f0b70::**)(char *, char *, float))&this->f_1c))(args->first, args->second, args->third);
}
