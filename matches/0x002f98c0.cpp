// Same code shape as 0x002b0de0 (propagated; names are from that function)
typedef unsigned int U_2f98c0;
extern "C" unsigned int * __cdecl FUN_002f98c0(unsigned int * dst, unsigned int count, unsigned int * src) {
    if (count) {
        for (; count; --count) {
            if (dst) {
                dst[0] = src[0];
                dst[1] = src[1];
            }
            dst += 2;
        }
        return dst;
    }
    return dst;
}
