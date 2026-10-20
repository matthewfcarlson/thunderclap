// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CActorManager,void,const_char_*,float,bool>::vfunc_2 @ 0x0002c890
#include "gen/global.h"

struct CActorManager_2c890 { void FUN_0002c890(const char *, float, bool); };
struct CallArguments { const char *text; float value; bool enabled; };

template <> void Method3<CActorManager, void, const char *, float, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2c890 * actor = (CActorManager_2c890 *)__p0; const CallArguments * arguments = (const CallArguments *)__p1; int unused = (int)__p2;

 (actor->*(*(void (CActorManager_2c890::**)(const char *, float, bool))&this->f_1c))(arguments->text, arguments->value, arguments->enabled);
}
