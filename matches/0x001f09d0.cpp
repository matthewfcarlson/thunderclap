typedef unsigned __int64 U64;
U64 __cdecl FUN_002672f0(int, int, int);

class CSoundCommand_1f09d0 {
public:
    virtual void vfunc_0();
    int field4;
    int field8;
    int fieldC;
    CSoundCommand_1f09d0(int c) : field4(0), field8(0), fieldC(c) {}
};

struct SoundId {
    U64 value;
    SoundId(int name) : value(0) { value = FUN_002672f0(name, 0, 0); }
};

class CSoundCommand_InstallEffect : public CSoundCommand_1f09d0 {
public:
    SoundId effect;
    CSoundCommand_InstallEffect(int name, int unused);
    virtual void vfunc_0();
};

CSoundCommand_InstallEffect::CSoundCommand_InstallEffect(int name, int unused)
    : CSoundCommand_1f09d0(0), effect(name)
{
}
