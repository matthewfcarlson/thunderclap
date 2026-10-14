// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000384e0 @ 0x000384e0
extern "C" int __cdecl _stricmp(const char *a, const char *b);

struct Event {
    int w[7];
    Event *FUN_001ca210(int prev, int next, int id);
};

struct Channel {
    void FUN_001cbc20(Event *e);
};

struct ChannelHolder {
    char pad[0x30];
    Channel *channel;
};

extern ChannelHolder *DAT_004dd700;
extern const char *DAT_0048f590[8];

struct Owner {
    int id;
};

struct Controller {
    char pad00[0x10];
    Owner *owner;
    char pad14[0x134 - 0x14];
    int current;
    void FUN_000384e0(const char *name);
};

void Controller::FUN_000384e0(const char *name)
{
    for (int i = 0; i < 8; i++) {
        if (_stricmp(name, DAT_0048f590[i]) == 0 && current != i) {
            Channel *ch = DAT_004dd700->channel;
            if (ch != 0) {
                Event ev;
                ev.FUN_001ca210(current, i, owner->id);
                ch->FUN_001cbc20(&ev);
            }
            current = i;
        }
    }
}
