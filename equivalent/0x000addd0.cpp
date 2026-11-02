// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_000addd0 @ 0x000addd0
struct Bounds_addd0 {
    float v[15];
};

union FloatBits_addd0 {
    float f;
    unsigned int u;
};

static float abs_bits(float x)
{
    FloatBits_addd0 b;
    b.f = x;
    b.u &= 0x7fffffff;
    return b.f;
}

extern "C" void FUN_000addd0(void *dst, const void *src)
{
    int i;

    for (i = 0; i < 11; i++) {
        if (((const Bounds_addd0 *)src)->v[i] > ((Bounds_addd0 *)dst)->v[i])
            ((Bounds_addd0 *)dst)->v[i] = ((const Bounds_addd0 *)src)->v[i];
    }
    for (i = 11; i < 15; i++) {
        if (abs_bits(((const Bounds_addd0 *)src)->v[i]) > abs_bits(((Bounds_addd0 *)dst)->v[i]))
            ((Bounds_addd0 *)dst)->v[i] = ((const Bounds_addd0 *)src)->v[i];
    }
}
