#include "decls/data/game/Render/Canvas.h"
#include "gen/owners.h"

struct Snd_1c16e0 {
    virtual void v0();
    virtual void Play(int, float, float, unsigned char);
};
void owners::Obj_1c16e0::FUN_001c16e0(float x, float y) {
    a = x;
    b = y;
    if (x != 0.0f && (*(Snd_1c16e0**)&DAT_004e2318)) {
        (*(Snd_1c16e0**)&DAT_004e2318)->Play(1, x, y, c);
        return;
    }
    (*(Snd_1c16e0**)&DAT_004e2318)->Play(0, x, y, c);
}
