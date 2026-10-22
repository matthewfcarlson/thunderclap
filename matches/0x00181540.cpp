class Base {
  public:
    virtual void f();
    char pad[8];
    Base();
};
class Track_181540 : public Base {
  public:
    int a, b, c;
    Track_181540() : a(0), b(0), c(0) {}
};
class PropDamageTrack : public Track_181540 {
  public:
    PropDamageTrack();
    virtual void f();
};
PropDamageTrack::PropDamageTrack() {
    *(int*)((char*)this + 8) = 1;
}