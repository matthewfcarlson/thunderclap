struct Base {
    virtual void f0();
    Base();
};
struct WCV : Base {
    WCV();
    virtual void f0();
};
WCV::WCV() {}
