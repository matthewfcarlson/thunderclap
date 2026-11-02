extern "C" int FUN_002673d0(char* s, int h) {
    if (s) {
        while (*s) {
            char c = *s;
            h = h * 31 + (c < 'a' ? c + 32 : c);
            ++s;
        }
    }
    return h;
}