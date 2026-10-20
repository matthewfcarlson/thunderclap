// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CSPManager,void,const_char_*,bool,float>::vfunc_2 @ 0x001e1c60
#include "compat/ptr.h"
#include "gen/global.h"

struct CSPManager_1e1c60 { void invoke(const char*, bool, float); };
struct Arguments { const char* text; bool flag; char pad[3]; float value; };
typedef void (CSPManager_1e1c60::*Callback)(const char*, bool, float);

template <> void Closure3<CSPManager, void, const char *, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; Arguments * args = (Arguments *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

    ((*(CSPManager_1e1c60 * *)&this->f_20)->*(*(Callback *)&this->f_1c))(args->text, args->flag, args->value);
}
