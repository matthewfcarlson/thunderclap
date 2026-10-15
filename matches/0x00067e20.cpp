extern "C" void _ReadWriteBarrier();
extern const float zero;
struct Vec {
    void Init();
    void Set(const float*);
};
struct Obj {
    int a, b, c, d, e, f;
    Vec v;
    Obj();
};
Obj::Obj() {
    v.Init();
    v.Set(&zero);
    a = 0;
    d = 0;
    c = 0;
    b = 0;
    _ReadWriteBarrier();
    e = 0;
    v.Set(&zero);
}