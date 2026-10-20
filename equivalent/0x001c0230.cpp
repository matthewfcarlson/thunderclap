// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CSubtitleManager,void,const_char_*,const_char_*,float>::vfunc_2 @ 0x001c0230
#include "gen/global.h"

struct CSubtitleManager_1c0230 { void placeholder(); };
struct SubtitleArgs { const char* first; const char* second; float time; };

template <> void Closure3<CSubtitleManager, void, const char *, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const SubtitleArgs * args = (const SubtitleArgs *)__p1; void * unused2 = (void *)__p2;

    ((*(CSubtitleManager_1c0230 * *)&this->f_20)->*(*(void (CSubtitleManager_1c0230::**)(const char *, const char *, float))&this->f_1c))(args->first, args->second, args->time);
}
