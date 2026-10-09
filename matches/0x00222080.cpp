// Same code shape as 0x0030f3d0 (propagated; names are from that function)
class Base {
  public:
    Base();
    char pad[0x40];
};
class Thing : public Base {
  public:
    int a;
    int b;
    int c;
    float d;
    int e;
    Thing(int);
    void Finish(int);
};
Thing::Thing(int x) : Base() {
    c = 0;
    b = 0;
    a = 0;
    d = 1.0f;
    int* q = &e;
    *q = 0;
    Finish(x);
}
