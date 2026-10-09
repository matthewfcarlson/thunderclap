void __stdcall Copy(char* dst, const char* src) {
    bool keep = true;
    char c;
    do {
        c = *src;
        if (!(c != 0 || keep)) break;
        keep = c != 0;
        *dst = c;
        ++dst;
        ++src;
    } while (1);
    *dst = 0;
}