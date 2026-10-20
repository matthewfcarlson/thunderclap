// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CTriggerVolumeManager,void,const_char_*,int,bool>::vfunc_2 @ 0x002003b0
#include "gen/global.h"

struct CTriggerVolumeManager_2003b0 {};
struct Arguments { const char* name; int value; unsigned char flag; };

template <> void Closure3<CTriggerVolumeManager, void, const char *, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * args = (Arguments *)__p1; void * unused2 = (void *)__p2;

    ((*(CTriggerVolumeManager_2003b0 * *)&this->f_20)->*(*(void (CTriggerVolumeManager_2003b0::**)(const char *, int, unsigned int))&this->f_1c))(args->name, args->value, args->flag);
}
