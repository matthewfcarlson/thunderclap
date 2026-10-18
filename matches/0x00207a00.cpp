// FUN_00207a00 @ 0x00207a00
#include "decls/data/game/global.h"

struct Anim;

struct Request {
    char pad0[4];
    signed char countA;
    signed char countB;
    int FUN_00208b80(int i);
    int FUN_00208b90(int i);
};

struct Player_207a00 {
    int FUN_00266710();
    void FUN_002666e0();
};

class Layers_207a00 {
public:
    char pad0[0x590];
    Request *request;
    char pad594[0x5a4 - 0x594];
    char state[0x548];
    Player_207a00 *player;
    char busy;
    char pad_af1;
    char flagAf2;
    int FUN_00203bb0();
    void FUN_00203e30(Player_207a00 *p);
    bool FUN_002046b0(int cur);
    void FUN_00207410();
    void FUN_00207a00(Request *req);
};

void Layers_207a00::FUN_00207a00(Request *req)
{
    int i;
    int countA = req->countA;
    for (i = 0; i < countA; i++) {
        int idx = req->FUN_00208b80(i);
        char c = state[idx];
        if (c == 0 || c == 2)
            state[idx] = 2;
        else if (c == 1 || c == 3)
            state[idx] = 1;
    }
    int cur = FUN_00203bb0();
    int countB = req->countB;
    for (i = 0; i < countB; i++) {
        int idx = req->FUN_00208b90(i);
        if (!flagAf2 && idx == cur && player) {
            int mode = player->FUN_00266710();
            busy = 1;
            if (mode == 3)
                FUN_00207410();
            else if ((*(char*)&DAT_004c91da))
                player->FUN_002666e0();
            else
                FUN_00203e30(player);
        }
        char c = state[idx];
        if (c == 1 || c == 3)
            state[idx] = 3;
        else if (c == 0 || c == 2)
            state[idx] = 0;
    }
    if (flagAf2 && !FUN_002046b0(cur) && player) {
        int mode = player->FUN_00266710();
        busy = 1;
        if (mode == 3)
            FUN_00207410();
        else if ((*(char*)&DAT_004c91da))
            player->FUN_002666e0();
        else
            FUN_00203e30(player);
    }
    request = req;
}
