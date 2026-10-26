#include "decls/data/game/global.h"
// data: gOne_3ebb0 = DAT_003f32dc, gZero_3ebb0 = DAT_003f32e0

class ClampOwner {
  public:
    char pad[0x1e58];
    float mValue;
    int mKey;
    float Get(int key);
};

float ClampOwner::Get(int key) {
    float value = mValue;
    if (key != mKey)
        return DAT_003f32e0;
    if (value >= DAT_003f32e0 && value <= DAT_003f32dc)
        return value;
    if (value > DAT_003f32dc)
        return DAT_003f32dc;
    return DAT_003f32e0;
}
