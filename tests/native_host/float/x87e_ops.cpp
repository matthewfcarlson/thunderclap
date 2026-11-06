// x87ext_native.cpp's operations against the x87 (long double, control word 0x027F) on x86-64 under Rosetta.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "softx87.h"
extern "C" {
void hulk_x87e_sin(double, hulk_x87_ext*); void hulk_x87e_atan2(double, double, hulk_x87_ext*); void hulk_x87e_pow(double, double, hulk_x87_ext*);
double hulk_x87e_mul(const hulk_x87_ext*, double); double hulk_x87e_add(const hulk_x87_ext*, double);
double hulk_x87e_sub(const hulk_x87_ext*, double); double hulk_x87e_rsub(double, const hulk_x87_ext*);
double hulk_x87e_div(const hulk_x87_ext*, double); double hulk_x87e_rdiv(double, const hulk_x87_ext*);
float hulk_x87e_to_float(const hulk_x87_ext*); int hulk_x87e_fcmp(const hulk_x87_ext*, double, int, int);
}
typedef long double ld;
static unsigned long long s = 88172645463325252ull;
static unsigned long long rnd() { s ^= s << 13; s ^= s >> 7; s ^= s << 17; return s; }
static double ur(double lo, double hi) { return lo + (hi - lo) * ((rnd() >> 11) * (1.0 / 9007199254740992.0)); }
static ld to_ld(hulk_x87_ext e) { ld v; memset(&v, 0, sizeof v); memcpy(&v, &e.m, 8); memcpy((char*)&v + 8, &e.se, 2); return v; }
static void cw(unsigned short c) { __asm__ volatile("fldcw %0" ::"m"(c)); }
#define OP(name, ins) static double name(ld a, ld b) { ld r; __asm__ volatile(ins : "=t"(r) : "0"(a), "u"(b) : "st(1)"); return (double)r; }
OP(xmul, "fmulp") OP(xadd, "faddp") OP(xsub, "fsubrp") OP(xdiv, "fdivrp")
static unsigned long long db(double d) { unsigned long long u; memcpy(&u, &d, 8); return u; }
int main(int argc, char** argv) {
    long N = argc > 1 ? atol(argv[1]) : 1000000, bad[9] = {0};
    for (long i = 0; i < N; i++) {
        hulk_x87_ext e;
        int k = i % 3;
        if (k == 0) hulk_x87e_sin(ur(-7, 7), &e);
        else if (k == 1) hulk_x87e_atan2(ur(-100, 100), ur(-100, 100), &e);
        else hulk_x87e_pow(ur(0.01, 4), ur(-3, 3), &e);
        double b = (i & 4) ? (double)(float)ur(-50, 50) : ur(-1e3, 1e3);
        if ((i & 63) == 0) b = 0.0;
        ld E = to_ld(e), B = b;
        cw(0x027F);
        volatile ld VE = E, VB = B; double r0 = (double)(VE * VB), r1 = (double)(VE + VB), r2 = (double)(VE - VB), r3 = (double)(VB - VE), r4 = (double)(VE / VB), r5 = (double)(VB / VE);
        float f = (float)E;
        cw(0x037F);
        if (db(r0) != db(hulk_x87e_mul(&e, b))) bad[0]++;
        if (db(r1) != db(hulk_x87e_add(&e, b))) bad[1]++;
        if (db(r2) != db(hulk_x87e_sub(&e, b))) bad[2]++;
        if (db(r3) != db(hulk_x87e_rsub(b, &e))) bad[3]++;
        if (db(r4) != db(hulk_x87e_div(&e, b))) bad[4]++;
        if (db(r5) != db(hulk_x87e_rdiv(b, &e))) bad[5]++;
        float g = hulk_x87e_to_float(&e); if (memcmp(&f, &g, 4)) bad[6]++;
        int c1 = E < B, c2 = E >= B, c3 = E == B;
        if (c1 != hulk_x87e_fcmp(&e, b, 4, 0) || c2 != hulk_x87e_fcmp(&e, b, 3, 0) || c3 != hulk_x87e_fcmp(&e, b, 1, 0) ||
            (B < E) != hulk_x87e_fcmp(&e, b, 4, 1)) bad[7]++;
    }
    printf("N=%ld mismatches: mul %ld add %ld sub %ld rsub %ld div %ld rdiv %ld to_float %ld fcmp %ld\n", N, bad[0], bad[1],
           bad[2], bad[3], bad[4], bad[5], bad[6], bad[7]);
}
