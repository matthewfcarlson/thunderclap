// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 30/30)
// FUN_0003b1c0 @ 0x0003b1c0
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct Msg {
    char data[0xb0];
    Msg *FUN_001c9a40(int id);
};

struct Dispatcher {
    void FUN_001cbc20(Msg *m);
};

struct System {
    char pad0[0x30];
    Dispatcher *dispatcher;
};

extern System *DAT_004dd700;

struct Source {
    int id;
};

struct Info {
    char pad0[0x134];
    float limit;
};

class Timer {
public:
    char pad0[0x10];
    Source *source;
    char pad14[0x11c - 0x14];
    Info *info;
    char pad120[0x1b0c - 0x120];
    float value;
    float maxValue;
    char pad1b14[4];
    float trigger;
    int count;
    char pad1b20[8];
    int mode;
    bool FUN_0003b1c0(float dt, bool force);
};

bool Timer::FUN_0003b1c0(float dt, bool force)
{
    unsigned int cookie = DAT_004d9968;
    Msg msg;

    if (!force) {
        if (trigger > 0.0f || count > 0) {
            if (dt < value) {
                __security_check_cookie(cookie);
                return false;
            }
        }
    }

    bool wasZero = (value <= 0.0f);
    System *sys = DAT_004dd700;
    value = dt;
    if (dt < 0.0f)
        value = 0.0f;

    Info *inf = info;
    if (inf) {
        if (maxValue < value)
            value = maxValue;
        if (!force) {
            float lim = inf->limit;
            if (lim > value && mode != 2)
                value = lim;
        }
        if (value <= 0.0f && !wasZero) {
            Dispatcher *d = sys->dispatcher;
            if (d) {
                msg.FUN_001c9a40(source->id);
                d->FUN_001cbc20(&msg);
            }
        }
    }
    __security_check_cookie(cookie);
    return true;
}
