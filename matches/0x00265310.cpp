struct Temp_265310 {
    char x[0x18];
    void f(int);
    int g(int, int);
};
struct Obj_265310 {
    char pad[0x10];
    int value;
    int run(int);
};
int Obj_265310::run(int param) {
    Temp_265310 t;
    t.f(value);
    return t.g(param, 0);
}