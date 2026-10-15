struct Item {
    char pad[0x1d24];
    int value;
};
struct Obj {
    Item* Find(unsigned long long x);
    void Set(int id, int val);
};
extern "C" unsigned long long __cdecl Convert(int x, int a, int b);
void Obj::Set(int id, int val) {
    unsigned long long k = Convert(id, 0, 0);
    Item* p = Find(k);
    if (p)
        p->value = val;
}