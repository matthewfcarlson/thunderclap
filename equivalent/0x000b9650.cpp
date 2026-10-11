// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 10/10)
// FUN_000b9650 @ 0x000b9650
class Player {
  public:
    char pad[0x9a8];
    char busy;
};
class Game {
  public:
    char pad[0x2218];
    Player* player;
    int mode;
};
class Fader {
  public:
    void FUN_001eb870();
    void FUN_001eb2a0(float dt, int flag);
    void FUN_001eb890();
};
class Panel {
  public:
    void FUN_00089d30();
};
Game* __cdecl FUN_000fc3d0();
void __cdecl FUN_000fc280(const char* name);

class Menu {
  public:
    char pad0[0x10];
    int state;
    char pad1[0x34 - 0x14];
    Panel* panel;
    char pad1b[4];
    Fader* fader;
    char pad2[0x1cf8 - 0x40];
    int saveSlot;
    void FUN_000b5030(int slot);
    void FUN_000b9650();
};

void Menu::FUN_000b9650() {
    if (state != 0x12)
        return;
    Player* p = FUN_000fc3d0()->player;
    if (p != 0 && p->busy != 0)
        return;
    state = 0;
    if (FUN_000fc3d0()->mode != 1)
        return;
    fader->FUN_001eb870();
    for (int i = 0; i < 10; i++)
        fader->FUN_001eb2a0(0.01f, 0);
    panel->FUN_00089d30();
    FUN_000b5030(saveSlot);
    FUN_000fc280("save_new_game");
    fader->FUN_001eb890();
}
