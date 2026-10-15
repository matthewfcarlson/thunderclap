struct Result {
    void get(void*);
};
struct X {
    Result* find(unsigned __int64);
    void fn(int a, int b, int c, int d);
};
extern "C" unsigned __int64 __cdecl makekey(int, int, int);
void X::fn(int a, int b, int c, int d) {
    unsigned __int64 key = makekey(a, 0, 0);
    Result* r = find(key);
    if (r)
        r->get(&b);
}