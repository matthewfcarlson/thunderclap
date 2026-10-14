class A_14580 {
  public:
    char pad[0x20];
    struct B_14580* p;
    float f();
};
struct B_14580 {
    char pad[0x2c];
    float value;
};
float A_14580::f() {
    return p->value;
}