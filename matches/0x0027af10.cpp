class Pair_27af10 {
  public:
    unsigned int a;
    unsigned int b;
    Pair_27af10* Set(unsigned int x, unsigned int y);
};
Pair_27af10* Pair_27af10::Set(unsigned int x, unsigned int y) {
    a = x;
    b = y;
    return this;
}