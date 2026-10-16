class Base {
  public:
    Base();
    virtual void Fn();
    char pad[4];
};
class PrintTrack : public Base {
  public:
    PrintTrack();
    int a, b, c, d;
    virtual void Fn();
};
PrintTrack::PrintTrack() : Base(), b(0), c(0), d(0) {
    a = 1;
}