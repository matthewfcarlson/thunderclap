typedef unsigned int U32_30bf40;
extern "C" unsigned int * FUN_0030bf40(unsigned int * src, int count, unsigned int * dst) {
    U32_30bf40* out = dst;
    if (count != 0) {
        do {
            if (out != 0)
                *out = *src;
            ++src;
            ++out;
        } while (--count != 0);
    }
    return out;
}