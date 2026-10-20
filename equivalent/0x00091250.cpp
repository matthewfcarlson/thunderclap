// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CStatsManager,void,char_*,char_*,int>::vfunc_2 @ 0x00091250
#include "gen/global.h"

struct CStatsManager_91250 {
    void FUN_00091250(char *, char *, int);
};
struct Arguments { char *first; char *second; int third; };

template <> void Closure3<CStatsManager, void, char *, char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arguments * arguments = (Arguments *)__p1;

    ((*(CStatsManager_91250 * *)&this->f_20)->*(*(void (CStatsManager_91250::**)(char *, char *, int))&this->f_1c))(arguments->first, arguments->second, arguments->third);
}
