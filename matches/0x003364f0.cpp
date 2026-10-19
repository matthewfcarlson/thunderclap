// Same code shape as 0x00336490 (propagated; names are from that function)
class Helper_3364f0 {
  public:
    int run(int a);
};
class Thing_3364f0 {
  public:
    int pad;
    Helper_3364f0* member;
    void consume(int x, int b);
    void combine(int a, int b);
};
void Thing_3364f0::combine(int a, int b) {
    consume(member->run(a), b);
}