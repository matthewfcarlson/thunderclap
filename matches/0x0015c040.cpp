class Base_15c040 {
  public:
    Base_15c040();
    virtual void f();
    char pad[4];
};
class Elem_15c040 {
  public:
    Elem_15c040();
    char pad[8];
};
class Track : public Base_15c040 {
  public:
    Track();
    virtual void f();
    char pad1[4];
    int val;
    float speed;
    char pad2[4];
    Elem_15c040 a, b, c, d, e;
    float x, y, z;
};
Track::Track() : val(0), speed(-1.0f), x(0), y(0.1f), z(0.1f) {}