// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0002c4f0..0x00034400 (kind game, layer game, confidence high), dominant class CActorManager
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0002eb10 Closure6<CActorManager,bool,const_char_*,const_char_*,const_char_*,const_char_*,bool,const_char_*>::vfunc_2 (87 B): equivalent/0x0002eb10.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@?$Closure6@VCActorManager@@_NPBDPBDPBDPBD_NPBD@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure6<CActorManager,bool,const_char_*,const_char_*,const_char_*,const_char_*,bool,const_char_*>::vfunc_2 @ 0x0002eb10
#include "gen/global.h"

struct CActorManager_2eb10 {
    bool FUN_0002eb10(bool, const char*, const char*, const char*, const char*, bool, const char*);
};

struct Arguments {
    const char* first;
    const char* second;
    const char* third;
    const char* fourth;
    bool fifth;
    char padding[3];
    const char* sixth;
};

template <> void Closure6<CActorManager, bool, const char *, const char *, const char *, const char *, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; const Arguments * arguments = (const Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CActorManager_2eb10 * *)&this->f_20)->*(*(bool (CActorManager_2eb10::**)(const char *, const char *, const char *, const char *, bool, const char *))&this->f_1c))(arguments->first, arguments->second, arguments->third, arguments->fourth, arguments->fifth, arguments->sixth);
    if (result) *result = value;
}

