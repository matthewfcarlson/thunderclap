class Base {
  public:
    Base();
    virtual void f0();
};
class SubC {
  public:
    SubC();

  private:
    char pad[12];
};
class Sub1C {
  public:
    Sub1C();
};
class CGrappleSequenceTrack : public Base {
  public:
    CGrappleSequenceTrack();
    virtual void g0();

  private:
    char pad[4];
    int m8;
    SubC mC;
    int m18;
    Sub1C m1C;
};
CGrappleSequenceTrack::CGrappleSequenceTrack() : Base(), mC(), m18(1), m1C() {
    m8 = 1;
}
