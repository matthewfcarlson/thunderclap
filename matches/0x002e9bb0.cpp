class Thing_2e9bb0 {
    char pad[0x60];

  public:
    unsigned int flags;
};
extern void FUN_002e69a0(Thing_2e9bb0*, const char*);
extern char* FUN_002e6c00(Thing_2e9bb0*, unsigned int);
extern void FUN_002e7580(Thing_2e9bb0*, char*, unsigned int);
extern int FUN_002e81e0(Thing_2e9bb0*, int);
extern void FUN_002e6c40(Thing_2e9bb0*, char*);
extern void FUN_002eb5e0(Thing_2e9bb0*, void*, void*, int);
void FUN(Thing_2e9bb0* a, void* x, unsigned int n) {
    if (!(a->flags & 1))
        FUN_002e69a0(a, "Missing IHDR before tEXt");
    if (a->flags & 4)
        a->flags |= 8;
    char* b = FUN_002e6c00(a, n + 1);
    FUN_002e7580(a, b, n);
    if (FUN_002e81e0(a, 0)) {
        FUN_002e6c40(a, b);
        return;
    }
    b[n] = 0;
    char* e = b;
    while (*e)
        ++e;
    if (e != b + n)
        ++e;
    void* q = FUN_002e6c00(a, 16);
    ((int*)q)[0] = -1;
    ((char**)q)[1] = b;
    ((char**)q)[2] = e;
    FUN_002eb5e0(a, x, q, 1);
    FUN_002e6c40(a, (char*)q);
}
