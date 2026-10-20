// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSoundRealTimeManager,void,char_*,char_*,char_*>::vfunc_2 @ 0x001edd70
#include "gen/global.h"

struct CSoundRealTimeManager_1edd70 { void placeholder(char *, char *, char *); };
struct Args { char *first; char *second; char *third; };
struct Function_1edd70 { virtual void vfunc_0(); virtual void vfunc_1(); };

template <> void Method3<CSoundRealTimeManager, void, char *, char *, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundRealTimeManager_1edd70 * manager = (CSoundRealTimeManager_1edd70 *)__p0; Args * args = (Args *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CSoundRealTimeManager_1edd70::**)(char *, char *, char *))&this->f_1c))(args->first, args->second, args->third);
}
