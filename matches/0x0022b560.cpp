#include "decls/data/game/Render.h"
// data: gZero_22b560 = DAT_00421a78

struct Vec4_22b560 {
    float x, y, z, w;
    Vec4_22b560* FlipIf(Vec4_22b560*);
};
Vec4_22b560* Vec4_22b560::FlipIf(Vec4_22b560* b) {
    if (b->w * w + b->z * z + b->y * y + b->x * x < (*(double*)&DAT_00421a78)) {
        x = -x;
        y = -y;
        z = -z;
        w = -w;
    }
    return this;
}