typedef unsigned int uint_335270;
uint_335270 FUN_00335270(uint_335270 x) {
    return (x & 0xff00 | x << 16) << 8 | (x & 0xff0000 | x >> 16) >> 8;
}