// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure6<CUnlockablesManager,void,int,const_char_*,const_char_*,const_char_*,const_char_*,int>::vfunc_2 @ 0x00094910
#include "gen/global.h"

class CUnlockablesManager_94910 { public: void FUN_00094910(int, const char*, const char*, const char*, const char*, int); }; 
struct CallArgs { int id; const char *a; const char *b; const char *c; const char *d; int value; };

template <> void Closure6<CUnlockablesManager, void, int, const char *, const char *, const char *, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { const CallArgs * args = (const CallArgs *)__p1;
 ((*(CUnlockablesManager_94910 * *)&this->f_20)->*(*(void (CUnlockablesManager_94910::**)(int, const char *, const char *, const char *, const char *, int))&this->f_1c))(args->id,args->a,args->b,args->c,args->d,args->value); }
