struct A_2731b0 {
    virtual void f0();
    virtual void f1();
    virtual void f(int);
};
struct B_2731b0 {
    virtual void f(int);
};
struct C_2731b0 : A_2731b0, B_2731b0 {
    C_2731b0();
    void f(int);
};
C_2731b0::C_2731b0() {}
