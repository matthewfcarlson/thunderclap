// STATUS: equivalent (tools/equiv.py level 3: 139 inputs, branch coverage 40/40)
// FUN_001cc620 @ 0x001cc620
struct Fader {
    void FUN_000d6fb0(char flag);
};

struct Panel {
    char pad0[0x3c];
    Fader *fader;
};

struct Counter {
    int FUN_00088fa0();
};

struct Stats {
    char pad0[0x80];
    Counter counter;
};

struct Hud {
    void FUN_000bc1e0(const char *name);
    void FUN_000b73b0();
    void FUN_000bce10();
    void FUN_000b7760();
    void FUN_000b89e0();
    void FUN_000bc750();
};

struct Game {
    char pad0[0xc];
    Panel *panel;
    char pad1[0x20 - 0x10];
    Hud *hud;
    char pad2[0x38 - 0x24];
    Stats *stats;
    Hud *FUN_00086280();
    Stats *FUN_00086310();
};

extern Game *DAT_004dd6ec;

void __fastcall FUN_001cc600(char flag);

struct Screen {
    char pad0[0xc];
    int state;
    void FUN_001cc620(int next);
};

void Screen::FUN_001cc620(int next)
{
    switch (next) {
    case 1:
        if (DAT_004dd6ec != 0 && DAT_004dd6ec->panel != 0 && DAT_004dd6ec->panel->fader != 0)
            DAT_004dd6ec->panel->fader->FUN_000d6fb0(0);
        state = next;
        return;
    case 2: {
        if (DAT_004dd6ec != 0 && DAT_004dd6ec->panel != 0 && DAT_004dd6ec->panel->fader != 0)
            DAT_004dd6ec->panel->fader->FUN_000d6fb0(0);
        Stats *stats = DAT_004dd6ec->FUN_00086310();
        if (stats->counter.FUN_00088fa0() >= 10) {
            DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("side_mission_fail");
            int cur = state;
            state = cur;
            return;
        }
        DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("story_mission_fail");
        DAT_004dd6ec->FUN_00086280()->FUN_000b89e0();
        int cur = state;
        state = cur;
        return;
    }
    case 9:
        if (DAT_004dd6ec != 0 && DAT_004dd6ec->panel != 0 && DAT_004dd6ec->panel->fader != 0)
            DAT_004dd6ec->panel->fader->FUN_000d6fb0(0);
        state = 2;
        return;
    case 3: {
        FUN_001cc600(0);
        Stats *stats = DAT_004dd6ec->FUN_00086310();
        if (stats->counter.FUN_00088fa0() >= 10) {
            DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("side_mission_success");
            state = next;
            return;
        }
        DAT_004dd6ec->FUN_00086280()->FUN_000b7760();
        DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("story_mission_success");
        state = next;
        return;
    }
    case 6: {
        DAT_004dd6ec->FUN_00086280()->FUN_000b73b0();
        DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("mission_accept");
        int cur = state;
        state = cur;
        return;
    }
    case 7: {
        DAT_004dd6ec->FUN_00086280()->FUN_000bce10();
        DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("jump_marker_select");
        int cur = state;
        state = cur;
        return;
    }
    case 10: {
        DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("fullscreen_message");
        int cur = state;
        state = cur;
        return;
    }
    case 11: {
        DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("fullscreen_question");
        int cur = state;
        state = cur;
        return;
    }
    case 12:
        DAT_004dd6ec->FUN_00086280()->FUN_000bc750();
        state = 2;
        return;
    }
    state = next;
}
