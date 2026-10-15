struct Result {
    char pad[0x1d20];
    int value;
};
struct X {
    Result* lookup(__int64);
    void set(int a, int b);
};
extern "C" __int64 __cdecl convert(int, int, int);
void X::set(int a, int b) {
    __int64 v = convert(a, 0, 0);
    Result* r = lookup(v);
    if (r)
        r->value = b;
}