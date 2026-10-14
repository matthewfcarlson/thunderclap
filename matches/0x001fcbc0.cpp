struct X_1fcbc0 {
    char pad[0xce];
    char m;
};
X_1fcbc0* __stdcall FUN_001fc7f0(void* p);
void __stdcall FUN_001fcbc0(void* p, char c) {
    X_1fcbc0* q = FUN_001fc7f0(p);
    if (q)
        q->m = c;
}
