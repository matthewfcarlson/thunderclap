#include "gen/owners.h"
struct ThisCall_001e9960 {
    void* FUN_001e9960(int);
};
void owners::Obj_1e9b00::FUN_001e9b00(hulk_intptr x) {
    void* p = ((ThisCall_001e9960*)(this))->FUN_001e9960(((int)x));
    if (p)
        value = p;
}