// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b4cf0..0x000bba40 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x000b9830 FUN_000b9830 (251 B): equivalent/0x000b9830.cpp [isolated: conflict: FUN_000fc3d0; on include/gen/ and not mergeable]
// sym: ?FUN_000b9830@Menu_b9830@@QAEXXZ @3c9015bd3a4c @w00158238f47c
// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 20/20)
// FUN_000b9830 @ 0x000b9830
#include "gen/global.h"

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strncpy(char*, const char*, unsigned int);
#endif

class Player_b9830 {
  public:
    char pad[0x9a8];
    char busy;
};
class Game_b9830 {
  public:
    char pad[0x2218];
    Player_b9830* player;
    int mode;
};
class Entry;
class Queue_b9830 {
  public:
    int FUN_00088fa0();
};
class Mission_b9830 {
  public:
    char pad[0x80];
    Queue_b9830 queue;
    void FUN_00089390();
    char FUN_00089a10();
    void FUN_00089a30(char flag);
    Entry* FUN_0008a310();
    void FUN_000895e0(Entry* e);
    void FUN_00089810(Entry* e);
};
class Hud_b9830 {
  public:
};
Game_b9830* __cdecl FUN_000fc3d0();
extern "C" void __cdecl FUN_000fc300();

class Menu_b9830 {
  public:
    char pad0[0x10];
    int state;
    char pad1[0x34 - 0x14];
    Mission_b9830* mission;
    Hud_b9830* hud;
    char pad2[0x1c8c - 0x3c];
    char saveName[32];
    Entry* FUN_000b4cf0(Entry* e);
    void FUN_000b9830();
};

void Menu_b9830::FUN_000b9830() {
    if (state != 0x16)
        return;
    Player_b9830* p = FUN_000fc3d0()->player;
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
        ((::CScenarioManager *)hud)->FUN_001cc620(5);
        mission->FUN_00089a30(1);
        strncpy(saveName, "side_missions", 0x1f);
        FUN_000fc300();
        return;
    }
    ((::CScenarioManager *)hud)->FUN_001cc620(9);
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

