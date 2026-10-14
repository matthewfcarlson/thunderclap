typedef void(__fastcall* Callback_11520)(void*);
void __stdcall FUN_00011520(void* base, int stride, int count, Callback_11520 fn) {
    int n = count - 1;
    if (n >= 0) {
        int m = n + 1;
        do {
            fn(base);
            base = (char*)base + stride;
        } while (--m != 0);
    }
}
