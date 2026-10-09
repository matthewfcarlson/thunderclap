class X {
  public:
    virtual void First();
    virtual void Second();
    virtual void Third(int);
    int count;
    void f();
};
void X::f() {
    First();
    if (--count == 0) {
        count = 0x5dc;
        Second();
        Third(1);
    } else
        Second();
}
