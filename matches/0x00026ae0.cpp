struct Result {
    char pad[0x1d7c];
    int value;
};
struct X {
    Result* lookup(unsigned long long);
    void set(int a, int b);
};
extern "C" unsigned long long __cdecl convert(int, int, int);
void X::set(int a, int b) {
    unsigned long long v = convert(a, 0, 0);
    Result* r = lookup(v);
    if (r)
        r->value = b;
}