typedef unsigned __int64 U64;
U64 __cdecl FUN_002672f0(int, int, int);

class SoundCommandBase {
public:
    virtual void vfunc_0();
    int field4;
    int field8;
    int fieldC;
    SoundCommandBase(int c) : field4(0), field8(0), fieldC(c) {}
};

struct SoundId {
    U64 value;
    SoundId(int name) : value(0) { value = FUN_002672f0(name, 0, 0); }
};

class CSoundCommand_InstallEffect : public SoundCommandBase {
public:
    SoundId effect;
    CSoundCommand_InstallEffect(int name, int unused);
    virtual void vfunc_0();
};

CSoundCommand_InstallEffect::CSoundCommand_InstallEffect(int name, int unused)
    : SoundCommandBase(0), effect(name)
{
}
