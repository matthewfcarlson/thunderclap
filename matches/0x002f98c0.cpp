// Same code shape as 0x002b0de0 (propagated; names are from that function)
typedef unsigned int U;
U* __cdecl FUN_002b0de0(U* dst, unsigned int count, U* src) {
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
