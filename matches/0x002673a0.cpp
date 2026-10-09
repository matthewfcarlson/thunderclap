int FUN_002673a0(char* s, int h) {
    if (s != 0) {
        char c = *s;
        while (c != 0) {
            h = h * 0x1f + (int)c;
            ++s;
            c = *s;
        }
    }
    return h;
}