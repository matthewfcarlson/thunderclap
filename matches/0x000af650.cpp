#include "decls/data/game/global.h"
// data: gFlag_af650 = DAT_004dda3d

class Obj_af650 {
  public:
    char pad0[8];
    unsigned char enabled;
    char pad9[0x14 - 9];
    int* data;
    void Set(int, unsigned int, float);
};
void Obj_af650::Set(int index, unsigned int element, float value) {
    if (enabled && element < (unsigned int)data[index * 12]) {
        if ((*(unsigned char*)&DAT_004dda3d))
            data[index * 12 + element + 5] = 0;
        *(float*)(data + index * 12 + element + 3) = value;
    }
}