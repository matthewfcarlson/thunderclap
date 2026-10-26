#include "decls/data/game/global.h"

typedef unsigned int u32_fc100;
struct Obj_fc100 {
    void F5(u32_fc100, u32_fc100);
    void F0(u32_fc100);
};
void Target(u32_fc100 a, u32_fc100 b) {
    (*(Obj_fc100**)&DAT_004e0a60)->F5(a, b);
    (*(Obj_fc100**)&DAT_004e0a60)->F0(a);
}
