// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001f0760 @ 0x001f0760
#include "decls/address.h"
typedef unsigned __int64 Key_1f0760;
extern int __cdecl FUN_002673a0(const char*, int);

class CSoundCommand_PlayMissionDialogueEvent {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(unsigned int, unsigned int);
    int f04;
    int f08;
    int f0c;
    unsigned int keyLo, keyHi;
    int id;
    int f1c;
    char text[0x20];
    char flag;
    char pad41[3];

    CSoundCommand_PlayMissionDialogueEvent(const char* name, const char* sub, const char* line, int arg1, float value, int arg2);
};

CSoundCommand_PlayMissionDialogueEvent::CSoundCommand_PlayMissionDialogueEvent(const char* name, const char* sub, const char* line, int arg1, float value, int arg2)
{
    f04 = 0;
    f08 = 0;
    f0c = arg2;
    keyLo = 0;
    keyHi = 0;
    Key_1f0760 k = FUN_002672f0(name, 0, 0);
    keyHi = (unsigned int)(k >> 32);
    keyLo = (unsigned int)k;
    id = FUN_002673a0(sub, 0);
    f1c = arg1;
    char *dst = text;
    char c;
    do {
        c = *line++;
        *dst++ = c;
    } while (c != 0);
    flag = (value == 1.0f);
}
