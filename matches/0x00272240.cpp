typedef unsigned char byte;
typedef unsigned int uint;
extern unsigned short g_code;
extern "C" bool __cdecl FUN_00272240(byte* p, uint* count, uint* value) {
    byte b = *p;
    uint v;
    uint n;
    if (b <= 0x7f) {
        v = (uint)b;
        n = 1;
    } else if (b >= 0xa1 && b <= 0xdf) {
        v = (uint)b + 0xfec0;
        n = 1;
    } else if (((b >= 0x81 && b <= 0x9f) || (b >= 0xe0 && b <= 0xfc)) && p[1] >= 0x40 && p[1] <= 0xfc &&
               p[1] != 0x7f) {
        v = g_code;
        n = 2;
    } else
        return false;
    if (count)
        *count = n;
    if (value)
        *value = v;
    return true;
}