class X_1a5e20 {
  public:
    char pad[0x24];
    struct Y_1a5e20* p24;
    Y_1a5e20* p28;
    void f();
};
class Y_1a5e20 {
  public:
    virtual void a();
    virtual void b();
};
void X_1a5e20::f() {
    if (p28) {
        p28->b();
        p28 = 0;
    }
    if (p24) {
        p24->b();
        p24 = 0;
    }
}