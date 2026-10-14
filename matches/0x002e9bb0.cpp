class Thing_2e9bb0 {
    char pad[0x60];

  public:
    unsigned int flags;
};
extern void Init(Thing_2e9bb0*, const char*);
extern char* Alloc(Thing_2e9bb0*, unsigned int);
extern void Op(Thing_2e9bb0*, char*, unsigned int);
extern int Check(Thing_2e9bb0*, int);
extern void Free(Thing_2e9bb0*, char*);
extern void Make(Thing_2e9bb0*, void*, void*, int);
void FUN(Thing_2e9bb0* a, void* x, unsigned int n) {
    if (!(a->flags & 1))
        Init(a, "Missing IHDR before tEXt");
    if (a->flags & 4)
        a->flags |= 8;
    char* b = Alloc(a, n + 1);
    Op(a, b, n);
    if (Check(a, 0)) {
        Free(a, b);
        return;
    }
    b[n] = 0;
    char* e = b;
    while (*e)
        ++e;
    if (e != b + n)
        ++e;
    void* q = Alloc(a, 16);
    ((int*)q)[0] = -1;
    ((char**)q)[1] = b;
    ((char**)q)[2] = e;
    Make(a, x, q, 1);
    Free(a, (char*)q);
}
