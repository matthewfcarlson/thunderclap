// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f01c0 @ 0x001f01c0
typedef unsigned __int64 U64;
U64 __cdecl FUN_002672f0(int, int, int);
int __cdecl FUN_002673a0(int, int);
struct CSoundCommand_PlayInterruptEvent {
    virtual void dummy();
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    CSoundCommand_PlayInterruptEvent(int a, int b, int c);
};
CSoundCommand_PlayInterruptEvent::CSoundCommand_PlayInterruptEvent(int a, int b, int c) {
    field4 = 0;
    field8 = 0;
    fieldC = c;
    field10 = 0;
    field14 = 0;
    U64 value = FUN_002672f0(a, 0, 0);
    field14 = (int)(value >> 32);
    field10 = (int)value;
    field18 = FUN_002673a0(b, 0);
}
