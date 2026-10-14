class C {
  public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void Fn(int);
    void Target();
};

void C::Target() {
    Fn(2);
}
