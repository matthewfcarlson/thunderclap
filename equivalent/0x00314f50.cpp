// STATUS: equivalent (tools/equiv.py level 3: 2239 inputs, branch coverage 50/50)
// FUN_00314f50 @ 0x00314f50
// Sweep::FUN_00314f50 (this=ecx, ret 8): box-vs-box separating-axis sweep. Generated from the original code
// with work/cq/x87c3.py: the frame is the volatile slot array L[] at the original offsets (E-0xc4..E-4,
// including the compiler's scratch/pointer slots, because the current checker compares the CONTENTS of locals
// passed by pointer and a fuzzed axis index reads those slots), FPU-resident values are recomputed inline from
// volatile reads, slot loads through an index are snapshotted at load time.
#include "compat/ptr.h"
union Wd_314f50 {
    float f;
    unsigned int u;
};

struct V3_314f50 {
    float x, y, z;
    float FUN_0022d110();
};

struct BoxA_314f50 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual V3_314f50 *Center();
};

struct BoxB {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual V3_314f50 *Center();
    void FUN_002fb940(volatile float *out, int idx);
};
typedef BoxA_314f50 VBox;

class Sweep_314f50 {
public:
    char pad0[0xc];
    float f0c;
    float f10;
    float delta[3];
    void FUN_00313540(unsigned order, float a, float b, float c);
    void FUN_003137f0(BoxA_314f50 *a, volatile float *p, unsigned e1, unsigned e2, int axis);
    void FUN_00314be0(BoxA_314f50 *a, volatile float *p, BoxB *b, volatile float *c, unsigned d, volatile float *n);
    void FUN_00314f50(BoxA_314f50 *a, BoxB *b);
};

void Sweep_314f50::FUN_00314f50(BoxA_314f50 *pa, BoxB *pb)
{
    volatile float *T = (volatile float *)this;
    volatile float *A = (volatile float *)pa;
    volatile Wd_314f50 L[49];
    float f11;
    float f22;
    float f26;
    float f35;
    float f36;
    float f37;
    float f46;
    float f47;
    float f48;
    float f7;
    int r10_edx;
    int r12_edx;
    int r13_eax;
    int r14_ecx;
    int r15_ebp;
    int r16_ecx;
    int r17_ecx;
    int r18_eax;
    int r19_ecx;
    int r1_ebp;
    int r20_edx;
    int r21_edx;
    int r23_edx;
    int r24_ecx;
    int r25_edx;
    int r27_edx;
    int r28_edx;
    int r29_ecx;
    int r2_edi;
    int r30_edi;
    int r31_eax;
    int r32_eax;
    int r33_ecx;
    int r38_edx;
    int r39_eax;
    int r3_ecx;
    int r40_edx;
    int r41_eax;
    int r42_eax;
    int r43_eax;
    int r44_ecx;
    int r4_eax;
    int r5_edx;
    int r6_edx;
    int r8_edx;
    int r9_ecx;
    unsigned tmpi, esiv, ecxv; int jo, cnt, kk, n1, n2, special; volatile float *ca, *cb, *cb2;
    volatile float * r34_eax;
    volatile float * r45_ecx;
    ca = (volatile float *)((VBox *)pa)->Center();
    cb = (volatile float *)((VBox *)pb)->Center();
    float l0 = cb[0];
    float l1 = ca[0];
    T[5] = (l0 - l1);
    float l3 = cb[1];
    float l4 = ca[1];
    T[6] = (l3 - l4);
    float l6 = cb[2];
    float l7 = ca[2];
    T[7] = (l6 - l7);
    if (*(volatile int *)&A[14] == 0) {
    r1_ebp = 0;
    r2_edi = 0;
    L[8].f = (((A[23] * T[7]) + (A[22] * T[6])) + (A[21] * T[5]));
    L[9].f = (((A[26] * T[7]) + (A[25] * T[6])) + (A[24] * T[5]));
    L[10].f = (((A[29] * T[7]) + (A[28] * T[6])) + (A[27] * T[5]));
        cnt = 0; jo = 0;
        do {
            ((BoxB *)pb)->FUN_002fb940(&L[2].f, cnt);
    r3_ecx = L[8].u;
    L[0].u = r3_ecx;
    r4_eax = 0x7fffffff;
    r5_edx = r3_ecx & r4_eax;
    L[0].u = r5_edx;
    r6_edx = L[9].u;
    *(volatile float *)((char *)L + 88 + (int)jo*1) = (((L[4].f * A[23]) + (L[3].f * A[22])) + (L[2].f * A[21]));
    L[1].f = (((L[4].f * A[23]) + (L[3].f * A[22])) + (L[2].f * A[21]));
    L[1].u = L[1].u & r4_eax;
    f7 = L[0].f;
    L[0].u = r6_edx;
    r8_edx = r6_edx & r4_eax;
    *(volatile float *)((char *)L + 148 + (int)jo*1) = (f7 - (L[1].f + A[18]));
    L[0].u = r8_edx;
    *(volatile float *)((char *)L + 92 + (int)jo*1) = (((L[4].f * A[26]) + (L[3].f * A[25])) + (L[2].f * A[24]));
    L[1].f = (((L[4].f * A[26]) + (L[3].f * A[25])) + (L[2].f * A[24]));
    L[1].u = L[1].u & r4_eax;
    r9_ecx = L[10].u;
    r10_edx = r9_ecx & r4_eax;
    f11 = L[0].f;
    L[0].u = r9_ecx;
    L[0].u = r10_edx;
    *(volatile float *)((char *)L + 152 + (int)jo*1) = (f11 - (L[1].f + A[19]));
    *(volatile float *)((char *)L + 96 + (int)jo*1) = (((L[4].f * A[29]) + (L[3].f * A[28])) + (L[2].f * A[27]));
    L[1].f = (((L[4].f * A[29]) + (L[3].f * A[28])) + (L[2].f * A[27]));
    L[1].u = L[1].u & r4_eax;
    jo = jo + 12;
    cnt = cnt + 1;
    *(volatile float *)((char *)L + 144 + (int)jo*1) = (L[0].f - (L[1].f + A[20]));
        } while (jo < 0x30);
    } else {
    r12_edx = *(volatile unsigned*)&T[5];
    r13_eax = *(volatile unsigned*)&T[6];
    r14_ecx = *(volatile unsigned*)&T[7];
    L[8].u = r12_edx;
    r15_ebp = 0;
    L[9].u = r13_eax;
    L[10].u = r14_ecx;
        L[6].u = (hulk_uintptr)&L[22].f;
        cnt = 0; jo = 0;
        do {
            ((BoxB *)pb)->FUN_002fb940((volatile float *)L[6].u, cnt);
    float sx90 = *(volatile float *)((char *)L + 88 + (int)jo*1);
    r16_ecx = L[8].u;
    L[0].f = sx90;
    L[1].u = r16_ecx;
    r17_ecx = L[0].u;
    r18_eax = 0x7fffffff;
    r19_ecx = r17_ecx & r18_eax;
    L[0].u = r19_ecx;
    r20_edx = r16_ecx & r18_eax;
    L[1].u = r20_edx;
    r21_edx = L[9].u;
    jo = jo + 12;
    f22 = L[1].f;
    L[1].u = r21_edx;
    r23_edx = r21_edx & r18_eax;
    *(volatile float *)((char *)L + 136 + (int)jo*1) = (f22 - (L[0].f + A[18]));
    L[1].u = r23_edx;
    float sx96 = *(volatile float *)((char *)L + 80 + (int)jo*1);
    L[0].f = sx96;
    L[0].u = L[0].u & r18_eax;
    r24_ecx = L[10].u;
    r25_edx = r24_ecx & r18_eax;
    f26 = L[1].f;
    L[1].u = r24_ecx;
    L[1].u = r25_edx;
    r27_edx = L[6].u;
    *(volatile float *)((char *)L + 140 + (int)jo*1) = (f26 - (L[0].f + A[19]));
    float sx102 = *(volatile float *)((char *)L + 84 + (int)jo*1);
    r28_edx = r27_edx + 12;
    L[0].f = sx102;
    L[6].u = r28_edx;
    L[0].u = L[0].u & r18_eax;
    cnt = cnt + 1;
    *(volatile float *)((char *)L + 144 + (int)jo*1) = (L[1].f - (L[0].f + A[20]));
        } while (jo < 0x30);
    }
    cnt = 0;
    L[6].u = 0;
    L[12].u = (hulk_uintptr)&L[38].f;
    do {
        esiv = L[12].u;
        ((Sweep_314f50 *)T)->FUN_00313540((hulk_uintptr)&L[34].f, ((volatile float *)esiv)[-1], ((volatile float *)esiv)[0], ((volatile float *)esiv)[1]);
        L[15].u = 0;
        do {
            int done = 0;
            do {
    r29_ecx = L[15].u;
    r30_edi = *(volatile unsigned *)((char *)L + 136 + (int)r29_ecx*4);
    r31_eax = r30_edi + cnt*1;
    r32_eax = r31_eax << 2;
    float sx108 = *(volatile float *)((char *)L + 148 + (int)r32_eax*1);
    L[1].u = 0xbf800000;
    L[0].f = sx108;
    float sx109 = *(volatile float *)((char *)L + 88 + (int)r32_eax*1);
    float sx110 = *(volatile float *)((char *)L + 32 + (int)r30_edi*4);
                if (!((-(sx109 * sx110)) < 0.0f))
                    L[1].u = 0x3f800000;
                ((BoxB *)pb)->FUN_002fb940(&L[2].f, L[6].u);
    r33_ecx = r30_edi + r30_edi*2 + 21;
    r34_eax = A + r33_ecx;
    f35 = L[2].f;
    L[2].f = ((f35 * L[1].f) + T[5]);
    f36 = L[3].f;
    L[3].f = ((f36 * L[1].f) + T[6]);
    f37 = L[4].f;
    L[4].f = ((f37 * L[1].f) + T[7]);
    L[7].f = (((L[4].f * r34_eax[2]) + (L[3].f * r34_eax[1])) + (L[2].f * r34_eax[0]));
                if (L[0].f < 0.0f) {
    r38_edx = L[7].u;
    L[5].u = r38_edx;
    r39_eax = L[5].u;
    r40_edx = 0x7fffffff;
    r41_eax = r39_eax & r40_edx;
    L[5].u = r41_eax;
                    if (L[5].f > A[r30_edi + 18])
                        break;
                }
                if (!(L[0].f <= T[3]))
                    break;
                if (!((A[r30_edi + 18] * -2.0f) < L[0].f)) {
    float sx151 = *(volatile float *)((char *)L + 32 + (int)r30_edi*4);
                    if (!((L[7].f * sx151) < 0.0f))
                        break;
                }
                n1 = (int)r30_edi >= 2 ? 0 : r30_edi + 1;
    r42_eax = n1 + cnt*1;
    float sx155 = *(volatile float *)((char *)L + 88 + (int)r42_eax*4);
    float sx157 = *(volatile float *)((char *)L + 32 + (int)n1*4);
    L[14].f = ((L[1].f * sx155) + sx157);
    L[14].u = L[14].u & 0x7fffffff;
    L[5].f = (L[14].f - A[n1 + 18]);
                if (!((L[14].f - A[n1 + 18]) <= (L[0].f > 0.0f ? T[4] : 0.0f)))
                    break;
                n2 = n1 >= 2 ? 0 : n1 + 1;
    r43_eax = n2 + cnt*1;
    float sx165 = *(volatile float *)((char *)L + 88 + (int)r43_eax*4);
    float sx167 = *(volatile float *)((char *)L + 32 + (int)n2*4);
    L[13].f = ((L[1].f * sx165) + sx167);
    L[13].u = L[13].u & 0x7fffffff;
    L[7].f = (L[13].f - A[n2 + 18]);
                if (!((L[13].f - A[n2 + 18]) <= (L[0].f > 0.0f ? T[4] : 0.0f)))
                    break;
    float sx174 = *(volatile float *)((char *)L + 32 + (int)r30_edi*4);
    L[11].u = 0xbf800000;
                if (!(sx174 < 0.0f))
                    L[11].u = 0x3f800000;
                ((BoxB *)pb)->FUN_002fb940(&L[2].f, L[6].u);
                cb2 = (volatile float *)((VBox *)pb)->Center();
    r44_ecx = r30_edi + r30_edi*2 + 21;
    r45_ecx = A + r44_ecx;
    f46 = L[2].f;
    L[2].f = ((f46 * L[1].f) + cb2[0]);
    f47 = L[3].f;
    L[3].f = ((f47 * L[1].f) + cb2[1]);
    f48 = L[4].f;
    L[4].f = ((f48 * L[1].f) + cb2[2]);
    L[19].f = (((-(L[11].f * L[0].f)) * r45_ecx[0]) + L[2].f);
    L[20].f = (((-(L[11].f * L[0].f)) * r45_ecx[1]) + L[3].f);
    L[21].f = (((-(L[11].f * L[0].f)) * r45_ecx[2]) + L[4].f);
                special = (T[3] == T[4]) && (L[0].f > 0.0f) && ((L[5].f > 0.0f) || (L[7].f > 0.0f)) && (((L[7].f > 0.0f ? L[7].f : 0.0f) * (L[7].f > 0.0f ? L[7].f : 0.0f) + (L[5].f > 0.0f ? L[5].f : 0.0f) * (L[5].f > 0.0f ? L[5].f : 0.0f)) + L[0].f * L[0].f > 0.001f);
                if (special) {
                    ((Sweep_314f50 *)T)->FUN_003137f0((BoxA_314f50 *)A, &L[19].f, L[5].u, L[7].u, r30_edi);
    L[16].f = (L[19].f - L[2].f);
    L[17].f = (L[20].f - L[3].f);
    L[18].f = (L[21].f - L[4].f);
                    L[0].f = ((V3_314f50 *)&L[16].f)->FUN_0022d110();
                } else {
    L[16].f = ((-L[11].f) * r45_ecx[0]);
    L[17].f = ((-L[11].f) * r45_ecx[1]);
    L[18].f = ((-L[11].f) * r45_ecx[2]);
                }
                ((Sweep_314f50 *)T)->FUN_00314be0((BoxA_314f50 *)A, &L[19].f, (BoxB *)pb, &L[2].f, L[0].u, &L[16].f);
                done = 1;
            } while (0);
            if (done)
                break;
            kk = L[15].u + 1;
            L[15].u = kk;
        } while (kk < 3);
        esiv = L[6].u + 1;
        ecxv = L[12].u + 12;
        cnt += 3;
        L[6].u = esiv;
        L[12].u = ecxv;
    } while (cnt < 12);
}
