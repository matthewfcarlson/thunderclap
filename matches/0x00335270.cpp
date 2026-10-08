typedef unsigned int uint;
uint FUN_00335270(uint x) {
    return (x & 0xff00 | x << 16) << 8 | (x & 0xff0000 | x >> 16) >> 8;
}