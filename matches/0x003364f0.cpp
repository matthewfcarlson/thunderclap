// Same code shape as 0x00336490 (propagated; names are from that function)
class Helper {
  public:
    int run(int a, int b);
};
class Thing {
  public:
    int pad;
    Helper* member;
    void consume(int x);
    void combine(int a, int b);
};
void Thing::combine(int a, int b) {
    int x = member->run(a, b);
    consume(x);
}