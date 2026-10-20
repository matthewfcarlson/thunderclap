// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CCameraManager,void,char_*,char_*,char_*,char_*>::vfunc_2 @ 0x0009d040
#include "gen/global.h"

class CCameraManager_9d040 {
public:
    void method(char *, char *, char *, char *);
};

template <> void Closure4<CCameraManager, void, char *, char *, char *, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { char ** args = (char **)__p1;

    ((*(CCameraManager_9d040 * *)&this->f_20)->*(*(void (CCameraManager_9d040::**)(char *, char *, char *, char *))&this->f_1c))(args[0], args[1], args[2], args[3]);
}
