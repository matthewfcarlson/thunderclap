struct B {
    int x, y, z;
};
struct C {
    int x, y, z;
    void Init(int a);
    void Done();
};
struct M {
    char d[64];
    void Ident();
    void Set(B* b);
    void Set3(int a, int b, int c);
};
struct S {
    int Run(C* c, M* m, float f, int a);
};
S* GetS();
int __stdcall Fn(int a1, B b, C c, int a8) {
    S* s = GetS();
    M m;
    m.Ident();
    m.Set(&b);
    m.Set3(c.x, c.y, c.z);
    c.Init(a1);
    int r = s->Run(&c, &m, -1.0f, a8);
    c.Done();
    return r;
}
