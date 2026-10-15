struct Result {
    char pad[0x1b40];
    unsigned long long value;
};
struct Obj {
    Result* get(unsigned long long);
    void fn(int, int);
};
extern "C" unsigned long long __cdecl first(int, int, int);
extern "C" unsigned long long __cdecl second(int);
void Obj::fn(int x, int y) {
    unsigned long long a = first(x, 0, 0);
    Result* r = get(a);
    if (r)
        r->value = second(y);
}