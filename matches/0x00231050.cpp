class C_231050 {
  public:
    char pad[0x18];
    int a;
    int b;
    void f();
};
void thunk(int);
void C_231050::f() {
    thunk(a);
    thunk(b);
}
