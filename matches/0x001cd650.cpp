#include "decls/data/game/global.h"
// data: Zero_1cd650 = DAT_003f32e0

struct ThisCall_001cccc0 {
    void Stop();
};
class Thing_1cd650 {
  public:
    char pad[0x11a8];
    float timer;
    int a;
    int b;
    void Update(float dt);
};
void Thing_1cd650::Update(float dt) {
    if (timer != (*(float*)&DAT_003f32e0)) {
        timer = timer - dt;
        if (timer <= (*(float*)&DAT_003f32e0)) {
            timer = 0.0f;
            ((ThisCall_001cccc0*)(this))->Stop();
            b = 0;
            a = 0;
        }
    }
}