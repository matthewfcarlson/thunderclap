extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct Src {
    int a;
    char b;
};
struct Dst {
    char pad[8];
    int flags;
    char pad2[0x38];
    Src value;
};
void __cdecl FUN_002eb4f0(void* p, Dst* d, Src* s) {
    if (p && d) {
        memcpy(&d->value, s, 5);
        d->flags |= 2;
    }
}