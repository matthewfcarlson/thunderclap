typedef unsigned int size_t;
void* operator new(size_t) throw();
struct Base {
    char data[8];
    Base(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
struct Elem {
    char data[8];
    Elem() throw();
};
struct Cond : Base {
    int type;
    int value;
    char pad[4];
    Elem elem;
    Cond() throw() : Base(0), type(2), value(0), elem() {}
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
struct Factory {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual Base* f5();
};
Base* Factory::f5() {
    return new Cond;
}