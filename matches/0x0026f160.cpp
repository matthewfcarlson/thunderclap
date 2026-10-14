class X_26f160 {
  public:
    virtual void First();
    virtual void Second();
    virtual void Third(int);
    int count;
    void f();
};
void X_26f160::f() {
    First();
    if (--count == 0) {
        count = 0x5dc;
        Second();
        Third(1);
    } else
        Second();
}
