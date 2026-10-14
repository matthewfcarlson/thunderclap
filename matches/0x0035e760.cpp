extern "C" unsigned long long hash(const char*);
extern int g_hi;
extern int g_lo;
void FUN_0035e760() {
    unsigned long long r = hash("$MACRO_DEFINE");
    g_hi = (int)r;
    g_lo = (int)(r >> 32);
}
