class D {
  public:
    int helper(int, int, int);
};
class C {
  public:
    char pad[4];
    D* sub;
    int second(int);
    int target(int, int, int);
};
int C::target(int a, int b, int c) {
    int x = sub->helper(a, b, c);
    return second(x);
}