class Base_5af30 {
  public:
    Base_5af30();
    virtual void f0();
};
class SubC_5af30 {
  public:
    SubC_5af30();

  private:
    char pad[12];
};
class Sub1C {
  public:
    Sub1C();
};
class CGrappleSequenceTrack : public Base_5af30 {
  public:
    CGrappleSequenceTrack();
    virtual void g0();

  private:
    char pad[4];
    int m8;
    SubC_5af30 mC;
    int m18;
    Sub1C m1C;
};
CGrappleSequenceTrack::CGrappleSequenceTrack() : Base_5af30(), mC(), m18(1), m1C() {
    m8 = 1;
}
