#include "decls/data/game/global.h"
// data: one = DAT_003f32dc, zero_225140 = DAT_003f32e0

struct Inner_225140 {
    char pad[0x10];
    float f;
};
class AnimationDriver_225140 {
  public:
    char pad[0x20];
    Inner_225140* p;
    char pad2[0x20c];
    float value;
    void Set(float x);
};
void AnimationDriver_225140::Set(float x) {
    float v = p->f - DAT_003f32dc;
    if (x < DAT_003f32e0) {
        value = 0;
        return;
    }
    if (x > v)
        value = v;
    else
        value = x;
}
