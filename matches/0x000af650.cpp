#include "decls/data/game/global.h"
// data: gFlag_af650 = DAT_004dda3d
#include "gen/owners.h"

void owners::Obj_af650::FUN_000af650(int index, unsigned int element, float value) {
    if (enabled && element < (unsigned int)data[index * 12]) {
        if ((*(unsigned char*)&DAT_004dda3d))
            data[index * 12 + element + 5] = 0;
        *(float*)(data + index * 12 + element + 3) = value;
    }
}