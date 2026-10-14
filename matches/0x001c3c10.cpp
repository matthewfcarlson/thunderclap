class B {
  public:
    void Method();
};

class A {
  public:
    B* m;
    void Fn();
};

void A::Fn() {
    m->Method();
}
