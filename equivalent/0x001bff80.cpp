// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CSubtitleManager,void,int,float,const_char_*,float>::vfunc_2 @ 0x001bff80
#include "gen/global.h"

struct CSubtitleManager_1bff80 { void FUN_001bff80(int, float, const char *, float); };
struct Arguments { int number; float time; const char *text; float duration; };

template <> void Closure4<CSubtitleManager, void, int, float, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused = (int)__p0; Arguments * arguments = (Arguments *)__p1; int other = (int)__p2;

    float time = arguments->time;
    ((*(CSubtitleManager_1bff80 * *)&this->f_20)->*(*(void (CSubtitleManager_1bff80::**)(int, float, const char *, float))&this->f_1c))(arguments->number, time, arguments->text, arguments->duration);
}
