typedef unsigned int uint;
unsigned int FUN_00329060(char *s) {
    unsigned int h = 0;
    char c = *s;
    while (c != 0) {
        h = h * 16 + (int)c;
        s++;
        unsigned int t = h & 0xf0000000;
        if (t) {
            unsigned int u = t ^ (t >> 24);
            h ^= u;
        }
        c = *s;
    }
    return h;
}
