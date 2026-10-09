struct Elem {
    ~Elem() throw();
    int a[2];
};
class Base {
  public:
    Base();
    virtual ~Base() throw();
    int pad[5];
};
class CGrappleLocoStrafe4Track : public Base {
  public:
    virtual ~CGrappleLocoStrafe4Track() throw();
    Elem e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10;
};
CGrappleLocoStrafe4Track::~CGrappleLocoStrafe4Track() throw() {}
