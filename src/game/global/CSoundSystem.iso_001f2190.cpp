// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f0ab0..0x001f2db0 (kind game, layer game, confidence high), dominant class CSoundSystem
// (tree_prelude.h: not needed)


// 0x001f2190 Closure3<CSoundSystem,void,char_*,float,float>::vfunc_2 (28 B): equivalent/0x001f2190.cpp [isolated: conflict: SoundArgs; on include/gen/ and not mergeable]
// sym: ?vfunc_2@?$Closure3@VCSoundSystem@@XPADMM@@UAEXPAX00@Z @737c210bc5da @w4be225ef0d24
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CSoundSystem,void,char_*,float,float>::vfunc_2 @ 0x001f2190
#include "gen/global.h"

struct CSoundSystem_1f2190 {};
struct SoundArgs { char *name; float first; float second; };

template <> void Closure3<CSoundSystem, void, char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; SoundArgs * args = (SoundArgs *)__p1; void * unused2 = (void *)__p2;

    ((*(CSoundSystem_1f2190 * *)&this->f_20)->*(*(void (CSoundSystem_1f2190::**)(char *, float, float))&this->f_1c))(args->name, args->first, args->second);
}

