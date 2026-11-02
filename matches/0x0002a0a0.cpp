// b..d: a 3-word vector passed by value.
struct Vec3_2a0a0 {
    int x, y, z;
};
struct Result {
    void get(void*);
};
struct X {
    Result* find(unsigned __int64);
    void fn(int a, Vec3_2a0a0 b);
};
extern "C" unsigned __int64 __cdecl makekey(int, int, int);
void X::fn(int a, Vec3_2a0a0 b) {
    unsigned __int64 key = makekey(a, 0, 0);
    Result* r = find(key);
    if (r)
        r->get(&b);
}