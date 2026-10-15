extern const char fmt[];
extern const char newline[];
extern "C" char print(const char*, const char*, ...);
extern "C" char other(const char**, const char*);
char target(const char** p, const char* s, const char** q) {
    const char* v = *p;
    if (print(v, fmt, s) && other(p, *q)) {
        v = *p;
        return print(v, newline);
    }
    return 0;
}
