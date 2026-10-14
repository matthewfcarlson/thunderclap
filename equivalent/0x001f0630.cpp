// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001f0630 @ 0x001f0630
typedef unsigned __int64 Key;
extern Key __cdecl FUN_002672f0(const char*, int, int);
extern int __cdecl FUN_002673a0(const char*, int);

class CSoundCommand_PlayDialogueEvent {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(unsigned int, unsigned int);
    int f04;
    int f08;
    int f0c;
    unsigned int keyLo, keyHi;
    int id;
    char flag;
    char pad1d[3];

    CSoundCommand_PlayDialogueEvent(const char* name, const char* sub, float value, int arg);
};

CSoundCommand_PlayDialogueEvent::CSoundCommand_PlayDialogueEvent(const char* name, const char* sub, float value, int arg)
{
    f04 = 0;
    f08 = 0;
    f0c = arg;
    keyLo = 0;
    keyHi = 0;
    Key k = FUN_002672f0(name, 0, 0);
    keyHi = (unsigned int)(k >> 32);
    keyLo = (unsigned int)k;
    id = FUN_002673a0(sub, 0);
    flag = (value == 1.0f);
}
