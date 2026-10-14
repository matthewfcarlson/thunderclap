// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 4/4)
// FUN_001b9020 @ 0x001b9020
// Screen/menu activation: bring up the HUD handles, flag the UI as active and reset the player's counter once.
class Cursor {
public:
    int FUN_000d6f50();
    void FUN_000d7030(int mode);
};

class Widget {
public:
    void FUN_000afe80();
};

class Fader {
public:
    void FUN_001c3800(float scale, int a, int b, int c, int d);
};

class Panel {
public:
    Widget* FUN_00086330();
};

class Player {
public:
    char pad0[0x1e58];
    int counter;
    void FUN_000361c0(int flag);
};

class PlayerHolder {
public:
    char pad0[0x124];
    Player* player;
};

class Game {
public:
    char pad0[0x20];
    PlayerHolder* holder;
    char pad24[0x3c - 0x24];
    Cursor* cursor;
    char pad40[0x54 - 0x40];
    Panel* panel;
};

extern Game* DAT_004dd700;
extern char DAT_004e222c;

Fader* __cdecl FUN_001c3d90();

class Screen {
public:
    char pad0[0x24];
    int cursorId;
    char pad28[0x32 - 0x28];
    char started;

    void FUN_001b9020();
};

void Screen::FUN_001b9020()
{
    cursorId = DAT_004dd700->cursor->FUN_000d6f50();
    DAT_004dd700->cursor->FUN_000d7030(0x100);
    DAT_004dd700->panel->FUN_00086330()->FUN_000afe80();
    FUN_001c3d90()->FUN_001c3800(0.28f, 0, 0, 0, 0);
    DAT_004e222c = 1;
    Player* player = DAT_004dd700->holder->player;
    if (player) {
        player->counter = 0;
        if (!started) {
            player->FUN_000361c0(1);
            started = 1;
        }
    }
}
