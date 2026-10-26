#include "decls/data/game/global.h"
// data: g_flag_fc1e0 = DAT_004e0a68, g_obj_fc1e0 = DAT_004e0a60

struct Inner_fc1e0 {
    void run(unsigned int, unsigned int);
};
struct Obj_fc1e0 {
    int pad;
    Inner_fc1e0* field;
};
void FUN_000fc1e0(unsigned int a, unsigned int b) {
    (*(Obj_fc1e0**)&DAT_004e0a60)->field->run(a, b);
    (*(unsigned char*)&DAT_004e0a68) = 1;
}