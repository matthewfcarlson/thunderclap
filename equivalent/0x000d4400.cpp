// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 17/18, incomplete)
// FUN_000d4400 @ 0x000d4400
#include "decls/data/game/global.h"

struct Accum {
    char pad0[0x220];
    float sum0;        // 0x220
    float sum1;        // 0x224
    float sum2;        // 0x228
    char pad22c[0x8];
    float damp0;       // 0x234
    char pad238[8];
    int id0;           // 0x240
    int count0;        // 0x244
    char flag0;
    char pad249[0x213];
    float sum3;        // 0x45c
    float sum4;        // 0x460
    float sum5;        // 0x464
    char pad468[8];
    float damp1;       // 0x470
    char pad474[8];
    int id1;           // 0x47c
    int count1;        // 0x480
    char flag1;        // 0x484

    void FUN_000d4400(int id, float amount);
};

void Accum::FUN_000d4400(int id, float amount)
{
    float x = id ? -amount : amount;
    float v0 = 0.0f;
    float v1 = x;
    float v2 = 0.0f;

    if (flag0 && id0 == id) {
        float scale = (*(float*)&DAT_003f32dc);
        if (id == 0)
            scale = DAT_004a06bc;
        float w0 = v0, w1 = v1, w2 = v2;
        if (count0 < 1) {
            damp0 = scale * damp0;
            count0++;
        } else {
            w0 *= scale;
            w1 *= scale;
            w2 = scale * w2;
        }
        sum0 = w0 + sum0;
        sum1 = w1 + sum1;
        sum2 = w2 + sum2;
    }
    if (flag1 && id1 == id) {
        float scale = (*(float*)&DAT_003f32dc);
        if (id == 0)
            scale = DAT_004a06bc;
        float w0 = v0, w1 = v1, w2 = v2;
        if (count1 < 1) {
            damp1 = scale * damp1;
            count1++;
        } else {
            w0 *= scale;
            w1 *= scale;
            w2 = scale * w2;
        }
        sum3 = w0 + sum3;
        sum4 = w1 + sum4;
        sum5 = w2 + sum5;
    }
}
