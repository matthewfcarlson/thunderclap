class Inner_216f60 {
  public:
    char pad[0x34];
    int value;
};
class Outer_216f60 {
  public:
    char pad[0x10];
    Inner_216f60* inner;
};
void step();
void f(Outer_216f60* p) {
    while (p->inner->value != 0)
        step();
}