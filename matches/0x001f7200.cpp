struct V3_1f7200 {
    float x, y, z;
};
struct T_1f7200 {
    char d[8];
    T_1f7200(int a) throw();
    ~T_1f7200() throw();
};
struct A_1f7200 {
    char d[0x40];
    A_1f7200() throw();
    void Set(V3_1f7200* v) throw();
};
struct S_1f7200 {
    void* Do(T_1f7200* t, A_1f7200* a, float lo, float hi) throw();
};
S_1f7200* GetS() throw();
void* __stdcall F(int a1, V3_1f7200 v) throw() {
    void* r = 0;
    A_1f7200 a;
    a.Set(&v);
    S_1f7200* s = GetS();
    if (s) {
        T_1f7200 t(a1);
        r = s->Do(&t, &a, -1.0f, 1.0f);
    }
    return r;
}
