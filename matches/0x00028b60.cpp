struct Result {
    char pad[0x1e58];
    float value;
};
struct Obj {
    Result* lookup(unsigned long long);
    float get(int);
};
extern "C" unsigned long long __cdecl acquire(int, int, int);
float Obj::get(int x) {
    unsigned long long v = acquire(x, 0, 0);
    Result* r = lookup(v);
    if (!r)
        return 0.0f;
    return r->value;
}