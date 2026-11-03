// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 17/18, incomplete)
// FUN_000d4400 @ 0x000d4400
#include "decls/data/game/global.h"
#include "gen/owners.h"


void owners::Accum_d4400::FUN_000d4400(int id, float amount)
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
