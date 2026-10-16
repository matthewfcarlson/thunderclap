int Hash(char* s, int h) {
    if (s) {
        while (*s) {
            char c = *s;
            h = h * 31 + (c < 'a' ? c + 32 : c);
            ++s;
        }
    }
    return h;
}