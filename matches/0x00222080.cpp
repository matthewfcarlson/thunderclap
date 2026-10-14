// Same code shape as 0x0030f3d0 (propagated; names are from that function)
class Base_222080 {
  public:
    Base_222080();
    char pad[0x40];
};
class Thing_222080 : public Base_222080 {
  public:
    int a;
    int b;
    int c;
    float d;
    int e;
    Thing_222080(int);
    void Finish(int);
};
Thing_222080::Thing_222080(int x) : Base_222080() {
    c = 0;
    b = 0;
    a = 0;
    d = 1.0f;
    int* q = &e;
    *q = 0;
    Finish(x);
}
