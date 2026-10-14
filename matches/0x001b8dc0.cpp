struct B_1b8dc0 {
    int x, y, z;
};
struct C_1b8dc0 {
    int x, y, z;
    void Init(int a);
    void Done();
};
struct M_1b8dc0 {
    char d[64];
    void Ident();
    void Set(B_1b8dc0* b);
    void Set3(int a, int b, int c);
};
struct S_1b8dc0 {
    int Run(C_1b8dc0* c, M_1b8dc0* m, float f, int a);
};
S_1b8dc0* GetS();
int __stdcall Fn(int a1, B_1b8dc0 b, C_1b8dc0 c, int a8) {
    S_1b8dc0* s = GetS();
    M_1b8dc0 m;
    m.Ident();
    m.Set(&b);
    m.Set3(c.x, c.y, c.z);
    c.Init(a1);
    int r = s->Run(&c, &m, -1.0f, a8);
    c.Done();
    return r;
}
