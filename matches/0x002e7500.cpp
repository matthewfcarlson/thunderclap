unsigned int FUN_002e7500(unsigned char* p) {
    unsigned int v = p[0];
    v = (v << 8) + p[1];
    v = (v << 8) + p[2];
    v = (v << 8) + p[3];
    return v;
}