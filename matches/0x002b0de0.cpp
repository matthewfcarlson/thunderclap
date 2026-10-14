typedef unsigned int U_2b0de0;
U_2b0de0* __cdecl FUN_002b0de0(U_2b0de0* dst, unsigned int count, U_2b0de0* src) {
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
