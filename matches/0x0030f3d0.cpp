class Base_30f3d0 {
  public:
    Base_30f3d0();
    char pad[0x40];
};
class Thing_30f3d0 : public Base_30f3d0 {
  public:
    int a;
    int b;
    int c;
    float d;
    int e;
    Thing_30f3d0(int);
    void Finish(int);
};
Thing_30f3d0::Thing_30f3d0(int x) : Base_30f3d0() {
    c = 0;
    b = 0;
    a = 0;
    d = 1.0f;
    int* q = &e;
    *q = 0;
    Finish(x);
}
