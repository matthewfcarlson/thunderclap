extern "C" int logmsg(void*, const char*, ...);
extern const char fmt1[];
extern const char fmt2[];
extern const char* types[];
int compare_error(void* p, int* a, int* b) {
    const char* x = types[*a];
    const char* y = types[*b];
    if (x[2] == y[2]) {
        logmsg(p, fmt2, x);
        return 0;
    }
    logmsg(p, fmt1, x, y);
    return 0;
}