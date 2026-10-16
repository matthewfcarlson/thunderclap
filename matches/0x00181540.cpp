class Base {
  public:
    virtual void f();
    char pad[8];
    Base();
};
class Mid : public Base {
  public:
    int a, b, c;
    Mid() : a(0), b(0), c(0) {}
};
class PropDamageTrack : public Mid {
  public:
    PropDamageTrack();
    virtual void f();
};
PropDamageTrack::PropDamageTrack() {
    *(int*)((char*)this + 8) = 1;
}