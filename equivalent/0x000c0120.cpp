// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure7<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x000c0120
#include "gen/global.h"

struct CFEManager_c0120 { char unused; };
struct Args { const char* values[7]; };

template <> void Closure7<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { Args * args = (Args *)__p1;

    ((*(CFEManager_c0120 * *)&this->f_20)->*(*(void (CFEManager_c0120::**)(const char *, const char *, const char *, const char *, const char *, const char *, const char *))&this->f_1c))(args->values[0], args->values[1], args->values[2], args->values[3], args->values[4], args->values[5], args->values[6]);
}
