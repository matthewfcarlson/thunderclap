extern "C" void* memset(void*, int, unsigned int);
struct X {
    int a, b, c, d, e, f;
    X(int);
};
X::X(int x) {
    memset(this, 0, 24);
    a = 24;
    b = 13;
    f = x;
}