struct Inner_2367f0 {};
struct Tmp_2367f0 {
    char pad[0x18];
    Tmp_2367f0(Inner_2367f0*);
    void f(int, int);
};
struct Obj_2367f0 {
    char pad[0x38];
    Inner_2367f0 inner;
    void target(int, int);
};
void Obj_2367f0::target(int a, int b) {
    Tmp_2367f0 t(&inner);
    t.f(a, b);
}