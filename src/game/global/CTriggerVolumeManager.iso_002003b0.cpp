// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001fc690..0x00201740 (kind game, layer game, confidence high), dominant class CTriggerVolumeManager
// (tree_prelude.h: not needed)


// 0x002003b0 Closure3<CTriggerVolumeManager,void,const_char_*,int,bool>::vfunc_2 (30 B): equivalent/0x002003b0.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@?$Closure3@VCTriggerVolumeManager@@XPBDH_N@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CTriggerVolumeManager,void,const_char_*,int,bool>::vfunc_2 @ 0x002003b0
#include "gen/global.h"

struct CTriggerVolumeManager_2003b0 {};
struct Arguments { const char* name; int value; unsigned char flag; };

template <> void Closure3<CTriggerVolumeManager, void, const char *, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * args = (Arguments *)__p1; void * unused2 = (void *)__p2;

    ((*(CTriggerVolumeManager_2003b0 * *)&this->f_20)->*(*(void (CTriggerVolumeManager_2003b0::**)(const char *, int, unsigned int))&this->f_1c))(args->name, args->value, args->flag);
}

