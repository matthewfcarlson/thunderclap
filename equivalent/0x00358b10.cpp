// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_00358b10 @ 0x00358b10
// FUN_00358b10: sphere sweep test against a capsule/segment (11 stack args, cdecl, bool result).
// Generated from the original x87 code with work/cq/x87c3.py: locals live in one volatile slot array L[]
// at the original frame offsets (E-0x98 .. E-4); values the original keeps unrounded on the FPU stack are
// recomputed inline from volatile reads, values it stores to the stack are written to L[] (rounded).
extern "C" double sqrt(double);
extern "C" float fabsf(float);

struct V3_358b10 {
    float x, y, z;
    void FUN_000111b0(const V3_358b10 *a, const V3_358b10 *b);
    void FUN_0022d180();
    float FUN_00018990();
};

union Wd_358b10 {
    float f;
    unsigned int u;
};

bool FUN_00358630(volatile float *p, volatile float *dir, float r, float t, int flag, float d, volatile float *n, volatile float *out);
bool FUN_00357960(volatile float *a, volatile float *dir, float t2, volatile float *p5, int a6, int a7, volatile float *n, volatile float *o9, volatile float *o10, volatile float *o11);
void FUN_00358030(volatile float *a, volatile float *dir, int flag, volatile float *p5, int a6, int a7, volatile float *o8c, volatile float *o20, volatile float *o44, volatile float *o4, volatile float *o64, int f1, int f2, int f3);
void FUN_0022de70(volatile float *a, volatile float *b, volatile float *p5, volatile float *p8, volatile float *o50, volatile float *o8);
bool FUN_003577c0(volatile float *out, volatile float *p5, int a6, int a7, volatile float *p8);
volatile float *FUN_00083e00(volatile float *out, volatile float *dir, float t);

bool FUN_00358b10(volatile float *a1, volatile float *a2, float a3, float a4, volatile float *a5, int a6, int a7,
                  volatile float *a8, volatile float *a9, volatile float *a10, volatile float *a11)
{
    volatile Wd_358b10 L[38];
    double len;
    int r10_edx;
    int r11_edx;
    int r12_eax;
    int r13_ecx;
    int r14_ecx;
    int r15_edx;
    int r16_edx;
    int r17_ecx;
    int r18_edx;
    int r19_eax;
    int r1_edx;
    int r20_ecx;
    int r21_eax;
    int r24_eax;
    int r25_eax;
    int r26_ecx;
    int r27_edx;
    int r28_eax;
    int r29_ecx;
    int r2_ecx;
    int r30_ecx;
    int r31_edx;
    int r32_ecx;
    int r35_ecx;
    int r36_ecx;
    int r37_edx;
    int r38_edx;
    int r39_edx;
    int r3_edx;
    int r40_eax;
    int r4_eax;
    int r5_ecx;
    int r6_eax;
    int r8_ecx;
    int r9_edx;
    volatile float *r1;
    volatile float ARGac;
    volatile float ARGb4;
    volatile float f22;
    volatile float f23;
    volatile float f33;
    volatile float f34;
    volatile float f7;
    r1_edx = *(volatile unsigned*)&a3;
    r2_ecx = *(volatile unsigned*)&a4;
    ARGb4 = (-(((a8[2] * a5[2]) + (a8[1] * a5[1])) + (a8[0] * a5[0])));
    if (!FUN_00358630(a1, a2, a3, a4, 1, ARGb4, a8, &L[14].f))
        return 0;
    r3_edx = a7;
    r4_eax = a6;
    L[23].f = (a4 * a2[2]);
    L[15].f = (a1[0] - (a4 * a2[0]));
    L[16].f = (a1[1] - (a4 * a2[1]));
    L[17].f = (a1[2] - L[23].f);
    L[0].f = (a4 + a4);
    r5_ecx = L[0].u;
    if (FUN_00357960(&L[15].f, a2, L[0].f, a5, a6, a7, a8, a9, a10, a11)) {
    r6_eax = L[14].u;
    *(volatile unsigned*)&a9[0] = r6_eax;
        return 1;
    }
    FUN_00358030(&L[15].f, a2, 0, a5, a6, a7, &L[3].f, &L[30].f, &L[21].f, &L[37].f, &L[13].f, 1, 1, 1);
    if (0.0f < L[3].f && L[3].f < L[0].f) {
    volatile float l38 = a2[1];
    L[6].f = (L[3].f * a2[2]);
    L[10].f = ((L[3].f * a2[0]) + L[15].f);
    f7 = L[6].f;
    L[6].f = (L[23].f * L[13].f);
    L[7].f = (L[30].f + (L[21].f * L[13].f));
    r8_ecx = L[7].u;
    *(volatile unsigned*)&a10[0] = r8_ecx;
    L[9].f = (L[32].f + L[6].f);
    a10[1] = (L[31].f + (L[22].f * L[13].f));
    a10[2] = (L[32].f + L[6].f);
    L[4].f = (L[10].f - L[7].f);
    L[5].f = (((L[3].f * l38) + L[16].f) - (L[31].f + (L[22].f * L[13].f)));
    a9[0] = sqrt((((L[4].f * L[4].f) + (((f7 + L[17].f) - L[9].f) * ((f7 + L[17].f) - L[9].f))) + (L[5].f * L[5].f)));
        if (sqrt((((L[4].f * L[4].f) + (((f7 + L[17].f) - L[9].f) * ((f7 + L[17].f) - L[9].f))) + (L[5].f * L[5].f))) < a3) {
    r9_edx = *(volatile unsigned*)&a8[0];
    *(volatile unsigned*)&a11[0] = r9_edx;
    r10_edx = *(volatile unsigned*)&a8[1];
    *(volatile unsigned*)&a11[1] = r10_edx;
    r11_edx = *(volatile unsigned*)&a8[2];
    *(volatile unsigned*)&a11[2] = r11_edx;
    r12_eax = L[14].u;
    *(volatile unsigned*)&a9[0] = r12_eax;
        return 1;
        }
    }
    L[9].f = (a4 * a2[2]);
    L[4].f = ((a4 * a2[0]) + a1[0]);
    L[6].f = (L[9].f + a1[2]);
    L[1].f = ((((L[17].f * a8[2]) + (L[16].f * a8[1])) + (L[15].f * a8[0])) - (((a8[2] * a5[2]) + (a8[1] * a5[1])) + (a8[0] * a5[0])));
    r13_ecx = L[1].u;
    r14_ecx = r13_ecx & 0x7fffffff;
    L[2].u = r14_ecx;
    L[1].f = ((((L[6].f * a8[2]) + (((a4 * a2[1]) + a1[1]) * a8[1])) + (L[4].f * a8[0])) - (((a8[2] * a5[2]) + (a8[1] * a5[1])) + (a8[0] * a5[0])));
    r15_edx = L[1].u;
    r16_edx = r15_edx & 0x7fffffff;
    L[1].u = r16_edx;
    if (L[2].f < L[1].f) {
    r17_ecx = L[16].u;
    r18_edx = L[17].u;
    r19_eax = L[15].u;
    L[28].u = r17_ecx;
    L[29].u = r18_edx;
        L[27].u = r19_eax;
    } else {
    r20_ecx = L[6].u;
    L[28].f = ((a4 * a2[1]) + a1[1]);
    r21_eax = L[4].u;
    L[29].u = r20_ecx;
        L[27].u = r21_eax;
    }
    L[24].f = ((a8[1] * a2[2]) - (a8[2] * a2[1]));
    L[26].f = ((a8[0] * a2[1]) - (a8[1] * a2[0]));
    f22 = L[24].f;
    f23 = L[24].f;
    L[24].f = ((((a8[2] * a2[0]) - (a8[0] * a2[2])) * a2[2]) - (L[26].f * a2[1]));
    L[25].f = ((((a8[0] * a2[1]) - (a8[1] * a2[0])) * a2[0]) - (f23 * a2[2]));
    L[26].f = ((f22 * a2[1]) - (((a8[2] * a2[0]) - (a8[0] * a2[2])) * a2[0]));
    FUN_0022de70(&L[27].f, &L[24].f, a5, a8, &L[18].f, &L[36].f);
    r24_eax = L[36].u;
    L[0].u = r24_eax;
    r25_eax = r24_eax & 0x7fffffff;
    L[0].u = r25_eax;
    if (L[0].f > a3)
        return 0;
    if (FUN_003577c0(&L[18].f, a5, a6, a7, a8)) {
    r26_ecx = L[18].u;
    r27_edx = L[19].u;
    r28_eax = L[20].u;
    *(volatile unsigned*)&a10[0] = r26_ecx;
    r29_ecx = L[14].u;
    *(volatile unsigned*)&a10[1] = r27_edx;
    *(volatile unsigned*)&a10[2] = r28_eax;
    *(volatile unsigned*)&a9[0] = r29_ecx;
    r30_ecx = *(volatile unsigned*)&a8[0];
    *(volatile unsigned*)&a11[0] = r30_ecx;
    r31_edx = *(volatile unsigned*)&a8[1];
    *(volatile unsigned*)&a11[1] = r31_edx;
    r32_ecx = *(volatile unsigned*)&a8[2];
    *(volatile unsigned*)&a11[2] = r32_ecx;
        return 1;
    }
    ((V3_358b10 *)&L[10].f)->FUN_000111b0((V3_358b10 *)a2, (V3_358b10 *)a8);
    L[2].f = (((L[12].f * L[12].f) + (L[11].f * L[11].f)) + (L[10].f * L[10].f));
    L[0].f = ((((L[12].f * (L[20].f - L[29].f)) + ((L[19].f - L[28].f) * L[11].f)) + ((L[18].f - L[27].f) * L[10].f)) + (((L[12].f * (L[20].f - L[29].f)) + ((L[19].f - L[28].f) * L[11].f)) + ((L[18].f - L[27].f) * L[10].f)));
    if (!(1e-5f < ((((((L[12].f * (L[20].f - L[29].f)) + ((L[19].f - L[28].f) * L[11].f)) + ((L[18].f - L[27].f) * L[10].f)) + (((L[12].f * (L[20].f - L[29].f)) + ((L[19].f - L[28].f) * L[11].f)) + ((L[18].f - L[27].f) * L[10].f))) * L[0].f) - (((((((L[20].f - L[29].f) * (L[20].f - L[29].f)) + ((L[19].f - L[28].f) * (L[19].f - L[28].f))) + ((L[18].f - L[27].f) * (L[18].f - L[27].f))) - (a3 * a3)) * L[2].f) * 4.0f))))
        return 0;
    L[1].f = sqrt(((((((L[12].f * (L[20].f - L[29].f)) + ((L[19].f - L[28].f) * L[11].f)) + ((L[18].f - L[27].f) * L[10].f)) + (((L[12].f * (L[20].f - L[29].f)) + ((L[19].f - L[28].f) * L[11].f)) + ((L[18].f - L[27].f) * L[10].f))) * L[0].f) - (((((((L[20].f - L[29].f) * (L[20].f - L[29].f)) + ((L[19].f - L[28].f) * (L[19].f - L[28].f))) + ((L[18].f - L[27].f) * (L[18].f - L[27].f))) - (a3 * a3)) * L[2].f) * 4.0f)));
    f33 = L[2].f;
    f34 = f33;
    L[2].f = (f34 + f34);
    ARGac = ((L[1].f - L[0].f) / L[2].f);
    r1 = FUN_00083e00(&L[33].f, &L[10].f, ARGac);
    L[7].f = (L[18].f + r1[0]);
    L[8].f = (L[19].f + r1[1]);
    L[9].f = (L[20].f + r1[2]);
    r35_ecx = L[9].u;
    L[6].u = r35_ecx;
    L[4].f = (L[18].f + r1[0]);
    L[5].f = (L[19].f + r1[1]);
    ARGac = (((-L[0].f) - L[1].f) / L[2].f);
    r1 = FUN_00083e00(&L[33].f, &L[10].f, ARGac);
    L[35].f = (L[20].f + r1[2]);
    L[10].f = ((L[18].f + r1[0]) - L[7].f);
    L[11].f = ((L[19].f + r1[1]) - L[8].f);
    L[12].f = (L[35].f - L[9].f);
    ((V3_358b10 *)&L[10].f)->FUN_0022d180();
    FUN_00358030(&L[4].f, &L[10].f, 1, a5, a6, a7, &L[3].f, &L[30].f, &L[21].f, &L[37].f, &L[13].f, 1, 1, 1);
    r1 = FUN_00083e00(&L[33].f, &L[10].f, L[3].f);
    r36_ecx = L[13].u;
    L[7].f = (L[4].f + r1[0]);
    L[8].f = (L[5].f + r1[1]);
    L[9].f = (L[6].f + r1[2]);
    r1 = FUN_00083e00(&L[33].f, &L[21].f, L[13].f);
    volatile float l271 = r1[0];
    volatile float l274 = r1[1];
    volatile float l277 = r1[2];
    L[35].f = (L[32].f + l277);
    a10[0] = (L[30].f + l271);
    a10[1] = (L[31].f + l274);
    a10[2] = (L[32].f + l277);
    L[21].f = (L[7].f - (L[30].f + l271));
    L[22].f = (L[8].f - (L[31].f + l274));
    L[23].f = (L[9].f - L[35].f);
    len = ((V3_358b10 *)&L[21].f)->FUN_00018990();
    a9[0] = len;
    if (!(len < 0.1f))
        return 0;
    r37_edx = *(volatile unsigned*)&a8[0];
    *(volatile unsigned*)&a11[0] = r37_edx;
    r38_edx = *(volatile unsigned*)&a8[1];
    *(volatile unsigned*)&a11[1] = r38_edx;
    r39_edx = *(volatile unsigned*)&a8[2];
    *(volatile unsigned*)&a11[2] = r39_edx;
    r40_eax = L[14].u;
    *(volatile unsigned*)&a9[0] = r40_eax;
        return 1;
}
