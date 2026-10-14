extern "C" unsigned long long __cdecl FUN_0027b020(const char*);
extern int g_a;
extern int g_b;

void __cdecl FUN_0035e460() {
    unsigned long long r = FUN_0027b020("waypoint");
    g_a = (int)r;
    g_b = (int)(r >> 32);
}
