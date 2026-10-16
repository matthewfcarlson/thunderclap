// STATUS: equivalent (tools/equiv.py level 3: 131 inputs, branch coverage 18/18)
// FUN_000be100 @ 0x000be100
#include "decls/data/game/unknown.h"

class Player_be100 {
  public:
    char pad[0x9a8];
    char busy;
};
class Game_be100 {
  public:
    char pad[0x2218];
    Player_be100* player;
    int mode;
};
class Singleton;
Game_be100* __cdecl FUN_000fc3d0();
Singleton* __cdecl FUN_001d4c90();

class Menu_be100 {
  public:
    char pad0[0x10];
    int state;
    char pad1[0x1cec - 0x14];
    int pending;
    int index;
    void FUN_000bc5c0(const char* kind, const char* level, int difficulty, int flag);
    void FUN_000be100();
};

void Menu_be100::FUN_000be100() {
    if (state != 0x17)
        return;
    Player_be100* p = FUN_000fc3d0()->player;
    if (p != 0 && p->busy != 0)
        return;
    state = 0;
    if (FUN_000fc3d0()->mode == 1 && pending >= 0x266 && pending <= 0x2c9 && FUN_001d4c90() != 0) {
        index = pending - 0x265;
        int difficulty = DAT_0049cab4;
        if (difficulty < 0 || difficulty >= 3)
            difficulty = 1;
        FUN_000bc5c0("oneshot", "c00m10", difficulty, 1);
    }
    pending = -1;
}
