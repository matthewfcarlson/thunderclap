struct Elem_15bbe0 {
    char d[8];
    ~Elem_15bbe0() throw();
};
class Track_15bbe0 {
  public:
    virtual ~Track_15bbe0() throw();
    char p[0x3c];
};
class LocomotionStrafe4Track_15bbe0 : public Track_15bbe0 {
  public:
    virtual ~LocomotionStrafe4Track_15bbe0() throw();
    Elem_15bbe0 a, b, c, d, e, f, g, h, i, j, k;
};
LocomotionStrafe4Track_15bbe0::~LocomotionStrafe4Track_15bbe0() throw() {}
