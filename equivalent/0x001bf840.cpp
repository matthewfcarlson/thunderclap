// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSubtitleManager,void,const_char_*,const_char_*,float>::vfunc_2 @ 0x001bf840
#include "gen/global.h"

struct CSubtitleManager_1bf840 { };
struct Arguments { const char *first; const char *second; float third; };

template <> void Method3<CSubtitleManager, void, const char *, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSubtitleManager_1bf840 * manager = (CSubtitleManager_1bf840 *)__p0; Arguments * args = (Arguments *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CSubtitleManager_1bf840::**)(const char *, const char *, float))&this->f_1c))(args->first, args->second, args->third);
}
