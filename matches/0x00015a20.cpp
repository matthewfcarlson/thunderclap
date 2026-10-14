// Same code shape as 0x00014580 (propagated; names are from that function)
class A_15a20 {
  public:
    char pad[0x20];
    struct B_15a20* p;
    float f();
};
struct B_15a20 {
    char pad[0x2c];
    float value;
};
float A_15a20::f() {
    return p->value;
}