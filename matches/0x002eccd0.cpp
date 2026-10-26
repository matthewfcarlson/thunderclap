#include "decls/data/engine/physics.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
// data: gEnabled_2eccd0 = DAT_00554c0c, kScale_2eccd0 = DAT_004d287c

struct Sub2_2eccd0 {
    void Do();
};

struct PA {
    char pad0[0x38];
    float f38;
    char pad1[0x2c];
    Sub2_2eccd0 s;
};

struct PB {
    char pad0[0x80];
    float f80;
    char pad1[0x2c];
    Sub2_2eccd0 s;
};


class Cls_2eccd0 {
  public:
    char pad[0x2c];
    float a;
    float b;
    void Set(float f);
};

void Cls_2eccd0::Set(float f) {
    a = f;
    if (!DAT_00554c0c)
        return;
    b = (*(const float*)&DAT_004d287c) * f;
    if ((*(PA**)&DAT_0055547c)) {
        (*(PA**)&DAT_0055547c)->s.Do();
        (*(PA**)&DAT_0055547c)->f38 = b;
    } else if ((*(PB**)&DAT_00554c14)) {
        (*(PB**)&DAT_00554c14)->s.Do();
        (*(PB**)&DAT_00554c14)->f80 = b;
    }
}
