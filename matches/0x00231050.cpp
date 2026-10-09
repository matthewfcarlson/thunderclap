class C {
public:
    char pad[0x18];
    int a;
    int b;
    void f();
};
void thunk(int);
void C::f() { thunk(a); thunk(b); }
