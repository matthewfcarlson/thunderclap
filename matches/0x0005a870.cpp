struct Elem_5a870 {
    ~Elem_5a870() throw();
    int a[2];
};
class CTrack_5a870 {
  public:
    CTrack_5a870();
    virtual ~CTrack_5a870() throw();
    int pad[5];
};
class CGrappleLocoStrafe4Track : public CTrack_5a870 {
  public:
    virtual ~CGrappleLocoStrafe4Track() throw();
    Elem_5a870 e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10;
};
CGrappleLocoStrafe4Track::~CGrappleLocoStrafe4Track() throw() {}
