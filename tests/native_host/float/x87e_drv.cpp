#include <stdio.h>
#include <string.h>
#include "softx87.h"
extern "C" { float k1(float, float); double k2(float, float); double k3(float, float); float k4(float); int k5(float, float);
             double k6(float); double k7(float, float);
             double sin(double x) { return hulk_x87_sin(x); } double cos(double x) { return hulk_x87_cos(x); }
             double atan2(double y, double x) { return hulk_x87_atan2(y, x); } double pow(double x, double y) { return hulk_x87_pow(x, y); } }
static unsigned long long s = 99;
static unsigned long long rnd() { s ^= s << 13; s ^= s >> 7; s ^= s << 17; return s; }
static float ur(double lo, double hi) { return (float)(lo + (hi - lo) * ((rnd() >> 11) * (1.0 / 9007199254740992.0))); }
#if defined(__x86_64__)
typedef long double ld;
static ld L(hulk_x87_ext e) { ld v; memset(&v, 0, sizeof v); memcpy(&v, &e.m, 8); memcpy((char*)&v + 8, &e.se, 2); return v; }
static void cw(unsigned short c) { __asm__ volatile("fldcw %0" ::"m"(c)); }
#endif
int main() {
    long bad[8] = {0}, n = 300000; unsigned long long h = 1469598103934665603ull;
    for (long i = 0; i < n; i++) {
        float a = ur(-7, 7), b = ur(-7, 7), y = ur(-50, 50), x = ur(-50, 50), r = ur(-20, 20), p = ur(0.01, 5);
        double o[7]; o[0] = k1(y, x); o[1] = k2(a, r); o[2] = k3(a, b); o[3] = k4(a); o[4] = k5(a, r / 20); o[5] = k6(a); o[6] = k7(p, b);
        for (int j = 0; j < 7; j++) { unsigned long long u; memcpy(&u, &o[j], 8); h = (h ^ u) * 1099511628211ull; }
#if defined(__x86_64__)
        double e[7];
        cw(0x027F);
        volatile ld t;
        t = L(hulk_x87_atan2_ext(y, x)) * (ld)57.29577951308232; e[0] = (float)(double)t;
        t = L(hulk_x87_sin_ext(a)) * (ld)r; e[1] = (double)t + 1.0;
        t = (ld)hulk_x87_sin(a) * L(hulk_x87_cos_ext(b)); e[2] = (double)t;
        e[3] = (float)L(hulk_x87_sin_ext(a));
        e[4] = L(hulk_x87_sin_ext(a)) > (ld)(r / 20);
        t = (ld)1.0 / L(hulk_x87_cos_ext(a)); e[5] = (double)t;
        t = (ld)b - L(hulk_x87_pow_ext(p, 0.75)); e[6] = (double)t;
        cw(0x037F);
        for (int j = 0; j < 7; j++) if (memcmp(&e[j], &o[j], 8)) bad[j]++;
#endif
    }
#if defined(__x86_64__)
    printf("vs x87 PC53 reference, mismatches of %ld: k1 %ld k2 %ld k3 %ld k4 %ld k5 %ld k6 %ld k7 %ld\n", n, bad[0], bad[1], bad[2], bad[3], bad[4], bad[5], bad[6]);
#endif
    printf("hash %016llx\n", h);
}
