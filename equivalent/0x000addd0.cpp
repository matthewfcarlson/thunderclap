// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_000addd0 @ 0x000addd0
struct Bounds {
    float v[15];
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

void FUN_000addd0(Bounds *dst, const Bounds *src)
{
    int i;

    for (i = 0; i < 11; i++) {
        if (src->v[i] > dst->v[i])
            dst->v[i] = src->v[i];
    }
    for (i = 11; i < 15; i++) {
        if (abs_bits(src->v[i]) > abs_bits(dst->v[i]))
            dst->v[i] = src->v[i];
    }
}
