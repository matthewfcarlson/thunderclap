// FUN_000b96e0 @ 0x000b96e0
class Player_b96e0 {
  public:
    char pad[0x9a8];
    char busy;
};
class Game_b96e0 {
  public:
    char pad[0x2218];
    Player_b96e0* player;
    int mode;
};
class Fader_b96e0 {
  public:
    void FUN_001eb870();
    void FUN_001eb2a0(float dt, int flag);
    void FUN_001eb890();
};
class Panel_b96e0 {
  public:
    void FUN_00089e10();
};
Game_b96e0* __cdecl FUN_000fc3d0();
void __cdecl FUN_000fc280(const char* name);

class Menu_b96e0 {
  public:
    char pad0[0x10];
    int state;
    char pad1[0x34 - 0x14];
    Panel_b96e0* panel;
    char pad1b[4];
    Fader_b96e0* fader;
    char pad2[0x1cf8 - 0x40];
    int saveSlot;
    void FUN_000b5030(int slot);
    void FUN_000b96e0();
};

void Menu_b96e0::FUN_000b96e0() {
    if (state != 0x13)
        return;
    Player_b96e0* p = FUN_000fc3d0()->player;
    if (p != 0 && p->busy != 0)
        return;
    state = 0;
    if (FUN_000fc3d0()->mode != 1)
        return;
    fader->FUN_001eb870();
    for (int i = 0; i < 10; i++)
        fader->FUN_001eb2a0(0.01f, 0);
    panel->FUN_00089e10();
    FUN_000b5030(saveSlot);
    FUN_000fc280("save_new_game");
    fader->FUN_001eb890();
}
