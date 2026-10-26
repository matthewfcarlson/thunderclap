// Same code shape as 0x000fc1e0 (propagated; names are from that function)
#include "decls/data/game/global.h"
// data: g_flag_fc220 = DAT_004e0a68, g_obj_fc220 = DAT_004e0a60

struct Inner_fc220 {
    void run(unsigned int, unsigned int);
};
struct Obj_fc220 {
    int pad;
    Inner_fc220* field;
};
void FUN_000fc220(unsigned int a, unsigned int b) {
    (*(Obj_fc220**)&DAT_004e0a60)->field->run(a, b);
    (*(unsigned char*)&DAT_004e0a68) = 1;
}