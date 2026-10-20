// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure6<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x00094880
#include "gen/global.h"

struct CUnlockablesManager_94880 {
    void FUN_00094880(const char *, int, const char *, const char *, const char *, const char *);
};
struct Arguments {
    const char *name;
    int number;
    const char *text1;
    const char *text2;
    const char *text3;
    const char *text4;
};

template <> void Closure6<CUnlockablesManager, void, const char *, int, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arguments * args = (Arguments *)__p1;

    ((*(CUnlockablesManager_94880 * *)&this->f_20)->*(*(void (CUnlockablesManager_94880::**)(const char *, int, const char *, const char *, const char *, const char *))&this->f_1c))(args->name, args->number, args->text1, args->text2, args->text3, args->text4);
}
