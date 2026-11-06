typedef struct { int i; unsigned u; short s; unsigned short us; signed char c; unsigned char uc; char pad[2];
                 long long ll; unsigned long long ull; int ill; unsigned ull32; int fi; unsigned cmp; } R;
void conv(const double* in, R* out, int n) {
    for (int k = 0; k < n; k++) {
        double x = in[k]; float f = (float)x;
        out[k].i = (int)x; out[k].u = (unsigned)x; out[k].s = (short)x; out[k].us = (unsigned short)x;
        out[k].c = (signed char)x; out[k].uc = (unsigned char)x; out[k].ll = (long long)x;
        out[k].ull = (unsigned long long)x; out[k].ill = (int)(long long)x; out[k].ull32 = (unsigned)(long long)x;
        out[k].fi = (int)f;
        out[k].cmp = (x < 1.0) | (x > 1.0) << 1 | (x == x) << 2 | (x != 1.0) << 3 | (!(x >= 1.0)) << 4 | (x <= 1.0) << 5;
    }
}
