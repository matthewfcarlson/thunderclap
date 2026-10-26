#include "decls/data/game/global.h"
// data: gDefault = DAT_003f32e0

class CScenarioManager_1cc990 {
  public:
    char pad[0x10];
    float values[0x40];
    float GetFloat(int index);
};

float CScenarioManager_1cc990::GetFloat(int index) {
    if (index >= 0 && index < 0x40)
        return values[index];
    return DAT_003f32e0;
}
