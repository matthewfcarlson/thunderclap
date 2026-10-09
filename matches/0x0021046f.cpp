// cl-flags: /Oy- /O1
struct I64 {
    int lo;
    int hi;
};

extern int(__stdcall* g_NtQuery)(void* h, void* iosb, void* buf, int size, int cls);
extern void __stdcall XapiSetLastNTError(int e);

int __stdcall FUN_0021046f(void* h, I64* a, I64* b, I64* c) {
    int buf[14];
    int iosb[2];
    int r = g_NtQuery(h, iosb, buf, 0x38, 0x22);
    if (r >= 0) {
        if (a) {
            a->lo = buf[0];
            a->hi = buf[1];
        }
        if (b) {
            b->lo = buf[2];
            b->hi = buf[3];
        }
        if (c) {
            c->lo = buf[4];
            c->hi = buf[5];
        }
        return 1;
    }
    XapiSetLastNTError(r);
    return 0;
}
