struct Result {
    char pad[0x1d40];
    char flag;
};
struct Obj {
    Result* get(unsigned long long v);
    void target(int id, char flag);
};
extern "C" unsigned long long __cdecl convert(int id, int a, int b);
void Obj::target(int id, char flag) {
    unsigned long long v = convert(id, 0, 0);
    Result* r = get(v);
    if (r)
        r->flag = flag;
}