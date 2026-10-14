// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 57/58, incomplete)
// hulkfight::motion::ProjectileEffect::vfunc_4 @ 0x00195bb0
// hulkfight::motion::ProjectileEffect::vfunc_4: per-frame projectile update (steer toward the target direction,
// integrate position, hit test via the usercall helpers FUN_00195290/001958c0/00195560, spawn/despawn effects).
// Generated from the original x87/integer code (work/cq/x87c3.py): `this` is addressed through the volatile
// float view T, the original's frame lives in the volatile slot array L[] at the original offsets, and
// FPU-resident values are recomputed inline from volatile reads so the compiler keeps the original rounding.
extern "C" float __cdecl fabsf(float);

union Wd_195bb0 {
    float f;
    unsigned int u;
};

struct Releasable_195bb0 {
    virtual void v0();
    virtual void Release();
};

struct V3x {
    float FUN_0022d110();
    void FUN_0022b980();
    bool FUN_0022d2b0(unsigned v, float eps);
    void FUN_00011160(float s, unsigned v);
};

struct Thing_195bb0 { unsigned FUN_001d72e0(); };
struct Reg59 { unsigned FUN_00059c10(unsigned id); };
struct Cls1d5 { unsigned FUN_001d5e80(unsigned a); };
struct Mat_195bb0 { void FUN_0022c3b0(unsigned in, unsigned out); };
struct VObj_195bb0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual Mat_195bb0 *v15();
};
struct Spawn_195bb0 { void FUN_0027ffc0(unsigned a, unsigned b); void FUN_0027ffb0(unsigned a); };
struct Cls283 { void FUN_00283a40(unsigned a, unsigned b, unsigned c, unsigned d); };
struct Cls1f6 { void FUN_001f6cd0(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f, unsigned g, unsigned h, unsigned i, unsigned j); };

extern unsigned DAT_004dd700;
unsigned FUN_00098190(float dt, unsigned f4c, unsigned v, unsigned z1, unsigned f24, unsigned z2, unsigned p34, unsigned p40, unsigned z3, unsigned z4, unsigned z5, unsigned one);
// equiv-conv: FUN_00195290 eax edx ecx edi stack stack stack stack stack stack stack
char FUN_00195290(unsigned a_eax, unsigned a_edx, unsigned a_ecx, unsigned a_edi, unsigned s1, unsigned s2, unsigned s3, unsigned s4, unsigned s5, unsigned s6, unsigned s7);
// equiv-conv: FUN_001958c0 eax stack stack stack stack stack stack stack stack stack stack
char FUN_001958c0(unsigned a_eax, unsigned s1, unsigned s2, unsigned s3, unsigned s4, unsigned s5, unsigned s6, unsigned s7, unsigned s8, unsigned s9, unsigned s10);
// equiv-conv: FUN_00195560 eax ecx ebx stack stack stack stack stack stack stack stack stack stack stack
char FUN_00195560(unsigned a_eax, unsigned a_ecx, unsigned a_ebx, unsigned s1, unsigned s2, unsigned s3, unsigned s4, unsigned s5, unsigned s6, unsigned s7, unsigned s8, unsigned s9, unsigned s10, unsigned s11);
unsigned FUN_0027f250();
float FUN_000964e0();
void FUN_00224db0(unsigned a, unsigned b, unsigned c);

class ProjectileEffect {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4(float dt);
};

void ProjectileEffect::vfunc_4(float dt)
{
    volatile float *T = (volatile float *)this;
    volatile Wd_195bb0 L[35];
    float L8c1;
    int r12_eax;
    int r13_edx;
    int r14_eax;
    int r15_edx;
    int r16_eax;
    int r17_eax;
    int r18_ecx;
    int r1_ecx;
    int r22_eax;
    int r23_ecx;
    int r24_edx;
    int r2_edi;
    int r30_eax;
    int r31_ecx;
    int r32_edx;
    int r33_ecx;
    int r34_eax;
    int r35_edx;
    int r3_edx;
    int r4_ecx;
    int r6_edx;
    int r7_eax;
    int r8_ecx;
    unsigned tmpi, ok, objv, O, eaxv, ecxv, edxv, ediv;
    volatile float * r5_ebx;
    volatile float * r9_ebp;
    volatile float ARGa4;
    volatile float f10;
    volatile float f11;
    volatile float f19;
    volatile float f20;
    volatile float f21;
    volatile float f25;
    volatile float f26;
    volatile float f27;
    volatile float f28;
    volatile float f29;
    if (*(volatile unsigned char *)&T[4] != 0)
        return;
    L[1].u = *(volatile unsigned *)&dt;
    L[1].u = L[1].u & 0x7fffffff;
    if (L[1].f <= 1e-5f)
        return;
    volatile float l0 = T[3];
    r1_ecx = *(volatile unsigned*)&T[6];
    r2_edi = 0;
    T[3] = (l0 - dt);
    r3_edx = *(volatile unsigned*)&((volatile float *)r1_ecx)[28];
    r4_ecx = *(volatile unsigned*)&T[9];
    L[9].u = r3_edx;
    if (r4_ecx != 0 && L[9].f > 0.0f) {
        if (FUN_00098190(dt, *(volatile unsigned *)&T[19], L[9].u, 0, r4_ecx, 0, (unsigned)(T + 13), (unsigned)(T + 16), 0, 0, 0, 1) == 0) {
            tmpi = *(volatile unsigned *)&T[9];
            if (tmpi != 0)
                ((Releasable_195bb0 *)tmpi)->Release();
            *(volatile unsigned *)&T[9] = 0;
        }
    }
    O = *(volatile unsigned *)&T[6];
    if (((volatile float *)O)[25] <= 0.0f) {
        T[19] = ((volatile float *)O)[24];
    } else {
    L[1].f = (((volatile float *)O)[25] * dt);
        if ((T[19] - ((volatile float *)O)[24]) < (-L[1].f)) {
            T[19] = (L[1].f + T[19]);
        } else {
            if ((T[19] - ((volatile float *)O)[24]) > L[1].f) {
                T[19] = (T[19] - L[1].f);
            } else {
                T[19] = ((volatile float *)O)[24];
            }
        }
    }
    volatile float l19 = T[19];
    r5_ebx = T + 16;
    r6_edx = *(volatile unsigned*)&r5_ebx[0];
    r7_eax = *(volatile unsigned*)&r5_ebx[1];
    r8_ecx = *(volatile unsigned*)&r5_ebx[2];
    L[2].u = r6_edx;
    L[3].u = r7_eax;
    L[4].u = r8_ecx;
    r9_ebp = T + 13;
    L[14].u = r2_edi;
    f10 = L[3].f;
    L[3].f = (f10 * l19);
    L[9].u = r2_edi;
    L[10].u = (unsigned)(r5_ebx);
    L[8].u = r2_edi;
    L[1].u = r2_edi;
    f11 = L[4].f;
    L[4].f = (f11 * l19);
    volatile float l28 = r9_ebp[0];
    r9_ebp[0] = (((L[2].f * l19) * dt) + l28);
    volatile float l33 = r9_ebp[1];
    r9_ebp[1] = ((L[3].f * dt) + l33);
    volatile float l38 = r9_ebp[2];
    r9_ebp[2] = ((L[4].f * dt) + l38);
    r12_eax = DAT_004dd700;
    r13_edx = *(volatile unsigned*)&T[8];
    L[15].u = r12_eax;
    r14_eax = *(volatile unsigned*)&((volatile float *)r12_eax)[17];
    tmpi = (unsigned)((Reg59 *)r14_eax)->FUN_00059c10(*(volatile unsigned *)((char *)T + 0x20));
    if (tmpi != 0)
        L[1].u = *(volatile unsigned *)((char *)tmpi + 0x12c);
    ok = FUN_00195290((unsigned)&L[9].f, (unsigned)&L[14].f, (unsigned)&L[11].f, (unsigned)(T + 10), (unsigned)(T + 13), (unsigned)&L[5].f, (unsigned)&L[8].f, L[1].u, 0, (unsigned)&((volatile unsigned char *)&L[0])[3], 0);
    ((volatile unsigned char *)&L[0])[3] = (unsigned char)ok;
    r15_edx = *(volatile unsigned*)&(T + 13)[0];
    *(volatile unsigned*)&T[10] = r15_edx;
    r16_eax = *(volatile unsigned*)&(T + 13)[1];
    *(volatile unsigned*)&T[11] = r16_eax;
    r17_eax = L[9].u;
    r18_ecx = *(volatile unsigned*)&(T + 13)[2];
    *(volatile unsigned*)&T[12] = r18_ecx;
    if (r17_eax != 0 && *(volatile unsigned *)((char *)r17_eax + 0x38) == 5)
        ediv = ((Thing_195bb0 *)*(volatile unsigned *)((char *)r17_eax + 0x3c))->FUN_001d72e0();
    else
        ediv = L[8].u;
    do {
        if (ediv == 0)
            break;
        if (*(volatile unsigned *)((char *)ediv + 0xc) == 1) {
            O = *(volatile unsigned *)&T[6];
            tmpi = *(volatile unsigned *)((char *)O + 0x80);
            L[8].u = *(volatile unsigned *)((char *)O + 0xb4);
            L[1].u = *(volatile unsigned *)((char *)O + 0xb8);
            edxv = *(volatile unsigned *)((char *)O + 0xa8);
            eaxv = *(volatile unsigned *)((char *)O + 0x9c);
            ok = FUN_00195560(ediv, (unsigned)(T + 16), (unsigned)&L[11].f, *(volatile unsigned *)((char *)T + 0x20), eaxv, edxv, (unsigned)&L[5].f, L[1].u, L[8].u, 0, tmpi, 0, 0x3f800000, 0);
            if (ok == 0)
                ((volatile unsigned char *)&L[0])[3] = 0;
            break;
        }
        if (*(volatile unsigned *)((char *)ediv + 0xc) != 5)
            break;
        O = *(volatile unsigned *)&T[6];
        tmpi = *(volatile unsigned *)((char *)O + 0x80);
        L[10].u = *(volatile unsigned *)((char *)O + 0xb4);
        L[8].u = *(volatile unsigned *)((char *)O + 0xb8);
        edxv = *(volatile unsigned *)((char *)O + 0xa8);
        eaxv = *(volatile unsigned *)((char *)O + 0x9c);
        ok = FUN_001958c0(*(volatile unsigned *)((char *)T + 0x20), ediv, eaxv, edxv, (unsigned)&L[11].f, (unsigned)&L[5].f, (unsigned)(T + 16), L[8].u, L[10].u, 0, tmpi);
        if (ok == 0) {
            ((volatile unsigned char *)&L[0])[3] = 0;
            break;
        }
        ediv = *(volatile unsigned *)((char *)ediv + 0x8);
        if (ediv == 0)
            break;
        ecxv = *(volatile unsigned *)((char *)ediv + 0xec);
        eaxv = *(volatile unsigned *)((char *)ediv + 0x40);
        if (((Cls1d5 *)ecxv)->FUN_001d5e80(eaxv) != 2)
            break;
        L[16].u = 0;
        L[17].u = 0x3f800000;
        L[18].u = 0;
        tmpi = (unsigned)((VObj_195bb0 *)ediv)->v15();
        ((Mat_195bb0 *)tmpi)->FUN_0022c3b0((unsigned)&L[16].f, (unsigned)&L[5].f);
        if ((((L[7].f * (T + 16)[2]) + (L[6].f * (T + 16)[1])) + (L[5].f * (T + 16)[0])) > 0.0f) {
    f19 = L[5].f;
    L[5].f = (f19 * -1.0f);
    f20 = L[6].f;
    L[6].f = (f20 * -1.0f);
    f21 = L[7].f;
    L[7].f = (f21 * -1.0f);
        }
    r22_eax = L[5].u;
    r23_ecx = L[6].u;
    r24_edx = L[7].u;
    L[2].u = r22_eax;
    L[3].u = r23_ecx;
    L[4].u = r24_edx;
    f25 = L[3].f;
    L[3].f = (f25 * (((((-(T + 16)[2]) * L[7].f) + ((-(T + 16)[1]) * L[6].f)) + ((-(T + 16)[0]) * L[5].f)) + ((((-(T + 16)[2]) * L[7].f) + ((-(T + 16)[1]) * L[6].f)) + ((-(T + 16)[0]) * L[5].f))));
    f26 = L[4].f;
    L[4].f = (f26 * (((((-(T + 16)[2]) * L[7].f) + ((-(T + 16)[1]) * L[6].f)) + ((-(T + 16)[0]) * L[5].f)) + ((((-(T + 16)[2]) * L[7].f) + ((-(T + 16)[1]) * L[6].f)) + ((-(T + 16)[0]) * L[5].f))));
    f27 = L[2].f;
    L[2].f = ((f27 * (((((-(T + 16)[2]) * L[7].f) + ((-(T + 16)[1]) * L[6].f)) + ((-(T + 16)[0]) * L[5].f)) + ((((-(T + 16)[2]) * L[7].f) + ((-(T + 16)[1]) * L[6].f)) + ((-(T + 16)[0]) * L[5].f)))) + (T + 16)[0]);
    f28 = L[3].f;
    L[3].f = (f28 + (T + 16)[1]);
    f29 = L[4].f;
    L[4].f = (f29 + (T + 16)[2]);
        ((V3x *)&L[2].f)->FUN_0022d110();
    r30_eax = L[2].u;
    r31_ecx = L[3].u;
    r32_edx = L[4].u;
    *(volatile unsigned*)&(T + 16)[1] = r31_ecx;
    r33_ecx = L[12].u;
    *(volatile unsigned*)&(T + 16)[0] = r30_eax;
    r34_eax = L[11].u;
    *(volatile unsigned*)&(T + 16)[2] = r32_edx;
    r35_edx = L[13].u;
    *(volatile unsigned*)&(T + 13)[1] = r33_ecx;
    *(volatile unsigned*)&(T + 13)[0] = r34_eax;
    *(volatile unsigned*)&(T + 13)[2] = r35_edx;
    ARGa4 = (dt * T[19]);
        ((V3x *)(T + 13))->FUN_00011160(ARGa4, (unsigned)(T + 16));
        ediv = *(volatile unsigned *)((char *)ediv + 0x114);
        ((volatile unsigned char *)&L[0])[3] = 0;
        if (ediv == 0)
            break;
        if (*(volatile unsigned *)((char *)ediv + 0xc) != 1)
            break;
        ediv = *(volatile unsigned *)((char *)ediv + 0x8);
        if (ediv == 0)
            break;
        eaxv = *(volatile unsigned *)((char *)ediv + 0x10);
        ecxv = *(volatile unsigned *)((char *)eaxv + 0x0);
        *(volatile unsigned *)((char *)T + 0x20) = ecxv;
    } while (0);
    ediv = FUN_0027f250();
    if (((volatile unsigned char *)&L[0])[3] == 0) {
        ((V3x *)&L[19].f)->FUN_0022b980();
        eaxv = *(volatile unsigned *)&T[6] + 0x20;
        L[2].u = *(volatile unsigned *)((char *)eaxv + 0x0);
        L[3].u = *(volatile unsigned *)((char *)eaxv + 0x4);
        L[4].u = *(volatile unsigned *)((char *)eaxv + 0x8);
        ((V3x *)&L[2].f)->FUN_0022d110();
        if (!((V3x *)(T + 16))->FUN_0022d2b0((unsigned)&L[2].f, 1e-5f))
            FUN_00224db0((unsigned)&L[19].f, (unsigned)&L[2].f, (unsigned)(T + 16));
        ecxv = *(volatile unsigned *)&T[13];
        edxv = *(volatile unsigned *)&T[14];
        eaxv = *(volatile unsigned *)&T[15];
        L[31].u = ecxv;
        L[32].u = edxv;
        L[33].u = eaxv;
        ((Spawn_195bb0 *)ediv)->FUN_0027ffc0(*(volatile unsigned *)((char *)T + 0x1c), (unsigned)&L[19].f);
        return;
    }
    ((Spawn_195bb0 *)ediv)->FUN_0027ffb0(*(volatile unsigned *)((char *)T + 0x1c));
    *(volatile unsigned *)((char *)T + 0x1c) = 0;
    ((V3x *)&L[19].f)->FUN_0022b980();
    eaxv = *(volatile unsigned *)&T[6] + 0x90;
    L[2].u = *(volatile unsigned *)((char *)eaxv + 0x0);
    L[3].u = *(volatile unsigned *)((char *)eaxv + 0x4);
    L[4].u = *(volatile unsigned *)((char *)eaxv + 0x8);
    L8c1 = ((V3x *)&L[2].f)->FUN_0022d110();
    L[1].f = L8c1;
    L[1].u = L[1].u & 0x7fffffff;
    if (L[1].f <= 1e-5f) {
        L[2].f = FUN_000964e0() + 0.001f;
        L[3].f = FUN_000964e0() + 0.001f;
        L[4].f = FUN_000964e0() + 0.001f;
        ((V3x *)&L[2].f)->FUN_0022d110();
    }
    if (!((V3x *)&L[2].f)->FUN_0022d2b0((unsigned)&L[5].f, 1e-5f))
        FUN_00224db0((unsigned)&L[19].f, (unsigned)&L[2].f, (unsigned)&L[5].f);
    edxv = L[11].u;
    eaxv = L[12].u;
    ecxv = L[13].u;
    L[32].u = eaxv;
    eaxv = *(volatile unsigned *)&T[6];
    L[31].u = edxv;
    L[33].u = ecxv;
    ((Cls283 *)ediv)->FUN_00283a40(eaxv + 0x88, (unsigned)&L[19].f, 0xbf800000, 0x3f800000);
    ecxv = L[14].u;
    *(volatile unsigned *)&T[3] = 0;
    if (ecxv != 0) {
        edxv = *(volatile unsigned *)&T[6];
        eaxv = *(volatile unsigned *)((char *)edxv + 0xbc);
        if ((int)eaxv > 0) {
            eaxv = eaxv - 1;
            tmpi = L[9].u;
            ((Cls1f6 *)*(volatile unsigned *)((char *)L[15].u + 0x38))->FUN_001f6cd0(ecxv, tmpi, (unsigned)&L[11].f, (unsigned)&L[5].f, (unsigned)(T + 16), eaxv, 0x3f800000, 0x3f800000, 0, 0);
        }
    }
}
