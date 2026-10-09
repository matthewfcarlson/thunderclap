void thunk(int);
class C {
  public:
    char pad[0x114];
    int a;
    int b;
    void f();
};
void C::f() {
    thunk(a);
    thunk(b);
}