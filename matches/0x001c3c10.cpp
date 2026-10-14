class B_1c3c10 {
  public:
    void Method();
};

class A_1c3c10 {
  public:
    B_1c3c10* m;
    void Fn();
};

void A_1c3c10::Fn() {
    m->Method();
}
