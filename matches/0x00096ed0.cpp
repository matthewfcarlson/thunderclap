extern "C" unsigned __int64 f1(unsigned int);
extern "C" unsigned __int64 f2(unsigned int, unsigned __int64);
extern "C" int f3(char*, unsigned int, const char*, ...);
extern char buf[];
extern const char fmt[];
char* target(unsigned int a, unsigned int b) {
    unsigned __int64 n = f2(b, f1(a));
    f3(buf, 64, fmt, (unsigned int)(n >> 32), (unsigned int)n);
    return buf;
}
