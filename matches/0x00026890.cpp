struct Obj {
    void Func(int);
};
struct Owner {
    Obj* Find(unsigned long long);
    bool Run(int, int);
};
extern "C" unsigned long long __cdecl Parse(int, int, int);
bool Owner::Run(int a, int b) {
    unsigned long long x = Parse(a, 0, 0);
    Obj* p = Find(x);
    if (!p)
        return false;
    p->Func(b);
    return true;
}