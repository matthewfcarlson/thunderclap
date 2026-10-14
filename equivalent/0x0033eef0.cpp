// STATUS: equivalent (tools/equiv.py level 3: 200 inputs, branch coverage 6/6)
// FUN_0033eef0 @ 0x0033eef0
// 0x0033eef0: fill the first half of a cos/sin table (quarter-wave steps) for an n-point transform
// equiv-conv: FUN_0033eef0 eax edx esi
extern "C" double atan(double);
extern "C" double cos(double);
extern "C" double sin(double);

struct Table {
    int pad;
    int n;
};

void FUN_0033eef0(Table* t, int n, float* out)
{
    t->n = n;
    if (n <= 1)
        return;
    int half = n >> 1;
    float step = (float)(atan(1.0) / half);
    float c = (float)cos(half * step);
    out[0] = c;
    out[half] = c * 0.5f;
    for (int i = 1; i < half; i++) {
        out[i] = (float)(cos(i * step) * 0.5);
        out[n - i] = (float)(sin(i * step) * 0.5);
    }
}
