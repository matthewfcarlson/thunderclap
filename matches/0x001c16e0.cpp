#include "decls/data/game/Render/Canvas.h"

struct Snd_1c16e0 {
    virtual void v0();
    virtual void Play(int, float, float, unsigned char);
};
class Obj_1c16e0 {
  public:
    char p[0xd0];
    float a;
    float b;
    unsigned char c;
    void Set(float x, float y);
};
void Obj_1c16e0::Set(float x, float y) {
    a = x;
    b = y;
    if (x != 0.0f && (*(Snd_1c16e0**)&DAT_004e2318)) {
        (*(Snd_1c16e0**)&DAT_004e2318)->Play(1, x, y, c);
        return;
    }
    (*(Snd_1c16e0**)&DAT_004e2318)->Play(0, x, y, c);
}
