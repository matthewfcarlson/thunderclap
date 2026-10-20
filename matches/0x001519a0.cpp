// hulkfight::motion::HitReactionFloatAction::vfunc_5 @ 0x001519a0
// Hit reaction "float" action: advance to step `step`, switching the active animation reference.
class Ref_1519a0 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Fighter_1519a0 {
public:
    void FUN_00035cd0();
};

class FighterRef_1519a0 {
public:
    Fighter_1519a0* FUN_00059a30();
};

class Owner_1519a0 {
public:
    FighterRef_1519a0* FUN_000592a0();
};

class Track {
public:
    Ref_1519a0* current;
    char pad4[0x24];

    void FUN_002322f0(int count, int arg);
    void FUN_00231f20(int step);
    void FUN_002324b0(int flag);
    int FUN_00231ee0();
};

class HitReactionFloatAction {
public:
    char pad0[0x20];
    Owner_1519a0* owner;
    Track track;
    Ref_1519a0* previous;
    int stepCount;
    char started;

    int FUN_001519a0(int step, int arg);
};

int HitReactionFloatAction::FUN_001519a0(int step, int arg)
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
    Ref_1519a0* now = track.current;
    if (now) {
        now->AddRef();
    }
    if (previous) {
        previous->Release();
    }
    previous = now;
    return track.FUN_00231ee0();
}
