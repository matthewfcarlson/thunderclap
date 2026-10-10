int FUN_00294c70(char* src, unsigned short* dst, int limit) {
    int i;
    if (dst == 0 || src == 0)
        return 0;
    unsigned char c = (unsigned char)src[0];
    i = 0;
    if (c != 0) {
        int m = limit - 1;
        do {
            if (i >= m)
                break;
            unsigned int v = (char)src[i];
            dst[i] = (unsigned short)(0xff & v);
            c = (unsigned char)src[i + 1];
            ++i;
        } while (c != 0);
    }
    dst[i] = 0;
    return i;
}
