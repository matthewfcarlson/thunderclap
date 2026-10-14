int __cdecl FUN_002723c0(char* dst, const char* src) {
    unsigned int i = 0;
    if (src[0]) {
        do {
            unsigned char c = src[i];
            dst[i] = c;
            if ((c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xfc)) {
                c = src[i + 1];
                if (c < 0x40 || c > 0xfc || c == 0x7f) {
                    dst[i] = 0;
                    return -1;
                }
                dst[i + 1] = c;
                ++i;
            }
            c = src[i + 1];
            ++i;
            if (!c)
                break;
        } while (1);
    }
    dst[i] = 0;
    return i;
}