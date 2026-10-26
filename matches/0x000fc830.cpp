#include "decls/data/game/global.h"
// data: gZero_fc830 = DAT_003f32e0

class C_fc830 {
  public:
    char pad[0x12];
    unsigned char flag;
    char pad2;
    float value;
    float Get();
};
float C_fc830::Get() {
    if (flag)
        return DAT_003f32e0;
    return value;
}