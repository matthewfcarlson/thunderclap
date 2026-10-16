// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 36/38, incomplete)
// FUN_00086ad0 @ 0x00086ad0
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
struct Flags_86ad0 {
    char pad0[4];
    char started;       // +4
    char quit;          // +5
    char pad1;
    char busy;          // +7
    char pad2;
    char paused;        // +9
};

struct PadState_86ad0 {
    char pad0[0x10];
    float value;
    char pad1[0x44 - 0x14];
};

struct Pad_86ad0 {
    void FUN_000ada70(PadState_86ad0 *out);
};

struct PadList_86ad0 {
    Pad_86ad0 *FUN_000ae640(int index);
    void FUN_000ae840();
};

struct Audio_86ad0 {
    void FUN_001eb870();
    void FUN_001eb890();
    void FUN_001eb2a0(float a, int b);
};

struct Fader_86ad0 {
    void FUN_001b8110(int ms);
};

struct Context {
    char pad[0x30];
    Audio_86ad0 *audio;
    Fader_86ad0 *fader;
};

struct World {
    char pad[0x54];
    Context *ctx;
};

struct Game_86ad0 {
    void FUN_00086ad0();
    char pad0[0x10];
    PadList_86ad0 *pads;
    char pad1[0x24 - 0x14];
    struct Renderer_86ad0 *renderer;
};

struct Renderer_86ad0 {
    void FUN_001bc040();
};


Flags_86ad0 *FUN_0008e090();
void FUN_002684c0();
char FUN_0008db80();

void Game_86ad0::FUN_00086ad0()
{
    if (DAT_0049c0dc > 0) {
        DAT_0049c0dc--;
        if (DAT_0049c0dc == 0)
            FUN_0008e090()->started = 1;
    }

    if (!FUN_0008e090()->started)
        return;

    if (!FUN_0008e090()->paused && !FUN_0008e090()->quit) {
        DAT_004dd700->ctx->audio->FUN_001eb870();
        FUN_0008e090()->paused = 1;
        for (int n = 10; n != 0; n--)
            DAT_004dd700->ctx->audio->FUN_001eb2a0(0.01f, 0);
    }

    if (FUN_0008e090()->quit)
        return;

    do {
        renderer->FUN_001bc040();
        FUN_0008e090()->busy = 1;
        FUN_002684c0();
        (*(int*)&DAT_004dda40)++;
    } while (!FUN_0008e090()->quit);

    bool rising = false;
    bool settled = false;
    PadState_86ad0 state;
    while (!(rising && settled) && FUN_0008e090()->quit) {
        int i = 0;
        do {
            pads->FUN_000ae640(i)->FUN_000ada70(&state);
            float v = state.value;
            if (rising) {
                if (v < 0.2f) {
                    settled = true;
                    break;
                }
            } else if (v > 0.2f) {
                rising = true;
                break;
            }
            i++;
        } while (i < 1);
        pads->FUN_000ae840();
    }

    if (FUN_0008e090()->busy && FUN_0008e090()->quit) {
        FUN_0008e090()->busy = 0;
        if (!FUN_0008db80()) {
            DAT_004dd700->ctx->audio->FUN_001eb890();
            FUN_0008e090()->paused = 0;
            for (int n = 10; n != 0; n--)
                DAT_004dd700->ctx->audio->FUN_001eb2a0(0.01f, 0);
            DAT_004dd700->ctx->fader->FUN_001b8110(500);
        }
    }
    DAT_004e222c = 1;
    (*(char*)&DAT_004ddbe1) = 1;
    (*(char*)&DAT_004e222d) = 1;
}
