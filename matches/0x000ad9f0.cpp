extern "C" void* __cdecl memset(void*, int, unsigned int);
struct FUN {
    char pad[0x18];
    unsigned int a[17];
    unsigned int b[17];
    char gap[0x0c];
    unsigned int c[17];
    unsigned int d[17];
};
void __fastcall FUN_000ad9f0(FUN* p) {
    memset(p->a, 0, 68);
    memset(p->b, 0, 68);
    memset(p->c, 0, 68);
    memset(p->d, 0, 68);
}