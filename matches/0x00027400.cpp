struct Item {
    char pad[0x1d18];
    int value;
};
struct Obj {
    Item* get(unsigned a, unsigned b);
    void fn(int x, int y);
};
extern "C" unsigned __int64 __cdecl decode(int, int, int);
void Obj::fn(int x, int y) {
    unsigned __int64 n = decode(x, 0, 0);
    Item* p = get((unsigned)n, (unsigned)(n >> 32));
    if (p)
        p->value = y;
}