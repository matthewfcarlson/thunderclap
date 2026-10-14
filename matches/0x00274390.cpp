class Sub_274390 {
  public:
    virtual void A();
    virtual void B();
};
struct Container_274390 {
    char pad[4];
    Sub_274390 sub;
    char pad2[0x10];
    unsigned int value;
};
class Outer_274390 {
  public:
    char pad[8];
    Container_274390* obj;
    unsigned int target(unsigned int a, unsigned int b);
};
unsigned int Outer_274390::target(unsigned int a, unsigned int b) {
    obj->sub.A();
    obj->value = b;
    obj->sub.B();
    return a;
}