class Obj {
  public:
    Obj* f(int, int);
    void helper(int, int, int);
};
Obj* Obj::f(int a, int b) {
    helper(12, a, b);
    return this;
}