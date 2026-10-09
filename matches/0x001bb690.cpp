void* operator new(unsigned int) throw();
struct Info {};
extern Info gInfo;
char GetFlag(Info*) throw();
struct Root {
    Root(void* h, int z) throw();
    virtual void Run();
    char pad[0x14];
};
struct M : Root {
    char f;
    int a;
    int b;
    M(void* h, int y, int x) throw() : Root(h, 0) {
        a = y;
        f = GetFlag(&gInfo);
        b = x;
    }
};
struct C : M {
    virtual void Run();
    C(void* h, int y, int x) throw() : M(h, y, x) {}
};
struct Owner {
    void Make(void* h, int x, int y);
    void Reg(void* h, M* c);
};
void Owner::Make(void* h, int x, int y) {
    C* c = new C(h, y, x);
    Reg(h, c);
}