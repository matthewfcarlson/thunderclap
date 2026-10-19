unsigned* f(unsigned* p, unsigned a, unsigned b, unsigned c) {
    *p = ((((b & 0x1ffff | 0x200000) << 5 | c & 0x1f) << 4) | (*(volatile unsigned*)p & 0xc0000000)) |
         (a & 0xf);
    return p;
}