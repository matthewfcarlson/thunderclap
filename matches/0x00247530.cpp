struct V {
    void* a;
    int(__cdecl* b)(void*, int);
};
extern V* g_247530;
int target(int x) {
    return g_247530->b(g_247530, x);
}
