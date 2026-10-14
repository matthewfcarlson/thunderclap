// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::HitReactionFloatAction::vfunc_5 @ 0x001519a0
// Hit reaction "float" action: advance to step `step`, switching the active animation reference.
class Ref {
public:
    virtual void AddRef();
    virtual void Release();
};

class Fighter {
public:
    void FUN_00035cd0();
};

class FighterRef {
public:
    Fighter* FUN_00059a30();
};

class Owner {
public:
    FighterRef* FUN_000592a0();
};

class Track {
public:
    Ref* current;
    char pad4[0x24];

    void FUN_002322f0(int count, int arg);
    void FUN_00231f20(int step);
    void FUN_002324b0(int flag);
    void FUN_00231ee0();
};

class HitReactionFloatAction {
public:
    char pad0[0x20];
    Owner* owner;
    Track track;
    Ref* previous;
    int stepCount;
    char started;

    void FUN_001519a0(int step, int arg);
};

void HitReactionFloatAction::FUN_001519a0(int step, int arg)
{
    if (step == 0 && !started) {
        track.FUN_002322f0(stepCount, arg);
    }
    started = 0;
    if (previous != track.current) {
        owner->FUN_000592a0()->FUN_00059a30()->FUN_00035cd0();
    }
    track.FUN_00231f20(step);
    if (step == stepCount - 1) {
        track.FUN_002324b0(1);
    }
    Ref* now = track.current;
    if (now) {
        now->AddRef();
    }
    if (previous) {
        previous->Release();
    }
    previous = now;
    track.FUN_00231ee0();
}
