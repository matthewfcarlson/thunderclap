// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CSoundCommand_PlayInterruptEvent::vfunc_1 @ 0x001ef470
struct SoundHandle {
    void FUN_001f3370(void *params);
};

struct SoundBank_1ef470 {
    void FUN_001f47b0(int arg);
    SoundHandle *FUN_001f2f30(void *event, int arg);
};

struct EventTable {
    void *FUN_001e98b0(void *key);
};

struct SoundSystem_1ef470 {
    SoundBank_1ef470 *bank;
    EventTable *events;
};

extern SoundSystem_1ef470 *DAT_004e370c;
extern int DAT_004e371c;
extern int DAT_004e3720;
extern int DAT_004e3724;

class CSoundCommand_PlayInterruptEvent {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(int arg, int unused);

    char pad4[0xc];
    char key[8];      // +0x10
    char params[8];   // +0x18
};

void CSoundCommand_PlayInterruptEvent::vfunc_1(int arg, int unused) {
    DAT_004e371c++;
    DAT_004e370c->bank->FUN_001f47b0(arg);
    void *event = DAT_004e370c->events->FUN_001e98b0(key);
    if (event == 0) {
        DAT_004e3720++;
        return;
    }
    SoundHandle *handle = DAT_004e370c->bank->FUN_001f2f30(event, arg);
    if (handle != 0) {
        handle->FUN_001f3370(params);
        return;
    }
    DAT_004e3724++;
}
