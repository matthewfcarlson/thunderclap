// STATUS: equivalent (tools/equiv.py level 3: 17528 inputs, branch coverage 32/34, incomplete)
// FUN_0033ef80 @ 0x0033ef80
// FUN_0033ef80 @ 0x0033ef80
// equiv-conv: FUN_0033ef80 ecx stack eax
// Swap the complex pairs at a[j1] and a[k1]. All four values are read before any is written, because
// the arrays may overlap (the original does it this way).
static __forceinline void SwapPair(float *a, int j1, int k1)
{
    float xr = a[j1];
    float xi = a[j1 + 1];
    float yr = a[k1];
    float yi = a[k1 + 1];
    a[j1] = yr;
    a[j1 + 1] = yi;
    a[k1] = xr;
    a[k1 + 1] = xi;
}

void FUN_0033ef80(int n, int *ip, float *a)
{
    int j, j1, k, k1, l, m, m2;

    ip[0] = 0;
    l = n;
    m = 1;
    while ((m << 3) < l) {
        l >>= 1;
        for (j = 0; j < m; j++)
            ip[m + j] = ip[j] + l;
        m <<= 1;
    }
    m2 = 2 * m;
    if ((m << 3) == l) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 2 * j + ip[k];
                k1 = 2 * k + ip[j];
                SwapPair(a, j1, k1);
                j1 += m2;
                k1 += 2 * m2;
                SwapPair(a, j1, k1);
                j1 += m2;
                k1 -= m2;
                SwapPair(a, j1, k1);
                j1 += m2;
                k1 += 2 * m2;
                SwapPair(a, j1, k1);
            }
            j1 = 2 * k + m2 + ip[k];
            k1 = j1 + m2;
            SwapPair(a, j1, k1);
        }
    } else {
        for (k = 1; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 2 * j + ip[k];
                k1 = 2 * k + ip[j];
                SwapPair(a, j1, k1);
                j1 += m2;
                k1 += m2;
                SwapPair(a, j1, k1);
            }
        }
    }
}
