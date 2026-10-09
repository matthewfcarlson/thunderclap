extern "C" unsigned int __cdecl FUN_0024c590(unsigned int* p, unsigned int x);
extern unsigned int DAT_004cc254[];
extern unsigned int DAT_004cc258[];
unsigned int __cdecl FUN_0024c590(unsigned int* p, unsigned int x) {
    unsigned int u = p[0];
    unsigned int v = (u >> 9) & 0x1ffff;
    unsigned int r = ((x % 1000) * v) / 1000 + (x / 1000) * v;
    int i = (int)(u << 28) >> 28;
    unsigned int d = DAT_004cc254[i * 6];
    unsigned int n = (u >> 4 & 31) * DAT_004cc258[i * 6];
    return ((r % d) * n) / d + (r / d) * n;
}