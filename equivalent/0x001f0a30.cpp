// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// CSoundCommand_InstallEffect::vfunc_1 @ 0x001f0a30
struct SoundSystem { void FUN_001ea560(unsigned int effect, unsigned int value); };
struct SoundGlobal { char pad[4]; SoundSystem* system; };
extern SoundGlobal* DAT_004e370c;
class CSoundCommand {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
class CSoundCommand_InstallEffect : public CSoundCommand {
public:
    char pad[12];
    unsigned int effect;
    unsigned int value;
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
void CSoundCommand_InstallEffect::vfunc_1(int, int) {
    DAT_004e370c->system->FUN_001ea560(effect, value);
}