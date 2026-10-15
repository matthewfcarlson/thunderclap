class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class HulkActionTrack : public Base {
  public:
    HulkActionTrack();
    int flag;
    int a;
    float b;
    char p2[4];
    char sub[8];
    int c;
    virtual void g();
};
HulkActionTrack::HulkActionTrack() : Base() {
    a = 0;
    b = -1.0f;
    ((Sub*)sub)->Sub::Sub();
    c = 0;
    flag = 1;
}