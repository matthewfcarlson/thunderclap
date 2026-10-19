// STATUS: equivalent (tools/equiv.py level 3: 13934 inputs, branch coverage 4/4)
// FUN_0030be90 @ 0x0030be90
   // 0.0f
#include "decls/data/game/global.h"

class Contact_30be90 {
public:
    char pad00[0x98];
    float a98, a9c, aa0;     // 0x98
    char pada4[0x54];
    unsigned char flagF8;    // 0xf8
    char padf9[3];
    float b0fc, b100, b104;  // 0xfc
    char pad108[0x30];
    float n138, n13c, n140;  // 0x138
    char pad144[0x10];
    float f154;              // 0x154
    float f158;              // 0x158
    void FUN_0030be90();
};

struct ThisCall_0030ad10 {
    void FUN_0030ad10(int mode, float *out);
};

void Contact_30be90::FUN_0030be90() {
    ((ThisCall_0030ad10*)(this))->FUN_0030ad10(flagF8, &f154);
    f158 = aa0 * n140 + a9c * n13c + a98 * n138;
    if (flagF8) {
        float d = b104 * n140 + b100 * n13c + b0fc * n138;
        if (d < 0.0f)
            f154 = -f154;
    }
}
