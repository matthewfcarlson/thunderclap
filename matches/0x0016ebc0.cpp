#include "decls/data/game/unknown.h"

class Obj {
    char pad[0x34];
    volatile float x;
    float y;
    volatile float z;

  public:
    unsigned char Set(const volatile float* p);
};
unsigned char Obj::Set(const volatile float* p) {
    float a = p[0] * (*(float*)&DAT_003f32b8);
    float b = p[1] * (*(float*)&DAT_003f32b8);
    volatile float c[3];
    c[2] = p[2] * (*(float*)&DAT_003f32b8);
    z = c[2];
    x = a;
    y = b;
    return 1;
}