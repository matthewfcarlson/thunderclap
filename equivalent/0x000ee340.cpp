// STATUS: equivalent (tools/equiv.py level 3: 122 inputs, branch coverage 28/28)
// ImageSelector::vfunc_5 @ 0x000ee340
// ImageSelector::vfunc_5: FE image-grid selector draw (rows x columns of cell objects, highlight, caption).
// Generated from the original code with work/cq/x87c3.py: `this` is addressed through the volatile float view T,
// the frame is the volatile slot array L[] at the original offsets, calls are made through the declared
// virtual slots of the device/context objects reached via DAT_0052c2ac / DAT_0052c2a8.
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "gen/global.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"

extern "C" float __cdecl fabsf(float);
void *thunk_FUN_0008d690(unsigned int size);

union Wd_ee340 {
    float f;
    unsigned int u;
};

struct Dev1 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void v15(unsigned a);
    virtual void v16(unsigned a);
};
struct Ctx_ee340 {
    Dev1 *dev;
    void FUN_00293d00(unsigned a);
    void FUN_00293da0(unsigned a, unsigned b, unsigned c);
};
struct Gfx {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual unsigned v30(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e);
    virtual void v31(unsigned a);
};
struct Obj14_ee340 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual void v14(unsigned out, unsigned who);
    virtual void v15(unsigned out, unsigned who);
    virtual float v16(unsigned who);
    virtual float v17(unsigned who);
    virtual void s18();
    virtual void s19();
    virtual unsigned v20();
};
struct Objr {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50();
    virtual unsigned v51();
};
struct Objs_ee340 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
    virtual unsigned v44();
};
struct Obj50_ee340 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void v8(unsigned a, unsigned b);
};
struct Obj10_ee340 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void v5(unsigned a, unsigned b);
    virtual void v6(unsigned a, unsigned b);
};
struct NewObj_ee340 { virtual void v0(); virtual void v1(); };
struct Fmt { Fmt *FUN_0028edb0(); };
struct Z { void FUN_0008ef00(); };
struct Fmt7 { void FUN_000f7fe0(unsigned a); };
struct Fmt8 { void FUN_000f80e0(unsigned a, unsigned b, unsigned c); };
struct Fmt9 { void FUN_000f78e0(); };

extern int DAT_00584554;
void FUN_000e11a0(float x, float y, float z, unsigned a, int b);
void FUN_000e0cc0(float x, float y, float z, unsigned a, int b);
// equiv-conv: FUN_000e0a90 edx stack stack stack stack stack
void FUN_000e0a90(unsigned a_edx, float x, float y, float z, float w, unsigned color);

void ImageSelector::vfunc_5() {
    volatile float *T = (volatile float *)this;
    volatile Wd_ee340 L[74];
    float fa;
    int r10_eax;
    int r11_eax;
    int r12_ecx;
    int r13_edx;
    int r14_edx;
    int r15_eax;
    int r16_ecx;
    int r17_eax;
    int r18_eax;
    int r19_ecx;
    int r1_eax;
    int r20_edx;
    int r21_edx;
    int r22_eax;
    int r23_ecx;
    int r24_eax;
    int r25_eax;
    int r26_ecx;
    int r27_edx;
    int r28_edx;
    int r29_eax;
    int r2_ecx;
    int r30_ecx;
    int r31_eax;
    int r32_eax;
    int r33_ecx;
    int r34_edx;
    int r35_edx;
    int r36_eax;
    int r37_ecx;
    int r38_eax;
    int r39_eax;
    int r3_edx;
    int r40_ecx;
    int r41_edx;
    int r42_eax;
    int r43_edx;
    int r44_ecx;
    int r45_eax;
    int r4_eax;
    int r5_ecx;
    int r6_edx;
    int r7_edx;
    int r8_eax;
    int r9_ecx;
    unsigned tmpi, tmp2, o14, esiv, ebpv, mem, zobj, gptr, colv;
    if (*(volatile unsigned char *)((char *)this + 0x74) == 0)
        return;
    if (*(volatile unsigned char *)((char *)this + 0x40) == 1) {
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
        ((Obj14_ee340 *)*(volatile unsigned *)((char *)this + 0x14))->v14((unsigned)&L[4].f, (unsigned)this);
        (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)&L[4].f);
        ((Obj14_ee340 *)*(volatile unsigned *)((char *)this + 0x14))->v15((unsigned)&L[0].f, (unsigned)this);
        tmpi = *(volatile unsigned *)((char *)this + 0x148);
        FUN_000e11a0(L[0].f, L[1].f, L[2].f, tmpi, 2);
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
    }
    if (*(volatile unsigned char *)((char *)this + 0x48) == 1) {
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
        ((Obj14_ee340 *)*(volatile unsigned *)((char *)this + 0x14))->v14((unsigned)&L[4].f, (unsigned)this);
        (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)&L[4].f);
        ((Obj14_ee340 *)*(volatile unsigned *)((char *)this + 0x14))->v15((unsigned)&L[0].f, (unsigned)this);
        tmpi = *(volatile unsigned *)((char *)this + 0x4c);
        FUN_000e0cc0(L[0].f, L[1].f, L[2].f, tmpi, 0);
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
    }
    if (*(volatile unsigned *)((char *)this + 0x50) != 0) {
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
        ((Obj14_ee340 *)*(volatile unsigned *)((char *)this + 0x14))->v14((unsigned)&L[4].f, (unsigned)this);
        (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)&L[4].f);
        (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293da0(*(volatile unsigned *)((char *)this + 0x54), *(volatile unsigned *)((char *)this + 0x58), *(volatile unsigned *)((char *)this + 0x5c));
        ((Obj50_ee340 *)*(volatile unsigned *)((char *)this + 0x50))->v8(0, 0);
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
    }
    (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
    ((Obj14_ee340 *)*(volatile unsigned *)((char *)this + 0x14))->v14((unsigned)&L[4].f, (unsigned)this);
    (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)&L[4].f);
    (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)((volatile float *)this + 30));
    if ((int)*(volatile unsigned *)((char *)this + 0x294) > 0) {
        L[7].u = 0;
        tmpi = (unsigned)this + 0x250;
        L[3].u = tmpi;
        esiv = (unsigned)this + 0x150;
        L[9].u = esiv;
        do {
            (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
            L[8].u = 0;
            if ((int)*(volatile unsigned *)((char *)this + 0x298) > 0) {
                L[10].u = esiv;
                do {
                    if (*(volatile unsigned *)((char *)esiv + 0x0) != 0) {
                        mem = (unsigned)thunk_FUN_0008d690(0x20);
                        ebpv = mem != 0 ? (unsigned)((Fmt *)mem)->FUN_0028edb0() : 0;
                        ((NewObj_ee340 *)ebpv)->v0();
                        tmpi = *(volatile unsigned *)((char *)ebpv + 0x10);
                        ((Obj10_ee340 *)tmpi)->v6(0x444d4c42, 1);
                        tmp2 = *(volatile unsigned *)((char *)esiv + 0x0);
                        tmp2 = tmp2 != 0 ? *(volatile unsigned *)((char *)tmp2 + 0x10) : 0;
                        tmpi = *(volatile unsigned *)((char *)ebpv + 0x10);
                        ((Obj10_ee340 *)tmpi)->v5((unsigned)&DAT_00584554, tmp2);
    r1_eax = *(volatile unsigned*)&((volatile float *)ebpv)[4];
    r2_ecx = (unsigned)DAT_0052c2a8;
    r3_edx = *(volatile unsigned*)&((volatile float *)r2_ecx)[0];
    L[26].f = (T[167] * 0.8f);
    L[27].f = (T[168] * 0.8f);
    L[21].u = 0;
    L[22].u = 0x3f800000;
    L[11].u = 0x3f800000;
    L[12].u = 0x3f800000;
    L[15].u = 0x3f800000;
    L[29].f = (L[26].f * -0.5f);
    L[16].u = 0;
    L[13].u = 0;
    L[14].u = 0;
    L[30].f = (L[27].f * 0.5f);
    L[17].f = (L[26].f * 0.5f);
    L[18].f = (L[27].f * 0.5f);
    L[32].f = (L[26].f * 0.5f);
    L[33].f = (L[27].f * -0.5f);
    L[23].f = (L[26].f * -0.5f);
    L[24].f = (L[27].f * -0.5f);
                        zobj = (unsigned)DAT_0052c2a8->v30(r1_eax, 0, 0x2021, 6, 0);
                        if (zobj != 0) {
    r4_eax = *(volatile unsigned*)&((volatile float *)zobj)[2];
    r5_ecx = L[23].u;
    r6_edx = L[24].u;
    *(volatile unsigned*)&((volatile float *)r4_eax)[0] = r5_ecx;
    *(volatile unsigned*)&((volatile float *)r4_eax)[1] = r6_edx;
    r7_edx = L[13].u;
    *(volatile unsigned*)&((volatile float *)r4_eax)[2] = 0;
    r8_eax = *(volatile unsigned*)&((volatile float *)zobj)[4];
    *(volatile unsigned*)&((volatile float *)r8_eax)[0] = 0xffffffff;
    r9_ecx = *(volatile unsigned*)&((volatile float *)zobj)[5];
    r10_eax = L[14].u;
    *(volatile unsigned*)&((volatile float *)r9_ecx)[0] = r7_edx;
    *(volatile unsigned*)&((volatile float *)r9_ecx)[1] = r10_eax;
                            ((Z *)zobj)->FUN_0008ef00();
    r11_eax = *(volatile unsigned*)&((volatile float *)zobj)[2];
    r12_ecx = L[29].u;
    r13_edx = L[30].u;
    *(volatile unsigned*)&((volatile float *)r11_eax)[0] = r12_ecx;
    *(volatile unsigned*)&((volatile float *)r11_eax)[1] = r13_edx;
    r14_edx = L[21].u;
    *(volatile unsigned*)&((volatile float *)r11_eax)[2] = 0;
    r15_eax = *(volatile unsigned*)&((volatile float *)zobj)[4];
    *(volatile unsigned*)&((volatile float *)r15_eax)[0] = 0xffffffff;
    r16_ecx = *(volatile unsigned*)&((volatile float *)zobj)[5];
    r17_eax = L[22].u;
    *(volatile unsigned*)&((volatile float *)r16_ecx)[0] = r14_edx;
    *(volatile unsigned*)&((volatile float *)r16_ecx)[1] = r17_eax;
                            ((Z *)zobj)->FUN_0008ef00();
    r18_eax = *(volatile unsigned*)&((volatile float *)zobj)[2];
    r19_ecx = L[17].u;
    r20_edx = L[18].u;
    *(volatile unsigned*)&((volatile float *)r18_eax)[0] = r19_ecx;
    *(volatile unsigned*)&((volatile float *)r18_eax)[1] = r20_edx;
    r21_edx = L[11].u;
    *(volatile unsigned*)&((volatile float *)r18_eax)[2] = 0;
    r22_eax = *(volatile unsigned*)&((volatile float *)zobj)[4];
    *(volatile unsigned*)&((volatile float *)r22_eax)[0] = 0xffffffff;
    r23_ecx = *(volatile unsigned*)&((volatile float *)zobj)[5];
    r24_eax = L[12].u;
    *(volatile unsigned*)&((volatile float *)r23_ecx)[0] = r21_edx;
    *(volatile unsigned*)&((volatile float *)r23_ecx)[1] = r24_eax;
                            ((Z *)zobj)->FUN_0008ef00();
    r25_eax = *(volatile unsigned*)&((volatile float *)zobj)[2];
    r26_ecx = L[23].u;
    r27_edx = L[24].u;
    *(volatile unsigned*)&((volatile float *)r25_eax)[0] = r26_ecx;
    *(volatile unsigned*)&((volatile float *)r25_eax)[1] = r27_edx;
    r28_edx = L[13].u;
    *(volatile unsigned*)&((volatile float *)r25_eax)[2] = 0;
    r29_eax = *(volatile unsigned*)&((volatile float *)zobj)[4];
    *(volatile unsigned*)&((volatile float *)r29_eax)[0] = 0xffffffff;
    r30_ecx = *(volatile unsigned*)&((volatile float *)zobj)[5];
    r31_eax = L[14].u;
    *(volatile unsigned*)&((volatile float *)r30_ecx)[0] = r28_edx;
    *(volatile unsigned*)&((volatile float *)r30_ecx)[1] = r31_eax;
                            ((Z *)zobj)->FUN_0008ef00();
    r32_eax = *(volatile unsigned*)&((volatile float *)zobj)[2];
    r33_ecx = L[17].u;
    r34_edx = L[18].u;
    *(volatile unsigned*)&((volatile float *)r32_eax)[0] = r33_ecx;
    *(volatile unsigned*)&((volatile float *)r32_eax)[1] = r34_edx;
    r35_edx = L[11].u;
    *(volatile unsigned*)&((volatile float *)r32_eax)[2] = 0;
    r36_eax = *(volatile unsigned*)&((volatile float *)zobj)[4];
    *(volatile unsigned*)&((volatile float *)r36_eax)[0] = 0xffffffff;
    r37_ecx = *(volatile unsigned*)&((volatile float *)zobj)[5];
    r38_eax = L[12].u;
    *(volatile unsigned*)&((volatile float *)r37_ecx)[0] = r35_edx;
    *(volatile unsigned*)&((volatile float *)r37_ecx)[1] = r38_eax;
                            ((Z *)zobj)->FUN_0008ef00();
    r39_eax = *(volatile unsigned*)&((volatile float *)zobj)[2];
    r40_ecx = L[32].u;
    r41_edx = L[33].u;
    *(volatile unsigned*)&((volatile float *)r39_eax)[0] = r40_ecx;
    *(volatile unsigned*)&((volatile float *)r39_eax)[1] = r41_edx;
    *(volatile unsigned*)&((volatile float *)r39_eax)[2] = 0;
    r42_eax = *(volatile unsigned*)&((volatile float *)zobj)[4];
    r43_edx = L[15].u;
    *(volatile unsigned*)&((volatile float *)r42_eax)[0] = 0xffffffff;
    r44_ecx = *(volatile unsigned*)&((volatile float *)zobj)[5];
    r45_eax = L[16].u;
    *(volatile unsigned*)&((volatile float *)r44_ecx)[0] = r43_edx;
    *(volatile unsigned*)&((volatile float *)r44_ecx)[1] = r45_eax;
                            ((Z *)zobj)->FUN_0008ef00();
                        }
                        DAT_0052c2a8->v31(zobj);
                        ((NewObj_ee340 *)ebpv)->v1();
                        colv = L[8].u;
                        if (*(volatile unsigned *)((char *)this + 0x2a8) == *(volatile unsigned *)((char *)this + 0x298) * L[7].u + colv) {
                            FUN_000e0a90(1, T[167] * 0.8f, T[168] * 0.8f, 1.0f, 0.02f, 0xff51c4ff);
                        }
                        if (*(volatile unsigned char *)(L[3].u + colv) != 0) {
                            tmpi = *(volatile unsigned *)((char *)this + 0x14);
                            tmpi = ((Obj14_ee340 *)tmpi)->v20();
                            tmpi = ((Objr *)tmpi)->v51();
                            tmpi = ((Objs_ee340 *)tmpi)->v44();
                            ((Fmt7 *)(unsigned)&L[38].f)->FUN_000f7fe0(tmpi);
                            fa = ((Obj14_ee340 *)*(volatile unsigned *)((char *)this + 0x14))->v17((unsigned)this);
                            L[20].f = fa;
                            fa = ((Obj14_ee340 *)*(volatile unsigned *)((char *)this + 0x14))->v16((unsigned)this);
                            *(volatile float *)((char *)&L[40].f + (L[72].u << 4)) = fa * L[20].f;
                            *(volatile unsigned *)((char *)&L[41].f + (L[72].u << 4)) = 1;
                            *(volatile unsigned *)((char *)&L[42].f + (L[72].u << 4)) = 2;
                            ((Fmt8 *)(unsigned)&L[38].f)->FUN_000f80e0((unsigned)&(*(int*)&DAT_0040b0a0), 0, 0);
                            ((Fmt9 *)(unsigned)&L[38].f)->FUN_000f78e0();
                        }
                    }
                    L[35].u = *(volatile unsigned *)((char *)this + 0x29c);
                    L[36].u = 0;
                    L[37].u = 0;
                    (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)&L[35].f);
                    colv = L[8].u + 1;
                    esiv = L[10].u + 4;
                    L[8].u = colv;
                    L[10].u = esiv;
                } while ((int)colv < (int)*(volatile unsigned *)((char *)this + 0x298));
            }
            (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
            L[4].u = 0;
            L[5].f = -T[168];
            L[6].u = 0;
            (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)&L[4].f);
            colv = L[7].u + 1;
            esiv = L[9].u + 0x20;
            tmpi = L[3].u + 8;
            L[7].u = colv;
            L[9].u = esiv;
            L[3].u = tmpi;
        } while ((int)colv < (int)*(volatile unsigned *)((char *)this + 0x294));
    }
    (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
}
