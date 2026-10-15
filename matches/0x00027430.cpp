struct Item {
    char pad[0x1d1c];
    int value;
};
struct Obj {
    Item* get(unsigned __int64 x);
    void set(int a, int b);
};
extern "C" unsigned __int64 __cdecl make64(int a, int b, int c);
void Obj::set(int a, int b) {
    unsigned __int64 x = make64(a, 0, 0);
    Item* p = get(x);
    if (p)
        p->value = b;
}