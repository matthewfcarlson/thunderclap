#include "decls/data/game/global.h"
// data: gZero_285a70 = DAT_003f32e0

#include "compat/ptr.h"
struct Data_285a70 {
    char pad[0x10];
    float value;
};
struct Target_285a70 {
    int a;
    int b;
    float result;
    int c;
    int d;
    float one;
    float maxv;
    int e;
    int f;
    unsigned char flag;
    char pad[3];
    Data_285a70* data;
};
void __fastcall FUN_00285a70(Target_285a70* p) {
    p->a = 0;
    p->b = 0;
    hulk_freg v;
    if (p->data == 0 || (v = p->data->value - DAT_003f32dc, v < DAT_003f32e0))
        v = DAT_003f32e0;
    p->result = v;
    p->c = 0;
    p->d = 0;
    p->one = 1.0f;
    p->maxv = 3.402823466e+38F;
    p->e = 0;
    p->f = 0;
    p->flag = 1;
}