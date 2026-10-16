// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001f06c0 @ 0x001f06c0
#include "decls/address.h"
typedef unsigned __int64 Key_1f06c0;
extern int __cdecl FUN_002673a0(const char*, int);

class CSoundCommand_PlayFightDialogueEvent {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(unsigned int, unsigned int);
    int f04;
    int f08;
    int f0c;
    unsigned int keyLo, keyHi;
    int id;
    int f1c;
    char flag;
    char pad21[3];

    CSoundCommand_PlayFightDialogueEvent(const char* name, const char* sub, int extra, float value, int arg);
};

CSoundCommand_PlayFightDialogueEvent::CSoundCommand_PlayFightDialogueEvent(const char* name, const char* sub, int extra, float value, int arg)
{
    f04 = 0;
    f08 = 0;
    f0c = arg;
    keyLo = 0;
    keyHi = 0;
    Key_1f06c0 k = FUN_002672f0(name, 0, 0);
    keyHi = (unsigned int)(k >> 32);
    keyLo = (unsigned int)k;
    id = FUN_002673a0(sub, 0);
    f1c = extra;
    flag = (value == 1.0f);
}
