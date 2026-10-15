struct Result {
    char pad[0x318];
    int value;
};
struct X {
    void target(int, int);
    Result* lookup(unsigned __int64);
};
extern "C" unsigned __int64 __cdecl FUN_002672f0(int, int, int);
void X::target(int a, int b) {
    unsigned __int64 n = FUN_002672f0(a, 0, 0);
    Result* r = lookup(n);
    if (r)
        r->value = b;
}