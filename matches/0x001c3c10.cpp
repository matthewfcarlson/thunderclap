class B_1c3c10 {
  public:
    void Method(int, int);
};

class A_1c3c10 {
  public:
    B_1c3c10* m;
    void Fn(int, int);
};

void A_1c3c10::Fn(int a0, int a1) {
    m->Method(a0, a1);
}
