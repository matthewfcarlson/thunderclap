class Helper_336490 {
  public:
    int run(int a);
};
class Thing_336490 {
  public:
    int pad;
    Helper_336490* member;
    void consume(int x, int b);
    void combine(int a, int b);
};
void Thing_336490::combine(int a, int b) {
    consume(member->run(a), b);
}