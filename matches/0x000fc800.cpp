#include "decls/data/game/global.h"
// data: threshold_fc800 = DAT_003f5d00

typedef unsigned char u8;
struct Obj_fc800 {
    char pad[0x10];
    u8 flag10;
    char pad11;
    u8 flag12;
    char pad13;
    float value;
    bool Target();
};
bool Obj_fc800::Target() {
    if (flag12)
        return true;
    if (!(value < DAT_003f5d00) && !flag10)
        return false;
    return true;
}