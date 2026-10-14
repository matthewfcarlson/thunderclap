struct V {
    void* a;
    void(__cdecl* b)(void*, int);
};
extern V* g_247530;
void target(int x) {
    g_247530->b(g_247530, x);
}
