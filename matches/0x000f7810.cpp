typedef unsigned short ushort;
typedef unsigned char uchar;
void FUN_000f7810(const ushort* src, uchar* dst)
{
    if (*src != 0) {
        do {
            *dst = (uchar)*src;
            ++src;
            ++dst;
        } while (*src != 0);
    }
    *dst = 0;
}