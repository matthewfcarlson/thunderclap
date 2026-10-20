// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method4<CSubtitleManager,void,int,float,const_char_*,float>::vfunc_2 @ 0x001bf550
#include "gen/global.h"

struct CSubtitleManager_1bf550 { void invoke(int, float, const char *, float); };
struct SubtitleArgs { int number; float start; const char *text; float end; };
struct Function_1bf550 { virtual void vfunc_0(); virtual void vfunc_1(); };

template <> void Method4<CSubtitleManager, void, int, float, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSubtitleManager_1bf550 * manager = (CSubtitleManager_1bf550 *)__p0; SubtitleArgs * arguments = (SubtitleArgs *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CSubtitleManager_1bf550::**)(int, float, const char *, float))&this->f_1c))(arguments->number, arguments->start, arguments->text, arguments->end);
}
