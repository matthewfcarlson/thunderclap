// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f08f0 @ 0x001f08f0
unsigned __int64 __cdecl FUN_002672f0(int, int, int);
int __cdecl FUN_002673a0(int, int);

class CSoundCommand_PlaySFXEvent {
public:
    virtual void unused();
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    CSoundCommand_PlaySFXEvent(int first, int second, int third);
};

CSoundCommand_PlaySFXEvent::CSoundCommand_PlaySFXEvent(int first, int second, int third) {
    field04 = 0;
    field08 = 0;
    field0c = third;
    field10 = 0;
    field14 = 0;
    unsigned __int64 result = FUN_002672f0(first, 0, 0);
    field14 = (int)(result >> 32);
    field10 = (int)result;
    field18 = FUN_002673a0(second, 0);
}