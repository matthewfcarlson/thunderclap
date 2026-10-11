// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_000adf20 @ 0x000adf20
struct Bounds {
    float v[17];
};

union FloatBits {
    float f;
    unsigned int u;
};

static float abs_bits(float x)
{
    FloatBits b;
    b.f = x;
    b.u &= 0x7fffffff;
    return b.f;
}

void FUN_000adf20(Bounds *dst, const Bounds *src)
{
    int i;

    for (i = 0; i < 13; i++) {
        if (src->v[i] > dst->v[i])
            dst->v[i] = src->v[i];
    }
    for (i = 13; i < 17; i++) {
        if (abs_bits(src->v[i]) > abs_bits(dst->v[i]))
            dst->v[i] = src->v[i];
    }
}
