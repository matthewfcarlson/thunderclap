#include "decls/data/game/global.h"
// data: g_flag_203db0 = DAT_004c91d9

class Obj_203db0 {
  public:
    char pad[0x530];
    int values[2];
    char pad2[0x38];
    int keys[2];
    int target(int key);
};
int Obj_203db0::target(int key) {
    int result = 0;
    if ((*(unsigned char*)((char*)&DAT_004c91d8 + 1))) {
        int i;
        for (i = 0; i < 2; ++i) {
            if (keys[i] == key) {
                if (i >= 0)
                    result = *(int*)((char*)this + 0x530 + i * 0x3c);
                break;
            }
        }
    }
    return result;
}
