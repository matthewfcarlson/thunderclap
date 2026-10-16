struct Result {
    char pad[0x1a4];
    int value;
};
struct Mid {
    Result* Get(unsigned long long);
};
struct Obj {
    char pad[4];
    Mid* mid;
    void Fn(int, int);
};
extern "C" unsigned long long __cdecl Conv(int);
void Obj::Fn(int a, int b) {
    Mid* m = mid;
    unsigned long long n = Conv(a);
    Result* r = m->Get(n);
    r->value = b;
}