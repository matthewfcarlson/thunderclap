class Helper_336490 {
  public:
    int run(int a, int b);
};
class Thing_336490 {
  public:
    int pad;
    Helper_336490* member;
    void consume(int x);
    void combine(int a, int b);
};
void Thing_336490::combine(int a, int b) {
    int x = member->run(a, b);
    consume(x);
}