// STATUS: equivalent (tools/equiv.py level 3: 19928 inputs, branch coverage 32/32)
// CControllerAgent::vfunc_4 @ 0x000fd0f0
// CControllerAgent::vfunc_4 (ret 0xc, three stack args): controller facing/aim update. Generated from the
// original code with work/cq/x87c3.py; `this` is addressed through the volatile float view T, the frame is the
// volatile slot array L[] at the original offsets, FPU-resident values are recomputed inline from volatile
// reads. FUN_000fce60 takes an implicit edi (equiv-conv).
extern "C" double sqrt(double);
extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

union Wd {
    float f;
    unsigned int u;
};

struct V3x { float FUN_0022d110(); };
struct Cls3660 { void FUN_000b3660(unsigned a); };
struct Cls3d20 { unsigned FUN_000b3d20(unsigned a); };
struct Cls1c38f0 { void FUN_001c38f0(unsigned a, unsigned b); };
struct Cls1c3990 { unsigned FUN_001c3990(); };
struct Cls1c3950 { void FUN_001c3950(unsigned a, unsigned b); };
struct VFight {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual VFight *v6();
};

extern float DAT_004a1aac;
extern float DAT_004a1ab0;
unsigned FUN_001c3d90();
float FUN_00018a20(float x);
// equiv-conv: FUN_000fce60 edi stack stack stack stack stack stack stack
void FUN_000fce60(unsigned a_edi, unsigned s1, unsigned s2, unsigned s3, unsigned s4, unsigned s5, unsigned s6, unsigned s7);
void FUN_000fd010(unsigned s1, unsigned s2, unsigned s3, unsigned s4, unsigned s5, unsigned s6);

class CControllerAgent {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4(unsigned a1, unsigned a2, unsigned a3);
    void FUN_000fc550(unsigned a, unsigned b, unsigned c);
};

void CControllerAgent::vfunc_4(unsigned a1, unsigned a2, unsigned a3)
{
    volatile float *T = (volatile float *)this;
    volatile Wd L[58];
    double A2;
    double ang;
    float D18a;
    float flen;
    int r11_eax;
    int r12_ecx;
    int r13_edx;
    int r14_esi;
    int r15_eax;
    int r16_eax;
    int r17_ecx;
    int r18_edx;
    int r1_ecx;
    int r2_edx;
    int r3_ecx;
    int r4_eax;
    int r5_eax;
    int r7_edx;
    int r8_eax;
    int r9_ecx;
    unsigned ebpv, ebxv;
    unsigned esiv, ediv;
    unsigned fgt, infov, objb, ev, tmpi, sv, rr;
    volatile float * r10_edx;
    volatile float * r6_ecx;
    volatile float ARGfc;
    FUN_000fc550(a1, a2, a3);
    fgt = (unsigned)((VFight *)*(volatile unsigned *)&T[22])->v6();
    if (*(volatile unsigned *)((char *)fgt + 0x140) == 4) {
        L[17].u = *(volatile unsigned *)((char *)fgt + 0x1af8);
        L[18].u = *(volatile unsigned *)((char *)fgt + 0x1afc);
        L[19].u = *(volatile unsigned *)((char *)fgt + 0x1b00);
        L[18].u = 0;
        ((V3x *)&L[17].f)->FUN_0022d110();
    } else {
        L[17].u = 0;
        L[18].u = 0x3f800000;
        L[19].u = 0;
    }
    infov = fgt + 0x1f58;
    sv = *(volatile unsigned *)((char *)fgt + 0x20a8);
    L[16].u = infov;
    if ((int)sv >= 0 && (int)sv < 4)
        ((Cls3660 *)((Cls3d20 *)*(volatile unsigned *)((char *)a1 + 4))->FUN_000b3d20(sv))->FUN_000b3660(infov);
    objb = FUN_001c3d90();
    r1_ecx = *(volatile unsigned*)&((volatile float *)infov)[42];
    r2_edx = *(volatile unsigned*)&((volatile float *)infov)[55];
    L[3].u = r1_ecx;
    r3_ecx = *(volatile unsigned*)&((volatile float *)infov)[40];
    r4_eax = *(volatile unsigned*)&((volatile float *)infov)[41];
    L[12].u = r3_ecx;
    L[4].u = r4_eax;
    {
        int reset;
    r5_eax = *(volatile unsigned*)&((volatile float *)infov)[56];
    L[1].u = r5_eax;
    L[11].u = r2_edx;
        reset = (L[12].f < T[53]);
        if (!reset) {
            L[0].u = *(volatile unsigned *)((char *)infov + 0xa0) & 0x7fffffff;
            reset = (L[0].f <= 1e-5f);
            if (!reset) {
                L[0].u = *(volatile unsigned *)((char *)this + 0xd4) & 0x7fffffff;
                reset = (L[0].f <= 1e-5f);
            }
        }
        if (reset) {
            *(volatile unsigned char *)((char *)this + 0xa1) = 0;
            *(volatile unsigned char *)((char *)this + 0xa0) = 0;
        }
    }
    if (*(volatile unsigned char *)((char *)this + 0xa1) != 0) {
        if (L[12].f - T[53] > DAT_004a1aac)
            *(volatile unsigned char *)((char *)this + 0xa1) = 0;
    }
    if (*(volatile unsigned char *)((char *)this + 0xa0) != 0) {
        esiv = (unsigned)(T + 54);
        FUN_000fce60(infov, esiv, (unsigned)&L[17].f, *(volatile unsigned *)((char *)this + 0x118), *(volatile unsigned *)((char *)this + 0x11c), L[4].u, L[3].u, (unsigned)&L[13].f);
        FUN_000fce60(infov, esiv, (unsigned)&L[17].f, *(volatile unsigned *)((char *)this + 0x118), *(volatile unsigned *)((char *)this + 0x11c), L[11].u, L[1].u, (unsigned)&L[27].f);
        FUN_000fd010(esiv, *(volatile unsigned *)((char *)this + 0x118), *(volatile unsigned *)((char *)this + 0x11c), L[4].u, L[3].u, (unsigned)&L[30].f);
        FUN_000fd010(esiv, *(volatile unsigned *)((char *)this + 0x118), *(volatile unsigned *)((char *)this + 0x11c), L[11].u, L[1].u, (unsigned)&L[33].f);
    L[16].f = (sqrt((((T[41] * T[41]) + (T[42] * T[42])) + (T[43] * T[43]))) * sqrt((((L[15].f * L[15].f) + (L[14].f * L[14].f)) + (L[13].f * L[13].f))));
    L[1].f = (sqrt((((T[41] * T[41]) + (T[42] * T[42])) + (T[43] * T[43]))) * sqrt((((L[15].f * L[15].f) + (L[14].f * L[14].f)) + (L[13].f * L[13].f))));
        L[1].u = L[1].u & 0x7fffffff;
        if (L[1].f <= 1e-5f) {
            *(volatile unsigned char *)((char *)this + 0xa1) = 0;
            *(volatile unsigned char *)((char *)this + 0xa0) = 0;
            ang = 0.0;
        } else {
            ang = FUN_00018a20(((((L[15].f * T[43]) + (L[14].f * T[42])) + (L[13].f * T[41])) / L[16].f));
        }
        if (ang > DAT_004a1ab0 * 0.017453292f) {
            *(volatile unsigned char *)((char *)this + 0xa1) = 1;
            *(volatile unsigned char *)((char *)this + 0xa0) = 0;
            *(volatile unsigned *)((char *)this + 0xd4) = L[12].u;
        }
        ediv = infov;
    } else if (*(volatile unsigned char *)((char *)this + 0xa1) != 0) {
    r6_ecx = T + 41;
    r7_edx = *(volatile unsigned*)&r6_ecx[0];
    r8_eax = *(volatile unsigned*)&r6_ecx[1];
    r9_ecx = *(volatile unsigned*)&r6_ecx[2];
    L[8].u = r7_edx;
    L[9].u = r8_eax;
    r10_edx = T + 44;
    r11_eax = *(volatile unsigned*)&r10_edx[0];
    L[10].u = r9_ecx;
    r12_ecx = *(volatile unsigned*)&r10_edx[1];
    r13_edx = *(volatile unsigned*)&r10_edx[2];
    L[5].u = r11_eax;
    L[6].u = r12_ecx;
    L[7].u = r13_edx;
        ((Cls1c38f0 *)objb)->FUN_001c38f0((unsigned)&L[2].f, (unsigned)&L[26].f);
        tmpi = ((Cls1c3990 *)objb)->FUN_001c3990();
        memcpy((void *)&L[36].f, (const void *)tmpi, 64);
        ((Cls1c3950 *)objb)->FUN_001c3950((unsigned)&L[0].f, (unsigned)&L[26].f);
        esiv = L[3].u; ediv = L[4].u;
        FUN_000fce60(ediv, (unsigned)&L[36].f, (unsigned)&L[17].f, L[2].u, L[0].u, ediv, esiv, (unsigned)&L[20].f);
        FUN_000fce60(ediv, (unsigned)&L[36].f, (unsigned)&L[17].f, L[2].u, L[0].u, L[11].u, L[1].u, (unsigned)&L[23].f);
        FUN_000fd010((unsigned)&L[36].f, L[2].u, L[0].u, ediv, esiv, (unsigned)&L[52].f);
        FUN_000fd010((unsigned)&L[36].f, L[2].u, L[0].u, L[11].u, L[1].u, (unsigned)&L[55].f);
    r14_esi = 0x7fffffff;
    L[0].u = 0;
    L[4].f = ((L[12].f - T[53]) / DAT_004a1aac);
    L[1].f = (sqrt((((L[21].f * L[21].f) + (L[22].f * L[22].f)) + (L[20].f * L[20].f))) * sqrt((((L[9].f * L[9].f) + (L[8].f * L[8].f)) + (L[10].f * L[10].f))));
        L[1].u = L[1].u & 0x7fffffff;
        if (!(L[1].f <= 1e-5f)) {
    ARGfc = ((((L[21].f * L[9].f) + (L[8].f * L[20].f)) + (L[22].f * L[10].f)) / (sqrt((((L[21].f * L[21].f) + (L[22].f * L[22].f)) + (L[20].f * L[20].f))) * sqrt((((L[9].f * L[9].f) + (L[8].f * L[8].f)) + (L[10].f * L[10].f)))));
            D18a = ARGfc;
            L[0].f = FUN_00018a20(D18a);
        }
        if (((L[20].f * L[10].f) - (L[22].f * L[8].f)) < 0.0f)
            L[0].f = -L[0].f;
    L[3].f = (sqrt((((L[24].f * L[24].f) + (L[25].f * L[25].f)) + (L[23].f * L[23].f))) * sqrt((((L[6].f * L[6].f) + (L[5].f * L[5].f)) + (L[7].f * L[7].f))));
    r15_eax = L[3].u;
    L[1].u = r15_eax;
    r16_eax = r15_eax & r14_esi;
    L[1].u = r16_eax;
        if (L[1].f <= 1e-5f) {
            A2 = 0.0;
        } else {
    ARGfc = ((((L[24].f * L[6].f) + (L[25].f * L[7].f)) + (L[5].f * L[23].f)) / L[3].f);
            D18a = ARGfc;
            A2 = FUN_00018a20(D18a);
        }
        if (((L[23].f * L[7].f) - (L[25].f * L[5].f)) < 0.0f)
            A2 = -A2;
    r17_ecx = L[9].u;
    r18_edx = L[6].u;
    L[14].u = r17_ecx;
    L[28].u = r18_edx;
    L[1].f = sin((L[0].f * L[4].f));
    L[3].f = cos((L[0].f * L[4].f));
    L[13].f = ((L[3].f * L[8].f) + (L[1].f * L[10].f));
    L[15].f = ((L[3].f * L[10].f) - (L[1].f * L[8].f));
    L[27].f = ((L[5].f * cos((A2 * L[4].f))) + (sin((A2 * L[4].f)) * L[7].f));
    L[29].f = ((cos((A2 * L[4].f)) * L[7].f) - (sin((A2 * L[4].f)) * L[5].f));
        ediv = L[16].u;
    } else {
        ((Cls1c38f0 *)objb)->FUN_001c38f0((unsigned)&L[2].f, (unsigned)&L[26].f);
        tmpi = ((Cls1c3990 *)objb)->FUN_001c3990();
        memcpy((void *)&L[36].f, (const void *)tmpi, 64);
        ((Cls1c3950 *)objb)->FUN_001c3950((unsigned)&L[0].f, (unsigned)&L[26].f);
        esiv = L[3].u; ediv = L[4].u;
        FUN_000fce60(ediv, (unsigned)&L[36].f, (unsigned)&L[17].f, L[2].u, L[0].u, ediv, esiv, (unsigned)&L[13].f);
        ebpv = L[11].u; ebxv = L[1].u;
        FUN_000fce60(ediv, (unsigned)&L[36].f, (unsigned)&L[17].f, L[2].u, L[0].u, ebpv, ebxv, (unsigned)&L[27].f);
        FUN_000fd010((unsigned)&L[36].f, L[2].u, L[0].u, ediv, esiv, (unsigned)&L[30].f);
        FUN_000fd010((unsigned)&L[36].f, L[2].u, L[0].u, ebpv, ebxv, (unsigned)&L[33].f);
        ediv = L[16].u;
    }
    tmpi = L[13].u;
    *(volatile unsigned *)((char *)ediv + 0x10c + 0x0) = tmpi;
    tmpi = L[14].u;
    *(volatile unsigned *)((char *)ediv + 0x10c + 0x4) = tmpi;
    tmpi = L[15].u;
    *(volatile unsigned *)((char *)ediv + 0x10c + 0x8) = tmpi;
    flen = ((V3x *)(ediv + 0x10c))->FUN_0022d110();
    *(volatile float *)((char *)ediv + 0x118) = flen;
    *(volatile unsigned *)((char *)ediv + 0x124) = 0;
    *(volatile unsigned *)((char *)ediv + 0x120) = 0;
    *(volatile unsigned *)((char *)ediv + 0x11c) = 0;
    *(volatile unsigned *)((char *)ediv + 0x128) = L[27].u;
    *(volatile unsigned *)((char *)ediv + 0x12c) = L[28].u;
    *(volatile unsigned *)((char *)ediv + 0x130) = L[29].u;
}
