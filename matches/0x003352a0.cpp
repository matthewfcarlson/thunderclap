class X {
public:
    virtual void f0();
    virtual void f1();
    char pad[8];
    int field;
    X* Init();
};

X* X::Init() {
    *(int*)this = 0x434300;
    field = 0;
    return this;
}
