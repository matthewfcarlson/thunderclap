#include "decls/data/game/global.h"

struct S_fc310 {
    char pad[0x175c];
    int value;
};
extern "C" int FUN_000fc310() {
    return (*(S_fc310**)&DAT_004e0a60)->value;
}