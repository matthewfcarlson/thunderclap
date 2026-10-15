struct Item {
    char pad[0x39c];
    int value;
};
struct Owner {
    Item* Lookup(__int64);
    int Fn(int);
};
extern "C" __int64 __cdecl Convert(int, int, int);
int Owner::Fn(int x) {
    __int64 k = Convert(x, 0, 0);
    Item* p = Lookup(k);
    if (!p)
        return 0;
    return p->value;
}