class Inner {
  public:
    char pad[0x34];
    int value;
};
class Outer {
  public:
    char pad[0x10];
    Inner* inner;
};
void step();
void f(Outer* p) {
    while (p->inner->value != 0)
        step();
}