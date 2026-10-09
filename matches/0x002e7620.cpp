extern void Error(unsigned int, const char*);
void Check(unsigned int unused, const char* s) {
    unsigned char c;
    c = (unsigned char)s[0];
    if (c < 0x29 || c > 0x7a || (c > 0x5a && c < 0x61)) {
        Error(unused, "invalid chunk type");
        return;
    }
    c = (unsigned char)s[1];
    if (c < 0x29 || c > 0x7a || (c > 0x5a && c < 0x61)) {
        Error(unused, "invalid chunk type");
        return;
    }
    c = (unsigned char)s[2];
    if (c < 0x29 || c > 0x7a || (c > 0x5a && c < 0x61)) {
        Error(unused, "invalid chunk type");
        return;
    }
    c = (unsigned char)s[3];
    if (c < 0x29 || c > 0x7a || (c > 0x5a && c < 0x61)) {
        Error(unused, "invalid chunk type");
        return;
    }
}