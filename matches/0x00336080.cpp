extern "C" long __cdecl atol(const char*);
struct Obj {
    const char* Get();
};
unsigned char __stdcall FUN_00336080(long** volatile p, Obj* out, int x, unsigned char flag) {
    const char* s = out->Get();
    if (!s)
        return 0;
    if (flag) {
        *p = (long*)atol(s);
        return 1;
    }
    long* q = *p;
    *q = atol(s);
    return 1;
}