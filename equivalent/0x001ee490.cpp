// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CSoundSimManager,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x001ee490
#include "gen/global.h"

struct CSoundSimManager_1ee490 { void callback(const char *, const char *, const char *, const char *); };

template <> void Closure4<CSoundSimManager, void, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** args = (const char **)__p1; void * unused2 = (void *)__p2;
 ((*(CSoundSimManager_1ee490 * *)&this->f_20)->*(*(void (CSoundSimManager_1ee490::**)(const char *, const char *, const char *, const char *))&this->f_1c))(args[0], args[1], args[2], args[3]); }
