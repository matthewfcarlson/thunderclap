struct Item {
    char pad[0x1d05];
    char flag;
};
struct Obj {
    Item* Get(unsigned long long x);
    void Set(int a, unsigned char b);
};
extern "C" unsigned long long __cdecl Make(int, int, int);
void Obj::Set(int a, unsigned char b) {
    unsigned long long x = Make(a, 0, 0);
    Item* p = Get(x);
    if (p)
        p->flag = b;
}