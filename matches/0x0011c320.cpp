class Base_11c320 {
  public:
    Base_11c320();
    virtual void f();
    char pad[8];
    void* p0;
    float x;
    void* p1;
};
class RoutTrack : public Base_11c320 {
  public:
    RoutTrack();
    virtual void f();
    float a, b, c, d;
    char flag;
    char pad2[3];
    float g, h, i, j;
};
RoutTrack::RoutTrack() : Base_11c320() {
    p0 = 0;
    p1 = 0;
    x = -1.0f;
    a = 1.0f;
    b = 15.0f;
    c = 0.5f;
    d = 3.0f;
    flag = 1;
    g = 2.5f;
    h = 5.5f;
    i = 2.0f;
    j = 4.0f;
}