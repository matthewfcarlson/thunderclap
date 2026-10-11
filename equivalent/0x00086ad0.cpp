// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 36/38, incomplete)
// FUN_00086ad0 @ 0x00086ad0
struct Flags {
    char pad0[4];
    char started;       // +4
    char quit;          // +5
    char pad1;
    char busy;          // +7
    char pad2;
    char paused;        // +9
};

struct PadState {
    char pad0[0x10];
    float value;
    char pad1[0x44 - 0x14];
};

struct Pad {
    void FUN_000ada70(PadState *out);
};

struct PadList {
    Pad *FUN_000ae640(int index);
    void FUN_000ae840();
};

struct Audio {
    void FUN_001eb870();
    void FUN_001eb890();
    void FUN_001eb2a0(float a, int b);
};

struct Fader {
    void FUN_001b8110(int ms);
};

struct Context {
    char pad[0x30];
    Audio *audio;
    Fader *fader;
};

struct Sim {
    char pad[0x54];
    Context *ctx;
};

struct Game {
    void FUN_00086ad0();
    char pad0[0x10];
    PadList *pads;
    char pad1[0x24 - 0x14];
    struct Renderer *renderer;
};

struct Renderer {
    void FUN_001bc040();
};

extern int DAT_0049c0dc;
extern Sim *DAT_004dd700;
extern int DAT_004dda40;
extern char DAT_004e222c;
extern char DAT_004ddbe1;
extern char DAT_004e222d;

Flags *FUN_0008e090();
void FUN_002684c0();
char FUN_0008db80();

void Game::FUN_00086ad0()
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
        DAT_004dda40++;
    } while (!FUN_0008e090()->quit);

    bool rising = false;
    bool settled = false;
    PadState state;
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
    DAT_004ddbe1 = 1;
    DAT_004e222d = 1;
}
