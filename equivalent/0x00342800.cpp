// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0; --wine 600 inputs)
// FUN_00342800 @ 0x00342800
#include "compat/ptr.h"
struct Block16_342800 {
    float v[16];
};

struct Scaler_342800 {
    int pad0;
    float scale;
    // data block arrives in eax
    void FUN_00342800(Block16_342800* d);
};

// equiv-conv: FUN_00342800 ecx eax
void Scaler_342800::FUN_00342800(Block16_342800* d)
{
    float S = scale;
    float* v = d->v;
    float tmp[13];

    // first half: elements 0,1,4,5,8,9,12,13
    hulk_freg A0 = v[8] + v[0];
    hulk_freg A1 = v[1] + v[9];
    float B0 = v[0] - v[8];
    float B1 = v[1] - v[9];
    hulk_freg C0 = v[4] + v[12];
    float C1 = v[5] + v[13];
    float D0 = v[4] - v[12];
    float D1 = v[5] - v[13];
    float s1c = C0 + A0;
    float s24 = C1 + A1;
    float s30 = A0 - C0;
    hulk_freg X1 = A1 - C1;
    hulk_freg E = B0 - D1;
    hulk_freg F = D0 + B1;
    float G = D1 + B0;
    float H = B1 - D0;

    // second half: elements 2,3,6,7,10,11,14,15
    hulk_freg A0b = v[2] + v[10];
    hulk_freg A1b = v[3] + v[11];
    float B0b = v[2] - v[10];
    float B1b = v[3] - v[11];
    hulk_freg C0b = v[6] + v[14];
    float C1b = v[7] + v[15];
    float D0b = v[6] - v[14];
    float D1b = v[7] - v[15];
    float s20 = C0b + A0b;
    float s28 = C1b + A1b;
    float s34 = A0b - C0b;
    float X1b = A1b - C1b;
    hulk_freg Eb = B0b - D1b;
    hulk_freg Fb = D0b + B1b;
    float Gb = D1b + B0b;
    float Hb = B1b - D0b;

    float P = (Eb - Fb) * S;
    hulk_freg Q = (Fb + Eb) * S;
    float R = (Gb - Hb) * S;
    float T = (Hb + Gb) * S;

    v[8] = P + E;
    v[9] = Q + F;
    v[10] = E - P;
    v[11] = F - Q;
    v[12] = G - T;
    v[13] = R + H;
    v[14] = T + G;
    v[15] = H - R;
    v[0] = s20 + s1c;
    v[1] = s28 + s24;
    v[2] = s1c - s20;
    v[3] = s24 - s28;
    v[4] = s30 - X1b;
    v[5] = s34 + X1;
    v[6] = X1b + s30;
    v[7] = X1 - s34;
}
