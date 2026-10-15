struct Result {
    char pad[0x1f50];
    unsigned char value;
};
struct X {
    Result* get(unsigned __int64);
    unsigned char fn(int);
};
extern "C" unsigned __int64 __cdecl lookup(int, int, int);
unsigned char X::fn(int a) {
    unsigned __int64 v = lookup(a, 0, 0);
    Result* p = get(v);
    if (!p)
        return 0;
    return p->value;
}