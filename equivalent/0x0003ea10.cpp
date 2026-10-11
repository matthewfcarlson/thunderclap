// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 18/18)
// FUN_0003ea10 @ 0x0003ea10
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct Actor {
    char pad0[0x328];
    void *target;            // 0x328
    char pad32c[0x1b48 - 0x32c];
    char active;             // 0x1b48
    void FUN_000393c0();
};

struct Group {
    char pad0[0xc];
    int count;               // 0x0c
    char FUN_000242d0(void *owner);
    Actor *FUN_00024190(int index);
};

struct Event {
    char data[0xc0];
    Event *FUN_001c9920(int a, void *b, int c, unsigned char d);
};

struct EventSink {
    char FUN_001cbc20(Event *e);
};

struct Manager {
    char pad0[0x20];
    Group *group;            // 0x20
    char pad24[0x30 - 0x24];
    EventSink *sink;         // 0x30
};
extern Manager *DAT_004dd700;

void *__cdecl FUN_001b46f0(void *key, int *out);

class Controller {
public:
    char pad0[0x10];
    int *ref10;               // 0x10
    char pad14[0x12c - 0x14];
    void *activeTarget;      // 0x12c
    char pad130[0x20b0 - 0x130];
    int mode;                // 0x20b0
    char pad20b4[0x22e4 - 0x20b4];
    void *key;               // 0x22e4
    unsigned char flag;      // 0x22e8
    void FUN_0003b1c0(int a, int b);
    void FUN_0003ea10(int newMode);
};

extern unsigned int DAT_004d9968;

struct Frame {
    int arg;
    Event ev;
    unsigned int cookie;
};

void Controller::FUN_0003ea10(int newMode)
{
    Frame f;
    f.cookie = DAT_004d9968;
    if (mode == 0) {
        if (newMode == 1) {
            FUN_0003b1c0(0, newMode);
            EventSink *sink = DAT_004dd700->sink;
            if (sink) {
                f.arg = 0;
                void *res = FUN_001b46f0(key, &f.arg);
                f.ev.FUN_001c9920(*ref10, res, f.arg, flag);
                sink->FUN_001cbc20(&f.ev);
            }
            if (!DAT_004dd700->group->FUN_000242d0(this)) {
                int count = DAT_004dd700->group->count;
                for (int i = 0; i < count; i++) {
                    Actor *a = DAT_004dd700->group->FUN_00024190(i);
                    if (a->target && a->target == activeTarget) {
                        if (a->active)
                            a->active = 0;
                        a->FUN_000393c0();
                    }
                }
            }
        }
    }
    mode = newMode;
    __security_check_cookie(f.cookie);
}
