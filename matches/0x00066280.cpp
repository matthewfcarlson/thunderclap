#include "decls/address.h"
#include "decls/data/game/hulkfight.h"
#include "gen/owners.h"
struct World {
    char pad[0x2c];
    int value;
};
extern "C" float __fastcall Run(int);
float owners::Obj_66280::FUN_00066280() {
    if (!enabled)
        return DAT_003f3388;
    if (!cached) {
        cached = DAT_004dd700->value;
        if (!cached)
            return DAT_003f3388;
    }
    return Run(enabled);
}