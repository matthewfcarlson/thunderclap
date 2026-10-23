// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_002ece90 @ 0x002ece90
#include "decls/data/engine/physics.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"

extern "C" double sqrt(double);

struct Listener_2ece90 {
    void FUN_002f7a60();
};
struct SystemA {
    char pad00[0x68];
    Listener_2ece90 listener;
};
struct SystemB {
    char pad00[0xb0];
    Listener_2ece90 listener;
};

class ScaledVec {
public:
    char pad00[0x10];
    float x, y, z;
    float sx, sy, sz;
    float length;
    void Set(float vx, float vy, float vz);
};

void ScaledVec::Set(float vx, float vy, float vz)
{
    x = vx;
    y = vy;
    z = vz;
    sx = DAT_004d287c * x;
    sy = DAT_004d287c * y;
    sz = DAT_004d287c * z;
    // sx..sz are read back from memory (rounded to float), as the original does
    const float *p = &sx;
    length = (float)sqrt(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]);
    if ((*(SystemA**)&DAT_0055547c)) {
        (*(SystemA**)&DAT_0055547c)->listener.FUN_002f7a60();
    } else if ((*(SystemB**)&DAT_00554c14)) {
        (*(SystemB**)&DAT_00554c14)->listener.FUN_002f7a60();
    }
}
