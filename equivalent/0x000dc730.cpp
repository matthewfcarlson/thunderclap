// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000dc730 @ 0x000dc730
struct Settings {
    char pad00[0xbc0];
    char flag;              // 0xbc0
};

struct Session {
    char pad00[0x175c];
    Settings *settings;     // 0x175c
};

struct Inner {
    char pad00[4];
    Session *session;       // 0x4
};

struct Middle {
    char pad00[8];
    Inner *inner;           // 0x8
};

struct Label {
    void FUN_000bc9f0(const char *name, int id);
};

struct LabelTable {
    Label *FUN_00086280();
};

extern LabelTable *DAT_004dd6ec;

class ControlPrompt {
public:
    char pad00[0x14];
    Middle *middle;         // 0x14
    char pad18[0x178 - 0x18];
    int state;              // 0x178
    void FUN_000dc730();
};

void ControlPrompt::FUN_000dc730()
{
    bool pressed = middle->inner->session->settings->flag != 0;
    int id;
    if (pressed)
        id = 0xb;
    else if (state == 2)
        id = 0xc;
    else
        id = 0xa;
    DAT_004dd6ec->FUN_00086280()->FUN_000bc9f0("DynamicControlButtonLabel", id);
}
