// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CSoundVoiceManager,void,char_*,char_*,char_*,int>::vfunc_2 @ 0x001f5b40
#include "gen/global.h"

struct CSoundVoiceManager_1f5b40 { void callback(char*, char*, char*, int); };
struct VoiceArgs { char* first; char* second; char* third; int fourth; };

template <> void Closure4<CSoundVoiceManager, void, char *, char *, char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { VoiceArgs * arguments = (VoiceArgs *)__p1;

    ((*(CSoundVoiceManager_1f5b40 * *)&this->f_20)->*(*(void (CSoundVoiceManager_1f5b40::**)(char *, char *, char *, int))&this->f_1c))(arguments->first, arguments->second, arguments->third, arguments->fourth);
}
