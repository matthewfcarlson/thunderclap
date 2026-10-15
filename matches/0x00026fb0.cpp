struct Found {
    char pad[0x1ca0];
    struct Inner* inner;
};
struct Inner {
    char pad[0x118];
    void Run(int);
};
struct Obj {
    Found* Lookup(unsigned long long);
    void Func(int, int);
};
extern "C" unsigned long long __cdecl Search(int, int, int);
void Obj::Func(int a, int b) {
    unsigned long long v = Search(a, 0, 0);
    Found* f = Lookup(v);
    if (f && f->inner)
        ((Inner*)((char*)f->inner + 0x118))->Run(b);
}