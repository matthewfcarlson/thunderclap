struct Base {
    Base(int a);
    virtual void V0();
    char pad[12];
    int m10;
};

struct Obj : Base {
    Obj(int a, int b);
};

Obj::Obj(int a, int b) : Base(a) {
    m10 = b;
}
