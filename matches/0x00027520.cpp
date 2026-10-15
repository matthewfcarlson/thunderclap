struct Result {
    char pad[0x1d08];
    int value;
};
struct Obj {
    Result* get(int, int);
    void func(int a, int b);
};
extern "C" unsigned __int64 __cdecl FUN_002672f0(int, int, int);
void Obj::func(int a, int b) {
    unsigned __int64 x = FUN_002672f0(a, 0, 0);
    Result* r = get((int)x, (int)(x >> 32));
    if (r)
        r->value = b;
}