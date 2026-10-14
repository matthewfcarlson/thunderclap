// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::ai::KeywordWaitAction::vfunc_5 @ 0x0010e570
struct Timer {
    char pad0[0x18];
    int arg0;               // 0x18
    int arg1;               // 0x1c
};

struct Mixer;

struct Handle {
    Mixer* FUN_00059a30();
};

struct Mgr {
    Handle* FUN_000592a0();
};

struct Mixer {
    float FUN_00037290(int a, int b);
};

namespace hulkfight {
namespace ai {
class KeywordWaitAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int skip, float dt);
    char pad04[0x1c - 4];
    Timer* timer;           // 0x1c
    Mgr* manager;           // 0x20
    float wait;             // 0x24
    float elapsed;          // 0x28
};
}
}

// Advances the elapsed time; false while the wait is still running.
bool hulkfight::ai::KeywordWaitAction::vfunc_5(int skip, float dt)
{
    if (skip == 0) {
        Mixer* mixer = manager->FUN_000592a0()->FUN_00059a30();
        elapsed = dt + elapsed;
        volatile float v = mixer->FUN_00037290(timer->arg0, timer->arg1);
        wait = v;
        if (v > 0.0f) {
            if (elapsed >= v)
                return false;
        }
        return true;
    }
    return true;
}
