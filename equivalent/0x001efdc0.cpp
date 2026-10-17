// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 4/4)
// FUN_001efdc0 @ 0x001efdc0
void* __cdecl FUN_0008d710(unsigned int, unsigned int);
struct CSoundCommand_ReturnToDefaultMix {
    virtual void command();
    int field4;
    int field8;
    int fieldC;
    int value;
};
struct SoundManager {
    void FUN_001ef260(CSoundCommand_ReturnToDefaultMix* command);
};
extern SoundManager* DAT_004e3710;
void __stdcall FUN_001efdc0(int value, int unused) {
    SoundManager* manager = DAT_004e3710;
    if (manager) {
        CSoundCommand_ReturnToDefaultMix* command = (CSoundCommand_ReturnToDefaultMix*)FUN_0008d710(20, 6);
        if (command) {
            CSoundCommand_ReturnToDefaultMix fresh;
            *(void**)command = *(void**)&fresh;
            command->field4 = 0;
            command->field8 = 0;
            command->fieldC = 0;
            command->value = value;
        }
        manager->FUN_001ef260(command);
    }
}