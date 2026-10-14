class A_223060 {
  public:
    int f();
};
class B_223060 {
  public:
    void g(int);
};
class C_223060 {
  public:
    char pad[0x10];
    A_223060 a;
    void f();
};
void C_223060::f() {
    int x = a.f();
    ((B_223060*)*(void**)((char*)this + 0x64))->g(x);
}