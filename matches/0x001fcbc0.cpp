struct X {
    char pad[0xce];
    char m;
};
X* __stdcall FUN_001fc7f0(void* p);
void __stdcall FUN_001fcbc0(void* p, char c) {
    X* q = FUN_001fc7f0(p);
    if (q)
        q->m = c;
}
