extern const char s0[];
extern const char s1[];
extern const char s2[];
extern const char s3[];
extern const char s4[];
extern const char s5[];
extern const char s6[];
extern const char s7[];
extern const char s8[];
extern const char s9[];
extern const char s10[];
extern const char s11[];
extern const char s12[];
extern const char s13[];
const char* f(int x) {
    if (x == 1)
        return s13;
    if (x == 3)
        return s12;
    if (x == 2)
        return s11;
    if (x == 4)
        return s10;
    if (x == 8)
        return s9;
    if (x == 7)
        return s8;
    if (x == 6)
        return s7;
    if (x == 5)
        return s6;
    if (x == 9)
        return s5;
    if (x == 10)
        return s4;
    if (x == 11)
        return s3;
    if (x == 12)
        return s2;
    if (x == 13)
        return s0;
    return 0;
}