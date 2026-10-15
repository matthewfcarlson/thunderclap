extern "C" void* memset(void*, int, unsigned);
struct X {
    int a, b, c, d, e, f;
    X(int v);
};
X::X(int v) {
    memset(this, 0, sizeof(*this));
    a = 24;
    b = 25;
    f = v;
}