class Pair {
  public:
    unsigned int a;
    unsigned int b;
    Pair* Set(unsigned int x, unsigned int y);
};
Pair* Pair::Set(unsigned int x, unsigned int y) {
    a = x;
    b = y;
    return this;
}