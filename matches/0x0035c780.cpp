extern "C" unsigned long long __cdecl FUN_0027b020(const char*);
extern int g0;
extern int g1;
void FUN_0035c780() {
    unsigned long long r = FUN_0027b020("apache");
    g0 = (int)r;
    g1 = (int)(r >> 32);
}
