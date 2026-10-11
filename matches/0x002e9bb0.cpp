class Thing {
    char pad[0x60];

  public:
    unsigned int flags;
};
extern void Init(Thing*, const char*);
extern char* Alloc(Thing*, unsigned int);
extern void Op(Thing*, char*, unsigned int);
extern int Check(Thing*, int);
extern void Free(Thing*, char*);
extern void Make(Thing*, void*, void*, int);
void FUN(Thing* a, void* x, unsigned int n) {
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
