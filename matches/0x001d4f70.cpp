struct X {
    char pad[0xc0];
    unsigned long long value;
};
unsigned long long __fastcall FUN_001d4f70(X* p) {
    return p->value;
}