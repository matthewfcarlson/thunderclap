// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_000adf20 @ 0x000adf20
struct Bounds_adf20 {
    float v[17];
};

union FloatBits_adf20 {
    float f;
    unsigned int u;
};

static float abs_bits(float x)
{
    FloatBits_adf20 b;
    b.f = x;
    b.u &= 0x7fffffff;
    return b.f;
}

extern "C" void FUN_000adf20(void *dst, const void *src)
{
    int i;

    for (i = 0; i < 13; i++) {
        if (((const Bounds_adf20 *)src)->v[i] > ((Bounds_adf20 *)dst)->v[i])
            ((Bounds_adf20 *)dst)->v[i] = ((const Bounds_adf20 *)src)->v[i];
    }
    for (i = 13; i < 17; i++) {
        if (abs_bits(((const Bounds_adf20 *)src)->v[i]) > abs_bits(((Bounds_adf20 *)dst)->v[i]))
            ((Bounds_adf20 *)dst)->v[i] = ((const Bounds_adf20 *)src)->v[i];
    }
}
