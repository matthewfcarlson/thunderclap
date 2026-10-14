// Same code shape as 0x00336490 (propagated; names are from that function)
class Helper_336690 {
  public:
    int run(int a, int b);
};
class Thing_336690 {
  public:
    int pad;
    Helper_336690* member;
    void consume(int x);
    void combine(int a, int b);
};
void Thing_336690::combine(int a, int b) {
    int x = member->run(a, b);
    consume(x);
}