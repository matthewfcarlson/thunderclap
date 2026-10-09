struct V3 {
    float x, y, z;
};
struct T {
    char d[8];
    T(int a) throw();
    ~T() throw();
};
struct A {
    char d[0x40];
    A() throw();
    void Set(V3* v) throw();
};
struct S {
    void* Do(T* t, A* a, float lo, float hi) throw();
};
S* GetS() throw();
void* __stdcall F(int a1, V3 v) throw() {
    void* r = 0;
    A a;
    a.Set(&v);
    S* s = GetS();
    if (s) {
        T t(a1);
        r = s->Do(&t, &a, -1.0f, 1.0f);
    }
    return r;
}
