// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_003429f0 @ 0x003429f0
struct Block16_3429f0 {
    float v[16];
};

struct Twiddle_3429f0 {
    int pad0;
    float c1;
    char pad8[8];
    float c2;
    float c3;
    // data block arrives in eax
    void FUN_003429f0(Block16_3429f0 *d);
};

// equiv-conv: FUN_003429f0 ecx eax
void Twiddle_3429f0::FUN_003429f0(Block16_3429f0 *d)
{
    float *v = d->v;

    // The original keeps these in its frame as rounded floats (volatile here); everything else is combined in
    // x87 registers (double), including the second stage's sums and differences.
    volatile float d09 = v[0] - v[9];
    volatile float s18 = v[8] + v[1];
    volatile float s90 = v[9] + v[0];
    volatile float d18 = v[1] - v[8];

    volatile float m10 = ((v[4] - v[13]) - (v[12] + v[5])) * c1;
    double s125 = v[12] + v[5];             // the listing adds the two pairs: MSVC 7.1 regroups a + b + (c - d)
    volatile float m11 = (s125 + (v[4] - v[13])) * c1;
    volatile float m12 = ((v[13] + v[4]) - (v[5] - v[12])) * c1;
    double s134 = v[13] + v[4];
    volatile float m1 = ((v[5] - v[12]) + s134) * c1;

    volatile float a19 = (v[2] - v[11]) * c2 - (v[3] + v[10]) * c3;
    volatile float a18 = (v[3] + v[10]) * c2 + (v[2] - v[11]) * c3;
    volatile float a17 = (v[11] + v[2]) * c3 - (v[3] - v[10]) * c2;
    volatile float a16 = (v[11] + v[2]) * c2 + (v[3] - v[10]) * c3;
    volatile float a15 = (v[6] - v[15]) * c3 - (v[7] + v[14]) * c2;
    volatile float a14 = (v[6] - v[15]) * c2 + (v[7] + v[14]) * c3;
    volatile float a13 = (v[15] + v[6]) * c2 - (v[7] - v[14]) * c3;
    double a2 = (v[7] - v[14]) * c2 + (v[15] + v[6]) * c3;

    double f3 = m10 + d09;
    double f21 = m11 + s18;
    double f20 = a15 + a19;
    volatile float f22 = a14 + a18;
    v[0] = f20 + f3;
    v[1] = f22 + f21;
    v[2] = f3 - f20;
    v[3] = f21 - f22;

    double g10 = d09 - m10;
    double g11 = s18 - m11;
    double g19 = a19 - a15;
    double g18 = a18 - a14;
    v[4] = g10 - g18;
    v[5] = g19 + g11;
    v[6] = g18 + g10;
    v[7] = g11 - g19;

    double h4 = s90 - m1;
    double h10 = m12 + d18;
    double h5 = a17 - a13;
    volatile float h3 = a16 - a2;
    v[8] = h5 + h4;
    v[9] = h3 + h10;
    v[10] = h4 - h5;
    v[11] = h10 - h3;

    double i1 = m1 + s90;
    volatile float i12 = d18 - m12;
    volatile float i13 = a13 + a17;
    double i2 = a2 + a16;
    v[12] = i1 - i2;
    v[13] = i13 + i12;
    v[14] = i2 + i1;
    v[15] = i12 - i13;
}
