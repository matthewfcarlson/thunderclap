// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/10, incomplete)
// FUN_000ae9f0 @ 0x000ae9f0
#include "decls/address.h"
#include "decls/data/game/global.h"
struct PadState_ae9f0 {
    int words[41];
};

struct PadSource {
    void FUN_000af0f0(PadState_ae9f0 *out);
};

struct PadList_ae9f0 {
    PadSource *FUN_000af3a0(int index);
};

struct InputManager {
    PadList_ae9f0 *FUN_000862d0();
};

struct World {
    char pad0[0x54];
    InputManager *input;
};


bool FUN_000ae9f0() {
    DAT_004dd700->input->FUN_000862d0();
    for (int i = 0; i < 1; i++) {
        PadState_ae9f0 state;
        DAT_004dd700->input->FUN_000862d0()->FUN_000af3a0(i)->FUN_000af0f0(&state);
        if (state.words[0] == 1 || state.words[12] == 1 || state.words[3] == 1 ||
            state.words[18] == 1) {
            DAT_004e222c = 1;
            return true;
        }
    }
    return false;
}
