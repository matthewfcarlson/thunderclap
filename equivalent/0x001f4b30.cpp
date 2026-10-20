// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CSoundVoiceManager,void,char_*,char_*,char_*,int>::vfunc_2 @ 0x001f4b30
#include "gen/global.h"

struct CSoundVoiceManager_1f4b30 {};
struct Function_1f4b30 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method4<CSoundVoiceManager, void, char *, char *, char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundVoiceManager_1f4b30 * object = (CSoundVoiceManager_1f4b30 *)__p0; void ** arguments = (void **)__p1; void * unused = (void *)__p2;

    (object->*(*(void (CSoundVoiceManager_1f4b30::**)(char *, char *, char *, int))&this->f_1c))((char *)arguments[0], (char *)arguments[1], (char *)arguments[2], (int)arguments[3]);
}
