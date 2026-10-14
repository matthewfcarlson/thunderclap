struct Elem_15bbe0 {
    char d[8];
    ~Elem_15bbe0() throw();
};
class Base_15bbe0 {
  public:
    virtual ~Base_15bbe0() throw();
    char p[0x3c];
};
class Strafe : public Base_15bbe0 {
  public:
    virtual ~Strafe() throw();
    Elem_15bbe0 a, b, c, d, e, f, g, h, i, j, k;
};
Strafe::~Strafe() throw() {}
