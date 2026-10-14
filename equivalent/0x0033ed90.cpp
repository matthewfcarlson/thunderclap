// STATUS: equivalent (tools/equiv.py level 3: 53 inputs, branch coverage 18/18)
// FUN_0033ed90 @ 0x0033ed90
extern "C" double __cdecl atan(double);
extern "C" double __cdecl cos(double);
extern "C" double __cdecl sin(double);

struct TwiddleTable_33ed90 {
    int size;
    int one;
};

/* Builds the FFT twiddle-factor table w[] for a transform of nw points (Ooura-style makewt). */
// equiv-conv: FUN_0033ed90 eax ecx edi
void FUN_0033ed90(TwiddleTable_33ed90 *ip, int nw, float *w)
{
    int nwh;
    int nw0;
    int nw1;
    int j;
    float delta;
    float wn_re;

    ip->size = nw;
    ip->one = 1;
    if (nw <= 2)
        return;

    nwh = nw >> 1;
    delta = (float)(atan(1.0) / nwh);
    w[0] = 1.0f;
    wn_re = (float)cos(nwh * delta);
    w[1] = wn_re;
    if (nwh >= 4) {
        w[2] = (float)(0.5 / cos(delta + delta));
        w[3] = (float)(0.5 / cos(delta * 6.0f));
    }
    for (j = 4; j < nwh; j += 4) {
        double x = j * delta;
        w[j] = (float)cos(x);
        w[j + 1] = (float)sin(x);
        x = (float)x * 3.0f;
        w[j + 2] = (float)cos(x);
        w[j + 3] = (float)sin(x);
    }

    nw0 = 0;
    while (nwh > 2) {
        nw1 = nw0 + nwh;
        nwh >>= 1;
        w[nw1] = 1.0f;
        w[nw1 + 1] = wn_re;
        if (nwh >= 4) {
            w[nw1 + 2] = 0.5f / w[nw0 + 4];
            w[nw1 + 3] = 0.5f / w[nw0 + 6];
            for (j = 4; j < nwh; j += 4) {
                w[nw1 + j] = w[nw0 + 2 * j];
                w[nw1 + j + 1] = w[nw0 + 2 * j + 1];
                w[nw1 + j + 2] = w[nw0 + 2 * j + 2];
                w[nw1 + j + 3] = w[nw0 + 2 * j + 3];
            }
        }
        nw0 = nw1;
    }
}
