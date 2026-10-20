// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure6<CActorManager,bool,const_char_*,const_char_*,const_char_*,const_char_*,bool,const_char_*>::vfunc_2 @ 0x0002eb10
#include "compat/ptr.h"
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
