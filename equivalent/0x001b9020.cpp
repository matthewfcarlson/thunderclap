// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 4/4)
// FUN_001b9020 @ 0x001b9020
// Screen/menu activation: bring up the HUD handles, flag the UI as active and reset the player's counter once.
class Cursor_1b9020 {
public:
    int FUN_000d6f50();
    void FUN_000d7030(int mode);
};

class Widget_1b9020 {
public:
    void FUN_000afe80();
};

class Fader_1b9020 {
public:
    void FUN_001c3800(float scale, int a, int b, int c, int d);
};

class Panel_1b9020 {
public:
    Widget_1b9020* FUN_00086330();
};

class Player_1b9020 {
public:
    char pad0[0x1e58];
    int counter;
    void FUN_000361c0(int flag);
};

class PlayerHolder_1b9020 {
public:
    char pad0[0x124];
    Player_1b9020* player;
};

class Game_1b9020 {
public:
    char pad0[0x20];
    PlayerHolder_1b9020* holder;
    char pad24[0x3c - 0x24];
    Cursor_1b9020* cursor;
    char pad40[0x54 - 0x40];
    Panel_1b9020* panel;
};

extern Game_1b9020* DAT_004dd700;
extern char DAT_004e222c;

Fader_1b9020* __cdecl FUN_001c3d90();

class Screen_1b9020 {
public:
    char pad0[0x24];
    int cursorId;
    char pad28[0x32 - 0x28];
    char started;

    void FUN_001b9020();
};

void Screen_1b9020::FUN_001b9020()
{
    cursorId = DAT_004dd700->cursor->FUN_000d6f50();
    DAT_004dd700->cursor->FUN_000d7030(0x100);
    DAT_004dd700->panel->FUN_00086330()->FUN_000afe80();
    FUN_001c3d90()->FUN_001c3800(0.28f, 0, 0, 0, 0);
    DAT_004e222c = 1;
    Player_1b9020* player = DAT_004dd700->holder->player;
    if (player) {
        player->counter = 0;
        if (!started) {
            player->FUN_000361c0(1);
            started = 1;
        }
    }
}
