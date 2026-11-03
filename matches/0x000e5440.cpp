// FUN_000e5440 @ 0x000e5440
#include "decls/data/game/global.h"
#include "gen/owners.h"


void owners::Fader_e5440::FUN_000e5440(int newState) {
    int old = state;
    state = newState;
    switch (newState) {
    case 0:
        level = 0;
        output = base * 0.0f;
        if (old != 0)
            FUN_000e53e0(old);
        break;
    case 1:
        level = 1.0f;
        output = base;
        stateTime = 0;
        if (old != 1)
            FUN_000e5330();
        break;
    case 2:
        level = 0;
        stateTime = 0;
        output = base * 0.0f;
        if (old != 2)
            FUN_000e5330();
        break;
    }
}
