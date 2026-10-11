// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 20/20)
// FUN_000b9830 @ 0x000b9830
extern "C" char* strncpy(char*, const char*, unsigned int);
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
class Entry;
class Queue {
  public:
    int FUN_00088fa0();
};
class Mission {
  public:
    char pad[0x80];
    Queue queue;
    void FUN_00089390();
    char FUN_00089a10();
    void FUN_00089a30(char flag);
    Entry* FUN_0008a310();
    void FUN_000895e0(Entry* e);
    void FUN_00089810(Entry* e);
};
class Hud {
  public:
    void FUN_001cc620(int state);
};
Game* __cdecl FUN_000fc3d0();
void __cdecl FUN_000fc300();

class Menu {
  public:
    char pad0[0x10];
    int state;
    char pad1[0x34 - 0x14];
    Mission* mission;
    Hud* hud;
    char pad2[0x1c8c - 0x3c];
    char saveName[32];
    Entry* FUN_000b4cf0(Entry* e);
    void FUN_000b9830();
};

void Menu::FUN_000b9830() {
    if (state != 0x16)
        return;
    Player* p = FUN_000fc3d0()->player;
    if (p != 0 && p->busy != 0)
        return;
    state = 9;
    if (FUN_000fc3d0()->mode != 1)
        return;
    if (mission == 0 || hud == 0)
        return;
    mission->FUN_00089390();
    int count = mission->queue.FUN_00088fa0();
    if (mission->FUN_00089a10() && count == 10) {
        hud->FUN_001cc620(5);
        mission->FUN_00089a30(1);
        strncpy(saveName, "side_missions", 0x1f);
        FUN_000fc300();
        return;
    }
    hud->FUN_001cc620(9);
    mission->FUN_00089a30(0);
    Entry* e = mission->FUN_0008a310();
    if (e == 0)
        return;
    Entry* r = FUN_000b4cf0(e);
    if (r == 0)
        return;
    mission->FUN_000895e0(r);
    mission->FUN_00089810(e);
    FUN_000fc300();
}
