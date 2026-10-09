struct Elem {
    char d[8];
    ~Elem() throw();
};
class Base {
  public:
    virtual ~Base() throw();
    char p[0x3c];
};
class Strafe : public Base {
  public:
    virtual ~Strafe() throw();
    Elem a, b, c, d, e, f, g, h, i, j, k;
};
Strafe::~Strafe() throw() {}
