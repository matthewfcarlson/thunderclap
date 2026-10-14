struct T_15ba50 {
    char d[8];
    ~T_15ba50() throw();
};
struct B_15ba50 {
    virtual ~B_15ba50() throw();
    char p[0x34];
};
struct D : B_15ba50 {
    T_15ba50 m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;
    ~D() throw();
};
D::~D() throw() {}
