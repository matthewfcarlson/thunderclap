extern "C" void* __cdecl memset(void*, int, unsigned int);
struct X {
    int a, b, c, d, e, f;
    X(int x);
};
X::X(int x) {
    memset(this, 0, 24);
    a = 0x18;
    b = 0x1a;
    f = x;
}