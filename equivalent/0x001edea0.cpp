// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CSoundSimManager,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x001edea0
#include "gen/global.h"

class CSoundSimManager_1edea0 { public: void placeholder(); };

template <> void Method4<CSoundSimManager, void, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundSimManager_1edea0 * manager = (CSoundSimManager_1edea0 *)__p0; const char ** arguments = (const char **)__p1; void * unused = (void *)__p2;

 (manager->*(*(void (CSoundSimManager_1edea0::**)(const char *, const char *, const char *, const char *))&this->f_1c))(arguments[0], arguments[1], arguments[2], arguments[3]);
}
