struct Elem_5a870 {
    ~Elem_5a870() throw();
    int a[2];
};
class Base_5a870 {
  public:
    Base_5a870();
    virtual ~Base_5a870() throw();
    int pad[5];
};
class CGrappleLocoStrafe4Track : public Base_5a870 {
  public:
    virtual ~CGrappleLocoStrafe4Track() throw();
    Elem_5a870 e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10;
};
CGrappleLocoStrafe4Track::~CGrappleLocoStrafe4Track() throw() {}
