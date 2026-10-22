typedef unsigned __int64 U64;
U64 __cdecl FUN_002672f0(int, int, int);
int __cdecl FUN_002673a0(int, int);

class CSoundCommand_1f0230 {
public:
    virtual void vfunc_0();
    int field4;
    int field8;
    int fieldC;
    CSoundCommand_1f0230(int c) : field4(0), field8(0), fieldC(c) {}
};

struct SoundId {
    U64 value;
    SoundId(int name) : value(0) { value = FUN_002672f0(name, 0, 0); }
};

class CSoundCommand_PlayTunableEvent : public CSoundCommand_1f0230 {
public:
    SoundId event;
    int tuning;
    int field1C;
    int field20;
    int field24;
    CSoundCommand_PlayTunableEvent(int name, int tuningName, int c, int d, int e, int f);
    virtual void vfunc_0();
};

CSoundCommand_PlayTunableEvent::CSoundCommand_PlayTunableEvent(int name, int tuningName, int c, int d, int e, int f)
    : CSoundCommand_1f0230(f), event(name)
{
    tuning = FUN_002673a0(tuningName, 0);
    field1C = c;
    field20 = d;
    field24 = e;
}
