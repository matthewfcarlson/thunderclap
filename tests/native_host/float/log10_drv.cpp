// tests/native_host/native_float_test.py "log10": softx87's log10 (the original's fldlg2; fxch; fyl2x) on the doubles given
// as 16 hex digits per line on stdin; prints "x e80 f db" per line: the 80-bit result (sign/exponent, mantissa), the result
// stored as a float, and the result times 10.0f at 53-bit precision stored as a float (FUN_00258f90's dB conversion).
#include "softx87.h"

#include <stdio.h>
#include <string.h>

int main() {
    char buf[64];
    hulk_x87_ext ten = hulk_x87_from_float(10.0f);
    while (fgets(buf, sizeof buf, stdin)) {
        unsigned long long b;
        if (sscanf(buf, "%llx", &b) != 1) continue;
        double x;
        memcpy(&x, &b, 8);
        hulk_x87_ext r = hulk_x87_log10_ext(x);
        float f = hulk_x87_to_float(r), db = hulk_x87_to_float(hulk_x87_fmul(r, ten, 53));
        unsigned fb, dbb;
        memcpy(&fb, &f, 4);
        memcpy(&dbb, &db, 4);
        printf("%016llx %04x%016llx %08x %08x\n", b, r.se, r.m, fb, dbb);
    }
    return 0;
}
