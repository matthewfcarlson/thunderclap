struct Pair_1e9bc0 {
    int a;
    int b;
};
extern Pair_1e9bc0* g_pairs;
bool FUN_001e9bc0(int a, int b) {
    for (int i = 0; i < 28; ++i) {
        if (a == g_pairs[i].a && b == g_pairs[i].b)
            return true;
    }
    return false;
}