#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct { int i; unsigned u; short s; unsigned short us; signed char c; unsigned char uc; char pad[2];
                 long long ll; unsigned long long ull; int ill; unsigned ull32; int fi; unsigned cmp; } R;
void conv(const double* in, R* out, int n);
#include VALS
int main(void) {
    int n = sizeof(V) / sizeof(V[0]); static R r[4000]; memset(r, 0, sizeof r); conv(V, r, n);
    for (int k = 0; k < n; k++)
        printf("%-22.17g i=%08x u=%08x s=%04hx us=%04hx c=%02hhx uc=%02hhx ll=%016llx ull=%016llx ill=%08x ull32=%08x fi=%08x cmp=%02x\n", V[k],
               r[k].i, r[k].u, r[k].s, r[k].us, r[k].c, r[k].uc, r[k].ll, r[k].ull, r[k].ill, r[k].ull32, r[k].fi, r[k].cmp);
}
