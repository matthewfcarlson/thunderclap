struct Item {
    char pad[0x1b68];
    int a, b, c;
};
struct Owner {
    Item* Get(__int64);
    void Fn(int);
};
extern "C" __int64 __cdecl Convert(int, int, int);
void Owner::Fn(int x) {
    __int64 v = Convert(x, 0, 0);
    Item* p = Get(v);
    if (p) {
        p->a = 0;
        p->b = 0;
        p->c = 0;
    }
}