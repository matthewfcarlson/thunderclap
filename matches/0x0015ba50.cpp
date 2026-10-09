struct T {
    char d[8];
    ~T() throw();
};
struct B {
    virtual ~B() throw();
    char p[0x34];
};
struct D : B {
    T m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;
    ~D() throw();
};
D::~D() throw() {}
