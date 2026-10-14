void thunk(int);
class C_22ec20 {
  public:
    char pad[0x114];
    int a;
    int b;
    void f();
};
void C_22ec20::f() {
    thunk(a);
    thunk(b);
}