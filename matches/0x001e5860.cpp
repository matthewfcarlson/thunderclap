struct V {
    float x, y, z;
    V() : x(0), y(0), z(0) {}
};
struct C_1e5860 {
    void inner(int, int, V, V);
    void target(int a, int b, V v);
};
void C_1e5860::target(int a, int b, V v) {
    V zero;
    inner(a, b, v, zero);
}