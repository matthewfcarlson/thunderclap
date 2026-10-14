// STATUS: equivalent (tools/equiv.py level 3: 1476 inputs, branch coverage 4/4)
// FUN_00342e50 @ 0x00342e50
// Real-FFT forward post-processing pass (rftbsub of an Ooura-style FFT).
// c (twiddle table) arrives in eax and a (data) in esi.
// equiv-conv: FUN_00342e50 eax esi stack stack
void __cdecl FUN_00342e50(float *c, float *a, int n, int nc)
{
    int m = n >> 1;
    int ks = 2 * nc / m;
    int kk = 0;
    for (int j = 2; j < m; j += 2) {
        int k = n - j;
        kk += ks;
        float wkr = 0.5f - c[nc - kk];
        float wki = c[kk];
        float xr = a[j] - a[k];
        float xi = a[j + 1] + a[k + 1];
        float yr = wkr * xr + wki * xi;
        float yi = wkr * xi - wki * xr;
        a[j] -= yr;
        a[j + 1] -= yi;
        a[k] += yr;
        a[k + 1] -= yi;
    }
}
