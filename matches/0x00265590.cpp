class B {
  public:
    void First();
    void Second();
};
class A {
  public:
    char pad[12];
    B* x;
    B* y;
    void Run();
};
void A::Run() {
    x->First();
    y->Second();
}