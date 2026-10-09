const float gScale = 33.333332061767578125f;
class Sink {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(float, int);
};
class Obj {
  public:
    char pad[0x44];
    float value;
    char pad2[0x54];
    Sink* sink;
    void set(float);
};
void Obj::set(float x) {
    value = x;
    sink->f6(x * gScale, 0);
}