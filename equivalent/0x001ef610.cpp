// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CSoundCommand_PlaySFXEvent::vfunc_1 @ 0x001ef610
struct SoundLookup { void* manager; void* events; };
extern SoundLookup* DAT_004e370c;
struct EventManager { int FUN_001e98b0(void*); };
struct SoundManager { int FUN_001f31a0(int); void FUN_001f3af0(int, void*, int); };
struct CSoundCommand { virtual void vfunc_0(); virtual void vfunc_1(int, int); };
struct CSoundCommand_PlaySFXEvent : CSoundCommand {
    char padding[12];
    int event;
    int field14;
    int field18;
    void vfunc_1(int argument, int unused);
};
void CSoundCommand_PlaySFXEvent::vfunc_1(int argument, int unused) {
    int eventId = ((EventManager*)DAT_004e370c->events)->FUN_001e98b0(&event);
    int soundId = ((SoundManager*)DAT_004e370c->manager)->FUN_001f31a0(argument);
    if (eventId && soundId)
        ((SoundManager*)DAT_004e370c->manager)->FUN_001f3af0(eventId, &field18, soundId);
}