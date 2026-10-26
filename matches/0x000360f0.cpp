#include "decls/data/game/global.h"
// data: Zero_360f0 = DAT_003f32e0

class Thing_360f0 {
  public:
    char pad[0x110];
    float value;
    int count;
    bool Target();
};
bool Thing_360f0::Target() {
    if (value > (*(float*)&DAT_003f32e0))
        return true;
    return count > 0;
}