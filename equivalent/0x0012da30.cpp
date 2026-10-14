// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::PostEvent_StringAction::vfunc_5 @ 0x0012da30
// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
struct Key {
    int lo, hi;
    Key() throw() {}
    Key(const Key &other) throw();
};

struct StatusCheck {
    char pad00[1];
    char FUN_001ccff0();
};

struct EventQueue {
    char pad00[1];
    char FUN_001cb990(Key id);
    void FUN_001cbc20(void *event);
};

struct EventBuilder {
    char data[0x20];
    void FUN_001cadf0(Key id);
};

struct Game {
    char pad00[0x2c];
    StatusCheck *status;     // 0x2c
    EventQueue *queue;       // 0x30
};
extern Game *DAT_004dd700;

struct ActionParams {
    char pad00[0x10];
    Key id;                 // 0x10
    char requireStatus;      // 0x18
    char requireNotQueued;   // 0x19
};

class PostEvent_StringAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool vfunc_5(int a, int b);
    char pad04[0x18];
    ActionParams *params;    // 0x1c
};

bool PostEvent_StringAction::vfunc_5(int a, int b) {
    Game *game = DAT_004dd700;
    if (game) {
        if (params->requireStatus) {
            if (!game->status || !game->status->FUN_001ccff0())
                return false;
        }
        if (params->requireNotQueued) {
            EventQueue *q = game->queue;
            if (!q || q->FUN_001cb990(params->id))
                return false;
        }
        EventQueue *q = game->queue;
        if (q) {
            EventBuilder ev;
            ev.FUN_001cadf0(params->id);
            q->FUN_001cbc20(&ev);
        }
    }
    return false;
}
