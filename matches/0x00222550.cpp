class Inner_222550 {
  public:
    char pad[16];
    int value;
    int make(int, int);
};
class Base_222550 {
  public:
    char pad[16];
    Inner_222550* inner;
    int a, b, c;
    void f(int, int);
    void helper(int);
};
void Base_222550::f(int x, int y) {
    if ((x | y) == 0) {
        a = 0;
        b = 0;
        c = inner->value - 1;
    } else {
        int z = inner->make(x, y);
        helper(z);
    }
}