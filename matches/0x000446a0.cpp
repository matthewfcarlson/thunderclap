#include "decls/data/game/global.h"
// data: gZero_446a0 = DAT_003f32e0

class C_446a0 {
    char pad[0xd0];

  public:
    float Get(int index);
};
float C_446a0::Get(int index) {
    if (index == 0)
        return DAT_003f32e0;
    return *(float*)((char*)this + 0xd0 + index * 4);
}