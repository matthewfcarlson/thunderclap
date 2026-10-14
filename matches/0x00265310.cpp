struct Temp_265310 {
    char x[0x18];
    void f(int);
    void g(int, int);
};
struct Obj_265310 {
    char pad[0x10];
    int value;
    void run(int);
};
void Obj_265310::run(int param) {
    Temp_265310 t;
    t.f(value);
    t.g(param, 0);
}