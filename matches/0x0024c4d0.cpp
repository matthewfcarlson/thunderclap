struct Entry {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};
extern Entry tab[];
unsigned __cdecl FUN_0024c4d0(unsigned* p, unsigned n) {
    unsigned x = *p;
    int i = (int)(x << 28) >> 28;
    unsigned d = ((x >> 4) & 31) * tab[i].b;
    unsigned q = n / d;
    unsigned r = n % d;
    unsigned v = tab[i].a;
    unsigned z = q * v;
    return z + r * v / d;
}