extern "C" unsigned long long hash(const char*);
extern int g_hi_35e760;
extern int g_lo_35e760;
void FUN_0035e760() {
    unsigned long long r = hash("$MACRO_DEFINE");
    g_hi_35e760 = (int)r;
    g_lo_35e760 = (int)(r >> 32);
}
