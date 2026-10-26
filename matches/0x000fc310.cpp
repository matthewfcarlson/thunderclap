#include "decls/data/game/global.h"

struct S_fc310 {
    char pad[0x175c];
    int value;
};
int f() {
    return (*(S_fc310**)&DAT_004e0a60)->value;
}