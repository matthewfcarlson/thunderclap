// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSoundVoiceManager,void,bool,bool,bool>::vfunc_2 @ 0x001f5a50
#include "gen/global.h"

struct CSoundVoiceManager_1f5a50 { void FUN_001f5a50(unsigned, unsigned, unsigned); };
struct Args { unsigned char first; char pad0[3]; unsigned char second; char pad1[3]; unsigned char third; };
struct Function_1f5a50 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(int, Args *, int); };

template <> void Closure3<CSoundVoiceManager, void, bool, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused = (int)__p0; Args * args = (Args *)__p1; int unused2 = (int)__p2;

 ((*(CSoundVoiceManager_1f5a50 * *)&this->f_20)->*(*(void (CSoundVoiceManager_1f5a50::**)(unsigned int, unsigned int, unsigned int))&this->f_1c))((reinterpret_cast<unsigned>(args) & ~255u) | args->first,args->second,args->third);
}
