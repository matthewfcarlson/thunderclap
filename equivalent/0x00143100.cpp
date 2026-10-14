// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00143100 @ 0x00143100
class RandomGen {
public:
    unsigned int z;
    unsigned int w;
    float FUN_00143100();
};
union FloatBits_143100 {
    float f;
    unsigned int u;
};
float RandomGen::FUN_00143100() {
    z = (z & 0xffff) * 0x9069 + (z >> 16);
    w = (w & 0xffff) * 0x4650 + (w >> 16);
    unsigned int r = (z << 16) + (w & 0xffff);
    FloatBits_143100 b;
    b.u = (r & 0x7fffff) | 0x3f800000;
    b.f = b.f - 1.0f;
    b.u |= r & 0x80000000;
    return b.f;
}
