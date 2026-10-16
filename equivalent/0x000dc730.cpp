// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000dc730 @ 0x000dc730
#include "decls/address.h"
struct Settings_dc730 {
    char pad00[0xbc0];
    char flag;              // 0xbc0
};

struct Session_dc730 {
    char pad00[0x175c];
    Settings_dc730 *settings;     // 0x175c
};

struct Inner_dc730 {
    char pad00[4];
    Session_dc730 *session;       // 0x4
};

struct Middle {
    char pad00[8];
    Inner_dc730 *inner;           // 0x8
};

struct Label_dc730 {
    void FUN_000bc9f0(const char *name, int id);
};

struct Singleton_4dd6ec {
    Label_dc730 *FUN_00086280();
};


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
