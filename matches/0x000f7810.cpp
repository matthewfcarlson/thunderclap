typedef unsigned short ushort_f7810;
typedef unsigned char uchar_f7810;
void FUN_000f7810(const ushort_f7810* src, uchar_f7810* dst) {
    if (*src != 0) {
        do {
            *dst = (uchar_f7810)*src;
            ++src;
            ++dst;
        } while (*src != 0);
    }
    *dst = 0;
}